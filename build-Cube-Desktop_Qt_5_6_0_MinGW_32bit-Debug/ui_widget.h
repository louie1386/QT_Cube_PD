/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget_D1;
    QLabel *label_1;
    QWidget *widget_D2;
    QLabel *label_2;
    QWidget *widget_D3;
    QLabel *label_3;
    QPushButton *pushButton;
    QWidget *widget_D4;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 480);
        widget_D1 = new QWidget(Widget);
        widget_D1->setObjectName(QStringLiteral("widget_D1"));
        widget_D1->setGeometry(QRect(0, 0, 400, 240));
        label_1 = new QLabel(widget_D1);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(10, 10, 121, 31));
        label_1->setStyleSheet(QStringLiteral("font: 12pt \"Arial\";"));
        widget_D2 = new QWidget(Widget);
        widget_D2->setObjectName(QStringLiteral("widget_D2"));
        widget_D2->setGeometry(QRect(0, 240, 400, 240));
        label_2 = new QLabel(widget_D2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 121, 31));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"Arial\";"));
        widget_D3 = new QWidget(Widget);
        widget_D3->setObjectName(QStringLiteral("widget_D3"));
        widget_D3->setGeometry(QRect(400, 0, 400, 240));
        label_3 = new QLabel(widget_D3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 121, 31));
        label_3->setStyleSheet(QStringLiteral("font: 12pt \"Arial\";"));
        pushButton = new QPushButton(widget_D3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(352, 0, 51, 41));
        pushButton->setFlat(true);
        widget_D4 = new QWidget(Widget);
        widget_D4->setObjectName(QStringLiteral("widget_D4"));
        widget_D4->setGeometry(QRect(400, 240, 400, 240));
        label_4 = new QLabel(widget_D4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 121, 31));
        label_4->setStyleSheet(QStringLiteral("font: 12pt \"Arial\";"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_1->setText(QApplication::translate("Widget", "(1)[LED OFF]", 0));
        label_2->setText(QApplication::translate("Widget", "(2)[LED OFF]", 0));
        label_3->setText(QApplication::translate("Widget", "(3)[LED OFF]", 0));
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("Widget", "(4)[LED OFF]", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
