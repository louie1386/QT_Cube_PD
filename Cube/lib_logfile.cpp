#include "widget.h"
#include "ui_widget.h"

QString Widget::FileName_Setting(QString FileName)
{
    QDateTime Now;
    QString logfilename;

    logfilename = Now.currentDateTime().toString();
    logfilename.replace(" ", "_");
    logfilename.replace(":", "_");
    logfilename += "_";
    logfilename += FileName;

    return logfilename;
}

QString Widget::logfile_setting(QString Path, QString FileName)
{
    QString cddir = "/";
    QString Real_Path;
    QString Devicedir;
    QStringList DeviceName;
    uint filenum;

    QString logfilename = FileName_Setting(FileName);

    if(QDir(logPath).exists())
    {
        logdir.setCurrent(logPath);
        logdir.setSorting(QDir::Time);
        DeviceName = logdir.entryList();
        filenum = logdir.count();
        if(filenum > 2)
        {
            Devicedir = DeviceName[filenum-1];
            logdir.mkpath(Devicedir + cddir + Path);
            logdir.setCurrent(logdir.currentPath() + cddir + Devicedir + cddir + Path);
            Real_Path = logdir.currentPath() + cddir + logfilename;
        }
        else
        {
            logdir.setCurrent(locationdir);
            logdir.mkpath(Path);
            logdir.setCurrent(logdir.currentPath() + cddir + Path);
            Real_Path = logdir.currentPath() + cddir + logfilename;
        }
    }
    else
    {
        logdir.setCurrent(locationdir);
        logdir.mkpath(Path);
        logdir.setCurrent(logdir.currentPath() + cddir + Path);
        Real_Path = logdir.currentPath() + cddir + logfilename;
    }
    logfile_max();

    return Real_Path;
}

void Widget::logfile_max()
{
    QString Devicedir;
    QStringList DeviceName;
    uint filenum;

    filenum = logdir.count();
    DeviceName = logdir.entryList();
    if(filenum > (logfilemax + 2))
    {
        Devicedir = DeviceName[2];
        logdir.remove(Devicedir);
    }
}

void Widget::PDfile_write(QString file, QByteArray time,
                          QByteArray ch1, QByteArray ch2)
{
    QFile writefile;
    writefile.setFileName(file);
    if(writefile.open(QIODevice::Append))
    {
        writefile.write(time.data());
        writefile.write(",");
        writefile.write(ch1.data());
        writefile.write(",");
        writefile.write(ch2.data());
        writefile.write("\n");
        writefile.close();
    }
}

void Widget::PDfile_write_title(QString file)
{
    PDfile_write(file, "Time", "chA", "chB");
}

