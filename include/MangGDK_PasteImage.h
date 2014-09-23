#ifndef MANGGDK_PASTEIMAGE_H_INCLUDED
#define MANGGDK_PASTEIMAGE_H_INCLUDED

void mgPasteImage(int in, int x, int y)
{
    SDL_Rect tmppos;
    SDL_Rect tmpcut;
    int erc;
    tmppos.x = x;
    tmppos.y = y;
    tmppos.w = mgI[in].w;
    tmppos.h = mgI[in].h;
    if(!mgI[in].a)
    {
        erc=SDL_RenderCopy( mgRenderer, mgI[in].t, NULL, &tmppos );
    }
    else
    {
        tmpcut.w=mgI[in].w/mgI[in].nof;
        tmpcut.h=mgI[in].h;
        tmpcut.y=0;
        tmpcut.x=tmpcut.w*mgI[in].f;
        tmppos.w=tmpcut.w;
        SDL_RenderCopy( mgRenderer, mgI[in].t, &tmpcut, &tmppos );
    }
    if(erc!=0)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif // _WIN32
        cout<<"Error Pasting Image: "<<in<<endl;
        cout<<SDL_GetError()<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif // _WIN32
    }

}

#endif // MANGGDK_PASTEIMAGE_H_INCLUDED
