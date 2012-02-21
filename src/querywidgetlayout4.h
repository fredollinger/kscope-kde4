/********************************************************************************
** Form generated from reading UI file 'querywidgetlayout4.ui'
**
** Created: Fri Nov 25 19:38:53 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYWIDGETLAYOUT4_H
#define UI_QUERYWIDGETLAYOUT4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "tabwidget4.h"

QT_BEGIN_NAMESPACE

class Ui_QueryWidgetLayout
{
public:
    QHBoxLayout *hboxLayout;
    kscope4::TabWidget *m_pQueryTabs;

    void setupUi(QWidget *QueryWidgetLayout)
    {
        if (QueryWidgetLayout->objectName().isEmpty())
            QueryWidgetLayout->setObjectName(QString::fromUtf8("QueryWidgetLayout"));
        QueryWidgetLayout->resize(740, 343);
        hboxLayout = new QHBoxLayout(QueryWidgetLayout);
        hboxLayout->setSpacing(0);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pQueryTabs = new kscope4::TabWidget(QueryWidgetLayout);
        m_pQueryTabs->setObjectName(QString::fromUtf8("m_pQueryTabs"));

        hboxLayout->addWidget(m_pQueryTabs);


        retranslateUi(QueryWidgetLayout);

        QMetaObject::connectSlotsByName(QueryWidgetLayout);
    } // setupUi

    void retranslateUi(QWidget *QueryWidgetLayout)
    {
        QueryWidgetLayout->setWindowTitle(QApplication::translate("QueryWidgetLayout", "Form2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QueryWidgetLayout: public Ui_QueryWidgetLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYWIDGETLAYOUT4_H
