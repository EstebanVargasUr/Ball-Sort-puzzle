#pragma once
#include "Nodo.h"
using namespace sf;
class Movimientos
{
	private:
		Nodo* tope;
		Nodo* ini;
		Nodo* dato;


	public:

		Movimientos();

		void push(int,int, int);
			
		void ReiniciaMov();

		Nodo* pop();
			
		Nodo* top();
};

