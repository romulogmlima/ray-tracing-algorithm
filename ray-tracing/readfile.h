#include <string>
#include <vector>

#include "vertex3.h"
#include "face3.h"

#ifndef READFILE_H
#define READFILE_H

using namespace std;

class ReadFile
{
    public:
        ReadFile();

        static vector<Vertex3> importListVertex(string pathFile);
        static vector<Face3> importListFaces(string pathFile);
};

#endif // READFILE_H
