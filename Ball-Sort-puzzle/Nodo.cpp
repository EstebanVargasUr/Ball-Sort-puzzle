#include "pch.h"
#include "Nodo.h"

Nodo::Nodo(string _color, Nodo* arr = NULL, Nodo* aba = NULL) {
	color = _color;
	sig = arr;
	ant = aba;
}

void Nodo::setColor(string _color) {
	color = _color;
}
string Nodo::getColor() {
	return color;
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