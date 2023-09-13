#include<graphics.h>
#include<direct.h>
int main()
{
    int gd=DETECT,gm=DETECT,x=0,state=0,y=450,up_limit=45;
    initgraph(&gd,&gm,NULL);
    while(!kbhit())
    {
        if(state==0)
        {
            y+=2;
            x+=1;
            if(y>=400)
                state=1;
        }
        if(state==1)
        {
            y-=2;
            x+=1;
            if(y<=up_limit)
            {
                state=0;
            }
        }
        fillellipse(x,y,15,15);
        delay(15);
        fillellipse(x,y,15,15);
        cleardevice();
    }
    getch();
    return 0;
}
