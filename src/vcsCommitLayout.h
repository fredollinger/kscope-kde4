/********************************************************************************
** Form generated from reading UI file 'vcsCommitLayout.ui'
**
** Created: Sun Oct 16 18:51:32 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCSCOMMITLAYOUT_H
#define UI_VCSCOMMITLAYOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vcsCommitLayout
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *textCommitMsg;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *vcsCommitLayout)
    {
        if (vcsCommitLayout->objectName().isEmpty())
            vcsCommitLayout->setObjectName(QString::fromUtf8("vcsCommitLayout"));
        vcsCommitLayout->resize(400, 300);
        verticalLayoutWidget = new QWidget(vcsCommitLayout);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textCommitMsg = new QPlainTextEdit(verticalLayoutWidget);
        textCommitMsg->setObjectName(QString::fromUtf8("textCommitMsg"));

        verticalLayout->addWidget(textCommitMsg);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(vcsCommitLayout);

        QMetaObject::connectSlotsByName(vcsCommitLayout);
    } // setupUi

    void retranslateUi(QDialog *vcsCommitLayout)
    {
        vcsCommitLayout->setWindowTitle(QApplication::translate("vcsCommitLayout", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("vcsCommitLayout", "Enter Commit Message", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class vcsCommitLayout: public Ui_vcsCommitLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCSCOMMITLAYOUT_H
