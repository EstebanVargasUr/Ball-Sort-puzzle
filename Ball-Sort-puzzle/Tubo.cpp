#include "pch.h"
#include "Tubo.h"

Tubo::Tubo() {
	tope = NULL;
	dato = NULL;
}
void Tubo::push(string color)
{
	dato = new Nodo();
	dato->getColor() = color;
	dato->setNodoSiguiente(NULL);
	if (tope == NULL)
	{
		dato->setNodoAnterior(NULL);
		tope = dato;
	}
	else
	{
		dato->setNodoAnterior(tope);
		tope->setNodoSiguiente(dato);
		tope = dato;
	}
}
string Tubo::pop()
{
	string color;
	color = tope->getColor();
	tope = tope->getNodoAnterior();
	tope->setNodoSiguiente(NULL);
	return color;
}

string Tubo::top()
{
	return tope->getColor();
}