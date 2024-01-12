//
//  main.c
//  Marsaglia Sampling on a spherical surface
//
//  Created by Siyang Cheng on 2021/10/4.
//  Copyright. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 20000

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
    max1=2147483647;

    
    //normalization to [-1,1]
    double uu[N];
    for(i=0;i<N;i++){
        uu[i]=2*(zz[i]/max1)-1;
        //printf("%f\n",uu[i]);
    }
    
    
    //
    //generate N random numbers for v
    int y=rand()*70+8;//the second seed is defined artificially and can be changed in anyway
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
    
    double max2;
    max2=2147483647;
    double vv[N];
    for(i=0;i<N;i++){
        vv[i]=2*(yy[i]/max2)-1;
        //printf("%f\n",vv[i]);
    }
    
    
    //calculate and test r^2
    double r_test[N];
    int count=0;
    for(i=0;i<N;i++){
        r_test[i]=vv[i]*vv[i]+uu[i]*uu[i];
        if(r_test[i]<=1){
            //printf("%f\n",r_test[i]);
            count=count+1;
        }
    }
    //printf("%d\n",count);
    
    double r2[count];
    double u[count];
    double v[count];
    double w[count];
    int count2;
    int j=0;
    for(j=0;j<count;){
        for(i=0;i<N;i++){
            if(r_test[i]<1){
                r2[j]=r_test[i];
                //printf("%f\n",r2[j]);
                u[j]=2*uu[i]*sqrt(1-r2[j]);
                v[j]=2*vv[i]*sqrt(1-r2[j]);
                w[j]=1-2*r2[j];
                //printf("%f\n",u[j]);
                //printf("%f\n",v[j]);
                j=j+1;
            }
        }
        count2=j;
        //printf("j=%d",j);
    }
    
    
    printf("-----------------------------x:---------------------------\n");
    for(j=0;j<count2;j++){
        printf("%4f\n",u[j]);
    }
    printf("-----------------------------y:---------------------------\n");
    for(j=0;j<count2;j++){
        printf("%4f\n",v[j]);
    }
    printf("-----------------------------z:---------------------------\n");
    for(j=0;j<count2;j++){
        printf("%4f\n",w[j]);
    }
}



