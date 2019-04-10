#include <cmath>
#include "transform.h"


Transform::Transform()
{
    for(int i = 0; i < 16; ++i)
    {
        values[i] = 0.0;
    }

    values[0] = values[5] = values[10] = values[15] = 1.0;
}

Transform & Transform::operator= (const Transform & RHS)
{
    for(int i = 0; i < 16; ++i)
    {
        values[i] = RHS.values[i];
    }

    return *this;
}

Transform Transform::operator* (const Transform & RHS) const
{
    Transform res;

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            res(i, j) = 0.0;
            for(int k = 0; k < 4; ++k)
            {
                res(i, j) += (*this)(i, k) * RHS(k, j);
            }
        }
    }

    return res;
}

void Transform::operator*(Vertex3 &v)
{
    double temp[4] = {v.x, v.y, v.z, 1.0};
    double res[4] = {0.0, 0.0, 0.0, 0.0};

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            res[i] += (*this)(i, j) * temp[j];
        }
    }

    v.x = res[0];
    v.y = res[1];
    v.z = res[2];
}

void Transform::operator*(Point3 &p)
{
    double temp[4] = {p.x, p.y, p.z, 1.0};
    double res[4] = {0.0, 0.0, 0.0, 0.0};

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            res[i] += (*this)(i, j) * temp[j];
        }
    }

    p.x = res[0];
    p.y = res[1];
    p.z = res[2];
}

Transform Transform::worldToCamera(Vector3 i, Vector3 j, Vector3 k, Vector3 eye)
{
    Transform WTC;

    WTC(0,0) = i.x;     WTC(0,1) = i.y;     WTC(0,2) = i.z;     WTC(0,3) = (-1) * i.dot(eye);
    WTC(1,0) = j.x;     WTC(1,1) = j.y;     WTC(1,2) = j.z;     WTC(1,3) = (-1) * j.dot(eye);
    WTC(2,0) = k.x;     WTC(2,1) = k.y;     WTC(2,2) = k.z;     WTC(2,3) = (-1) * k.dot(eye);
    WTC(3,0) = 0;       WTC(3,1) = 0;       WTC(3,2) = 0;       WTC(3,3) = 1;

    return WTC;
}

Transform Transform::cameraToWorld(Vector3 i, Vector3 j, Vector3 k, Vector3 eye)
{
    Transform WTC;

    WTC(0,0) = i.x;     WTC(0,1) = j.x;     WTC(0,2) = k.x;     WTC(0,3) = eye.x;
    WTC(1,0) = i.y;     WTC(1,1) = j.y;     WTC(1,2) = k.y;     WTC(1,3) = eye.y;
    WTC(2,0) = i.z;     WTC(2,1) = j.z;     WTC(2,2) = k.z;     WTC(2,3) = eye.z;
    WTC(3,0) = 0;       WTC(3,1) = 0;       WTC(3,2) = 0;       WTC(3,3) = 1;

    return WTC;
}

Transform Transform::rotation(double angle, Axis axis)
{
    Transform rotation;

    if(axis == X_AXIS)
    {
        rotation(2,2) = cos(rad(angle));
        rotation(1,2) = -sin(rad(angle));
        rotation(1,1) = cos(rad(angle));
        rotation(2,1) = sin(rad(angle));
    }
    else if(axis == Y_AXIS)
    {
        rotation(0,0) = cos(rad(angle));
        rotation(2,2) = cos(rad(angle));
        rotation(2,0) = -sin(rad(angle));
        rotation(0,2) = sin(rad(angle));
    }
    else if(axis == Z_AXIS)
    {
        rotation(0,0) = cos(rad(angle));
        rotation(1,1) = cos(rad(angle));
        rotation(0,1) = -sin(rad(angle));
        rotation(1,0) = sin(rad(angle));
    }

    return rotation;
}

Transform Transform::translation(Vector3 displ)
{
    Transform res;

    res(0, 3) = displ.x;
    res(1, 3) = displ.y;
    res(2, 3) = displ.z;

    return res;
}

Transform Transform::scale(double x, double y, double z)
{
    Transform res;

    res(0, 0) = x;
    res(1, 1) = y;
    res(2, 2) = z;

    return res;
}

double& Transform::operator()(unsigned int row, unsigned int col)
{
    return values[row * 4 + col];
}

const double& Transform::operator()(unsigned int row, unsigned int col) const
{
    return values[row * 4 + col];
}

double Transform::rad(double angle)
{
    return( angle * (M_PI/180) );
}
