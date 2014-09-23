#include "MangGDK.h"
#include <iostream>

using namespace std;

int main(int argc, char* args[])
{
    mgInit(960,720,"ShadowChildren");

    mgSetColorKey(21, 21, 21);
    mgLoadImage("media/dude.png", 1);
    mgMakeAnimated(1,4);

    int character_x =0;

    while(mgRunning())
    {
        if(mgRightKey())
        {
            character_x=character_x+1;
        }
        if(mgLeftKey())
        {
            character_x=character_x-1;
        }
        mgPasteImage(1, character_x, 0);
        mgSync();
    }

    return 0;
}
