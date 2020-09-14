#include "pch.h"
#include "Juego.h"
using namespace std;
using namespace sf;
Juego::Juego(int resolucion_x, int resolucion_y, string Titulo)
{
	
    RenderWindow Ventana1(sf::VideoMode(resolucion_x, resolucion_y), Titulo);
  
    Texture texture;
    if (!texture.loadFromFile("Circulo.png"))
    {
        // error...
    }
    texture.setSmooth(true);
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(500.f, 400.f));
    sprite.setColor(sf::Color(0, 255, 0));
    while (Ventana1.isOpen())
    {
        Event event;
        while (Ventana1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Ventana1.close();
        }

        Ventana1.clear();
        Ventana1.draw(sprite);
        Ventana1.display();
    }
}

