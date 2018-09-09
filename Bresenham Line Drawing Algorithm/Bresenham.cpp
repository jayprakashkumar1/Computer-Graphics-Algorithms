// Bresenham's line algorithm 

// header files 
#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
    int gd,gm,i;
    gd=DETECT;

    int x1,y1,x2,y2,x,y;
    float dy,dx,m;

// Inputs
// two points (x1,y1) and (x2,y2)
    printf("enter value of x1 and y1 : ");
    scanf("%d%d",&x1,&y1);
    printf("enter value of x2 and y2 : ");
    scanf("%d%d",&x2,&y2);

// initiate graphics after taking inputs
    initgraph(&gd,&gm,NULL);

    dx=abs(x2-x1);
    dy=abs(y2-y1);

        m=dy/dx;          // slope

// three cases: 
// m<1 or m>1 or m=1 

x=x1,y=y1;         // initial points 

if(m<1)                       //m<1
{    int Xmax=x2>x1?x2:x1;
    
    float   p=2*y-dx;     // initial decision parameter

    for(;x<=Xmax;x++)         //loop 
    {
        if(p>0)
        {
            putpixel(x,y,GREEN);     // pixel ON at (x,y) 
            y++;
            p=p+2*dy-dx;           // next decision parameter 
        }
        else
            {
                putpixel(x,y,GREEN);
                p=p+2*y;               // next decision parameter
           }
           delay(100);  // making delaying to draw line 
    }
}    
else if(m>1)         // m>1         // just interchange x and y 
{    int ymax=y2>y1?y2:y1;
     float   p=2*x-dy;     
    for(;y<=ymax;y++)      
    {
        if(p>0)
        {
            putpixel(x,y,GREEN);
            x++;
            p=p+2*dx-dy;
        }
        else
            {
                putpixel(x,y,GREEN);
                p=p+2*x;
           }
           delay(100);
    }
}
else       // m=1
{
    for(int i=1;i<=dx;i++)         // i<=dx or i<=dy
   { putpixel(x++,y++,GREEN);       // both x and y increases 
     delay(100);
   }
}    
        delay(100000);     // delay
        closegraph(); //deallocating all memory from graphics mode     
    return 0;
}


// In Terminal
// To compile :  g++ Bresenham.cpp -lgraph
// To Run :  ./a.out
