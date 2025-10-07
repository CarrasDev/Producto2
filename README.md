# Verificar direcciones IP mediante Ping

## Descripción

Este proyecto permite verificar la conectividad de direcciones IP utilizando la función de Ping. Está desarrollado en C y orientado a ejecutarse en sistemas Windows. El objetivo principal es comprobar el estado de diferentes adaptadores de red y registrar los resultados de las pruebas de conectividad mientras se aprende sobre programación en C y manejo de ficheros.

## Características

- Lectura de direcciones IP desde un archivo de texto ([producto2.txt](producto2.txt)).
- Ejecución de Ping a cada dirección IP listada.
- Registro de resultados en archivos de salida.
- Obtención y registro de la fecha y hora de cada verificación.
- Identificación y manejo de adaptadores de red.
- Modularidad mediante archivos de funciones auxiliares ([fun_aux.c](fun_aux.c), [fun_aux.h](fun_aux.h), [adaptador_red.c](adaptador_red.c), [fechaHora.c](fechaHora.c), [verificar_ip.c](verificar_ip.c)).
- Documentación técnica en [documentacion/Entregable.pdf](documentacion/Entregable.pdf).

## Estructura del proyecto

- **main.c**: Punto de entrada del programa.
- **adaptador_red.c**: Funciones para identificar y manejar adaptadores de red.
- **fechaHora.c**: Obtención de la fecha y hora actual.
- **verificar_ip.c**: Lógica para realizar el Ping y verificar conectividad.
- **fun_aux.c / fun_aux.h**: Funciones auxiliares utilizadas en el proyecto.
- **producto2.txt**: Archivo de entrada con las direcciones IP a verificar.
- **documentacion/Entregable.pdf**: Documento con la especificación y detalles técnicos.

## Uso

1. Coloca las direcciones IP a verificar en el archivo [producto2.txt](producto2.txt), una por línea.
2. Compila el proyecto con Visual Studio o usando el archivo de solución [Producto2.sln](Producto2.sln).
3. Ejecuta el programa. Los resultados se guardarán en los archivos de salida especificados en el código.

## Compilación

Abre la solución [Producto2.sln](Producto2.sln) en Visual Studio y compila el proyecto. Los archivos objeto y ejecutables se generan en las carpetas `Debug/` y `Producto2/Debug/`.

## Documentación

Consulta [documentacion/Entregable.pdf](documentacion/Entregable.pdf) para detalles sobre el diseño, la lógica de verificación y los requisitos funcionales.

## Créditos

Proyecto creado por::

- Daniel Carrasco ([CarrasDev](https://github.com/CarrasDev))

---

> Para cualquier duda o sugerencia, ponte en contacto o abre un issue en el repositorio.

¡¡Gracias por visitar mi proyecto!! 😊