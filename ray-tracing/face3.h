#include "vector3.h"
#include "ray.h"

#ifndef FACE_H
#define FACE_H

class Face3
{
    public:
        Face3(int id, int idV1, int idV2, int idV3);

        int getID();
        int getIDVertex1();
        int getIDVertex2();
        int getIDVertex3();

        int intersect(Ray ray, const Point3 v1, const Point3 v2, const Point3 v3, double* out);
        Vector3 getNormal();

    private:
        int id;
        int idV1, idV2, idV3;
        Vector3 normal;
};

#endif // FACE_H
