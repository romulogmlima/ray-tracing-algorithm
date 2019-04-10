#include <iostream>
#include <fstream>
#include <iomanip>

#include "readfile.h"

ReadFile::ReadFile()
{

}

vector<Vertex3> ReadFile::importListVertex(string pathFile)
{
    ifstream myfile (pathFile.c_str());
    vector<Vertex3> listVertex;

    if (myfile.is_open())
    {
        int id;
        double x,y,z;

        while( myfile >> id >> x >> y >>z)
        {
            Vertex3 v(id, x, y, z);
            listVertex.push_back(v);
        }

        myfile.close();

    }
    else
    {
        cout << "Unable to open file";
    }

    return listVertex;
}

vector<Face3> ReadFile::importListFaces(string pathFile)
{
    ifstream myfile (pathFile.c_str());
    vector<Face3> listFaces;

    if (myfile.is_open())
    {
        int ind;
        int v1, v2, v3;

        while( myfile >> ind >> v1 >> v2 >> v3)
        {
            Face3 f(ind, v1, v2, v3);
            listFaces.push_back(f);
        }

        myfile.close();

    }
    else
    {
        cout << "Unable to open file";
    }

    return listFaces;
}
