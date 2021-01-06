/********************************************************************************
** Form generated from reading UI file 'analysis.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSIS_H
#define UI_ANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analysis
{
public:

    void setupUi(QWidget *analysis)
    {
        if (analysis->objectName().isEmpty())
            analysis->setObjectName(QStringLiteral("analysis"));
        analysis->resize(400, 300);

        retranslateUi(analysis);

        QMetaObject::connectSlotsByName(analysis);
    } // setupUi

    void retranslateUi(QWidget *analysis)
    {
        analysis->setWindowTitle(QApplication::translate("analysis", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class analysis: public Ui_analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSIS_H
