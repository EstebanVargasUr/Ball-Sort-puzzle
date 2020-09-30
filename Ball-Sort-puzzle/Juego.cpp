#include "pch.h"
#include "Juego.h"

void Juego::CargarJuego() {
    window.create(VideoMode(1200, 700), "Ball Sort Puzzle");
    icon.loadFromFile("Circulo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Cargartexturas();
    
    while (window.isOpen())
    {
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
                            Escena = 11;
                           
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

                    if (Escena == 1 || Escena == 2 || Escena == 3|| Escena==4 || Escena == 5)
                    {
              
                        // Tubo #1
                        if (tubos[0].top() != 500 && BolitaSeleccionada != 2 && BolitaSeleccionada != 3 && BolitaSeleccionada != 4 && BolitaSeleccionada != 5) //Sale arriba del 1
                        {
                            if (Bolitas[tubos[0].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1 && BolitaSeleccionada == 0)
                            {
                                BolaActual = tubos[0].top();
                                BolitaSeleccionada = 1;
                                bolasTubo1 = bolasTubo1 - 1;

                                if (Escena == 1)
                                Bolitas[tubos[0].top()].setPosition(410, 130);
                                
                                if (Escena == 2 || Escena == 3||Escena==4 || Escena == 5)
                                Bolitas[tubos[0].top()].setPosition(110, 130);
                            }
                            if (tubo == 3  && bolasTubo3 != 4)
                            {
                                if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[2].top()].getColor() || bolasTubo3 == 0) //Baja la bola al tubo 3
                                {
                                    movimientos.push(tubos[0].top(), 1, 3);
                                    if(Escena == 1)
                                    Bolitas[tubos[0].top()].setPosition(810, saberXY(bolasTubo3, Escena));
                                    
                                    if(Escena == 2 || Escena == 3||Escena==4 || Escena == 5)
                                    Bolitas[tubos[0].top()].setPosition(510, saberXY(bolasTubo3, Escena));

                                    tubos[2].push(tubos[0].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 2 && bolasTubo2 != 4)
                            {
                                if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[1].top()].getColor() || bolasTubo2 == 0) { //Baja la bola al tubo 2
                                    
                                    movimientos.push(tubos[0].top(), 1, 2);

                                    if(Escena == 1)
                                    Bolitas[tubos[0].top()].setPosition(610, saberXY(bolasTubo2, Escena));

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[0].top()].setPosition(310, saberXY(bolasTubo2, Escena));

                                    tubos[1].push(tubos[0].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 1 && bolasTubo1 !=4) //Para incertar en el mismo lugar
                            {
                                if(Escena == 1)
                                Bolitas[tubos[0].top()].setPosition(410, saberXY(bolasTubo1, Escena));

                                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[0].top()].setPosition(110, saberXY(bolasTubo1, Escena));

                                bolasTubo1 = bolasTubo1 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }

                            if (tubo == 4 && Escena == 2 || tubo == 4 && Escena == 3 || tubo == 4 && Escena == 4 || tubo == 4 && Escena == 5)
                            {
                             
                                if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[3].top()].getColor() || bolasTubo4 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[0].top(), 1, 4);

                                    if (Escena == 2 || Escena == 3|| Escena == 4 || Escena == 5)
                                    Bolitas[tubos[0].top()].setPosition(710, saberXY(bolasTubo4, Escena));

                                    tubos[3].push(tubos[0].pop());
                                    bolasTubo4 = bolasTubo4 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 5 && Escena == 2 || tubo == 5 && Escena == 3 || tubo == 5 && Escena == 4 || tubo == 5 && Escena == 5)
                            {
                                if (Bolitas[tubos[0].top()].getColor() == Bolitas[tubos[4].top()].getColor() || bolasTubo5 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[0].top(), 1, 5);

                                    if (Escena == 2 || Escena == 3|| Escena==4 || Escena == 5)
                                    Bolitas[tubos[0].top()].setPosition(910, saberXY(bolasTubo5, Escena));

                                    tubos[4].push(tubos[0].pop());
                                    bolasTubo5 = bolasTubo5 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                        }
                       
                    //TUBO #2
                        if (tubos[1].top() != 500 && BolitaSeleccionada !=1 && BolitaSeleccionada != 3 && BolitaSeleccionada != 4 && BolitaSeleccionada != 5) 
                        {
                            if (Bolitas[tubos[1].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1 && BolitaSeleccionada == 0)//Saca arriba del tubo
                            {
                                BolaActual = tubos[1].top();
                               
                                BolitaSeleccionada = 2;
                                bolasTubo2 = bolasTubo2 - 1;

                                if (Escena == 1)
                                Bolitas[tubos[1].top()].setPosition(610, 130);

                                if (Escena == 2 || Escena == 3 || Escena == 4||Escena == 5)
                                Bolitas[tubos[1].top()].setPosition(310, 130);
                        
                            }
                        
                            if (tubo == 3 && bolasTubo3 != 4)
                            {
                                if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[2].top()].getColor() || bolasTubo3 == 0) {//baja al tubo3
                                    movimientos.push(tubos[1].top(), 2, 3);

                                    if(Escena == 1)
                                    Bolitas[tubos[1].top()].setPosition(810, saberXY(bolasTubo3, Escena));

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[1].top()].setPosition(510, saberXY(bolasTubo3, Escena));

                                    tubos[2].push(tubos[1].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 1 && bolasTubo1 != 4)
                            {
                                //Baja al tubo1
                                if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[0].top()].getColor() || bolasTubo1 == 0) {
                                        
                                    movimientos.push(tubos[1].top(), 2,1);

                                    if(Escena == 1)
                                    Bolitas[tubos[1].top()].setPosition(410, saberXY(bolasTubo1, Escena));

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[1].top()].setPosition(110, saberXY(bolasTubo1, Escena));

                                    tubos[0].push(tubos[1].pop());
                                    bolasTubo1 = bolasTubo1 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 2 && bolasTubo2 != 4) //Vuelve a insertar al T2
                            {   
                                if(Escena == 1)
                                Bolitas[tubos[1].top()].setPosition(610, saberXY(bolasTubo2, Escena));

                                if(Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[1].top()].setPosition(310, saberXY(bolasTubo2, Escena));
                                bolasTubo2 = bolasTubo2 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                            if (tubo == 4 && bolasTubo4 != 4)
                            {
                                //Baja al tubo4
                                if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[3].top()].getColor() || bolasTubo4 == 0) {

                                    movimientos.push(tubos[1].top(), 2, 4);

                                    if (Escena == 1)
                                    Bolitas[tubos[1].top()].setPosition(410, saberXY(bolasTubo4, Escena));

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[1].top()].setPosition(710, saberXY(bolasTubo4, Escena));

                                    tubos[3].push(tubos[1].pop());
                                    bolasTubo4 = bolasTubo4 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 5 && bolasTubo5 != 4)
                            {
                                //Baja al tubo5
                                if (Bolitas[tubos[1].top()].getColor() == Bolitas[tubos[4].top()].getColor() || bolasTubo5 == 0) 
                                {
                                    movimientos.push(tubos[1].top(), 2, 5);

                                    if (Escena == 1)
                                    Bolitas[tubos[1].top()].setPosition(410, saberXY(bolasTubo5, Escena));

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[1].top()].setPosition(910, saberXY(bolasTubo5, Escena));

                                    tubos[4].push(tubos[1].pop());
                                    bolasTubo5 = bolasTubo5 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                        }
                        //Tubo #3
                        if (tubos[2].top() != 500 && BolitaSeleccionada != 1 && BolitaSeleccionada != 2 && BolitaSeleccionada != 4 && BolitaSeleccionada != 5) 
                        {
                            if (Bolitas[tubos[2].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1 && BolitaSeleccionada == 0)
                            {
                                BolaActual = tubos[2].top();
                                BolitaSeleccionada = 3;
                                bolasTubo3 = bolasTubo3 - 1;
                                if(Escena == 1)
                                Bolitas[tubos[2].top()].setPosition(810, 130);
                                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[2].top()].setPosition(510, 130);
                            }
                            if (tubo == 1 && bolasTubo1 != 4)
                            {
                                if (Bolitas[tubos[2].top()].getColor() == Bolitas[tubos[0].top()].getColor() || bolasTubo1 == 0) {
                                    
                                    movimientos.push(tubos[2].top(), 3,1);
                                    
                                    if(Escena == 1)
                                    Bolitas[tubos[2].top()].setPosition(410, saberXY(bolasTubo1, Escena));

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[2].top()].setPosition(110, saberXY(bolasTubo1, Escena));

                                    tubos[0].push(tubos[2].pop());
                                    bolasTubo1 = bolasTubo1 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 2 && bolasTubo2 != 4)
                            {
                                if (Bolitas[tubos[2].top()].getColor() == Bolitas[tubos[1].top()].getColor() || bolasTubo2 == 0) {
                                    
                                    movimientos.push(tubos[2].top(), 3,2);
                                    
                                    if(Escena == 1)
                                    Bolitas[tubos[2].top()].setPosition(610, saberXY(bolasTubo2, Escena));

                                    if(Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[2].top()].setPosition(310, saberXY(bolasTubo2, Escena));

                                    tubos[1].push(tubos[2].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 3 && bolasTubo3 != 4)
                            {
                                if(Escena == 1)
                                Bolitas[tubos[2].top()].setPosition(810, saberXY(bolasTubo3, Escena));

                                if(Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[2].top()].setPosition(510, saberXY(bolasTubo3, Escena));
                                bolasTubo3 = bolasTubo3 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                            if (tubo == 4 && bolasTubo4 != 4)
                            {
                                if (Bolitas[tubos[2].top()].getColor() == Bolitas[tubos[3].top()].getColor() || bolasTubo4 == 0) {

                                    movimientos.push(tubos[2].top(), 3, 4);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                        Bolitas[tubos[2].top()].setPosition(710, saberXY(bolasTubo4, Escena));

                                    tubos[3].push(tubos[2].pop());
                                    bolasTubo4 = bolasTubo4 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 5 && bolasTubo5 != 4)
                            {
                                if (Bolitas[tubos[2].top()].getColor() == Bolitas[tubos[4].top()].getColor() || bolasTubo5 == 0) {

                                    movimientos.push(tubos[2].top(), 3, 5);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[2].top()].setPosition(910, saberXY(bolasTubo5, Escena));

                                    tubos[4].push(tubos[2].pop());
                                    bolasTubo5 = bolasTubo5 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                        }
                        if (BtnMovAntSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Movimientos();
                        }
                    }
                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                    {
                        // Tubo #4
                        if (tubos[3].top() != 500 && BolitaSeleccionada != 2 && BolitaSeleccionada != 3 && BolitaSeleccionada != 1 && BolitaSeleccionada != 5) //Sale arriba del 4
                        {
                            if (Bolitas[tubos[3].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1 && BolitaSeleccionada == 0)
                            {
                                BolaActual = tubos[3].top();
                                BolitaSeleccionada = 4;
                                bolasTubo4 = bolasTubo4 - 1;

                                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[3].top()].setPosition(710, 130);
                            }
                            if (tubo == 3 && bolasTubo3 != 4) //Inserta en T3
                            {
                                if (Bolitas[tubos[3].top()].getColor() == Bolitas[tubos[2].top()].getColor() || bolasTubo3 == 0) //Baja la bola al tubo 3
                                {
                                    movimientos.push(tubos[3].top(), 4, 3);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[3].top()].setPosition(510, saberXY(bolasTubo3, Escena));
                                    tubos[2].push(tubos[3].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 2 && bolasTubo2 != 4)//Inserta en T2
                            {
                                if (Bolitas[tubos[3].top()].getColor() == Bolitas[tubos[1].top()].getColor() || bolasTubo2 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[3].top(), 4, 2);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[3].top()].setPosition(310, saberXY(bolasTubo2, Escena));

                                    tubos[1].push(tubos[3].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 1 && bolasTubo1 != 4)//Inserta en T1
                            {
                                if (Bolitas[tubos[3].top()].getColor() == Bolitas[tubos[0].top()].getColor() || bolasTubo1 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[3].top(), 4, 1);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                        Bolitas[tubos[3].top()].setPosition(110, saberXY(bolasTubo1, Escena));

                                    tubos[0].push(tubos[3].pop());
                                    bolasTubo1 = bolasTubo1 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 5 && bolasTubo5 != 4)//Inserta en T5
                            {
                                if (Bolitas[tubos[3].top()].getColor() == Bolitas[tubos[4].top()].getColor() || bolasTubo5 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[3].top(), 4, 5);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                    Bolitas[tubos[3].top()].setPosition(910, saberXY(bolasTubo5, Escena));

                                    tubos[4].push(tubos[3].pop());
                                    bolasTubo5 = bolasTubo5 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 4 && bolasTubo4 != 4) //Para incertar en el mismo lugar
                            {
                                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[3].top()].setPosition(710, saberXY(bolasTubo4, Escena));

                                bolasTubo4 = bolasTubo4 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            } 
                        }
                        // Tubo #5
                        if (tubos[4].top() != 500 && BolitaSeleccionada != 2 && BolitaSeleccionada != 3 && BolitaSeleccionada != 1 && BolitaSeleccionada != 4) //Sale arriba del 5
                        {
                            if (Bolitas[tubos[4].top()].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && lim == 1 && BolitaSeleccionada == 0)
                            {
                                BolaActual = tubos[4].top();
                                BolitaSeleccionada = 5;
                                bolasTubo5 = bolasTubo5 - 1;

                                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[4].top()].setPosition(910, 130);
                            }
                            if (tubo == 3 && bolasTubo3 != 4) //Inserta en T3
                            {
                                if (Bolitas[tubos[4].top()].getColor() == Bolitas[tubos[2].top()].getColor() || bolasTubo3 == 0) //Baja la bola al tubo 3
                                {
                                    movimientos.push(tubos[4].top(), 5, 3);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                        Bolitas[tubos[4].top()].setPosition(510, saberXY(bolasTubo3, Escena));

                                    tubos[2].push(tubos[4].pop());
                                    bolasTubo3 = bolasTubo3 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 2 && bolasTubo2 != 4)//Inserta en T2
                            {
                                if (Bolitas[tubos[4].top()].getColor() == Bolitas[tubos[1].top()].getColor() || bolasTubo2 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[4].top(), 5, 2);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                        Bolitas[tubos[4].top()].setPosition(310, saberXY(bolasTubo2, Escena));

                                    tubos[1].push(tubos[4].pop());
                                    bolasTubo2 = bolasTubo2 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 1 && bolasTubo1 != 4)//Inserta en T1
                            {
                                if (Bolitas[tubos[4].top()].getColor() == Bolitas[tubos[0].top()].getColor() || bolasTubo1 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[4].top(), 5, 1);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                        Bolitas[tubos[4].top()].setPosition(110, saberXY(bolasTubo1, Escena));

                                    tubos[0].push(tubos[4].pop());
                                    bolasTubo1 = bolasTubo1 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 4 && bolasTubo4 != 4)//Inserta en T4
                            {
                                if (Bolitas[tubos[4].top()].getColor() == Bolitas[tubos[3].top()].getColor() || bolasTubo4 == 0) { //Baja la bola al tubo 2

                                    movimientos.push(tubos[4].top(), 5, 4);

                                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                        Bolitas[tubos[4].top()].setPosition(710, saberXY(bolasTubo4, Escena));

                                    tubos[3].push(tubos[4].pop());
                                    bolasTubo4 = bolasTubo4 + 1;
                                    BolitaSeleccionada = 0;
                                    tubo = 0;
                                }
                            }
                            if (tubo == 5 && bolasTubo5 != 4) //Para insertar en el mismo lugar
                            {
                                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                                Bolitas[tubos[4].top()].setPosition(910, saberXY(bolasTubo5, Escena));

                                bolasTubo5 = bolasTubo5 + 1;
                                BolitaSeleccionada = 0;
                                tubo = 0;
                            }
                        }
                    }
                    if (Escena == 6 || Escena == 11) 
                    {
                        if (BtnDevolverseSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            Escena = 0;
                        }
                    }
                    if (Escena == 11)
                    {
                        if (BtnNiv1Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            Escena = 1;
                            window.setTitle("NIVEL 1");
                            Bolitas = new Sprite[8];
                            tubos = new Tubo[3];
                            TubosEnsayo = new Sprite[3];

                            for (int i = 0; i < 3; i++)
                            tubos[i].push(500);

                            CantBolas = 8; CantTubos = 3; tubo = 0; lim = 0;
                            bolasTubo1 = 4; bolasTubo2 = 4; bolasTubo3 = 0;
                            CantMov = 0;  NivelesGanados = 0;

                            Cargartexturas();
                            ManejoBolasLvl1();
                            CargaEscenas();
                        }

                        if (BtnNiv2Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 2;
                            window.setTitle("NIVEL 2");
                            Bolitas = new Sprite[12];
                            tubos = new Tubo[5];
                            TubosEnsayo = new Sprite[5];

                            for (int i = 0; i < 5; i++)
                                tubos[i].push(500);

                            CantTubos = 5;  CantBolas = 12;
                            tubo = 0;   lim = 0; CantMov = 0;

                            bolasTubo1 = 4; bolasTubo2 = 4;
                            bolasTubo3 = 0; bolasTubo4 = 4; bolasTubo5 = 0;
                            NivelesGanados = 0;

                            movimientos.ReiniciaMov();
                            movimientos.push(500, 500, 500);

                            Cargartexturas();
                            ManejoBolasLvl2();
                            CargaEscenas();
                        }

                        if (BtnNiv3Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 3;
                            window.setTitle("NIVEL 3");
                            Bolitas = new Sprite[12];
                            tubos = new Tubo[5];
                            TubosEnsayo = new Sprite[5];

                            for (int i = 0; i < 5; i++)
                                tubos[i].push(500);

                            CantTubos = 5;  CantBolas = 12;
                            tubo = 0;   lim = 0; CantMov = 0;

                            bolasTubo1 = 4; bolasTubo2 = 2;
                            bolasTubo3 = 3; bolasTubo4 = 0; bolasTubo5 = 3;
                            NivelesGanados = 0;

                            movimientos.ReiniciaMov();
                            movimientos.push(500, 500, 500);

                            Cargartexturas();
                            ManejoBolasLvl3();
                            CargaEscenas();
                        }

                        if (BtnNiv4Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 4;
                            window.setTitle("NIVEL 4");
                            Bolitas = new Sprite[16];
                            tubos = new Tubo[5];
                            TubosEnsayo = new Sprite[5];

                            for (int i = 0; i < 5; i++)
                                tubos[i].push(500);

                            CantTubos = 5;  CantBolas = 16;
                            tubo = 0;   lim = 0; CantMov = 0;

                            bolasTubo1 = 4; bolasTubo2 = 4;
                            bolasTubo3 = 4; bolasTubo4 = 3; bolasTubo5 = 1;
                            NivelesGanados = 0;

                            movimientos.ReiniciaMov();
                            movimientos.push(500, 500, 500);

                            Cargartexturas();
                            ManejoBolasLvl4();
                            CargaEscenas();
                        }

                        if (BtnNiv5Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 5;
                            window.setTitle("NIVEL 5");
                            Bolitas = new Sprite[16];
                            tubos = new Tubo[5];
                            TubosEnsayo = new Sprite[5];

                            for (int i = 0; i < 5; i++)
                                tubos[i].push(500);

                            CantTubos = 5;  CantBolas = 16;
                            tubo = 0;   lim = 0; CantMov = 0;

                            bolasTubo1 = 3; bolasTubo2 = 3;
                            bolasTubo3 = 4; bolasTubo4 = 3; bolasTubo5 = 3;
                            NivelesGanados = 0;

                            movimientos.ReiniciaMov();
                            movimientos.push(500, 500, 500);

                            Cargartexturas();
                            ManejoBolasLvl5();
                            CargaEscenas();
                        }
                    }
                    if (Escena != 0)
                    {
                        if (BtnHomeSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 0;
                        }

                        if (BtnMenuSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 11;
                        }

                        if (BtnReiniciarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            if (Escena == 1)
                            {
                                window.setTitle("NIVEL 1");
                                Bolitas = new Sprite[8];
                                tubos = new Tubo[3];
                                TubosEnsayo = new Sprite[3];

                                for (int i = 0; i < 3; i++)
                                tubos[i].push(500);

                                CantBolas = 8; CantTubos = 3; tubo = 0; lim = 0;
                                bolasTubo1 = 4; bolasTubo2 = 4; bolasTubo3 = 0;
                                CantMov = 0;  NivelesGanados = 0;

                                Cargartexturas();
                                ManejoBolasLvl1();
                                CargaEscenas();
                            }
                            if (Escena == 2)
                            {
                                window.setTitle("NIVEL 2");
                                Bolitas = new Sprite[12];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 12;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 4; bolasTubo2 = 4;
                                bolasTubo3 = 0; bolasTubo4 = 4; bolasTubo5 = 0;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl2();
                                CargaEscenas();
                            }
                            if (Escena == 3)
                            {
                                window.setTitle("NIVEL 3");
                                Bolitas = new Sprite[12];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 12;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 4; bolasTubo2 = 2;
                                bolasTubo3 = 3; bolasTubo4 = 0; bolasTubo5 = 3;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl3();
                                CargaEscenas();
                            }
                            if (Escena == 4)
                            {
                                window.setTitle("NIVEL 4");
                                Bolitas = new Sprite[16];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 16;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 4; bolasTubo2 = 4;
                                bolasTubo3 = 4; bolasTubo4 = 3; bolasTubo5 = 1;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl4();
                                CargaEscenas();
                            }
                            if (Escena == 5)
                            {
                                window.setTitle("NIVEL 5");
                                Bolitas = new Sprite[16];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 16;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 3; bolasTubo2 = 3;
                                bolasTubo3 = 4; bolasTubo4 = 3; bolasTubo5 = 3;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl5();
                                CargaEscenas();
                            }
                        }

                        if (BtnSigSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            if (NivelesGanados == 1)
                            {
                                Escena = 2;
                                window.setTitle("NIVEL 2");
                                Bolitas = new Sprite[12];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 12;
                                tubo = 0;   lim = 0; CantMov = 0;
                                
                                bolasTubo1 = 4; bolasTubo2 = 4;
                                bolasTubo3 = 0; bolasTubo4 = 4; bolasTubo5 = 0;
                                NivelesGanados = 0;
                               
                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);
                                
                                Cargartexturas();
                                ManejoBolasLvl2();
                                CargaEscenas();
                                
                            }
                            if (NivelesGanados == 2)
                            {
                                Escena = 3;
                                window.setTitle("NIVEL 3");
                                Bolitas = new Sprite[12];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 12;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 4; bolasTubo2 = 2;
                                bolasTubo3 = 3; bolasTubo4 = 0; bolasTubo5 = 3;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl3();
                                CargaEscenas();
                            }
                            if (NivelesGanados == 3)
                            {
                                Escena = 4;
                                window.setTitle("NIVEL 4");
                                Bolitas = new Sprite[16];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 16;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 4; bolasTubo2 = 4;
                                bolasTubo3 = 4; bolasTubo4 = 3; bolasTubo5 = 1;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl4();
                                CargaEscenas();
                            }
                            if (NivelesGanados == 4)
                            {
                                Escena = 5;
                                window.setTitle("NIVEL 5");
                                Bolitas = new Sprite[16];
                                tubos = new Tubo[5];
                                TubosEnsayo = new Sprite[5];

                                for (int i = 0; i < 5; i++)
                                    tubos[i].push(500);

                                CantTubos = 5;  CantBolas = 16;
                                tubo = 0;   lim = 0; CantMov = 0;

                                bolasTubo1 = 3; bolasTubo2 = 3;
                                bolasTubo3 = 4; bolasTubo4 = 3; bolasTubo5 = 3;
                                NivelesGanados = 0;

                                movimientos.ReiniciaMov();
                                movimientos.push(500, 500, 500);

                                Cargartexturas();
                                ManejoBolasLvl5();
                                CargaEscenas();
                            }
                        }
                    }


                }
                break;

            case Event::MouseMoved:
                if (Escena == 1 || Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5) {

                    if (TubosEnsayo[0].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada != 0)
                        {
                            tubo = 1;
                            if (Escena == 1)
                            {
                                Bolitas[BolaActual].setPosition(410, 130);
                            }
                            if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                            {
                                Bolitas[BolaActual].setPosition(110, 130);
                            }  
                        }
                    }

                    if (TubosEnsayo[1].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada != 0) 
                        {    
                            tubo = 2;
                            if (Escena == 1) 
                            {
                                 Bolitas[BolaActual].setPosition(610, 130);
                            }
                            if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                            {
                                Bolitas[BolaActual].setPosition(310, 130);
                            }
                        }
                    }

                    if (TubosEnsayo[2].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada != 0 ) {
                            
                            tubo = 3;
                            if (Escena == 1)
                            {
                                Bolitas[BolaActual].setPosition(810, 130);
                            }
                            if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                            {
                                Bolitas[BolaActual].setPosition(510, 130);
                            }
                        }
                    }
                }

                if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                {
                    if (TubosEnsayo[3].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada != 0) {

                            tubo = 4;
                            if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                            {
                                Bolitas[BolaActual].setPosition(710, 130);
                            }
                        }
                    }

                    if (TubosEnsayo[4].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    {
                        if (BolitaSeleccionada != 0) {

                            tubo = 5;
                            if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                            {
                                Bolitas[BolaActual].setPosition(910, 130);
                            }
                        }
                    }
                }

                break;
 
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
    BtnMenuSpt.setPosition(Vector2f(1062, 295));
    BtnMenuSpt.setScale(0.4f, 0.4f);

    BtnReiniciarTx.loadFromFile("reiniciar.png");
    BtnReiniciarSpt.setTexture(BtnReiniciarTx);
    BtnReiniciarSpt.setPosition(Vector2f(1050, 180));
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

    BtnGuardarTx.loadFromFile("btnGuardar.png");
    BtnGuardarSpt.setTexture(BtnGuardarTx);
    BtnGuardarSpt.setPosition(Vector2f(1065, 65));
    BtnGuardarSpt.setScale(0.8,0.8);

    BtnMovAntTx.loadFromFile("btnMovAnt.png");
    BtnMovAntSpt.setTexture(BtnMovAntTx);
    BtnMovAntSpt.setPosition(Vector2f(1065, 390));
    BtnMovAntSpt.setScale(0.8,0.8);

    BtnHomeTx.loadFromFile("btnHome.png");
    BtnHomeSpt.setTexture(BtnHomeTx);
    BtnHomeSpt.setPosition(Vector2f(1065, 490));
    BtnHomeSpt.setScale(0.75, 0.75);

    BtnNiv1Tx.loadFromFile("btnNivel1.png");
    BtnNiv1Spt.setTexture(BtnNiv1Tx);
    BtnNiv1Spt.setPosition(Vector2f(100, 200));
    BtnNiv1Spt.setScale(0.75, 0.75);

    BtnNiv2Tx.loadFromFile("btnNivel2.png");
    BtnNiv2Spt.setTexture(BtnNiv2Tx);
    BtnNiv2Spt.setPosition(Vector2f(500, 200));
    BtnNiv2Spt.setScale(0.75, 0.75);

    BtnNiv3Tx.loadFromFile("btnNivel3.png");
    BtnNiv3Spt.setTexture(BtnNiv3Tx);
    BtnNiv3Spt.setPosition(Vector2f(900, 200));
    BtnNiv3Spt.setScale(0.75, 0.75);

    BtnNiv4Tx.loadFromFile("btnNivel4.png");
    BtnNiv4Spt.setTexture(BtnNiv4Tx);
    BtnNiv4Spt.setPosition(Vector2f(300, 400));
    BtnNiv4Spt.setScale(0.75, 0.75);

    BtnNiv5Tx.loadFromFile("btnNivel5.png");
    BtnNiv5Spt.setTexture(BtnNiv5Tx);
    BtnNiv5Spt.setPosition(Vector2f(700, 400));
    BtnNiv5Spt.setScale(0.75, 0.75);

    BtnSigTx.loadFromFile("siguiente.png");
    BtnSigSpt.setTexture(BtnSigTx);
    BtnSigSpt.setPosition(Vector2f(800.f, 315));
    BtnSigSpt.setScale(0.5f, 0.5f);

    BtnRepeticionTx.loadFromFile("btnRepeticion.png");
    BtnRepeticionSpt.setTexture(BtnRepeticionTx);
    BtnRepeticionSpt.setPosition(Vector2f(615, 308));
    BtnRepeticionSpt.setScale(1, 1);

    if (NivelesGanados != 0) 
    {
        BtnMenuSpt.setPosition(Vector2f(270.f, 308.f));
        BtnMenuSpt.setScale(0.5f, 0.5f);

        BtnHomeSpt.setPosition(Vector2f(440.f, 308.f));
        BtnHomeSpt.setScale(1, 1);

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

    if (Escena != 0 && Escena != 10 & Escena != 6 && Escena != 11)
    {
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(BtnReiniciarSpt);
        window.draw(BtnMenuSpt);
        window.draw(BtnMovAntSpt);
        window.draw(BtnHomeSpt);
        window.draw(BtnGuardarSpt);

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
        window.draw(BtnHomeSpt);
        window.draw(BtnRepeticionSpt);
        if (NivelesGanados != 5) {
            window.draw(BtnSigSpt);
        }
        window.display();
    }
    if (Escena == 11)
    {
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(BtnDevolverseSpt);
        window.draw(BtnNiv1Spt);
        window.draw(BtnNiv2Spt);
        window.draw(BtnNiv3Spt);
        window.draw(BtnNiv4Spt);
        window.draw(BtnNiv5Spt);
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

void Juego::ManejoBolasLvl2()
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

        num2 = 0;

        for (int i = 8; i < 12; i++)
        {
            BolitaSpt1.setColor(Color::Yellow);
            Bolitas[i] = BolitaSpt1;
            num2 = num2 + 100;
        }

        //Tubos Ensayo
        TubosEnsayo[0].setPosition(100, 200);
        TubosEnsayo[1].setPosition(300, 200);
        TubosEnsayo[2].setPosition(500, 200);
        TubosEnsayo[3].setPosition(700, 200);
        TubosEnsayo[4].setPosition(900, 200);
        //T1
        Bolitas[4].setPosition(110, 230);//1T1
        Bolitas[0].setPosition(110, 280);//1T2
        Bolitas[8].setPosition(110, 330);//1T3
        Bolitas[6].setPosition(110, 380); //1T4
        tubos[0].push(6);
        tubos[0].push(8);
        tubos[0].push(0);
        tubos[0].push(4);
        //T2
        Bolitas[10].setPosition(310, 230);//2T1
        Bolitas[7].setPosition(310, 280);//2T2
        Bolitas[1].setPosition(310, 330);//2T3
        Bolitas[5].setPosition(310, 380);//2T4
        tubos[1].push(5);
        tubos[1].push(1);
        tubos[1].push(7);
        tubos[1].push(10);
        //T3 = Vacio
        //T4
        Bolitas[2].setPosition(710, 230);//4T1
        Bolitas[9].setPosition(710, 280);//4T2
        Bolitas[3].setPosition(710, 330);//4T3
        Bolitas[11].setPosition(710, 380);//4T4
        tubos[3].push(11);
        tubos[3].push(3);
        tubos[3].push(9);
        tubos[3].push(2);
        //T5 = Vacio
    }
}

void Juego::ManejoBolasLvl3()
{
    if (lim == 0)
    {
        lim = 1;

        for (int i = 0; i < 4; i++)
        {
            BolitaSpt1.setColor(Color::Cyan);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 4; i < 8; i++)
        {
            BolitaSpt1.setColor(Color::Magenta);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 8; i < 12; i++)
        {
            BolitaSpt1.setColor(Color::White);
            Bolitas[i] = BolitaSpt1;
        }

        //Tubos Ensayo
        TubosEnsayo[0].setPosition(100, 200);
        TubosEnsayo[1].setPosition(300, 200);
        TubosEnsayo[2].setPosition(500, 200);
        TubosEnsayo[3].setPosition(700, 200);
        TubosEnsayo[4].setPosition(900, 200);
        //T1
        Bolitas[4].setPosition(110, 230);//1T1
        Bolitas[0].setPosition(110, 280);//1T2
        Bolitas[8].setPosition(110, 330);//1T3
        Bolitas[6].setPosition(110, 380); //1T4
        tubos[0].push(6);
        tubos[0].push(8);
        tubos[0].push(0);
        tubos[0].push(4);
        //T2 = Vacio
        Bolitas[2].setPosition(310, 330);//2T3
        Bolitas[10].setPosition(310, 380);//2T4
        tubos[1].push(10);
        tubos[1].push(2);
        //T3
        //Bolitas[10].setPosition(510, 230);//3T1
        Bolitas[7].setPosition(510, 280);//3T2
        Bolitas[1].setPosition(510, 330);//3T3
        Bolitas[11].setPosition(510, 380);//3T4
        tubos[2].push(11);
        tubos[2].push(1);
        tubos[2].push(7);
        //T4 = Vacio
        //T5
        
        Bolitas[9].setPosition(910, 280);//5T2
        Bolitas[3].setPosition(910, 330);//5T3
        Bolitas[5].setPosition(910, 380);//5T4
        tubos[4].push(5);
        tubos[4].push(3);
        tubos[4].push(9);
        
        
    }
}

void Juego::ManejoBolasLvl4()
{
    if (lim == 0)
    {
        lim = 1;

        for (int i = 0; i < 4; i++)
        {
            BolitaSpt1.setColor(Color::Green);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 4; i < 8; i++)
        {
            BolitaSpt1.setColor(Color::White);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 8; i < 12; i++)
        {
            BolitaSpt1.setColor(Color::Yellow);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 12; i < 16; i++)
        {
            BolitaSpt1.setColor(Color::Red);
            Bolitas[i] = BolitaSpt1;
        }

        //Tubos Ensayo
        TubosEnsayo[0].setPosition(100, 200);
        TubosEnsayo[1].setPosition(300, 200);
        TubosEnsayo[2].setPosition(500, 200);
        TubosEnsayo[3].setPosition(700, 200);
        TubosEnsayo[4].setPosition(900, 200);
        //T1
        Bolitas[2].setPosition(110, 230);//1T2
        Bolitas[4].setPosition(110, 280);//1T3
        Bolitas[13].setPosition(110, 330);//1T2
        Bolitas[12].setPosition(110, 380); //1T4
        tubos[0].push(12);
        tubos[0].push(13);
        tubos[0].push(4);
        tubos[0].push(2);
        
        //T2
        Bolitas[8].setPosition(310, 230);//2T3
        Bolitas[14].setPosition(310, 280);//2T4
        Bolitas[0].setPosition(310, 330);//2T3
        Bolitas[5].setPosition(310, 380);//2T4
        tubos[1].push(5);
        tubos[1].push(0);
        tubos[1].push(14);
        tubos[1].push(8);
        //T3
        Bolitas[9].setPosition(510, 230);//3T2
        Bolitas[15].setPosition(510, 280);//3T2
        Bolitas[6].setPosition(510, 330);//3T3
        Bolitas[1].setPosition(510, 380);//3T4
        tubos[2].push(1);
        tubos[2].push(6);
        tubos[2].push(15);
        tubos[2].push(9);
        //T4 
       
        Bolitas[10].setPosition(710, 280);//4T2
        Bolitas[3].setPosition(710, 330);//4T3
        Bolitas[7].setPosition(710, 380);//4T4
        tubos[3].push(7);
        tubos[3].push(3);
        tubos[3].push(10);
        //T5
        Bolitas[11].setPosition(910, 380);//5T4
        tubos[4].push(11);
    }
}

void Juego::ManejoBolasLvl5()
{
    if (lim == 0)
    {
        lim = 1;

        for (int i = 0; i < 4; i++)
        {
            BolitaSpt1.setColor(Color::Yellow);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 4; i < 8; i++)
        {
            BolitaSpt1.setColor(Color::Cyan);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 8; i < 12; i++)
        {
            BolitaSpt1.setColor(Color::Magenta);
            Bolitas[i] = BolitaSpt1;
        }

        for (int i = 12; i < 16; i++)
        {
            BolitaSpt1.setColor(Color::White);
            Bolitas[i] = BolitaSpt1;
        }

        //Tubos Ensayo
        TubosEnsayo[0].setPosition(100, 200);
        TubosEnsayo[1].setPosition(300, 200);
        TubosEnsayo[2].setPosition(500, 200);
        TubosEnsayo[3].setPosition(700, 200);
        TubosEnsayo[4].setPosition(900, 200);
        //T1
        
        Bolitas[4].setPosition(110, 280); //1T4
        Bolitas[1].setPosition(110, 330);//1T2
        Bolitas[0].setPosition(110, 380); //1T4
        tubos[0].push(0);
        tubos[0].push(1);
        tubos[0].push(4);

        //T2
        Bolitas[13].setPosition(310, 280);//2T4
        Bolitas[12].setPosition(310, 330);//2T3
        Bolitas[8].setPosition(310, 380);//2T4
        tubos[1].push(8);
        tubos[1].push(12);
        tubos[1].push(13);
        //T3
        Bolitas[14].setPosition(510, 230);//3T2
        Bolitas[2].setPosition(510, 280);//3T2
        Bolitas[5].setPosition(510, 330);//3T3
        Bolitas[6].setPosition(510, 380);//3T4
        tubos[2].push(6);
        tubos[2].push(5);
        tubos[2].push(2);
        tubos[2].push(14);
        //T4 

        Bolitas[7].setPosition(710, 280);//4T2
        Bolitas[9].setPosition(710, 330);//4T3
        Bolitas[15].setPosition(710, 380);//4T4
        tubos[3].push(15);
        tubos[3].push(9);
        tubos[3].push(7);
        //T5
        Bolitas[10].setPosition(910, 280);//4T2
        Bolitas[11].setPosition(910, 330);//4T3
        Bolitas[3].setPosition(910, 380);//5T4
        tubos[4].push(3);
        tubos[4].push(11);
        tubos[4].push(10);
    }
}

int Juego::saberXY(int x, int esc) {
    if (esc == 1)
    {
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
        
    }
    if (esc == 2 || esc == 3 || esc==4 || esc==5)
    {
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
    }
    return y;
}

void Juego::Movimientos()
{
    int posY = 0;
    if (CantMov < 5)
    {
        if (Escena == 1 || Escena == 2 || Escena == 3 || Escena==4 || Escena == 5)
        {
            posY = 380;

            for (int i = 0; i < 4; i++)
            {
                if (bolasTubo1 == i && movimientos.top()->getTuboDestino() == 1)
                {
                    if (movimientos.top()->getTuboOrigen() == 2)
                        bolasTubo2 = bolasTubo2 - 1;
                    if (movimientos.top()->getTuboOrigen() == 3)
                        bolasTubo3 = bolasTubo3 - 1;
                    if (movimientos.top()->getTuboOrigen() == 4 && Escena == 2 || movimientos.top()->getTuboOrigen() == 4 && Escena == 3|| movimientos.top()->getTuboOrigen() == 4 && Escena==4 || movimientos.top()->getTuboOrigen() == 4 && Escena == 5)
                        bolasTubo4 = bolasTubo4 - 1;
                    if (movimientos.top()->getTuboOrigen() == 5 && Escena == 2 || movimientos.top()->getTuboOrigen() == 5 && Escena == 3||movimientos.top()->getTuboOrigen() == 5 && Escena == 4 || movimientos.top()->getTuboOrigen() == 5 && Escena == 5)
                        bolasTubo5 = bolasTubo5 - 1;

                    tubos[0].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop());
                    if(Escena == 1)
                    Bolitas[movimientos.pop()->getBolita()].setPosition(410, posY);
                    if(Escena == 2 || Escena == 3||Escena == 4 || Escena == 5)
                    Bolitas[movimientos.pop()->getBolita()].setPosition(110, posY);

                    bolasTubo1 = bolasTubo1 + 1;
                    CantMov = CantMov + 1;
                    break;
                }

                if (bolasTubo2 == i && movimientos.top()->getTuboDestino() == 2)
                {
                    if (movimientos.top()->getTuboOrigen() == 1)
                        bolasTubo1 = bolasTubo1 - 1;
                    if (movimientos.top()->getTuboOrigen() == 3)
                        bolasTubo3 = bolasTubo3 - 1;
                    if (movimientos.top()->getTuboOrigen() == 4 && Escena == 2 || movimientos.top()->getTuboOrigen() == 4 && Escena == 3 || movimientos.top()->getTuboOrigen() == 4 && Escena == 4 || movimientos.top()->getTuboOrigen() == 4 && Escena == 5)
                        bolasTubo4 = bolasTubo4 - 1;
                    if (movimientos.top()->getTuboOrigen() == 5 && Escena == 2 || movimientos.top()->getTuboOrigen() == 5 && Escena == 3 || movimientos.top()->getTuboOrigen() == 5 && Escena == 4 || movimientos.top()->getTuboOrigen() == 5 && Escena == 5)
                        bolasTubo5 = bolasTubo5 - 1;

                    tubos[1].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop()); //Saca la bola del tubo donde esta y la inserta a donde estaba
                    if(Escena == 1)
                    Bolitas[movimientos.pop()->getBolita()].setPosition(610, posY);
                    if(Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                    Bolitas[movimientos.pop()->getBolita()].setPosition(310, posY);

                    bolasTubo2 = bolasTubo2 + 1;
                    CantMov = CantMov + 1;
                    break;
                }

                if (bolasTubo3 == i && movimientos.top()->getTuboDestino() == 3)
                {
                    if (movimientos.top()->getTuboOrigen() == 1)
                        bolasTubo1 = bolasTubo1 - 1;
                    if (movimientos.top()->getTuboOrigen() == 2)
                        bolasTubo2 = bolasTubo2 - 1;
                    if (movimientos.top()->getTuboOrigen() == 4 && Escena == 2 || movimientos.top()->getTuboOrigen() == 4 && Escena == 3 || movimientos.top()->getTuboOrigen() == 4 && Escena == 4 || movimientos.top()->getTuboOrigen() == 4 && Escena == 5)
                        bolasTubo4 = bolasTubo4 - 1;
                    if (movimientos.top()->getTuboOrigen() == 5 && Escena == 2 || movimientos.top()->getTuboOrigen() == 5 && Escena == 3 || movimientos.top()->getTuboOrigen() == 5 && Escena == 4 || movimientos.top()->getTuboOrigen() == 5 && Escena == 5)
                        bolasTubo5 = bolasTubo5 - 1;

                    tubos[2].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop());
                    if(Escena == 1)
                    Bolitas[movimientos.pop()->getBolita()].setPosition(810, posY);
                    if(Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                    Bolitas[movimientos.pop()->getBolita()].setPosition(510, posY);

                    bolasTubo3 = bolasTubo3 + 1;
                    CantMov = CantMov + 1;
                    break;
                }

                if (Escena == 2 || Escena == 3||Escena==4 || Escena == 5)
                {
                    if (bolasTubo4 == i && movimientos.top()->getTuboDestino() == 4)
                    {
                        if (movimientos.top()->getTuboOrigen() == 1)
                            bolasTubo1 = bolasTubo1 - 1;
                        if (movimientos.top()->getTuboOrigen() == 2)
                            bolasTubo2 = bolasTubo2 - 1;
                        if (movimientos.top()->getTuboOrigen() == 3)
                            bolasTubo3 = bolasTubo3 - 1;
                        if (movimientos.top()->getTuboOrigen() == 5 && Escena == 2 || movimientos.top()->getTuboOrigen() == 5 && Escena == 3 || movimientos.top()->getTuboOrigen() == 5 && Escena == 4 || movimientos.top()->getTuboOrigen() == 5 && Escena == 5)
                            bolasTubo5 = bolasTubo5 - 1;

                        tubos[3].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop());

                        if(Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                        Bolitas[movimientos.pop()->getBolita()].setPosition(710, posY);

                        bolasTubo4 = bolasTubo4 + 1;
                        CantMov = CantMov + 1;
                        break;
                    }
                    if (bolasTubo5 == i && movimientos.top()->getTuboDestino() == 5)
                    {
                        if (movimientos.top()->getTuboOrigen() == 1)
                            bolasTubo1 = bolasTubo1 - 1;
                        if (movimientos.top()->getTuboOrigen() == 2)
                            bolasTubo2 = bolasTubo2 - 1;
                        if (movimientos.top()->getTuboOrigen() == 3)
                            bolasTubo3 = bolasTubo3 - 1;
                        if (movimientos.top()->getTuboOrigen() == 4 && Escena == 2 || movimientos.top()->getTuboOrigen() == 5 && Escena == 3 || movimientos.top()->getTuboOrigen() == 5 && Escena == 4 || movimientos.top()->getTuboOrigen() == 5 && Escena == 5)
                            bolasTubo4 = bolasTubo4 - 1;

                        tubos[4].push(tubos[movimientos.top()->getTuboOrigen() - 1].pop());

                        if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                        Bolitas[movimientos.pop()->getBolita()].setPosition(910, posY);

                        bolasTubo5 = bolasTubo5 + 1;
                        CantMov = CantMov + 1;
                        break;
                    }
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
            NivelesGanados = 1;
            Cargartexturas(); 
            
        }
    }

    if (Escena == 2 || Escena == 3||Escena==4 || Escena == 5)
    {
        for (int i = 0; i < 5; i++)
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
            if (TubosEnsayo[i].getGlobalBounds().contains(Bolitas[8].getPosition()) && TubosEnsayo[i].getGlobalBounds().contains(Bolitas[9].getPosition()))
            {
                if (TubosEnsayo[i].getGlobalBounds().contains(Bolitas[10].getPosition()) && TubosEnsayo[i].getGlobalBounds().contains(Bolitas[11].getPosition()))
                {
                    TubosCompletados = TubosCompletados + 1;
                }
            }
        }

        if (TubosCompletados == 3)
        {
            
            if(Escena == 2)
            NivelesGanados = 2; 
            if(Escena == 3)
            NivelesGanados = 3;
            if (Escena == 4)
                NivelesGanados = 4;
            if (Escena == 5)
                NivelesGanados = 5;

            Escena = 10;
            Cargartexturas();
        }
    }
}
