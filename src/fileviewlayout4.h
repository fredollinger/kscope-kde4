/********************************************************************************
** Form generated from reading UI file 'fileviewlayout4.ui'
**
** Created: Tue Jul 5 13:16:50 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEVIEWLAYOUT4_H
#define UI_FILEVIEWLAYOUT4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <kfiletreeview.h>
#include "filelist4.h"
#include "kfiletreeview.h"

QT_BEGIN_NAMESPACE

class Ui_FileViewLayout
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *m_pTabWidget;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    FileList *m_pFileList;
    QWidget *tab1;
    QVBoxLayout *vboxLayout2;
    KFileTreeView *m_pFileTree;

    void setupUi(QWidget *FileViewLayout)
    {
        if (FileViewLayout->objectName().isEmpty())
            FileViewLayout->setObjectName(QString::fromUtf8("FileViewLayout"));
        FileViewLayout->resize(364, 639);
        vboxLayout = new QVBoxLayout(FileViewLayout);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_pTabWidget = new QTabWidget(FileViewLayout);
        m_pTabWidget->setObjectName(QString::fromUtf8("m_pTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        vboxLayout1 = new QVBoxLayout(tab);
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        m_pFileList = new FileList(tab);
        m_pFileList->setObjectName(QString::fromUtf8("m_pFileList"));

        vboxLayout1->addWidget(m_pFileList);

        m_pTabWidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        vboxLayout2 = new QVBoxLayout(tab1);
        vboxLayout2->setSpacing(0);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        m_pFileTree = new KFileTreeView(tab1);
        m_pFileTree->setObjectName(QString::fromUtf8("m_pFileTree"));

        vboxLayout2->addWidget(m_pFileTree);

        m_pTabWidget->addTab(tab1, QString());

        vboxLayout->addWidget(m_pTabWidget);


        retranslateUi(FileViewLayout);

        QMetaObject::connectSlotsByName(FileViewLayout);
    } // setupUi

    void retranslateUi(QWidget *FileViewLayout)
    {
        FileViewLayout->setWindowTitle(QApplication::translate("FileViewLayout", "Form1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pTabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_pFileList->setToolTip(QApplication::translate("FileViewLayout", "Project File List", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pTabWidget->setTabText(m_pTabWidget->indexOf(tab), QString());
#ifndef QT_NO_TOOLTIP
        m_pFileTree->setToolTip(QApplication::translate("FileViewLayout", "File Tree", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pTabWidget->setTabText(m_pTabWidget->indexOf(tab1), QString());
    } // retranslateUi

};

namespace Ui {
    class FileViewLayout: public Ui_FileViewLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEVIEWLAYOUT4_H
