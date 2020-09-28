#include "pch.h"
#include "Juego.h"

void Juego::CargarJuego() {
    window.create(VideoMode(1200, 700), "Ball Sort Puzzle");
    icon.loadFromFile("Circulo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Cargartexturas();
    
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
                            tubo = 0;
                            bolasTubo1 = 4;
                            bolasTubo2 = 4;
                            bolasTubo3 = 0;
                            movimientos.push(500,500,500);
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
                        if (tubos[0].top() != 500 && BolitaSeleccionada != 2 && BolitaSeleccionada != 3) //Sale arriba del 1
                        {
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
                                    if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[2].top()].getColor()) //Baja la bola al tubo 3
                                    {
                                        movimientos.push(tubos[0].top(), 1,3);
                                        Bolitas[tubos[0].top()].setPosition(810, saberXY(bolasTubo3));
                                        tubos[2].push(tubos[0].pop());
                                        bolasTubo3 = bolasTubo3 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;   
                                    }
                                }
                                else { //Si el tubo 3 esta vacio, baja la bola

                                    movimientos.push(tubos[0].top(), 1,3);
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
                                    
                                    if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[1].top()].getColor()) { //Baja la bola al tubo 2
                                        movimientos.push(tubos[0].top(), 1,2);
                                        
                                        Bolitas[tubos[0].top()].setPosition(610, saberXY(bolasTubo2));
                                        tubos[1].push(tubos[0].pop());
                                        bolasTubo2 = bolasTubo2 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else { //Si el tubo 2 esta vacio, baja la bola
                                    movimientos.push(tubos[0].top(), 1,2);
                                   
                                    Bolitas[tubos[0].top()].setPosition(610, saberXY(bolasTubo2));
                                    tubos[1].push(tubos[0].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;

                                }
                            }
                            if (tubo == 1 && bolasTubo1 !=4) //Para incertar en el mismo lugar
                            {
                                Bolitas[tubos[0].top()].setPosition(410, saberXY(bolasTubo1));
                                bolasTubo1 = bolasTubo1 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                        }
                       
                    //TUBO #2
                        if (tubos[1].top() != 500 && BolitaSeleccionada !=1 && BolitaSeleccionada != 3) {
                            if (Bolitas[tubos[1].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1)//Saca arriba del tubo
                            {
                                BolaActual = tubos[1].top();
                                Bolitas[tubos[1].top()].setPosition(610, 130);
                                BolitaSeleccionada = 2;
                                bolasTubo2 = bolasTubo2 - 1;
                        
                            }
                        
                            if (tubo == 3 && bolasTubo3 != 4)
                            {
                
                                if (bolasTubo3 != 0) { //Baja la bola al tubo 3
                                    if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[2].top()].getColor()) {
                                        movimientos.push(tubos[1].top(), 2, 3); 
                                        
                                        Bolitas[tubos[1].top()].setPosition(810, saberXY(bolasTubo3));
                                        tubos[2].push(tubos[1].pop());
                                        bolasTubo3 = bolasTubo3 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {//Si el tubo esta vacio
                                    movimientos.push(tubos[1].top(), 2,3); 
                                    Bolitas[tubos[1].top()].setPosition(810, saberXY(bolasTubo3));
                                    tubos[2].push(tubos[1].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }

                            }
                            if (tubo == 1 && bolasTubo1 != 4)
                            {
                                if (bolasTubo1 != 0) {//Baja al tubo1
                                    if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[0].top()].getColor()) {
                                        movimientos.push(tubos[1].top(), 2,1);
                                        Bolitas[tubos[1].top()].setPosition(410, saberXY(bolasTubo1));
                                        tubos[0].push(tubos[1].pop());
                                        bolasTubo1 = bolasTubo1 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                    movimientos.push(tubos[1].top(), 2,1);
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
                                        movimientos.push(tubos[2].top(), 3,1);
                                        Bolitas[tubos[2].top()].setPosition(410, saberXY(bolasTubo1));
                                        tubos[0].push(tubos[2].pop());
                                        bolasTubo1 = bolasTubo1 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                    movimientos.push(tubos[2].top(), 3,1);
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
                                        movimientos.push(tubos[2].top(), 3,2);
                                        Bolitas[tubos[2].top()].setPosition(610, saberXY(bolasTubo2));
                                        tubos[1].push(tubos[2].pop());
                                        bolasTubo2 = bolasTubo2 + 1;
                                        BolitaSeleccionada = 0;
                                        tubo = 0;
                                    }
                                }
                                else {
                                    movimientos.push(tubos[2].top(), 3,2);
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
                        
                        if (BtnMovAntSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Movimientos();
                        }
                    }
                    if (Escena == 6) {
                        if (BtnDevolverseSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            Escena = 0;
                        }
                    }

                    if (Escena == 10 || Escena == 1)
                    {
                        
                        if (BtnMenuSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 0;
                            Bolitas = new Sprite[8];
                            tubos = new Tubo[3];

                            for (int i = 0; i < 3; i++)
                                tubos[i].push(500);

                            TubosEnsayo = new Sprite[3];
                            CantBolas = 8;
                            CantTubos = 3;
                            tubo = 0;
                            bolasTubo1 = 4;
                            bolasTubo2 = 4;
                            bolasTubo3 = 0;
                            lim = 0;
                            CantMov = 0;
                        }

                        if (BtnReiniciarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
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
                            tubo = 0;
                            bolasTubo1 = 4;
                            bolasTubo2 = 4;
                            bolasTubo3 = 0;
                            lim = 0;
                            Cargartexturas();
                            CantMov = 0;
                            ManejoBolasLvl1();
                            CargaEscenas();
                        }

                        if (BtnSigSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {


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
    BtnMenuSpt.setPosition(Vector2f(1062, 360));
    BtnMenuSpt.setScale(0.4f, 0.4f);

    BtnSigTx.loadFromFile("siguiente.png");
    BtnSigSpt.setTexture(BtnSigTx);
    BtnSigSpt.setPosition(Vector2f(730.f, 315));
    BtnSigSpt.setScale(0.5f, 0.5f);

    BtnReiniciarTx.loadFromFile("reiniciar.png");
    BtnReiniciarSpt.setTexture(BtnReiniciarTx);
    BtnReiniciarSpt.setPosition(Vector2f(1050, 200));
    BtnReiniciarSpt.setScale(0.4f, 0.4f);

    TuboEnsayoTx.loadFromFile("TuboEnsayoB.png");
    TuboEnsayoTx.setSmooth(true);
    TuboEnsayoSpt.setTexture(TuboEnsayoTx);
    TuboEnsayoSpt.setScale(0.35f, 0.35f);

    BolitaTx.loadFromFile("Bola.png");
    BolitaTx.setSmooth(true);
    BolitaSpt1.setTexture(BolitaTx);
    BolitaSpt1.setScale(0.2f, 0.2f);

    VictoriaTx.loadFromFile("gane.png");
    VictoriaSpt.setTexture(VictoriaTx);
    VictoriaSpt.setPosition(Vector2f(410, 80));
    VictoriaSpt.setScale(1.3, 1.3);

    BtnMovAntTx.loadFromFile("btnMovAnt.png");
    BtnMovAntSpt.setTexture(BtnMovAntTx);
    BtnMovAntSpt.setPosition(Vector2f(1065, 480));
    BtnMovAntSpt.setScale(0.8,0.8);

    if (Escena == 10) 
    {
        BtnReiniciarSpt.setPosition(Vector2f(530.f, 300.f));
        BtnReiniciarSpt.setScale(0.5f, 0.5f);

        BtnMenuSpt.setPosition(Vector2f(370.f, 308.f));
        BtnMenuSpt.setScale(0.5f, 0.5f);

    }
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
        window.draw(BtnReiniciarSpt);
        window.draw(BtnMenuSpt);
        window.draw(BtnMovAntSpt);
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
    if (Escena == 6){ //Acerca de..
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(UNASpt);
        window.draw(BtnDevolverseSpt);
        window.display();
    }
    if (Escena == 10)//Pantalla de victoria
    {
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(VictoriaSpt);
        window.draw(BtnMenuSpt);
        window.draw(BtnReiniciarSpt);
        window.draw(BtnSigSpt);

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

void Juego::Movimientos()
{
    int posY = 0;
    if (CantMov < 5)
    {
        if (Escena == 1)
        {
            posY = 380;

            for (int i = 0; i < 4; i++)
            {
                if (bolasTubo1 == i && movimientos.top()->getTuboDestino() == 1)
                {
                    cout << "Aplica 1" << endl;
                    if (movimientos.top()->getTuboOrigen() == 2)
                        bolasTubo2 = bolasTubo2 - 1;
                    if (movimientos.top()->getTuboOrigen() == 3)
                        bolasTubo3 = bolasTubo3 - 1;

                    tubos[0].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop());
                    Bolitas[movimientos.pop()->getBolita()].setPosition(410, posY);
                    bolasTubo1 = bolasTubo1 + 1;
                    CantMov = CantMov + 1;
                    break;
                }

                if (bolasTubo2 == i && movimientos.top()->getTuboDestino() == 2)
                {
                    cout << "Aplica 2" << endl;
                    if (movimientos.top()->getTuboOrigen() == 1)
                        bolasTubo1 = bolasTubo1 - 1;
                    if (movimientos.top()->getTuboOrigen() == 3)
                        bolasTubo3 = bolasTubo3 - 1;

                    tubos[1].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop()); //Saca la bola del tubo donde esta y la inserta a donde estaba
                    Bolitas[movimientos.pop()->getBolita()].setPosition(610, posY);
                    bolasTubo2 = bolasTubo2 + 1;
                    CantMov = CantMov + 1;
                    break;
                }

                if (bolasTubo3 == i && movimientos.top()->getTuboDestino() == 3)
                {
                    cout << "Aplica 3" << endl;
                    if (movimientos.top()->getTuboOrigen() == 1)
                        bolasTubo1 = bolasTubo1 - 1;
                    if (movimientos.top()->getTuboOrigen() == 2)
                        bolasTubo2 = bolasTubo2 - 1;

                    tubos[2].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop());
                    Bolitas[movimientos.pop()->getBolita()].setPosition(810, posY);
                    bolasTubo3 = bolasTubo3 + 1;
                    CantMov = CantMov + 1;
                    break;
                }
                posY = posY - 50;
            }
        }
    }
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
            Escena = 10;
            Cargartexturas();
        }
    }
}
