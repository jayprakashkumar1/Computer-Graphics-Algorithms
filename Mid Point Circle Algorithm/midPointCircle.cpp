// mid point circle algorithm 
// Header files
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void midPointCircle(int Xc,int Yc,int r)
{
    int x=0,y=r;          // initially drawing  from top point 
    int p=1-r;            // initial decision parameter

    // for 1 (x,y) point, draw all symmetric points in 8 octet
       do
     {
         putpixel(Xc+x,Yc+y,GREEN);          // 1st octet pixels
         putpixel(Xc+y,Yc+x,GREEN);            // 2nd octet pixels
         putpixel(Xc+y,Yc-x,GREEN);            // 3rd octet pixels
         putpixel(Xc+x,Yc-y,GREEN);            // 4th octet pixels
         putpixel(Xc-x,Yc-y,GREEN);              // 5th octet pixels
         putpixel(Xc-y,Yc-x,GREEN);               // 6th octet pixels
         putpixel(Xc-y,Yc+x,GREEN);               // 7th octet pixels
         putpixel(Xc-x,Yc+y,GREEN);               // 8th octet pixels

        if(p>=0)
        {   // next points
              y--;             // Yk-1     
              p=p+2*(x-y)+1;          // here x means Xk+1, y means Yk-1
        }
        else
        {  
            p=p+2*x+1;            // next decision parameter
        }
            x++;             // Xk+1
 
        delay(100);       // to see one by one drawing pixels 
       
    }while(x<=y);        // till first octet from top to right 
}
int main()
{
    int gd,gm,i;
    gd=DETECT;

    int x,y;
    int Xc,Yc,r;
// Inputs center and radius
    printf("enter coordinate of center point : ");
    scanf("%d%d",&Xc,&Yc);
    printf("enter value of radius  : ");
    scanf("%d",&r);

// initiate graphics after taking inputs
    initgraph(&gd,&gm,NULL);

    midPointCircle(Xc,Yc,r);

        delay(100000); // delay 
        closegraph(); //deallocating all memory from graphics mode     

    return 0;
}

// In Terminal
// To compile :  g++ midPointCircle.cpp -lgraph
// To Run :  ./a.out
