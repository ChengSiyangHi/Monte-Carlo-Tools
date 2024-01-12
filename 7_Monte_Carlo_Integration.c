//
//  main.c
//  Monte_Carlo_Integration
//
//  Created by Siyang Cheng on 2021/10/23.
//  Copyright. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 100000


double F(double x,double y,double z,double u,double v){
    double sum=0;
    sum=5-x*x+y*y-z*z+u*u*u-v*v*v;
    return sum;
}


//main
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
    //Generate N random numbers for x
    int z_test=0;
    int i=0;
    double zz1[N];
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        //Schrage Method
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz1[i]=z;
        //printf("%f\n",zz1[i]);
    }
    
    
    //
    //generate N random numbers for y
    z=rand()*70;
    double zz2[N];
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz2[i]=z;
        //printf("%f\n",zz2[i]);
    }
    
    //
    //generate N random numbers for z
    z=rand()*6+140;
    double zz3[N];
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz3[i]=z;
        //printf("%f\n",zz3[i]);
    }
    
    //
    //generate N random numbers for u
    z=rand()*21+30;
    double zz4[N];
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz4[i]=z;
        //printf("%f\n",zz4[i]);
    }
    
    //
    //generate N random numbers for v
    z=rand()+28;
    double zz5[N];
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz5[i]=z;
        //printf("%f\n",zz4[i]);
    }
    
    
    //normalization
    double x[N];
    double y[N];
    double zz[N];
    double u[N];
    double v[N];
    double max=2147483647;
    for(i=0;i<N;i++){
        x[i]=7*zz1[i]/max/10;
        y[i]=4*zz2[i]/max/7;
        zz[i]=9*zz3[i]/max/10;
        u[i]=2*zz4[i]/max;
        v[i]=13*zz5[i]/max/11;
        //printf("%f,%f,%f,%f,%f\n",x[i],y[i],zz[i],u[i],v[i]);
    }
    
    
    //calculate the integral
    double integral=0;
    for(i=0;i<N;i++){
        integral=integral+F(x[i],y[i],zz[i],u[i],v[i]);
        printf("integral=%f\n",integral);
    }
    integral=integral*234/275/N;
    printf("N=%d\n",N);
    printf("integral=%f\n",integral);

    
    
}
