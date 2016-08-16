#include "widget.h"
#include "ui_widget.h"

void Widget::initial()
{
    RXD_counter = 0;
    for(int i = 0;i < 4;i++)
    {
        pointnum[i] = 0;
        button[i] = false;
    }

    serialport_initial();
    timer_initial();
    ui_initial();
    draw_initial();  
}

void Widget::ui_initial()
{

}

void Widget::serialport_initial()
{
    bool COM = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if(info.portName() != "ttyAMA0")
        {
            serial.setPortName(info.portName());
        }
        if(info.portName() == "COM3")
        {
            COM = true;
        }
    }
    if(COM)
        serial.setPortName("COM3");
    serial.setBaudRate(serial.Baud9600);
    serial.setDataBits(serial.Data8);
    serial.setFlowControl(serial.NoFlowControl);
    serial.setParity(serial.NoParity);
    serial.setStopBits(serial.OneStop);
    serial.close();
    if(serial.open(QIODevice::ReadWrite))
    {
        connect(&serial,SIGNAL(readyRead()),this,SLOT(read_Com()));
        serial_disconnect_timer = SerialResetTime;
    }
    else
    {
        serial.close();
    }
}

void Widget::timer_initial()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout_todo()));
    timer->start(timer_T);
}

void Widget::draw_initial()
{
    ui->widget_D1->installEventFilter(this);
    ui->widget_D2->installEventFilter(this);
    ui->widget_D3->installEventFilter(this);
    ui->widget_D4->installEventFilter(this);
}
