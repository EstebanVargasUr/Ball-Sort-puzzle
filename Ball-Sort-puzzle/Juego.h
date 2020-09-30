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
	Tubo* tubos; //Guarda en un vector dinamico los tubos
	Image icon;
	Movimientos movimientos; //Guarda los movimientos para hacer el devolver movimiento

	int Escena=0;
	int lim=0; //Permite limitar algunas funciones para que no se ejecuten antes de tiempo
	int CantBolas=0;
	int CantTubos=0;
	int BolitaSeleccionada=0; //Muestra de que tubo se tomo la bola
	int BolaActual=0;
	int bolasTubo1=0; //Muestra la cantidad de bolas en el tubo1
	int bolasTubo2=0;//Muestra la cantidad de bolas en el tubo2
	int bolasTubo3 = 0, bolasTubo4 = 0, bolasTubo5 = 0, bolasTubo6=0;//Muestra la cantidad de bolas en los tubos
	int tubo=0; //En el tubo donde se encuentra la bola
	int y =0;
	int TubosCompletados=0; //Muestra la cantidad de tubos que ya se encuentran llenos de forma correcta
	int CantMov = 0; //Lleva la cuenta de la cantidad movimientos que ha retrocedido, para limitar a 5
	int NivelesGanados = 0;
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
	Texture BtnHomeTx;
	Texture BtnNiv1Tx, BtnNiv2Tx, BtnNiv3Tx, BtnNiv4Tx, BtnNiv5Tx;
	Texture BtnRepeticionTx, BtnGuardarTx;
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
	Sprite VictoriaSpt;
	Sprite BtnHomeSpt;
	Sprite BtnNiv1Spt, BtnNiv2Spt, BtnNiv3Spt, BtnNiv4Spt, BtnNiv5Spt;
	Sprite BtnRepeticionSpt, BtnGuardarSpt;

	Sprite* Bolitas; //Guarda los sprites de las bolas en un vector dinamico
	Sprite* TubosEnsayo; //Guarda los sprites de los tubos en un vector dinamico
	public:

	void CargarJuego();
	void Cargartexturas();
	void CargaEscenas();
	void ManejoBolasLvl1();
	void ManejoBolasLvl2();
	void ManejoBolasLvl3();
	void ManejoBolasLvl4();
	void ManejoBolasLvl5();
	int saberXY(int,int);
	void Victoria();
	void Movimientos();
};

