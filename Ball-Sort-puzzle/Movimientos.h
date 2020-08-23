#pragma once
#include "Nodo.h"
class Movimientos
{
	private:
		Nodo* frente;
		Nodo* fin;
		Nodo* dato;

	public:
		Movimientos();
		void push(string);
			
		string pop();
			
		string top();
};

