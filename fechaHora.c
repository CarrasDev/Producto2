
/***********************************/
/*  Autor: Daniel Carrasco Luque   */
/***********************************/

/*  Obtiene la fecha y hora actual para después
*   insertar en el fichero "producto2.txt" */


#include <stdio.h>
#include <time.h>


int insertarFechaHora(void) {

    const char* FILE_OUT = "producto2.txt";

    // Obtiene la hora actual en segundos desde el "Epoch"
    time_t t = time(NULL);

    // Transforma la sentencia anterior a tipo tm con fecha y hora desglosada.
    // localtime() ajusta la hora a la zona horaria de la maquina.
    struct tm* tiempoLocal = localtime(&t);

    // Generar String con formato horario
    char fechaHora[25] = { 0 };
    strftime(fechaHora, sizeof(fechaHora), "%d-%m-%Y %H:%M:%S", tiempoLocal);

    // Abrir el fichero en modo de adición
    FILE* fileOut = fopen(FILE_OUT, "a"); 
    if (fileOut == NULL) {
        printf("Error al abrir el archivo de salida\n");
        return 1;
    }

    // Escribir la fecha y hora en el fichero
    fprintf(fileOut, "%s\n", fechaHora);

    fclose(fileOut);
    printf("\nFecha y hora actual insertadas en %s %s.\n", FILE_OUT, fechaHora);
    system("pause");

    return 0;
}