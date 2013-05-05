#ifndef _RAYTRACER_HEADER_
#define _RAYTRACER_HEADER_

#define EPSILON 0.00000001

typedef struct
{
    long double X;
    long double Y;
    long double Z;
} Dot;

typedef struct
{
    long double R;
    long double G;
    long double B;
} Color;

typedef struct
{
    long double X;
    long double Y;
    long double Z;
} Vector;

typedef struct
{
    int Framebuffer_height;
    int Framebuffer_width;
    /*Camera Settings*/
    Dot Vrp;
    Vector Viewplane_normal;
    Vector Vector_up;
    Dot Window_min;
    Dot Window_max;
    Dot Eye;
    Vector Vrc_n;
    Vector Vrc_u;
    Vector Vrc_v;
} AppSettings;

extern AppSettings Settings;
extern Color** Framebuffer;

Vector vector(Dot a, Dot b);
long double norm(Vector v);
Vector normalize_with_norm(Vector vector, long double norm);
Vector normalize(Vector vector);
Vector cross_product(Vector, Vector);
Vector scalar_multiplication(Vector v, long double factor);

void raytracer();
#endif
