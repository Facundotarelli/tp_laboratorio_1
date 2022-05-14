/*
 * herramientas.c
 *
 *  Created on: 13 may. 2022
 *      Author: tarel
 */

#include "ArrayPassenger.h"

float totalDelArray(Passenger* valores, int longitud)
{
		int i;
		float acumulador =0;

		for(i =0; i < longitud; i++)
		{
			if(valores[i].isEmpty != -1)
			{
				acumulador = acumulador + valores[i].price;
			}
		}
	return acumulador;
}

float promedioDeArray(Passenger* valores, int longitud, float total)
{
	int i;
	float promedio =0;
	int contador;


	for(i =0; i < longitud; i++)
		{
			if(valores[i].isEmpty != -1)
			{
				contador++;
			}
		}
			promedio = total /contador;

	return promedio;
}

int contadorDelMayorAlPromedio(Passenger* valores, int longitud, float promedio)
{

	int i;
	float contador =0;



			for(i =0; i < longitud; i++)
			{
				if(valores[i].isEmpty != -1)
				{
					if(valores[i].price > promedio)
					{
						contador++;
					}
				}
			}


			return contador;

}
