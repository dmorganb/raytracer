#include "raytracer.h"

Dot get_pixel(int i, int j) 
{
    Dot w;

    w.X = ((long double)(j) + 0.5) / (long double)(Settings.Framebuffer_width);
    w.X *= (Settings.Window_max.X - Settings.Window_min.X);
    w.X += Settings.Window_min.X;

    w.Y = ((long double)(i) + 0.5) / (long double)(Settings.Framebuffer_height);
    w.Y *= (Settings.Window_max.Y - Settings.Window_min.Y);
    w.Y += Settings.Window_min.Y;

    w.Z = ((long double)(i) + 0.5) / (long double)(Settings.Framebuffer_height);
    w.Z *= (Settings.Window_max.Y - Settings.Window_min.Y);
    w.Z += Settings.Window_min.Y;
    
    return w;
}

Color get_color(Dot dot, Vector ray)
{
    Color color;
    return color;
}

Color explore(Dot dot)
{
    Dot eye;
    Vector ray = vector(eye, dot);
    ray = normalize(ray);

    return (get_color(eye, ray));
}

void raytracer()
{
    int i, j;
    
    for (i = 0; i < Settings.Framebuffer_height; i++)
    {
        for (j = 0; j < Settings.Framebuffer_width; j++)
        {
            Dot w = get_pixel(i, j);
            Color color = explore(w);
        }
    }
}
