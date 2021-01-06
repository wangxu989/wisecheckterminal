/********************************************************************************
** Form generated from reading UI file 'programwork.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMWORK_H
#define UI_PROGRAMWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgramWork
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ProgramWork)
    {
        if (ProgramWork->objectName().isEmpty())
            ProgramWork->setObjectName(QStringLiteral("ProgramWork"));
        ProgramWork->resize(836, 507);
        horizontalLayout_3 = new QHBoxLayout(ProgramWork);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(ProgramWork);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(widget);


        retranslateUi(ProgramWork);

        QMetaObject::connectSlotsByName(ProgramWork);
    } // setupUi

    void retranslateUi(QWidget *ProgramWork)
    {
        ProgramWork->setWindowTitle(QApplication::translate("ProgramWork", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ProgramWork", "\350\257\267\346\211\253\346\217\217\345\221\230\345\267\245\343\200\201\350\256\276\345\244\207\343\200\201\347\224\237\344\272\247\344\273\244\344\272\214\347\273\264\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProgramWork: public Ui_ProgramWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMWORK_H
