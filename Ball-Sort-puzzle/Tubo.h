#pragma once
#include "Nodo.h"
class Tubo
{
private:
	Nodo* tope;
	Nodo* dato;

public:
	void push(string);
	void pop();
	void top();
};

