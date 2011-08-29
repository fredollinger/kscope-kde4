/********************************************************************************
** Form generated from reading UI file 'calltreelayout4.ui'
**
** Created: Sun Aug 28 19:35:49 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALLTREELAYOUT4_H
#define UI_CALLTREELAYOUT4_H

#include <Qt3Support/Q3ButtonGroup>
#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3WidgetStack>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CallTreeLayout
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    Q3ButtonGroup *m_pViewGroup;
    QHBoxLayout *hboxLayout1;
    QToolButton *m_pGraphButton;
    QToolButton *m_pCalledButton;
    QToolButton *m_pCallingButton;
    QFrame *line1;
    Q3ButtonGroup *m_pGraphGroup;
    QHBoxLayout *hboxLayout2;
    QToolButton *m_pSaveButton;
    QToolButton *m_pZoomInButton;
    QToolButton *m_pZoomOutButton;
    QToolButton *m_pRotateButton;
    QToolButton *m_pPrefButton;
    QSpacerItem *spacer2;
    Q3WidgetStack *m_pStack;
    QWidget *WStackPage;
    QVBoxLayout *vboxLayout1;
    QWidget *WStackPage1;
    QVBoxLayout *vboxLayout2;
    QWidget *WStackPage2;
    QVBoxLayout *vboxLayout3;
    QLabel *m_pHelpLabel;

    void setupUi(QWidget *CallTreeLayout)
    {
        if (CallTreeLayout->objectName().isEmpty())
            CallTreeLayout->setObjectName(QString::fromUtf8("CallTreeLayout"));
        CallTreeLayout->resize(695, 578);
        vboxLayout = new QVBoxLayout(CallTreeLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pViewGroup = new Q3ButtonGroup(CallTreeLayout);
        m_pViewGroup->setObjectName(QString::fromUtf8("m_pViewGroup"));
        m_pViewGroup->setFrameShape(Q3GroupBox::NoFrame);
        m_pViewGroup->setLineWidth(0);
        m_pViewGroup->setExclusive(true);
        m_pViewGroup->setColumnLayout(0, Qt::Vertical);
        m_pViewGroup->layout()->setSpacing(6);
        m_pViewGroup->layout()->setContentsMargins(0, 0, 0, 0);
        hboxLayout1 = new QHBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_pViewGroup->layout());
        if (boxlayout)
            boxlayout->addLayout(hboxLayout1);
        hboxLayout1->setAlignment(Qt::AlignTop);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_pGraphButton = new QToolButton(m_pViewGroup);
        m_pGraphButton->setObjectName(QString::fromUtf8("m_pGraphButton"));
        m_pGraphButton->setCheckable(true);
        m_pGraphButton->setAutoRaise(true);

        hboxLayout1->addWidget(m_pGraphButton);

        m_pCalledButton = new QToolButton(m_pViewGroup);
        m_pCalledButton->setObjectName(QString::fromUtf8("m_pCalledButton"));
        m_pCalledButton->setCheckable(true);
        m_pCalledButton->setAutoRaise(true);

        hboxLayout1->addWidget(m_pCalledButton);

        m_pCallingButton = new QToolButton(m_pViewGroup);
        m_pCallingButton->setObjectName(QString::fromUtf8("m_pCallingButton"));
        m_pCallingButton->setCheckable(true);
        m_pCallingButton->setAutoRaise(true);

        hboxLayout1->addWidget(m_pCallingButton);


        hboxLayout->addWidget(m_pViewGroup);

        line1 = new QFrame(CallTreeLayout);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::VLine);
        line1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line1);

        m_pGraphGroup = new Q3ButtonGroup(CallTreeLayout);
        m_pGraphGroup->setObjectName(QString::fromUtf8("m_pGraphGroup"));
        m_pGraphGroup->setFlat(true);
        m_pGraphGroup->setFrameShape(Q3GroupBox::NoFrame);
        m_pGraphGroup->setLineWidth(0);
        m_pGraphGroup->setColumnLayout(0, Qt::Vertical);
        m_pGraphGroup->layout()->setSpacing(6);
        m_pGraphGroup->layout()->setContentsMargins(0, 0, 0, 0);
        hboxLayout2 = new QHBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(m_pGraphGroup->layout());
        if (boxlayout1)
            boxlayout1->addLayout(hboxLayout2);
        hboxLayout2->setAlignment(Qt::AlignTop);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        m_pSaveButton = new QToolButton(m_pGraphGroup);
        m_pSaveButton->setObjectName(QString::fromUtf8("m_pSaveButton"));
        m_pSaveButton->setAutoRaise(true);

        hboxLayout2->addWidget(m_pSaveButton);

        m_pZoomInButton = new QToolButton(m_pGraphGroup);
        m_pZoomInButton->setObjectName(QString::fromUtf8("m_pZoomInButton"));
        m_pZoomInButton->setCheckable(false);
        m_pZoomInButton->setAutoRaise(true);

        hboxLayout2->addWidget(m_pZoomInButton);

        m_pZoomOutButton = new QToolButton(m_pGraphGroup);
        m_pZoomOutButton->setObjectName(QString::fromUtf8("m_pZoomOutButton"));
        m_pZoomOutButton->setCheckable(false);
        m_pZoomOutButton->setAutoRaise(true);

        hboxLayout2->addWidget(m_pZoomOutButton);

        m_pRotateButton = new QToolButton(m_pGraphGroup);
        m_pRotateButton->setObjectName(QString::fromUtf8("m_pRotateButton"));
        m_pRotateButton->setCheckable(false);
        m_pRotateButton->setAutoRaise(true);

        hboxLayout2->addWidget(m_pRotateButton);

        m_pPrefButton = new QToolButton(m_pGraphGroup);
        m_pPrefButton->setObjectName(QString::fromUtf8("m_pPrefButton"));
        m_pPrefButton->setCheckable(false);
        m_pPrefButton->setAutoRaise(true);

        hboxLayout2->addWidget(m_pPrefButton);


        hboxLayout->addWidget(m_pGraphGroup);

        spacer2 = new QSpacerItem(110, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer2);


        vboxLayout->addLayout(hboxLayout);

        m_pStack = new Q3WidgetStack(CallTreeLayout);
        m_pStack->setObjectName(QString::fromUtf8("m_pStack"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pStack->sizePolicy().hasHeightForWidth());
        m_pStack->setSizePolicy(sizePolicy);
        WStackPage = new QWidget(m_pStack);
        WStackPage->setObjectName(QString::fromUtf8("WStackPage"));
        WStackPage->setGeometry(QRect(0, 0, 677, 500));
        vboxLayout1 = new QVBoxLayout(WStackPage);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));

        m_pStack->addWidget(WStackPage, -1);
        WStackPage1 = new QWidget(m_pStack);
        WStackPage1->setObjectName(QString::fromUtf8("WStackPage1"));
        WStackPage1->setGeometry(QRect(0, 0, 100, 30));
        vboxLayout2 = new QVBoxLayout(WStackPage1);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));

        m_pStack->addWidget(WStackPage1, -1);
        WStackPage2 = new QWidget(m_pStack);
        WStackPage2->setObjectName(QString::fromUtf8("WStackPage2"));
        WStackPage2->setGeometry(QRect(0, 0, 100, 30));
        vboxLayout3 = new QVBoxLayout(WStackPage2);
        vboxLayout3->setSpacing(6);
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));

        m_pStack->addWidget(WStackPage2, -1);

        vboxLayout->addWidget(m_pStack);

        m_pHelpLabel = new QLabel(CallTreeLayout);
        m_pHelpLabel->setObjectName(QString::fromUtf8("m_pHelpLabel"));
        m_pHelpLabel->setWordWrap(false);

        vboxLayout->addWidget(m_pHelpLabel);


        retranslateUi(CallTreeLayout);
        QObject::connect(m_pPrefButton, SIGNAL(clicked()), CallTreeLayout, SLOT(slotPrefClicked()));
        QObject::connect(m_pRotateButton, SIGNAL(clicked()), CallTreeLayout, SLOT(slotRotateClicked()));
        QObject::connect(m_pZoomOutButton, SIGNAL(clicked()), CallTreeLayout, SLOT(slotZoomOutClicked()));
        QObject::connect(m_pZoomInButton, SIGNAL(clicked()), CallTreeLayout, SLOT(slotZoomInClicked()));
        QObject::connect(m_pSaveButton, SIGNAL(clicked()), CallTreeLayout, SLOT(slotSaveClicked()));
        QObject::connect(m_pViewGroup, SIGNAL(clicked(int)), CallTreeLayout, SLOT(slotViewChanged(int)));
        QObject::connect(m_pViewGroup, SIGNAL(clicked(int)), m_pStack, SLOT(raiseWidget(int)));

        QMetaObject::connectSlotsByName(CallTreeLayout);
    } // setupUi

    void retranslateUi(QWidget *CallTreeLayout)
    {
        CallTreeLayout->setWindowTitle(QApplication::translate("CallTreeLayout", "Call Graph", 0, QApplication::UnicodeUTF8));
        m_pViewGroup->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        m_pGraphButton->setToolTip(QApplication::translate("CallTreeLayout", "Call Graph", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pGraphButton->setText(QApplication::translate("CallTreeLayout", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pCalledButton->setToolTip(QApplication::translate("CallTreeLayout", "Called Functions Tree", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pCalledButton->setText(QApplication::translate("CallTreeLayout", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pCallingButton->setToolTip(QApplication::translate("CallTreeLayout", "Calling Functions Tree", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pCallingButton->setText(QApplication::translate("CallTreeLayout", "...", 0, QApplication::UnicodeUTF8));
        m_pGraphGroup->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        m_pSaveButton->setToolTip(QApplication::translate("CallTreeLayout", "Save As...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pSaveButton->setText(QApplication::translate("CallTreeLayout", "a", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pZoomInButton->setToolTip(QApplication::translate("CallTreeLayout", "Zoom In", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pZoomInButton->setText(QApplication::translate("CallTreeLayout", "a", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pZoomOutButton->setToolTip(QApplication::translate("CallTreeLayout", "Zoom Out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pZoomOutButton->setText(QApplication::translate("CallTreeLayout", "a", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pRotateButton->setToolTip(QApplication::translate("CallTreeLayout", "Rotate", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pRotateButton->setText(QApplication::translate("CallTreeLayout", "a", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pPrefButton->setToolTip(QApplication::translate("CallTreeLayout", "Preferences", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pPrefButton->setText(QApplication::translate("CallTreeLayout", "a", 0, QApplication::UnicodeUTF8));
        m_pHelpLabel->setText(QApplication::translate("CallTreeLayout", "Help Message", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CallTreeLayout: public Ui_CallTreeLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALLTREELAYOUT4_H
