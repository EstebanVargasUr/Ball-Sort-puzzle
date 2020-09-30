#pragma once
#include "Nodo.h"
using namespace sf;

class Repeticion
{
private:
	Nodo* tope;
	Nodo* ini;
	Nodo* dato;


public:

	Repeticion();

	void ReiniciaMov();

	void push(int);

	int pop();

	int top();
};
