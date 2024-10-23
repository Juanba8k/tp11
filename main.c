#include <stdio.h>

#include "traduccion.h"//main usa la funcion terminal, para esto necesita su prototipo especificado en traduccion.h


#include "juego.h"//main invoca a la funcion evaluacion, para esto necesita su prototipo especificado en juego.h


#define MAX 1000 //valor maximo de generaciones

int q=0; //flag para terminar el programa cuando se aprieta q/Q, se declara como variable global para que el archivo que contiene a la funcion terminal pueda hacer eso de la misma y modificarla

int main (void)

{	do

	{

		int gen;

		printf("Introducir numero de repeticiones (minimo 0, maximo %d repeticiones) o presionar 'q' para salir\n", MAX);

		gen= terminal();//esta funcion invocada recolecta el numero de generaciones ingresado por el usuario y lo almacena en la variable gen

		

		if(q!=1)//en la funcion terminal se usa q como flag y si se detecta que el usuario ingreso una q/Q, lo termina

		{

			evaluacion(gen);//esta funcion es el juego de la vida que termina imprimiendo la situacion final del juego, no devuelve nada

		}

	

	}

	while(q!=1);// sigue pidiendole al usuario el numero de generaciones mientras que no ingrese una Q/q

	return 0;

}