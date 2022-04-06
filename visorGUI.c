#include "tigr/tigr.h"

#include "guiXML.h"

#include "guiICONS.h"

#include <math.h>

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

Tigr *backdrop, *screen;
Tigr *cargarIcono(char archivo[]);
void imprimirIcono(Tigr *screen, char texto[], Tigr *icon, int posx, int posy);

#define NUMERO_ICONOS 8

int main(int argc, char *argv[])
{
    lectura(argv[1]);
    char tipoIconos[7][2][50];
    strcpy(tipoIconos[0][0],"./icons/audio.png");
    strcpy(tipoIconos[0][1],"audio");
    strcpy(tipoIconos[1][0],"./icons/calculator.png");
    strcpy(tipoIconos[1][1]," ");
    strcpy(tipoIconos[2][0],"./icons/internet.png");
    strcpy(tipoIconos[2][1],"internet");
    strcpy(tipoIconos[3][0],"./icons/notepad.png");
    strcpy(tipoIconos[3][1]," ");
    strcpy(tipoIconos[4][0],"./icons/setup.png");
    strcpy(tipoIconos[4][1],"setup");
    strcpy(tipoIconos[5][0],"./icons/terminal.png");
    strcpy(tipoIconos[5][1]," ");
    strcpy(tipoIconos[6][0],"./icons/trash.png");
    strcpy(tipoIconos[6][1],"trash");
    
    int Iconos = numIoncos();

    struct Icon iconos[NUMERO_ICONOS];
    
    for (int i = 0; i < Iconos; i++){
        iconos[i] = leerIcono(i);
    }
    // Make a window and an off-screen backdrop.
    screen = tigrWindow(320, 200, "GUI", 0);
    backdrop = tigrBitmap(screen->w, screen->h);

    // Fill in the background.
    tigrClear(backdrop, tigrRGB(255,255,255));

    // Repeat till they close the window.
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
    {
        // Composite the GUI
        tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);
        for(int i = 0; i < 7; i++){
            imprimirIcono(screen, Iconos, cargarIcono(Iconos[i][0]), i, 0);   
        }

        // Update the window.
        tigrUpdate(screen);
    }
    
    tigrFree(backdrop);
    tigrFree(screen);

return 0;
}
