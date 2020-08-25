#pragma once
#include "Nodo.h"
class Tubo
{
private:
	Nodo* tope;

public:
	Tubo();
	void push(string);
	string pop();
	string top();
};

