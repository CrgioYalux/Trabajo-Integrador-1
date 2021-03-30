#include "./utilidades_generales.h"
#include "./Adivinum/utilidades_adivinum.h"
#include "./Ahorcado/utilidades_ahorcado.h"
#include "./MayMen/utilidades_maymen.h"
#include "./WarCoin/utilidades_warcoin.h"
#include "./utilidades_menu.h"

int main(){
	system("cls");
	srand((unsigned)time(0));
	int elegir;
	int juegoAleatorio;
	int mainLoop = 1;
	
	cout << "\tBienvenido!" << endl;
	Cadena opciones[] = {"Warcoin", "MayMen", "Ahorcado", "Adivinum", "Aleatorio"};
	char texto_menu[650];
	formatearMenu("Estos son los juegos que puedes jugar.\nElije uno o selecciona \"Aleatorio\" para elegir uno al azar.", texto_menu, opciones, 5);

	while(mainLoop==1){
		inputInt(elegir, texto_menu, true, 1, 6);
		
		system("cls");
		
		switch(elegir){
			case 1:
				menu_warcoin();
				break;
			case 2:
				menu_maymen();
				break;
			case 3:
				menu_adivinum();
				break;
			case 4:
				menu_adivinum();
				break;
			case 5:
				seleccionarJuego(generarNumeroAleatorio(1,5));
				break;
			case 6:
				mainLoop = 0;
				break;
		}
	}
}
