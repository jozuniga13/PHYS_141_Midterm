/* This the initial setup for the two galaxies in mice project */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXPNT 3000            /* maximum number of points */
#define PI 3.141592654

double M,Rmin,Rinit;
double G=1; 

int main(argc, argv)
int argc;
char *argv[];
{
    M=pow(10,11); /* in solar mass */
    Rmin=25*pow(10,3); /* in parsec */
    /* to keep G as 1, convert M into a new mass unit */
    M=M/



    return 0;
}


