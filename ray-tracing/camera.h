#include "point3.h"
#include "vector3.h"
#include "ray.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
    public:
        Camera();
        Camera(Point3 &, Point3 &, int width, int height, int colPixels,
               int linPixels, double dist);

        Vector3 getBaseI();
        Vector3 getBaseJ();
        Vector3 getBaseK();

        Ray generateRay(int row, int col);
        Point3 getEye();

    private:
        Point3 eye;
        Point3 lookAt;

        Vector3 i, j, k;
        Vector3 up;

        int linPixels, colPixels;
        int width, height;
        double dist;
        double deltaX, deltaY;

        void computerIJK(void);
};

#endif // CAMERA_H
