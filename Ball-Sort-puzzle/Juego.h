#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
using namespace std;

class  Juego
{
public:

	 Juego(int resolucion_x, int resolucion_y); //Contructor que va a inicializar la ventana
	 
	 void ManejoEventos();
	 void ManejoComponentes();
private:

	Event event;

	//Texturas
	Texture	BtnJugarTx;
	Texture LogoInicialTx;
	Texture FondoMenuTx;
	//Sprites
	Sprite BtnJugarSpt;
	Sprite LogoInicialSpt;
	Sprite FondoMenuSpt;
};
