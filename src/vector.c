#include <stdlib.h>
#include <math.h>

#include "raytracer.h"

Vector vector(Dot a, Dot b)
{
    Vector vector;
    vector.X = b.X - a.X;
    vector.Y = b.Y - a.Y;
    vector.Z = b.Z - a.Z;
    
    return vector;
}

long double norm(Vector V)
{
    long double norm = (long double) sqrt((double) (V.X*V.X + V.Y*V.Y + V.Z*V.Z));
    return norm;
}

Vector normalize_with_norm(Vector vector, long double norm)
{
    Vector result;
    result.X = vector.X / norm;
    result.Y = vector.Y / norm;
    result.Z = vector.Z / norm;
    return result;
}

Vector normalize(Vector vector)
{
    return normalize_with_norm(vector, norm(vector));
}

Vector cross_product(Vector v, Vector w)
{
    Vector product;
    product.X = (v.Y * w.Z) - (v.Z * w.Y);
    product.Y = (v.Z * w.X) - (v.X * w.Z);
    product.Z = (v.X * w.Y) - (v.Y * w.X);
    
    return product;
}

Vector scalar_multiplication(Vector v, long double factor)
{
    Vector scaled;
    scaled.X = v.X * factor;
    scaled.Y = v.Y * factor;
    scaled.Z = v.Z * factor;
    
    return scaled;
}
