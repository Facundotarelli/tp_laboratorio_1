/*
 * paraElTp1.c
 *
 *  Created on: 10 abr. 2022
 *      Author: tarel
 */

float descontar(float precio)
{
	float descuento;

	descuento = precio - (precio * 0.10);

	return descuento;

}

float aumento(float importe)
{
	float interes;

	interes = importe * 1.25;

	return interes;
}

float dividirBtc(float precio)
{
	float divisionBtc;

	divisionBtc = precio / 50000;

	return divisionBtc;

}

float precioPorKm(float precio, float kilometros)
{
	float precioMultiKm;

	precioMultiKm = precio / kilometros;

    return precioMultiKm;
}

float diferenciaPrecio(float latam, float aerolineas)
{
	float difenciaLaAe;

		if(latam > aerolineas)
		{
			difenciaLaAe = latam - aerolineas;

		}
		else
		{
			difenciaLaAe = aerolineas;
		}

	return difenciaLaAe;
}
