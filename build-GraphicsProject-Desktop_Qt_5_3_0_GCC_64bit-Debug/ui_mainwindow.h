/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCartesian;
    QAction *actionParametric;
    QAction *actionInteger_DDA;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionCartesian_2;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuLine;
    QMenu *menuFile;
    QMenu *menuCicle;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(295, 304);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionCartesian = new QAction(MainWindow);
        actionCartesian->setObjectName(QStringLiteral("actionCartesian"));
        actionParametric = new QAction(MainWindow);
        actionParametric->setObjectName(QStringLiteral("actionParametric"));
        actionInteger_DDA = new QAction(MainWindow);
        actionInteger_DDA->setObjectName(QStringLiteral("actionInteger_DDA"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionCartesian_2 = new QAction(MainWindow);
        actionCartesian_2->setObjectName(QStringLiteral("actionCartesian_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 295, 25));
        menuLine = new QMenu(menuBar);
        menuLine->setObjectName(QStringLiteral("menuLine"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuCicle = new QMenu(menuBar);
        menuCicle->setObjectName(QStringLiteral("menuCicle"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLine->menuAction());
        menuBar->addAction(menuCicle->menuAction());
        menuLine->addAction(actionCartesian);
        menuLine->addSeparator();
        menuLine->addAction(actionParametric);
        menuLine->addSeparator();
        menuLine->addAction(actionInteger_DDA);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuCicle->addSeparator();
        menuCicle->addSeparator();
        menuCicle->addAction(actionCartesian_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCartesian->setText(QApplication::translate("MainWindow", "Cartesian", 0));
        actionParametric->setText(QApplication::translate("MainWindow", "Parametric", 0));
        actionInteger_DDA->setText(QApplication::translate("MainWindow", "Integer DDA", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionCartesian_2->setText(QApplication::translate("MainWindow", "cartesian", 0));
        menuLine->setTitle(QApplication::translate("MainWindow", "Line", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuCicle->setTitle(QApplication::translate("MainWindow", "cicle", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
