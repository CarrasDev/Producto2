/***********************************/
/*  Autor: Daniel Carrasco Luque   */
/***********************************/

#ifndef FUN_AUX_H
#define FUN_AUX_H


/*	Se utiliza para vaciar el buffer despúes de una llamada de teclado */

void limpiarBuffer();


/*	Se utiliza para quitar la \n de un string */

void limpiarBarraN(char* destino, char* origen);


/*	Verificar ruta a fichero de usuario 
 *	Return 0 = OK, 1 = FAIL */

int verificarRuta(const char* ruta);


/*	Función generica para realizar preguntas tipo si o no.
*	Se le pasa String con la pregunta.
*   Retorna: Si = 1, No = 0;  */

int preguntarSiNo(const char* pregunta);


/* Borra la indexación creada para seleccionar los adaptadores */

void eliminarIndexación(char* entrada, char* salida);


#endif