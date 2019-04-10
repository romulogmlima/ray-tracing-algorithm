#include "object3d.h"

Object3D::Object3D(int idObj, vector<Vertex3> listVertex, vector<Face3> listFaces, Material matrl)
{
    this->idObj = idObj;
    this->listVertex = listVertex;
    this->listFaces = listFaces;
    this->matrl = matrl;
}

Face3 Object3D::getFace(int index)
{
    return listFaces.at(index);
}

int Object3D::getNumberOfFaces()
{
    return listFaces.size();
}

Vertex3 & Object3D::getVertex(int index)
{
    return listVertex.at(index);
}

int Object3D::getNumberOfVertices()
{
    return listVertex.size();
}

vector<Vertex3> & Object3D::getListVertex()
{
    return listVertex;
}

vector<Face3> Object3D::getListFaces()
{
    return listFaces;
}

int Object3D::getID()
{
    return idObj;
}

Intersection Object3D::intersect(Ray ray)
{
    int temp = 0;
    double near = 100000.0;
    double out;
    Intersection its;

    for(int i = 0; i < getNumberOfFaces(); ++i)
    {
        Face3 f = getFace(i);

        Vertex3 v1 = getVertex(f.getIDVertex1());
        Vertex3 v2 = getVertex(f.getIDVertex2());
        Vertex3 v3 = getVertex(f.getIDVertex3());

        Point3 p1(v1.x, v1.y, v1.z);
        Point3 p2(v2.x, v2.y, v2.z);
        Point3 p3(v3.x, v3.y, v3.z);

        temp = 0;
        out = 0.f;

        //Find vectors for two edges sharing V1
        Vector3 e1 = p2-p1;
        Vector3 e2 = p3-p1;

        //Normal vector
        Vector3 normal = (e1.cross(e2)).normalize();

        double flag = (normal.dot(ray.getDirection()) / (normal.length()*(ray.getDirection()).length()));

        if(flag <= 0.0f)
        {
            temp = f.intersect(ray, p1, p2, p3, &out);
        }

        if(temp == 1)
        {
            if(out < near)
            {
                near = out;
                Vector3 vtemp = (ray.getDirection()) * out;

                its.isIntsc = true;
                its.setIntersectionPoint(Point3(vtemp.x, vtemp.y, vtemp.z));
                its.setDistanceOrigin(near);
                its.setMaterialObjIntsc(this->matrl);
                its.setNormalIntscPoint(f.getNormal());
                its.setObjectID(this->idObj);
            }
        }
    }

    return its;
}
