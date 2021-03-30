
int generarNumeroAleatorio_maymen(int min, int max);
int comoJugar_maymen();
int comenzarPartida_maymen();
int ayuda(int numJugador, int anteriorNumJugador, int numSecreto, int ronda);
int guardarPuntaje_maymen(int punt, int &sumatoriaPunt);
void menu_maymen();

int comenzarPartida_maymen(){
	int numeroSecreto = generarNumeroAleatorio_maymen(1,999);
	int puntaje = 10;
	int intento, aux, aux2, intentoAnterior;
	for(int i=0; i<10; i++){
		
		do{
			char nro[5] = {'\0'};
			char nrointento[20] = "Intento ";
			enteroACadena(i+1, nro);
			strcat(nrointento, nro);
			strcat(nrointento, ": ");
			inputInt(aux2, nrointento);
			if(aux2>999 || aux2<1){
				cout << "\nEl numero ingresado no se encuentra entre las posibilidades. \nIngreselo nuevamente...\n";
			}
		else{
			intento = aux2;
		}
		}while(aux2>999 || aux2<1);

		system("cls");

		if(intento < numeroSecreto){
			cout << "El numero secreto es mayor." << endl;
			aux = ayuda(intento, intentoAnterior, numeroSecreto, i);
			intentoAnterior = aux;
			puntaje = puntaje - 1;
		}
		else if(intento > numeroSecreto){
			cout << "El numero secreto es menor." << endl;
			aux = ayuda(intento, intentoAnterior, numeroSecreto, i);
			intentoAnterior = aux;
			puntaje = puntaje - 1;
		}
		else if(intento == numeroSecreto){
			cout << "Muy bien, acertaste!" << endl;
			cout << "Tu puntaje es " << puntaje << endl;
			limpiar(1);
			return puntaje;
		}
		if(i==9&&intento!=numeroSecreto){
			puntaje = 0;
			cout << "Has perdido." << endl;
			cout << "El numero secreto era: " << numeroSecreto << endl;
			cout << "Tu puntaje es: " << puntaje << endl;
			cout << "Intentalo otra vez!" << endl;
			limpiar(1);
			return puntaje;
		}		
	}
}

int guardarPuntaje_maymen(int punt, int &sumatoriaPunt){
	sumatoriaPunt = sumatoriaPunt + punt;
	return sumatoriaPunt;
}

int ayuda(int numJugador, int anteriorNumJugador, int numSecreto, int ronda){
	if((numJugador < numSecreto) && ronda == 0){
		printf("y se encuentra entre %d y 999.\n\n",numJugador+1);
	}
	if((numJugador < numSecreto) && ronda != 0){
		if(numJugador <= anteriorNumJugador && numJugador < numSecreto && anteriorNumJugador < numSecreto){
			numJugador = anteriorNumJugador;
			printf("al numero ingresado en este intento y el anterior.\nConsejo: Ingrese un numero mayor al que ingreso en el intento anterior a este.\n\n");
			printf("Se encuentra entre %d y 999.\n\n", numJugador+1);
		}
		else if(numJugador > anteriorNumJugador && numJugador < numSecreto && anteriorNumJugador < numSecreto){
			printf("y se encuentra entre %d y 999.\n\n", numJugador+1);
		}
		else{
			printf("y se encuentra entre %d y %d.\n\n", numJugador+1, anteriorNumJugador-1);
		}
		}
		
	if((numJugador > numSecreto) && ronda == 0){
		printf("y se encuentra entre 1 y %d.\n\n",numJugador-1);
	}
	if((numJugador > numSecreto) && ronda != 0){
		if(numJugador >= anteriorNumJugador && numJugador > numSecreto && anteriorNumJugador > numSecreto){
			numJugador = anteriorNumJugador;
			printf("al numero ingresado en este intento y el anterior.\nConsejo: Ingrese un numero menor al que ingreso en el intento anterior a este.\n\n");
			printf("Se encuentra entre 1 y %d.\n\n", numJugador-1);	
			
		}
		else if(numJugador < anteriorNumJugador && numJugador > numSecreto && anteriorNumJugador > numSecreto){
			printf("y se encuentra entre 1 y %d.\n\n", numJugador-1);	
		}	
		else{
			printf("y se encuentra entre %d y %d.\n\n", anteriorNumJugador+1, numJugador-1);
		}
	}
	return numJugador;
}

int generarNumeroAleatorio_maymen(int min, int max){
	return min + (rand()%(max-min));
}

int comoJugar__maymen(){
	int eleccion;
	
	system("cls");
	
	printf("\tComo jugar\n\n");
	printf("(1/3) MAYMEN es un juego que consiste en adivinar un numero secreto que puede estar entre el 1 y el 999.\n");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(2/3) Tendras que ingresar un numero en cada uno de tus intentos,�pero ten cuidado que tienes solo 10!\n");
	printf("\tEl programa te ira avisando si el valor que ingresaste es mayor, menor o igual al numero secreto.\n");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(3/3) Comienzas con 10 puntos y se te va restando 1 punto con cada intento fallido.\n");
	
	limpiar(1);
	
	inputInt(eleccion, "Estas listo para jugar?\n(Si=1/No=2): ", true, 1, 2);
}

void menu_maymen(){
	system("cls");

	srand((unsigned)time(0));
	int opcion, loop = 1, eleccionCase3;
	int puntajeJugador, puntajeTotal = 0;
	int partida = 0, listadoPuntaje[100];
	
	printf("  Bienvenido a MayMen\n\n");
	Cadena opciones[] = {"Comenzar una partida", "Puntajes", "Como jugar"};
	char texto_menu[450];
	formatearMenu("Bienvenido a MayMen", texto_menu, opciones, 3);
	
	while(loop==1){
		inputInt(opcion, texto_menu, true, 1, 4);

		system("cls");
		
		switch(opcion){
			case 1:
				printf("Partida %d.\nComienza a adivinar, mucha suerte!",partida+1);
				limpiar();
				puntajeJugador = comenzarPartida_maymen();
				puntajeTotal = guardarPuntaje_maymen(puntajeJugador, puntajeTotal);
				listadoPuntaje[partida] = puntajeJugador;
				partida++;
				break;
			case 2:
				cout << "Puntajes." << endl;
				if(partida>0){
					for(int x=0; x<partida; x++){
						printf("Partida %d: %d puntos.\n",x+1,listadoPuntaje[x]);
					}
					printf("Puntaje total (de %d partida/s): %d",partida,puntajeTotal);
				}
				else{
					printf("Aun no tiene puntaje. Juegue una partida!\n");
				}
				limpiar();
				break;
			case 3:
				eleccionCase3 = comoJugar__maymen();
				if(eleccionCase3 == 1){
					printf("Partida %d.\nComienza a adivinar, mucha suerte!",partida+1);
					limpiar();
					puntajeJugador = comenzarPartida_maymen();
					puntajeTotal = guardarPuntaje_maymen(puntajeJugador, puntajeTotal);
					listadoPuntaje[partida] = puntajeJugador;
					partida++;		
					break;
				}
				else if(eleccionCase3 == 2){
					loop = 1;
					break;
				}
				
			case 4:	
				loop = 0;
				break;	
		}
	}
};