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
		void push(int);
			
		int pop();
			
		int top();
};

