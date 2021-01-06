/********************************************************************************
** Form generated from reading UI file 'finish_work.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISH_WORK_H
#define UI_FINISH_WORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myledit.h>

QT_BEGIN_NAMESPACE

class Ui_finish_work
{
public:
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_31;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    MyLEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    MyLEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_25;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    MyLEdit *lineEdit_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    MyLEdit *lineEdit_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    MyLEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    MyLEdit *lineEdit_5;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_26;
    QHBoxLayout *horizontalLayout_32;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_4;
    MyLEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    MyLEdit *lineEdit_12;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_17;
    MyLEdit *lineEdit_15;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    MyLEdit *lineEdit_14;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_2;
    MyLEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_3;
    MyLEdit *lineEdit_18;
    QHBoxLayout *horizontalLayout_28;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_20;
    QLineEdit *lineEdit_20;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_21;
    MyLEdit *lineEdit_21;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_18;
    MyLEdit *lineEdit_16;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_19;
    MyLEdit *lineEdit_17;

    void setupUi(QWidget *finish_work)
    {
        if (finish_work->objectName().isEmpty())
            finish_work->setObjectName(QStringLiteral("finish_work"));
        finish_work->resize(1177, 579);
        verticalLayout_11 = new QVBoxLayout(finish_work);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox_4 = new QGroupBox(finish_work);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font;
        font.setPointSize(12);
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QLatin1String(" QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        horizontalLayout_27 = new QHBoxLayout(groupBox_4);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font1;
        font1.setPointSize(16);
        label_7->setFont(font1);

        horizontalLayout_4->addWidget(label_7);

        lineEdit_6 = new MyLEdit(groupBox_4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(0, 40));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(241, 97, 97, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_6->setPalette(palette);
        lineEdit_6->setFont(font1);
        lineEdit_6->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_6);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);

        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        horizontalLayout_9->addWidget(label_8);

        lineEdit_7 = new MyLEdit(groupBox_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setEnabled(true);
        lineEdit_7->setMinimumSize(QSize(0, 40));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_7->setPalette(palette1);
        lineEdit_7->setFont(font1);
        lineEdit_7->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(lineEdit_7);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 5);

        gridLayout->addLayout(horizontalLayout_9, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 60));
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(14);
        pushButton->setFont(font2);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 60));
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));
        pushButton_2->setFont(font2);
        pushButton_2->setMouseTracking(false);

        horizontalLayout->addWidget(pushButton_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        horizontalLayout_31->addLayout(gridLayout);


        verticalLayout_7->addLayout(horizontalLayout_31);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_14->addWidget(label_14);

        lineEdit_13 = new MyLEdit(groupBox_4);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setMinimumSize(QSize(0, 40));
        lineEdit_13->setFont(font1);
        lineEdit_13->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_13);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        horizontalLayout_12->addWidget(label_11);

        lineEdit_10 = new MyLEdit(groupBox_4);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        lineEdit_10->setMinimumSize(QSize(0, 40));
        lineEdit_10->setFont(font1);
        lineEdit_10->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(lineEdit_10);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout_12);


        horizontalLayout_25->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_13->addWidget(label_12);

        lineEdit_11 = new MyLEdit(groupBox_4);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setMinimumSize(QSize(0, 40));
        lineEdit_11->setFont(font1);
        lineEdit_11->setStyleSheet(QLatin1String("color:black;\n"
""));
        lineEdit_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(lineEdit_11);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_3->addWidget(label_5);

        lineEdit_5 = new MyLEdit(groupBox_4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setMinimumSize(QSize(0, 40));
        lineEdit_5->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_5->setFont(font1);
        lineEdit_5->setStyleSheet(QLatin1String("color:black;\n"
""));
        lineEdit_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_5);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_25->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout_25);

        verticalLayout_7->setStretch(0, 3);
        verticalLayout_7->setStretch(1, 2);

        verticalLayout_8->addLayout(verticalLayout_7);


        horizontalLayout_27->addLayout(verticalLayout_8);


        verticalLayout_11->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(finish_work);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QLatin1String(" QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        horizontalLayout_26 = new QHBoxLayout(groupBox_3);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral(""));

        horizontalLayout_16->addWidget(label_4);

        lineEdit_3 = new MyLEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setMinimumSize(QSize(0, 40));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_3->setPalette(palette2);
        lineEdit_3->setFont(font1);
        lineEdit_3->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_3);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 6);

        verticalLayout_9->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_15->setFont(font3);
        label_15->setStyleSheet(QStringLiteral(""));

        horizontalLayout_17->addWidget(label_15);

        lineEdit_12 = new MyLEdit(groupBox_3);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setEnabled(false);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_12->setPalette(palette3);
        lineEdit_12->setFont(font1);
        lineEdit_12->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(lineEdit_12);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 6);

        verticalLayout_9->addLayout(horizontalLayout_17);


        horizontalLayout_32->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);
        label_17->setStyleSheet(QStringLiteral(""));

        horizontalLayout_19->addWidget(label_17);

        lineEdit_15 = new MyLEdit(groupBox_3);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setEnabled(true);
        QFont font4;
        font4.setPointSize(18);
        lineEdit_15->setFont(font4);
        lineEdit_15->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(lineEdit_15);

        horizontalLayout_19->setStretch(0, 1);
        horizontalLayout_19->setStretch(1, 4);

        verticalLayout_10->addLayout(horizontalLayout_19);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);
        label_16->setStyleSheet(QStringLiteral(""));

        horizontalLayout_18->addWidget(label_16);

        lineEdit_14 = new MyLEdit(groupBox_3);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setEnabled(true);
        lineEdit_14->setFont(font4);
        lineEdit_14->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(lineEdit_14);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 4);

        verticalLayout_10->addLayout(horizontalLayout_18);


        horizontalLayout_32->addLayout(verticalLayout_10);

        horizontalLayout_32->setStretch(0, 3);
        horizontalLayout_32->setStretch(1, 2);

        horizontalLayout_26->addLayout(horizontalLayout_32);


        verticalLayout_11->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(finish_work);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QLatin1String(" QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_11->addWidget(label_2);

        lineEdit_2 = new MyLEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_2->setPalette(palette4);
        lineEdit_2->setFont(font4);
        lineEdit_2->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_2->setEchoMode(QLineEdit::Normal);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(lineEdit_2);


        horizontalLayout_24->addLayout(horizontalLayout_11);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral(""));

        horizontalLayout_22->addWidget(label_3);

        lineEdit_18 = new MyLEdit(groupBox_2);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setEnabled(true);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_18->setPalette(palette5);
        lineEdit_18->setFont(font4);
        lineEdit_18->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(lineEdit_18);


        horizontalLayout_24->addLayout(horizontalLayout_22);


        verticalLayout_5->addLayout(horizontalLayout_24);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);
        label_20->setStyleSheet(QStringLiteral(""));

        horizontalLayout_29->addWidget(label_20);

        lineEdit_20 = new QLineEdit(groupBox_2);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setEnabled(false);
        lineEdit_20->setFont(font4);
        lineEdit_20->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_29->addWidget(lineEdit_20);


        horizontalLayout_28->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);
        label_21->setStyleSheet(QStringLiteral(""));

        horizontalLayout_30->addWidget(label_21);

        lineEdit_21 = new MyLEdit(groupBox_2);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setEnabled(true);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_21->setPalette(palette6);
        lineEdit_21->setFont(font4);
        lineEdit_21->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_30->addWidget(lineEdit_21);


        horizontalLayout_28->addLayout(horizontalLayout_30);


        verticalLayout_5->addLayout(horizontalLayout_28);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_11->addWidget(groupBox_2);

        groupBox = new QGroupBox(finish_work);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String(" QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        horizontalLayout_15 = new QHBoxLayout(groupBox);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);
        label_18->setStyleSheet(QStringLiteral(""));

        horizontalLayout_20->addWidget(label_18);

        lineEdit_16 = new MyLEdit(groupBox);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setEnabled(false);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_16->setPalette(palette7);
        lineEdit_16->setFont(font4);
        lineEdit_16->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_20->addWidget(lineEdit_16);


        horizontalLayout_8->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);
        label_19->setStyleSheet(QStringLiteral(""));

        horizontalLayout_21->addWidget(label_19);

        lineEdit_17 = new MyLEdit(groupBox);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setEnabled(true);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_17->setPalette(palette8);
        lineEdit_17->setFont(font4);
        lineEdit_17->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(lineEdit_17);


        horizontalLayout_8->addLayout(horizontalLayout_21);


        horizontalLayout_15->addLayout(horizontalLayout_8);


        verticalLayout_11->addWidget(groupBox);

        verticalLayout_11->setStretch(0, 5);
        verticalLayout_11->setStretch(1, 2);
        verticalLayout_11->setStretch(2, 2);
        verticalLayout_11->setStretch(3, 1);

        retranslateUi(finish_work);

        QMetaObject::connectSlotsByName(finish_work);
    } // setupUi

    void retranslateUi(QWidget *finish_work)
    {
        finish_work->setWindowTitle(QApplication::translate("finish_work", "Form", 0));
        groupBox_4->setTitle(QApplication::translate("finish_work", "\345\212\240\345\267\245\344\277\241\346\201\257", 0));
        label_7->setText(QApplication::translate("finish_work", "\346\210\220\345\223\201\346\225\260\351\207\217", 0));
        label_8->setText(QApplication::translate("finish_work", "\345\276\205\345\244\204\347\220\206\346\225\260", 0));
        pushButton->setText(QApplication::translate("finish_work", "\345\211\251\344\275\231\346\225\260", 0));
        pushButton_2->setText(QApplication::translate("finish_work", "\346\240\207\347\256\261\346\225\260", 0));
        label_14->setText(QApplication::translate("finish_work", "\350\241\250\351\235\242\345\244\204\347\220\206", 0));
        label_11->setText(QApplication::translate("finish_work", "\345\267\245\344\275\234\346\227\266\351\225\277", 0));
        lineEdit_10->setPlaceholderText(QApplication::translate("finish_work", "\345\210\206\351\222\237", 0));
        label_12->setText(QApplication::translate("finish_work", "\347\203\255\345\244\204\347\220\206\345\217\267", 0));
        label_5->setText(QApplication::translate("finish_work", "\345\275\223\345\211\215\346\227\266\351\227\264", 0));
        groupBox_3->setTitle(QApplication::translate("finish_work", "\345\267\245\345\272\217\344\277\241\346\201\257", 0));
        label_4->setText(QApplication::translate("finish_work", "\347\224\237\344\272\247\344\273\244\345\217\267", 0));
        label_15->setText(QApplication::translate("finish_work", "\347\211\251\346\226\231\344\277\241\346\201\257", 0));
        lineEdit_12->setText(QString());
        label_17->setText(QApplication::translate("finish_work", "\344\272\247\345\223\201\346\211\271\346\254\241", 0));
        label_16->setText(QApplication::translate("finish_work", "\346\243\200\351\252\214\346\212\245\345\221\212", 0));
        groupBox_2->setTitle(QApplication::translate("finish_work", "\350\256\276\345\244\207\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("finish_work", "\350\256\276\345\244\207\345\217\267    ", 0));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("finish_work", "\350\256\276\345\244\207\345\220\215", 0));
        label_20->setText(QApplication::translate("finish_work", "\350\243\205\346\250\241\346\270\205\345\215\225", 0));
        label_21->setText(QApplication::translate("finish_work", "\345\234\260    \347\202\271", 0));
        groupBox->setTitle(QApplication::translate("finish_work", "\345\221\230\345\267\245\344\277\241\346\201\257", 0));
        label_18->setText(QApplication::translate("finish_work", "\345\267\245        \345\217\267 ", 0));
        label_19->setText(QApplication::translate("finish_work", "\345\247\223    \345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class finish_work: public Ui_finish_work {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISH_WORK_H
