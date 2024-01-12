//
//  main.c
//  Data Acceptance Rejection Sampling
//
//  Created by Siyang Cheng on 2021/10/24.
//  Copyright. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 100000


void main ( void )
{
    //   int i;
    //   int j;
    //   float data[114][2];
    //   FILE* fp=fopen("data.TXT","r");
    //   if(fp==NULL){
    //       printf("none data.");
    //   }
    //   for(i=0;i<114;i++){
    //       for(j=0;j<2;j++){
    //           fscanf(fp,"%f",&data[i][j]);
    //       }
    //       fscanf(fp,"\n");
    //   }
    //   fclose(fp);
    //
    //   for(i=0;i<114;i++){
    //       for(j=0;j<3;j++){
    //           printf("%.1f\n",data[i][j]);
    //       }
    //   }
    
    
    //input rawdata
    int data[114][2]={2900,1158,2901,1163,2902,1167,2903,1171,2904,1178,2905,1188,2906,1200,2907,1214,2908,1233,2909,1256,2910,1281,2911,1303,2912,1320,2913,1335,2914,1351,2915,1368,2916,1386,2917,1402,2918,1417,2919,1432,2920,1449,2921,1469,2922,1490,2923,1511,2924,1531,2925,1551,2926,1572,2927,1597,2928,1623,2929,1647,2930,1666,2931,1684,2932,1704,2933,1728,2934,1753,2935,1778,2936,1800,2937,1819,2938,1838,2939,1856,2940,1873,2941,1888,2942,1901,2943,1915,2944,1937,2945,1969,2946,2006,2947,2045,2948,2081,2949,2118,2950,2158,2951,2207,2952,2265,2953,2329,2954,2389,2955,2437,2956,2472,2957,2501,2958,2532,2959,2569,2960,2612,2961,2876,2962,3109,2963,3902,2964,4987,2965,5672,2966,4704,2967,3401,2968,2749,2969,2409,2970,2328,2971,2263,2972,2218,2973,2185,2974,2149,2975,2096,2976,2021,2977,1930,2978,1838,2979,1762,2980,1715,2981,1696,2982,1697,2983,1701,2984,1692,2985,1659,2986,1601,2987,1525,2988,1442,2989,1358,2990,1277,2991,1206,2992,1194,2993,1458,2994,2664,2995,6190,2996,13605,2997,24698,2998,35560,2999,22719,3000,23865,3001,37630,3002,21964,3003,17629,3004,5497,3005,1298,3006,769,3007,530,3008,341,3009,208,3010,110,3011,64,3012,39,3013,9};
    
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
        //printf("%f\n",zz[i]);
    }
    

    //generate N random numbers for xi2
    int y=rand()+70;//the second seed is defined artificially and can be changed in anyway
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
    double max=2147483647;
    double xi1[N];
    double xi2[N];
    for(i=0;i<N;i++){
        xi1[i]=zz[i]/max;
        xi2[i]=yy[i]/max;
    }
    
    
    //calculate xi_x & xi_y
    double xi_x[N];
    double xi_y[N];
    for(i=0;i<N;i++){
        if(xi1[i]<0.32727){
            xi_x[i]=275*xi1[i]+2900;
        }
        else xi_x[i]=(275*xi1[i]-91)/8+2990;
        //printf("%f\n",xi_x[i]);
    }
    
    for(i=0;i<N;i++){
        if(xi_x[i]<=2990){
            xi_y[i]=5000*xi2[i];
        }
        else xi_y[i]=40000*xi2[i];
        //printf("%f\n",xi_y[i]);
    }
    
    //select the expected random number for p2
    for(i=0;i<N;i++){
        int xi_x_test=floor(xi_x[i])-2900;
        //printf("%d\n",xi_x_test);
        if(xi_y[i]<data[xi_x_test][1]){
            printf("%f\n",xi_x[i]);
        }
    }
    
    
}
