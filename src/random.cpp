#include"random.h"
void srrand(int seed)
{
    rrand_index=0;
    rrand_init=1;
    rrand_mt[0]=seed;
    for(int i=1;i<624;i++)
    {
        int t=1812433253*(rrand_mt[i-1]^(rrand_mt[i-1]>>30))+i;
        rrand_mt[i]=t&0xffffffff;
    }
}
void rrand_generate()
{
    for(int i=0;i<624;i++)
    {
        int y=(rrand_mt[i]&0x80000000)+(rrand_mt[(i+1)%624]&0x7fffffff);
        rrand_mt[i]=rrand_mt[(i+397)%624]^(y>>1);
        if(y&1)rrand_mt[i]^=2567483615;
    }
}
int rrand()
{
    if(!rrand_init)srrand(time(nullptr));
    if(rrand_index==0)rrand_generate();
    int y=rrand_mt[rrand_index];
    y=y^(y>>11);
    y=y^((y<<7)&2636928640);
    y=y^((y<<15)&4022730752);
    y=y^(y>>18);
    rrand_index=(rrand_index+1)%624;
    return y;
}
