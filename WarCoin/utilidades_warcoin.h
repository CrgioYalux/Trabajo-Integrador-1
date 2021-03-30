int generarNumeroAleatorio_warcoin(int min, int max);
int comenzarPartida_warcoin();
int guardarPuntaje_warcoin(int punt, int &sumatoriaPunt);
int comoJugar_warcoin();
void menu_warcoin();

int comenzarPartida_warcoin(){
	system("cls");
	int cantMinMonedasUsuario, cantMaxMonedasUsuario;
	int cantidadMonedas = generarNumeroAleatorio_warcoin(10,50);
	int turno = generarNumeroAleatorio_warcoin(1,3);
	int loop = 1, ronda = 1;
	int eliminarMonedas, eliminarMonedasPc;
	int puntaje = 0;
	
	inputInt(cantMinMonedasUsuario, "Ingresa la cantidad minima de monedas que se pueden retirar: ", true, 1);
	inputInt(cantMaxMonedasUsuario, "Ingresa la cantidad maxima de monedas que se pueden retirar: ", true, 1);

	system("cls");
	do{
		inputInt(cantidadMonedas, "Cantidad de monedas inicial: ");
		if(cantidadMonedas < cantMaxMonedasUsuario){
			cout << "La cantidad inicial de monedas es menor a la cantidad maxima de monedas que pueden retirar." << endl;
			cout << "Vuelva a ingresar." << endl;
			limpiar(1);
		}
	}while(cantidadMonedas < cantMaxMonedasUsuario);
	
	while(loop==1){		
		if(turno==1){
			if(cantMinMonedasUsuario>cantidadMonedas){
				puntaje = 0;
				printf("La computadora gano!\n");
				printf("Tu puntaje es: %d",puntaje);
				limpiar(1);
				break;
			}
			else{
				if(ronda==1){
					printf("Comienza la partida el usuario.\n");
				}
				else if(ronda>1){
					printf("\nTurno del usuario.\n");	
				}	
				do{
					inputInt(eliminarMonedas, "Ingresa la cantidad de monedas a eliminar: ", true, 1);
				if(eliminarMonedas>cantMaxMonedasUsuario || eliminarMonedas<cantMinMonedasUsuario){
					printf("\n\nSe deben eliminar entre %d y %d monedas. Vuelva a intentarlo.\n\n",cantMinMonedasUsuario,cantMaxMonedasUsuario);
				}
				else if(eliminarMonedas>cantidadMonedas){
					printf("\n\nLa cantidad de monedas restante es menor a la cantidad de monedas que quiere eliminar. Vuelva a intentarlo.\n\n");
				}
				}while(eliminarMonedas>cantMaxMonedasUsuario || eliminarMonedas<cantMinMonedasUsuario || eliminarMonedas>cantidadMonedas);
				cantidadMonedas = cantidadMonedas - eliminarMonedas;
				printf("\nQuedan %d monedas.\n",cantidadMonedas);
				turno = 2;
				ronda++;
			}
		}
		
		if(turno==2){
			if(cantMinMonedasUsuario>cantidadMonedas){
				puntaje = 5;
				printf("Has ganado!\nTu puntaje es: %d",puntaje);
				limpiar(1);
				break;
			}
			else{
				if(ronda==1){
					printf("Comienza la partida la computadora.\n");
				}
				else if(ronda>1){
					printf("\nTurno de la computadora.\n");
				}
				do{
					eliminarMonedasPc = generarNumeroAleatorio_warcoin(cantMinMonedasUsuario,cantMaxMonedasUsuario);
				}while(eliminarMonedasPc>cantidadMonedas);
				cantidadMonedas = cantidadMonedas - eliminarMonedasPc;
				printf("La computadora elimino %d monedas de la pila.\n",eliminarMonedasPc);
				printf("\nQuedan %d monedas.\n",cantidadMonedas);
				turno = 1;
				ronda++;
			}
		}
	}
  return puntaje;
};

int comoJugar_warcoin(){
	int eleccion;
	system("cls");
	printf("\tComo jugar\n\n");
	printf("(1/3) WarCoin es un juego que consiste en turnarse para quitar monedas de una pila.\n");
	printf("El que vacia la pila de monedas es quien gana el juego.");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(2/3) Al comenzar el usuario indicara la cantidad minima y maxima de monedas que se pueden sacar.\n");
	printf("El programa elegira un numero entre 10 y 50 para la cantidad de monedas que habra en la pila.");
	
	limpiar(1);
	
	printf("\tComo jugar\n\n");
	printf("(3/3) El usuario obtendra 5 puntos por partida si logra vaciar la pila de monedas.\nSi no lo logra, los puntos iran para la computadora.");
	
	limpiar(1);
	
	inputInt(eleccion, "Estas listo para jugar?\n(Si=1/No=2): ", true, 1, 2);

	system("cls");
	return eleccion;
};

int guardarPuntaje_warcoin(int punt, int &sumatoriaPunt){
	sumatoriaPunt = sumatoriaPunt + punt;
	return sumatoriaPunt;
};

int generarNumeroAleatorio_warcoin(int min, int max){
	int numero;
	return numero = min + (rand()%(max-min));
};

void menu_warcoin(){
	system("cls");
	srand((unsigned)time(0));
	int opcion, opcion2, loop = 1;
	int listadoPuntajes[100];
	int puntaje = 0, sumatoriaPuntaje = 0;
	int partida = 0;
	
	Cadena opciones[] = {"Comenzar una partida", "Puntajes", "Como jugar"};
	char texto_menu[450];
	formatearMenu("Bienvenido a Warcoin", texto_menu, opciones, 3);
	
	while(loop == 1){
		inputInt(opcion, texto_menu, true, 1, 4);
		
		system("cls");
	
	switch(opcion){
		case 1:
			printf("Partida %d. Mucha suerte!\n",partida+1);
			limpiar(1);
			puntaje = comenzarPartida_warcoin();
			sumatoriaPuntaje = guardarPuntaje_warcoin(puntaje,sumatoriaPuntaje);
			listadoPuntajes[partida] = puntaje;
			partida++;
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
			opcion2 = comoJugar_warcoin();
			if(opcion2==1){
				printf("Partida %d. Mucha suerte!\n",partida+1);
				limpiar(1);
				puntaje = comenzarPartida_warcoin();
				sumatoriaPuntaje = guardarPuntaje_warcoin(puntaje,sumatoriaPuntaje);
				listadoPuntajes[partida] = puntaje;
				partida++;	
			}
			break;
		case 4:
			loop = 0;
			break;
	}
	}
};