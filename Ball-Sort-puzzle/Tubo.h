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
	void push(Sprite);
	Sprite pop();
	Sprite top();
};

