/*
 * precio.h
 *
 *  Created on: 13 may. 2022
 *      Author: Santy
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

float total(Passenger *list, int len);
float promedio(Passenger *list, int len, float total);
int superados(float price, int len, float prom);

#endif /* FUNCIONES_H_ */
