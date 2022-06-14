
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

//K1
int k;
const int k2=5;
#define pi 3.142


class Donut
{
    float A=0, B=0;
    float i, j;                 //phi, theta
    float Z[2480];              //z-Buffer
    char b[2480];
public:

void Display()
{

    system("cls");
    while(1) 
    {
        memset(b,32,2480);
        memset(Z,0,7040);
        for(j=0; j <= 2*pi; j+=0.03)             
        {
            for(i=0; i <= 2*pi; i+=0.01) 
            {
                
                float cosj2 = cos(j)+2;

                float m = 1/(sin(i) * cosj2 * sin(A) + sin(j) * cos(A) + k2);            //1/(z+k2)

                float t = sin(i) * cosj2 * cos(A) - sin(j) * sin(A);

                int x = 40 + 30 * m * (cos(i) * cosj2 * cos(B) - t * sin(B));             //Calculating x
 
                int y = 12 + 15 * m * (cos(i) * cosj2 * sin(B) + t * cos(B));             //Claculating y

                int z = x + 80 * y;

                //Luminance 
                int N = 8 * ((sin(j) * sin(A) - sin(i) * cos(j) * cos(A)) * cos(B) - sin(i) * cos(j) * sin(A) - sin(j) * cos(A) - cos(i) * cos(j) * sin(B));
                
                if(y <= 100 && y >= 0 && x >= 0 && x <= 100 && m >= Z[z])
                {
                    Z[z] = m;                              //string in Z-buffer
                    b[z] = ".,-~:;=!*#$@"[N > 1 ? N : 0];  // Choosing ASCII character and storing it in buffer
                }
            }
        }
        system("cls");
        for(k=0; k<1760; k++)
            putchar(k %  80 ? b[k] : 10);        //Character to be written
        A += 0.05;
        B += 0.02;
    }
}
};

main()
{
    Donut d;
    d.Display();
}