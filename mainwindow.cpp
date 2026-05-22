#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QChartView>
#include <QBarCategoryAxis>

#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QHeaderView>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Sistema de Inventario");

    setFixedSize(width(), height());

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("inventario.db");

    if(db.open())
    {
        qDebug() << "Base de datos abierta";
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "No se pudo abrir la base de datos");
    }

    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS inventario("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "nombre TEXT,"
               "tipo TEXT,"
               "cantidad INTEGER,"
               "ubicacion TEXT)");

    ui->tableInventario->setColumnCount(5);

    QStringList titulos;

    titulos << "ID"
            << "Nombre"
            << "Tipo"
            << "Cantidad"
            << "Ubicacion";

    ui->tableInventario->setHorizontalHeaderLabels(titulos);

    ui->tableInventario->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);

    mostrarDatos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarDatos()
{
    ui->tableInventario->setRowCount(0);

    QSqlQuery query;

    query.exec("SELECT * FROM inventario");

    int fila = 0;

    while(query.next())
    {
        ui->tableInventario->insertRow(fila);

        int cantidad =
            query.value(3).toInt();

        for(int columna = 0; columna < 5; columna++)
        {
            QTableWidgetItem *item =
                new QTableWidgetItem(
                    query.value(columna).toString());

            if(cantidad < 5)
            {
                item->setBackground(Qt::red);
            }

            ui->tableInventario->setItem(
                fila,
                columna,
                item);
        }

        fila++;
    }

    actualizarEstadisticas();

    actualizarGrafica();
}

void MainWindow::actualizarEstadisticas()
{
    QSqlQuery query;

    int totalArticulos = 0;
    int cantidadTotal = 0;
    int stockBajo = 0;

    query.exec("SELECT * FROM inventario");

    while(query.next())
    {
        totalArticulos++;

        int cantidad =
            query.value(3).toInt();

        cantidadTotal =
            cantidadTotal + cantidad;

        if(cantidad < 5)
        {
            stockBajo++;
        }
    }

    ui->lblTotal->setText(
        "Total articulos: "
        + QString::number(totalArticulos));

    ui->lblCantidad->setText(
        "Cantidad total: "
        + QString::number(cantidadTotal));

    ui->lblStock->setText(
        "Stock bajo: "
        + QString::number(stockBajo));
}

void MainWindow::actualizarGrafica()
{
    int stockBajo = 0;
    int stockNormal = 0;

    QSqlQuery query;

    query.exec("SELECT * FROM inventario");

    while(query.next())
    {
        int cantidad =
            query.value(3).toInt();

        if(cantidad < 5)
        {
            stockBajo++;
        }
        else
        {
            stockNormal++;
        }
    }

    QBarSet *set0 =
        new QBarSet("Inventario");

    *set0 << stockNormal
          << stockBajo;

    QBarSeries *series =
        new QBarSeries();

    series->append(set0);

    QChart *chart =
        new QChart();

    chart->addSeries(series);

    chart->setTitle(
        "Dashboard Inventario");

    chart->createDefaultAxes();

    QChartView *chartView =
        new QChartView(chart);

    chartView->setRenderHint(
        QPainter::Antialiasing);

    QLayout *layoutAnterior =
        ui->widgetGrafica->layout();

    if(layoutAnterior != nullptr)
    {
        delete layoutAnterior;
    }

    QVBoxLayout *layout =
        new QVBoxLayout(ui->widgetGrafica);

    layout->addWidget(chartView);
}
void MainWindow::on_btnAgregar_clicked()
{
    QString nombre =
        ui->txtNombre->text();

    QString tipo =
        ui->txtTipo->text();

    QString cantidad =
        ui->txtCantidad->text();

    QString ubicacion =
        ui->txtUbicacion->text();

    QSqlQuery query;

    query.prepare(
        "INSERT INTO inventario(nombre,tipo,cantidad,ubicacion)"
        "VALUES(:nombre,:tipo,:cantidad,:ubicacion)");

    query.bindValue(":nombre", nombre);
    query.bindValue(":tipo", tipo);
    query.bindValue(":cantidad", cantidad);
    query.bindValue(":ubicacion", ubicacion);

    if(query.exec())
    {
        mostrarDatos();

        QMessageBox::information(this,
                                 "Correcto",
                                 "Articulo agregado");

        ui->txtNombre->clear();
        ui->txtTipo->clear();
        ui->txtCantidad->clear();
        ui->txtUbicacion->clear();
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "No se pudo agregar");
    }
}

void MainWindow::on_btnEliminar_clicked()
{
    int fila =
        ui->tableInventario->currentRow();

    if(fila < 0)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Seleccione un articulo");

        return;
    }

    QString id =
        ui->tableInventario->item(fila,0)->text();

    QSqlQuery query;

    query.prepare(
        "DELETE FROM inventario WHERE id = :id");

    query.bindValue(":id", id);

    if(query.exec())
    {
        QMessageBox::information(this,
                                 "Correcto",
                                 "Articulo eliminado");

        mostrarDatos();
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "No se pudo eliminar");
    }
}

void MainWindow::on_btnBuscar_clicked()
{
    QString nombre =
        ui->txtNombre->text();

    QSqlQuery query;

    query.prepare(
        "SELECT * FROM inventario "
        "WHERE nombre LIKE :nombre");

    query.bindValue(":nombre",
                    "%" + nombre + "%");

    ui->tableInventario->setRowCount(0);

    int fila = 0;

    if(query.exec())
    {
        while(query.next())
        {
            ui->tableInventario->insertRow(fila);

            int cantidad =
                query.value(3).toInt();

            for(int columna = 0; columna < 5; columna++)
            {
                QTableWidgetItem *item =
                    new QTableWidgetItem(
                        query.value(columna).toString());

                if(cantidad < 5)
                {
                    item->setBackground(Qt::red);
                }

                ui->tableInventario->setItem(
                    fila,
                    columna,
                    item);
            }

            fila++;
        }
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "No se pudo buscar");
    }
}

void MainWindow::on_tableInventario_cellClicked(int row, int column)
{
    idSeleccionado =
        ui->tableInventario->item(row,0)->text();

    ui->txtNombre->setText(
        ui->tableInventario->item(row,1)->text());

    ui->txtTipo->setText(
        ui->tableInventario->item(row,2)->text());

    ui->txtCantidad->setText(
        ui->tableInventario->item(row,3)->text());

    ui->txtUbicacion->setText(
        ui->tableInventario->item(row,4)->text());
}

void MainWindow::on_btnEditar_clicked()
{
    QString nombre =
        ui->txtNombre->text();

    QString tipo =
        ui->txtTipo->text();

    QString cantidad =
        ui->txtCantidad->text();

    QString ubicacion =
        ui->txtUbicacion->text();

    QSqlQuery query;

    query.prepare(
        "UPDATE inventario SET "
        "nombre = :nombre,"
        "tipo = :tipo,"
        "cantidad = :cantidad,"
        "ubicacion = :ubicacion "
        "WHERE id = :id");

    query.bindValue(":nombre", nombre);
    query.bindValue(":tipo", tipo);
    query.bindValue(":cantidad", cantidad);
    query.bindValue(":ubicacion", ubicacion);
    query.bindValue(":id", idSeleccionado);

    if(query.exec())
    {
        QMessageBox::information(this,
                                 "Correcto",
                                 "Articulo actualizado");

        mostrarDatos();
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "No se pudo actualizar");
    }
}

void MainWindow::on_btnCSV_clicked()
{
    QFile archivo("inventario.csv");

    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream salida(&archivo);

        salida << "ID;Nombre;Tipo;Cantidad;Ubicacion;Estado\n";

        QSqlQuery query;

        query.exec("SELECT * FROM inventario");

        while(query.next())
        {
            int cantidad =
                query.value(3).toInt();

            salida
                << query.value(0).toString() << ";"
                << query.value(1).toString() << ";"
                << query.value(2).toString() << ";"
                << query.value(3).toString() << ";"
                << query.value(4).toString() << ";";

            if(cantidad < 5)
            {
                salida << "STOCK BAJO";
            }
            else
            {
                salida << "OK";
            }

            salida << "\n";
        }

        archivo.close();

        QMessageBox::information(this,
                                 "Correcto",
                                 "CSV exportado");
    }
    else
    {
        QMessageBox::critical(this,
                              "Error",
                              "No se pudo exportar");
    }
}