#include "vector3.h"
#include "vertex3.h"
#include "point3.h"

#ifndef TMATRIX_H
#define TMATRIX_H

class Transform
{
    public:
        Transform();

        enum Axis {X_AXIS, Y_AXIS, Z_AXIS};

        Transform & operator=(const Transform &);
        Transform operator*(const Transform &) const;
        void operator*(Vertex3 &v);
        void operator*(Point3 &p);

        static Transform worldToCamera(Vector3 i, Vector3 j, Vector3 k, Vector3 eye);
        static Transform cameraToWorld(Vector3 i, Vector3 j, Vector3 k, Vector3 eye);
        static Transform rotation(double angle, Axis axis);
        static Transform translation(Vector3 displ);
        static Transform scale(double x, double y, double z);

    private:
        double values[16];
        static double rad(double angle);

        // Assignment operator. Ex:m(0,0) = 1;
        double& operator()( unsigned int row, unsigned int column);
        const double& operator()(unsigned int row, unsigned int column) const;
};

#endif // TMATRIX_H
