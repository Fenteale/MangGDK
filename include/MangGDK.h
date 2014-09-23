#ifndef MANGGDK_H_INCLUDED
#define MANGGDK_H_INCLUDED

#define MG_MAX_IMAGES 100


#ifdef _WIN32
#include "windows.h"
#include "SDL\SDL.h"
#include "SDL\SDL_Image.h"
#endif // _WIN32

#include <iostream>
#include "MangGDK_Class_Image.h"




//SDL_Surface* mgI[MG_MAX_IMAGES];
mgImage mgI[MG_MAX_IMAGES];
mgRBG mgCMap;
SDL_Window* mgWindow = NULL;
SDL_Surface* mgScreen = NULL;
SDL_Renderer* mgRenderer = NULL;
SDL_Event mgEvents;
bool running = false;
int mgScaleX, mgScaleY;

#ifdef _WIN32
HANDLE hCon;
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c){
        if(hCon == NULL)
                hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hCon, c);
}
#endif

//###### BEGIN LONG LIST OF INCLUDES ##############

#include "MangGDK_LoadImage.h"
#include "MangGDK_PasteImage.h"
#include "MangGDK_Sync.h"
#include "MangGDK_MultiThreading.h"
#include "MangGDK_MakeAnimated.h"
#include "MangGDK_Input.h"

//###### END LONG LIST OF INCLUDES #############

using namespace std;





void mgSetUpscale(int tx, int ty)
{
    mgScaleX=tx;
    mgScaleY=ty;
}

void mgInit(int sw, int sh, string winname)
{
    cout<<"Initializing MangGDK"<<endl;
    running=true;
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif // _WIN32
        cout<<"Error Initializing SDL"<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif // _WIN32
        running=false;
    }
    mgWindow = SDL_CreateWindow( winname.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sw, sh, SDL_WINDOW_SHOWN );
    if(mgWindow == NULL)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif // _WIN32
        cout<<"Error Initializing the Window!"<<endl;
        cout<<SDL_GetError()<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif // _WIN32
        running=false;
    }
    //mgScreen = SDL_GetWindowSurface( mgWindow ); //OLD WAY OF DOING THE SCREEN STUFF
    mgRenderer = SDL_CreateRenderer( mgWindow, -1, SDL_RENDERER_ACCELERATED );
    if(mgRenderer == NULL)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif // _WIN32
        cout<<"Error Initializing the Renderer!"<<endl;
        cout<<SDL_GetError()<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif // _WIN32
        running=false;
    }

    if( !IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG )
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif // _WIN32
        cout<<"Error Initializing PNG Loading!"<<endl;
        cout<<SDL_GetError()<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif // _WIN32
    }

    mg_InitKeys();


    if(running)
    {
        cout<<"Successfully Initialized MangGDK!"<<endl;
    }

}

void mgInit()
{
    mgInit(640, 480, "MangGDK Application");
}

void mgClose()
{
    /* ################### FIX THIS PART ################
    for(int x=0;x<=MG_MAX_IMAGES;x++)
    {
        if(mgI[x].t!=NULL)
        {
            SDL_DestroyTexture(mgI[x].t);
        }
    }
    */
    cout<<"Destroyed all Textures.."<<endl;
    SDL_DestroyWindow(mgWindow);
    mgWindow=NULL;

    SDL_Quit();
    running = false;
}


#endif // MANGGDK_H_INCLUDED
