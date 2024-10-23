#include <stdio.h>
#include "traduccion.h"
#define MAX 1000

unsigned int convertor (char a);
extern int q;
int terminal ()
{
    char c;
    unsigned int gen;
do //Se encarga de que el numero ingresado sea menor o igual a MAX
	{
	    c = getchar (); //pido el primer char
	    if (c=='\n') //si se apreta enter, se devuelve gen=1, para que solo avance una generación
			{
			gen= 1;
			}
	    else if ((c== 'q' || c== 'Q')) //si se ingresa q, se activa la flag que termina el programa
			{
			q=1;
			printf("FIN.\n");
			}
	    else //se llama a la funcion que convierte el numero ingresado en pantalla a entero
		{

		    gen = convertor(c);

		    if (gen>MAX) //si gen es mas grande que max, muestra un error en terminal
		    {
		        printf("error, volver a ingresar numero:\n");
		    }
		} 
	    }
	    while (gen>MAX); //si gen no es mas chico o igual a MAX, se repite el proceso que pide el numero, hasta ingresar un numero valido
	    return gen;
}


unsigned int convertor (char a) //funcion que convierte el las repeticiones ingresadas en la terminal a un numero decimal legible por el compilador.
{
    unsigned int num=0;
    int flag=0;
    do 
    { 
            if (flag==0) //si flag esta en 0, significa que la funcion se llamo por primera vez, y se presta atencion al 'a' cargado anteriormente
            {
            ++flag; //se incrementa flag, para que al repetir el proceso, e indicar que la proxima, cuando se active el while (a!='\n'), debe solicitar el dato con getchart
            }
            else 
            {
                a = getchar(); //si se activa la flag, entonces la funcion pide el dato con getchart localmente
            }

            if((a<='9')&&(a>='0')) //se evalua si el caracter extraido de la terminal es un numero del 0 al 9 o si es algun caracter distinto de un numero. Si es un numero, opera con el mismo.
            {
                num= num*10 +(a-'0'); //para el primer digito, inicialmente, num vale 0, por lo que lo unico que se hace es redefinir a num como el numero decimal extraido del ascii. La resta hace la diferencia entre los decimales y el ascii para ellos. Ejemplo>> el ascii del 9 es el 57. 57-48 es 9 decimal. Para obtener el numero final, se multiplica por 10 al numero previo y luego se le suma el consecutivo.
            }
            else if (a == '\n') // si es enter, no hace nada
            {
            }
            else //si el caracter obtenido de la terminal no es un numero, da error de formato y se asigna num como -1, un valor no valido en ascii que sirve para luego pedir que se ingrese nuevamente los datos.  
            {
                num=MAX+100; // devuelve un numero que hace repetir el loop que solicita datos
                while ((a=getchar())!= '\n') //limpia los posiibles caracteres puestos despues del caracter incompatible
                {
                }
            }
    }while (a!= '\n');

    return num; //ahora la funcion vale lo que obtenga de estas operaciones, osea, el numero ingresado en la terminal en decimal.
}
