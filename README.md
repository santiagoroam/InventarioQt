# Sistema de Inventario Qt

Aplicación de escritorio desarrollada en C++ utilizando Qt y SQLite para la gestión de inventario de artículos electrónicos o de laboratorio.

---

# Descripción

El sistema permite administrar artículos mediante una interfaz gráfica intuitiva desarrollada con Qt Widgets. La aplicación implementa operaciones CRUD completas, almacenamiento persistente con SQLite, exportación de datos y un dashboard estadístico.

Este proyecto fue desarrollado como proyecto final del curso **Algoritmos en Sistemas Electrónicos**.

---

# Características

✅ Agregar artículos al inventario  
✅ Editar artículos existentes  
✅ Eliminar artículos  
✅ Buscar artículos por nombre  
✅ Base de datos SQLite integrada  
✅ Exportación CSV compatible con Excel  
✅ Alertas visuales de stock bajo  
✅ Dashboard con estadísticas  
✅ Gráficas usando Qt Charts  
✅ Documentación automática con Doxygen  

---

# Tecnologías Utilizadas

- C++
- Qt Widgets
- Qt Charts
- SQLite3
- Git
- GitHub
- Doxygen

---

# Interfaz del Sistema

## Interfaz Principal



---

## Dashboard y Estadísticas



---

## Exportación CSV



---

# Base de Datos

El sistema utiliza una base de datos SQLite llamada:

```text
inventario.db
```

La tabla principal es:

| Campo | Tipo |
|---|---|
| id | INTEGER |
| nombre | TEXT |
| tipo | TEXT |
| cantidad | INTEGER |
| ubicacion | TEXT |

---

# Funcionalidades Implementadas

## CRUD Completo

El sistema permite:

- Crear artículos
- Leer artículos
- Actualizar artículos
- Eliminar artículos

---

## Alertas de Stock Bajo

Los artículos con cantidad menor a 5 unidades se resaltan automáticamente en color rojo.

---

## Exportación CSV

La información del inventario puede exportarse a:

```text
inventario.csv
```

Compatible con Microsoft Excel.

---

## Dashboard Estadístico

El dashboard muestra:

- Total de artículos
- Cantidad total almacenada
- Productos con stock bajo
- Gráfica estadística

---

# Documentación Doxygen

La documentación automática se encuentra en:

```text
/html/index.html
```

---

# Estructura del Proyecto

```text
InventarioQt/
│
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
├── CMakeLists.txt
├── inventario.db
├── inventario.csv
├── html/
└── README.md
```

---

# Compilación

## Requisitos

- Qt 6
- Compilador C++
- SQLite
- Qt Charts

---

## Compilar con Qt Creator

1. Abrir el proyecto en Qt Creator.
2. Configurar el kit de compilación.
3. Ejecutar Build.
4. Ejecutar Run.

---

# Autor

## Santiago Rodriguez

Ingeniería Electrónica  
Escuela Colombiana de Ingeniería Julio Garavito

Correo:
```text
santiago.ramezquita@mail.escuelaing.edu.co
```

---

# Repositorio

Repositorio oficial del proyecto:

https://github.com/santiagoroam/InventarioQt.git

---

# Licencia

Proyecto académico desarrollado con fines educativos.
