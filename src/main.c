#include <stdlib.h>

#include "raytracer.h"

AppSettings Settings;
Color** Framebuffer;

int main(int argc, char* argv[])
{
    /*init Settings*/
    int i;
    Settings.Framebuffer_height = 600;
    Settings.Framebuffer_width = 800;
    
    Framebuffer = (Color**) malloc(sizeof(Color*) * Settings.Framebuffer_height);
    
    for(i = 0; i < Settings.Framebuffer_height; i++) 
    {
        Framebuffer[i] = (Color*) malloc(sizeof(Color) * Settings.Framebuffer_width);
    }
    
    raytracer();
  
    for(i = 0; i < Settings.Framebuffer_height; i++) 
    {
        free(Framebuffer[i]);
    }

    free(Framebuffer);
    
    return EXIT_SUCCESS;
}