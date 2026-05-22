#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/**
 * @brief Namespace de la interfaz gráfica.
 */
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Clase principal del sistema de inventario.
 *
 * Esta clase administra toda la interfaz gráfica,
 * las operaciones CRUD, la conexión con SQLite,
 * las estadísticas y la exportación CSV.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Constructor principal.
     * @param parent Widget padre.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la ventana principal.
     */
    ~MainWindow();

private slots:

    /**
     * @brief Agrega un nuevo artículo
     * a la base de datos.
     */
    void on_btnAgregar_clicked();

    /**
     * @brief Elimina un artículo
     * seleccionado de la tabla.
     */
    void on_btnEliminar_clicked();

    /**
     * @brief Busca artículos por nombre.
     */
    void on_btnBuscar_clicked();

    /**
     * @brief Actualiza la información
     * de un artículo existente.
     */
    void on_btnEditar_clicked();

    /**
     * @brief Detecta la fila seleccionada
     * de la tabla de inventario.
     *
     * @param row Fila seleccionada.
     * @param column Columna seleccionada.
     */
    void on_tableInventario_cellClicked(int row, int column);

    /**
     * @brief Exporta el inventario
     * a un archivo CSV.
     */
    void on_btnCSV_clicked();

private:

    /**
     * @brief Puntero a la interfaz gráfica.
     */
    Ui::MainWindow *ui;

    /**
     * @brief Almacena el ID seleccionado
     * de la tabla.
     */
    QString idSeleccionado;

    /**
     * @brief Muestra todos los datos
     * almacenados en la base de datos.
     */
    void mostrarDatos();

    /**
     * @brief Actualiza las estadísticas
     * generales del inventario.
     */
    void actualizarEstadisticas();

    /**
     * @brief Genera la gráfica estadística
     * del dashboard.
     */
    void actualizarGrafica();
};

#endif // MAINWINDOW_H