#ifndef MANGGDK_MULTITHREADING_H_INCLUDED
#define MANGGDK_MULTITHREADING_H_INCLUDED

// TODO (Mangmasta#1#): Need To Finish With Programming Multithreading

/*
SDL_Thread* mgThread;
bool threaddone=false;

class TLI_ARG{
public:
    int in;
    string itl;
};

void dmgTLI(TLI_ARG a)
{
    string itl;
    int in;
    itl=a.itl;
    in=a.in;
    mgI[in] = SDL_LoadBMP(itl.c_str());
    if(mgI[in]==NULL)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif
        cout<<"Cannot load image: "<<itl<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif
    }
    threaddone=true;
}

void mgLoadImageThreaded(string itl, int in)
{
    TLI_ARG a;
    a.in=in;
    a.itl=itl;
    mgThread = SDL_CreateThread(dmgTLI, "dmgTLI", (void*)void);
    if(mgThread==NULL)
    {
        #ifdef _WIN32
        SetColor(RED);
        #endif
        cout<<"Failed to Create another thread, loading image normally."<<endl;
        #ifdef _WIN32
        SetColor(GRAY);
        #endif

        mgLoadImage(itl,in);
    }
    else
    {
        threaddone=false;
    }
}

bool mgThreadDone()
{
    if(threaddone&&mgThread!=NULL)
    {
        SDL_WaitThread(mgThread, NULL);
    }
    return threaddone;
}
*/
#endif // MANGGDK_MULTITHREADING_H_INCLUDED
