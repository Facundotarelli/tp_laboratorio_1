/*
 * paraElTp1.h
 *
 *  Created on: 10 abr. 2022
 *      Author: tarel
 */



#ifndef PROTOTIPOTP_H_
#define PROTOTIPOTP_H_

#include "PrototipoTp.h"

#include <stdio.h>
#include <stdlib.h>

///@fn descontar(float)
/// @brief Para los descuentos de Aerolineas y descuentos de Latam
///
/// @param descuentoAerolineas,descuentoLatam
/// @return el precio ingresado con descuento
float descontar(float precio);

///@fn aumento(float)
/// @brief Para los aumentos de Aerolineas y aumentos de Latam
///
/// @param interesAerolineas,interesLatam
/// @return el precio ingresado con aumento
float aumento(float);

///@fn dividirBtc(float)
/// @brief Para calcular precio en bitcoin
///
/// @param btcLatam,btcAerolineas
/// @return El precio en bitcoin
float dividirBtc(float);

///@fn precioPorKm(float,float)
/// @brief Para calcular el precio por kilometro
///
/// @param unitarioAerolineas,unitarioLatam
/// @return muestra el precio tras ser multiplicado por la cantidad de kilometros
float precioPorKm(float precio, float kilometros);

///@fn diferenciaPrecio(float,float)
/// @brief Para mostrar la diferencia de precio entre Aerolineas y Latam
///
/// @param diferencias
/// @return Muestra cuanta diferencia hay entre Aerolineas y Latam
float diferenciaPrecio(float latam, float aerolineas);


#endif /* PROTOTIPOTP_H_ */
