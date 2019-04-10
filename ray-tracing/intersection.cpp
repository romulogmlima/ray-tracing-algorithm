#include "intersection.h"

Intersection::Intersection()
{
    isIntsc = false;
}

void Intersection::operator=(Intersection &its)
{
    isIntsc = its.isIntsc;
    pIntsc = its.getIntersectionPoint();
    normal = its.getNormalIntscPoint();
    distOri = its.getDistanceOrigin();
    idObj = its.getObjectID();
    matObj = its.getMaterialObjIntsc();
}

Point3 Intersection::getIntersectionPoint()
{
    return pIntsc;
}

void Intersection::setIntersectionPoint(Point3 pIntsc)
{
    this->pIntsc = pIntsc;
}

Vector3 Intersection::getNormalIntscPoint()
{
    return normal;
}

void Intersection::setNormalIntscPoint(Vector3 normal)
{
    this->normal= normal;
}

double Intersection::getDistanceOrigin()
{
    return distOri;
}

void Intersection::setDistanceOrigin(double distOrigin)
{
    this->distOri = distOrigin;
}

int Intersection::getObjectID()
{
    return idObj;
}

void Intersection::setObjectID(int idObj)
{
    this->idObj = idObj;
}

Material Intersection::getMaterialObjIntsc()
{
    return matObj;
}

void Intersection::setMaterialObjIntsc(Material matObj)
{
    this->matObj = matObj;
}
