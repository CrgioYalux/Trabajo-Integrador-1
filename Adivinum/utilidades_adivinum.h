int comoJugar_adivinum();
int comenzarPartida_adivinum();
int generarNumeroAleatorio_adivinum(int min, int max);
void check(int numeroUsuario, int numeroSecreto);
int guardarPuntaje_adivinum(int punt, int &sumatoriaPunt);
void descomponerNumero(int numero, int &u, int &d, int &c, int &uM);
void menu_adivinum();

int comenzarPartida_adivinum(){
	int numAleatorio, numUsuario;
	int uNumUsuario, dNumUsuario, cNumUsuario, uMNumUsuario;
	numAleatorio = generarNumeroAleatorio_adivinum(1000, 9999);
	int intento = 0, puntaje = 10;
	bool aux_loop = true;

	for(int x=1; x<=10; x++){
		do{
			char nro[5] = {'\0'};
			char intento[30] = "Intento ";
			enteroACadena(x, nro);
			strcat(intento, nro);
			strcat(intento, ": ");
			
			inputInt(numUsuario, intento, true, 1);

			descomponerNumero(numUsuario, uNumUsuario, dNumUsuario, cNumUsuario, uMNumUsuario);
			if(numUsuario<1000||numUsuario>9999){
				cout << "El numero ingresado no tiene cuatro cifras. Ingreselo nuevamente." << endl;
				limpiar(1);
			}
			else if(uNumUsuario==0 || dNumUsuario==0 || cNumUsuario==0 || uMNumUsuario==0 || uNumUsuario==dNumUsuario || uNumUsuario==cNumUsuario || uNumUsuario==uMNumUsuario || dNumUsuario==cNumUsuario || dNumUsuario==uMNumUsuario || cNumUsuario==uMNumUsuario){
				cout << "El numero ingresado no puede contener 0 y sus digitos deben ser diferentes entre si. Ingreselo nuevamente" << endl;
				limpiar(1);
			}
			else{
				aux_loop = false;
			}
		}while(aux_loop);
	
		check(numUsuario, numAleatorio);
		
		if(numUsuario!=numAleatorio){
			puntaje--;
		}
		else if(numUsuario==numAleatorio){
			cout << "Felicitaciones! Acertaste el numero." << endl;
			cout << "Puntaje obtenido: " << puntaje << endl;
			limpiar(1);
			break;
		}
		intento++;
		if(intento==10&&numUsuario!=numAleatorio){
			printf("Has perdido! El numero era: %d\nPuntaje obtenido: 0",numAleatorio);
			limpiar(1);
		}
	}
	return puntaje;
}

void check(int numeroUsuario, int numeroSecreto){
	int uNumUsuario, uNumSecreto;
	int dNumUsuario, dNumSecreto;
	int cNumUsuario, cNumSecreto;
	int uMNumUsuario, uMNumSecreto;
	
	int posicionesIncorrectas = 0, posicionesCorrectas = 0;
	
	descomponerNumero(numeroUsuario, uNumUsuario, dNumUsuario, cNumUsuario, uMNumUsuario);
	descomponerNumero(numeroSecreto, uNumSecreto, dNumSecreto, cNumSecreto, uMNumSecreto);
	
	if(uNumUsuario == uNumSecreto){
		posicionesCorrectas++;
	}
	else if(uNumUsuario == dNumSecreto || uNumUsuario == cNumSecreto || uNumUsuario == uMNumSecreto){
		posicionesIncorrectas++;
	}
	
	if(dNumUsuario == dNumSecreto){
		posicionesCorrectas++;
	}
	else if(dNumUsuario == uNumSecreto || dNumUsuario == cNumSecreto || dNumUsuario == uMNumSecreto){
		posicionesIncorrectas++;
	}
	if(cNumUsuario == cNumSecreto){
		posicionesCorrectas++;
	}
	else if(cNumUsuario == uNumSecreto || cNumUsuario == dNumSecreto || cNumUsuario == uMNumSecreto){
		posicionesIncorrectas++;
	}
	if(uMNumUsuario == uMNumSecreto){
		posicionesCorrectas++;
	}
	else if(uMNumUsuario == uNumSecreto || uMNumUsuario == dNumSecreto || uMNumUsuario == cNumSecreto){
		posicionesIncorrectas++;
	}
	printf("\nCant. Misma Posicion: %d - Cant. Otra Posicion: %d\n\n",posicionesCorrectas,posicionesIncorrectas);
}

int comoJugar_adivinum(){
	int eleccion;
	system("cls");
	printf("\tComo jugar\n\n");
	printf("(1/3) Adivinum es un juego que consiste en adivinar un numero de 4 cifras.\n");
	printf("El numero estara formado por digitos del 1 al 9. Ademas, los digitos no se repetiran.");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(2/3) Tendras 10 intentos para adivinarlo.\n");
	printf("El programa te ira avisando cuantos digitos estan bien ubicados y cuantos no lo estan.");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(3/3) Comienzas con 10 puntos y se te va restando 1 punto con cada intento fallido.");
	
	limpiar(1);
	
	inputInt(eleccion, "Estas listo para jugar?\n(Si=1/No=2): ", true, 1, 2);
	return eleccion;
}

int guardarPuntaje_adivinum(int punt, int &sumatoriaPunt){
	sumatoriaPunt = sumatoriaPunt + punt;
	return sumatoriaPunt;
}

void descomponerNumero(int numero, int &u, int &d, int &c, int &uM){
	uM=numero/1000;
	c=(numero-(uM*1000))/100;
	d=(numero- (uM*1000 + c*100))/10;
	u=numero-(uM*1000 + c*100 + d*10 );
}

int generarNumeroAleatorio_adivinum(int min, int max){
	int numero = min + (rand()%(max-min));
	int u, d, c, uM;
	descomponerNumero(numero, u, d, c, uM);
	while(u==0 || d==0 || c==0 || uM==0 || u==d || u==c || u==uM || d==c || d==uM || c==uM){
		numero = min + (rand()%(max-min));
		descomponerNumero(numero, u, d, c, uM);
	}
	return numero;
}

void menu_adivinum(){
	system("cls");
	srand((unsigned)time(0));
	int loop = 1, opcion, opcion2, partida = 0, listadoPuntaje[100];
	int puntaje, puntajeTotal;
	//menu
	Cadena opciones[] = {"Comenzar una partida", "Puntajes", "Como jugar"};
	char texto_menu[450];
	formatearMenu("Bienvenido a Adivinum", texto_menu, opciones, 3);
	
	while(loop == 1){
		inputInt(opcion, texto_menu, true, 1, 4);
		
		system("cls");
		
		switch(opcion){
			case 1:
				printf("Partida %d.\nComienza a adivinar, mucha suerte!",partida+1);
				limpiar(1);
				puntaje = comenzarPartida_adivinum();
				puntajeTotal = guardarPuntaje_adivinum(puntaje, puntajeTotal);
				listadoPuntaje[partida] = puntaje;
				partida++;
				break;
			case 2:
				printf("\tPuntajes\n\n");
				if(partida>0){
					for(int x=0; x<partida; x++){
						printf("Partida %d: %d puntos.\n",x+1,listadoPuntaje[x]);
					}
					printf("Puntaje total (de %d partida/s): %d",partida,puntajeTotal);
				}
				else{
					printf("Aun no tiene puntaje. Juegue una partida!\n");
				}
				limpiar(1);
				break;
			case 3:
				opcion2 = comoJugar_adivinum();
				if(opcion2 == 1){
					printf("Partida %d.\nComienza a adivinar, mucha suerte!",partida+1);
					limpiar(1);
					puntaje = comenzarPartida_adivinum();
					puntajeTotal = guardarPuntaje_adivinum(puntaje, puntajeTotal);
					listadoPuntaje[partida] = puntaje;
					partida++;
				}
				break;
			case 4:
				loop = 0;
				break;
		}
	}
};