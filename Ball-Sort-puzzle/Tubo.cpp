#include "pch.h"
#include "Tubo.h"

Tubo::Tubo() {
	tope = NULL;
}
void Tubo::push(Sprite bolita)
{
	Nodo* aux = new Nodo();
	aux->setBolita(bolita);
	aux->setNodoSiguiente(tope);
	tope = aux;
}
Sprite Tubo::pop()
{
	Sprite bolita;
	bolita = tope->getBolita();
	Nodo* aux = tope;
	tope = aux->getNodoSiguiente();
	delete aux;
	return bolita;
}

Sprite Tubo::top()
{
	return tope->getBolita();
}