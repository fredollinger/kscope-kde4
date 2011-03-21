#ifndef PREFFRONTENDLAYOUT_H
#define PREFFRONTENDLAYOUT_H

#include <qvariant.h>


#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3TextEdit>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "klineedit.h"
#include "kpushbutton.h"
#include "kurlrequester.h"

QT_BEGIN_NAMESPACE

namespace Ui {

class Ui_PrefFrontendLayout
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *textLabel1;
    QLabel *textLabel2;
    QLabel *textLabel1_2;
    QVBoxLayout *vboxLayout2;
    KUrlRequester *m_pCscopeURL;
    KUrlRequester *m_pCtagsURL;
    KUrlRequester *m_pDotURL;
    QFrame *line2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacer8;
    QPushButton *m_pGuessButton;
    Q3TextEdit *m_pScriptText;

    void setupUi(QWidget *PrefFrontendLayout)
    {
        if (PrefFrontendLayout->objectName().isEmpty())
            PrefFrontendLayout->setObjectName(QString::fromUtf8("PrefFrontendLayout"));
        PrefFrontendLayout->resize(415, 368);
        vboxLayout = new QVBoxLayout(PrefFrontendLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        textLabel1 = new QLabel(PrefFrontendLayout);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setWordWrap(false);

        vboxLayout1->addWidget(textLabel1);

        textLabel2 = new QLabel(PrefFrontendLayout);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        sizePolicy.setHeightForWidth(textLabel2->sizePolicy().hasHeightForWidth());
        textLabel2->setSizePolicy(sizePolicy);
        textLabel2->setWordWrap(false);

        vboxLayout1->addWidget(textLabel2);

        textLabel1_2 = new QLabel(PrefFrontendLayout);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setWordWrap(false);

        vboxLayout1->addWidget(textLabel1_2);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        m_pCscopeURL = new KUrlRequester(PrefFrontendLayout);
        m_pCscopeURL->setObjectName(QString::fromUtf8("m_pCscopeURL"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(5));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pCscopeURL->sizePolicy().hasHeightForWidth());
        m_pCscopeURL->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(m_pCscopeURL);

        m_pCtagsURL = new KUrlRequester(PrefFrontendLayout);
        m_pCtagsURL->setObjectName(QString::fromUtf8("m_pCtagsURL"));

        vboxLayout2->addWidget(m_pCtagsURL);

        m_pDotURL = new KUrlRequester(PrefFrontendLayout);
        m_pDotURL->setObjectName(QString::fromUtf8("m_pDotURL"));

        vboxLayout2->addWidget(m_pDotURL);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);

        line2 = new QFrame(PrefFrontendLayout);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacer8 = new QSpacerItem(261, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer8);

        m_pGuessButton = new QPushButton(PrefFrontendLayout);
        m_pGuessButton->setObjectName(QString::fromUtf8("m_pGuessButton"));

        hboxLayout1->addWidget(m_pGuessButton);


        vboxLayout->addLayout(hboxLayout1);

        m_pScriptText = new Q3TextEdit(PrefFrontendLayout);
        m_pScriptText->setObjectName(QString::fromUtf8("m_pScriptText"));
        m_pScriptText->setEnabled(true);
        m_pScriptText->setReadOnly(true);

        vboxLayout->addWidget(m_pScriptText);


        retranslateUi(PrefFrontendLayout);

        QMetaObject::connectSlotsByName(PrefFrontendLayout);
    } // setupUi

    void retranslateUi(QWidget *PrefFrontendLayout)
    {
        PrefFrontendLayout->setWindowTitle(QApplication::translate("PrefFrontendLayout", "Form3", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("PrefFrontendLayout", "Cscope path:", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("PrefFrontendLayout", "Ctags path:", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("PrefFrontendLayout", "Dot path:", 0, QApplication::UnicodeUTF8));
        m_pGuessButton->setText(QApplication::translate("PrefFrontendLayout", "G&uess", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrefFrontendLayout: public Ui_PrefFrontendLayout {};
} // namespace Ui

QT_END_NAMESPACE

class PrefFrontendLayout : public QWidget, public Ui::PrefFrontendLayout
{
    Q_OBJECT

public:
    PrefFrontendLayout(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
    ~PrefFrontendLayout();

protected slots:
    virtual void languageChange();

};

}

#endif // PREFFRONTENDLAYOUT_H
