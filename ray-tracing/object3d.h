#include <vector>
#include "vertex3.h"
#include "face3.h"
#include "material.h"
#include "intersection.h"

using namespace std;

#ifndef OBJECT3D_H
#define OBJECT3D_H

class Object3D
{
    public:
        Object3D(int idObj,vector<Vertex3>, vector<Face3>, Material);

        vector<Vertex3> & getListVertex();
        vector<Face3> getListFaces();

        Face3 getFace(int);
        Vertex3 & getVertex(int);
        Intersection intersect(Ray);

        int getNumberOfFaces(void);
        int getNumberOfVertices(void);
        int getID(void);

    private:
        vector<Vertex3> listVertex;
        vector<Face3> listFaces;
        Material matrl;
        int idObj;
};

#endif // OBJECT3D_H
