/*
 ============================================================================
 Name        : Tp1.c
 Author      : Facundo Tarelli Division D
 Version     :
 Copyright   : MIT
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.  El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 */

#include <stdio.h>
#include <stdlib.h>

#include "PrototipoTp.h"

int main(void) {

	setbuf(stdout,NULL);

	float kilometros=0;
	int opciones;
	float precioAerolineas=0;
	float precioLatam=0;
	float descuentoAerolineas;
	float interesAerolineas;
	float descuentoLatam;
	float interesLatam;
	float btcAerolineas;
	float btcLatam;
	float unitarioAerolineas;
	float unitarioLatam;
	float diferencias;
	float flagUno=0;
	float flagDos=0;
	float flagTres=0;


	do {
			printf("\n 1-Ingresar Kilómetros: (Km = %.2f)\n"
			"\n 2-Ingresar Precio de los Vuelos(aerolineas= %.2f , latam= %.2f). \n"
			"\n 3-Calcular todos los costos \n"
			"\n 4-Informar Resultados \n"
			"\n 5-Carga forzada de datos \n"
			"\n 6-salir \n"
			"\n Ingrese la opcion deseada: ", kilometros, precioAerolineas, precioLatam);
			fflush(stdin);
			scanf("%d" , &opciones);


		switch(opciones)
		{

		case 1:

			printf(" \n Ingrese kilometros: ");
			scanf("%f" , &kilometros);

			while(kilometros <1)
			{
				printf("Error, el numero ingresado es invalido, vuelva a intentar con un numero mayor a 0 \n");
				fflush(stdin);
				scanf("%f" , &kilometros);
			}
			flagUno=1;
			break;

		case 2:

			printf("\n Ingrese precio de Aerolineas: ");
			scanf("%f" , &precioAerolineas);

			while(precioAerolineas <1)
			{
				printf("Vuelva a intentar con un numero mayor a 0 \n");
				fflush(stdin);
				scanf("%f" , &precioAerolineas);

			}

			printf("\n Ingrese precio de Latam: ");
					scanf("%f" , &precioLatam);

			while(precioLatam <1)
			{
				printf("Vuelva a intentar con un numero mayor a 0 \n");
				fflush(stdin);
				scanf("%f" , &precioLatam);

			}

			flagDos=1;
			break;

		case 3:

			if(flagUno && flagDos)
			{

				descuentoLatam = descontar(precioLatam);
				interesLatam =  aumento(precioLatam);
				btcLatam = dividirBtc(precioLatam);
				unitarioLatam= precioPorKm(precioLatam, kilometros);

				descuentoAerolineas = descontar(precioAerolineas);
				interesAerolineas =  aumento(precioAerolineas);
				btcAerolineas = dividirBtc(precioAerolineas);
				unitarioAerolineas= precioPorKm(precioAerolineas, kilometros);

				diferencias = diferenciaPrecio(precioAerolineas, precioLatam);
				flagTres=1;
			}
			else
			{
				printf("\n Error, pase por 1 y 2 antes de continuar \n ");
			}

		break;

		case 4:
			if(flagTres==1)
			{
				printf("KMs Ingresados: %.2f km\n\n", kilometros);
				printf("Precio Aerolineas: $%.2f\n", precioAerolineas);
				printf("a) Precio con tarjeta de debito: %.2f\n" , descuentoAerolineas);
				printf("b) precio con tarjeta de credito: %.2f\n" , interesAerolineas);
				printf("c) precio pagando con bitcoin: %.2f\n", btcAerolineas);
				printf("d) Mostrar precio unitario:  $ %.2f \n\n", unitarioAerolineas);

				printf("Precio Latam: $%.2f\n", precioLatam);
				printf("a) Precio con tarjeta de debito: %.2f\n" , descuentoLatam);
				printf("b) precio con tarjeta de credito: %.2f\n" , interesLatam);
				printf("c) precio pagando con bitcoin: %.2f\n", btcLatam);
				printf("d) Mostrar precio unitario: $ %.2f \n\n", unitarioLatam);

				printf("La diferencia de precio es de: $ %.2f \n", diferencias);
			}
			else
			{
				printf("Error, debe pasar por el 3 antes de continuar");
			}

			 break;

		case 5:

				kilometros = 7090;
				precioAerolineas=162965;
				precioLatam=159339;

				descuentoLatam = descontar(precioLatam);
				interesLatam =  aumento(precioLatam);
				btcLatam = dividirBtc(precioLatam);
				unitarioLatam= precioPorKm(precioLatam, kilometros);

				descuentoAerolineas = descontar(precioAerolineas);
				interesAerolineas =  aumento(precioAerolineas);
				btcAerolineas = dividirBtc(precioAerolineas);
				unitarioAerolineas= precioPorKm(precioAerolineas, kilometros);
				diferencias = diferenciaPrecio(precioAerolineas, precioLatam);


				printf("Carga forzada de datos\n");
				printf("KMs Ingresados: %.2f km\n\n", kilometros);
				printf("Precio Aerolineas: $%.2f\n", precioAerolineas);
				printf("a) Precio con tarjeta de debito: %.2f\n" , descuentoAerolineas);
				printf("b) precio con tarjeta de credito: %.2f\n" , interesAerolineas);
				printf("c) precio pagando con bitcoin: %.2f\n", btcAerolineas);
				printf("d) Mostrar precio unitario:  $ %.2f \n\n", unitarioAerolineas);

				printf("Precio Latam: $%.2f\n", precioLatam);
				printf("a) Precio con tarjeta de debito: %.2f\n" , descuentoLatam);
				printf("b) precio con tarjeta de credito: %.2f\n" , interesLatam);
				printf("c) precio pagando con bitcoin: %.2f\n", btcLatam);
				printf("d) Mostrar precio unitario: $ %.2f \n\n", unitarioLatam);

				printf("La diferencia de precio es de: $ %.2f \n", diferencias);


			break;

		case 6:

			printf("\n Gracias por su visita, hasta luego.");


			break;

		default:

			printf("Opcion invalida, el numero ingreso es mayor que 6 o menor que 1 o es un caracter \n");

		}

		}while(opciones !=6);

	return 0;
}
