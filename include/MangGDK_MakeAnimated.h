#ifndef MANGGDK_MAKEANIMATED_H_INCLUDED
#define MANGGDK_MAKEANIMATED_H_INCLUDED

void mgMakeAnimated(int in, int nos)
{
    mgI[in].a=true;
    mgI[in].nof=nos;
    mgI[in].f=0;
}

#endif // MANGGDK_MAKEANIMATED_H_INCLUDED
