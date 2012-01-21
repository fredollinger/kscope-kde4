/********************************************************************************
** Form generated from reading UI file 'symbollayout4.ui'
**
** Created: Sat Jan 21 14:04:06 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLLAYOUT4_H
#define UI_SYMBOLLAYOUT4_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include "kcombobox.h"
#include "khistorycombobox.h"
#include "klineedit.h"

QT_BEGIN_NAMESPACE

class Ui_SymbolLayout
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    KHistoryComboBox *khistorycombobox;
    QComboBox *m_pTypeCombo;
    QHBoxLayout *horizontalLayout;
    QTableWidget *m_pHintList;
    KHistoryComboBox *m_pSymbolHC;

    void setupUi(QDialog *SymbolLayout)
    {
        if (SymbolLayout->objectName().isEmpty())
            SymbolLayout->setObjectName(QString::fromUtf8("SymbolLayout"));
        SymbolLayout->resize(400, 456);
        vboxLayout = new QVBoxLayout(SymbolLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(SymbolLayout);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(SymbolLayout);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        khistorycombobox = new KHistoryComboBox(SymbolLayout);
        khistorycombobox->setObjectName(QString::fromUtf8("khistorycombobox"));

        verticalLayout_2->addWidget(khistorycombobox);

        m_pTypeCombo = new QComboBox(SymbolLayout);
        m_pTypeCombo->setObjectName(QString::fromUtf8("m_pTypeCombo"));

        verticalLayout_2->addWidget(m_pTypeCombo);


        horizontalLayout_2->addLayout(verticalLayout_2);


        vboxLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        vboxLayout->addLayout(horizontalLayout);

        m_pHintList = new QTableWidget(SymbolLayout);
        m_pHintList->setObjectName(QString::fromUtf8("m_pHintList"));

        vboxLayout->addWidget(m_pHintList);

        m_pSymbolHC = new KHistoryComboBox(SymbolLayout);
        m_pSymbolHC->setObjectName(QString::fromUtf8("m_pSymbolHC"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pSymbolHC->sizePolicy().hasHeightForWidth());
        m_pSymbolHC->setSizePolicy(sizePolicy);
        m_pSymbolHC->setDuplicatesEnabled(false);

        vboxLayout->addWidget(m_pSymbolHC);


        retranslateUi(SymbolLayout);

        QMetaObject::connectSlotsByName(SymbolLayout);
    } // setupUi

    void retranslateUi(QDialog *SymbolLayout)
    {
        SymbolLayout->setWindowTitle(QApplication::translate("SymbolLayout", "KScope Query", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SymbolLayout", "Type", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SymbolLayout", "Symbol", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SymbolLayout: public Ui_SymbolLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLLAYOUT4_H
