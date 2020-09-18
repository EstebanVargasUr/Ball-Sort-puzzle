#pragma once

using namespace sf;
class Nodo
{
private:
    Sprite bolita;
    Nodo *sig;
    Nodo *ant;

public:
    Nodo();
    Nodo(Sprite, Nodo*, Nodo*);

    void setBolita(Sprite);
    void setNodoSiguiente(Nodo*);
    void setNodoAnterior(Nodo*);

    Sprite getBolita();
    Nodo* getNodoSiguiente();
    Nodo* getNodoAnterior();
};

