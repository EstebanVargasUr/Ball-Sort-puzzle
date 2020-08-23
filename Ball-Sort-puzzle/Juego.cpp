#include "pch.h"
#include "Juego.h"
using namespace std;
using namespace sf;
Juego::Juego(int resolucion_x, int resolucion_y, string Titulo)
{
	
    RenderWindow Ventana1(sf::VideoMode(resolucion_x, resolucion_y), Titulo);
   
    CircleShape shape(200.f);
    shape.setFillColor(Color::Green);

    while (Ventana1.isOpen())
    {
        Event event;
        while (Ventana1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Ventana1.close();
        }

        Ventana1.clear();
        Ventana1.draw(shape);
        Ventana1.display();
    }
}

