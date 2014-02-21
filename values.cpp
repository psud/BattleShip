#include "values.h"

values::values()
{
    //Just for debugging
    //changes things like naming of grid fields
    debugging = true;

    //Padding
    paddingTop = 100;
    paddingLeft = 50;

    //Set Width of pens here
    strokeWidth = 4;
    lineWidth = 2;

    //Set Starting Points here
    startX = 0;
    startY = 0;
    endX = 450;
    endY = 450;

    numFields = 10;

    //Font Size of naming of the fields
    fontSize = 15;

    portDistance = 100;

    portSpace = 11;



}

int values::getXStart(){

    return startX + paddingLeft;
}

int values::getYStart(){
    return startY+ paddingTop;
}

int values::getXEnd(){
    return endX+ paddingLeft;
}

int values::getYEnd(){
    return endY+ paddingTop;
}

int values::getStrokeWidth(){
    return strokeWidth;
}

int values::getLineWidth(){
    return lineWidth;
}

int values::getPaddingLeft(){
    return paddingLeft;
}

int values::getPaddingTop(){
    return paddingTop;
}

int values::getNumFiels(){
    return numFields;
}
int values::getFieldWidth(){
    int fieldWidth;
    fieldWidth = endX - startX;
    fieldWidth = fieldWidth / numFields;
    return fieldWidth;
}
int values::getFieldHeight(){
    int fieldHeight;
    fieldHeight = endY - startY;
    fieldHeight = fieldHeight / numFields;
    return fieldHeight;
}

//Unused
int values::getPxHorizontal(){
    return endX - startX;
}
//Unused
int values::getPxVertical(){
    return endY - endX;
}

int values::getFontSize(){
    return fontSize;
}

int values::getPortDistance(){
    return portDistance;
}

int values::getPortSpace(){
    return portSpace;
}

bool values::debugState(){
    return debugging;
}



