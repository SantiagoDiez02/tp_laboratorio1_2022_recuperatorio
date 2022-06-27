/*
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (AB)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de AB es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp_1.h"


int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	int operandoUno;
	int operandoDos;
	int resultadoSuma;
	int resultadoResta;
	int resultadoDivision;
	int resultadoMult;
	int resultadoFactUno;
	int resultadoFactDos;

	do {
		opcion = Opciones(opcion);
		switch (opcion) {
		case 1:
			printf(
					"Usted ha seleccionado la opcion 1.Ingresar 1er operando (A=x)\n");
			printf("ingrese el 1er operando\n");
			scanf("%d", &operandoUno);
			break;
		case 2:
			printf(
					"Usted ha seleccionado la opcion 2.Ingresar 2do operando (B=y)\n");
			printf("ingrese el 2do operando\n");
			scanf("%d", &operandoDos);
			break;
		case 3:
			printf(
					"Usted ha seleccionado la opcion 3.Calcular todas las operaciones\n");
			resultadoSuma = suma(operandoUno, operandoDos);
			resultadoResta = resta(operandoUno, operandoDos);

			if (operandoDos != 0) {
				resultadoDivision = division(operandoUno, operandoDos);
			}
			resultadoMult = multiplicacion(operandoUno, operandoDos);
			resultadoFactUno = factorialUno(operandoUno);
			resultadoFactDos = factorialDos(operandoDos);
			break;
		case 4:
			printf("Usted ha seleccionado la opcion 4.Informar resultados\n");
			printf(
					"el 1er operando fue: %d, el 2do operando fue: %d, y el resultado de la suma es: %d\n",
					operandoUno, operandoDos, resultadoSuma);
			printf(
					"el 1er operando fue: %d, el 2do operando fue: %d, el resultado de la resta es: %d\n",
					operandoUno, operandoDos, resultadoResta);
			if (operandoDos != 0) {

				printf(
						"el 1er operando fue: %d, el 2do operando fue: %d,el resultado de la division es: %d\n",
						operandoUno, operandoDos, resultadoDivision);
			} else {
				printf("no fue posible dividir por 0");
			}
			printf(
					"el 1er operando fue: %d, el 2do operando fue: %d, el resultado de la multiplicacion es: %d\n",
					operandoUno, operandoDos, resultadoMult);
			printf("el factorial del primer operando es: %d\n",
					resultadoFactUno);
			printf("el factorial del segundo operando es: %d\n",
					resultadoFactDos);
			break;
		case 5:
			printf(
					"Usted ha seleccionado la opcion 5.Salir. que tenga un buen dia\n");
			break;
		}

	} while (opcion != 5);
	return 0;

}
