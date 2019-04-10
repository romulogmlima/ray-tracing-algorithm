#include "material.h"

Material::Material()
{
    Material(RGBColor(0.0,0.0,0.0), RGBColor(0.0,0.0,0.0), RGBColor(0.0,0.0,0.0), 10.0);
}

Material::Material(const RGBColor &_ka , const RGBColor &_kd , const RGBColor &_ks, const double _shCoef)
{
    this->ka = _ka;
    this->kd = _kd;
    this->ks = _ks;
    this->shininess = _shCoef;
}

RGBColor Material::getAmbientRefCoefficient()
{
    return ka;
}

RGBColor Material::getDiffuseRefCoefficient()
{
    return kd;
}

RGBColor Material::getSpecularRefCoefficient()
{
    return ks;
}

double Material::getShininessCoefficient()
{
    return shininess;
}
