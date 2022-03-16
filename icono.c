#include "tigr/tigr.h"

#include "parser.h"

#include <math.h>

#include <stdio.h>

#include <stdlib.h>

Tigr *backdrop, *screen;

int main(int argc, char *argv[])
{
    readfile();
    
    // Load our sprite.

    Tigr *trash = tigrLoadImage("./icons/trash.png");
    if (!trash)
        tigrError(0, "Cannot load trash");

    Tigr *terminal = tigrLoadImage("./icons/terminal.png");
    if (!terminal)
        tigrError(0, "Cannot load terminal");
    
    Tigr *setup = tigrLoadImage("./icons/setup.png");
    if (!setup)
        tigrError(0, "Cannot load setup");
    
    Tigr *notepad = tigrLoadImage("./icons/notepad.png");
    if (!notepad)
        tigrError(0, "Cannot load notepad");
    
    Tigr *internet = tigrLoadImage("./icons/internet.png");
    if (!internet)
            tigrError(0, "Cannot load internet");

    Tigr *calculator = tigrLoadImage("./icons/calculator.png");
    if (!calculator)
        tigrError(0, "Cannot load calculator");

    Tigr *audio = tigrLoadImage("./icons/audio.png");
    if (!audio)
        tigrError(0, "Cannot load audio");
    
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

        //dibuja trash
        tigrBlitAlpha(screen, trash, 32, 64, 0, 0, trash->w, trash->h, 1.0f);

        //dibuja terminal
        tigrBlitAlpha(screen, terminal, 64, 64, 0, 0, terminal->w, terminal->h, 1.0f);
        
        //dibuja setup
        tigrBlitAlpha(screen, setup, 96, 64, 0, 0, setup->w, setup->h, 1.0f);
        
        //dibuja notepad
        tigrBlitAlpha(screen, notepad, 128, 64, 0, 0, notepad->w, notepad->h, 1.0f);

        //dibuja internet
        tigrBlitAlpha(screen, internet, 160, 64, 0, 0, internet->w, internet->h, 1.0f);

        //dibuja calculator
        tigrBlitAlpha(screen, calculator, 192, 64, 0, 0, calculator->w, calculator->h, 1.0f);
        
        //dibuja audio
        tigrBlitAlpha(screen, audio, 224, 64, 0, 0, audio->w, audio->h, 1.0f);

        // Update the window.
        tigrUpdate(screen);
    }
    
    tigrFree(trash);
    tigrFree(terminal);
    tigrFree(setup);
    tigrFree(notepad);
    tigrFree(internet);
    tigrFree(calculator);
    tigrFree(audio);
    tigrFree(backdrop);
    tigrFree(screen);

return 0;
}
