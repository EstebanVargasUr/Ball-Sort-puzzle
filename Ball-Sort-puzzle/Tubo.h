#pragma once
#include "Nodo.h"
#include "SFML\Graphics.hpp"
using namespace sf;

class Tubo
{
private:
	Nodo* tope;

public:
	Tubo();
	void push(int);
	int pop();
	int top();
};

