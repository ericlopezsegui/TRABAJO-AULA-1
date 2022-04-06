#include "tigr/tigr.h"

#include "parser.h"

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

Tigr *cargarIcono(char archivo[]){   
    Tigr *icon = tigrLoadImage(archivo);
    if (!icon)
        tigrError(0, "Cannot load icon");
    return icon;
}

void imprimirIcono(Tigr *screen, char texto[], Tigr *icon, int posx, int posy){
    tigrBlitAlpha(screen, icon, posx*40, posy*40,0,0, icon->w, icon->h, 1.0f);
    tigrPrint(screen, tfont, posx*40, posy*40 + 32, tigrRGB (0,0,0), texto);
}