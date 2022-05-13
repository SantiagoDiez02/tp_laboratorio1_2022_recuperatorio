#include "ArrayPassenger.h"
#include "Input.h"
#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#define VACIO -1

int initPassengers(Passenger *list, int len) {
	int i = 0;

	for (; i < len; i++) {
		list[i].isEmpty = VACIO;
	}

	return 0;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
		float price, int typePassenger, int statusFlight, char flyCode[]) {
	int i = 0;
	for (; i < len; i++) {
		if (list[i].isEmpty == VACIO) {
			list[i].isEmpty = 0;
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			list[i].statusFlight = statusFlight;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			strcpy(list[i].flyCode, flyCode);

			printf("\n\tSU ID ES: %d\n", id);

			i = len + 1;
		}

	}
	return 0;
}

int findPassengerById(Passenger *list, int len, int id) {
	int i;
	int posicionADevolver;

	for (i = 0; i < len; i++) {
		if (list[i].id == id) {
			posicionADevolver = i;
			i = len + 1;
		}
	}

	return posicionADevolver;
}

int removePassenger(Passenger *list, int len, int id) {
	int posicionAVaciar = -1;
	int retorno = 0;
	posicionAVaciar = findPassengerById(list, len, id);

	if (posicionAVaciar == -1) {
		retorno = -1;
	}

	list[posicionAVaciar].isEmpty = -1;

	return retorno;
}

int sortPassengers(Passenger *list, int len, int order) {
	int i;
	int j;
	int value = 0;

	Passenger listAux;

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (list[j].isEmpty != -1) {
				if (order == 1) {
					if (list[i].typePassenger > list[j].typePassenger) {
						value = 1;
					} else {
						value = strcmp(list[i].lastName, list[j].lastName);
					}
				}

				else {
					if (list[i].typePassenger < list[j].typePassenger) {
						value = strcmp(list[j].lastName, list[i].lastName);
					}
				}

				if (value == 1) {
					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flyCode, list[i].flyCode);
					listAux.typePassenger = list[i].typePassenger;
					listAux.statusFlight = list[i].statusFlight;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flyCode, list[j].flyCode);
					list[i].typePassenger = list[j].typePassenger;
					list[i].statusFlight = list[j].statusFlight;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flyCode, listAux.flyCode);
					list[j].typePassenger = listAux.typePassenger;
					list[j].statusFlight = listAux.statusFlight;
				}
			}
		}
	}
	return 0;
}
int printPassenger(Passenger *list, int len) {

	printf(
			"\n\tID: \t|| Nombre: \t|| Apellido: || Codigo De Vuelo: || Precio: \t\t|| Tipo De Pasajero:   || Estado De Vuelo: \n");
	for (int i = 0; i < len; i++) {
		if (list[i].id != 0) {
			printf(
					" \t%d \t||   %s \t||   %s \t||   %s \t||     %.2f \t||    %d \t\t||   %d\n",
					list[i].id, list[i].name, list[i].lastName, list[i].flyCode,
					list[i].price, list[i].typePassenger, list[i].statusFlight);
		} else {
			break;
		}
	}

	return 0;
}
int sortPassengersByCode(Passenger *list, int len, int order) {
	int i;
	int j;
	int value = 0;

	Passenger listAux;

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (list[j].isEmpty != -1) {
				if (order == 1) {
					if (list[i].statusFlight > list[j].statusFlight) {
						value = 1;
					} else {
						value = strcmp(list[i].flyCode, list[j].flyCode);
					}
				}

				else {
					if (list[i].statusFlight < list[j].statusFlight) {
						value = strcmp(list[j].flyCode, list[i].flyCode);
					}
				}

				if (value == 1) {
					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flyCode, list[i].flyCode);
					listAux.typePassenger = list[i].typePassenger;
					listAux.statusFlight = list[i].statusFlight;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flyCode, list[j].flyCode);
					list[i].typePassenger = list[j].typePassenger;
					list[i].statusFlight = list[j].statusFlight;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flyCode, listAux.flyCode);
					list[j].typePassenger = listAux.typePassenger;
					list[j].statusFlight = listAux.statusFlight;
				}
			}
		}
	}
	return 0;
}
