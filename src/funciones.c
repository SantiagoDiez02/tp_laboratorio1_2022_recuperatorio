/*
 * precio.c
 *
 *  Created on: 13 may. 2022
 *      Author: Santy
 */

#include "ArrayPassenger.h"
#include "funciones.h"
#include <limits.h>

float total(Passenger *list, int len) {
	float acum;
	acum = 0;

	for (int i = 0; i < len; i++) {
		acum += list[i].price;
	}
	return acum;
}
float promedio(Passenger *list, int len, float total) {
	float prom;
	float contador;
	prom=0;
	contador = 0;
	for (int i = 0; i < len; i++) {
		contador++;

	}
	prom = total / contador;
	return prom;
}
int superados(float price, int len, float prom) {
	int contador = 0;
	float i;
	for (i = 0; i < len; i++) {
		if (prom < price) {
			contador++;
		}
	}
	return contador;
}

