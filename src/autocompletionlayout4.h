/********************************************************************************
** Form generated from reading UI file 'autocompletionlayout4.ui'
**
** Created: Sat Jun 18 01:46:08 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCOMPLETIONLAYOUT4_H
#define UI_AUTOCOMPLETIONLAYOUT4_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AutoCompletionLayout
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *auto_qhbl5;
    QLabel *textLabel1;
    QSpacerItem *spacer15;
    QSpinBox *m_pMinCharsSpin;
    QHBoxLayout *auto_qhbl2;
    QLabel *textLabel2;
    QSpacerItem *spacer16;
    QSpinBox *m_pDelaySpin;
    QHBoxLayout *auto_qhbl3;
    QLabel *textLabel3;
    QSpacerItem *spacer17;
    QSpinBox *m_pMaxEntriesSpin;
    QSpacerItem *spacer19;
    QHBoxLayout *auto_qhbl1;
    QSpacerItem *spacer18;
    QPushButton *m_pOKButton;
    QPushButton *m_pCancelButton;

    void setupUi(QDialog *AutoCompletionLayout)
    {
        if (AutoCompletionLayout->objectName().isEmpty())
            AutoCompletionLayout->setObjectName(QString::fromUtf8("AutoCompletionLayout"));
        AutoCompletionLayout->resize(287, 183);
        vboxLayout = new QVBoxLayout(AutoCompletionLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        auto_qhbl5 = new QHBoxLayout();
        auto_qhbl5->setSpacing(6);
        auto_qhbl5->setObjectName(QString::fromUtf8("auto_qhbl5"));
        textLabel1 = new QLabel(AutoCompletionLayout);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        auto_qhbl5->addWidget(textLabel1);

        spacer15 = new QSpacerItem(71, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        auto_qhbl5->addItem(spacer15);

        m_pMinCharsSpin = new QSpinBox(AutoCompletionLayout);
        m_pMinCharsSpin->setObjectName(QString::fromUtf8("m_pMinCharsSpin"));

        auto_qhbl5->addWidget(m_pMinCharsSpin);


        vboxLayout->addLayout(auto_qhbl5);

        auto_qhbl2 = new QHBoxLayout();
        auto_qhbl2->setSpacing(6);
        auto_qhbl2->setObjectName(QString::fromUtf8("auto_qhbl2"));
        textLabel2 = new QLabel(AutoCompletionLayout);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        textLabel2->setWordWrap(false);

        auto_qhbl2->addWidget(textLabel2);

        spacer16 = new QSpacerItem(101, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        auto_qhbl2->addItem(spacer16);

        m_pDelaySpin = new QSpinBox(AutoCompletionLayout);
        m_pDelaySpin->setObjectName(QString::fromUtf8("m_pDelaySpin"));
        m_pDelaySpin->setMaximum(10000);
        m_pDelaySpin->setSingleStep(100);

        auto_qhbl2->addWidget(m_pDelaySpin);


        vboxLayout->addLayout(auto_qhbl2);

        auto_qhbl3 = new QHBoxLayout();
        auto_qhbl3->setSpacing(6);
        auto_qhbl3->setObjectName(QString::fromUtf8("auto_qhbl3"));
        textLabel3 = new QLabel(AutoCompletionLayout);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        textLabel3->setWordWrap(false);

        auto_qhbl3->addWidget(textLabel3);

        spacer17 = new QSpacerItem(81, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        auto_qhbl3->addItem(spacer17);

        m_pMaxEntriesSpin = new QSpinBox(AutoCompletionLayout);
        m_pMaxEntriesSpin->setObjectName(QString::fromUtf8("m_pMaxEntriesSpin"));
        m_pMaxEntriesSpin->setMinimum(1);
        m_pMaxEntriesSpin->setMaximum(1000);

        auto_qhbl3->addWidget(m_pMaxEntriesSpin);


        vboxLayout->addLayout(auto_qhbl3);

        spacer19 = new QSpacerItem(20, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        vboxLayout->addItem(spacer19);

        auto_qhbl1 = new QHBoxLayout();
        auto_qhbl1->setSpacing(6);
        auto_qhbl1->setObjectName(QString::fromUtf8("auto_qhbl1"));
        spacer18 = new QSpacerItem(111, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        auto_qhbl1->addItem(spacer18);

        m_pOKButton = new QPushButton(AutoCompletionLayout);
        m_pOKButton->setObjectName(QString::fromUtf8("m_pOKButton"));

        auto_qhbl1->addWidget(m_pOKButton);

        m_pCancelButton = new QPushButton(AutoCompletionLayout);
        m_pCancelButton->setObjectName(QString::fromUtf8("m_pCancelButton"));

        auto_qhbl1->addWidget(m_pCancelButton);


        vboxLayout->addLayout(auto_qhbl1);


        retranslateUi(AutoCompletionLayout);

        QMetaObject::connectSlotsByName(AutoCompletionLayout);
    } // setupUi

    void retranslateUi(QDialog *AutoCompletionLayout)
    {
        AutoCompletionLayout->setWindowTitle(QApplication::translate("AutoCompletionLayout", "Auto-Completion Properties", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("AutoCompletionLayout", "Minimum Characters", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("AutoCompletionLayout", "Delay (ms)", 0, QApplication::UnicodeUTF8));
        textLabel3->setText(QApplication::translate("AutoCompletionLayout", "Maximum Entries", 0, QApplication::UnicodeUTF8));
        m_pOKButton->setText(QApplication::translate("AutoCompletionLayout", "OK", 0, QApplication::UnicodeUTF8));
        m_pCancelButton->setText(QApplication::translate("AutoCompletionLayout", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AutoCompletionLayout: public Ui_AutoCompletionLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCOMPLETIONLAYOUT4_H
