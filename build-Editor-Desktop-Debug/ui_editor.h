/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_description;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QTextEdit *textEdit;
    QWidget *tab_item;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QCheckBox *checkBox_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *spinBox;
    QTextEdit *textEdit_2;
    QCheckBox *checkBox_2;
    QWidget *tab_exits;
    QFormLayout *formLayout;
    QLabel *label_N;
    QComboBox *combo_N;
    QComboBox *combo_S;
    QComboBox *combo_V;
    QComboBox *combo_E;
    QLabel *label_S;
    QLabel *label_W;
    QLabel *label_E;
    QWidget *tab_npcs;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_namn;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_name;
    QLineEdit *edit_name;
    QWidget *widget_description;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_description;
    QPlainTextEdit *edit_description;
    QWidget *widget_dialogs;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_dialog;
    QTextEdit *edit_dialog;
    QLabel *label_recieved_dialog;
    QTextEdit *edit_recieved_dialog;
    QWidget *widget_modifier;
    QGridLayout *gridLayout;
    QLineEdit *edit_hair;
    QLineEdit *edit_height;
    QLabel *label_hair;
    QLabel *label_height;
    QLabel *label_width;
    QLineEdit *edit_wants;
    QLineEdit *edit_weight;
    QLineEdit *edit_width;
    QLabel *label_weight;
    QLabel *label_wants;
    QCheckBox *checkBox;
    QWidget *right_widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_room;
    QComboBox *combobox_rooms;
    QPushButton *buttom_new_room;
    QLabel *label_items;
    QListWidget *list_items;
    QPushButton *button_item;
    QLabel *label_npcs;
    QListWidget *list_npcs;
    QPushButton *button_npc;
    QMenuBar *menuBar;
    QMenu *menuArkiv;
    QMenu *menuRedigera;
    QMenu *menuVisa;
    QMenu *menuInstallning;
    QMenu *menuHjalp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QStringLiteral("Editor"));
        Editor->resize(631, 592);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Editor->sizePolicy().hasHeightForWidth());
        Editor->setSizePolicy(sizePolicy);
        Editor->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(Editor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setAutoFillBackground(false);
        tab_description = new QWidget();
        tab_description->setObjectName(QStringLiteral("tab_description"));
#ifndef QT_NO_TOOLTIP
        tab_description->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP
        verticalLayout_6 = new QVBoxLayout(tab_description);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(tab_description);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        lineEdit = new QLineEdit(tab_description);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_6->addWidget(lineEdit);

        label_2 = new QLabel(tab_description);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        textEdit = new QTextEdit(tab_description);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_6->addWidget(textEdit);

        tabWidget->addTab(tab_description, QString());
        tab_item = new QWidget();
        tab_item->setObjectName(QStringLiteral("tab_item"));
        gridLayout_2 = new QGridLayout(tab_item);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(tab_item);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        checkBox_3 = new QCheckBox(tab_item);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 5, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_item);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 0, 1, 1);

        label_4 = new QLabel(tab_item);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        checkBox_4 = new QCheckBox(tab_item);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 8, 0, 1, 1);

        widget = new QWidget(tab_item);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        gridLayout_2->addWidget(widget, 4, 0, 1, 1);

        textEdit_2 = new QTextEdit(tab_item);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout_2->addWidget(textEdit_2, 3, 0, 1, 1);

        checkBox_2 = new QCheckBox(tab_item);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 6, 0, 1, 1);

        tabWidget->addTab(tab_item, QString());
        tab_exits = new QWidget();
        tab_exits->setObjectName(QStringLiteral("tab_exits"));
        formLayout = new QFormLayout(tab_exits);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_N = new QLabel(tab_exits);
        label_N->setObjectName(QStringLiteral("label_N"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_N);

        combo_N = new QComboBox(tab_exits);
        combo_N->setObjectName(QStringLiteral("combo_N"));

        formLayout->setWidget(0, QFormLayout::FieldRole, combo_N);

        combo_S = new QComboBox(tab_exits);
        combo_S->setObjectName(QStringLiteral("combo_S"));

        formLayout->setWidget(1, QFormLayout::FieldRole, combo_S);

        combo_V = new QComboBox(tab_exits);
        combo_V->setObjectName(QStringLiteral("combo_V"));

        formLayout->setWidget(2, QFormLayout::FieldRole, combo_V);

        combo_E = new QComboBox(tab_exits);
        combo_E->setObjectName(QStringLiteral("combo_E"));

        formLayout->setWidget(3, QFormLayout::FieldRole, combo_E);

        label_S = new QLabel(tab_exits);
        label_S->setObjectName(QStringLiteral("label_S"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_S);

        label_W = new QLabel(tab_exits);
        label_W->setObjectName(QStringLiteral("label_W"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_W);

        label_E = new QLabel(tab_exits);
        label_E->setObjectName(QStringLiteral("label_E"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_E);

        tabWidget->addTab(tab_exits, QString());
        tab_npcs = new QWidget();
        tab_npcs->setObjectName(QStringLiteral("tab_npcs"));
        verticalLayout_2 = new QVBoxLayout(tab_npcs);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_namn = new QWidget(tab_npcs);
        widget_namn->setObjectName(QStringLiteral("widget_namn"));
        verticalLayout_3 = new QVBoxLayout(widget_namn);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_name = new QLabel(widget_namn);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(10, 0));

        verticalLayout_3->addWidget(label_name);

        edit_name = new QLineEdit(widget_namn);
        edit_name->setObjectName(QStringLiteral("edit_name"));

        verticalLayout_3->addWidget(edit_name);


        verticalLayout_2->addWidget(widget_namn);

        widget_description = new QWidget(tab_npcs);
        widget_description->setObjectName(QStringLiteral("widget_description"));
        verticalLayout_4 = new QVBoxLayout(widget_description);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_description = new QLabel(widget_description);
        label_description->setObjectName(QStringLiteral("label_description"));
        label_description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(label_description);

        edit_description = new QPlainTextEdit(widget_description);
        edit_description->setObjectName(QStringLiteral("edit_description"));

        verticalLayout_4->addWidget(edit_description);


        verticalLayout_2->addWidget(widget_description);

        widget_dialogs = new QWidget(tab_npcs);
        widget_dialogs->setObjectName(QStringLiteral("widget_dialogs"));
        widget_dialogs->setMinimumSize(QSize(0, 100));
        verticalLayout_5 = new QVBoxLayout(widget_dialogs);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_dialog = new QLabel(widget_dialogs);
        label_dialog->setObjectName(QStringLiteral("label_dialog"));

        verticalLayout_5->addWidget(label_dialog);

        edit_dialog = new QTextEdit(widget_dialogs);
        edit_dialog->setObjectName(QStringLiteral("edit_dialog"));

        verticalLayout_5->addWidget(edit_dialog);

        label_recieved_dialog = new QLabel(widget_dialogs);
        label_recieved_dialog->setObjectName(QStringLiteral("label_recieved_dialog"));

        verticalLayout_5->addWidget(label_recieved_dialog);

        edit_recieved_dialog = new QTextEdit(widget_dialogs);
        edit_recieved_dialog->setObjectName(QStringLiteral("edit_recieved_dialog"));

        verticalLayout_5->addWidget(edit_recieved_dialog);


        verticalLayout_2->addWidget(widget_dialogs);

        widget_modifier = new QWidget(tab_npcs);
        widget_modifier->setObjectName(QStringLiteral("widget_modifier"));
        widget_modifier->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(widget_modifier);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        edit_hair = new QLineEdit(widget_modifier);
        edit_hair->setObjectName(QStringLiteral("edit_hair"));

        gridLayout->addWidget(edit_hair, 0, 1, 1, 1);

        edit_height = new QLineEdit(widget_modifier);
        edit_height->setObjectName(QStringLiteral("edit_height"));

        gridLayout->addWidget(edit_height, 2, 3, 1, 1);

        label_hair = new QLabel(widget_modifier);
        label_hair->setObjectName(QStringLiteral("label_hair"));

        gridLayout->addWidget(label_hair, 0, 0, 1, 1);

        label_height = new QLabel(widget_modifier);
        label_height->setObjectName(QStringLiteral("label_height"));

        gridLayout->addWidget(label_height, 2, 2, 1, 1);

        label_width = new QLabel(widget_modifier);
        label_width->setObjectName(QStringLiteral("label_width"));

        gridLayout->addWidget(label_width, 2, 0, 1, 1);

        edit_wants = new QLineEdit(widget_modifier);
        edit_wants->setObjectName(QStringLiteral("edit_wants"));

        gridLayout->addWidget(edit_wants, 4, 1, 1, 1);

        edit_weight = new QLineEdit(widget_modifier);
        edit_weight->setObjectName(QStringLiteral("edit_weight"));

        gridLayout->addWidget(edit_weight, 0, 3, 1, 1);

        edit_width = new QLineEdit(widget_modifier);
        edit_width->setObjectName(QStringLiteral("edit_width"));

        gridLayout->addWidget(edit_width, 2, 1, 1, 1);

        label_weight = new QLabel(widget_modifier);
        label_weight->setObjectName(QStringLiteral("label_weight"));

        gridLayout->addWidget(label_weight, 0, 2, 1, 1);

        label_wants = new QLabel(widget_modifier);
        label_wants->setObjectName(QStringLiteral("label_wants"));

        gridLayout->addWidget(label_wants, 4, 0, 1, 1);

        checkBox = new QCheckBox(widget_modifier);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 4, 3, 1, 1);


        verticalLayout_2->addWidget(widget_modifier);

        tabWidget->addTab(tab_npcs, QString());

        horizontalLayout_2->addWidget(tabWidget);

        right_widget = new QWidget(centralWidget);
        right_widget->setObjectName(QStringLiteral("right_widget"));
        right_widget->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(right_widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_room = new QLabel(right_widget);
        label_room->setObjectName(QStringLiteral("label_room"));

        verticalLayout->addWidget(label_room);

        combobox_rooms = new QComboBox(right_widget);
        combobox_rooms->setObjectName(QStringLiteral("combobox_rooms"));
        combobox_rooms->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(combobox_rooms);

        buttom_new_room = new QPushButton(right_widget);
        buttom_new_room->setObjectName(QStringLiteral("buttom_new_room"));

        verticalLayout->addWidget(buttom_new_room);

        label_items = new QLabel(right_widget);
        label_items->setObjectName(QStringLiteral("label_items"));

        verticalLayout->addWidget(label_items);

        list_items = new QListWidget(right_widget);
        new QListWidgetItem(list_items);
        new QListWidgetItem(list_items);
        new QListWidgetItem(list_items);
        new QListWidgetItem(list_items);
        list_items->setObjectName(QStringLiteral("list_items"));
        list_items->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(list_items);

        button_item = new QPushButton(right_widget);
        button_item->setObjectName(QStringLiteral("button_item"));

        verticalLayout->addWidget(button_item);

        label_npcs = new QLabel(right_widget);
        label_npcs->setObjectName(QStringLiteral("label_npcs"));

        verticalLayout->addWidget(label_npcs);

        list_npcs = new QListWidget(right_widget);
        new QListWidgetItem(list_npcs);
        new QListWidgetItem(list_npcs);
        list_npcs->setObjectName(QStringLiteral("list_npcs"));
        list_npcs->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(list_npcs);

        button_npc = new QPushButton(right_widget);
        button_npc->setObjectName(QStringLiteral("button_npc"));

        verticalLayout->addWidget(button_npc);


        horizontalLayout_2->addWidget(right_widget);

        Editor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Editor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 20));
        menuArkiv = new QMenu(menuBar);
        menuArkiv->setObjectName(QStringLiteral("menuArkiv"));
        menuRedigera = new QMenu(menuBar);
        menuRedigera->setObjectName(QStringLiteral("menuRedigera"));
        menuVisa = new QMenu(menuBar);
        menuVisa->setObjectName(QStringLiteral("menuVisa"));
        menuInstallning = new QMenu(menuBar);
        menuInstallning->setObjectName(QStringLiteral("menuInstallning"));
        menuHjalp = new QMenu(menuBar);
        menuHjalp->setObjectName(QStringLiteral("menuHjalp"));
        Editor->setMenuBar(menuBar);
        statusBar = new QStatusBar(Editor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Editor->setStatusBar(statusBar);

        menuBar->addAction(menuArkiv->menuAction());
        menuBar->addAction(menuRedigera->menuAction());
        menuBar->addAction(menuVisa->menuAction());
        menuBar->addAction(menuInstallning->menuAction());
        menuBar->addAction(menuHjalp->menuAction());

        retranslateUi(Editor);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Editor", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tab_description->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("Editor", "Namn", 0));
        lineEdit->setText(QApplication::translate("Editor", "Hus", 0));
        label_2->setText(QApplication::translate("Editor", "Beskrivning", 0));
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_description), QApplication::translate("Editor", "Beskrivning", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_description), QApplication::translate("Editor", "<html><head/><body><p>Rummets namn och beskrivning</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        tab_item->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Editor", "Namn", 0));
        checkBox_3->setText(QApplication::translate("Editor", "G\303\245r att s\303\244lja", 0));
        lineEdit_2->setText(QApplication::translate("Editor", "Kaffekopp", 0));
        label_4->setText(QApplication::translate("Editor", "Beskrivning", 0));
        checkBox_4->setText(QApplication::translate("Editor", "G\303\245r att kasta", 0));
        label_5->setText(QApplication::translate("Editor", "V\303\244rde", 0));
        textEdit_2->setHtml(QApplication::translate("Editor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">En riktigt fin kaffekopp</p></body></html>", 0));
        checkBox_2->setText(QApplication::translate("Editor", "G\303\245r att plocka upp", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_item), QApplication::translate("Editor", "Objekt", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_item), QApplication::translate("Editor", "<html><head/><body><p>Objekt</p></body></html>", 0));
        label_N->setText(QApplication::translate("Editor", "Nord", 0));
        combo_N->clear();
        combo_N->insertItems(0, QStringList()
         << QApplication::translate("Editor", "Inget", 0)
         << QApplication::translate("Editor", "Rum 1: Hus", 0)
         << QApplication::translate("Editor", "Rum 2: Fult hus", 0)
        );
        combo_S->clear();
        combo_S->insertItems(0, QStringList()
         << QApplication::translate("Editor", "Inget", 0)
         << QApplication::translate("Editor", "Rum 1: Hus", 0)
         << QApplication::translate("Editor", "Rum 2: Fult hus", 0)
        );
        combo_V->clear();
        combo_V->insertItems(0, QStringList()
         << QApplication::translate("Editor", "Inget", 0)
         << QApplication::translate("Editor", "Rum 1: Hus", 0)
         << QApplication::translate("Editor", "Rum 2: Fult hus", 0)
        );
        combo_E->clear();
        combo_E->insertItems(0, QStringList()
         << QApplication::translate("Editor", "Inget", 0)
         << QApplication::translate("Editor", "Rum 1: Hus", 0)
         << QApplication::translate("Editor", "Rum 2: Fult hus", 0)
        );
        label_S->setText(QApplication::translate("Editor", "Syd", 0));
        label_W->setText(QApplication::translate("Editor", "V\303\244st", 0));
        label_E->setText(QApplication::translate("Editor", "\303\226st", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_exits), QApplication::translate("Editor", "Utg\303\245ngar", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_exits), QApplication::translate("Editor", "<html><head/><body><p>\303\204ndra rummets utg\303\245ngar</p></body></html>", 0));
        label_name->setText(QApplication::translate("Editor", "Namn", 0));
        edit_name->setText(QApplication::translate("Editor", "Granntant \303\205sa", 0));
        label_description->setText(QApplication::translate("Editor", "Beskrivning", 0));
        edit_description->setPlainText(QApplication::translate("Editor", "Extremt nyfiken", 0));
        label_dialog->setText(QApplication::translate("Editor", "Dialog", 0));
        edit_dialog->setHtml(QApplication::translate("Editor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Har du n\303\245got nytt skvaller?</p></body></html>", 0));
        label_recieved_dialog->setText(QApplication::translate("Editor", "Dialog vid mottaget objekt", 0));
        edit_recieved_dialog->setHtml(QApplication::translate("Editor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Tack f\303\266r kaffet och skvallerstunden, jag bjuder p\303\245 fika!</p></body></html>", 0));
        edit_hair->setText(QApplication::translate("Editor", "Gr\303\245", 0));
        edit_height->setText(QApplication::translate("Editor", "130", 0));
        label_hair->setText(QApplication::translate("Editor", "H\303\245rf\303\244rg", 0));
        label_height->setText(QApplication::translate("Editor", "L\303\244ngd", 0));
        label_width->setText(QApplication::translate("Editor", "Bredd", 0));
        edit_wants->setText(QApplication::translate("Editor", "Kaffekopp", 0));
        edit_weight->setText(QApplication::translate("Editor", "60", 0));
        edit_width->setText(QApplication::translate("Editor", "100", 0));
        label_weight->setText(QApplication::translate("Editor", "Vikt", 0));
        label_wants->setText(QApplication::translate("Editor", "Beg\303\244r", 0));
        checkBox->setText(QApplication::translate("Editor", "F\303\266rs\303\244ljare", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_npcs), QApplication::translate("Editor", "Personer", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_npcs), QApplication::translate("Editor", "<html><head/><body><p>Person</p></body></html>", 0));
        label_room->setText(QApplication::translate("Editor", "Rum", 0));
        combobox_rooms->clear();
        combobox_rooms->insertItems(0, QStringList()
         << QApplication::translate("Editor", "Rum 1: Hus", 0)
         << QApplication::translate("Editor", "Rum 2: Fult hus", 0)
        );
        buttom_new_room->setText(QApplication::translate("Editor", "L\303\244gg till nytt rum", 0));
        label_items->setText(QApplication::translate("Editor", "Objekt i rummet", 0));

        const bool __sortingEnabled = list_items->isSortingEnabled();
        list_items->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list_items->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Editor", "Kaffekopp", 0));
        QListWidgetItem *___qlistwidgetitem1 = list_items->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Editor", "L\303\245da", 0));
        QListWidgetItem *___qlistwidgetitem2 = list_items->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Editor", "Pannkaka", 0));
        QListWidgetItem *___qlistwidgetitem3 = list_items->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Editor", "John", 0));
        list_items->setSortingEnabled(__sortingEnabled);

        button_item->setText(QApplication::translate("Editor", "L\303\244gg till nytt objekt", 0));
        label_npcs->setText(QApplication::translate("Editor", "Personer i rummet", 0));

        const bool __sortingEnabled1 = list_npcs->isSortingEnabled();
        list_npcs->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = list_npcs->item(0);
        ___qlistwidgetitem4->setText(QApplication::translate("Editor", "Armen", 0));
        QListWidgetItem *___qlistwidgetitem5 = list_npcs->item(1);
        ___qlistwidgetitem5->setText(QApplication::translate("Editor", "Granntant \303\205sa", 0));
        list_npcs->setSortingEnabled(__sortingEnabled1);

        button_npc->setText(QApplication::translate("Editor", "L\303\244gg till ny person", 0));
        menuArkiv->setTitle(QApplication::translate("Editor", "Arkiv", 0));
        menuRedigera->setTitle(QApplication::translate("Editor", "Redigera", 0));
        menuVisa->setTitle(QApplication::translate("Editor", "Visa", 0));
        menuInstallning->setTitle(QApplication::translate("Editor", "Inst\303\244llningar", 0));
        menuHjalp->setTitle(QApplication::translate("Editor", "Hj\303\244lp", 0));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
