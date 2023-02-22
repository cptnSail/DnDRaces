/********************************************************************************
** Form generated from reading UI file 'infowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWIDGET_H
#define UI_INFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWidget
{
public:
    QGridLayout *gridMain;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridScroll;
    QLabel *label;

    void setupUi(QWidget *InfoWidget)
    {
        if (InfoWidget->objectName().isEmpty())
            InfoWidget->setObjectName(QString::fromUtf8("InfoWidget"));
        InfoWidget->resize(400, 300);
        gridMain = new QGridLayout(InfoWidget);
        gridMain->setObjectName(QString::fromUtf8("gridMain"));
        gridMain->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(InfoWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 298));
        gridScroll = new QGridLayout(scrollAreaWidgetContents);
        gridScroll->setSpacing(0);
        gridScroll->setObjectName(QString::fromUtf8("gridScroll"));
        gridScroll->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridScroll->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridMain->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(InfoWidget);

        QMetaObject::connectSlotsByName(InfoWidget);
    } // setupUi

    void retranslateUi(QWidget *InfoWidget)
    {
        InfoWidget->setWindowTitle(QCoreApplication::translate("InfoWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("InfoWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWidget: public Ui_InfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWIDGET_H
