#include "pch.h"
#include "Tubo.h"

Tubo::Tubo() {
	tope = NULL;
}
void Tubo::push(string color)
{
	Nodo* aux = new Nodo();
	aux->setColor(color);
	aux->setNodoSiguiente(tope);
	tope = aux;
}
string Tubo::pop()
{
	string color;
	color = tope->getColor();
	Nodo* aux = tope;
	tope = aux->getNodoSiguiente();
	delete aux;
	return color;
}

string Tubo::top()
{
	return tope->getColor();
}