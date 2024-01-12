//
//  main.c
//  Diffusion_Limited_Aggregation
//
//  Created by Siyang Cheng on 2021/12/21.
//  Copyright. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 100000



//main
void main ( void )
{
    //a grid for recording DLA position
    int position[2601][2];
    //the core
    position[0][0]=25;
    position[0][1]=25;
    
    //random walk
    int n=0;
    int RW_x;
    int RW_y;//record the position of each random work particle
    
    //16807 generator
    int a=16807;
    int b=0;
    int m=2147483647;
    int q=m/a;
    int r=m%a;
    int i;
    int j;
    int k;
    
    
    for(i=1;i<5000;i++){
        RW_x=25;
        RW_y=25;
        
        //Generate 5000 random numbers for each particle
        srand(time(0));
        unsigned int z=rand();
        int z_test=0;
        double zz[5000];
        for(j=0;j<5000;j++){//no more than 5000 steps for 1 RW particle
            z_test=a*(z%q)-r*(int)(z/q)+b;
            //Schrage Method
            if(z_test>=0)
                z=z_test;
            else z=z_test+m;
            zz[j]=z;
            //printf("%f\n",zz[j]);
        }
        
        //normalization
        double xi[5000];
        double max=2147483647;
        for(i=0;i<5000;i++){
            xi[i]=zz[i]/max;
            //printf("%f\n",xi[i]);
        }
        
        for(j=0;j<5000;j++){//one step of RW
            //DLA
            for(k=0;k<j;k++){
                if((RW_x-position[k][0])*(RW_x-position[k][0])+(RW_y-position[k][1])*(RW_y-position[k][1])<=2){
                    position[j][0]=RW_x;
                    position[j][1]=RW_y;
                    n=n+1;
                    break;
                }
            }
            //reach the wall
            if(RW_x<0||RW_y<0||RW_x>50||RW_y>50){
                break;
            }
            //RW
            if(xi[j]>=0&&xi[j]<0.25){
                RW_x=RW_x;
                RW_y=RW_y+1;
                
                
            }
            if(xi[j]>=0.25&&xi[j]<0.5){
                RW_x=RW_x+1;
                RW_y=RW_y;
            }
            if(xi[j]>=0.5&&xi[j]<0.75){
                RW_x=RW_x;
                RW_y=RW_y-1;
            }
            if(xi[j]>=0.75&&xi[j]<1){
                RW_x=RW_x-1;
                RW_y=RW_y;
            }
            
        }
        //RW end for one partitle
    }//RW end for N particle
    
    //output
    printf("-------------------------------------x position-------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%d\n",position[i][0]);
    }
    printf("-------------------------------------y position-------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%d\n",position[i][1]);
    }
        
    
    
}
