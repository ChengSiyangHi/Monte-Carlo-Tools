//
//  main.c
//  Percolation
//
//  Created by Siyang Cheng on 2021/11/19.
//  Copyright © 2021 Siyang Cheng. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double F(double x){
    double sum1=0;
    sum1=x*x*x-4*x*x+4*x-1;
    return sum1;
}


int main() {
    double i;
    double reso=0;
    for(i=0.38196;i<0.38197;i=i+0.000001){
        reso=pow(i,3)-4*pow(i,2)+4*i-1;
        printf("i=%f,F=%f\n",i,reso);
    }
    return reso;
}
