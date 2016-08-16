#include "widget.h"
#include "ui_widget.h"

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::Paint)
    {
        if(obj == ui->widget_D1)
        {
            QPainter painter(ui->widget_D1);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);


            painter.setPen(Qt::red);
            painter.drawPolyline(points_1, pointnum[0]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(points_2, pointnum[0]);
        }
        else if(obj == ui->widget_D2)
        {
            QPainter painter(ui->widget_D2);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);


            painter.setPen(Qt::red);
            painter.drawPolyline(points_3, pointnum[1]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(points_4, pointnum[1]);
        }
        else if(obj == ui->widget_D3)
        {
            QPainter painter(ui->widget_D3);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);


            painter.setPen(Qt::red);
            painter.drawPolyline(points_5, pointnum[2]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(points_6, pointnum[2]);
        }
        else if(obj == ui->widget_D4)
        {
            QPainter painter(ui->widget_D4);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);


            painter.setPen(Qt::red);
            painter.drawPolyline(points_7, pointnum[3]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(points_8, pointnum[3]);
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Widget::PDdrawnewpoint(int x, int y1, int y2, int DN)
{
    int Height = 240;
    switch(DN)
    {
        case 0:
            points_1[x] = QPointF(x, Height - y1);
            points_2[x] = QPointF(x, Height - y2);
            ui->widget_D1->update();
            break;
        case 1:
            points_3[x] = QPointF(x, Height - y1);
            points_4[x] = QPointF(x, Height - y2);
            ui->widget_D2->update();
            break;
        case 2:
            points_5[x] = QPointF(x, Height - y1);
            points_6[x] = QPointF(x, Height - y2);
            ui->widget_D3->update();
            break;
        case 3:
            points_7[x] = QPointF(x, Height - y1);
            points_8[x] = QPointF(x, Height - y2);
            ui->widget_D4->update();
            break;
    }
}
