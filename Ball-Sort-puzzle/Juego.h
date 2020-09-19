#pragma once
#include "SFML\Graphics.hpp"
#include "Tubo.h"
using namespace sf;
using namespace std;

class Juego
{
private:

	RenderWindow window;
	Event event;
	Tubo* tubos;
	Image icon;

	int Escena;
	int lim;
	int CantBolas;
	int CantTubos;
	int BolitaSeleccionada;
	int BolaActual;

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

