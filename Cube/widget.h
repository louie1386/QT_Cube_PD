#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QPainter>
#include <QPointF>
#include <QDir>
#include <QDateTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    static const int SerialResetTime =      3;      //sec
    static const int timer_T =              2250;   //ms

    const double Draw_range =        200;    //pixel
    const double Draw_base =         20;     //pixel
    const double ADC14bits =         16384;
    const double ADCVRef =           4.096*3;
    const int datadelayset =         3;         //pixel
    static const int logfilemax =    1000;

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

    void LabelnumChange();

    bool eventFilter(QObject *obj, QEvent *event);

    void PDdrawnewpoint(int DN);

    void on_pushButton_clicked();

    QString FileName_Setting(QString FileName);

    QString logfile_setting(QString Path, QString FileName);

    void logfile_max();

    void PDfile_write(QString file, QByteArray time,
                              QByteArray ch1, QByteArray ch2);

    void PDfile_write_title(QString file);

private:
    Ui::Widget *ui;
    QSerialPort serial;
    int serial_disconnect_timer;

    int RXD_counter;
    unsigned int rawdata[16];
    unsigned int points[8][400];
    int pointnum[4];
    bool button[4];

    double ADC_min[4];
    double ADC_max[4];
    double SIG_Diff[4];
    int datadelay[4] = {datadelayset, datadelayset, datadelayset, datadelayset};
    bool SIGmax[4] = {false, false, false, false};

    QString logdirname, logPath, locationdir;
    QDir logdir;
    QString PDfile[4];
    int log_sec_time, filepart;

    unsigned int labelnum[4][3];
};

#endif // WIDGET_H
