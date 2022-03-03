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

void angular();
void position();

int main(argc, argv)
int argc;
char *argv[];
{
    M=pow(10,11); /* in solar mass */
    /* to keep G as 1, convert M into a new mass unit */
    M=M*4.30091*pow(10,-6);
    
    /* set up position vectors */
    int particleN=297*2;  
    double r[MAXPNT],theta[MAXPNT];
    double x1,x2; /* find out the initial positions of the core masses */


    angular(r,theta)
    double x[MAXPNT],y[MAXPNT],z[MAXPNT];
    position(x,y,z,particleN,x1,x2);
    
    
    



    return 0;
}

void angular(r,theta)
double r[];
double theta[];
{
    int ringn=11;
    int innern=12;
    int outern=42;
    for (int i=0;i<ringn;i++)
    {
        double radius=(0.2+0.05*i)*Rmin;
        double theta=2*PI/(innern+3*i);
        r[i]=radius;
        theta[i]=theta;
    }
}




void position(x,y,z,n,x1,x2)
double x[];
double y[];
double z[];
int n;
double x1; /* position of the first core mass */
double x2;
{
    int ringn=11;
    int innern=12;
    int outern=42;
    
    int count=0;
   
    /* first galaxy */
    for (int i=0;i<ringn;i++)
    {
        for (int j=0;j<12+3*i;j++)
        {
            x[count]=r[i]*cos(j*theta[i])+x1;
            y[count]=r[i]*sin(j*theta[i]);
            z[count]=0;
            count++;
        }
    }

    /* second galaxy */
    for (int i=0;i<ringn;i++)
    {
        for (int j=0;j<12+3*i;j++)
        {
            x[count]=radius*cos(j*theta)+x2;
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




