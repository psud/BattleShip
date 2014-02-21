#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "controller.h"
#include "values.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DeletePorts();
private slots:
    void DrawBox();
    void DrawFields();
    void DrawFieldNames();
    void DrawBoatPort();
    int DrawSinglePort(int width, int amount, int startY);
    void DrawMissedField(int xx, int yy);
    void mouseDown(int xx, int yy);
    void DrawBoatInField(int startX, int startY, int endX, int endY, bool rightDirection);
    int calCoordinate(int fieldNum, bool horizontal);
    void keyPressEvent(QKeyEvent *e);
    void gameStart();

    void on_bSubmit_clicked();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *e);

    values vals;
   // Controller con;

protected:
       void mouseMoveEvent(QMouseEvent * event);
       void mousePressEvent(QMouseEvent * event);




};

#endif // MAINWINDOW_H
