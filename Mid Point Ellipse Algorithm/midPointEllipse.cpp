// mid point Ellipse algorithm 

// Header files
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void midPointEllipse(int Xc,int Yc,int Rx,int Ry)
{
    int x=0,y=Ry;         // initial starting point 
    float p;
 // region 1             m<1
 // unit x interval 
 // and either Yk or yk-1

 // initial decision parameter
 p=pow(Ry,2)+pow(Rx,2)/4.0 - Ry*pow(Rx,2);


    do
    {   
    //From region 1 points draw all symmetric points in region 1,3,5,7  
  
         putpixel(Xc+x,Yc+y,GREEN);          // 1st Quadrant pixels
         putpixel(Xc-x,Yc+y,GREEN);            // 2nd Quadrant pixels
         putpixel(Xc-x,Yc-y,GREEN);            // 3rd Quadrant pixels
         putpixel(Xc+x,Yc-y,GREEN);            // 4th Quadrant pixels
    if(p>=0)
    {   // next y point 
        y--;
        p=p+2*pow(Ry,2)*x+pow(Ry,2)-2*pow(Rx,2)*y;  // next decision parameter
    }
    else
    {
        p=p+2*pow(Ry,2)*x+pow(Ry,2); 
    }
    x++;     // unit interval of x 

    delay(100);      // to see drawing points 

    }while(Ry*Ry*x<Rx*Rx*y);          // stopping condn till reaches to region 2

// region 2        m>1
// unit y interval
// and either Xk or Xk+1 

// initial decision parameter
p=pow(x+0.5,2)*Ry*Ry+pow(y-1,2)*Rx*Rx-Rx*Rx*Ry*Ry;

     do
    {   
         
         putpixel(Xc+x,Yc+y,RED);          // 1st Quadrant pixels
         putpixel(Xc-x,Yc+y,RED);            // 2nd Quadrant pixels
         putpixel(Xc-x,Yc-y,BLUE);            // 3rd Quadrant pixels
         putpixel(Xc+x,Yc-y,BLUE);            // 4th Quadrant pixels
    if(p>=0)
    {
        p=p-2*pow(Rx,2)*y+pow(Rx,2);
    }
    else
    {
        x++;
        p=p+2*pow(Ry,2)*x-2*pow(Rx,2)*y-pow(Rx,2);
    }
        y--;

    delay(100);      // to see drawing points 

    }while(y>=0);
}

int main()
{
    int gd,gm,i;
    gd=DETECT;

    int x,y;
    int Xc,Yc,Rx,Ry;
// inputs 
//center points of ellipse 
//and semi major axis and semi minor axis 

    printf("enter coordinate of center point of Ellipse : ");
    scanf("%d%d",&Xc,&Yc);
    printf("enter value of Semi major and semi minor axis value (Rx,Ry): ");
    scanf("%d%d",&Rx,&Ry);

// initiate graphics after taking inputs
    initgraph(&gd,&gm,NULL);

    midPointEllipse(Xc,Yc,Rx,Ry);    // calling 

    delay(100000); // delay to see outputs
    
    //deallocating all memory from graphics mode     
    closegraph();     
    return 0;
}

// In Terminal
// To compile :  g++ midPointEllipse.cpp -lgraph
// To Run :  ./a.out
