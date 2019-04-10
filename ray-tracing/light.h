#include "point3.h"
#include "rgbcolor.h"
#include <math.h>

#ifndef LIGHT_H
#define LIGHT_H

class Light
{
    public:
        Light();
        Light(const Point3 &, const RGBColor &, const double, const double, const double);

        Point3 & getPosition();
        RGBColor getColor();
        double getAttenuation(double);

    private:
        Point3 lightPosition;
        RGBColor lightColor;

        double attenuationConstant;    // constant attenuation factor
        double attenuationLinear;      // linear attenuation factor
        double attenuationQuadratic;   // quadratic attenuation factor
};

#endif // LIGHT_H
