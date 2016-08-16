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
                    unsigned int y1, y2;
                    y1 = (drawpoint[j*2] - ADC_min) * Draw_range / ADC_max + Draw_base;
                    y2 = (drawpoint[j*2+1] - ADC_min) * Draw_range / ADC_max + Draw_base;
                    PDdrawnewpoint(pointnum[j], y1, y2, j);
                    pointnum[j]++;
                    button[j] = true;
                }
                else if(drawpoint[j*2] == 0x8000)
                {
                    pointnum[j] = 0;
                    button[j] = false;
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
