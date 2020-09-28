#include "pch.h"
#include "Movimientos.h"
Movimientos::Movimientos() {
	tope = NULL;
	ini = NULL;
	dato = NULL;
}

void Movimientos::push(int bolita, int tuboDestino, int tuboOrigen) {

	dato = new Nodo();
	dato->setBolita(bolita);
	dato->setTuboDestino(tuboDestino);
	dato->setTuboOrigen(tuboOrigen);
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
Nodo* Movimientos::pop() {
	Nodo* aux;
	aux = tope;
	tope = tope->getNodoAnterior();
	tope->setNodoSiguiente(NULL);
	return aux;
}
Nodo* Movimientos::top() {
	return tope;
}

void Movimientos::ReiniciaMov()
{
	tope = NULL;
	ini = NULL;
}