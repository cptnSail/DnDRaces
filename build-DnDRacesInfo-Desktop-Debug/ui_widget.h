/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *btnDwarf;
    QLabel *dwarf;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnElf;
    QLabel *elf;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnHalfling;
    QLabel *halfling;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnHuman;
    QLabel *human;
    QLabel *Icon;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnGnome;
    QLabel *gnome;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnHalfElf;
    QLabel *halfElf;
    QVBoxLayout *verticalLayout_7;
    QPushButton *btnHalfOrc;
    QLabel *halfOrc;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnTiefling;
    QLabel *tiefling;
    QFrame *line;
    QFrame *line_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(642, 840);
        Widget->setMaximumSize(QSize(642, 840));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setToolTipDuration(-10);
        centralwidget = new QWidget(Widget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnDwarf = new QPushButton(centralwidget);
        btnDwarf->setObjectName(QString::fromUtf8("btnDwarf"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnDwarf->sizePolicy().hasHeightForWidth());
        btnDwarf->setSizePolicy(sizePolicy);
        btnDwarf->setMinimumSize(QSize(200, 200));
        btnDwarf->setMaximumSize(QSize(200, 200));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/src/DwarfOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDwarf->setIcon(icon1);

        verticalLayout->addWidget(btnDwarf);

        dwarf = new QLabel(centralwidget);
        dwarf->setObjectName(QString::fromUtf8("dwarf"));
        dwarf->setTextFormat(Qt::MarkdownText);
        dwarf->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(dwarf);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnElf = new QPushButton(centralwidget);
        btnElf->setObjectName(QString::fromUtf8("btnElf"));
        sizePolicy.setHeightForWidth(btnElf->sizePolicy().hasHeightForWidth());
        btnElf->setSizePolicy(sizePolicy);
        btnElf->setMinimumSize(QSize(200, 200));
        btnElf->setMaximumSize(QSize(200, 200));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/src/ElfOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnElf->setIcon(icon2);

        verticalLayout_2->addWidget(btnElf);

        elf = new QLabel(centralwidget);
        elf->setObjectName(QString::fromUtf8("elf"));
        elf->setTextFormat(Qt::MarkdownText);
        elf->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(elf);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnHalfling = new QPushButton(centralwidget);
        btnHalfling->setObjectName(QString::fromUtf8("btnHalfling"));
        sizePolicy.setHeightForWidth(btnHalfling->sizePolicy().hasHeightForWidth());
        btnHalfling->setSizePolicy(sizePolicy);
        btnHalfling->setMinimumSize(QSize(200, 200));
        btnHalfling->setMaximumSize(QSize(200, 200));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/src/HalfOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHalfling->setIcon(icon3);

        verticalLayout_3->addWidget(btnHalfling);

        halfling = new QLabel(centralwidget);
        halfling->setObjectName(QString::fromUtf8("halfling"));
        halfling->setTextFormat(Qt::MarkdownText);
        halfling->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(halfling);


        gridLayout->addLayout(verticalLayout_3, 1, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnHuman = new QPushButton(centralwidget);
        btnHuman->setObjectName(QString::fromUtf8("btnHuman"));
        sizePolicy.setHeightForWidth(btnHuman->sizePolicy().hasHeightForWidth());
        btnHuman->setSizePolicy(sizePolicy);
        btnHuman->setMinimumSize(QSize(200, 200));
        btnHuman->setMaximumSize(QSize(200, 200));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/src/HumanOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHuman->setIcon(icon4);

        verticalLayout_4->addWidget(btnHuman);

        human = new QLabel(centralwidget);
        human->setObjectName(QString::fromUtf8("human"));
        human->setTextFormat(Qt::MarkdownText);
        human->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(human);


        gridLayout->addLayout(verticalLayout_4, 2, 0, 1, 1);

        Icon = new QLabel(centralwidget);
        Icon->setObjectName(QString::fromUtf8("Icon"));
        Icon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Icon, 2, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        btnGnome = new QPushButton(centralwidget);
        btnGnome->setObjectName(QString::fromUtf8("btnGnome"));
        sizePolicy.setHeightForWidth(btnGnome->sizePolicy().hasHeightForWidth());
        btnGnome->setSizePolicy(sizePolicy);
        btnGnome->setMinimumSize(QSize(200, 200));
        btnGnome->setMaximumSize(QSize(200, 200));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/src/GnomeOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGnome->setIcon(icon5);

        verticalLayout_5->addWidget(btnGnome);

        gnome = new QLabel(centralwidget);
        gnome->setObjectName(QString::fromUtf8("gnome"));
        gnome->setTextFormat(Qt::MarkdownText);
        gnome->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(gnome);


        gridLayout->addLayout(verticalLayout_5, 2, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btnHalfElf = new QPushButton(centralwidget);
        btnHalfElf->setObjectName(QString::fromUtf8("btnHalfElf"));
        sizePolicy.setHeightForWidth(btnHalfElf->sizePolicy().hasHeightForWidth());
        btnHalfElf->setSizePolicy(sizePolicy);
        btnHalfElf->setMinimumSize(QSize(200, 200));
        btnHalfElf->setMaximumSize(QSize(200, 200));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/src/HElfOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHalfElf->setIcon(icon6);

        verticalLayout_6->addWidget(btnHalfElf);

        halfElf = new QLabel(centralwidget);
        halfElf->setObjectName(QString::fromUtf8("halfElf"));
        halfElf->setTextFormat(Qt::MarkdownText);
        halfElf->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(halfElf);


        gridLayout->addLayout(verticalLayout_6, 3, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        btnHalfOrc = new QPushButton(centralwidget);
        btnHalfOrc->setObjectName(QString::fromUtf8("btnHalfOrc"));
        sizePolicy.setHeightForWidth(btnHalfOrc->sizePolicy().hasHeightForWidth());
        btnHalfOrc->setSizePolicy(sizePolicy);
        btnHalfOrc->setMinimumSize(QSize(200, 200));
        btnHalfOrc->setMaximumSize(QSize(200, 200));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/src/HOrcOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHalfOrc->setIcon(icon7);

        verticalLayout_7->addWidget(btnHalfOrc);

        halfOrc = new QLabel(centralwidget);
        halfOrc->setObjectName(QString::fromUtf8("halfOrc"));
        halfOrc->setTextFormat(Qt::MarkdownText);
        halfOrc->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(halfOrc);


        gridLayout->addLayout(verticalLayout_7, 3, 1, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        btnTiefling = new QPushButton(centralwidget);
        btnTiefling->setObjectName(QString::fromUtf8("btnTiefling"));
        sizePolicy.setHeightForWidth(btnTiefling->sizePolicy().hasHeightForWidth());
        btnTiefling->setSizePolicy(sizePolicy);
        btnTiefling->setMinimumSize(QSize(200, 200));
        btnTiefling->setMaximumSize(QSize(200, 200));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/src/TieflingOf.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTiefling->setIcon(icon8);

        verticalLayout_8->addWidget(btnTiefling);

        tiefling = new QLabel(centralwidget);
        tiefling->setObjectName(QString::fromUtf8("tiefling"));
        tiefling->setTextFormat(Qt::MarkdownText);
        tiefling->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(tiefling);


        gridLayout->addLayout(verticalLayout_8, 3, 2, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(5);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 2, 1, 1);

        Widget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Widget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 642, 26));
        Widget->setMenuBar(menubar);
        statusbar = new QStatusBar(Widget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Widget->setStatusBar(statusbar);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QMainWindow *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "D&D Races", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Races", nullptr));
        btnDwarf->setText(QString());
        dwarf->setText(QCoreApplication::translate("Widget", "Dwarf", nullptr));
        btnElf->setText(QString());
        elf->setText(QCoreApplication::translate("Widget", "Elf", nullptr));
        btnHalfling->setText(QString());
        halfling->setText(QCoreApplication::translate("Widget", "Halfling", nullptr));
        btnHuman->setText(QString());
        human->setText(QCoreApplication::translate("Widget", "Human", nullptr));
        Icon->setText(QCoreApplication::translate("Widget", "Icon", nullptr));
        btnGnome->setText(QString());
        gnome->setText(QCoreApplication::translate("Widget", "Gnome", nullptr));
        btnHalfElf->setText(QString());
        halfElf->setText(QCoreApplication::translate("Widget", "Half-Elf", nullptr));
        btnHalfOrc->setText(QString());
        halfOrc->setText(QCoreApplication::translate("Widget", "Half-Orc", nullptr));
        btnTiefling->setText(QString());
        tiefling->setText(QCoreApplication::translate("Widget", "Tiefling", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
