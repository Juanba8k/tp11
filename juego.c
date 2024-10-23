#include <stdio.h>
#include "juego.h"
//defino numero de filas y columnas
#define MAX 1000
#define COL 7
#define FIL 7
// directivas preprocesador
#if(COL<=0)
      #error columnas negativas
#endif

#if(FIL<=0)
	#error filas negativas
#endif

#if((COL>50 ) || (FIL>50)|| ((FIL*COL)>1000))
	#warning dificil de ver
#endif
//prototipos
int supervivencia (int, int);
void printeo_matriz (void); //



int mati[FIL][COL]={{1,1,1,1,1,1,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,1,1,1,1,1,1}};//estado inicial
int matf[FIL][COL];//matriz auxiliar para no "pisar" el estado inicial del juego que se almacena en mati

	
void evaluacion (int gen)
{

int i=0;
int j=0;
int m;

printf("Estado inicial:\n"); //Se imprime la matriz ingresada
printeo_matriz ();

printf("Se avanzaron %d generaciones.\n", gen);

for(m=gen; m!=0;--m)
{
	for(i=0; i<COL ; ++i)   //recorre las columnas de mati
	{
		for (j=0 ; j<FIL ; ++j)   //recorre las filas de mati
		{	
			matf[j][i] = supervivencia(j,i);    //llama a la funcion que se encarga de analizar a las celulas vecinas y determinar si vive o muere cada posicion, esto se guarda en una matriz auxiliar matf
		}
	}
}

for(i=0; i<COL ; ++i)
{
	for (j=0; j<FIL ; ++j)
	{	
		int k;
		k= matf[j][i];    //transfiere datos de matriz alternativa a la real
		mati[j][i]=k;	
	}		
}		
	  
	
printeo_matriz (); //se imprime la matriz luego de avanzar las generaciones ingresadas


}

//funciones invocadas en la funcion terminal

int supervivencia (int j, int i) //la funcion recibe lugar por lugar de mati
{
int p=0;    //nueva "columna"
int t=0;    //nueva "fila"
int celvivas=0;   //contador celulas vivas
int a=0;//sera lo que devuelve esta funcion, 1 si esta viva o 0 si esta muerta luego de jugar el juego
for(p=(i-1) ; (p<=(i+1)) ; ++p)   //recorre los vecinos por columna
{
    if((p<0)||(p>(COL-1)))    //chequea no salirse del rango columnas
    {
    }
    else
    {
        for(t= (j-1);t<=(j+1); ++t)   //recorre los vecinos por fila
        {
            if((j==t)&&(i==p))    //celula que se esta evaluando, no hace nada
            {
            }
            else if ((t<0)||(t>(FIL-1)))    //chequea no salirse del rango de filas
            {
            }
            else 
            {
              if (mati[t][p]==1)    //si la celula del lugar evaluado es uno, aumenta un contador para luego ver cuantas vecinas vivas tendra la celula que esta siendo evaluada
              { 
                celvivas = (celvivas +1);
              }
              else
              {
            
              }
            }
       
          }
      }
}
if (mati[j][i]==1)    //si celula inicialmente viva
{
  if ((celvivas==3)||(celvivas==2) )    //deja el mismo valor (viva),si tiene dos o tres vivas a su alrededor
  { 
    a=1;
  }
  else
  {
    a=0;   //mata la celula
  }
}
else  //si celula inicialmente muerta
{
  if (celvivas==3)  //hace que viva la celula si tiene tres vecinas
  {
    a=1;
  }
  else    //celula continua muerta
  {
  a=0;
  }
}
return a;    //devuelve si la posicion esta en 1, celula viva, o en 0, celula muerta.
}


//esta cambiando el valor de mati no el de matf
//chequear cual es el error



void printeo_matriz (void) // muestra la matriz en la terminal, se solicita el i y j, para que siempre esten inicializados en 0
{
	for(int j=0; j<FIL ; ++j)
	{
		    for (int i=0; i<COL ; ++i)
		    {
		        if(mati[j][i]==1)
		        {
		            printf("|*|");
		        }
		        else
		        {
		            printf("| |");
		        }   	
		    }
		    printf("\n");
	} 

}