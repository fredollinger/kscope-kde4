/********************************************************************************
** Form generated from reading UI file 'greplayout.ui'
**
** Created: Sun Oct 9 14:16:02 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREPLAYOUT_H
#define UI_GREPLAYOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GrepLayout
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditSearch;
    QPushButton *buttonSearch;

    void setupUi(QDialog *GrepLayout)
    {
        if (GrepLayout->objectName().isEmpty())
            GrepLayout->setObjectName(QString::fromUtf8("GrepLayout"));
        GrepLayout->resize(372, 300);
        verticalLayoutWidget = new QWidget(GrepLayout);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 60, 291, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditSearch = new QLineEdit(verticalLayoutWidget);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditSearch->sizePolicy().hasHeightForWidth());
        lineEditSearch->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lineEditSearch);

        buttonSearch = new QPushButton(verticalLayoutWidget);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        sizePolicy.setHeightForWidth(buttonSearch->sizePolicy().hasHeightForWidth());
        buttonSearch->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(buttonSearch);


        retranslateUi(GrepLayout);

        QMetaObject::connectSlotsByName(GrepLayout);
    } // setupUi

    void retranslateUi(QDialog *GrepLayout)
    {
        GrepLayout->setWindowTitle(QApplication::translate("GrepLayout", "Dialog", 0, QApplication::UnicodeUTF8));
        buttonSearch->setText(QApplication::translate("GrepLayout", "Search", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GrepLayout: public Ui_GrepLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREPLAYOUT_H
