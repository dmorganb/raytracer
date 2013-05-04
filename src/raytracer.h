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
    Dot Window_min;
    Dot Window_max;
} AppSettings;

extern AppSettings Settings;

Vector vector(Dot a, Dot b);
long double norm(Vector v);
Vector normalize_with_norm(Vector vector, long double norm);
Vector normalize(Vector vector);

void raytracer();
