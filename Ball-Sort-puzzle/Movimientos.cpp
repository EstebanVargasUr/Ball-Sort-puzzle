#include "pch.h"
#include "Movimientos.h"
Movimientos::Movimientos() {
	frente = NULL;
	fin = NULL;
	dato = NULL;
}

void Movimientos::push(string color) {
	
	dato->setColor(color);
	dato->setNodoSiguiente(NULL);

	if (!frente) {
		frente = dato;
	}
	else {
		fin->setNodoSiguiente(dato);
	}

	fin = dato;
}
string Movimientos::pop(){
	Nodo* aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->getNodoSiguiente();
	}
	string color = aux->getColor();
	delete aux;
	return color;
}
string Movimientos::top() {
	return frente->getColor();
}
