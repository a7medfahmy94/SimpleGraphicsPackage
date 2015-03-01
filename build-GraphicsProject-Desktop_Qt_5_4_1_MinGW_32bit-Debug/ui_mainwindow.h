/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCartesian;
    QAction *actionParametric;
    QAction *actionInteger_DDA;
    QWidget *centralWidget;
    QLabel *current_selected;
    QMenuBar *menuBar;
    QMenu *menuLine;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionCartesian = new QAction(MainWindow);
        actionCartesian->setObjectName(QStringLiteral("actionCartesian"));
        actionParametric = new QAction(MainWindow);
        actionParametric->setObjectName(QStringLiteral("actionParametric"));
        actionInteger_DDA = new QAction(MainWindow);
        actionInteger_DDA->setObjectName(QStringLiteral("actionInteger_DDA"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        current_selected = new QLabel(centralWidget);
        current_selected->setObjectName(QStringLiteral("current_selected"));
        current_selected->setGeometry(QRect(196, -11, 201, 31));
        current_selected->setLayoutDirection(Qt::LeftToRight);
        current_selected->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuLine = new QMenu(menuBar);
        menuLine->setObjectName(QStringLiteral("menuLine"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuLine->menuAction());
        menuLine->addAction(actionCartesian);
        menuLine->addSeparator();
        menuLine->addAction(actionParametric);
        menuLine->addSeparator();
        menuLine->addAction(actionInteger_DDA);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCartesian->setText(QApplication::translate("MainWindow", "Cartesian", 0));
        actionParametric->setText(QApplication::translate("MainWindow", "Parametric", 0));
        actionInteger_DDA->setText(QApplication::translate("MainWindow", "Integer DDA", 0));
        current_selected->setText(QString());
        menuLine->setTitle(QApplication::translate("MainWindow", "Line", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
