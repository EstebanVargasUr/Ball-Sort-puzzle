#pragma once
class Nodo
{
private:
    string color;
    Nodo *sig;
    Nodo *ant;

public:
    Nodo(string, Nodo*, Nodo*);

    void setColor(string);
    void setNodoSiguiente(Nodo*);
    void setNodoAnterior(Nodo*);

    string getColor();
    Nodo* getNodoSiguiente();
    Nodo* getNodoAnterior();
};

