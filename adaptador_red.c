/***********************************/
/*  Autor: Daniel Carrasco Luque   */
/***********************************/

/*	Muestra el listado de adaptadores de red del PC mediante "ipconfig"
*	Permite seleccionar uno y guarda en un fichero llamado "adaptadores.txt":
*	nombre, ip, puerta de enlace y mascara de subred */


#include <stdio.h>
#include <string.h> 

#include "fun_aux.h"


int seleccionarAdaptadorRed(void) {

	// Archivos
	const char* IPCONFIG_FILE = "ipconfig.txt";
	const char* TEMP_FILE = "temp.txt";
	const char* OUT_FILE = "adaptador.txt";

	// Busquedas
	const char* BUSCAR_ADAPT = "Adaptador";
	const char* BUSCAR_IP = "IPv4";

	char instruccion[30] = { 0 };
	
	// Construir sentencia para system
	strcat(instruccion, "ipconfig > ");
	strcat(instruccion, IPCONFIG_FILE);

	system(instruccion);

	// Abre fichero generado por system con contenido de ipconfig
	FILE* fileIpConfig = fopen(IPCONFIG_FILE, "r");
	if (fileIpConfig == NULL) {
		printf("Error al abrir archivo ipconfig");
		return 1;
	}

	// Crea un archivo temporal, si existe lo borramos para usarlo
	FILE* fileTemp = fopen(TEMP_FILE, "w");
	if (fileTemp == NULL) {
		printf("Error al abrir archivo temporal");
		return 1;
	}


	/*	Lee el fichero generado por ipconfig.
	*	Filtra los adaptadores que no tienen IPv4.
	*	Indexa los adaptadores en un fichero temporal
	*	junto a IPv4, Puerta de enlace y Mascara de red
	*/
	int contador = 1; // Indice para numerar los adaptadores
	char contadorStr[10] = { 0 };
	char lineaActual[300] = { 0 };
	char lineaAux[300] = { 0 };
	char lineaConcat[310] = { 0 };
	while (fgets(lineaActual, sizeof(lineaActual), fileIpConfig)) {

		// Busca nombre de adaptador y lo almacena en una variable auxiliar
		if (strstr(lineaActual, BUSCAR_ADAPT)) {
			strcpy(lineaAux, lineaActual);
		}
		// Busca la linia que contiene IPv4
		if (strstr(lineaActual, BUSCAR_IP)) {

			// aseguramos que los strings estén vacios despues de cada uso
			memset(contadorStr, 0, sizeof(contadorStr));
			memset(lineaConcat, 0, sizeof(lineaConcat));

			// Convertir contador de int a string
			sprintf(contadorStr, "%d", contador);

			// Asignar indice al adaptador
			strcat(lineaConcat, "> ");
			strcat(lineaConcat, contadorStr);
			strcat(lineaConcat, ". ");
			strcat(lineaConcat, lineaAux);

			// Indice + Nombre Adaptador
			fprintf(fileTemp, "%s", lineaConcat);

			// IPv4
			fprintf(fileTemp, "%s", lineaActual);

			// Mascara de subred
			fgets(lineaActual, sizeof(lineaActual), fileIpConfig);
			fprintf(fileTemp, "%s", lineaActual);

			// Puerta de enlace
			fgets(lineaActual, sizeof(lineaActual), fileIpConfig);
			fprintf(fileTemp, "%s", lineaActual);

			// Preparamos para procesar un nuevo adaptador
			contador++;
			memset(lineaConcat, 0, sizeof(lineaConcat));
		}
	}
	fclose(fileIpConfig);
	remove(IPCONFIG_FILE);

	fclose(fileTemp); // Cerramos por estar en modo escritura


	// Abrir fichero que contiene los adaptadores filtrados
	fileTemp = fopen(TEMP_FILE, "r");
	if (fileTemp == NULL) {
		printf("Error al abrir archivo temporal");
		return 1;
	}

	// Abrimos en agregación "a" por si nos interesa acumular resultados en el fichero de salida
	FILE* fileOut = fopen(OUT_FILE, "a");
	if (fileOut == NULL) {
		printf("Error al abrir archivo de salida");
		return 1;
	}

	// Mostrar adaptadores a escoger
	system("cls");
	printf("Listado de adaptadores de red escogibles:\n\n");
	while (fgets(lineaActual, sizeof(lineaActual), fileTemp)) {
		printf("%s", lineaActual);
	}	
	
	/*	Seleccionar un adaptador de red mediante indice.
	*	Buscarlo en fichero, eliminar el indice y copiar
	*	a un fichero de salida el nombre y sus datos asociados.
	*/
	char eleccion[3] = { 0 };
	char busqueda[10] = { 0 };
	int encontrado = 0;

	while (!encontrado) {

		printf("\nEscoja opcion: ");
		scanf("%2s", eleccion);
		limpiarBuffer();

		// Construir indice
		memset(busqueda, 0, sizeof(busqueda));
		strcat(busqueda, "> ");
		strcat(busqueda, eleccion);

		// Devolver puntero al inicio del archivo.
		rewind(fileTemp);
				
		while (fgets(lineaActual, sizeof(lineaActual), fileTemp) && encontrado == 0) {
			if (strstr(lineaActual, busqueda)) {
				
				// Adaptador
				eliminarIndexación(lineaActual, lineaAux);
				fprintf(fileOut, "%s", lineaAux);
				// IPv4
				fgets(lineaActual, sizeof(lineaActual), fileTemp);
				fprintf(fileOut, "%s", lineaActual);
				// Mascara
				fgets(lineaActual, sizeof(lineaActual), fileTemp);
				fprintf(fileOut, "%s", lineaActual);
				// Puerta
				fgets(lineaActual, sizeof(lineaActual), fileTemp);
				fprintf(fileOut, "%s", lineaActual);

				printf("\n\nAdaptador agregado con exito.\n");
				encontrado = 1;
				break;
			}
		}
		if (!encontrado) {
			printf("Eleccion no valida.");
		}
	}


	system("pause");
	fclose(fileOut);
	fclose(fileTemp);
	remove(TEMP_FILE);

	return 0;
}
