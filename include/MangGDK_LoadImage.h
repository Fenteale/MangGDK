#ifndef MANGGDK_LOADIMAGE_H_INCLUDED
#define MANGGDK_LOADIMAGE_H_INCLUDED
#include <string>

using namespace std;

void mgLoadImage(string itl, int in)
{
    SDL_Surface* ts= IMG_Load(itl.c_str());
    if(ts==NULL)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif
        cout<<"Cannot load image: "<<itl<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif
    }
    mgI[in].h=ts->h;
    mgI[in].w=ts->w;
    SDL_SetColorKey(ts, SDL_TRUE, mgCMap.cm(ts));
    mgI[in].t = SDL_CreateTextureFromSurface( mgRenderer, ts );
    if(mgI[in].t==NULL)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif
        cout<<"Couldn't make a texture from the image: "<<itl<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif
    }
    SDL_FreeSurface( ts );
}

void mgSetColorKey(int r, int b, int g)
{
    mgCMap.r=r;
    mgCMap.b=b;
    mgCMap.g=g;
}

#endif // MANGGDK_LOADIMAGE_H_INCLUDED
