/***********************************/
/*  Autor: Daniel Carrasco Luque   */
/***********************************/

/*	Se solicita un fichero con direcciones IP.
	Muestra por pantalla el contenido del fichero.
	Ejecuta "ping" a cada ip y verifica si la conexión es correcta.
	Guarda el resultado en fichero "producto2.txt" */


#include <stdio.h>
#include <string.h>

#include "fun_aux.h"


int verificarIps(void) {

	const char* BUSCAR = "Paquetes: enviados";
	const char* PING_IP_OK = "recibidos = 4";
	const char* FILE_OUT = "producto2.txt";
	const char* FILE_PING = "ping.txt";

	char ruta[300] = { 0 };
	char* ip;
	char instruccion[100] = "";
	char* encontrada;
	int contador = 0;
	int stop = 1;
	int control = 1;	
	

	// Captar fichero del usuario o retornar al menú anterior
	system("cls");
	printf("\Proporcione ruta completa y nombre de archivo o escriba \"salir\" para ir al menu anterior.\n");
	printf("Ej.: C:\\ruta\\fichero.txt\n\n");
	do {

		memset(ruta, 0, sizeof(ruta));
		printf("\nRuta: ");
		scanf("%299s", ruta);
		limpiarBuffer();

		if ((strcmp(ruta, "salir") == 0) || (strcmp(ruta, "SALIR") == 0)) {
			control = 0;
		}else if (!verificarRuta(ruta)) {
			control = 0;
		} else {
			printf("\nArchivo o ruta proporcionada no valida.\n");
		}

	} while (control);


	
	// Abrir fichero de usuario para mostrar contenido por pantalla.
	FILE* fileListIp = fopen(ruta, "r");
	if (fileListIp == NULL) {
		printf("Error al abrir el archivo fuente");
		return 1;
	}

	// Mostrar contenido del fichero
	system("cls");
	printf("IP's contenidas en su fichero:\n\n");
	char lineaOrigen[100];
	while (fgets(lineaOrigen, sizeof(lineaOrigen), fileListIp)) {
		printf("%s", lineaOrigen);
	}

	
	// Preguntamos si queremos procesar las ip's o no
	printf("\n");
	char* pregunta = "Verificar IP's? (s/n): ";
	if (!preguntarSiNo(pregunta)) {
		fclose(fileListIp);
		return 0;
	}

	// Retornamos el puntero al inicio del fichero
	rewind(fileListIp);

	// Iniciamos proceso de verificación de las IP's
	printf("Esto llevara unos segundos...\n");
	while (fgets(lineaOrigen, sizeof(lineaOrigen), fileListIp)) {
		ip = lineaOrigen;
		// Limpia el String de \n
		limpiarBarraN(ip, lineaOrigen);
		printf("%s ", lineaOrigen);

		// Aseguramos que instrucción esté totalmente a 0 antes de concatenar
		memset(instruccion, 0, sizeof(instruccion));

		// Contruir la instruccion ping para system con salida en ping.txt
		strcat(instruccion, "ping ");
		strcat(instruccion, ip);
		strcat(instruccion, " > ");
		strcat(instruccion, FILE_PING);

		// llamada a ping
		system(instruccion);

		// Abrir archivo generado por system
		FILE* fileIp = fopen(FILE_PING, "r");
		if (fileIp == NULL) {
			printf("Error al abrir archivo temporal");
			return 1;
		}

		// Abrir archivo de salida para almacenar las IP's verificadas OK
		FILE* fileOut = fopen(FILE_OUT, "a");
		if (fileOut == NULL) {
			printf("Error al abrir el archivo de salida");
			return 1;
		}

		// Verificamos si el ping es OK o FAIL y actualizamos fichero de salida con IP OK
		stop = 1;
		char lineaPing[60];
		while (fgets(lineaPing, sizeof(lineaPing), fileIp) && (stop == 1)) {
			encontrada = strstr(lineaPing, BUSCAR);

			if (encontrada) {
				stop = 0; // no leemos más el archivo de origen

				encontrada = strstr(lineaPing, PING_IP_OK); // Buscamos cantidad de paquetes recibidos
				if (encontrada) {
					printf("\033[0;32m");	// Terminal a verde
					printf("OK\n");
					printf("\033[0;0m");	// Restaurar consola

					fprintf(fileOut, "%s\n", ip);	// IP ok guardada en fichero		
				}
				else {
					printf("\033[0;31m");	// Terminal a Rojo
					printf(" FAIL\n");
					printf("\033[0;0m");	// Restaurar Terminal
				}
			}
		}
		
		fclose(fileOut);
		fclose(fileIp);
	}

	fclose(fileListIp);

	// Eliminamos archivo temporal
	remove(FILE_PING);
	system("pause");
			
	return 0;
}