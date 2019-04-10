#include <vector>

#include "object3d.h"
#include "camera.h"
#include "transform.h"
#include "intersection.h"
#include "light.h"

#ifndef SCENE_H
#define SCENE_H

class Scene
{
    public:
        Scene(Camera, RGBColor);

        void addLight(const Light &);
        void addObject3D(const Object3D &);

        int getNumberOfObjects(void);
        Object3D & getObject3D(int);
        Light & getLight(int);

        void changeCoordinateSystemsWTC(void);
        void applyTransformation(int, const Transform);
        void rayTracing(vector< vector<RGBColor> > &);

    private:
        vector<Light> listLights;
        vector<Object3D> listObjects3D;
        Camera camera;
        RGBColor ambientEmission; // global ambient term

        RGBColor getLighting(Intersection &);
        RGBColor ambientComponent(Material);
        RGBColor diffuseComponent(Vector3, Vector3, RGBColor, Material);
        RGBColor specularComponent(Vector3, Vector3, RGBColor, Material);
};

#endif // SCENE_H
