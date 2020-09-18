#include "pch.h"
#include "Nodo.h"

Nodo::Nodo() {
	
	sig = NULL;
	ant = NULL;
}

Nodo::Nodo(Sprite _bolita, Nodo* arr = NULL, Nodo* aba = NULL) {
	bolita = _bolita;
	sig = arr;
	ant = aba;
}

void Nodo::setBolita(Sprite _bolita) {
	bolita = _bolita;
}
Sprite Nodo::getBolita() {
	return bolita;
}
void Nodo::setNodoSiguiente(Nodo* arr) {
	sig = arr;
}
Nodo* Nodo::getNodoSiguiente() {
	return sig;
}
void Nodo::setNodoAnterior(Nodo* aba) {
	ant = aba;
}
Nodo* Nodo::getNodoAnterior() {
	return ant;
}