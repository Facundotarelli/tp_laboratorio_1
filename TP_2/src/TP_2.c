/*
 ============================================================================
 Name        : TP_2.c
 Author      : Facundo Tarelli
 Version     :
 Copyright   : MIT
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
1 Enunciado
Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 */



#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "ArrayPassenger.h"
#include "InputsDeArray.h"
#include "herramientas.h"

int main(void)
{
	setbuf(stdout, NULL);

	int respuesta;
	int respuestaPasoDos;
	int largo = 2000;
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int contadorPasajero =0;
	int buscarPosicion;
	int ordenamiento; //ascendente y descendente
	int busqueda; //determina el tipo de busqueda
	float total;
	float promedio;
	int contadorDelMayorPromedio;
	int validacionDelAdd;
	int validacionDelRemove;
	int validacionDeLaInfo; //valida la informacion de los pasajeros
	int bandera=0;

	Passenger pasajeros [largo];

	initPassengers(pasajeros, largo);
	do
	{
		printf( "\n1-ALTAS:Ingresar pasajero: \n"
		"2-MODIFICAR: Modificar pasajero: \n"
		"3-BAJA:Eliminar pasajero: \n"
		"4-INFORMAR:Informar pasajeros: \n"
		"5- Ingreso forzado de pasajeros: \n"
		"6- Salir: \n"
		"\n Ingrese la opcion deseada:");

		scanf("%d", &respuesta);
		fflush(stdin);

		switch(respuesta)
		{
			case 1:
				contadorPasajero ++;
				rellenarArray(name, "Ingrese el nombre del pasajero:");
				rellenarArray(lastName, "Ingrese el apellido del pasajero");
				rellenarFloat(&price, "Ingrese el precio del vuelo");
				rellenarArray(flycode, "Ingrese el codigo de vuelo");
				rellenar(&typePassenger,"Ingrese el tipo de pasajero:");
				validacionDelAdd = 	addPassenger(pasajeros, largo, contadorPasajero, name, lastName, price, typePassenger,flycode);
				if(validacionDelAdd == -1)
				{
					printf("Error, vuelva a ingresar");
				}
				bandera = 1;
				break;
		case 2:
			if(bandera ==1)
			{
				rellenar(&id,"Ingrese el id del pasajero a modificar: " );
				buscarPosicion = findPassengerById(pasajeros, largo, id);
				do{
					printf( "\n1-Modificar nombre. \n"
					"2-Modificar apellido. \n"
					"3-Modificar precio. \n"
					"4-Modificar codigo de vuelo. \n"
					"5- Modificar tipo de pasajero. \n"
					"6- Salir. \n"
					"\n Ingrese la opcion deseada.");

					scanf("%d", &respuestaPasoDos);
					fflush(stdin);
					switch(respuestaPasoDos)
					{
						case 1:
							rellenarArray(pasajeros[buscarPosicion].name, "\nIngrese el nombre del pasajero:");
							break;
						case 2:
							rellenarArray(pasajeros[buscarPosicion].lastName, "Ingrese el apellido del pasajero");
							break;
						case 3:
							rellenarFloat(&pasajeros[buscarPosicion].price, " Ingrese el precio a modificar." );
							break;
						case 4:
							rellenarArray(pasajeros[buscarPosicion].flycode, "Ingrese el codigo de vuelo");
							break;
						case 5:
							rellenar(&pasajeros[buscarPosicion].typePassenger, "Ingrese el tipo de pasajero:");
							break;
						case 6:
							printf("\nFinalizacion del sistema, hasta luego");
							break;
						default:
							printf("\nError,opcion erronea, vuelva a intentarlo");
							break;
					}
				}while (respuestaPasoDos !=6);
			}
			else
			{
				printf("\nError, debe ingresar por el paso 1 antes de ingresar al 2\n");
			}
			break;
		case 3:
			if(bandera ==1)
			{
				rellenar(&id,"Ingrese el id del pasajero a modificar: " );
				buscarPosicion = findPassengerById(pasajeros, largo, id);
				pasajeros[buscarPosicion].isEmpty = -1;
				validacionDelRemove = removePassenger(pasajeros, largo, buscarPosicion);
				if(validacionDelRemove == -1)
				{
					printf("Error, vuelva a intentar");
				}
			}
			else
			{
				printf("\nError, debe ingresar por el paso 1 antes de ingresar al 3\n");
			}
			break;
		case 4:
			if(bandera ==1)
			{
				rellenar(&ordenamiento, "\n1-Ordenar por el apellido y por el tipo de pasajero. \n2-Ordenamiento por el codigo y el estado de vuelo.");
				rellenar(&busqueda, "\n1-Ordenar de forma ascendente. \n2-Ordenar de forma descendente.");
				total = totalDelArray(pasajeros, largo);
				promedio = promedioDeArray(pasajeros, largo, total);
				contadorDelMayorPromedio = contadorDelMayorAlPromedio(pasajeros, largo, promedio);
				if(ordenamiento == 1)
				{
					validacionDeLaInfo= sortPassengers(pasajeros, largo, ordenamiento);
				}
				else
				{
					validacionDeLaInfo= sortPassengersByCode(pasajeros, largo, ordenamiento);
				}
				if(validacionDeLaInfo == -1)
				{
					printf("Error, vuelva a intentarlo");
				}
				printPassenger(pasajeros, largo);
				printf("La suma de todos los precios %f y el promedio es %f. %d pasajeros superan ese promedio", total, promedio, contadorDelMayorPromedio);
			}
			else
			{
				printf("\nError, debe ingresar por el paso 1 antes de ingresar al 4\n");
			}
			break;
		case 5:
			contadorPasajero ++;
			strcpy(name, "Pepe");
			strcpy(lastName, "Argento");
			price = 2000;
			typePassenger = 1;
			strcpy(flycode, "BAN-17");
			addPassenger(pasajeros, largo, contadorPasajero, name, lastName, price, typePassenger,flycode);
			contadorPasajero ++;
			strcpy(name, "Moni");
			strcpy(lastName, "Argento");
			price = 3000;
			typePassenger = 2;
			strcpy(flycode, "BAN-18");
			addPassenger(pasajeros, largo, contadorPasajero, name, lastName, price, typePassenger,flycode);
			contadorPasajero ++;
			strcpy(name, "Paola");
			strcpy(lastName, "Argento");
			price = 4000;
			typePassenger = 3;
			strcpy(flycode, "BAN-19");
			addPassenger(pasajeros, largo, contadorPasajero, name, lastName, price, typePassenger,flycode);
			contadorPasajero ++;
			strcpy(name, "Coqui");
			strcpy(lastName, "Argento");
			price = 5000;
			typePassenger = 4;
			strcpy(flycode, "BAN-20");
			addPassenger(pasajeros, largo, contadorPasajero, name, lastName, price, typePassenger,flycode);
			bandera= 1;
			break;
		case 6:
			printf("\n Hasta luego!");
			break;
		default:
			printf("\nOpcion no valida.\n");
			break;
		}
	}while(respuesta != 6);

	return 0;
}
