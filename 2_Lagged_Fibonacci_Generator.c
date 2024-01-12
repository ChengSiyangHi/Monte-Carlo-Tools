//
//  main.c
//  Lagged Fibonacci Generator
//
//  Created by Siyang Cheng on 2021/9/17.
//  Copyright. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//values of N and p be changed here
#define N 10000
#define p 4

void main ( void )
{
    //Obtain the time seed and the first random number
    srand(time(0));
    int zz[N];
    zz[0]=rand();
    zz[1]=rand();
    printf( "%d\n%d\n", zz[0],zz[1]);
    
    //Fibonacci delayed generator
    int m=2147483647;
    int i=p;
    int z_test=0;
    for(i=p;i<N;i++){
        z_test=(zz[i-1]+zz[i-p])%m; //p represents the delay and '+' can be changed to '-' '*' etc.
        if(z_test>=0)
            zz[i]=z_test;
        else zz[i]=z_test+m;
        printf("%d\n",zz[i]);
    }
    
    //Count the number of xn-1>xn+1>xn
    int j=0;
    float count=0;
    float ratio=1;
    for(j=1;j<N-1;j++){
        if((zz[j+1]>zz[j])&&(zz[j-1]>zz[j+1]))
            count=count+1;
        ratio=count/N;
    }
    printf("count:%f\n",count);
    printf("ratio:%f\n",ratio);
}
