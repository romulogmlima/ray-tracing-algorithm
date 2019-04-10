#include "point3.h"
#include "material.h"

#ifndef INTERSECTION_H
#define INTERSECTION_H

class Intersection
{
    public:
        Intersection();

        void operator=(Intersection &its);
        void setIntersectionPoint(Point3);
        void setNormalIntscPoint(Vector3);
        void setDistanceOrigin(double);
        void setObjectID(int);
        void setMaterialObjIntsc(Material);

        Point3 getIntersectionPoint();
        Vector3 getNormalIntscPoint();
        Material getMaterialObjIntsc();
        double getDistanceOrigin();
        int getObjectID();

        bool isIntsc;

    private:
        Point3 pIntsc;
        Vector3 normal;
        Material matObj;

        double distOri;
        int idObj;
};

#endif // INTERSECTION_H
