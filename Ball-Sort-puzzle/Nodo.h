#pragma once

using namespace sf;
class Nodo
{
private:

    Nodo* sig;
    Nodo* ant;
    int bolita;

    //Para la pila de regresar movimientos
    int tuboDestino;   //tubo a donde va la bola
    int tuboOrigen; //tubo de donde viene la bola
    

public:
    Nodo();
    Nodo(int, Nodo*, Nodo*);

    void setBolita(int);
    void setNodoSiguiente(Nodo*);
    void setNodoAnterior(Nodo*);
    void setTuboDestino(int);
    void setTuboOrigen(int);

    int getTuboOrigen();
    int getTuboDestino();
    int getBolita();
    Nodo* getNodoSiguiente();
    Nodo* getNodoAnterior();
};

