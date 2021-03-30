int generarNumeroAleatorio(int min, int max);
void seleccionarJuego(int juego);

int generarNumeroAleatorio(int min, int max){
	int numero;
	return numero = min + (rand()%(max-min));
};

void seleccionarJuego(int juego){
	switch (juego){
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
	}
}