#include "rgbcolor.h"

RGBColor::RGBColor() : red(0.0), green(0.0), blue(0.0)
{

}

RGBColor::RGBColor(double _c) : red(_c), green(_c), blue(_c)
{

}

RGBColor::RGBColor(double _red, double _green, double _blue) : red(_red), green(_green), blue(_blue)
{

}

RGBColor RGBColor::operator+ (const RGBColor &c) const
{
    return RGBColor(red + c.red, green + c.green, blue + c.blue);
}

RGBColor& RGBColor::operator+= (const RGBColor &c)
{
    red += c.red;
    green += c.green;
    blue += c.blue;

    return (*this);
}

RGBColor RGBColor::operator * (const double scalar) const
{
    return RGBColor(red * scalar, green * scalar, blue * scalar);
}

RGBColor& RGBColor::operator*= (const double scalar)
{
    red *= scalar;
    green *= scalar;
    blue *= scalar;

    return (*this);
}

RGBColor RGBColor::operator/ (const double scalar) const
{
    return RGBColor(red/scalar, green/scalar, blue/scalar);
}

RGBColor& RGBColor::operator/= (const double scalar)
{
    red /= scalar;
    green /= scalar;
    blue /= scalar;

    return (*this);
}

RGBColor RGBColor::operator* (const RGBColor &c) const
{
    return RGBColor (red * c.red, green * c.green, blue * c.blue);
}


bool RGBColor::operator== (const RGBColor& c) const
{
    return ((red == c.red) && (green == c.green) && (blue == c.blue));
}
