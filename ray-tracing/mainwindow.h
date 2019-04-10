#include "rgbcolor.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initialize();
    void teste(vector< vector<RGBColor> > &);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QGraphicsScene *scene;

    double pEyeX, pEyeY, pEyeZ;
    double pAtX, pAtY, pAtZ;
    double pLightX, pLightY, pLightZ;
    double cLightR, cLightG, cLightB;
    double kaR, kaG, kaB, kdR, kdG, kdB, ksR, ksG, ksB;
    double shininess;
};

#endif // MAINWINDOW_H
