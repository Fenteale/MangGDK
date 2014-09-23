#ifndef MANGGDK_INPUT_H_INCLUDED
#define MANGGDK_INPUT_H_INCLUDED
bool downkeypressed;
bool upkeypressed;
bool leftkeypressed;
bool rightkeypressed;

void mg_InitKeys()
{
    downkeypressed = false;
    upkeypressed = false;
    leftkeypressed = false;
    rightkeypressed = false;
}

void mg_ParseInput()
{
    if(mgEvents.type == SDL_KEYDOWN )
    {
        switch (mgEvents.key.keysym.sym)
        {
            case SDLK_DOWN:
            downkeypressed = true;
            break;

            case SDLK_UP:
            upkeypressed = true;
            break;

            case SDLK_LEFT:
            leftkeypressed = true;
            break;

            case SDLK_RIGHT:
            rightkeypressed = true;
            break;
        }
    }
    else if(mgEvents.type == SDL_KEYUP )
    {
        switch (mgEvents.key.keysym.sym)
        {
            case SDLK_DOWN:
            downkeypressed = false;
            break;

            case SDLK_UP:
            upkeypressed = false;
            break;

            case SDLK_LEFT:
            leftkeypressed = false;
            break;

            case SDLK_RIGHT:
            rightkeypressed = false;
            break;
        }
    }

}

bool mgDownKey()
{
    return downkeypressed;
}

bool mgUpKey()
{
    return upkeypressed;
}

bool mgLeftKey()
{
    return leftkeypressed;
}

bool mgRightKey()
{
    return rightkeypressed;
}

#endif // MANGGDK_INPUT_H_INCLUDED
