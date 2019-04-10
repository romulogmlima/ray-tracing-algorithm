#include <iostream>
#include "camera.h"

using namespace std;

Camera::Camera(){}

Camera::Camera(Point3 &eye, Point3 &lookAt, int width, int height, int colPixels, int linPixels, double dist)
{
    this->eye = eye;
    this->lookAt = lookAt;

    this->up.x = lookAt.x - eye.x;
    this->up.y = (lookAt.y + 1) - eye.y;
    this->up.z = lookAt.z - eye.z;

    this->width = width;
    this->height = height;
    this->colPixels = colPixels;
    this->linPixels = linPixels;
    this->dist = dist;

    this->deltaX = static_cast<double>(width) / colPixels;
    this->deltaY = static_cast<double>(height) / linPixels;

    computerIJK();
}

void Camera::computerIJK()
{
    k = (eye - lookAt).normalize();
    i = up.cross(k).normalize();
    j = k.cross(i);
}

Ray Camera::generateRay(int row, int col)
{
    if( (col < 0) || (col > colPixels - 1) || (row < 0) || (row > linPixels - 1) )
    {
        return Ray(Point3(), Point3());
    }
    else
    {
        double posx = (-width/2.0) + deltaX/2.0 + deltaX * col;
        double posy = (+height/2.0) - deltaY/2.0 - deltaY * row;

        return Ray(Point3(0.0, 0.0, 0.0), Point3(posx, posy, (-1) * dist));
    }
}

Vector3 Camera::getBaseI()
{
    return i;
}

Vector3 Camera::getBaseJ()
{
    return j;
}

Vector3 Camera::getBaseK()
{
    return k;
}

Point3 Camera::getEye()
{
    return eye;
}
