#include <iostream>
#include <math.h>
#include "scene.h"
#include "constants.h"

using namespace std;

Scene::Scene(Camera cam, RGBColor _ambientEmission)
{
    this->camera = cam;
    this->ambientEmission = _ambientEmission;
}

Object3D & Scene::getObject3D(int indc)
{
    return listObjects3D.at(indc);
}

Light & Scene::getLight(int indc)
{
    return listLights.at(indc);
}

int Scene::getNumberOfObjects()
{
    return listObjects3D.size();
}

void Scene::addLight(const Light &light)
{
    listLights.push_back(light);
}

void Scene::addObject3D(const Object3D &obj)
{
    listObjects3D.push_back(obj);
}

void Scene::applyTransformation(int indc, Transform tMx)
{
    Object3D &tempObj = getObject3D(indc);

    for(int j = 0; j < tempObj.getNumberOfVertices(); ++j)
    {
        Vertex3 &v = tempObj.getVertex(j);
        tMx * v;
    }
}

void Scene::changeCoordinateSystemsWTC()
{
    Point3 source(0.0, 0.0, 0.0);
    Transform mWTC = Transform::worldToCamera(camera.getBaseI(), camera.getBaseJ(),
                                              camera.getBaseK(), (camera.getEye() - source));

    for(vector<int>::size_type i = 0; i < listObjects3D.size(); ++i)
    {
        Object3D & tempObj = getObject3D(i);

        for(int j = 0; j < tempObj.getNumberOfVertices(); ++j)
        {
            Vertex3 &v = tempObj.getVertex(j);
            mWTC * v;
        }
    }

    for(vector<int>::size_type i = 0; i < listLights.size(); ++i)
    {
        Light & tempLight = getLight(i);
        Point3 &p = tempLight.getPosition();
        mWTC * p;
    }
}

void Scene::rayTracing(vector< vector<RGBColor> > &view)
{
    double near;

    for(int j = 0; j < LIN_PIX; ++j)
    {
        for(int k = 0; k < COL_PIX; ++k)
        {
            Ray tt = camera.generateRay(j, k);
            Intersection temp;
            near = 100000.0;

            for(int i = 0; i < getNumberOfObjects(); ++i)
            {
                Intersection its = getObject3D(i).intersect(tt);

                if(its.isIntsc)
                {
                    if(its.getDistanceOrigin() < near)
                    {
                        near = its.getDistanceOrigin();
                        temp=its;
                    }
                }
            }

            if(temp.isIntsc)
            {
                view[j][k] = getLighting(temp);

                Point3 pLight = getLight(0).getPosition();
                Point3 pInts = temp.getIntersectionPoint();
                double dist = pInts.distance(pLight);
                Ray vl(pInts, pLight);

                for(int i = 0 ; i < getNumberOfObjects() ; ++i)
                {
                    Object3D obj = getObject3D(i);

                    if(obj.getID() != temp.getObjectID())
                    {
                        Intersection itft = obj.intersect(vl);

                        if(itft.isIntsc)
                        {
                            if(itft.getDistanceOrigin() < dist)
                            {
                                //view[j][k] = Luminance(0.0, 0.0, 0.0); // ILUMINAR COM AMBIENTE
                                view[j][k] = ambientComponent(temp.getMaterialObjIntsc());
                                break;
                            }
                        }
                    }
                }

            }
            else
            {
                // pixel background color
                view[j][k] = RGBColor(0.0, 0.0, 0.0);
            }
        }
    }
}

RGBColor Scene::getLighting(Intersection &its)
{
    Point3 pLight, pInts, pObs;
    Vector3 normal, vl, vv, vr;
    Material matIntsc;
    RGBColor tempDif, tempSpe, tempAmb;

    pLight = listLights.at(0).getPosition();
    pInts = its.getIntersectionPoint();
    pObs = Point3();

    // normal vector is perpendicular to the surface and directed outwards from the surface.
    normal = its.getNormalIntscPoint();

    // light vector points towards the light source.
    vl = (pLight-pInts).normalize();

    // view vector points in the direction of the viewer.
    vv = (pObs-pInts).normalize();

    // reflection vector indicates the direction of pure reflection of the light vector.
    vr = (normal * (2*normal.dot(vl)) - vl).normalize();

    matIntsc = its.getMaterialObjIntsc();

    RGBColor Ilig = listLights.at(0).getColor();

    RGBColor compAmb = ambientComponent(matIntsc);
    RGBColor compDif = diffuseComponent(vl, normal, Ilig, matIntsc);
    RGBColor compSpec = specularComponent(vr, vv, Ilig, matIntsc);

    /*Attenuation*/
    double dist = pInts.distance(pLight);
    Light lr = listLights.at(0);
    double attenuation = lr.getAttenuation(dist);

    return (((compDif + compSpec) * attenuation) + compAmb);
}

RGBColor Scene::ambientComponent(Material matObj3D)
{
    return (ambientEmission * matObj3D.getAmbientRefCoefficient());
}

RGBColor Scene::diffuseComponent(Vector3 vLight, Vector3 normal, RGBColor diffLight, Material matObj3D)
{
    if(vLight.dot(normal) > 0)
    {
        return (diffLight * matObj3D.getDiffuseRefCoefficient()) * vLight.dot(normal);
    }
    else
    {
        return RGBColor();
    }
}

RGBColor Scene::specularComponent(Vector3 vReflec, Vector3 vView, RGBColor specLight, Material matObj3D)
{
    if(vReflec.dot(vView) > 0)
    {
        return (specLight * matObj3D.getSpecularRefCoefficient()) * pow(vReflec.dot(vView), matObj3D.getShininessCoefficient());
    }
    else
    {
        return RGBColor();
    }
}
