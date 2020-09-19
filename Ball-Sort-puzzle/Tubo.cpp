#include "pch.h"
#include "Tubo.h"

Tubo::Tubo() {
	tope = NULL;
}
void Tubo::push(int bolita)
{
	Nodo* aux = new Nodo();
	aux->setBolita(bolita);
	aux->setNodoSiguiente(tope);
	tope = aux;
}
int Tubo::pop()
{
	int bolita;
	bolita = tope->getBolita();
	Nodo* aux = tope;
	tope = aux->getNodoSiguiente();
	delete aux;
	return bolita;
}

int Tubo::top()
{
	return tope->getBolita();
}