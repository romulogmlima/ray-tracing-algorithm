#include "face3.h"

#define EPSILON 0.000001

Face3::Face3(int _id, int _idV1, int _idV2, int _idV3): id(_id), idV1(_idV1), idV2(_idV2), idV3(_idV3)
{

}

int Face3::getID()
{
    return id;
}

int Face3::getIDVertex1()
{
    return idV1;
}

int Face3::getIDVertex2()
{
    return idV2;
}

int Face3::getIDVertex3()
{
    return idV3;
}

Vector3 Face3::getNormal()
{
    return normal;
}

int Face3::intersect(Ray ray, const Point3 v1, const Point3 v2, const Point3 v3, double *out)
{
    Vector3 e1, e2;   //Edge1, Edge2
    Vector3 P, Q, T;

    double det, inv_det, u, v;
    double t;

    //Find vectors for two edges sharing V1
    e1 = v2 - v1;
    e2 = v3 - v1;

    normal = (e1.cross(e2)).normalize(); // normal vector

    //Begin calculating determinant - also used to calculate u parameter
    P = ray.getDirection().cross(e2);

    //if determinant is near zero, ray lies in plane of triangle
    det = e1.dot(P);

    if((det > (-EPSILON)) && (det < EPSILON))
    {
        return 0;
    }

    inv_det = 1.f/det;

    //calculate distance from V1 to ray origin
    T = ray.getOrigin() - v1;

    //Calculate u parameter and test bound
    u = T.dot(P) * inv_det;

    //The intersection lies outside of the triangle
    if((u < 0.f) || (u > 1.f))
    {
        return 0;
    }

    //Prepare to test v parameter
    Q = T.cross(e1);

    //Calculate V parameter and test bound
    v = ray.getDirection().dot(Q) * inv_det;

    //The intersection lies outside of the triangle
    if((v < 0.f) || ((u + v) > 1.f))
    {
        return 0;
    }

    t = e2.dot(Q) * inv_det;

    //ray intersection
    if( t > EPSILON )
    {
        *out = t;
        return 1;
    }

    return 0;
}
