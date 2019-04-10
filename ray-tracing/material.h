#include "rgbcolor.h"

#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
    public:
        Material();
        Material(const RGBColor &, const RGBColor &, const RGBColor &, const double);

        RGBColor getAmbientRefCoefficient();
        RGBColor getDiffuseRefCoefficient();
        RGBColor getSpecularRefCoefficient();
        double getShininessCoefficient();

    private:
        RGBColor ka;   // ambient reflection coefficient
        RGBColor kd;   // diffuse reflection coefficient
        RGBColor ks;   // specular reflection coefficient

        double shininess;  // shininess coefficient
};

#endif // MATERIAL_H
