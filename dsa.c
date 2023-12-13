#include "bubblesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include<stdio.h>
// int main(){
//     int x=0;
//     for(int i=0;i<99;i++)
//     {
//         x+=i;
//         // for(int j=0;j<99-i;j++){
//         // }
//         // printf("\n");
//     }
//     printf("%d",x);
// }

// #include <stdio.h>
// #include <stdlib.h>
// void insertionsort(int *p,int a);
// int main(){
//     int n;
//     scanf("%d",&n);
//     int *p=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&p[i]);
//     }
//     insertionsort(p,n);
//     for(int i=0;i<n;i++){
//         printf("%d ",p[i]);
//     }
//     free(p);
// }
// void insertionsort(int *p,int a)
// {
//     for(int i=1;i<a;i++){
//         int temp=p[i];
//       int j=i-1;
//       while(j>=0 && p[j]>temp){
//           p[j+1]=p[j];
//         //   printf("%d ",p[j+1]);
//           j--;
//       }
//       p[j+1]=temp;
//     }
// }

// #include <stdio.h>
// #include <time.h>

// int main() {
//     clock_t start_time = clock();
    
//     // Your code to measure execution time for.
//     for (int i = 0; i < 1000000000; i++) {
//         // Some computation.
//     }
    
//     clock_t end_time = clock();
    
//     double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time taken: %f seconds\n", cpu_time_used);
    
//     return 0;
// }

// int main(){
//     FILE *fptr;
//     fptr=fopen("random.txt","w");
//     int n=100000;
//     int *p=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         p[i]=i+1;
//     }
//     random(p,n);
//     for(int i=0;i<n;i++){
//         fprintf(fptr,"%d\n",p[i]);
//     }
//     printf("done");
//     fclose(fptr);
//     free(p);
// }

