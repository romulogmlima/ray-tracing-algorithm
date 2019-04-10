#include <iostream>
#include <math.h>
#include <QtDebug>
#include <QDoubleValidator>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "readfile.h"
#include "object3d.h"
#include "vector3.h"
#include "camera.h"
#include "transform.h"
#include "scene.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->eye_x->setValidator(new QDoubleValidator(-500, 500, 2, this));
    ui->eye_y->setValidator(new QDoubleValidator(-500, 500, 2, this));
    ui->eye_z->setValidator(new QDoubleValidator(-500, 500, 2, this));

    ui->at_x->setValidator(new QDoubleValidator(-500, 500, 2, this));
    ui->at_y->setValidator(new QDoubleValidator(-500, 500, 2, this));
    ui->at_z->setValidator(new QDoubleValidator(-500, 500, 2, this));

    ui->light_pos_x->setValidator(new QDoubleValidator(-500, 500, 2, this));
    ui->light_pos_y->setValidator(new QDoubleValidator(-500, 500, 2, this));
    ui->light_pos_z->setValidator(new QDoubleValidator(-500, 500, 2, this));

    ui->light_comp_red->setInputMask("9.99");
    ui->light_comp_green->setInputMask("9.99");
    ui->light_comp_blue->setInputMask("9.99");

    ui->ka_red->setInputMask("9.99");
    ui->ka_green->setInputMask("9.99");
    ui->ka_blue->setInputMask("9.99");

    ui->kd_red->setInputMask("9.99");
    ui->kd_green->setInputMask("9.99");
    ui->kd_blue->setInputMask("9.99");

    ui->ks_red->setInputMask("9.99");
    ui->ks_green->setInputMask("9.99");
    ui->ks_blue->setInputMask("9.99");

    ui->shininess->setValidator(new QDoubleValidator(0, 500, 2, this));
}

void MainWindow::initialize()
{
    vector<Vertex3> v1 = ReadFile::importListVertex(VERTEX_CUBE_PATH_FILE);
    vector<Face3> f1 = ReadFile::importListFaces(FACE_CUBE_PATH_FILE);

    vector<Vertex3> v2 = ReadFile::importListVertex(VERTEX_ROOF_PATH_FILE);
    vector<Face3> f2 = ReadFile::importListFaces(FACE_ROOF_PATH_FILE);

    vector<Vertex3> v3 = ReadFile::importListVertex(VERTEX_CYLINDER_PATH_FILE);
    vector<Face3> f3 = ReadFile::importListFaces(FACE_CYLINDER_PATH_FILE);

    Material mat(RGBColor(kaR, kaG, kaB), RGBColor(kdR, kdG, kdB), RGBColor(ksR, ksG, ksB), shininess);

    Object3D stairstep0(0, v1, f1, mat);
    Object3D stairstep1(1, v1, f1, mat);
    Object3D stairstep2(2, v1, f1, mat);
    Object3D roof(3, v2, f2, mat);

    Point3 eye(pEyeX, pEyeY, pEyeZ);
    Point3 lookAt(pAtX, pAtY, pAtZ);

    Camera camera(eye, lookAt, W_T, H_T, COL_PIX, LIN_PIX, 6);
    Scene scene(camera, RGBColor(0.5, 0.5, 0.5));

    Light lwhite(Point3(pLightX, pLightY, pLightZ), RGBColor(cLightR, cLightG, cLightB), 1.0f, 0.0014f, 0.000007f);

    scene.addLight(lwhite);

    scene.addObject3D(stairstep0);
    scene.addObject3D(stairstep1);
    scene.addObject3D(stairstep2);
    scene.addObject3D(roof);

    for(int i = 4; i <= 49; ++i)
    {
        Object3D pillar(i, v3, f3, mat);
        scene.addObject3D(pillar);
    }

    scene.applyTransformation(0, Transform::scale(16.45, 0.5, 35.75));
    scene.applyTransformation(1, Transform::scale(15.95, 0.5, 35.25));
    scene.applyTransformation(1, Transform::translation(Vector3(0.0, 1.0, 0.0)));
    scene.applyTransformation(2, Transform::scale(15.45, 0.5, 34.75));
    scene.applyTransformation(2, Transform::translation(Vector3(0.0, 2.0, 0.0)));
    scene.applyTransformation(3, Transform::scale(3.09, 1.0, 3.475));
    scene.applyTransformation(3, Transform::translation(Vector3(0.0, 12.9, 0.0)));

    for(int i = 4 ; i <= 11 ; ++i)
    {
        scene.applyTransformation(i, Transform::scale(0.95, 5.2, 0.95));
        scene.applyTransformation(i, Transform::translation(Vector3(13.0 - (i-4)*(3.71), 7.7, 32.3)));
    }

    for(int i = 12 ; i <= 19 ; ++i)
    {
        scene.applyTransformation(i, Transform::scale(0.95, 5.2, 0.95));
        scene.applyTransformation(i, Transform::translation(Vector3(13.0 - (i-12)*(3.71), 7.7, -32.3)));
    }

    for(int i = 20 ; i <= 34 ; ++i)
    {
        scene.applyTransformation(i, Transform::scale(0.95, 5.2, 0.95));
        scene.applyTransformation(i, Transform::translation(Vector3(-13.0, 7.7, 32.3 - (i-19)*(4.0375))));
    }

    for(int i = 35 ; i <= 49 ; ++i)
    {
        scene.applyTransformation(i, Transform::scale(0.95, 5.2, 0.95));
        scene.applyTransformation(i, Transform::translation(Vector3(13.0, 7.7, 32.3 - (i-34)*(4.0375))));
    }

    scene.changeCoordinateSystemsWTC();

    vector< vector<RGBColor> > vec(LIN_PIX, vector<RGBColor>(COL_PIX));
    scene.rayTracing(vec);

    this->teste(vec);
}

void MainWindow::teste(vector< vector<RGBColor> > &view)
{
    QImage image22(LIN_PIX, COL_PIX, QImage::Format_RGB32);

    QRgb value;
    RGBColor temp;

    for(int i = 0; i < LIN_PIX ; ++i)
    {
        for(int j = 0; j < COL_PIX ; ++j)
        {
            temp = view[i][j];

            temp.red = (temp.red > 1) ? 1: temp.red;
            temp.green = (temp.green > 1) ? 1: temp.green;
            temp.blue = (temp.blue > 1) ? 1: temp.blue;

            value = qRgb(temp.red * 255, temp.green * 255, temp.blue * 255);
            image22.setPixel(j, i, value);
        }
    }

    image = QPixmap::fromImage(image22);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    pEyeX = ui->eye_x->text().toDouble();
    pEyeY = ui->eye_y->text().toDouble();
    pEyeZ = ui->eye_z->text().toDouble();
    cout << "Eye point: " << pEyeX << ", " << pEyeY << ", " << pEyeZ << endl;

    pAtX = ui->at_x->text().toDouble();
    pAtY = ui->at_y->text().toDouble();
    pAtZ = ui->at_z->text().toDouble();
    cout << "Look-at point: " << pAtX << ", " << pAtY << ", " << pAtZ << endl;

    pLightX = ui->light_pos_x->text().toDouble();
    pLightY = ui->light_pos_y->text().toDouble();
    pLightZ = ui->light_pos_z->text().toDouble();
    cout << "Light position: " << pLightX << ", " << pLightY << ", " << pLightZ << endl;

    cLightR = ui->light_comp_red->text().toDouble();
    cLightG = ui->light_comp_green->text().toDouble();
    cLightB = ui->light_comp_blue->text().toDouble();
    cout << "Light color: " << cLightR << ", " << cLightG << ", " << cLightB << endl;

    kaR = ui->ka_red->text().toDouble();
    kaG = ui->ka_green->text().toDouble();
    kaB = ui->ka_blue->text().toDouble();
    cout << "Ka: " << kaR << ", " << kaG << ", " << kaB << endl;

    kdR = ui->kd_red->text().toDouble();
    kdG = ui->kd_green->text().toDouble();
    kdB = ui->kd_blue->text().toDouble();
    cout << "Kd: " << kdR << ", " << kdG << ", " << kdB << endl;

    ksR = ui->ks_red->text().toDouble();
    ksG = ui->ks_green->text().toDouble();
    ksB = ui->ks_blue->text().toDouble();
    cout << "Ks: " << ksR << ", " << ksG << ", " << ksB << endl;

    shininess = ui->shininess->text().toDouble();
    cout << "Shininess: " << shininess << endl;

    this->initialize();
}
