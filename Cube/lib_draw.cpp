#include "widget.h"
#include "ui_widget.h"

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::Paint)
    {
        QPointF pA[400], pB[400];
        unsigned int Hight = 240;
        if(obj == ui->widget_D1)
        {
            QPainter painter(ui->widget_D1);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);

            for(int i =0;i<400;i++)
            {
                pA[i] = QPointF(i, Hight - ((points[0][i] - ADC_min[0]) * Draw_range / ADC_max[0] + Draw_base));
                pB[i] = QPointF(i, Hight - ((points[1][i] - ADC_min[0]) * Draw_range / ADC_max[0] + Draw_base));
            }

            painter.setPen(Qt::red);
            painter.drawPolyline(pA, pointnum[0]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(pB, pointnum[0]);
        }
        else if(obj == ui->widget_D2)
        {
            QPainter painter(ui->widget_D2);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);

            for(int i =0;i<400;i++)
            {
                pA[i] = QPointF(i, Hight - ((points[2][i] - ADC_min[1]) * Draw_range / ADC_max[1] + Draw_base));
                pB[i] = QPointF(i, Hight - ((points[3][i] - ADC_min[1]) * Draw_range / ADC_max[1] + Draw_base));
            }

            painter.setPen(Qt::red);
            painter.drawPolyline(pA, pointnum[1]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(pA, pointnum[1]);
        }
        else if(obj == ui->widget_D3)
        {
            QPainter painter(ui->widget_D3);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);

            for(int i =0;i<400;i++)
            {
                pA[i] = QPointF(i, Hight - ((points[4][i] - ADC_min[2]) * Draw_range / ADC_max[2] + Draw_base));
                pB[i] = QPointF(i, Hight - ((points[5][i] - ADC_min[2]) * Draw_range / ADC_max[2] + Draw_base));
            }

            painter.setPen(Qt::red);
            painter.drawPolyline(pA, pointnum[2]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(pB, pointnum[2]);
        }
        else if(obj == ui->widget_D4)
        {
            QPainter painter(ui->widget_D4);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,400,240);

            for(int i =0;i<400;i++)
            {
                pA[i] = QPointF(i, Hight - ((points[6][i] - ADC_min[3]) * Draw_range / ADC_max[3] + Draw_base));
                pB[i] = QPointF(i, Hight - ((points[7][i] - ADC_min[3]) * Draw_range / ADC_max[3] + Draw_base));
            }

            painter.setPen(Qt::red);
            painter.drawPolyline(pA, pointnum[3]);

            painter.setPen(Qt::blue);
            painter.drawPolyline(pB, pointnum[3]);
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Widget::PDdrawnewpoint(int DN)
{
    switch(DN)
    {
        case 0:
            ui->widget_D1->update();
            break;
        case 1:
            ui->widget_D2->update();
            break;
        case 2:
            ui->widget_D3->update();
            break;
        case 3:
            ui->widget_D4->update();
            break;
    }
}
