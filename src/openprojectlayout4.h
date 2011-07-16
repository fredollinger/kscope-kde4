/********************************************************************************
** Form generated from reading UI file 'openprojectlayout4.ui'
**
** Created: Sat Jul 16 18:59:10 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENPROJECTLAYOUT4_H
#define UI_OPENPROJECTLAYOUT4_H

#include <Qt3Support/Q3ButtonGroup>
#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3ListBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "klineedit.h"
#include "kpushbutton.h"
#include "kurlrequester.h"

QT_BEGIN_NAMESPACE

class Ui_OpenProjectLayout
{
public:
    QVBoxLayout *vboxLayout;
    Q3ButtonGroup *buttonGroup5;
    QHBoxLayout *hboxLayout;
    KURLRequester *m_pProjPathRequester;
    Q3ButtonGroup *buttonGroup6;
    QVBoxLayout *vboxLayout1;
    Q3ListBox *m_pRecentList;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacer4;
    QPushButton *m_pRemoveButton;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacer6;
    QPushButton *m_pOpenButton;
    QPushButton *m_pCancelButton;

    void setupUi(QDialog *OpenProjectLayout)
    {
        if (OpenProjectLayout->objectName().isEmpty())
            OpenProjectLayout->setObjectName(QString::fromUtf8("OpenProjectLayout"));
        OpenProjectLayout->resize(417, 384);
        vboxLayout = new QVBoxLayout(OpenProjectLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        buttonGroup5 = new Q3ButtonGroup(OpenProjectLayout);
        buttonGroup5->setObjectName(QString::fromUtf8("buttonGroup5"));
        buttonGroup5->setColumnLayout(0, Qt::Vertical);
        buttonGroup5->layout()->setSpacing(6);
        buttonGroup5->layout()->setContentsMargins(11, 11, 11, 11);
        hboxLayout = new QHBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(buttonGroup5->layout());
        if (boxlayout)
            boxlayout->addLayout(hboxLayout);
        hboxLayout->setAlignment(Qt::AlignTop);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pProjPathRequester = new KURLRequester(buttonGroup5);
        m_pProjPathRequester->setObjectName(QString::fromUtf8("m_pProjPathRequester"));

        hboxLayout->addWidget(m_pProjPathRequester);


        vboxLayout->addWidget(buttonGroup5);

        buttonGroup6 = new Q3ButtonGroup(OpenProjectLayout);
        buttonGroup6->setObjectName(QString::fromUtf8("buttonGroup6"));
        buttonGroup6->setColumnLayout(0, Qt::Vertical);
        buttonGroup6->layout()->setSpacing(6);
        buttonGroup6->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout1 = new QVBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(buttonGroup6->layout());
        if (boxlayout1)
            boxlayout1->addLayout(vboxLayout1);
        vboxLayout1->setAlignment(Qt::AlignTop);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        m_pRecentList = new Q3ListBox(buttonGroup6);
        m_pRecentList->setObjectName(QString::fromUtf8("m_pRecentList"));

        vboxLayout1->addWidget(m_pRecentList);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacer4 = new QSpacerItem(281, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer4);

        m_pRemoveButton = new QPushButton(buttonGroup6);
        m_pRemoveButton->setObjectName(QString::fromUtf8("m_pRemoveButton"));

        hboxLayout1->addWidget(m_pRemoveButton);


        vboxLayout1->addLayout(hboxLayout1);


        vboxLayout->addWidget(buttonGroup6);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacer6 = new QSpacerItem(201, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer6);

        m_pOpenButton = new QPushButton(OpenProjectLayout);
        m_pOpenButton->setObjectName(QString::fromUtf8("m_pOpenButton"));
        m_pOpenButton->setDefault(true);

        hboxLayout2->addWidget(m_pOpenButton);

        m_pCancelButton = new QPushButton(OpenProjectLayout);
        m_pCancelButton->setObjectName(QString::fromUtf8("m_pCancelButton"));

        hboxLayout2->addWidget(m_pCancelButton);


        vboxLayout->addLayout(hboxLayout2);


        retranslateUi(OpenProjectLayout);
        QObject::connect(m_pOpenButton, SIGNAL(clicked()), OpenProjectLayout, SLOT(accept()));
        QObject::connect(m_pCancelButton, SIGNAL(clicked()), OpenProjectLayout, SLOT(reject()));
        QObject::connect(m_pRemoveButton, SIGNAL(clicked()), OpenProjectLayout, SLOT(slotRemoveRecent()));
        QObject::connect(m_pRecentList, SIGNAL(highlighted(Q3ListBoxItem*)), OpenProjectLayout, SLOT(slotSelectRecent(Q3ListBoxItem*)));
        QObject::connect(m_pRecentList, SIGNAL(doubleClicked(Q3ListBoxItem*)), OpenProjectLayout, SLOT(slotOpenRecent(Q3ListBoxItem*)));
        QObject::connect(m_pProjPathRequester, SIGNAL(urlSelected(QString)), OpenProjectLayout, SLOT(slotProjectSelected(QString)));
        QObject::connect(m_pRecentList, SIGNAL(returnPressed(Q3ListBoxItem*)), OpenProjectLayout, SLOT(slotOpenRecent(Q3ListBoxItem*)));

        QMetaObject::connectSlotsByName(OpenProjectLayout);
    } // setupUi

    void retranslateUi(QDialog *OpenProjectLayout)
    {
        OpenProjectLayout->setWindowTitle(QApplication::translate("OpenProjectLayout", "Open Project", 0, QApplication::UnicodeUTF8));
        buttonGroup5->setTitle(QApplication::translate("OpenProjectLayout", "Project Path", 0, QApplication::UnicodeUTF8));
        buttonGroup6->setTitle(QApplication::translate("OpenProjectLayout", "Recent Projects", 0, QApplication::UnicodeUTF8));
        m_pRemoveButton->setText(QApplication::translate("OpenProjectLayout", "Remove", 0, QApplication::UnicodeUTF8));
        m_pOpenButton->setText(QApplication::translate("OpenProjectLayout", "&Open", 0, QApplication::UnicodeUTF8));
        m_pOpenButton->setShortcut(QApplication::translate("OpenProjectLayout", "Alt+O", 0, QApplication::UnicodeUTF8));
        m_pCancelButton->setText(QApplication::translate("OpenProjectLayout", "C&ancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenProjectLayout: public Ui_OpenProjectLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPROJECTLAYOUT4_H
