#include <stdlib.h>

#include "raytracer.h"

AppSettings Settings;

Dot dot_create(long double x, long double y, long double z)
{
    Dot dot;
    dot.X = x;
    dot.Y = y;
    dot.Z = z;
    
    return dot;
}

void load_settings()
{
    /*TODO load this from an scene file*/
    Settings.Framebuffer_height = 2;
    Settings.Framebuffer_width = 2;
    Settings.Vrp = dot_create(0.0, 0.0, -1.0);
    Settings.Viewplane_normal = vector_create(0.0, 0.0, 1.0);
    Settings.Vector_up = vector_create(0.0, 1.0, 0.0);
    Settings.Window_min = dot_create(-1.0, -1.0, 0.0);
    Settings.Window_max = dot_create(1.0, 1.0, 0.0);
    Settings.Eye = dot_create(0.0, 0.0, -4.0);
    
    Settings.Vrc_n = vector_create(0.0, 0.0, 1.0);
    Settings.Vrc_u = vector_create(0.0, 1.0, 0.0);
    Settings.Vrc_v = vector_create(1.0, 0.0, 0.0);
}

int main(int argc, char* argv[])
{
    /*init Settings*/
    load_settings();
    
    
    framebuffer_create();
    
    raytracer();
  
    framebuffer_destroy();
    
    return EXIT_SUCCESS;
}