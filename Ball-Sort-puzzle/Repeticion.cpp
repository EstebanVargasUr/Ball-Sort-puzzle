#include "pch.h"
#include "Repeticion.h"

Repeticion ::Repeticion()
{
	tope = NULL;
	dato = NULL;
	ini= NULL;
}

//Metodo Push
void Repeticion::push(int n)
{
	dato = new Nodo();
	dato->setBolita(n);
	dato->setNodoSiguiente(NULL);

	if (tope == NULL)
	{
		dato->setNodoAnterior(NULL);
		tope = dato;
		ini= dato;
	}
	else
	{
		dato->setNodoAnterior(tope);
		tope->setNodoSiguiente(dato);
		tope = dato;
	}
}
//Metodo Pop
int Repeticion::pop()
{
	int num;
	num = ini->getBolita();

	ini = ini->getNodoSiguiente();
	ini->setNodoAnterior(NULL);
	return num;
}

//Metodo Top
int Repeticion::top()
{
	return ini->getBolita();
}