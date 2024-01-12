//
//  main.c
//  Function Sampling of pdf
//
//  Created by Siyang Cheng on 2021/10/4.
//  Copyright. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 100000

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
    //Generate N random numbers for u
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
    
    //calculate the range of the array
    double max1;
    max1=zz[0];
    for(i=0;i<N;i++){
        if(zz[i+1]>max1)
            max1=zz[i+1];
    }
    //printf("max1:%f\n",max1);
    
    //normalization
    for(i=0;i<N;i++){
        zz[i]=zz[i]/max1;
        //printf("%f\n",zz[i]);
        }
    
    //converse to p1
    double p1[N];
    for(i=0;i<N;i++){
        p1[i]=4/3*zz[i]-1/3;
        if(p1[i]>0){
            printf("%f\n",p1[i]);
        }
        p1[i]=4*zz[i]-1;
        if(p1[i]<0){
            printf("%f\n",p1[i]);
        }
    }
}
