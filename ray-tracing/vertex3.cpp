#include "vertex3.h"

Vertex3::Vertex3(int _id, double _x, double _y, double _z) : x(_x), y(_y), z(_z), id(_id)
{

}

int Vertex3::getID()
{
    return id;
}

