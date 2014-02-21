#include "controller.h"
#include <QDebug>

Controller::Controller()
{
  //  boats[vals.getNumFiels()][vals.getNumFiels()];
}

//bool Controller::checkField(int xx, int yy){
//    bool hit;

//       if (boats[xx][yy]!= 0){
//           return true;

//       }
//       else {
//           return false;
//       }

//}


//void Controller::setBoats(int boatsIn[][]){
//    for (int i = 0; i < vals.getNumFiels(); i++){
//        for(int o = 0; o < vals.getNumFields(); o++){
//            boats[i,o]=boatsIn[i,o];
//        }
//    }

//}

void Controller::submitClicked(){
    MainWindow ui;
    ui.DeletePorts();

    qDebug() << "bla";
}
