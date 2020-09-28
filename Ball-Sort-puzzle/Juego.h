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

	int Escena=0;
	int lim=0;
	int CantBolas=0;
	int CantTubos=0;
	int BolitaSeleccionada=0;
	int BolaActual=0;
	int bolasTubo1=0;
	int bolasTubo2=0;
	int bolasTubo3=0;
	int tubo=0;
	int y =0;
	int TubosCompletados=0; //Muestra la cantidad de tubos que ya se encuentran llenos de forma correcta

	//Texturas
	Texture	BtnJugarTx;
	Texture BtnAcercaDeTx;
	Texture BtnSalirTx;
	Texture UNATx;
	Texture LogoInicialTx;
	Texture FondoMenuTx;
	Texture TuboEnsayoTx;
	Texture BolitaTx;
	//Sprites
	Sprite BtnJugarSpt;
	Sprite BtnAcercaDeSpt;
	Sprite BtnSalirSpt;
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
	void Victoria();
};

