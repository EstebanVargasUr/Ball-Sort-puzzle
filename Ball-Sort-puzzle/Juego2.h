#pragma once
#include "SFML\Graphics.hpp"
#include "Tubo.h"
using namespace sf;
using namespace std;

class Juego2
{
private:
	
	Tubo* tubos;
	Image icon;

	int Escena = 0;
	int lim = 0;
	int CantBolas = 0;
	int CantTubos = 0;
	int BolitaSeleccionada = 0;

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
	Sprite* Bolitas;
	Sprite* TubosEnsayo;

public:

	void CargarJuego();
	void Cargartexturas();
	void CargaEscenas();
	void ManejoBolasLvl1();

};

