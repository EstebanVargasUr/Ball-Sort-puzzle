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
	int bolasTubo1;
	int bolasTubo2;
	int bolasTubo3;
	int tubo;
	int y;

	//Texturas
	Texture	BtnJugarTx;
	Texture BtnAcercaDeTx;
	Texture BtnSalirTx;
	Texture UNATx;
	Texture BtnDevolverseTx;
	Texture BtnMenuTx;
	Texture BtnSigTx;
	Texture BtnReiniciarTx;
	Texture LogoInicialTx;
	Texture FondoMenuTx;
	Texture TuboEnsayoTx;
	Texture BolitaTx;
	//Sprites
	Sprite BtnJugarSpt;
	Sprite BtnAcercaDeSpt;
	Sprite BtnSalirSpt;
	Sprite BtnDevolverseSpt;
	Sprite BtnMenuSpt;
	Sprite BtnSigSpt;
	Sprite BtnReiniciarSpt;
	Sprite UNASpt;
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
	int saberXY(int);
};

