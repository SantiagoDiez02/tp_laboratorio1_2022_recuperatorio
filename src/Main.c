/*
 ============================================================================
 Name        : tp_2.c
 Author      : Santy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 *  (!) El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP2 de la materia, el mismo deberá de ser realizado utilizando Eclipse. Recuerden que tiene que encontrarse en el mismo repositorio reportado, no en uno nuevo.
 *	(!) Si no cuenta con los archivos .cproject y .project el TP no se corregirá.
 *	(!) El TP debe contar, al menos, con la biblioteca correspondiente a la entidad y otra donde se encuentren los inputs.
 *	(!) Recuerden que si el TP no compila o rompe al momento de hacer alguna prueba se encuentra desaprobado.
 *	(!) No se deben modificar los prototipos de las funciones dadas en el enunciado
 *
 *  Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
 *	no puede tener más de 2000 pasajeros.
 *	Datos:
 *
 *	El sistema deberá tener el siguiente menú de opciones:
 *	1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
 *	número de Id. El resto de los campos se le pedirá al usuario.
 *
 *	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 *	o Precio o Tipo de pasajero o Código de vuelo
 *	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 *	4. INFORMAR:
 * 	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
 * 	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
 *	promedio.
 *	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 *	1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 *	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 *	carga de algún pasajero.
 *	2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 */

//SANTIAGO DIEZ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Input.h"
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int id;
	char namePassenger[51];
	char lastNamePassenger[51];
	float price;
	char flyCode[10];
	int typePassenger; //1.'Ejecutivo' - 2.'Turista' - 3.'VIP'
	int statusFlight; //1.'Activo' - 2.'Cancelado'
	int verificar;
	int idABuscar;
	int posicionDada;
	int respuestaSubMenu;
	int respuestaSubMenu2;
	int idABorrar;
	int respuesta;
	int largo;
	float tot;
	float prom;
	int contador;

	tot=0;
	prom=0;
	contador=0;

	id = 0;
	largo = 2000;

	Passenger pasajeros[largo];

	initPassengers(pasajeros, largo);

	do {
		printf("\n------------MENU------------\n"
				"\nIngrese la opcion deseada.\n"
				"\n\t1- Ingresar pasajero.\n"
				"\n\t2- Modificar pasajero.\n"
				"\n\t3- Eliminar pasajero.\n"
				"\n\t4- Informar pasajeros.\n"
				"\n\t5- Ingreso forzado de pasajeros.\n"
				"\n\t6- Salir.\n");
		scanf("%d", &respuesta);
		fflush(stdin);

		switch (respuesta) {
		case 1:

			verificar = cadenaValidada(namePassenger,
					"\nIngrese el nombre del pasajero\n");
			if (verificar == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato válido\n");
			}

			verificar = cadenaValidada(lastNamePassenger,
					"\nIngrese el apellido del pasajero\n");
			if (verificar == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato válido\n");
			}

			verificar = cadenaValidada(flyCode,
					"\nIngrese el codigo de vuelo\n");
			if (verificar == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato válido\n");
			}

			verificar = utn_getNumeroFlotante(&price,
					"\nIngrese el precio del vuelo\n"
							"(de mil a un millon)\n", "\n\tERROR.\n", 1000,
					1000000, 4);
			if (verificar == -1) {

				break;
			} else {
				printf("\nFunciono correctamente,Dato válido\n");
			}
			verificar =
					utn_getNumeroEntero(&typePassenger,
							"\nIngrese el tipo de pasajero. \n1.'Ejecutivo' - 2.'Turista' - 3.'VIP'\n",
							"\n\tERROR.\n", 1, 3, 4);
			if (verificar == -1) {

				break;
			} else {
				printf("\nFunciono correctamente,Dato válido\n");
			}

			verificar =
					utn_getNumeroEntero(&statusFlight,
							"\nIngrese el estado del vuelo. \n1.'Activo' - 2.'Cancelado'\n",
							"\n\tERROR.\n", 1, 2, 4);
			if (verificar == -1) {

				break;
			} else {
				printf("\nFunciono correctamente,Dato válido\n");
			}
			id++;

			addPassenger(pasajeros, largo, id, namePassenger, lastNamePassenger,
					price, typePassenger, statusFlight, flyCode);

			break;

		case 2:
			if (id != 0) {
				pedirEntero(&idABuscar,
						"\nIngrese la ID que se va a MODIFICAR\n");

				if (idABuscar != id) {
					printf("\n\nAun no existe esa ID\n"
							"Ingrese una existente porfavor\n");
					break;
				}

				posicionDada = findPassengerById(pasajeros, largo, idABuscar);

				do {
					printf("\n\n\t--Modificacion--\n"
							"\n¿que desea modificar a continuacion?\n"
							"\n\t1- Modificar nombre.\n"
							"\n\t2- Modificar apellido.\n"
							"\n\t3- Modificar codigo de vuelo.\n"
							"\n\t4- Modificar precio.\n"
							"\n\t5- Modificar tipo de pasajero.\n"
							"\n\t7- Salir.\n");
					scanf("%d", &respuestaSubMenu);
					fflush(stdin);

					switch (respuestaSubMenu) {
					case 1:

						verificar = cadenaValidada(pasajeros[posicionDada].name,
								"\nIngrese el nombre modificado\n");
						if (verificar == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato válido\n");
						}
						break;

					case 2:
						verificar = cadenaValidada(
								pasajeros[posicionDada].lastName,
								"\nIngrese el apellido modificado\n");
						if (verificar == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato válido\n");
						}
						break;

					case 3:

						verificar = cadenaValidada(
								pasajeros[posicionDada].flyCode,
								"\nIngrese el codigo de vuelo modificado.\n");
						if (verificar == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato válido\n");
						}
						break;

					case 4:

						verificar = utn_getNumeroFlotante(
								&pasajeros[posicionDada].price,
								"\nIngrese el precio modificado.\n"
										"(de mil a un millon)\n",
								"\n\tERROR.\n", 1000, 1000000, 4);
						if (verificar == -1) {

							break;
						} else {
							printf("\nFunciono correctamente,Dato válido\n");
						}
						break;

					case 5:
						verificar =
								utn_getNumeroEntero(
										&pasajeros[posicionDada].typePassenger,
										"\n\nIngrese el tipo de pasajero modificado.\n 1.'Ejecutivo' - 2.'Turista' - 3.'VIP'\n",
										"\n\tERROR.\n", 1, 3, 4);
						if (verificar == -1) {

							break;
						} else {
							printf("\nFunciono correctamente,Dato válido\n");
						}

						break;

					case 6:
						verificar =
								utn_getNumeroEntero(
										&pasajeros[posicionDada].statusFlight,
										"\n\nIngrese el tipo de pasajero modificado.\n 1.'Ejecutivo' - 2.'Turista' - 3.'VIP'\n",
										"\n\tERROR.\n", 1, 3, 4);
						if (verificar == -1) {

							break;
						} else {
							printf("\nFunciono correctamente,Dato válido\n");
						}

						break;
					case 7:
						printf("\n\nSaliendo al menu\n");
						break;

					default:
						printf("\n\nOpcion no valida.\n");

					}
				} while (respuestaSubMenu != 7);

			} else {
				printf("\n\n<Faltan datos o no se selecciono la opcion 1>\n");
			}
			break;
		case 3:
			if (id != 0) {

				pedirEntero(&idABorrar,
						"\n\nIngrese el ID que se va a BORRAR\n");

				if (idABorrar != id) {
					printf("\n\nAun no existe esa ID\n"
							"Ingrese una existente porfavor\n");
					break;
				}

				removePassenger(pasajeros, largo, idABorrar);
			} else {
				printf("\n\n<Faltan datos o no se selecciono la opcion 1>\n");
			}
			break;

		case 4:
			if (id != 0) {
				do {
					printf(
							"\n\n\t--Mostrar y Ordenar--\n"
									"\n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
									"\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el preciopromedio."
									"\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
									"\n\t4- Salir.\n");
					scanf("%d", &respuestaSubMenu2);
					fflush(stdin);

					switch (respuestaSubMenu2) {
					case 1:
						sortPassengers(pasajeros, largo, 1);
						printPassenger(pasajeros, largo);
						break;
					case 2:

						tot = total(pasajeros, largo);
						prom = promedio(pasajeros, largo, tot);
						contador = superados(price, largo, prom);
						printf(
								"el total es: %f, el promedio es: %f y la cantidad de pasajeros que superan el promedio son: %d",
								tot, prom, contador);
						break;
					case 3:
						sortPassengersByCode(pasajeros, largo, 1);
						printPassenger(pasajeros, largo);
						break;
					case 4:
						printf("\n\nSaliendo al menu\n");
						break;
					default:
						printf("\n\nOpcion no valida.\n");

					}
				} while (respuestaSubMenu2 != 4);

			} else {
				printf("\n\n<Faltan datos o no se selecciono la opcion 1>\n");
			}
			break;
		case 5:
			id++;
			strcpy(namePassenger, "santiago");
			strcpy(lastNamePassenger, "diez");
			price = 15000;
			typePassenger = 2;
			strcpy(flyCode, "latam");
			statusFlight = 1;

			addPassenger(pasajeros, largo, id, namePassenger, lastNamePassenger,
					price, typePassenger, statusFlight, flyCode);

			id++;
			strcpy(namePassenger, "lucas");
			strcpy(lastNamePassenger, "rodriguez");
			price = 17000;
			typePassenger = 1;
			strcpy(flyCode, "despegar");
			statusFlight = 2;

			addPassenger(pasajeros, largo, id, namePassenger, lastNamePassenger,
					price, typePassenger, statusFlight, flyCode);

			id++;
			strcpy(namePassenger, "pedro");
			strcpy(lastNamePassenger, "pascal");
			price = 20000;
			typePassenger = 3;
			strcpy(flyCode, "latam");
			statusFlight = 1;

			addPassenger(pasajeros, largo, id, namePassenger, lastNamePassenger,
					price, typePassenger, statusFlight, flyCode);

			id++;
			strcpy(namePassenger, "agustin");
			strcpy(lastNamePassenger, "suarez");
			price = 25000;
			typePassenger = 2;
			strcpy(flyCode, "euro");
			statusFlight = 1;

			addPassenger(pasajeros, largo, id, namePassenger, lastNamePassenger,
					price, typePassenger, statusFlight, flyCode);

			id++;
			strcpy(namePassenger, "vanesa");
			strcpy(lastNamePassenger, "lenes");
			price = 19000;
			typePassenger = 1;
			strcpy(flyCode, "latam");
			statusFlight = 2;

			addPassenger(pasajeros, largo, id, namePassenger, lastNamePassenger,
					price, typePassenger, statusFlight, flyCode);

			break;
		case 6:
			printf("\nSaliendo del menu.\n"
					"\n\n\n\tMUCHAS GRACIAS!!!\n"
					"\nSantiago Diez");
			break;

		default:
			printf("\nOpcion no valida.\n");
			break;

		}

	} while (respuesta != 6);

	return 0;
}
