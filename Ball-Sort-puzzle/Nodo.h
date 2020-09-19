#pragma once

using namespace sf;
class Nodo
{
private:
    int bolita;
    Nodo *sig;
    Nodo *ant;

public:
    Nodo();
    Nodo(int, Nodo*, Nodo*);

    void setBolita(int);
    void setNodoSiguiente(Nodo*);
    void setNodoAnterior(Nodo*);

    int getBolita();
    Nodo* getNodoSiguiente();
    Nodo* getNodoAnterior();
};

