#ifndef AUTOCOMPLETIONLAYOUT_H
#define AUTOCOMPLETIONLAYOUT_H

#include <qvariant.h>


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
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1;
    QSpacerItem *spacer15;
    QSpinBox *m_pMinCharsSpin;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabel2;
    QSpacerItem *spacer16;
    QSpinBox *m_pDelaySpin;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel3;
    QSpacerItem *spacer17;
    QSpinBox *m_pMaxEntriesSpin;
    QSpacerItem *spacer19;
    QHBoxLayout *hboxLayout3;
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
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1 = new QLabel(AutoCompletionLayout);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout->addWidget(textLabel1);

        spacer15 = new QSpacerItem(71, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer15);

        m_pMinCharsSpin = new QSpinBox(AutoCompletionLayout);
        m_pMinCharsSpin->setObjectName(QString::fromUtf8("m_pMinCharsSpin"));

        hboxLayout->addWidget(m_pMinCharsSpin);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        textLabel2 = new QLabel(AutoCompletionLayout);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        textLabel2->setWordWrap(false);

        hboxLayout1->addWidget(textLabel2);

        spacer16 = new QSpacerItem(101, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer16);

        m_pDelaySpin = new QSpinBox(AutoCompletionLayout);
        m_pDelaySpin->setObjectName(QString::fromUtf8("m_pDelaySpin"));
        m_pDelaySpin->setMaximum(10000);
        m_pDelaySpin->setSingleStep(100);

        hboxLayout1->addWidget(m_pDelaySpin);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel3 = new QLabel(AutoCompletionLayout);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        textLabel3->setWordWrap(false);

        hboxLayout2->addWidget(textLabel3);

        spacer17 = new QSpacerItem(81, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer17);

        m_pMaxEntriesSpin = new QSpinBox(AutoCompletionLayout);
        m_pMaxEntriesSpin->setObjectName(QString::fromUtf8("m_pMaxEntriesSpin"));
        m_pMaxEntriesSpin->setMaximum(1000);
        m_pMaxEntriesSpin->setMinimum(1);

        hboxLayout2->addWidget(m_pMaxEntriesSpin);


        vboxLayout->addLayout(hboxLayout2);

        spacer19 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer19);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        spacer18 = new QSpacerItem(111, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer18);

        m_pOKButton = new QPushButton(AutoCompletionLayout);
        m_pOKButton->setObjectName(QString::fromUtf8("m_pOKButton"));

        hboxLayout3->addWidget(m_pOKButton);

        m_pCancelButton = new QPushButton(AutoCompletionLayout);
        m_pCancelButton->setObjectName(QString::fromUtf8("m_pCancelButton"));

        hboxLayout3->addWidget(m_pCancelButton);


        vboxLayout->addLayout(hboxLayout3);


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

class AutoCompletionLayout : public QDialog, public Ui::AutoCompletionLayout
{
    Q_OBJECT

public:
    AutoCompletionLayout(QWidget* parent = 0, const char* name = 0, bool modal = false, Qt::WindowFlags fl = 0);
    ~AutoCompletionLayout();

protected slots:
    virtual void languageChange();

};

#endif // AUTOCOMPLETIONLAYOUT_H
