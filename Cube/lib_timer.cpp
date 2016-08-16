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
