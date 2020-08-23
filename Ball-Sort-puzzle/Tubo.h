#pragma once
#include "Nodo.h"
class Tubo
{
private:
	Nodo* tope;
	Nodo* dato;

public:
	Tubo();
	void push(string);
	string pop();
	string top();
};

