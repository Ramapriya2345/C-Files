#include"swap.h"
#include<time.h>
#include<stdlib.h>
void bubblesort(int *p,int a)
{
    for(int j=0;j<a-1;j++){
    for(int i=0;i<a-1-j;i++){
        if(p[i]>p[i+1]){
        swap(&p[i],&p[i+1]);
    }
    }
    }
}
// void descending(int *p,int a)
// {
//     for(int j=0;j<a-1;j++){
//     for(int i=0;i<a-1-j;i++){
//         if(p[i]<p[i+1]){
//         swap(&p[i],&p[i+1]);
//     }
//     }}
// }

// void random(int *p,int a)
// {
//     srand(time(NULL));
//     for(int j=0;j<a;j++){
//      int i = rand() % (j + 1);
//      int temp = p[j];
//         p[j] = p[i];
//         p[i] = temp;
//     }
// }

// void nearsort(int *p,int a,int b)
// {
//     srand(time(NULL));
//     for(int j=a-1;j<b;j++){
//      p[j]=(rand()%(b-a+1))+a;
//     }
    
// }
