#include "widget.h"
#include "ui_widget.h"

void Widget::read_Com()
{
    QByteArray RXD_str;

    RXD_str.clear();
    RXD_str = serial.read(1).toHex();

    while(!RXD_str.isEmpty())
    {
        rawdata[RXD_counter] = RXD_str.toInt(0,16);
        RXD_counter++;
        if(RXD_counter == 16)
        {
            RXD_counter = 0;
            unsigned int drawpoint[8];
            for(int i = 0;i < 8;i++)
            {
                drawpoint[i] = (rawdata[i*2] * 256) + rawdata[i*2+1];
            }


            for(int j = 0;j < 4;j++)
            {
                if(drawpoint[j*2] != 0x8000 && pointnum[j] < 400)
                {
                    //unsigned int y1, y2;
                    if(pointnum[j] == 0)
                    {
                        if(drawpoint[j*2] < drawpoint[j*2+1])
                        {
                            ADC_min[j] = drawpoint[j*2];
                            SIGmax[j] = true;
                            SIG_Diff[j] = drawpoint[j*2+1] - drawpoint[j*2];
                        }
                        else
                        {
                            ADC_min[j] = drawpoint[j*2+1];
                            SIGmax[j] = false;
                            SIG_Diff[j] = drawpoint[j*2] - drawpoint[j*2+1];
                        }
                        ADC_max[j] = (1 / ADCVRef * ADC14bits);
                    }

                    if(SIGmax[j])
                        drawpoint[j*2+1] -= SIG_Diff[j];
                    else
                        drawpoint[j*2] -= SIG_Diff[j];

                    if(drawpoint[j*2] > ADC_max[j])
                        ADC_max[j] = drawpoint[j*2];
                    if(drawpoint[j*2+1] > ADC_max[j])
                        ADC_max[j] = drawpoint[j*2+1];
                    if(drawpoint[j*2] < ADC_min[j])
                        ADC_min[j] = drawpoint[j*2];
                    if(drawpoint[j*2+1] < ADC_min[j])
                        ADC_min[j] = drawpoint[j*2+1];

                    if(pointnum[j] < 400)
                    {
                        points[j*2][pointnum[j]]     = (drawpoint[j*2]);
                        points[j*2+1][pointnum[j]]   = (drawpoint[j*2+1]);
                        PDdrawnewpoint(j);
                        labelnum[j][0] = ADC_min[j];
                        labelnum[j][1] = (ADC_max[j] - ADC_min[j]) / 2 + ADC_min[j];
                        labelnum[j][2] = ADC_max[j];
                    }
                    button[j] = true;

                    if(datadelay[j] == 0)
                    {
                        QByteArray time_log,ch1_log, ch2_log;
                        time_log.setNum(pointnum[j]);
                        ch1_log.setNum(drawpoint[j*2]);
                        ch2_log.setNum(drawpoint[j*2+1]);
                        if(pointnum[j] == 0)
                        {
                            PDfile[j] = logfile_setting(logdirname, (QString::number(j) + QString("_PD.csv")));
                            PDfile_write_title(PDfile[j]);
                        }
                        PDfile_write(PDfile[j], time_log, ch1_log, ch2_log);
                        pointnum[j]++;
                    }

                    if(datadelay[j]>0)
                    {
                        datadelay[j]--;
                    }
                }
                else if(drawpoint[j*2] == 0x8000)
                {
                    pointnum[j] = 0;
                    button[j] = false;
                    datadelay[j] = datadelayset;
                }
            }

            if(button[0] == true && pointnum[0] < 400)
                ui->label_1->setText("(1)[LED ON ]");
            else
                ui->label_1->setText("(1)[LED OFF]");
            if(button[1] == true && pointnum[1] < 400)
                ui->label_2->setText("(2)[LED ON ]");
            else
                ui->label_2->setText("(2)[LED OFF]");
            if(button[2] == true && pointnum[2] < 400)
                ui->label_3->setText("(3)[LED ON ]");
            else
                ui->label_3->setText("(3)[LED OFF]");
            if(button[3] == true && pointnum[3] < 400)
                ui->label_4->setText("(4)[LED ON ]");
            else
                ui->label_4->setText("(4)[LED OFF]");
        }
        RXD_str = serial.read(1).toHex();
    }
}
