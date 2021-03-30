void completar(char letra, string palabra, string &palabraSec);
void guardarErrores(char error, char arreglo[], int nError);
void errores(char letra, string palabra, int &errores);
string elegirPalabra(string array[], int sizeArray);
int guardarPuntaje_ahorcado(int punt, int &sumatoriaPunt);
void estadoCuerpo(string partes[], int errores);
int generarNumeroAleatorio_ahorcado(int min, int max);
string ocultarPalabra(string palabra);
void aMayus(char &letra);
int esLetra(char letra);
int comenzarPartida_ahorcado();
int comoJugar_ahorcado();
void menu_ahorcado();

void guardarErrores(char error, char arreglo[], int nError){
		arreglo[nError-1] = error;
}

int esLetra(char letra){
	int cont = 0;
	for(int x=0; x<10; x++){
		if(letra == NUMEROS[x]){
			return 0;
		}
	}
	return 1;
}

int comenzarPartida_ahorcado(){
	// variables
	string conjuntoPalabras[] = {"COMPILADOR","ENTORNO","COMPUTADORA","ESTRUCTURA","SELECCION","REPETICION","DIRECTIVA","ALGORITMO","PROGRAMA","EJECUCION",
	"INT","FLOAT","CHAR","DOUBLE","LONG","IF","ELSE","FOR","WHILE","RETURN","BREAK","SWITCH","CASE","MAIN","INCLUDE","DEFINE","STRUCT","CIN","COUT","ENDL"};
	string partesCuerpo[] = {"Cabeza","Tronco","Brazo izquierdo","Brazo derecho","Pierna izquierda","Pierna derecha","Mano izquierda","Mano derecha","Pie izquierdo","Pie derecho"};
	int cantConjPalabras = sizeof(conjuntoPalabras)/sizeof(conjuntoPalabras[0]);
	int cantPartesCuerpo = sizeof(partesCuerpo)/sizeof(partesCuerpo[0]);
	string palabraRandom = elegirPalabra(conjuntoPalabras,cantConjPalabras+1);
	string palabraOculta = ocultarPalabra(palabraRandom);
	string comprobar = palabraOculta;
	char intentoCaracter;
	int jugada = 1;
	int puntaje = 0, contadorErrores = 0;
	int loop1 = 1, usado=1, cont=0, contPartes = 0;
	int aux1, aux2;
	char listaErrores[] = {'x','x','x','x','x','x','x','x','x','x','x'};
	int sizeListaErrores;
	char separador[100];
	crearSeparador(separador, 70, '-');
	
	//funcionamiento
	for(int x=0; x<cantPartesCuerpo*3; x++){
		do{
			do{
				cout << separador << endl;
				cout << "Palabra a adivinar: " << palabraOculta << endl;
				cout << "Jugada " << jugada << endl;
				if(contPartes == 10){
					cout << "Ten cuidado, este es tu ultimo intento!" << endl;
				}
				cout << "Ingresa una letra: ";
				cin >> intentoCaracter;
				if(!esLetra(intentoCaracter)){
					cout << "\n\nDebes ingresar una letra. No se permiten numeros o simbolos." << endl;
					limpiar(1);
				}
				aMayus(intentoCaracter);
					if(contPartes>0){
						for(int n=0; n<sizeListaErrores; n++){
							if(intentoCaracter==listaErrores[n]){
								aux1=1;
								cout << "\n\nEsta letra ya fue agregada a la lista de intentos fallidos. Intenta con otra." << endl;
								break;
							}
							else{
								aux1=0;
							}
							
						}
					}
			}while(aux1==1);
			for(int a=0; a<palabraOculta.length(); a++){
				if(intentoCaracter==palabraOculta[a]){
					cont++;
				}
			}
			
			if(cont>=1){
				cout << "\nEsta letra ya ha sido ingresada. Intente con otra.\n";
				cont = 0;
				usado = 1;
			}
			else if(cont==0){
				usado = 0;
				break;		
			}
	
		}while(usado==1);
		aux2 = contPartes;
		completar(intentoCaracter,palabraRandom,palabraOculta);	
		errores(intentoCaracter,palabraRandom,contPartes);
		
		if(contPartes!=aux2){
			guardarErrores(intentoCaracter,listaErrores,contPartes);
		}
		
		if(contPartes>0){
			sizeListaErrores = sizeof(listaErrores)/sizeof(listaErrores[0]);
			cout << "Intentos fallidos: ";
			for(int z=0; z<sizeListaErrores; z++){
				if(z==0){
					cout << listaErrores[z];
				}
				else{
					cout << " - " << listaErrores[z];
				}
			}
		}
		
		if(contPartes == 11){
			puntaje = 0;
			cout << "Perdiste! Te has quedado sin intentos." << endl;
			cout << "Tu puntaje es: " << puntaje << endl;
			cout << "La palabra era: " << palabraRandom << endl;
			return puntaje;
			break;
		}
		else{
			estadoCuerpo(partesCuerpo,contPartes);
		}

		if(palabraOculta==palabraRandom&&contPartes==0){
			puntaje = 50;
			cout << "Muy bien, has acertado. Y sin errores!" << endl << "Tu puntaje: " << puntaje << " puntos." << endl;
			break;
		}else if(palabraOculta==palabraRandom&&contPartes>0){
			puntaje = 50 - (2*contPartes);
			cout << "Muy bien, has acertado!" << endl << "Tu puntaje: " << puntaje << " puntos." << endl;
			break;
		}
		jugada++;
	}
	return puntaje;
}

int guardarPuntaje_ahorcado(int punt, int &sumatoriaPunt){
	sumatoriaPunt = sumatoriaPunt + punt;
	return sumatoriaPunt;
}

void estadoCuerpo(string partes[], int errores){
	for(int x=0; x<errores; x++){
		if(x==(errores-1)){
			if(x==0){
				cout << "\nEstado del mu\244eco: " << partes[x];
			}
			else{
				cout << " - " << partes[x];
			}
		}
		else{
			if(x==0){
				cout << "\nEstado del mu\244eco: " << partes[x];
			}
			else{
				cout << " - " << partes[x];
			}
		}			
	}
	cout << endl << endl;
}

string elegirPalabra(string array[], int sizeArray){
	int palabra = generarNumeroAleatorio_ahorcado(0,sizeArray);
	return array[palabra];
}

void aMayus(char &letra){
	string abcMin = "abcdefghijklmnopqrstuvwxyz";
	string abcMay = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for(int x=0; x<abcMin.length(); x++){
		if(letra == abcMin[x]){
			letra = abcMay[x];
		}
	}
}

void completar(char letra, string palabra, string &palabraSec){
	char guion = '_';
	for(int x=0; x<palabra.size(); x++){
		if(letra == palabra[x]){
			palabraSec[x] = letra;
		}
		else if(palabraSec[x]=='_'){
			palabraSec[x] = guion;
		}
	}
}

void errores(char letra, string palabra, int &errores){
	int aux=0;
	for(int x=0; x<palabra.size(); x++){
		if(letra == palabra[x]){
			aux++;
		}
	}
	if(aux==0){
		errores++;
	}
}	

string ocultarPalabra(string palabra){
	char guion = '_';
	string oculta = palabra;
	for(int x=0; x<palabra.length(); x++){
		oculta[x] = guion;
	}
	return oculta;
}

int generarNumeroAleatorio_ahorcado(int min, int max){
	int numero = min + (rand()%(max-min));
	return numero;
}

int comoJugar_ahorcado(){
	int eleccion;
	system("cls");
	printf("\tComo jugar\n\n");
	printf("(1/4) Ahorcado es un juego que consiste en adivinar palabras.\n");
	printf("En este caso las palabras estan asociadas con la programacion en c++.");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(2/4) El usuario debera adivinar la palabra caracter por caracter.\n");
	printf("Cada vez que falle se iran agregando partes del cuerpo del ahorcado.\n");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(3/4) El cuerpo tiene 10 partes por lo que el usuario tiene 10 intentos para completarlo.\n");
	printf("Al llegar a los 10 intentos, el siguiente error provocara el estado de ahorcado y el usuario perdera la partida.\n");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(4/4) Si gana, el usuario obtendra 50 puntos menos el doble de los errores que haya cometido.\n");
	printf("Si pierde su puntaje sera 0.\n");
	
	limpiar(1);
	
	inputInt(eleccion, "Estas listo para jugar?\n(Si=1/No=2): ", true, 1, 2);
	return eleccion;
}

void menu_ahorcado(){
	system("cls");
	srand((unsigned)time(0));
	int puntaje = 0, sumatoriaPuntaje = 0, partida = 0;
	int opcion, opcion2;
	int loop = 1;
	int listadoPuntajes[100];
	
	Cadena opciones[] = {"Comenzar una partida", "Puntajes", "Como jugar"};
	char texto_menu[450];
	formatearMenu("Bienvenido al Ahorcado", texto_menu, opciones, 3);

	while(loop == 1){
		inputInt(opcion, texto_menu, true, 1, 4);
	
		system("cls");
		
		switch(opcion){
			case 1:
				printf("Partida %d. Mucha suerte!\n",partida+1);
				limpiar(1);
				puntaje = comenzarPartida_ahorcado();
				sumatoriaPuntaje = guardarPuntaje_ahorcado(puntaje,sumatoriaPuntaje);
				listadoPuntajes[partida] = puntaje;
				partida++;
				limpiar(2);
				break;
			case 2:
				printf("\tPuntajes\n\n");
				if(partida>0){
					for(int x=0; x<partida; x++){
						printf("Partida %d: %d puntos.\n",x+1,listadoPuntajes[x]);
					}
					printf("Puntaje total (de %d partida/s): %d",partida,sumatoriaPuntaje);
				}
				else{
					printf("Aun no tiene puntaje. Juegue una partida!\n");
				}
				limpiar(2);
				break;
			case 3:
				opcion2 = comoJugar_ahorcado();
				if(opcion2==1){
					printf("Partida %d. Mucha suerte!\n",partida+1);
					limpiar(1);
					puntaje = comenzarPartida_ahorcado();
					sumatoriaPuntaje = guardarPuntaje_ahorcado(puntaje,sumatoriaPuntaje);
					listadoPuntajes[partida] = puntaje;
					partida++;
					limpiar(2);
				}
				break;
			case 4:
				loop = 0;
				break;
		}
	}
}