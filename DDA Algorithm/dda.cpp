// Header files 
#include<stdio.h>
#include<graphics.h> // for graphics 
#include<stdlib.h>   // for exit
#include<math.h>     // for mathematical functions 

int round(float x)
{
    int temp=x;
    float pt=x-temp;
    temp=pt>0.5?temp++:temp;
    return temp;
}

int main()
{
    int gd=DETECT,gm,i=0;
    float x1,y1,x2,y2;


//inputs  coordinates of two points
   printf("enter x1 and y1: ");
   scanf("%f %f",&x1,&y1);
   printf("enter x2 and y2: ");
   scanf("%f %f",&x2,&y2);

    initgraph(&gd,&gm,NULL);   // initiating the graphics mode  

   float dx=abs(x2-x1);
   float dy=abs(y2-y1);
// slope    
   float m=dy/dx;

   float step=dx>dy?dx:dy;
// X increment y increment 
   float xInc=dx/step;
   float yInc=dy/step;
    

// loop untill step  
   while(i++<=step)
   { putpixel(round(x1),round(y1),RED); // 
     x1=x1+xInc;
     y1=y1+yInc;
    delay(100);         // delay to see pixels
   }
      delay(50000);       // delay to see output

//deallocating all memory from graphics mode     
   closegraph();

    return 0;
}

// In Terminal
// To compile :  g++ dda.cpp -lgraph
// To Run :  ./a.out
