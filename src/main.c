#include <stdio.h>
#include <stdlib.h>
#include "tp_1.h"
#include "Input.h"

int main(void) {

	setbuf(stdout, NULL);

	float kilometros = 0;
	int opcion;
	float precioVueloAerolineas = 0;
	float aerolineasCredito;
	float aerolineasDebito;
	float aerolineasBitcoin;
	float aerolineasUnitario;
	float precioVueloLatam = 0;
	float latamCredito;
	float latamDebito;
	float latamBitcoin;
	float latamUnitario;
	int agencia;
	int kilometrosForzado = 7090;
	int precioAerolineaForzado = 162965;
	int precioLatamForzado = 159339;
	float diferenciaPrecios;

	int flagDeCargas = 0;

	do {
		printf("\n1. Ingresar kilometros"
				"\n2. Ingresar precio de vuelos"
				"\n3. Calcular todos los costos"
				"\n4. Informar resultados"
				"\n5. Carga forzada de datos"
				"\n6. Salir\n"

				"\nSeleccione una opcion:");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			utn_getNumeroFlotante(&kilometros,
					"Ingrese la cantidad de kilometros:\n",
					"ERROR. Reingrese la cantidad de kilometros:\n", 0, 1000000,
					4);
			flagDeCargas++;
			break;
		case 2:

			do {
				utn_getNumeroEntero(&agencia,
						"\nDesea ingresar el precio de Aerolineas o Latam?\n 1 para aerolineas o 2 para latam) ",
						"1 para aerolineas o 2 para latam", 1, 2, 4);

				switch (agencia) {
				case 1:
					utn_getNumeroFlotante(&precioVueloAerolineas,
							"Ingrese el precio del vuelo: \n",
							"ERROR. Reingrese el precio del vuelo: \n", 0,
							1000000, 4);

					break;
				case 2:
					utn_getNumeroFlotante(&precioVueloLatam,
							"Ingrese el precio del vuelo: \n",
							"ERROR. Reingrese el precio del vuelo: \n", 0,
							1000000, 4);
				}
			} while (agencia != 1 && agencia != 2);
			flagDeCargas++;
			break;
		case 3:
			if (flagDeCargas >= 2) {

				calcularValores(precioVueloAerolineas, kilometros,
						&aerolineasDebito, &aerolineasCredito,
						&aerolineasBitcoin, &aerolineasUnitario);
				calcularValores(precioVueloLatam, kilometros, &latamDebito,
						&latamCredito, &latamBitcoin, &latamUnitario);
				diferenciaPrecios = calcularDiferencia(precioVueloAerolineas,
						precioVueloLatam);
			} else {
				printf("\nNo ingreso los kilometros o el precio del vuelo\n");
			}
			break;
		case 4:
			if (flagDeCargas >= 2) {
				mostrarInformacion(precioVueloAerolineas, kilometros,
						aerolineasDebito, aerolineasCredito, aerolineasBitcoin,
						aerolineasUnitario, precioVueloLatam, latamDebito,
						latamCredito, latamBitcoin, latamUnitario,
						diferenciaPrecios);
			} else {
				printf("\nNo ingreso los kilometros o el precio del vuelo\n");
			}
			break;
		case 5:
			calcularValores(precioAerolineaForzado, kilometrosForzado,
					&aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin,
					&aerolineasUnitario);
			calcularValores(precioLatamForzado, kilometrosForzado, &latamDebito,
					&latamCredito, &latamBitcoin, &latamUnitario);
			diferenciaPrecios = calcularDiferencia(precioAerolineaForzado,
					precioLatamForzado);

			mostrarInformacion(precioAerolineaForzado, kilometrosForzado,
					aerolineasDebito, aerolineasCredito, aerolineasBitcoin,
					aerolineasUnitario, precioLatamForzado, latamDebito,
					latamCredito, latamBitcoin, latamUnitario,
					diferenciaPrecios);
			break;
		case 6:
			printf("usted selecciono la opcion 6, salir, muchas gracias!!!"
					"Santiago Diez");
			break;
		default:
			printf("\nError, ingrese una opcion valida\n");
		}
	} while (opcion != 6);

	return EXIT_SUCCESS;
}
