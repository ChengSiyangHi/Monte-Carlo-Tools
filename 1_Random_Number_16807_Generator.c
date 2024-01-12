//
//  main.c
//  16807 Random Number Generator based on Schrage's Method
//
//  Created by Siyang Cheng on 2021/9/16.
//  Copyright All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//values of N and l be changed here
#define N 100 //total number of the randoms
#define l 3 //step length
#define K 20 //the number of ranges for homogeneity test
#define kf 3 //the number of factor for homogeneity test

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
    
    //Generate N random numbers
    int z_test=0;
    double zz[N];
    int i=0;
    //Schrage Method
    for(i=0;i<N;i++){
        z_test=a*(z%q)-r*(int)(z/q)+b;
        if(z_test>=0)
            z=z_test;
        else z=z_test+m;
        zz[i]=z;
        //printf("%f\n",zz[i]);
    }
    printf("***************N=%d************\n",N);
    
    //calculate the range of the array
    int max;
    max=zz[0];
    for(i=0;i<N;i++){
        if(zz[i+1]>max)
            max=zz[i+1];
    }
    printf("max:%d\n",max);
    
    
    //obtain 2D points
    int s=(int)(N/l/2);//the number of points
    printf("s=%d\n",s);
    double point[s][2];
    int j=0;
    //x and y are printed successively and correspondingly to make it easier for
    //copying the datas to Matlab and obtaining a 2D distribution picture
    printf("---------------x:---------------\n");
    for(j=0;j<=s;j++){
        point[j][0]=(double)(zz[j]/max);
        printf("%f\n",point[j][0]);
    }
    printf("---------------y:---------------\n");
    for(j=0;j<=s;j++){
        point[j][1]=(double)(zz[j+l]/max);
        printf("%f\n",point[j][1]);
    }
    
    
    //homogeneity test
    //int nk[K]={0};
    //float xx=0;
    //int k=0;
    //int sum=0;
    //for(k=0;k<K;k++){
    //    for(i=0;i<N;i++){
    //        if((zz[i]>=k*(float)(max/K))&&(zz[i]<=(k+1)*(float)(max/K)))
    //            nk[k]=nk[k]+1;
    //        else nk[k]=nk[k];
    //    }
    //    //printf("nk%d:%d\n",k,nk[k]);
    //    sum=sum+nk[k];
    //    //sum: the number of randoms that have been considered in the previous"if"
    //    //which is actually always < N
    //    //mk should be sum/K instead of N/K
    //}
    //printf("sum:%d\n",sum);
    //float mk=sum/K;
    //printf("mk:%f\n",mk);
    
    //for(k=0;k<K;k++){
    //    xx=xx+(nk[k]-mk)*(nk[k]-mk)/mk;
    //}
    //printf("xx:%f\n",xx);//xx is supposed to be close to K
    
    
    //homogeneity test by <x^k>
    int count=0;
    double sum=0;
    double xk=0;
    float test=0;
    for(j=0;j<=s;j++){
        sum=sum+pow(point[j][0],kf)+pow(point[j][1],kf);
        count=count+1;
    }
    printf("sum=%f\n",sum);
    printf("count=%d\n",count);
    xk=(double)(sum/count);
    printf("<x^k>=%f\n",xk);
}
