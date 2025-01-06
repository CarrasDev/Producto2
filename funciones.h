/***********************************/
/*  Autor: Daniel Carrasco Luque   */
/***********************************/

#ifndef FUNCIONES_H
#define FUNCIONES_H


/*	Se solicita un fichero con direcciones IP.
*	Muestra por pantalla el contenido del fichero.
*	Ejecuta "ping" a cada ip y verifica si la conexión es correcta.
*	Guarda el resultado en fichero "producto2.txt" */

int verificarIps(void);


/*  Obtiene la fecha y hora actual para después
*   insertar en el fichero "producto2.txt" */

int insertarFechaHora(void);


/*	Muestra el listado de adaptadores de red del PC mediante "ipconfig"
*	Permite seleccionar uno y guarda en un fichero llamado "adaptadores.txt":
*	nombre, ip, puerta de enlace y mascara de subred */

int seleccionarAdaptadorRed(void);


#endif