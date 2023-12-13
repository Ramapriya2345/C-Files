#include "bubblesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int main(){
//     int n;
//     scanf("%d",&n);
//     int *p=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&p[i]);
//     }
//     bubblesort(p,n);
//     for(int i=0;i<n;i++){
//         printf("%d",p[i]);
//     }
//     free(p);
// }

// ascending
// int main(){
//     FILE *fptr;
//     fptr=fopen("ascending.txt","w");
//     int n=100000;
//     int *p=(int *)malloc(sizeof(int)*n);
    // for(int i=0;i<n;i++){
    //     p[i]=i+1;
    // }
//     bubblesort(p,n);
//     for(int i=0;i<n;i++){
//         fprintf(fptr,"%d\n",p[i]);
//     }
    // printf("done");
    // fclose(fptr);
    // free(p);
// }

// descending
// int main(){
//     FILE *fptr;
//     fptr=fopen("descending.txt","w");
//     int n=100000;
//     int *p=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         p[i]=i+1;
//     }
//     descending(p,n);
//     for(int i=0;i<n;i++){
//         fprintf(fptr,"%d\n",p[i]);
//     }
//     printf("done");
//     fclose(fptr);
//     free(p);
// }

// random
int main(){
    FILE *fptr;
    fptr=fopen("random.txt","w");
    int n=100000;
    int *p=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        p[i]=i+1;
    }
    random(p,n);
    for(int i=0;i<n;i++){
        fprintf(fptr,"%d\n",p[i]);
    }
    printf("done");
    fclose(fptr);
    free(p);
}

// merely sorted
// int main(){
//     FILE *fptr;
//     fptr=fopen("nearlysorted.txt","w");
//     int n=100000;
//     int *p=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         p[i]=i+1;
//     }
//     nearsort(p,100,150);
//     nearsort(p,860,900);
//     nearsort(p,413,512);
//     for(int i=0;i<n;i++){
//         fprintf(fptr,"%d\n",p[i]);
//     }
//     printf("done");
//     fclose(fptr);
//     free(p);
// }

// bubblesort
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int n;
//     scanf("%d",&n);
//     int *p=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&p[i]);
//     }
//     bubblesort(p,n);
//     for(int i=0;i<n;i++){
//         printf("%d",p[i]);
//     }
//     free(p);
// }
// void bubblesort(int *p,int a)
// {
//     for(int j=a-1;j<=2;j--){
//     for(int i=1;i<a-1;i++){
//         if(p[i]>p[i+1]){
//         swap(&p[i],&p[i+1]);
//     }
//     }
//     }
// }
// void swap(int *a,int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }

