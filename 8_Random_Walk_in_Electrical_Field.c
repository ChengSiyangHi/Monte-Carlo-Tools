//
//  main.c
//  Random_Walk_in_Electrical_Field
//
//  Created by Siyang Cheng on 2021/11/03.
//  Copyright. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 10000

void main ( void )
{
    //Obtain the time seed and the first random number
    srand(time(0));
    unsigned int z=rand();
    //printf( "%d\n", z);
    
    //16807 generator
    int a=16807;
    int b=0;
    int m=2147483647;
    int q=m/a;
    int r=m%a;
    
    
    //
    //Generate N random numbers for xi1
    int z_test=0;
    double zz[N];
    int i=0;
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        //Schrage Method
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz[i]=z;
        //printf("%f\n",zz[i]);
    }
    
    
    //
    //generate N random numbers for xi2
    int y=rand()*70+3;//the second seed is defined artificially and can be changed in anyway
    int y_test=0;
    double yy[N];
    for(i=0;i<N;i++){
        y_test=a*(y%q)-r*(int)(y/q)+b;
        if(y_test>=0)
            y=y_test;
        else y=y_test+m;
        yy[i]=y;
        //printf("%f\n",yy[i]);
    }
    
    
    //normalization
    double xi1[N];
    double xi2[N];
    double max=2147483647;
    for(i=0;i<N;i++){
        xi1[i]=2*zz[i]/max-1;
        //printf("%f\n",xi1[i]);
    }
    for(i=0;i<N;i++){
        xi2[i]=2*yy[i]/max-1;
        //printf("%f\n",xi2[i]);
    }
    
    double gamma_x[N];
    double gamma_y[N];
    gamma_x[0]=xi1[0]*xi1[0];
    gamma_y[0]=xi2[0]*xi2[0];
    //printf("gamama x=%f\n",gamma_x[0]);
    printf("------------------------x:------------------------\n");
    for(i=1;i<N;i++){
        gamma_x[i]=gamma_x[i-1]+xi1[0]*xi1[i];
        printf("%f\n",gamma_x[i]);
    }
    printf("------------------------y:------------------------\n");
    for(i=1;i<N;i++){
        gamma_y[i]=gamma_y[i-1]+xi2[0]*xi2[i];
        printf("%f\n",gamma_y[i]);
    }
    
    
    
    
}

