#ifndef VERTEX_H
#define VERTEX_H

class Vertex3
{
    public:
        Vertex3(int _id, double _x, double _y, double _z);
        int getID();
        double x, y, z;

    private:
        int id;
};

#endif // VERTEX_H
