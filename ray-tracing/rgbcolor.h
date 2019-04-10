#ifndef COLOR_H
#define COLOR_H

class RGBColor
{
    public:
        RGBColor();
        RGBColor(double _c);
        RGBColor(double _red, double _green, double _blue);

        RGBColor operator+ (const RGBColor & c) const;	 // addition
        RGBColor& operator+= (const RGBColor & c);       // compound addition
        RGBColor operator* (const RGBColor & c) const;   // component-wise multiplication
        bool operator== (const RGBColor & c) const;      // are these two colours the same?

        RGBColor operator * (const double scalar) const;  // multiplication by a double variable on the right
        RGBColor& operator*= (const double scalar);       // compound multiplication by a double variable on the right
        RGBColor operator/ (const double scalar) const;   // division by a double variable
        RGBColor& operator/= (const double scalar);       // compound division by a double variable

        double red;
        double green;
        double blue;
};

#endif // COLOR_H

