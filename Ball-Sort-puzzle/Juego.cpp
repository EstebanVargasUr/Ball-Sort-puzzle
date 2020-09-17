#include "pch.h"
#include "Juego.h"
using namespace std;
using namespace sf;
Juego::Juego(int resolucion_x, int resolucion_y)
{
   RenderWindow Ventana1(VideoMode(resolucion_x, resolucion_y), "Menu inicial");
  
   ManejoComponentes();
    
    while (Ventana1.isOpen())
    {
       
        while (Ventana1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Ventana1.close();
        }

        Ventana1.clear();
       
        Ventana1.draw(FondoMenuSpt);
        Ventana1.draw(LogoInicialSpt);
        Ventana1.draw(BtnJugarSpt);
        Ventana1.display();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                Vector2i posicion_mouse;
                posicion_mouse = Mouse::getPosition(Ventana1);

                if (BtnJugarSpt.getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y))
                {
                    Ventana1.close();
                    cout << "CLICK!" << endl;
                    RenderWindow Ventana2(sf::VideoMode(resolucion_x, resolucion_y), "SELECTOR DE NIVELES");
                    while (Ventana2.isOpen())
                    {
                        while (Ventana2.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                                Ventana2.close();
                        }
                        Ventana2.draw(FondoMenuSpt);
                        Ventana2.display();
                    }

                }
            }
        }
    }
}

void Juego::ManejoComponentes()
{
    LogoInicialTx.loadFromFile("Logo3.png");
    LogoInicialSpt.setTexture(LogoInicialTx);
    LogoInicialSpt.setPosition(Vector2f(475.f, 20.f));
    LogoInicialSpt.setScale(1.3, 1.3);
    LogoInicialTx.setSmooth(true);

    FondoMenuTx.loadFromFile("fondo.jpg");
    FondoMenuSpt.setTexture(FondoMenuTx);
    FondoMenuSpt.setScale(0.7f, 0.7f);

    BtnJugarTx.loadFromFile("BtnJugar2.png");
    BtnJugarSpt.setTexture(BtnJugarTx);
    BtnJugarSpt.setPosition(Vector2f(460.f, 290));
    BtnJugarSpt.setScale(0.8, 0.8);
}

void Juego::ManejoEventos()
{
 

   

}
