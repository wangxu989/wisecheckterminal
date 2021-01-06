/********************************************************************************
** Form generated from reading UI file 'startwork.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWORK_H
#define UI_STARTWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myledit.h>

QT_BEGIN_NAMESPACE

class Ui_startwork
{
public:
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    MyLEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    MyLEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    MyLEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_15;
    QLineEdit *lineEdit_12;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_16;
    MyLEdit *lineEdit_13;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    MyLEdit *lineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    MyLEdit *lineEdit_10;

    void setupUi(QWidget *startwork)
    {
        if (startwork->objectName().isEmpty())
            startwork->setObjectName(QStringLiteral("startwork"));
        startwork->resize(1247, 606);
        verticalLayout_9 = new QVBoxLayout(startwork);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        groupBox_3 = new QGroupBox(startwork);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font;
        font.setPointSize(18);
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
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setPointSize(16);
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_4);

        lineEdit_3 = new MyLEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setMinimumSize(QSize(0, 40));
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
        lineEdit_3->setPalette(palette);
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setMinimumSize(QSize(0, 40));
        lineEdit_4->setFont(font);
        lineEdit_4->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setMinimumSize(QSize(0, 40));
        lineEdit_5->setFont(font);
        lineEdit_5->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 4);

        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(label_7);

        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setEnabled(false);
        lineEdit_6->setMinimumSize(QSize(0, 40));
        lineEdit_6->setFont(font);
        lineEdit_6->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_6);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_6);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_9->addWidget(groupBox_3);

        groupBox = new QGroupBox(startwork);
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
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(label_2);

        lineEdit_2 = new MyLEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setMinimumSize(QSize(0, 40));
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
        lineEdit_2->setPalette(palette1);
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEdit_2);


        horizontalLayout_15->addLayout(horizontalLayout_7);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QStringLiteral(""));

        horizontalLayout_14->addWidget(label_14);

        lineEdit_11 = new MyLEdit(groupBox);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setEnabled(false);
        lineEdit_11->setMinimumSize(QSize(0, 40));
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
        lineEdit_11->setPalette(palette2);
        lineEdit_11->setFont(font);
        lineEdit_11->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(lineEdit_11);


        horizontalLayout_15->addLayout(horizontalLayout_14);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 1);

        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QStringLiteral(""));

        horizontalLayout_16->addWidget(label_15);

        lineEdit_12 = new QLineEdit(groupBox);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setEnabled(false);
        lineEdit_12->setMinimumSize(QSize(0, 40));
        lineEdit_12->setFont(font);
        lineEdit_12->setStyleSheet(QStringLiteral("color:black;"));
        lineEdit_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(lineEdit_12);


        horizontalLayout_13->addLayout(horizontalLayout_16);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);
        label_16->setStyleSheet(QStringLiteral(""));

        horizontalLayout_19->addWidget(label_16);

        lineEdit_13 = new MyLEdit(groupBox);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setEnabled(false);
        lineEdit_13->setMinimumSize(QSize(0, 40));
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
        lineEdit_13->setPalette(palette3);
        lineEdit_13->setFont(font);
        lineEdit_13->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(lineEdit_13);


        horizontalLayout_13->addLayout(horizontalLayout_19);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);

        verticalLayout_7->addLayout(horizontalLayout_13);


        verticalLayout_5->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(verticalLayout_5);


        verticalLayout_9->addWidget(groupBox);

        groupBox_2 = new QGroupBox(startwork);
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
        horizontalLayout_18 = new QHBoxLayout(groupBox_2);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_6->addWidget(label);

        lineEdit = new MyLEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(0, 40));
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
        lineEdit->setPalette(palette4);
        lineEdit->setFont(font);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit);


        horizontalLayout_12->addLayout(horizontalLayout_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral(""));

        horizontalLayout_11->addWidget(label_12);

        lineEdit_10 = new MyLEdit(groupBox_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        lineEdit_10->setMinimumSize(QSize(0, 40));
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
        lineEdit_10->setPalette(palette5);
        lineEdit_10->setFont(font);
        lineEdit_10->setStyleSheet(QLatin1String("color:black;\n"
"background-color:rgb(241,97,97)"));
        lineEdit_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(lineEdit_10);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_12);


        horizontalLayout_18->addLayout(verticalLayout_2);


        verticalLayout_9->addWidget(groupBox_2);

        verticalLayout_9->setStretch(0, 2);
        verticalLayout_9->setStretch(1, 2);
        verticalLayout_9->setStretch(2, 1);
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox->raise();

        retranslateUi(startwork);

        QMetaObject::connectSlotsByName(startwork);
    } // setupUi

    void retranslateUi(QWidget *startwork)
    {
        startwork->setWindowTitle(QApplication::translate("startwork", "Form", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("startwork", "\345\267\245\345\272\217\344\277\241\346\201\257", Q_NULLPTR));
        label_4->setText(QApplication::translate("startwork", "\347\224\237\344\272\247\344\273\244\345\217\267", Q_NULLPTR));
        label_5->setText(QApplication::translate("startwork", "\347\211\251\346\226\231\344\277\241\346\201\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("startwork", "\345\274\272\345\210\266\346\243\200\351\252\214", Q_NULLPTR));
        label_7->setText(QApplication::translate("startwork", "\346\240\207\347\256\261\346\225\260\351\207\217", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("startwork", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("startwork", "\350\256\276\345\244\207\345\217\267    ", Q_NULLPTR));
        label_14->setText(QApplication::translate("startwork", "\350\256\276\345\244\207\345\220\215", Q_NULLPTR));
        label_15->setText(QApplication::translate("startwork", "\350\243\205\346\250\241\346\270\205\345\215\225", Q_NULLPTR));
        label_16->setText(QApplication::translate("startwork", "\345\234\260    \347\202\271", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("startwork", "\345\221\230\345\267\245\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("startwork", "\345\267\245        \345\217\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("startwork", "\345\247\223    \345\220\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class startwork: public Ui_startwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWORK_H
