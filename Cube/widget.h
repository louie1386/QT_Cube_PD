#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QPainter>
#include <QPointF>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    static const int SerialResetTime =      3;      //sec
    static const int timer_T =              1500;   //ms

    const double Draw_range =        200;    //pixel
    const double Draw_base =         20;     //pixel
    const double ADC14bits =         16384;
    const double ADCVRef =           4.096*3;
    const double Volt_min =          2;
    const double Volt_max =          6;
    const double ADC_min =           Volt_min * ADC14bits / ADCVRef;
    const double ADC_max =           Volt_max * ADC14bits / ADCVRef;
    ~Widget();

private slots:
    void initial();

    void ui_initial();

    void serialport_initial();

    void timer_initial();

    void draw_initial();

    void read_Com();

    void timeout_todo();

    void Open_Device();

    void Get_Volt();

    bool eventFilter(QObject *obj, QEvent *event);

    void PDdrawnewpoint(int x, int y1, int y2, int DN);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QSerialPort serial;
    int serial_disconnect_timer;

    int RXD_counter;
    unsigned int rawdata[16];
    QPointF points_1[400], points_2[400], points_3[400], points_4[400],
            points_5[400], points_6[400], points_7[400], points_8[400];
    int pointnum[4];
    bool button[4];
};

#endif // WIDGET_H
