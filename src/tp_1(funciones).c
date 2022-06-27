#include <stdio.h>
#include <stdlib.h>


int Opciones(int opcion) {

	printf("\nElija una opcion: ");
	printf("\n1. Ingresar 1er operando (A=x)");
	printf("\n2. Ingresar 2do operando (B=y)");
	printf("\n3. Calcular todas las operaciones");
	printf("\n4. Informar resultados");
	printf("\n5. Salir");

	scanf("%d", &opcion);

	return opcion;
}

int suma(int operandoUno, int operandoDos) {
	int resultado;

	resultado = operandoUno + operandoDos;

	return resultado;
}

int resta(int operandoUno, int operandoDos) {
	int resultado;

	resultado = operandoUno - operandoDos;

	return resultado;
}

int division(int operandoUno, int operandoDos) {
	int resultado;

	resultado = operandoUno / operandoDos;

	return resultado;
}

int multiplicacion(int operandoUno, int operandoDos) {
	int resultado;

	resultado = operandoUno * operandoDos;
	return resultado;
}

int factorialUno(int operandoUno) {
	int resultFactUno;
	if (operandoUno == 0) {
		resultFactUno = 1;
	} else {
		resultFactUno = operandoUno * factorialUno(operandoUno - 1);
	}

	return resultFactUno;
}


int factorialDos(int operandoDos) {
	int resultFactDos;
	if (operandoDos == 0) {
		resultFactDos = 1;
	} else {
		resultFactDos = operandoDos * factorialDos(operandoDos - 1);
	}

	return resultFactDos;
}

