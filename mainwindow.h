#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAgregar_clicked();

    void on_btnEliminar_clicked();

    void on_btnBuscar_clicked();

    void on_btnEditar_clicked();

    void on_btnCSV_clicked();

    void on_tableInventario_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    void mostrarDatos();

    void actualizarEstadisticas();

    void actualizarGrafica();

    QString idSeleccionado;
};

#endif // MAINWINDOW_H