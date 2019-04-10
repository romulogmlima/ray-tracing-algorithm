#include <iostream>
#include "light.h"

using namespace std;

Light::Light()
{
    Point3(50.0, 0.0, 0.0);
    RGBColor(1.0, 1.0, 1.0);
    attenuationConstant = 1.0;
    attenuationLinear = 0.0;
    attenuationQuadratic = 0.0;
}

Light::Light(const Point3 &_mLightPoint, const RGBColor &_mLightColor,
             const double _attConstant, const double _attLinear, const double _attQuadratic)
{
    this->lightPosition = _mLightPoint;
    this->lightColor = _mLightColor;

    this->attenuationConstant = _attConstant;
    this->attenuationLinear = _attLinear;
    this->attenuationQuadratic = _attQuadratic;
}

Point3 & Light::getPosition()
{
    return lightPosition;
}

RGBColor Light::getColor()
{
    return lightColor;
}

double Light::getAttenuation(double dist)
{
    return (1.0 / (attenuationConstant + attenuationLinear * dist +
                   attenuationQuadratic * pow(dist, 2.0f)));
}
