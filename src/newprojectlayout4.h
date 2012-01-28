/********************************************************************************
** Form generated from reading UI file 'newprojectlayout4.ui'
**
** Created: Sat Jan 28 09:44:35 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NEWPROJECTLAYOUT4_H
#define NEWPROJECTLAYOUT4_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3ListBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3TextEdit>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kbuttongroup.h"
#include "klineedit.h"
#include "kpushbutton.h"
#include "kurlrequester.h"

QT_BEGIN_NAMESPACE

class Ui_NewProjectLayout
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *tabWidget2;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    QGridLayout *qgl1;
    QLabel *textLabel2;
    QLineEdit *m_pNameEdit;
    QLabel *textLabel1;
    KUrlRequester *m_pPathRequester;
    QCheckBox *m_pHiddenDirCheck;
    QHBoxLayout *qhbl2;
    QLabel *textLabel1_2;
    KUrlRequester *m_pSrcRootRequester;
    QLabel *textLabel1_3;
    QSpacerItem *spacer29;
    QWidget *tab1;
    QHBoxLayout *hboxLayout;
    Q3GroupBox *groupBox1;
    QVBoxLayout *vboxLayout2;
    Q3ListBox *m_pTypesList;
    QVBoxLayout *qvbl2;
    QSpacerItem *spacer7;
    QPushButton *m_pAddButton;
    QPushButton *m_pRemoveButton;
    QSpacerItem *spacer2;
    Q3GroupBox *groupBox2;
    QVBoxLayout *vboxLayout3;
    QLineEdit *m_pTypesEdit;
    Q3ListBox *m_pAvailTypesList;
    QSpacerItem *spacer8_2;
    QWidget *TabPage1;
    QVBoxLayout *vboxLayout4;
    QCheckBox *m_pKernelCheck;
    QCheckBox *m_pInvCheck;
    QCheckBox *m_pNoCompCheck;
    QCheckBox *m_pSlowPathCheck;
    QHBoxLayout *qhbl3;
    QCheckBox *m_pAutoRebuildCheck;
    QSpacerItem *spacer32;
    QLabel *m_pAutoRebuildLabel;
    QSpinBox *m_pAutoRebuildSpin;
    QHBoxLayout *qhbl4_2;
    QCheckBox *m_pACCheck;
    QSpacerItem *spacer33;
    QPushButton *m_pACButton;
    QHBoxLayout *qhbl4;
    QCheckBox *m_pTabWidthCheck;
    QSpacerItem *spacer9;
    QSpinBox *m_pTabWidthSpin;
    QSpacerItem *spacer31;
    QWidget *TabPage2;
    QVBoxLayout *vboxLayout5;
    QLabel *textLabel1_4;
    Q3TextEdit *m_pCtagsCmdEdit;
    QWidget *VCS;
    KButtonGroup *m_kbuttongroupVcs;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonvcsNone;
    QRadioButton *radioButtonVcsGit;
    QRadioButton *radioButtonVcsP4;
    QHBoxLayout *qhbl1;
    QSpacerItem *spacer8;
    QPushButton *m_pCreateButton;
    QPushButton *m_pCancelButton;

    void setupUi(QDialog *NewProjectLayout)
    {
        if (NewProjectLayout->objectName().isEmpty())
            NewProjectLayout->setObjectName(QString::fromUtf8("NewProjectLayout"));
        NewProjectLayout->resize(539, 383);
        vboxLayout = new QVBoxLayout(NewProjectLayout);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        tabWidget2 = new QTabWidget(NewProjectLayout);
        tabWidget2->setObjectName(QString::fromUtf8("tabWidget2"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        vboxLayout1 = new QVBoxLayout(tab);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        qgl1 = new QGridLayout();
        qgl1->setSpacing(6);
        qgl1->setObjectName(QString::fromUtf8("qgl1"));
        textLabel2 = new QLabel(tab);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        textLabel2->setWordWrap(false);

        qgl1->addWidget(textLabel2, 1, 0, 1, 1);

        m_pNameEdit = new QLineEdit(tab);
        m_pNameEdit->setObjectName(QString::fromUtf8("m_pNameEdit"));

        qgl1->addWidget(m_pNameEdit, 0, 1, 1, 1);

        textLabel1 = new QLabel(tab);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        qgl1->addWidget(textLabel1, 0, 0, 1, 1);

        m_pPathRequester = new KUrlRequester(tab);
        m_pPathRequester->setObjectName(QString::fromUtf8("m_pPathRequester"));

        qgl1->addWidget(m_pPathRequester, 1, 1, 1, 1);


        vboxLayout1->addLayout(qgl1);

        m_pHiddenDirCheck = new QCheckBox(tab);
        m_pHiddenDirCheck->setObjectName(QString::fromUtf8("m_pHiddenDirCheck"));

        vboxLayout1->addWidget(m_pHiddenDirCheck);

        qhbl2 = new QHBoxLayout();
        qhbl2->setSpacing(6);
        qhbl2->setObjectName(QString::fromUtf8("qhbl2"));
        textLabel1_2 = new QLabel(tab);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setWordWrap(false);

        qhbl2->addWidget(textLabel1_2);

        m_pSrcRootRequester = new KUrlRequester(tab);
        m_pSrcRootRequester->setObjectName(QString::fromUtf8("m_pSrcRootRequester"));

        qhbl2->addWidget(m_pSrcRootRequester);


        vboxLayout1->addLayout(qhbl2);

        textLabel1_3 = new QLabel(tab);
        textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));
        textLabel1_3->setAlignment(Qt::AlignVCenter);
        textLabel1_3->setWordWrap(true);

        vboxLayout1->addWidget(textLabel1_3);

        spacer29 = new QSpacerItem(31, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacer29);

        tabWidget2->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        hboxLayout = new QHBoxLayout(tab1);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox1 = new Q3GroupBox(tab1);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        groupBox1->setColumnLayout(0, Qt::Vertical);
        groupBox1->layout()->setSpacing(6);
        groupBox1->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout2 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(groupBox1->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout2);
        vboxLayout2->setAlignment(Qt::AlignTop);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        m_pTypesList = new Q3ListBox(groupBox1);
        m_pTypesList->setObjectName(QString::fromUtf8("m_pTypesList"));

        vboxLayout2->addWidget(m_pTypesList);


        hboxLayout->addWidget(groupBox1);

        qvbl2 = new QVBoxLayout();
        qvbl2->setSpacing(6);
        qvbl2->setObjectName(QString::fromUtf8("qvbl2"));
        spacer7 = new QSpacerItem(21, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        qvbl2->addItem(spacer7);

        m_pAddButton = new QPushButton(tab1);
        m_pAddButton->setObjectName(QString::fromUtf8("m_pAddButton"));

        qvbl2->addWidget(m_pAddButton);

        m_pRemoveButton = new QPushButton(tab1);
        m_pRemoveButton->setObjectName(QString::fromUtf8("m_pRemoveButton"));

        qvbl2->addWidget(m_pRemoveButton);

        spacer2 = new QSpacerItem(21, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        qvbl2->addItem(spacer2);


        hboxLayout->addLayout(qvbl2);

        groupBox2 = new Q3GroupBox(tab1);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setColumnLayout(0, Qt::Vertical);
        groupBox2->layout()->setSpacing(6);
        groupBox2->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout3 = new QVBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(groupBox2->layout());
        if (boxlayout1)
            boxlayout1->addLayout(vboxLayout3);
        vboxLayout3->setAlignment(Qt::AlignTop);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        m_pTypesEdit = new QLineEdit(groupBox2);
        m_pTypesEdit->setObjectName(QString::fromUtf8("m_pTypesEdit"));

        vboxLayout3->addWidget(m_pTypesEdit);

        m_pAvailTypesList = new Q3ListBox(groupBox2);
        m_pAvailTypesList->setObjectName(QString::fromUtf8("m_pAvailTypesList"));

        vboxLayout3->addWidget(m_pAvailTypesList);


        hboxLayout->addWidget(groupBox2);

        spacer8_2 = new QSpacerItem(61, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer8_2);

        tabWidget2->addTab(tab1, QString());
        TabPage1 = new QWidget();
        TabPage1->setObjectName(QString::fromUtf8("TabPage1"));
        vboxLayout4 = new QVBoxLayout(TabPage1);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setContentsMargins(11, 11, 11, 11);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        m_pKernelCheck = new QCheckBox(TabPage1);
        m_pKernelCheck->setObjectName(QString::fromUtf8("m_pKernelCheck"));

        vboxLayout4->addWidget(m_pKernelCheck);

        m_pInvCheck = new QCheckBox(TabPage1);
        m_pInvCheck->setObjectName(QString::fromUtf8("m_pInvCheck"));

        vboxLayout4->addWidget(m_pInvCheck);

        m_pNoCompCheck = new QCheckBox(TabPage1);
        m_pNoCompCheck->setObjectName(QString::fromUtf8("m_pNoCompCheck"));

        vboxLayout4->addWidget(m_pNoCompCheck);

        m_pSlowPathCheck = new QCheckBox(TabPage1);
        m_pSlowPathCheck->setObjectName(QString::fromUtf8("m_pSlowPathCheck"));

        vboxLayout4->addWidget(m_pSlowPathCheck);

        qhbl3 = new QHBoxLayout();
        qhbl3->setSpacing(6);
        qhbl3->setObjectName(QString::fromUtf8("qhbl3"));
        m_pAutoRebuildCheck = new QCheckBox(TabPage1);
        m_pAutoRebuildCheck->setObjectName(QString::fromUtf8("m_pAutoRebuildCheck"));

        qhbl3->addWidget(m_pAutoRebuildCheck);

        spacer32 = new QSpacerItem(125, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        qhbl3->addItem(spacer32);

        m_pAutoRebuildLabel = new QLabel(TabPage1);
        m_pAutoRebuildLabel->setObjectName(QString::fromUtf8("m_pAutoRebuildLabel"));
        m_pAutoRebuildLabel->setEnabled(false);
        m_pAutoRebuildLabel->setWordWrap(false);

        qhbl3->addWidget(m_pAutoRebuildLabel);

        m_pAutoRebuildSpin = new QSpinBox(TabPage1);
        m_pAutoRebuildSpin->setObjectName(QString::fromUtf8("m_pAutoRebuildSpin"));
        m_pAutoRebuildSpin->setEnabled(false);

        qhbl3->addWidget(m_pAutoRebuildSpin);


        vboxLayout4->addLayout(qhbl3);

        qhbl4_2 = new QHBoxLayout();
        qhbl4_2->setSpacing(6);
        qhbl4_2->setObjectName(QString::fromUtf8("qhbl4_2"));
        m_pACCheck = new QCheckBox(TabPage1);
        m_pACCheck->setObjectName(QString::fromUtf8("m_pACCheck"));

        qhbl4_2->addWidget(m_pACCheck);

        spacer33 = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        qhbl4_2->addItem(spacer33);

        m_pACButton = new QPushButton(TabPage1);
        m_pACButton->setObjectName(QString::fromUtf8("m_pACButton"));
        m_pACButton->setEnabled(false);

        qhbl4_2->addWidget(m_pACButton);


        vboxLayout4->addLayout(qhbl4_2);

        qhbl4 = new QHBoxLayout();
        qhbl4->setSpacing(6);
        qhbl4->setObjectName(QString::fromUtf8("qhbl4"));
        m_pTabWidthCheck = new QCheckBox(TabPage1);
        m_pTabWidthCheck->setObjectName(QString::fromUtf8("m_pTabWidthCheck"));

        qhbl4->addWidget(m_pTabWidthCheck);

        spacer9 = new QSpacerItem(211, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        qhbl4->addItem(spacer9);

        m_pTabWidthSpin = new QSpinBox(TabPage1);
        m_pTabWidthSpin->setObjectName(QString::fromUtf8("m_pTabWidthSpin"));
        m_pTabWidthSpin->setEnabled(false);

        qhbl4->addWidget(m_pTabWidthSpin);


        vboxLayout4->addLayout(qhbl4);

        spacer31 = new QSpacerItem(21, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout4->addItem(spacer31);

        tabWidget2->addTab(TabPage1, QString());
        TabPage2 = new QWidget();
        TabPage2->setObjectName(QString::fromUtf8("TabPage2"));
        vboxLayout5 = new QVBoxLayout(TabPage2);
        vboxLayout5->setSpacing(6);
        vboxLayout5->setContentsMargins(11, 11, 11, 11);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        textLabel1_4 = new QLabel(TabPage2);
        textLabel1_4->setObjectName(QString::fromUtf8("textLabel1_4"));
        textLabel1_4->setWordWrap(false);

        vboxLayout5->addWidget(textLabel1_4);

        m_pCtagsCmdEdit = new Q3TextEdit(TabPage2);
        m_pCtagsCmdEdit->setObjectName(QString::fromUtf8("m_pCtagsCmdEdit"));
        m_pCtagsCmdEdit->setTextFormat(Qt::PlainText);
        m_pCtagsCmdEdit->setAutoFormatting(Q3TextEdit::AutoAll);

        vboxLayout5->addWidget(m_pCtagsCmdEdit);

        tabWidget2->addTab(TabPage2, QString());
        VCS = new QWidget();
        VCS->setObjectName(QString::fromUtf8("VCS"));
        m_kbuttongroupVcs = new KButtonGroup(VCS);
        m_kbuttongroupVcs->setObjectName(QString::fromUtf8("m_kbuttongroupVcs"));
        m_kbuttongroupVcs->setGeometry(QRect(0, 0, 511, 301));
        m_kbuttongroupVcs->setProperty("current", QVariant(-1));
        verticalLayoutWidget = new QWidget(m_kbuttongroupVcs);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, -10, 511, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonvcsNone = new QRadioButton(verticalLayoutWidget);
        radioButtonvcsNone->setObjectName(QString::fromUtf8("radioButtonvcsNone"));
        radioButtonvcsNone->setChecked(true);

        verticalLayout->addWidget(radioButtonvcsNone);

        radioButtonVcsGit = new QRadioButton(verticalLayoutWidget);
        radioButtonVcsGit->setObjectName(QString::fromUtf8("radioButtonVcsGit"));

        verticalLayout->addWidget(radioButtonVcsGit);

        radioButtonVcsP4 = new QRadioButton(verticalLayoutWidget);
        radioButtonVcsP4->setObjectName(QString::fromUtf8("radioButtonVcsP4"));

        verticalLayout->addWidget(radioButtonVcsP4);

        tabWidget2->addTab(VCS, QString());

        vboxLayout->addWidget(tabWidget2);

        qhbl1 = new QHBoxLayout();
        qhbl1->setSpacing(6);
        qhbl1->setObjectName(QString::fromUtf8("qhbl1"));
        spacer8 = new QSpacerItem(141, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        qhbl1->addItem(spacer8);

        m_pCreateButton = new QPushButton(NewProjectLayout);
        m_pCreateButton->setObjectName(QString::fromUtf8("m_pCreateButton"));
        m_pCreateButton->setDefault(true);

        qhbl1->addWidget(m_pCreateButton);

        m_pCancelButton = new QPushButton(NewProjectLayout);
        m_pCancelButton->setObjectName(QString::fromUtf8("m_pCancelButton"));

        qhbl1->addWidget(m_pCancelButton);


        vboxLayout->addLayout(qhbl1);

        QWidget::setTabOrder(m_pNameEdit, m_pPathRequester);
        QWidget::setTabOrder(m_pPathRequester, m_pHiddenDirCheck);
        QWidget::setTabOrder(m_pHiddenDirCheck, m_pSrcRootRequester);
        QWidget::setTabOrder(m_pSrcRootRequester, m_pAddButton);
        QWidget::setTabOrder(m_pAddButton, m_pRemoveButton);
        QWidget::setTabOrder(m_pRemoveButton, m_pKernelCheck);
        QWidget::setTabOrder(m_pKernelCheck, m_pInvCheck);
        QWidget::setTabOrder(m_pInvCheck, m_pNoCompCheck);
        QWidget::setTabOrder(m_pNoCompCheck, m_pSlowPathCheck);
        QWidget::setTabOrder(m_pSlowPathCheck, m_pAutoRebuildCheck);
        QWidget::setTabOrder(m_pAutoRebuildCheck, m_pAutoRebuildSpin);
        QWidget::setTabOrder(m_pAutoRebuildSpin, m_pACCheck);
        QWidget::setTabOrder(m_pACCheck, m_pACButton);
        QWidget::setTabOrder(m_pACButton, m_pTabWidthCheck);
        QWidget::setTabOrder(m_pTabWidthCheck, m_pTabWidthSpin);
        QWidget::setTabOrder(m_pTabWidthSpin, m_pCreateButton);
        QWidget::setTabOrder(m_pCreateButton, m_pCancelButton);
        QWidget::setTabOrder(m_pCancelButton, tabWidget2);
        QWidget::setTabOrder(tabWidget2, m_pTypesList);
        QWidget::setTabOrder(m_pTypesList, m_pTypesEdit);
        QWidget::setTabOrder(m_pTypesEdit, m_pAvailTypesList);
        QWidget::setTabOrder(m_pAvailTypesList, m_pCtagsCmdEdit);

        retranslateUi(NewProjectLayout);
        QObject::connect(m_pAddButton, SIGNAL(clicked()), NewProjectLayout, SLOT(slotAddType()));
        QObject::connect(m_pRemoveButton, SIGNAL(clicked()), NewProjectLayout, SLOT(slotRemoveType()));
        QObject::connect(m_pAutoRebuildCheck, SIGNAL(toggled(bool)), m_pAutoRebuildSpin, SLOT(setEnabled(bool)));
        QObject::connect(m_pACCheck, SIGNAL(toggled(bool)), m_pACButton, SLOT(setEnabled(bool)));
        QObject::connect(m_pAvailTypesList, SIGNAL(highlighted(QString)), NewProjectLayout, SLOT(slotAvailTypesChanged(QString)));
        QObject::connect(m_pTabWidthCheck, SIGNAL(toggled(bool)), m_pTabWidthSpin, SLOT(setEnabled(bool)));
        QObject::connect(m_pAutoRebuildCheck, SIGNAL(toggled(bool)), m_pAutoRebuildLabel, SLOT(setEnabled(bool)));
        QObject::connect(m_pHiddenDirCheck, SIGNAL(toggled(bool)), m_pPathRequester, SLOT(setDisabled(bool)));

        tabWidget2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(NewProjectLayout);
    } // setupUi

    void retranslateUi(QDialog *NewProjectLayout)
    {
        NewProjectLayout->setWindowTitle(QApplication::translate("NewProjectLayout", "Create Project", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("NewProjectLayout", "Path", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pNameEdit->setWhatsThis(QApplication::translate("NewProjectLayout", "Enter a name for this project.\n"
"The name must conform to the file system's naming conventions for directories (e.g., no spaces, exclamaion marks, etc.).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textLabel1->setText(QApplication::translate("NewProjectLayout", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pPathRequester->setWhatsThis(QApplication::translate("NewProjectLayout", "The path to hold this project.\n"
"KScope will create a directory with the given name under this project, and populate it with the project configuration and database files.\n"
"This does not need to be the path in which the source files reside.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pHiddenDirCheck->setText(QApplication::translate("NewProjectLayout", "&Use a hidden folder under the source root directory", 0, QApplication::UnicodeUTF8));
        m_pHiddenDirCheck->setShortcut(QApplication::translate("NewProjectLayout", "Alt+U", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("NewProjectLayout", "Source Root (Optional)", 0, QApplication::UnicodeUTF8));
        textLabel1_3->setText(QApplication::translate("NewProjectLayout", "<blockquote>A project consists of several files located in a directory\n"
" with the given name and path. The project's name needs to be a valid directory\n"
"name and must not contain any whitespace.</blockquote>\n"
"<br>\n"
"<blockquote>The Source Root is a convinient way to specify a common\n"
"path for all source files, but is not required.</blockquote>", 0, QApplication::UnicodeUTF8));
        tabWidget2->setTabText(tabWidget2->indexOf(tab), QApplication::translate("NewProjectLayout", "Detai&ls", 0, QApplication::UnicodeUTF8));
        groupBox1->setTitle(QApplication::translate("NewProjectLayout", "This Project", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pTypesList->setWhatsThis(QApplication::translate("NewProjectLayout", "KScope uses these filters to locate source files to include in this project.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pAddButton->setWhatsThis(QApplication::translate("NewProjectLayout", "Adds the selected file type to the current project.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pAddButton->setText(QApplication::translate("NewProjectLayout", "<< &Add", 0, QApplication::UnicodeUTF8));
        m_pAddButton->setShortcut(QApplication::translate("NewProjectLayout", "Alt+A", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pRemoveButton->setWhatsThis(QApplication::translate("NewProjectLayout", "Remove the selected file type from the project.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pRemoveButton->setText(QApplication::translate("NewProjectLayout", ">> &Remove", 0, QApplication::UnicodeUTF8));
        m_pRemoveButton->setShortcut(QApplication::translate("NewProjectLayout", "Alt+R", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QApplication::translate("NewProjectLayout", "Available Types", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pTypesEdit->setWhatsThis(QApplication::translate("NewProjectLayout", "You can enter custom file types here.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pAvailTypesList->clear();
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.c", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.h", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.l", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.y", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.S", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.cc", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.cpp", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.cxx", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.C", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.hh", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.hpp", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.hxx", 0, QApplication::UnicodeUTF8));
        m_pAvailTypesList->insertItem(QApplication::translate("NewProjectLayout", "*.H", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pAvailTypesList->setWhatsThis(QApplication::translate("NewProjectLayout", "A list of standard file types.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        tabWidget2->setTabText(tabWidget2->indexOf(tab1), QApplication::translate("NewProjectLayout", "File T&ypes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pKernelCheck->setWhatsThis(QApplication::translate("NewProjectLayout", "For kernel projects, symbols are not looked up in the standard include path.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pKernelCheck->setText(QApplication::translate("NewProjectLayout", "Kernel project (-k)", 0, QApplication::UnicodeUTF8));
        m_pKernelCheck->setShortcut(QString());
#ifndef QT_NO_WHATSTHIS
        m_pInvCheck->setWhatsThis(QApplication::translate("NewProjectLayout", "An inverted index may greatly speed up searches in a large project. The project's building process is longer, though.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pInvCheck->setText(QApplication::translate("NewProjectLayout", "Build inverted inde&x (-q)", 0, QApplication::UnicodeUTF8));
        m_pInvCheck->setShortcut(QApplication::translate("NewProjectLayout", "Alt+X", 0, QApplication::UnicodeUTF8));
        m_pNoCompCheck->setText(QApplication::translate("NewProjectLayout", "Do not compress the database (-c)", 0, QApplication::UnicodeUTF8));
        m_pNoCompCheck->setShortcut(QString());
        m_pSlowPathCheck->setText(QApplication::translate("NewProjectLayout", "Slower, but more accurate, function definition detection (-D)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pAutoRebuildCheck->setWhatsThis(QApplication::translate("NewProjectLayout", "Rebuild the database after changed files are saved to disk.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pAutoRebuildCheck->setText(QApplication::translate("NewProjectLayout", "Refresh data&base automatically", 0, QApplication::UnicodeUTF8));
        m_pAutoRebuildCheck->setShortcut(QApplication::translate("NewProjectLayout", "Alt+B", 0, QApplication::UnicodeUTF8));
        m_pAutoRebuildLabel->setText(QApplication::translate("NewProjectLayout", "(Seconds)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pAutoRebuildSpin->setWhatsThis(QApplication::translate("NewProjectLayout", "Wait this number of seconds after the last save before rebuilding the database.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pACCheck->setWhatsThis(QApplication::translate("NewProjectLayout", "As-you-type symbol completion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pACCheck->setText(QApplication::translate("NewProjectLayout", "&Use symbol auto-completion", 0, QApplication::UnicodeUTF8));
        m_pACCheck->setShortcut(QApplication::translate("NewProjectLayout", "Alt+U", 0, QApplication::UnicodeUTF8));
        m_pACButton->setText(QApplication::translate("NewProjectLayout", "Options...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pTabWidthCheck->setToolTip(QApplication::translate("NewProjectLayout", "Overrides the editor's configured tab width", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pTabWidthCheck->setText(QApplication::translate("NewProjectLayout", "Override default tab width (Kate only)", 0, QApplication::UnicodeUTF8));
        tabWidget2->setTabText(tabWidget2->indexOf(TabPage1), QApplication::translate("NewProjectLayout", "&Options", 0, QApplication::UnicodeUTF8));
        textLabel1_4->setText(QApplication::translate("NewProjectLayout", "Ctags command line (Do not change unless you know what you are doing!)", 0, QApplication::UnicodeUTF8));
        tabWidget2->setTabText(tabWidget2->indexOf(TabPage2), QApplication::translate("NewProjectLayout", "&Advanced", 0, QApplication::UnicodeUTF8));
        m_kbuttongroupVcs->setTitle(QApplication::translate("NewProjectLayout", "Select the Appropriate Version Control System for this Project", 0, QApplication::UnicodeUTF8));
        radioButtonvcsNone->setText(QApplication::translate("NewProjectLayout", "None", 0, QApplication::UnicodeUTF8));
        radioButtonVcsGit->setText(QApplication::translate("NewProjectLayout", "git", 0, QApplication::UnicodeUTF8));
        radioButtonVcsP4->setText(QApplication::translate("NewProjectLayout", "Perforce", 0, QApplication::UnicodeUTF8));
        tabWidget2->setTabText(tabWidget2->indexOf(VCS), QApplication::translate("NewProjectLayout", "Version Control", 0, QApplication::UnicodeUTF8));
        m_pCreateButton->setText(QApplication::translate("NewProjectLayout", "&Create", 0, QApplication::UnicodeUTF8));
        m_pCancelButton->setText(QApplication::translate("NewProjectLayout", "Ca&ncel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewProjectLayout: public Ui_NewProjectLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NEWPROJECTLAYOUT4_H
