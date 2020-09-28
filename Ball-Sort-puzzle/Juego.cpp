#include "pch.h"
#include "Juego.h"

void Juego::CargarJuego() {
    window.create(VideoMode(1200, 700), "Ball Sort Puzzle");
    icon.loadFromFile("Circulo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Cargartexturas();
    tubo = 0;
    bolasTubo1 = 4;
    bolasTubo2 = 4;
    bolasTubo3 = 0;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
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
                    if (Escena == 0) {
                        if (BtnJugarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 1;
                            window.setTitle("NIVEL 1");
                            Bolitas = new Sprite[8];
                            tubos = new Tubo[3];
                            for (int i = 0; i < 3; i++)
                                tubos[i].push(500);
                            TubosEnsayo = new Sprite[3];
                            CantBolas = 8;
                            CantTubos = 3;
                            ManejoBolasLvl1();
                        }
                        if (BtnAcercaDeSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 6;
                            window.setTitle("ACERCA DE");

                        }
                        if (BtnSalirSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            window.close();
                        }
                    }

                    if (Escena == 1) {
                        // Tubo #1
                        if (tubos[0].top() != 500 && BolitaSeleccionada != 2 && BolitaSeleccionada != 3) {
                            if (Bolitas[tubos[0].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1)
                            {
                                BolaActual = tubos[0].top();
                                Bolitas[tubos[0].top()].setPosition(410, 130);
                                BolitaSeleccionada = 1;
                                bolasTubo1 = bolasTubo1 - 1;
                            }
                            if (tubo == 3  && bolasTubo3!=4)
                            {
                                
                                if (bolasTubo3 != 0) {
                                    if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[2].top()].getColor()) {
                                        Bolitas[tubos[0].top()].setPosition(810, saberXY(bolasTubo3));
                                        tubos[2].push(tubos[0].pop());
                                        bolasTubo3 = bolasTubo3 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                   
                                    Bolitas[tubos[0].top()].setPosition(810, saberXY(bolasTubo3));
                                    tubos[2].push(tubos[0].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                                
                            }
                            if (tubo == 2 && bolasTubo2 != 4)
                            {
                                if (bolasTubo2 != 0) {
                                    
                                    if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[1].top()].getColor()) {
                                        Bolitas[tubos[0].top()].setPosition(610, saberXY(bolasTubo2));
                                        tubos[1].push(tubos[0].pop());
                                        bolasTubo2 = bolasTubo2 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                    Bolitas[tubos[0].top()].setPosition(610, saberXY(bolasTubo2));
                                    tubos[1].push(tubos[0].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;

                                }
                            }
                            if (tubo == 1&& bolasTubo1 !=4)
                            {
                                Bolitas[tubos[0].top()].setPosition(410, saberXY(bolasTubo1));
                                bolasTubo1 = bolasTubo1 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                        }
                       
                    //TUBO #2
                        if (tubos[1].top() != 500&&BolitaSeleccionada!=1&& BolitaSeleccionada != 3) {
                            if (Bolitas[tubos[1].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1)
                            {
                                
                                BolaActual = tubos[1].top();
                                Bolitas[tubos[1].top()].setPosition(610, 130);
                                BolitaSeleccionada = 2;
                                bolasTubo2 = bolasTubo2 - 1;

                            }
                            if (tubo == 3 && bolasTubo3 != 4)
                            {
                                if (bolasTubo3 != 0) {
                                    if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[2].top()].getColor()) {
                                        Bolitas[tubos[1].top()].setPosition(810, saberXY(bolasTubo3));
                                        tubos[2].push(tubos[1].pop());
                                        bolasTubo3 = bolasTubo3 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {

                                    Bolitas[tubos[1].top()].setPosition(810, saberXY(bolasTubo3));
                                    tubos[2].push(tubos[1].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }

                            }
                            if (tubo == 1 && bolasTubo1 != 4)
                            {
                                if (bolasTubo1 != 0) {
                                    if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[0].top()].getColor()) {
                                        Bolitas[tubos[1].top()].setPosition(410, saberXY(bolasTubo1));
                                        tubos[0].push(tubos[1].pop());
                                        bolasTubo1 = bolasTubo1 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                    Bolitas[tubos[1].top()].setPosition(410, saberXY(bolasTubo1));
                                    tubos[0].push(tubos[1].pop());
                                    bolasTubo1 = bolasTubo1 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;

                                }
                            }
                            if (tubo == 2 && bolasTubo2 != 4)
                            {
                                Bolitas[tubos[1].top()].setPosition(610, saberXY(bolasTubo2));
                                bolasTubo2 = bolasTubo2 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                        }
                        //Tubo #3
                        if (tubos[2].top() != 500&& BolitaSeleccionada != 1 && BolitaSeleccionada != 2) {
                            if (Bolitas[tubos[2].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1)
                            {
                                
                                BolaActual = tubos[2].top();
                                Bolitas[tubos[2].top()].setPosition(810, 130);
                                BolitaSeleccionada = 3;
                                bolasTubo3 = bolasTubo3 - 1;

                            }
                            if (tubo == 1 && bolasTubo1 != 4)
                            {

                                if (bolasTubo1 != 0) {
                                    if (Bolitas[tubos[2].top()].getColor() == Bolitas[tubos[0].top()].getColor()) {
                                        Bolitas[tubos[2].top()].setPosition(410, saberXY(bolasTubo1));
                                        tubos[0].push(tubos[2].pop());
                                        bolasTubo1 = bolasTubo1 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {

                                    Bolitas[tubos[2].top()].setPosition(410, saberXY(bolasTubo1));
                                    tubos[0].push(tubos[2].pop());
                                    bolasTubo1 = bolasTubo1 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }

                            }
                            if (tubo == 2 && bolasTubo2 != 4)
                            {
                                if (bolasTubo2 != 0) {

                                    if (Bolitas[tubos[2].top()].getColor() == Bolitas[tubos[1].top()].getColor()) {
                                        Bolitas[tubos[2].top()].setPosition(610, saberXY(bolasTubo2));
                                        tubos[1].push(tubos[2].pop());
                                        bolasTubo2 = bolasTubo2 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                    Bolitas[tubos[2].top()].setPosition(610, saberXY(bolasTubo2));
                                    tubos[1].push(tubos[2].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;

                                }
                            }
                            if (tubo == 3 && bolasTubo3 != 4)
                            {
                               
                                Bolitas[tubos[2].top()].setPosition(810, saberXY(bolasTubo3));
                                bolasTubo3 = bolasTubo3 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                        }
                    }
                    if (Escena == 6) {
                        if (BtnDevolverseSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            Escena = 0;
                        }
                    }
                   


                }
                break;

            case Event::MouseMoved:
                if (Escena == 1) {

                    if (TubosEnsayo[0].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada == 1 || BolitaSeleccionada == 2 || BolitaSeleccionada == 3) {
                            Bolitas[BolaActual].setPosition(410, 130);
                            tubo = 1;
                           
                        }

                    }

                    if (TubosEnsayo[1].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada == 1 || BolitaSeleccionada == 2 || BolitaSeleccionada == 3) {
                            Bolitas[BolaActual].setPosition(610, 130);
                            tubo = 2;
                            
                        }

                    }

                    if (TubosEnsayo[2].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada == 1 || BolitaSeleccionada == 2 || BolitaSeleccionada == 3) {
                            Bolitas[BolaActual].setPosition(810, 130);
                            tubo = 3;
                           
                        }

                    }
                }
                break;
                // we don't process other types of events
            default:
                break;
            }

        }
        Victoria();
        CargaEscenas();

    }
}

void Juego::Cargartexturas() {
    LogoInicialTx.loadFromFile("Logo3.png");
    LogoInicialTx.setSmooth(true);
    LogoInicialSpt.setTexture(LogoInicialTx);
    LogoInicialSpt.setPosition(Vector2f(475.f, 20.f));
    LogoInicialSpt.setScale(1.3f, 1.3f);

    FondoMenuTx.loadFromFile("fondo.jpg");
    FondoMenuSpt.setTexture(FondoMenuTx);
    FondoMenuSpt.setScale(1, 1);

    UNATx.loadFromFile("acercaDe.png");
    UNASpt.setTexture(UNATx);
    UNASpt.setPosition(Vector2f(150.f, 10.f));
    UNASpt.setScale(0.8f, 0.8f);

    BtnJugarTx.loadFromFile("btnJugar3.png");
    BtnJugarSpt.setTexture(BtnJugarTx);
    BtnJugarSpt.setPosition(Vector2f(500.f, 280.f));
    BtnJugarSpt.setScale(0.8f, 0.7f);

    BtnAcercaDeTx.loadFromFile("btnAcercaDe.png");
    BtnAcercaDeSpt.setTexture(BtnAcercaDeTx);
    BtnAcercaDeSpt.setPosition(Vector2f(500.f, 400.f));
    BtnAcercaDeSpt.setScale(0.8f, 0.7f);

    BtnSalirTx.loadFromFile("btnSalir.png");
    BtnSalirSpt.setTexture(BtnSalirTx);
    BtnSalirSpt.setPosition(Vector2f(500.f, 520.f));
    BtnSalirSpt.setScale(0.8f, 0.7f);

    BtnDevolverseTx.loadFromFile("btnDevolver.png");
    BtnDevolverseSpt.setTexture(BtnDevolverseTx);
    BtnDevolverseSpt.setPosition(Vector2f(50.f, 600.f));
    BtnDevolverseSpt.setScale(0.5f, 0.4f);

    BtnMenuTx.loadFromFile("menu.png");
    BtnMenuSpt.setTexture(BtnMenuTx);
    BtnMenuSpt.setPosition(Vector2f(50.f, 600.f));
    BtnMenuSpt.setScale(0.5f, 0.4f);

    BtnSigTx.loadFromFile("siguiente.png");
    BtnSigSpt.setTexture(BtnSigTx);
    BtnSigSpt.setPosition(Vector2f(50.f, 600.f));
    BtnSigSpt.setScale(0.5f, 0.4f);

    BtnReiniciarTx.loadFromFile("reiniciar.png");
    BtnReiniciarSpt.setTexture(BtnReiniciarTx);
    BtnReiniciarSpt.setPosition(Vector2f(50.f, 600.f));
    BtnReiniciarSpt.setScale(0.5f, 0.4f);

    TuboEnsayoTx.loadFromFile("TuboEnsayoB.png");
    TuboEnsayoTx.setSmooth(true);
    TuboEnsayoSpt.setTexture(TuboEnsayoTx);
    TuboEnsayoSpt.setScale(0.35f, 0.35f);

    BolitaTx.loadFromFile("Bola.png");
    BolitaTx.setSmooth(true);
    BolitaSpt1.setTexture(BolitaTx);
    BolitaSpt1.setScale(0.2f, 0.2f);
}

void Juego::CargaEscenas() {

    if (Escena == 0)
    {
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(LogoInicialSpt);
        window.draw(BtnJugarSpt);
        window.draw(BtnAcercaDeSpt);
        window.draw(BtnSalirSpt);
        window.display();
    }

    if (Escena == 1)
    {
        window.clear();
        window.draw(FondoMenuSpt);
        for (int i = 0; i < CantTubos; i++)
        {
            TubosEnsayo[i].setTexture(TuboEnsayoTx);
            TubosEnsayo[i].setScale(0.35f, 0.35f);
            window.draw(TubosEnsayo[i]);
        }

        for (int i = 0; i < CantBolas; i++)
        {
            window.draw(Bolitas[i]);
        }

        window.display();
    }
    if (Escena == 6){
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(UNASpt);
        window.draw(BtnDevolverseSpt);
        window.display();
    }
}

void Juego::ManejoBolasLvl1()
{

    int num2;
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
            
            tubos[0].push(6);
            tubos[0].push(2);
            tubos[0].push(0);
            tubos[0].push(4);
            //T2
            Bolitas[3].setPosition(610, 230);//2T1
            Bolitas[7].setPosition(610, 280);//2T2
            Bolitas[1].setPosition(610, 330);//2T3
            Bolitas[5].setPosition(610, 380);//2T4
           
           
            tubos[1].push(5);
            tubos[1].push(1);
            tubos[1].push(7);
            tubos[1].push(3);
        }
      
}
int Juego::saberXY(int x) {
    if (x == 0) {
        y = 380;
    }
    if (x == 1) {
        y = 330;
    }
    if (x == 2) {
        y = 280;
    }
    if (x == 3) {
        y = 230;
    }
    return y;
}

void Juego::Victoria()
{
    TubosCompletados = 0;//Permite que no se encicle y sume mas de lo necesario al llenar un tubo

    //Victoria para nivel 1
    if (Escena == 1)
    {
        
        if (bolasTubo1 == 4 || bolasTubo2 == 4 || bolasTubo3 == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                if (TubosEnsayo[i].getGlobalBounds().contains(Bolitas[4].getPosition()) && TubosEnsayo[i].getGlobalBounds().contains(Bolitas[5].getPosition()))
                {
                    if (TubosEnsayo[i].getGlobalBounds().contains(Bolitas[6].getPosition()) && TubosEnsayo[i].getGlobalBounds().contains(Bolitas[7].getPosition()))
                    {
                        TubosCompletados = TubosCompletados + 1;
                    }
                }
                if (TubosEnsayo[i].getGlobalBounds().contains(Bolitas[0].getPosition()) && TubosEnsayo[i].getGlobalBounds().contains(Bolitas[1].getPosition()))
                {
                    if (TubosEnsayo[i].getGlobalBounds().contains(Bolitas[2].getPosition()) && TubosEnsayo[i].getGlobalBounds().contains(Bolitas[3].getPosition()))
                    {
                        TubosCompletados = TubosCompletados + 1;
                    }
                }
            }  
        }   
    
        if (TubosCompletados == 2)
        {
            cout << "----->USTED ES UNA PERRA GANADORA<-----" << endl;
        }
    }
}
