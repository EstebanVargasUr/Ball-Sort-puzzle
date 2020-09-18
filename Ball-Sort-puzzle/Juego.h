#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
using namespace std;

class  Juego
{
public:

	 Juego();
	 
	 void ManejoEventos();
	 void ManejoComponentesV1();
	 void ManejoBolasLvl1();

private:

	int CantBolas = 0;
	int CantTubos = 0;
	Sprite* Bolitas = NULL;
	Sprite* TubosEnsayo = NULL;
	//Texturas
	Texture	BtnJugarTx;
	Texture LogoInicialTx;
	Texture FondoMenuTx;
	Texture TuboEnsayoTx;
	Texture BolitaTx;
	//Sprites
	Sprite BtnJugarSpt;
	Sprite LogoInicialSpt;
	Sprite FondoMenuSpt;
	Sprite TuboEnsayoSpt;
	Sprite BolitaSpt1;
};
