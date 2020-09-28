#pragma once
#include "SFML\Graphics.hpp"
#include "Tubo.h"
#include "Movimientos.h"
using namespace sf;
using namespace std;

class Juego
{
private:

	RenderWindow window;
	Event event;
	Tubo* tubos;
	Image icon;
	Movimientos movimientos;

	int Escena=0;
	int lim=0;
	int CantBolas=0;
	int CantTubos=0;
	int BolitaSeleccionada=0; //Muestra de que tubo se tomo la bola
	int BolaActual=0;
	int bolasTubo1=0;
	int bolasTubo2=0;
	int bolasTubo3=0;
	int tubo=0; //En el tubo donde se encuentra la bola
	int y =0;
	int TubosCompletados=0; //Muestra la cantidad de tubos que ya se encuentran llenos de forma correcta
	int CantMov = 0; //Lleva la cuenta de la cantidad movimientos que ha retrocedido, para limitar a 5

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
	Texture VictoriaTx;
	Texture BtnMovAntTx;
	//Sprites
	Sprite BtnJugarSpt;
	Sprite BtnAcercaDeSpt;
	Sprite BtnSalirSpt;
	Sprite BtnDevolverseSpt;
	Sprite BtnMenuSpt;
	Sprite BtnSigSpt;
	Sprite BtnReiniciarSpt;
	Sprite BtnMovAntSpt;
	Sprite UNASpt;
	Sprite LogoInicialSpt;
	Sprite FondoMenuSpt;
	Sprite TuboEnsayoSpt;
	Sprite BolitaSpt1;
	Sprite* Bolitas;
	Sprite* TubosEnsayo;
	Sprite VictoriaSpt;

	public:

	void CargarJuego();
	void Cargartexturas();
	void CargaEscenas();
	void ManejoBolasLvl1();
	int saberXY(int);
	void Victoria();
	void Movimientos();
};

