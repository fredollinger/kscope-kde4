/********************************************************************************
** Form generated from reading UI file 'queryviewlayout4.ui'
**
** Created: Sun Oct 9 12:52:32 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYVIEWLAYOUT4_H
#define UI_QUERYVIEWLAYOUT4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "queryview4.h"

QT_BEGIN_NAMESPACE

class Ui_QueryViewLayout
{
public:
    QVBoxLayout *vboxLayout;
    // kscope4::QueryView *m_pView;
    QLabel *textLabel1;
    QFrame *line1;
    QHBoxLayout *hboxLayout;
    QSpacerItem *Horizontal_Spacing2;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *QueryViewLayout)
    {
        if (QueryViewLayout->objectName().isEmpty())
            QueryViewLayout->setObjectName(QString::fromUtf8("QueryViewLayout"));
        QueryViewLayout->resize(654, 499);
        QueryViewLayout->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(QueryViewLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        // m_pView = new kscope4::QueryView(QueryViewLayout);
        // m_pView->setObjectName(QString::fromUtf8("m_pView"));

        // vboxLayout->addWidget(m_pView);

        textLabel1 = new QLabel(QueryViewLayout);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setWordWrap(false);

        vboxLayout->addWidget(textLabel1);

        line1 = new QFrame(QueryViewLayout);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Horizontal_Spacing2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Horizontal_Spacing2);

        buttonOk = new QPushButton(QueryViewLayout);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(true);
        buttonOk->setDefault(true);

        hboxLayout->addWidget(buttonOk);

        buttonCancel = new QPushButton(QueryViewLayout);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(true);

        hboxLayout->addWidget(buttonCancel);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(QueryViewLayout);
        QObject::connect(buttonOk, SIGNAL(clicked()), QueryViewLayout, SLOT(accept()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), QueryViewLayout, SLOT(reject()));

        QMetaObject::connectSlotsByName(QueryViewLayout);
    } // setupUi

    void retranslateUi(QDialog *QueryViewLayout)
    {
        QueryViewLayout->setWindowTitle(QApplication::translate("QueryViewLayout", "Query Results", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("QueryViewLayout", "Right-click inside the list for more options.", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("QueryViewLayout", "&OK", 0, QApplication::UnicodeUTF8));
        buttonOk->setShortcut(QString());
        buttonCancel->setText(QApplication::translate("QueryViewLayout", "&Cancel", 0, QApplication::UnicodeUTF8));
        buttonCancel->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class QueryViewLayout: public Ui_QueryViewLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYVIEWLAYOUT4_H
