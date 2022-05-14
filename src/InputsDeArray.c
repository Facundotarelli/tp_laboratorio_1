/*
 * InputsDeArray.c
 *
 *  Created on: 11 may. 2022
 *      Author: Facundo Tarelli
 */

#include <stdio.h>
#include <string.h>


void rellenar(int* variableQueRecibe, char textoQueMuestra[])
{
	printf(textoQueMuestra);
	scanf("%d", variableQueRecibe);
	fflush(stdin);
}

void rellenarFloat(float* variableQueRecibe, char textoQueMuestra[])
{
		printf(textoQueMuestra);
		scanf("%f", variableQueRecibe);
		fflush(stdin);
	}


void rellenarArray(char arrayQueRecibe[], char textoQueMuestra[])
{
		printf(textoQueMuestra);
		gets(arrayQueRecibe);
		fflush(stdin);

}


