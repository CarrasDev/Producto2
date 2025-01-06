/***********************************/
/*  Autor: Daniel Carrasco Luque   */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "fun_aux.h"


/*  Se utiliza para vaciar el buffer despúes de una llamada de teclado */

void limpiarBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


/*  Se utiliza para quitar la \n de un string */

void limpiarBarraN(char* destino, char* origen) {
    int j = 0;
    for (int i = 0; i < strlen(origen); i++) {
        if (origen[i] != '\n') {
            destino[j++] = origen[i];
        }
    }
    destino[j] = '\0';
}


/*  Verificar ruta a fichero de usuario
*   Return 0 = OK, 1 = FAIL */

int verificarRuta(const char* ruta) {
    FILE* prueba = fopen(ruta, "r");
    if (prueba) {
        fclose(prueba);
        return 0;
    } else {
        return 1;
    }
}


/*	Función generica para realizar preguntas tipo si o no.
    Se le pasa String con la pregunta.
    Retorna: 1 = Si, 0 = No; */

int preguntarSiNo(const char* pregunta) {
    char respuesta[3];

    while (1) {
        printf("%s", pregunta);
        scanf("%2s", respuesta);
        limpiarBuffer();

        if ((strcmp(respuesta, "s") == 0) || (strcmp(respuesta, "S") == 0)) {
            return 1;
        } else if ((strcmp(respuesta, "n") == 0) || (strcmp(respuesta, "N") == 0)) {
            return 0;
        }
    }
}


/*  Borra la indexación creada para seleccionar los adaptadores.
*   recorremos el string hasta encontrar la A de Adaptador.
*   retornamos una cadena sin indexar */

void eliminarIndexación(char* entrada, char* salida) {
    memset(salida, 0, sizeof(salida));
    int leng = strlen(entrada);
    int i;

    for (i = 0; i < leng; i++) {
        if (entrada[i] == 'A') {
            break;
        }
    }
    strcpy(salida, &entrada[i]);
}