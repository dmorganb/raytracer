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
