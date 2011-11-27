/********************************************************************************
** Form generated from reading UI file 'openprojectdlg2.ui'
**
** Created: Sun Nov 27 09:33:35 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENPROJECTDLG2_H
#define UI_OPENPROJECTDLG2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OpenProjectDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *pathEdit_;
    QToolButton *browseButton_;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *recentProjectsList_;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *removeProjectButton_;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *newButton_;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *openButton_;
    QPushButton *cancelButton_;

    void setupUi(QDialog *OpenProjectDialog)
    {
        if (OpenProjectDialog->objectName().isEmpty())
            OpenProjectDialog->setObjectName(QString::fromUtf8("OpenProjectDialog"));
        OpenProjectDialog->setEnabled(true);
        OpenProjectDialog->resize(485, 418);
        verticalLayout_2 = new QVBoxLayout(OpenProjectDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(OpenProjectDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pathEdit_ = new QLineEdit(OpenProjectDialog);
        pathEdit_->setObjectName(QString::fromUtf8("pathEdit_"));

        horizontalLayout->addWidget(pathEdit_);

        browseButton_ = new QToolButton(OpenProjectDialog);
        browseButton_->setObjectName(QString::fromUtf8("browseButton_"));

        horizontalLayout->addWidget(browseButton_);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(OpenProjectDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        recentProjectsList_ = new QListWidget(groupBox);
        recentProjectsList_->setObjectName(QString::fromUtf8("recentProjectsList_"));

        verticalLayout->addWidget(recentProjectsList_);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        removeProjectButton_ = new QPushButton(groupBox);
        removeProjectButton_->setObjectName(QString::fromUtf8("removeProjectButton_"));
        removeProjectButton_->setEnabled(false);

        horizontalLayout_2->addWidget(removeProjectButton_);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        newButton_ = new QPushButton(OpenProjectDialog);
        newButton_->setObjectName(QString::fromUtf8("newButton_"));

        horizontalLayout_3->addWidget(newButton_);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        openButton_ = new QPushButton(OpenProjectDialog);
        openButton_->setObjectName(QString::fromUtf8("openButton_"));
        openButton_->setEnabled(false);
        openButton_->setDefault(true);

        horizontalLayout_3->addWidget(openButton_);

        cancelButton_ = new QPushButton(OpenProjectDialog);
        cancelButton_->setObjectName(QString::fromUtf8("cancelButton_"));

        horizontalLayout_3->addWidget(cancelButton_);


        verticalLayout_2->addLayout(horizontalLayout_3);

        QWidget::setTabOrder(pathEdit_, browseButton_);
        QWidget::setTabOrder(browseButton_, recentProjectsList_);
        QWidget::setTabOrder(recentProjectsList_, removeProjectButton_);
        QWidget::setTabOrder(removeProjectButton_, newButton_);
        QWidget::setTabOrder(newButton_, openButton_);
        QWidget::setTabOrder(openButton_, cancelButton_);

        retranslateUi(OpenProjectDialog);
        QObject::connect(cancelButton_, SIGNAL(clicked()), OpenProjectDialog, SLOT(reject()));
        QObject::connect(newButton_, SIGNAL(clicked()), OpenProjectDialog, SLOT(newProject()));
        QObject::connect(pathEdit_, SIGNAL(textChanged(QString)), OpenProjectDialog, SLOT(pathChanged(QString)));
        QObject::connect(recentProjectsList_, SIGNAL(itemSelectionChanged()), OpenProjectDialog, SLOT(recentProjectSelected()));
        QObject::connect(removeProjectButton_, SIGNAL(clicked()), OpenProjectDialog, SLOT(removeProject()));
        QObject::connect(browseButton_, SIGNAL(clicked()), OpenProjectDialog, SLOT(browse()));
        QObject::connect(openButton_, SIGNAL(clicked()), OpenProjectDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(OpenProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenProjectDialog)
    {
        OpenProjectDialog->setWindowTitle(QApplication::translate("OpenProjectDialog", "Open Project", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenProjectDialog", "Path", 0, QApplication::UnicodeUTF8));
        browseButton_->setText(QApplication::translate("OpenProjectDialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OpenProjectDialog", "Recent Projects", 0, QApplication::UnicodeUTF8));
        removeProjectButton_->setText(QApplication::translate("OpenProjectDialog", "Remove", 0, QApplication::UnicodeUTF8));
        newButton_->setText(QApplication::translate("OpenProjectDialog", "&New...", 0, QApplication::UnicodeUTF8));
        openButton_->setText(QApplication::translate("OpenProjectDialog", "&Open", 0, QApplication::UnicodeUTF8));
        cancelButton_->setText(QApplication::translate("OpenProjectDialog", "&Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenProjectDialog: public Ui_OpenProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPROJECTDLG2_H
