#include "pch.h"
#include "Juego.h"
using namespace std;
using namespace sf;
Juego::Juego(int resolucion_x, int resolucion_y, string Titulo)
{
	
    RenderWindow Ventana1(sf::VideoMode(resolucion_x, resolucion_y), Titulo);
  
    Texture texture,texture2, BtnJugarTx;
    texture.loadFromFile("Logo3.png");
    texture2.loadFromFile("fondo.jpg");
    BtnJugarTx.loadFromFile("BtnJugar.png");

    Sprite sprite, sprite2, BtnJugarSpt;
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(475.f, 20.f));
    sprite.setScale(1.3, 1.3);
    
    texture.setSmooth(true);
    sprite2.setTexture(texture2);
    sprite2.setScale(0.7f,0.7f);

    BtnJugarSpt.setTexture(BtnJugarTx);
    BtnJugarSpt.setPosition(Vector2f(60.f, 100.f));
    BtnJugarSpt.setScale(0.6, 0.6);
    while (Ventana1.isOpen())
    {
        Event event;
        while (Ventana1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Ventana1.close();
        }

        Ventana1.clear();
        Ventana1.draw(sprite2);
        Ventana1.draw(sprite);
        Ventana1.draw(BtnJugarSpt);
        Ventana1.display();
    }
}

