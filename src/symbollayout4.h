/********************************************************************************
** Form generated from reading UI file 'symbollayout4.ui'
**
** Created: Sat Oct 15 16:21:13 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLLAYOUT4_H
#define UI_SYMBOLLAYOUT4_H

#include <Qt3Support/Q3ButtonGroup>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include "kcombobox.h"
#include "khistorycombobox.h"
#include "klineedit.h"

QT_BEGIN_NAMESPACE

class Ui_SymbolLayout
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *textLabel1;
    QLabel *textLabel2;
    QVBoxLayout *vboxLayout2;
    QComboBox *m_pTypeCombo;
    KHistoryComboBox *m_pSymbolHC;
    QCheckBox *m_pSubStringCheck;
    QCheckBox *m_pCaseCheck;
    QFrame *line2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacer2;
    QPushButton *m_pOKButton;
    QPushButton *m_pHintButton;
    QPushButton *m_pCancelButton;
    QTableView *m_pHintList;
    Q3ButtonGroup *m_pHintGroup;
    QVBoxLayout *vboxLayout3;
    QRadioButton *m_pBeginWithRadio;
    QRadioButton *m_pContainRadio;

    void setupUi(QDialog *SymbolLayout)
    {
        if (SymbolLayout->objectName().isEmpty())
            SymbolLayout->setObjectName(QString::fromUtf8("SymbolLayout"));
        SymbolLayout->resize(343, 456);
        vboxLayout = new QVBoxLayout(SymbolLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        textLabel1 = new QLabel(SymbolLayout);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setWordWrap(false);

        vboxLayout1->addWidget(textLabel1);

        textLabel2 = new QLabel(SymbolLayout);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        sizePolicy.setHeightForWidth(textLabel2->sizePolicy().hasHeightForWidth());
        textLabel2->setSizePolicy(sizePolicy);
        textLabel2->setWordWrap(false);

        vboxLayout1->addWidget(textLabel2);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        m_pTypeCombo = new QComboBox(SymbolLayout);
        m_pTypeCombo->setObjectName(QString::fromUtf8("m_pTypeCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pTypeCombo->sizePolicy().hasHeightForWidth());
        m_pTypeCombo->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(m_pTypeCombo);

        m_pSymbolHC = new KHistoryComboBox(SymbolLayout);
        m_pSymbolHC->setObjectName(QString::fromUtf8("m_pSymbolHC"));
        sizePolicy1.setHeightForWidth(m_pSymbolHC->sizePolicy().hasHeightForWidth());
        m_pSymbolHC->setSizePolicy(sizePolicy1);
        m_pSymbolHC->setDuplicatesEnabled(false);

        vboxLayout2->addWidget(m_pSymbolHC);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);

        m_pSubStringCheck = new QCheckBox(SymbolLayout);
        m_pSubStringCheck->setObjectName(QString::fromUtf8("m_pSubStringCheck"));

        vboxLayout->addWidget(m_pSubStringCheck);

        m_pCaseCheck = new QCheckBox(SymbolLayout);
        m_pCaseCheck->setObjectName(QString::fromUtf8("m_pCaseCheck"));

        vboxLayout->addWidget(m_pCaseCheck);

        line2 = new QFrame(SymbolLayout);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacer2 = new QSpacerItem(71, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer2);

        m_pOKButton = new QPushButton(SymbolLayout);
        m_pOKButton->setObjectName(QString::fromUtf8("m_pOKButton"));

        hboxLayout1->addWidget(m_pOKButton);

        m_pHintButton = new QPushButton(SymbolLayout);
        m_pHintButton->setObjectName(QString::fromUtf8("m_pHintButton"));

        hboxLayout1->addWidget(m_pHintButton);

        m_pCancelButton = new QPushButton(SymbolLayout);
        m_pCancelButton->setObjectName(QString::fromUtf8("m_pCancelButton"));

        hboxLayout1->addWidget(m_pCancelButton);


        vboxLayout->addLayout(hboxLayout1);

        m_pHintList = new QTableView(SymbolLayout);
        m_pHintList->setObjectName(QString::fromUtf8("m_pHintList"));

        vboxLayout->addWidget(m_pHintList);

        m_pHintGroup = new Q3ButtonGroup(SymbolLayout);
        m_pHintGroup->setObjectName(QString::fromUtf8("m_pHintGroup"));
        m_pHintGroup->setColumnLayout(0, Qt::Vertical);
        m_pHintGroup->layout()->setSpacing(6);
        m_pHintGroup->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout3 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_pHintGroup->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout3);
        vboxLayout3->setAlignment(Qt::AlignTop);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        m_pBeginWithRadio = new QRadioButton(m_pHintGroup);
        m_pBeginWithRadio->setObjectName(QString::fromUtf8("m_pBeginWithRadio"));

        vboxLayout3->addWidget(m_pBeginWithRadio);

        m_pContainRadio = new QRadioButton(m_pHintGroup);
        m_pContainRadio->setObjectName(QString::fromUtf8("m_pContainRadio"));

        vboxLayout3->addWidget(m_pContainRadio);


        vboxLayout->addWidget(m_pHintGroup);

        QWidget::setTabOrder(m_pSymbolHC, m_pTypeCombo);
        QWidget::setTabOrder(m_pTypeCombo, m_pSubStringCheck);
        QWidget::setTabOrder(m_pSubStringCheck, m_pOKButton);
        QWidget::setTabOrder(m_pOKButton, m_pHintButton);
        QWidget::setTabOrder(m_pHintButton, m_pCancelButton);
        QWidget::setTabOrder(m_pCancelButton, m_pHintList);
        QWidget::setTabOrder(m_pHintList, m_pBeginWithRadio);
        QWidget::setTabOrder(m_pBeginWithRadio, m_pContainRadio);

        retranslateUi(SymbolLayout);

        QMetaObject::connectSlotsByName(SymbolLayout);
    } // setupUi

    void retranslateUi(QDialog *SymbolLayout)
    {
        SymbolLayout->setWindowTitle(QApplication::translate("SymbolLayout", "KScope Query", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("SymbolLayout", "Type", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("SymbolLayout", "Symbol", 0, QApplication::UnicodeUTF8));
        m_pTypeCombo->clear();
        m_pTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("SymbolLayout", "References to", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Definition of", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Functions called by", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Functions calling", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Find text", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Find EGrep pattern", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Find file", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Files #including", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SymbolLayout", "Call graph for", 0, QApplication::UnicodeUTF8)
        );
        m_pSubStringCheck->setText(QApplication::translate("SymbolLayout", "Search for &a Sub-String", 0, QApplication::UnicodeUTF8));
        m_pSubStringCheck->setShortcut(QApplication::translate("SymbolLayout", "Alt+A", 0, QApplication::UnicodeUTF8));
        m_pCaseCheck->setText(QApplication::translate("SymbolLayout", "Case Insensitive", 0, QApplication::UnicodeUTF8));
        m_pOKButton->setText(QApplication::translate("SymbolLayout", "OK", 0, QApplication::UnicodeUTF8));
        m_pHintButton->setText(QApplication::translate("SymbolLayout", "Hi&nt", 0, QApplication::UnicodeUTF8));
        m_pCancelButton->setText(QApplication::translate("SymbolLayout", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pHintGroup->setTitle(QApplication::translate("SymbolLayout", "Hint Options", 0, QApplication::UnicodeUTF8));
        m_pBeginWithRadio->setText(QApplication::translate("SymbolLayout", "S&ymbols Beginning With...", 0, QApplication::UnicodeUTF8));
        m_pContainRadio->setText(QApplication::translate("SymbolLayout", "Sym&bols Containing...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SymbolLayout: public Ui_SymbolLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLLAYOUT4_H
