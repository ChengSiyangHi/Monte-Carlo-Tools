//
//  main.c
//  Markov_Chain
//
//  Created by Siyang Cheng on 2021/12/14.
//  Copyright. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 10000
#define beta 5

//integral function
double Z(double x,double y){
    double sum1=0;
    sum1=exp(beta*(2*(x*x+y*y)-0.5*(pow(x,4)+pow(y,4))-0.5*pow((x-y),4)));
    return sum1;
}

double xx(double x,double y){
    double sum2=0;
    sum2=x*x*exp(beta*(2*(x*x+y*y)-0.5*(pow(x,4)+pow(y,4))-0.5*pow((x-y),4)));
    return sum2;
}

double yy(double x,double y){
    double sum3=0;
    sum3=y*y*exp(beta*(2*(x*x+y*y)-0.5*(pow(x,4)+pow(y,4))-0.5*pow((x-y),4)));
    return sum3;
}

double xxyy(double x,double y){
    double sum3=0;
    sum3=(x*x+y*y)*exp(beta*(2*(x*x+y*y)-0.5*(pow(x,4)+pow(y,4))-0.5*pow((x-y),4)));
    return sum3;
}



//main
void main ( void )
{
    int gamma=1;
    
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
    }
    
    //Generate N random numbers for xi2
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
    
    
    //normalization
    double R1[N];
    double R2[N];
    double x_test1[N]; //x1'
    double x_test2[N]; //x2'
    double max=2147483647;
    for(i=0;i<N;i++){
        R1[i]=zz[i]/max;
        x_test1[i]=-gamma*log(R1[i]);
        R2[i]=zz2[i]/max;
        x_test2[i]=-gamma*log(R2[i]);
    }
    
    
    //Metropolis-Hasting selecting
    double xi[N];
    xi[0]=1;
    double rr;
    printf("-----------------------------------Markov-x-----------------------------------\n");
    for(i=0;i<N;i++){
        rr=(x_test1[i]/xi[i])*exp(-(x_test1[i]-xi[i]))*exp((x_test1[i]-xi[i])/gamma);
        if(R1[i]<1&&R1[i]<rr){
            xi[i+1]=x_test1[i];
        }
        else xi[i+1]=xi[i];
        printf("%f\n",xi[i+1]);
    }
    
    double xi2[N];
    xi2[0]=1;
    printf("-----------------------------------Markov-y-----------------------------------\n");
    for(i=0;i<N;i++){
        rr=(x_test2[i]/xi2[i])*exp(-(x_test2[i]-xi2[i]))*exp((x_test2[i]-xi2[i])/gamma);
        if(R2[i]<1&&R2[i]<rr){
            xi2[i+1]=x_test2[i];
        }
        else xi2[i+1]=xi2[i];
        printf("%f\n",xi2[i+1]);
    }
    
    //calculate the integral
    double sum=0;
    double count=0;
    for(i=N/10;i<N;i++){
        sum=sum+xxyy(xi[i],xi2[i]);
        count=count+1;
    }
    sum=sum/count;
    printf("xxyy=%f\n",sum);
}

