/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtNombre;
    QLineEdit *txtTipo;
    QLineEdit *txtCantidad;
    QLineEdit *txtUbicacion;
    QPushButton *btnAgregar;
    QPushButton *btnEditar;
    QPushButton *btnEliminar;
    QPushButton *btnBuscar;
    QTableWidget *tableInventario;
    QPushButton *btnCSV;
    QWidget *widgetGrafica;
    QLabel *lblTotal;
    QLabel *lblCantidad;
    QLabel *lblStock;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(883, 761);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 100, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 150, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 200, 71, 20));
        txtNombre = new QLineEdit(centralwidget);
        txtNombre->setObjectName("txtNombre");
        txtNombre->setGeometry(QRect(160, 60, 113, 28));
        txtTipo = new QLineEdit(centralwidget);
        txtTipo->setObjectName("txtTipo");
        txtTipo->setGeometry(QRect(160, 100, 113, 28));
        txtCantidad = new QLineEdit(centralwidget);
        txtCantidad->setObjectName("txtCantidad");
        txtCantidad->setGeometry(QRect(160, 150, 113, 28));
        txtUbicacion = new QLineEdit(centralwidget);
        txtUbicacion->setObjectName("txtUbicacion");
        txtUbicacion->setGeometry(QRect(160, 200, 113, 28));
        btnAgregar = new QPushButton(centralwidget);
        btnAgregar->setObjectName("btnAgregar");
        btnAgregar->setGeometry(QRect(40, 300, 90, 29));
        btnEditar = new QPushButton(centralwidget);
        btnEditar->setObjectName("btnEditar");
        btnEditar->setGeometry(QRect(150, 300, 90, 29));
        btnEliminar = new QPushButton(centralwidget);
        btnEliminar->setObjectName("btnEliminar");
        btnEliminar->setGeometry(QRect(260, 300, 90, 29));
        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(370, 300, 90, 29));
        tableInventario = new QTableWidget(centralwidget);
        tableInventario->setObjectName("tableInventario");
        tableInventario->setGeometry(QRect(40, 340, 681, 191));
        tableInventario->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableInventario->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        btnCSV = new QPushButton(centralwidget);
        btnCSV->setObjectName("btnCSV");
        btnCSV->setGeometry(QRect(490, 300, 90, 29));
        widgetGrafica = new QWidget(centralwidget);
        widgetGrafica->setObjectName("widgetGrafica");
        widgetGrafica->setGeometry(QRect(500, 50, 341, 211));
        lblTotal = new QLabel(centralwidget);
        lblTotal->setObjectName("lblTotal");
        lblTotal->setGeometry(QRect(340, 90, 101, 20));
        lblCantidad = new QLabel(centralwidget);
        lblCantidad->setObjectName("lblCantidad");
        lblCantidad->setGeometry(QRect(340, 150, 101, 20));
        lblStock = new QLabel(centralwidget);
        lblStock->setObjectName("lblStock");
        lblStock->setGeometry(QRect(340, 200, 101, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 883, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Tipo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cantidad", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ubicacion", nullptr));
        btnAgregar->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnEditar->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnCSV->setText(QCoreApplication::translate("MainWindow", "Exportar CSV", nullptr));
        lblTotal->setText(QCoreApplication::translate("MainWindow", "Total art\303\255culos", nullptr));
        lblCantidad->setText(QCoreApplication::translate("MainWindow", "Cantidad total", nullptr));
        lblStock->setText(QCoreApplication::translate("MainWindow", "Stock bajo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
