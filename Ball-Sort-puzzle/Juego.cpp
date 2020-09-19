#include "pch.h"
#include "Juego.h"
#include<time.h>
#include "Tubo.h"
using namespace std;
using namespace sf;


/*Event event;
RenderWindow Ventana1(VideoMode(1200, 700), "Menu inicial");
Tubo* Tubo1 = new Tubo();
Tubo* Tubo2 = new Tubo();
Tubo* Tubo3 = new Tubo();
Juego::Juego()
{
    Image icon;
    icon.loadFromFile("Circulo.png");
    Ventana1.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (Ventana1.isOpen())
    {
        ManejoComponentesV1();

        while (Ventana1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Ventana1.close();
        }

        //Se setean las escenas y se dibujan sus respectivos componentes
        if (Escena == 0)
        {
            Ventana1.clear();
            Ventana1.draw(FondoMenuSpt);
            Ventana1.draw(LogoInicialSpt);
            Ventana1.draw(BtnJugarSpt);
            Ventana1.display();
        }

        if (Escena == 1)
        {
            Ventana1.clear();
            Ventana1.draw(FondoMenuSpt);
            for (int i = 0; i < CantTubos; i++)
            {
                Ventana1.draw(TubosEnsayo[i]);
            }
        
            for (int i = 0; i <CantBolas; i++)
            {
                Ventana1.draw(Bolitas[i]);
            }

            Ventana1.display();
        }

       
        ManejoEventos(); //Se evaluan eventos
    }
}

void Juego::ManejoComponentesV1() //Se establecen texturas y sprites
{
    LogoInicialTx.loadFromFile("Logo3.png");
    LogoInicialTx.setSmooth(true);
    LogoInicialSpt.setTexture(LogoInicialTx);
    LogoInicialSpt.setPosition(Vector2f(475.f, 20.f));
    LogoInicialSpt.setScale(1.3, 1.3);
    
    FondoMenuTx.loadFromFile("fondo.jpg");
    FondoMenuSpt.setTexture(FondoMenuTx);
    FondoMenuSpt.setScale(1,1);

    BtnJugarTx.loadFromFile("BtnJugar2.png");
    BtnJugarSpt.setTexture(BtnJugarTx);
    BtnJugarSpt.setPosition(Vector2f(460.f, 290.f));
    BtnJugarSpt.setScale(0.8, 0.8);
   
    ManejoBolasLvl1();
}
int BolitaSeleccionada = 0;
void Juego::ManejoEventos()
{
    Vector2i posicion_mouse;
    posicion_mouse = Mouse::getPosition(Ventana1);

    //EVENTO DE PRESIONAR EL BOTON JUGAR -V1-
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && Escena == 0)
    {
        if (BtnJugarSpt.getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y))
        {
            Escena = 1;
            Ventana1.setTitle("NIVEL 1");
        }
    }

   
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && Escena == 1 && lim == 1)
    {
        if (Bolitas[4].getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y))
        {
            cout << "mueve";
            Bolitas[4].setPosition(300, 100);
            BolitaSeleccionada = 1;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && Escena == 1 && BolitaSeleccionada == 1 || BolitaSeleccionada == 3)
    {
        if (TubosEnsayo[1].getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y))
        {
            cout << "mueveTubo 2 | ";
            Bolitas[4].setPosition(470, 100);
            BolitaSeleccionada = 2;

        }    
    }
    
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && Escena == 1 && BolitaSeleccionada == 1|| BolitaSeleccionada == 2)
    {
        if (TubosEnsayo[2].getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y))
        {
            cout << "mueveTubo 3 | ";
            Bolitas[4].setPosition(640, 100);
            BolitaSeleccionada = 3;
        }
    }
}


void Juego::ManejoBolasLvl1()
{
    

    TuboEnsayoTx.loadFromFile("TuboEnsayoB.png");
    TuboEnsayoTx.setSmooth(true);
    TuboEnsayoSpt.setTexture(TuboEnsayoTx);
    TuboEnsayoSpt.setScale(0.35, 0.35);

    int num,num2;
    if (Escena == 1)
    {
        if (lim == 0)
        {
            lim = 1;

            BolitaTx.loadFromFile("Bola.png");
            BolitaTx.setSmooth(true);

            BolitaSpt1.setTexture(BolitaTx);
            BolitaSpt1.setScale(0.2, 0.2);

            Bolitas = new Sprite[8];
            TubosEnsayo = new Sprite[3];
            CantBolas = 8;
            CantTubos = 3;

            num2 = 0;

            for (int i = 0; i < 4; i++)
            {
                BolitaSpt1.setColor(Color::Red);
                Bolitas[i] = BolitaSpt1;
                num2 = num2 + 100;
            }

            num2 = 0;

            for (int i = 4; i < 8; i++)
            {
                BolitaSpt1.setColor(Color::Green);
                Bolitas[i] = BolitaSpt1;
                num2 = num2 + 100;
            }

            //Tubos Ensayo
            TuboEnsayoSpt.setPosition(305, 200);
            TubosEnsayo[0] = TuboEnsayoSpt;
            TuboEnsayoSpt.setPosition(475, 200);
            TubosEnsayo[1] = TuboEnsayoSpt;
            TuboEnsayoSpt.setPosition(645, 200);
            TubosEnsayo[2] = TuboEnsayoSpt;
            //T1
            Bolitas[4].setPosition(300, 200);//1T1
            Bolitas[0].setPosition(300, 250);//1T2
            Bolitas[2].setPosition(300, 300);//1T3
            Bolitas[6].setPosition(300, 350); //1T4
            Tubo1->push(Bolitas[6]);
            Tubo1->push(Bolitas[2]);
            Tubo1->push(Bolitas[0]);
            Tubo1->push(Bolitas[4]);
            //T2
            Bolitas[3].setPosition(470, 200);//2T1
            Bolitas[7].setPosition(470, 250);//2T2
            Bolitas[1].setPosition(470, 300);//2T3
            Bolitas[5].setPosition(470, 350);//2T4
            Tubo1->push(Bolitas[5]);
            Tubo1->push(Bolitas[1]);
            Tubo1->push(Bolitas[7]);
            Tubo1->push(Bolitas[3]);
        }
    }
}*/
