/***********************************/
/*      Daniel Carrasco Luque      */
/*           Producto 2            */
/*                                 */
/*  Adquiriendo destrezas básicas  */
/***********************************/


#include <stdio.h>
#include <stdlib.h>

#include "fun_aux.h"
#include "funciones.h"


// Menú principal del programa
int main(void) {

	int opcion;

	while (1) {

		system("cls");
		printf("\nMenu:\n\n");
		printf("> 1. Insertar fecha y hora en documento\n");
		printf("> 2. Verificar IP's desde archivo\n");
		printf("> 3. Informacion de aptadores de red\n");
		printf("> 0. Salir del programa\n");
		
		printf("\nEscoja opcion: ");
		scanf("%d", &opcion);
		limpiarBuffer();

		if (opcion >= 0 && opcion < 4) {
			switch (opcion) {
			case 1:
				insertarFechaHora();
				break;
			case 2:
				verificarIps();
				break;
			case 3:
				seleccionarAdaptadorRed();
				break;
			case 0:
				printf("\nHasta la proxima!!");
				return 0;
			}
		}	
	}
}