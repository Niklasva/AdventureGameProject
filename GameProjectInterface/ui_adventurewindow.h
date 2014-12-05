/********************************************************************************
** Form generated from reading UI file 'adventurewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVENTUREWINDOW_H
#define UI_ADVENTUREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdventureWindow
{
public:
    QAction *menu_load;
    QWidget *Q;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *text_box;
    QLineEdit *lineEdit;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *inventory_list;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuArkiv;

    void setupUi(QMainWindow *AdventureWindow)
    {
        if (AdventureWindow->objectName().isEmpty())
            AdventureWindow->setObjectName(QStringLiteral("AdventureWindow"));
        AdventureWindow->resize(500, 472);
        menu_load = new QAction(AdventureWindow);
        menu_load->setObjectName(QStringLiteral("menu_load"));
        menu_load->setCheckable(false);
        Q = new QWidget(AdventureWindow);
        Q->setObjectName(QStringLiteral("Q"));
        horizontalLayout = new QHBoxLayout(Q);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(Q);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        text_box = new QTextEdit(widget);
        text_box->setObjectName(QStringLiteral("text_box"));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        text_box->setFont(font);
        text_box->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(text_box);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font1;
        font1.setFamily(QStringLiteral("Utopia"));
        lineEdit->setFont(font1);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(Q);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(180, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        inventory_list = new QListWidget(widget_2);
        inventory_list->setObjectName(QStringLiteral("inventory_list"));

        verticalLayout_2->addWidget(inventory_list);


        horizontalLayout->addWidget(widget_2);

        AdventureWindow->setCentralWidget(Q);
        statusBar = new QStatusBar(AdventureWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AdventureWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(AdventureWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 25));
        menuArkiv = new QMenu(menuBar);
        menuArkiv->setObjectName(QStringLiteral("menuArkiv"));
        AdventureWindow->setMenuBar(menuBar);

        menuBar->addAction(menuArkiv->menuAction());
        menuArkiv->addAction(menu_load);

        retranslateUi(AdventureWindow);

        QMetaObject::connectSlotsByName(AdventureWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdventureWindow)
    {
        AdventureWindow->setWindowTitle(QApplication::translate("AdventureWindow", "AdventureWindow", 0));
        menu_load->setText(QApplication::translate("AdventureWindow", "Ladda spel", 0));
        text_box->setHtml(QApplication::translate("AdventureWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">V\303\244lkommen till text\303\244ventyrsprogrammet!</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Tryck p\303\245 arkiv, ladda f\303\266r att v\303\244lja ett spel</p></body></html>", 0));
        label_3->setText(QApplication::translate("AdventureWindow", "\303\204ventyrskorg", 0));
        menuArkiv->setTitle(QApplication::translate("AdventureWindow", "Arkiv", 0));
    } // retranslateUi

};

namespace Ui {
    class AdventureWindow: public Ui_AdventureWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVENTUREWINDOW_H
