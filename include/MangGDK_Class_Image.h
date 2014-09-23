#ifndef MANGGDK_CLASS_IMAGE_H_INCLUDED
#define MANGGDK_CLASS_IMAGE_H_INCLUDED

class mgImage {
public:
    mgImage();
    SDL_Texture* t;
    int h,w,f,nof;
    bool a;
};

mgImage::mgImage()
{
    a=false;
}

class mgRBG
{
public:
    mgRBG();
    int r,b,g;
    Uint32 cm(SDL_Surface* tmps)
    {
        return SDL_MapRGB(tmps->format,r,g,b);
    }
};

mgRBG::mgRBG(){
    r=0;
    b=0;
    g=0;
}



#endif // MANGGDK_CLASS_IMAGE_H_INCLUDED
