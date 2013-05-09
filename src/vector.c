#include <stdlib.h>
#include <math.h>

#include "raytracer.h"

Vector vector_create(long double x, long double y, long double z)
{
    Vector vector;
    vector.X = x;
    vector.Y = y;
    vector.Z = z;
    
    return vector;
}

Vector vector(Dot a, Dot b)
{
    return vector_create(b.X - a.X, b.Y - a.Y, b.Z - a.Z);
}

long double norm(Vector v)
{
    return (long double) sqrt((double) (v.X*v.X + v.Y*v.Y + v.Z*v.Z));
}

Vector normalize(Vector vector)
{
    long double n = norm(vector);
    return vector_create(vector.X / n, vector.Y / n, vector.Z / n);
}

Vector cross_product(Vector v, Vector w)
{
    return vector_create((v.Y * w.Z) - (v.Z * w.Y), (v.Z * w.X) - (v.X * w.Z), (v.X * w.Y) - (v.Y * w.X));
}

Vector scalar_multiplication(Vector v, long double factor)
{
    return vector_create(v.X * factor, v.Y * factor, v.Z * factor);
}
