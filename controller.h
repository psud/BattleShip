#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "netinterface.h"
#include "mainwindow.h"
#include "values.h"
#include "controller.h"

class Controller
{
public:
   Controller();

    //checkField(int xx, int yy);

    //setBoats(int boats[][]);

    //gameStart();

    void submitClicked();

private:
   // int boats[10][10];

    values vals;
    //Why cant I init this here?!?!
   // MainWindow ui;


};

#endif // CONTROLLER_H
