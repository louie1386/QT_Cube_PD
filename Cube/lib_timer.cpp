#include "widget.h"
#include "ui_widget.h"

void Widget::timeout_todo()
{
    Open_Device();
    Get_Volt();
}

void Widget::Open_Device()
{
    if(!(serial_disconnect_timer))
        serialport_initial();
}

void Widget::Get_Volt()
{
    QString TXD_str = QString(0xAA);
    RXD_counter = 0;
    serial.write(TXD_str.toLatin1());
}

void Widget::LabelnumChange()
{
    ui->labelN1_1->setText(QString(labelnum[0][0]));
    ui->labelN1_2->setText(QString(labelnum[0][1]));
    ui->labelN1_3->setText(QString(labelnum[0][2]));

    ui->labelN2_1->setText(QString(labelnum[1][0]));
    ui->labelN2_2->setText(QString(labelnum[1][1]));
    ui->labelN2_3->setText(QString(labelnum[1][2]));

    ui->labelN3_1->setText(QString(labelnum[2][0]));
    ui->labelN3_2->setText(QString(labelnum[2][1]));
    ui->labelN3_3->setText(QString(labelnum[2][2]));

    ui->labelN4_1->setText(QString(labelnum[3][0]));
    ui->labelN4_2->setText(QString(labelnum[3][1]));
    ui->labelN4_3->setText(QString(labelnum[3][2]));
}
