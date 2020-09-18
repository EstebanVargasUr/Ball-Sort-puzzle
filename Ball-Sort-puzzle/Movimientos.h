#pragma once
#include "Nodo.h"
using namespace sf;
class Movimientos
{
	private:
		Nodo* frente;
		Nodo* fin;
		Nodo* dato;

	public:
		Movimientos();
		void push(Sprite);
			
		Sprite pop();
			
		Sprite top();
};

