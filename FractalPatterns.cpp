#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;
class Koch
{
public:
    void koch(int x_coord_1, int y_coord_1, int x_coord_2, int y_coord_2, int m_angle, int it)
    {
        float angle = m_angle*M_PI/180;
        int x3 = (2*x_coord_1+x_coord_2)/3;
        int y3 = (2*y_coord_1+y_coord_2)/3;

        int x4 = (x_coord_1+2*x_coord_2)/3;
        int y4 = (y_coord_1+2*y_coord_2)/3;

        int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
        int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

        if(it > 0)
        {
            koch(x_coord_1, y_coord_1, x3, y3, m_angle, it-1);
            koch(x3, y3, x, y, m_angle, it-1);
            koch(x, y, x4, y4, m_angle, it-1);
            koch(x4, y4, x_coord_2, y_coord_2, m_angle, it-1);
        }
        else
        {
            line(x_coord_1, y_coord_1, x_coord_2, y_coord_2);
        }
    }
};
class Hilbert
{
public:
    void move(int j,int h,int&x,int&y)
    {
        if(j==1)
            y-=h;
        else if(j==2)
            x+=h;
        else if(j==3)
            y+=h;
        else if(j==4)
            x-=h;
        lineto(x,y);
    }
    void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y)
    {
        if(i>0)
        {
            i--;
            hilbert(d,r,u,l,i,h,x,y);
            move(r,h,x,y);
            hilbert(r,d,l,u,i,h,x,y);
            move(d,h,x,y);
            hilbert(r,d,l,u,i,h,x,y);
            move(l,h,x,y);
            hilbert(u,l,d,r,i,h,x,y);
        }
    }
};

int main()
{
    int n, x0=50, y0=150, x, y, h=10, r=2, d=3, l=4, u=1, ch;
    char ans;

    initwindow(800,800,"CGOOP");

    Koch k;
    Hilbert H;

    do{
        cleardevice();
        cout << "\n1. Generate Koch Curve\n2. Generate Hilbert Curve\n3. Generate SnowFlake by Koch Curve\nEnter choice: ";
        cin >> ch;
        cout << endl;
        int it;
        double x_1 = 118.5, y_1 = 455.72, x_2 = 481.5, y_2 = 455.72, l1_angle = -60, x_3 = 300, y_3 = 141.36;
        int x_coord_1 = 100, x_coord_2 = 400, y_coord_1 = 100, y_coord_2 = 400;
        switch (ch) {
            case 1:
                cout<<"Enter no. of iteration(s): \t";
                cin>>it;
                k.koch(x_coord_1, y_coord_1, x_coord_2, y_coord_2, -l1_angle, it);
                break;

            case 2:
                cout<<"Give the value of n:\t";
                cin>>n;
                x=x0;
                y=y0;
                moveto(x,y);
                H.hilbert(r,d,l,u,n,h,x,y);
                break;

            case 3:
                cout<<"Enter no. of iteration(s): \t";
                cin>>it;
                k.koch(x_1, y_1, x_2, y_2, l1_angle, it);
                k.koch(x_2, y_2, x_3, y_3, l1_angle, it);
                k.koch(x_3, y_3, x_1, y_1, l1_angle, it);
                break;
        }
        cout<<"\nDo u want to continue...";
        cin>>ans;
    }while(ans=='y'||ans=='Y');

    delay(1000);
    closegraph();

}
