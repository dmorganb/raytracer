#include <stdio.h>
#include "raytracer.h"

/*Assumes direction is a unitary vector*/
Dot translate(Dot dot, Vector direction, long double magnitude)
{
    Vector t = scalar_multiplication(direction, magnitude);
    Dot translated;
    
    translated.X = dot.X + t.X;
    translated.Y = dot.Y + t.Y;
    translated.Z = dot.Z + t.Z;
    
    return translated;
}

Dot nvu_xyz(Dot nvu)
{
    Dot xyz = translate(Settings.Vrp, Settings.Vrc_n, nvu.Z);
    xyz = translate(xyz, Settings.Vrc_u, nvu.Y);
    xyz = translate(xyz, Settings.Vrc_v, nvu.X);
    
    return xyz;
}

Dot get_window_dot(int i, int j) 
{
    Dot w;

    w.X = ((long double)(j) + 0.5) / (long double)(Settings.Framebuffer_width);
    w.X *= (Settings.Window_max.X - Settings.Window_min.X);
    w.X += Settings.Window_min.X;

    w.Y = ((long double)(i) + 0.5) / (long double)(Settings.Framebuffer_height);
    w.Y *= (Settings.Window_max.Y - Settings.Window_min.Y);
    w.Y += Settings.Window_min.Y;

    w.Z = 0.0;
    printf("w en nvu = (%Lf, %Lf, %Lf)\n", w.X, w.Y, w.Z);
       
    return nvu_xyz(w);
}

Color get_color(Dot dot, Vector ray)
{
    Color color;
    return color;
}

Color explore(Dot dot)
{
    Dot eye = nvu_xyz(Settings.Eye);
    Vector ray = vector(eye, dot);
    ray = normalize(ray);

    return (get_color(eye, ray));
}

void plot(int i, int j, Color color)
{
    if((0 <= i && i < Settings.Framebuffer_height) && (0 <= j && j < Settings.Framebuffer_width))
    {
        Framebuffer[i][j] = color;
    }
    else
    {
        fprintf(stderr, "error: plot: i = %i, j = %i\n", i, j);
    }
}

void raytracer()
{
    int i, j;
    
    for (i = 0; i < Settings.Framebuffer_height; i++)
    {
        for (j = 0; j < Settings.Framebuffer_width; j++)
        {
            Dot w = get_window_dot(i, j);
            Color color = explore(w);
            printf("i = %i, j=%i\n", i, j);
            printf("w = (%Lf, %Lf, %Lf)\n", w.X, w.Y, w.Z);
            plot(i, j, color);
        }
    }
}
