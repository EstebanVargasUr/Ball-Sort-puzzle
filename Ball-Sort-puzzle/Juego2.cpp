#include "pch.h"
#include "Juego2.h"

RenderWindow window(VideoMode(1200, 700), "Ball Sort Puzzle");
void Juego2::CargarJuego() {
  //  window.setSize(Vector2u(1240, 720));
  //  window.setTitle("Ball Sort Puzzle");
    icon.loadFromFile("Circulo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Cargartexturas();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            
            switch (event.type)
            {
                // window closed
            case Event::Closed:
                // "close requested" event: we close the window
                window.close();
                break;

                // key pressed
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (BtnJugarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && Escena == 0)
                    {
                        Escena = 1;
                        window.setTitle("NIVEL 1");
                        tubos = new Tubo[3];
                        Bolitas = new Sprite[8];
                        TubosEnsayo = new Sprite[3];
                        CantBolas = 8;
                        CantTubos = 3;
                    }

                    if (Bolitas[4].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        if (Escena == 1 && lim == 1) {
                            cout << "mueve";
                            Bolitas[4].setPosition(410, 130);
                            BolitaSeleccionada = 1;
                        }
                    }

                    if (TubosEnsayo[0].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && Escena == 1)
                    {
                        if (BolitaSeleccionada == 2 || BolitaSeleccionada == 3) {
                            cout << "mueveTubo 1 | ";
                            Bolitas[4].setPosition(410, 130);
                            BolitaSeleccionada = 1;
                        }

                    }

                    if (TubosEnsayo[1].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && Escena == 1)
                    {
                        if (BolitaSeleccionada == 1 || BolitaSeleccionada == 3) {
                            cout << "mueveTubo 2 | ";
                            Bolitas[4].setPosition(610, 130);
                            BolitaSeleccionada = 2;
                        }

                    }

                    if (TubosEnsayo[2].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && Escena == 1)
                    {
                        if (BolitaSeleccionada == 1 || BolitaSeleccionada == 2) {
                            cout << "mueveTubo 3 | ";
                            Bolitas[4].setPosition(810, 130);
                            BolitaSeleccionada = 3;
                        }
                        
                    }
                }
                break;

            case Event::MouseMoved:

                break;
                // we don't process other types of events
            default:
                break;
            }
            
        }
        ManejoBolasLvl1();
        CargaEscenas();

    }
}

void Juego2::Cargartexturas() {
    LogoInicialTx.loadFromFile("Logo3.png");
    LogoInicialTx.setSmooth(true);
    LogoInicialSpt.setTexture(LogoInicialTx);
    LogoInicialSpt.setPosition(Vector2f(475.f, 20.f));
    LogoInicialSpt.setScale(1.3, 1.3);

    FondoMenuTx.loadFromFile("fondo.jpg");
    FondoMenuSpt.setTexture(FondoMenuTx);
    FondoMenuSpt.setScale(1, 1);

    BtnJugarTx.loadFromFile("BtnJugar2.png");
    BtnJugarSpt.setTexture(BtnJugarTx);
    BtnJugarSpt.setPosition(Vector2f(460.f, 290.f));
    BtnJugarSpt.setScale(0.8, 0.8);

    TuboEnsayoTx.loadFromFile("TuboEnsayoB.png");
    TuboEnsayoTx.setSmooth(true);
    TuboEnsayoSpt.setTexture(TuboEnsayoTx);
    TuboEnsayoSpt.setScale(0.35, 0.35);

    BolitaTx.loadFromFile("Bola.png");
    BolitaTx.setSmooth(true);
    BolitaSpt1.setTexture(BolitaTx);
    BolitaSpt1.setScale(0.2, 0.2);
}

void Juego2::CargaEscenas() {

    if (Escena == 0)
    {
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(LogoInicialSpt);
        window.draw(BtnJugarSpt);
        window.display();
    }

    if (Escena == 1)
    {
        window.clear();
        window.draw(FondoMenuSpt);
        for (int i = 0; i < CantTubos; i++)
        {
            TubosEnsayo[i].setTexture(TuboEnsayoTx);
            TubosEnsayo[i].setScale(0.35, 0.35);
            window.draw(TubosEnsayo[i]);
        }

        for (int i = 0; i < CantBolas; i++)
        {
            window.draw(Bolitas[i]);
        }

        window.display();
    }
}

void Juego2::ManejoBolasLvl1()
{

    int num2;
    if (Escena == 1)
    {
        if (lim == 0)
        {
            lim = 1;

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
            TubosEnsayo[0].setPosition(400, 200);
            TubosEnsayo[1].setPosition(600, 200);
            TubosEnsayo[2].setPosition(800, 200);
            //T1
            Bolitas[4].setPosition(410, 230);//1T1
            Bolitas[0].setPosition(410, 280);//1T2
            Bolitas[2].setPosition(410, 330);//1T3
            Bolitas[6].setPosition(410, 380); //1T4
            tubos[0].push(Bolitas[6]);
            tubos[0].push(Bolitas[2]);
            tubos[0].push(Bolitas[0]);
            tubos[0].push(Bolitas[4]);
            //T2
            Bolitas[3].setPosition(610, 230);//2T1
            Bolitas[7].setPosition(610, 280);//2T2
            Bolitas[1].setPosition(610, 330);//2T3
            Bolitas[5].setPosition(610, 380);//2T4
            tubos[1].push(Bolitas[5]);
            tubos[1].push(Bolitas[1]);
            tubos[1].push(Bolitas[7]);
            tubos[1].push(Bolitas[3]);
        }
    }
}