/*
 * ArrayPassenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: Facundo Tarelli
 */


#include <stdio.h>
#include "ArrayPassenger.h"
#include <string.h>



int initPassengers(Passenger* list, int len)
{
	int i=0;

	for(i=0; i < len; i ++)
	{
		list[i].isEmpty = -1;

	}
	return 0;
}

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int i=0;
	setbuf(stdout, NULL);

	for(i=0; i < len; i++)
		{
			if(list[i].isEmpty == -1)
			{

				list[i].isEmpty =0;

				list[i].id = id;

				list[i].price = price;

				list[i].typePassenger = typePassenger;

				strcpy(list[i].name, name);

				strcpy(list[i].lastName, lastName);

				strcpy(list[i].flycode, flycode);

				printf("\nEl id del pasajero es %d\n", list[i].id);

				i = len + 1;
			}
		}
		return 0;
	}
int findPassengerById(Passenger* list, int len, int id)
{
	int posicion; //posicion que busco con el id
	int i=0;

	if(list == NULL)
	{

		return -1;
	}
	for(i=0; i < len; i ++)
	{
		if(list[i].id == id)
		{
		posicion = i;
		}
	}
		return posicion;
}

int sortPassengers(Passenger* list, int len, int order)
{

	int i =0;
	int j =0;
	int comparacionValor = 0;

	Passenger lista;

		if(list == NULL)
		{
		return -1;
		}


		for(i = 0; i < len; i++)
		{
			for (j = i+1; j < len; j++)
			{
				if (list[j].isEmpty != -1)
				{
					if (order == 1)
					{
						if(list[i].typePassenger > list[j].typePassenger)
						{
							comparacionValor = 1;
						}
						else
						{
							if(list[i].typePassenger == list[j].typePassenger)
							{
								comparacionValor = strcmp(list[i].lastName, list[j].lastName);
							}
						}
					}
					else
					{
						if(list[i].typePassenger < list[j].typePassenger)
						{
							comparacionValor = 1;
						}
						else
						{
							if(list[i].typePassenger == list[j].typePassenger)
							{
								comparacionValor = strcmp(list[j].lastName, list[i].lastName);
							}
						}

						if(comparacionValor ==1)
						{
							lista.id = list[i].id;
							strcpy(lista.name, list[i].name);
							strcpy(lista.lastName, list[i].lastName);
							lista.price = list[i].price;
							strcpy(lista.flycode, list[i].flycode);
							lista.typePassenger = list[i].typePassenger;

							list[i].id = list[j].id;
							strcpy(list[i].name, list[j].name);
							strcpy(list[i].lastName, list[j].lastName);
							list[i].price = list[j].price;
							strcpy(list[i].flycode, list[j].flycode);
							list[i].typePassenger = list[j].typePassenger;

							list[j].id = lista.id;
							strcpy(list[j].name, lista.name);
							strcpy(list[j].lastName, lista.lastName);
							list[j].price = lista.price;
							strcpy(list[j].flycode, lista.flycode);
							list[j].typePassenger = lista.typePassenger;
						}

					}
				}

			}

		}
		return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i =0;
	int j =0;
	int comparacionValor = 0;

	Passenger lista;

		if(list == NULL)
		{
			return -1;
		}

		for(i = 0; i < len; i++)
		{
			for (j = i+1; j < len; j++)
			{
				if (list[j].isEmpty != -1)
				{
					if (order == 1)
					{
						if(list[i].statusFlight > list[j].statusFlight)
						{
							comparacionValor = 1;
						}
						else
						{
							if(list[i].statusFlight == list[j].statusFlight)
							{
								comparacionValor = strcmp(list[i].flycode, list[j].flycode);
							}
						}
					}
					else
					{
						if(list[i].statusFlight < list[j].statusFlight)
						{
							comparacionValor = 1;
						}
						else
						{
							if(list[i].statusFlight == list[j].statusFlight)
							{
								comparacionValor = strcmp(list[j].flycode, list[i].flycode);
							}
						}

						if(comparacionValor ==1)
						{
							lista.id = list[i].id;
							strcpy(lista.name, list[i].name);
							strcpy(lista.lastName, list[i].lastName);
							lista.price = list[i].price;
							strcpy(lista.flycode, list[i].flycode);
							lista.typePassenger = list[i].typePassenger;

							list[i].id = list[j].id;
							strcpy(list[i].name, list[j].name);
							strcpy(list[i].lastName, list[j].lastName);
							list[i].price = list[j].price;
							strcpy(list[i].flycode, list[j].flycode);
							list[i].typePassenger = list[j].typePassenger;

							list[j].id = lista.id;
							strcpy(list[j].name, lista.name);
							strcpy(list[j].lastName, lista.lastName);
							list[j].price = lista.price;
							strcpy(list[j].flycode, lista.flycode);
							list[j].typePassenger = lista.typePassenger;
						}

					}
				}

			}

		}
		return 0;
}


int printPassenger(Passenger* list, int length)
{
	int i;

	for(i = 0; i< length; i++)
	{
		if(list[i].isEmpty != -1)
		{
			printf("%d -", list[i].id);
			printf(list[i].lastName);
			printf(" ");
			printf(list[i].name);
			printf(" - Precio: ");
			printf("$%f - Codigo de vuelo: ", list[i].price);
			printf(" -");

			if(list[i].typePassenger == 1)
			{
				printf(" Menor ");

			}
			else
			{
				if(list[i].statusFlight == 2)
				{
					printf(" Adolescente");
				}
				else
				{
					printf(" Adulto ");
				}
			}


			if(list[i].statusFlight == 1)
			{
				printf(" Activo ");
			}
			else
			{
				printf(" Inactivo ");
			}
			printf("\n _________________________\n");
		}
	}
	return 0;
}

int removePassenger(Passenger* list, int len, int id)
{
	int posicionVaciar = -1;
	int retorno =0;
	posicionVaciar = findPassengerById(list, len, id);

	if(list == NULL)
	{
		return -1;
	}

	list[posicionVaciar].isEmpty = -1;
	list[posicionVaciar].id = -1;

	return retorno;
}


