//Patrick Sudhaus
//19.02.2014
//Beautiful Code Pat! SHORT LINES

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//All sizes and variables are set in values class


//How can I remove the warning here?
void MainWindow::paintEvent(QPaintEvent *e){

    //Pen Color for future implementation
    ////pen.setColor(QColor(0,255,0,255));

    DrawBox();
    DrawFields();
    DrawFieldNames();
    DrawBoatPort();

    DrawMissedField(8,4);
    DrawMissedField(8,5);
    DrawMissedField(4,3);

   // DeletePorts();

    int startY = vals.getPaddingTop();
    startY -= vals.getFieldHeight();

    startY = DrawSinglePort(5,1,startY);
    startY = DrawSinglePort(4,2,startY);

    //DeletePorts();


    //    QPainter painter(this);
    //    QPixmap pic(":/new/prefix1/img/SchiffFront.png");
    //    painter.drawPixmap(400,400,100,100,pic);
    //TestDraw();
    //   QPainter painter(this);
    //     QPixmap pic(":/new/prefix1/img/SchiffFront.png");
    //    painter.drawPixmap(400,400,100,100,pic);

    // DrawBoatInField(1,1,3,1,true);


    //DrawBox(startX+ 500, startY, endX+ 500, endY, strokeWidth);
    //DrawFields(startX+ 500, startY, endX+ 500, endY, lineWidth);
}


void MainWindow::DrawBox(){

    //Set Starting Points here
    int startX = vals.getXStart();
    int startY = vals.getYStart();
    int endX = vals.getXEnd();
    int endY = vals.getYEnd();
    int penWidth = vals.getStrokeWidth();

    QPainter painter(this);

    //Set Stroke COlor here
    QPen strokePen(Qt::black);
    strokePen.setWidth(penWidth);
    painter.setPen(strokePen);

    //Cal how many px the box must have
    int width;
    int height;
    width = endX - startX;
    height = endY - startY;

    painter.drawRect(startX, startY,width,height);
}

void MainWindow::DrawFields(){
    int numberFields = vals.getNumFiels();

    int startX = vals.getXStart();
    int startY = vals.getYStart();
    int endX = vals.getXEnd();
    int endY = vals.getYEnd();

    int lineWidth = vals.getLineWidth();
    //Added strokeWidth so the 2 paints dont overlap
    int strokeWidth = vals.getStrokeWidth();

    QPainter painter(this);

    //Set Line Color here
    QPen pen(Qt::blue);
    pen.setWidth(lineWidth);
    painter.setPen(pen);

    //Drawing lines for Stroke
    QPoint start;
    QPoint end;

    //Calculate px per field (outsourced to values)
    int fieldWidth;
    int fieldHeight;

    fieldWidth = vals.getFieldWidth();
    fieldHeight = vals.getFieldHeight();

    //Horizontal Lines
    for (int i = 1; i < numberFields; i++){
        start.setX(startX + strokeWidth);
        start.setY(startY + (fieldHeight * i));
        end.setX(endX - strokeWidth);
        end.setY(startY + (fieldHeight * i));
        //Draw created Line
        painter.drawLine(start, end);
    }

    //Vertikal Lines
    for (int i = 1; i < numberFields; i++){
        start.setX(startX + (fieldWidth * i));
        start.setY(startY + strokeWidth);
        end.setX(startX + (fieldWidth * i));
        end.setY(endY - strokeWidth);
        //Draw newly created Line
        painter.drawLine(start, end);
    }
}

void MainWindow::DrawFieldNames(){
    int numberFields = vals.getNumFiels();

    int fieldWidth = vals.getFieldWidth();
    int fieldHeight = vals.getFieldHeight();
    int startX = vals.getXStart();
    int startY = vals.getYStart();

    QPainter painter(this);
    painter.setPen(Qt::red);
    QFont font = painter.font();
    font.setPointSize(vals.getFontSize());
    painter.setFont(font);

    QPoint point;
    //Draw horizontal Numbers
    for (int i = 1; i <= numberFields; i++){
        int xLoc;
        xLoc = startX - 5;
        xLoc += (i-1)*fieldWidth;
        xLoc += fieldWidth /2;
        point.setX(xLoc);
        point.setY(startY - 10);
        QString num;
        if (vals.debugState())
            num = QString::number(i -1);
        else
            num = QString::number(i);
        painter.drawText(point, num);
    }
    //Draw Vertical Numbers
    for (int i = 1; i <= numberFields; i++){
        int yLoc;
        yLoc = startY;
        //Adding pixels to correct offset
        yLoc += 10;
        yLoc += (i-1)*fieldHeight;
        yLoc += fieldHeight/2;
        point.setY(yLoc);
        point.setX(startX- 20);
        //To crate the letters Im taking the ascii number and adding
        //the counter vatiable i so I get the letters easily and in a loop
        char fieldName;
        fieldName = 64 + i;
        QString num;
        if (vals.debugState())
            num = QString::number(i -1);
        else
            num = QString(fieldName);
        painter.drawText(point, num);
    }
}

void MainWindow::DrawBoatPort(){
    QPainter p(this);
    QPen pen(Qt::green);
    pen.setWidth(vals.getStrokeWidth());
    p.setPen(pen);

    //Amount of Boats (source: wikipedia)
    // ein Schlachtschiff (5 Kästchen)
    // zwei Kreuzer (je 4 Kästchen)
    // drei Zerstörer (je 3 Kästchen)
    // vier U-Boote (je 2 Kästchen)

    int startY = vals.getPaddingTop();
    startY -= vals.getFieldHeight();

    startY = DrawSinglePort(5,1,startY);
    startY = DrawSinglePort(4,2,startY);
    startY = DrawSinglePort(3,3,startY);
    startY = DrawSinglePort(2,4,startY);


}

//Why cant I pass QPainter to methods??!?
int MainWindow::DrawSinglePort(int width, int amount, int startY){//, QPainter *p){
    QPainter p(this);
    QColor myPenColor;
        myPenColor = Qt::green;

    QPen pen(myPenColor);
    pen.setWidth(vals.getStrokeWidth());
    p.setPen(pen);

    int fieldHeight;
    int pSpace;
    int widthPx;
    int startX;
    fieldHeight = vals.getFieldHeight();
    pSpace = vals.getPortSpace();
    widthPx= width * fieldHeight;
    startX = vals.getPxHorizontal();
    startX += vals.getPortDistance();
    startX += vals.getPaddingLeft();

    for (int i = 0; i < amount; i++){
        if (width < 3 && i % 2 == 1){
            int startXOffset;
            startXOffset = startX + 2 * vals.getFieldWidth()+ vals.getPortSpace();
            p.drawRect(startXOffset, startY, widthPx, fieldHeight);
        }
        else {
            startY += fieldHeight + pSpace;
            p.drawRect(startX, startY, widthPx, fieldHeight);
        }
    }

    return startY;
}

void MainWindow::DeletePorts(){
    QPainter p(this);
 qDebug() << "bla";
    int startX = vals.getPxHorizontal();
    startX += vals.getPortDistance();
    startX -= 30;
    int startY = vals.getPaddingTop();
    int width = 5 * vals.getFieldWidth();
    int height= vals.getPxVertical();
    p.eraseRect(startX,startY,300,300);
    //p.eraseRect(100,100,100,100);
}



void MainWindow::DrawBoatInField(int startX, int startY, int endX, int endY, bool rightDirection){

    QPainter painter(this);
    int startPxX;
    int startPxY;
    int endPxX;
    int endPxY;
    int width;
    int height;
    startPxX = calCoordinate(startX, true);
    startPxY = calCoordinate(startY, true);
    endPxX = calCoordinate(endX, false);
    endPxY = calCoordinate(endY, false);
    //    QString testOut;
    //    testOut = "startX: " + QString::number(startPxX) + "\n";
    //    testOut += "startY: " + QString::number(startPxY) + "\n";
    //    testOut += "endX: " + QString::number(endPxX) + "\n";
    //    testOut += "endY: " + QString::number(endPxY) + "\n";
    //    ui->label->setText(testOut);

    int direction = 0;
    //direction = 1 --> horizontal, front to right
    //direction = 2 --> horizontal, front to left
    //direction = 3 --> vertical, front down
    //direction = 4 --> vertical, front up
    if (startY == endY && rightDirection)
        direction = 1;
    else if (startY == endY && !rightDirection)
        direction = 2;
    else if (startX == endX && rightDirection)
        direction = 3;
    else if (startX == endX && !rightDirection)
        direction = 4;
    //if nothing is true direction stays 0

    int length = 0;
    if (direction == 1 || direction == 2){
        length = endX - startX;
        width = length * vals.getFieldWidth();
        height = vals.getFieldHeight();
    }
    if (direction == 3 || direction == 4){
        length = endY - startY;
        width = vals.getFieldWidth();
        height = length * vals.getFieldHeight();
    }





    QPixmap pic(":/new/prefix1/img/SchiffFront.png");
    //painter.drawPixmap(400,400,100,100,pic);

    painter.drawPixmap(startPxX,startPxY,width,height,pic);
}

void MainWindow::DrawMissedField(int xx, int yy){
    QPainter p(this);

    int startX;
    int startY;

    startX = calCoordinate(xx, true);
    startY = calCoordinate(yy, false);


    QPixmap splash(":/new/prefix1/splash");
    p.drawPixmap(startX, startY, vals.getFieldWidth(), vals.getFieldHeight(), splash);
}


void MainWindow::gameStart(){


}


int MainWindow::calCoordinate(int fieldNum, bool horizontal){
    int px;
    if (horizontal){
        px = fieldNum * vals.getFieldWidth();
        px += vals.getPaddingLeft();
    }
    else {
        px = fieldNum * vals.getFieldHeight();
        px += vals.getPaddingTop();
    }

    return px;
}

void MainWindow::mouseDown(int xx, int yy){
    int xInField;
    int yInField;
    int posX;
    int posY;

    xInField = xx - vals.getXStart();
    yInField = yy - vals.getYStart();
    posX = xInField /
            vals.getFieldWidth();
    posY = yInField / vals.getFieldHeight();

    ui->label->setText("X: "+ QString::number(xInField)+
                       ", Y: "+QString::number(yInField)+
                       "posY: "+ QString::number(posX)+
                       ", posY: "+QString::number(posY));


}



void MainWindow::mousePressEvent(QMouseEvent * event){
    int xx;
    int yy;
    xx = event->x();
    yy = event->y();
    mouseDown(xx,yy);

    //DrawMissedField(5,5);//calCoordinate(xx,true),calCoordinate(yy,false));
    DrawMissedField(1,1);

}


void MainWindow::mouseMoveEvent(QMouseEvent * event){
    int xx;
    int yy;
    xx = event->x();
    yy = event->y();
    mouseDown(xx,yy);
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    ui->label->setText("Key Pressed: " + QString(e->key()));

    if(e->key() == Qt::Key_Right){

    }
    if(e->key() == Qt::Key_Left){

    }
    if(e->key() == Qt::Key_Up){

    }
    if(e->key() == Qt::Key_Down){

    }
}

void MainWindow::on_bSubmit_clicked()
{


   // int boatsField[vals.getNumFiels()][vals.getNumFiels()];

    //TODO
    //get all of the filled and empty field
    //could do this directly in DrawBoatInField

   // Controller con;
   // con.submitClicked();

    int bla = DrawSinglePort(6,1,100);

}
