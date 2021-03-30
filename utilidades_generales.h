#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cstring>
#include<math.h>
#include<strings.h>
#include<limits.h>

using namespace std;

char NUMEROS[] = "0123456789";

typedef char Cadena[100]; 


void inputInt(int &resultado, const char texto[], bool permitirLimites = false, int valorMin = INT_MIN, int valorMax = INT_MAX);
int cantidadCoincidencias(char cadena1[], char cadena2[]);
void formatearMenu(const char tituloMenu[], char output[], Cadena opciones[], int cantOpciones);
int convertirCadenaEnEntero(char cadena[]);
char enteroACaracter(int numero);
void crearSeparador(char resultado[], int len, const char separador);
int lenCadenaMasLarga(Cadena cadenas[], int cantCadenas);
void limpiar(int i = 0);
void enteroACadena(int entero, char resultado[]);
int descomponerEntero(int numero);
void crearArregloDesdeInt(int numero, int cantUnidades, int arregloResultado[]);

void inputInt(int &resultado, const char texto[], bool permitirLimites, int valorMin, int valorMax){
	bool loop = true;
	do{
		char aux_input[100];
		if(strlen(texto) != 0){
			cout << texto;
		}
		_flushall();
		gets(aux_input);

		system("cls");

		if(cantidadCoincidencias(aux_input, NUMEROS) == strlen(aux_input)){
			resultado = convertirCadenaEnEntero(aux_input);

			if(permitirLimites){
				if(resultado < valorMin || resultado > valorMax){
					cout << "El valor ingresado no es valido. Intentelo otra vez." << endl;
					limpiar(1);
				}
				else{
					loop = false;
				}
			}
			else{
				loop = false;
			}
		}
		else{
			cout << "Solo se permiten caracteres numericos. Intentelo otra vez." << endl;
			limpiar(1);
		}
	}while(loop);
};

int cantidadCoincidencias(char cadena1[], char cadena2[]){
	int cadena1Len = strlen(cadena1);
	int cadena2Len = strlen(cadena2);
	int contadorCoincidencias = 0;
	
	for(int i=0; i<cadena1Len; i++){
		for(int j=0; j<cadena2Len; j++){
			if(cadena1[i] == cadena2[j]){
				contadorCoincidencias++;
			}
		}
	}
	
	return contadorCoincidencias;
};

int convertirCadenaEnEntero(char cadena[]){
  int potencia = strlen(cadena);
  int resultado = 0;
  for(int i=0; i<strlen(cadena); i++){
    potencia--;
    double unidad = pow(10, potencia);
    char caracter = cadena[i];
    int aEntero = caracter - '0';
    int valor = unidad * aEntero;
    resultado = resultado + valor;
  }
	return resultado;
};

void formatearMenu(const char tituloMenu[], char output[], Cadena opciones[], int cantOpciones){
	int resultadoLen = cantOpciones * 100 + 50;
	char resultado[resultadoLen] = {'\0'};

	char minimunLen = strlen("Cerrar la aplicacion\n");
	int len = lenCadenaMasLarga(opciones, cantOpciones);
	if(len < minimunLen){
		len = minimunLen;
	}
	char separador[len+6];
	crearSeparador(separador, len+4, '=');

	strcat(resultado, tituloMenu);
	strcat(resultado, "\n");
	strcat(resultado, separador);

	for(int i=0; i<cantOpciones; i++){
		char numero = enteroACaracter(i+1);
		char numero_opcion[] = {numero, '.', '\0'};
		char opcion[100] = {'\0'};
		strcat(opcion, numero_opcion);
		strcat(opcion, opciones[i]);
		strcat(opcion, "\n");
		strcat(resultado, opcion);
	}

	char numero = enteroACaracter(cantOpciones+1);
	char numero_opcion[] = {numero, '.', '\0'};
	char opcion[100] = {'\0'};
	strcat(opcion, "\n");
	strcat(opcion, numero_opcion);	
	strcat(opcion, "Cerrar la aplicacion\n");
	strcat(resultado, opcion);
	strcat(resultado, separador);
	strcat(resultado, "Ingrese una opcion: ");
	strcpy(output, resultado);
}


char enteroACaracter(int numero){
    return numero + '0';
}

void crearSeparador(char resultado[], int len, const char separador){
	char texto_separador[len];
	for(int i=0; i<len-2; i++){
		texto_separador[i] = separador;
	}
	texto_separador[len-2] = '\n';
	texto_separador[len-1] = '\0';
	strcpy(resultado, texto_separador);
}

int lenCadenaMasLarga(Cadena cadenas[], int cantCadenas){
	int lenCadena = 0;
	for(int i = 0; i<cantCadenas; i++){
		if(strlen(cadenas[i]) > lenCadena){
			lenCadena = strlen(cadenas[i]);
		} 
	}
	return lenCadena;
}

void limpiar(int i){
	if(i==1){
		printf("\nPresione una tecla para continuar...\n\n");	
	}
	getch();
	system("cls");
};


void enteroACadena(int entero, char resultado[]){
	int enteroLen = descomponerEntero(entero);
	int arreglo_entero[enteroLen]; 
	crearArregloDesdeInt(entero, enteroLen, arreglo_entero);

	for(int i = 0; i < enteroLen; i++){
		resultado[i] = enteroACaracter(arreglo_entero[i]);
	}
};

int descomponerEntero(int numero){
	int unidades = 0;
	while(true){
		if(numero == 0){
			return unidades;
		}
		numero /= 10;				
		unidades++;
	}
};

void crearArregloDesdeInt(int numero, int cantUnidades, int arregloResultado[]){
	for(int i=cantUnidades-1; i>=0; i--){
		arregloResultado[i] = numero % 10;
		numero /=  10;
	}
};