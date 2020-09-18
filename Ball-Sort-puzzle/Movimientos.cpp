#include "pch.h"
#include "Movimientos.h"
Movimientos::Movimientos() {
	frente = NULL;
	fin = NULL;
	dato = NULL;
}

void Movimientos::push(Sprite bolita) {
	dato = new Nodo();
	dato->setBolita(bolita);
	dato->setNodoSiguiente(NULL);

	if (!frente) {
		frente = dato;
	}
	else {
		fin->setNodoSiguiente(dato);
	}

	fin = dato;
}
Sprite Movimientos::pop(){
	Nodo* aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->getNodoSiguiente();
	}
	Sprite bolita = aux->getBolita();
	delete aux;
	return bolita;
}
Sprite Movimientos::top() {
	return frente->getBolita();
}
