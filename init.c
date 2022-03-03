/* This the initial setup for the two galaxies in mice project */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXPNT 3000            /* maximum number of points */
#define PI 3.141592654

double M,Rinit;
double G=1.0; 
double Rmin=25; /* in kiloparsec */

void position();

int main(argc, argv)
int argc;
char *argv[];
{
    M=pow(10,11); /* in solar mass */
    /* to keep G as 1, convert M into a new mass unit */
    M=M*4.30091*pow(10,-6);
    
    /* set up position vectors */
    int particleN=297;  
    double x[particleN],y[particleN],z[particleN];
    position(x,y,z,particleN);
    
    



    return 0;
}

void position(x,y,z,n)
double x[];
double y[];
double z[];
int n;
{
    int ringn=11;
    int innern=12;
    int outern=42;
    
    int count=0;
    
    /* compute the radius and theta of the points in each ring w.r.t. the center of the galaxy (the core mass) */
    for (int i=0;i<ringn;i++)
    {
        double radius=(0.2+0.05*i)*Rmin;
        double theta=2*PI/(innern+3*i);
        for (int j=0;j<12+3*i;j++)
        {
            x[count]=radius*cos(j*theta);
            y[count]=radius*sin(j*theta);
            z[count]=0;
            count++;
        }
    }
    
    /* check if the number of particles in each disk is equal to 297 */
    if (count!=n)
    {
        printf("There is something wrong with how I compute (r,theta).\n");
    }
    
}




