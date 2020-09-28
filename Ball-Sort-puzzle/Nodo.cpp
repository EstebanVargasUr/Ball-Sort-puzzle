#include "pch.h"
#include "Nodo.h"

Nodo::Nodo() {
	bolita = NULL;
	sig = NULL;
	ant = NULL;
}

Nodo::Nodo(int _bolita, Nodo* arr = NULL, Nodo* aba = NULL) {
	bolita = _bolita;
	sig = arr;
	ant = aba;
}

void Nodo::setBolita(int _bolita) {
	bolita = _bolita;
}
int Nodo::getBolita() {
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
void Nodo::setTuboDestino(int _tubo) {
	tuboDestino = _tubo;
}
int Nodo::getTuboDestino()
{
	return tuboDestino;
}
void Nodo::setTuboOrigen(int _tuboV)
{
	tuboOrigen = _tuboV;
}
int Nodo::getTuboOrigen()
{
	return tuboOrigen;
}