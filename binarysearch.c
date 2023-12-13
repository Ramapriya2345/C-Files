#include <stdlib.h>
#include <time.h>
#include<stdio.h>

// int main(){
//     int *a=malloc(sizeof(int));
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d",&n);
//     printf("Enter the elements: ");
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     int search;
//     printf("Enter the element to be searched: ");
//     scanf("%d",&search);
//     int result=binarysearch(a,n,search);
//     if(result==-1){
//         printf("Element not found");
//     }
//     else{
//         printf("Element found at index %d",result);
//     }
// }
// int binarysearch(int *a,int size,int num){
//     int l=0;
//     int r=size-1;
//     int mid=(l+r)/2;
//     while(l<=r){
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//         mid=(l+r)/2;
//     }
// }

// int binarysearch(int *a,int size,int num);
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//    clock_t start_time = clock();
//    int index=binarysearch(a,n,1);
//    printf("%d",index);
//    clock_t end_time = clock();
//    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Time taken: %f seconds\n", cpu_time_used);
//    fclose(fptr);
//    free(a);
// }
// int binarysearch(int *a,int size,int num){
//     int l=0;
//     int r=size-1;
//     int mid=(l+r)/2;
//     while(l<=r){
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//         mid=(l+r)/2;
//     }
// }//0 secs

// int binarysearch(int *a,int size,int num);
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//    clock_t start_time = clock();
//    int index=binarysearch(a,n,100000);
//    printf("%d",index);
//    clock_t end_time = clock();
//    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Time taken: %f seconds\n", cpu_time_used);
//    fclose(fptr);
//    free(a);
// }
// int binarysearch(int *a,int size,int num){
//     int l=0;
//     int r=size-1;
//     int mid=(l+r)/2;
//     while(l<=r){
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//         mid=(l+r)/2;
//     }
// }//0 secs

// int binarysearch(int *a,int size,int num);
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//    clock_t start_time = clock();
//    int index=binarysearch(a,n,50000);
//    printf("%d",index);
//    clock_t end_time = clock();
//    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Time taken: %f seconds\n", cpu_time_used);
//    fclose(fptr);
//    free(a);
// }
// int binarysearch(int *a,int size,int num){
//     int l=0;
//     int r=size-1;
//     int mid=(l+r)/2;
//     while(l<=r){
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//         mid=(l+r)/2;
//     }
// }//0 secs

// int binarysearch(int *a,int size,int num);
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//    clock_t start_time = clock();
//    int index=binarysearch(a,n,100050);
//    printf("%d",index);
//    clock_t end_time = clock();
//    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Time taken: %f seconds\n", cpu_time_used);
//    fclose(fptr);
//    free(a);
// }
// int binarysearch(int *a,int size,int num){
//     int l=0;
//     int r=size-1;
//     int mid=(l+r)/2;
//     while(l<=r){
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//         mid=(l+r)/2;
//     }
// }//0 secs

// int binarysearch(int *a,int size,int num);
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//    clock_t start_time = clock();
//    int index=binarysearch(a,n,100050);
//    if(index==-1){
//     printf("Element not found\n");
//    }
//    else{
//       printf("%d\n",index);
//    }
//    clock_t end_time = clock();
//    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Time taken: %f seconds\n", cpu_time_used);
//    fclose(fptr);
//    free(a);
// }
// int binarysearch(int *a,int size,int num){
//     int l=0;
//     int r=size-1;
//     int mid=(l+r)/2;
//     while(l<=r){
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             l=mid+1;
//         }
//         else{
//             r=mid-1;
//         }
//         mid=(l+r)/2;
//     }
//     return -1;
// }//0 secs



//binary search using recursion
// int binarysearch(int *a,int l,int r,int num){
//     if(l<=r){
//         int mid=(l+r)/2;
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             return binarysearch(a,mid+1,r,num);
//         }
//         else{
//             return binarysearch(a,l,mid-1,num);
//         }
//     }
//     return -1;
// }
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//     clock_t start_time = clock();
//     int index=binarysearch(a,0,n-1,1);
//     printf("%d",index);
//     clock_t end_time = clock();
//     double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time taken: %f seconds\n", cpu_time_used);
//     fclose(fptr);
//     free(a);
// }//0 sec

// int binarysearch(int *a,int l,int r,int num){
//     if(l<=r){
//         int mid=(l+r)/2;
//         if(a[mid]==num){
//             return mid;
//         }
//         else if(a[mid]<num){
//             return binarysearch(a,mid+1,r,num);
//         }
//         else{
//             return binarysearch(a,l,mid-1,num);
//         }
//     }
//     return -1;
// }
// int main(){
//     FILE *fptr;
//     fptr=fopen("iascending.txt","r");
//     int *a=malloc(sizeof(int));
//     int n=0;
//     while(fscanf(fptr,"%d",&a[n])==1){
//       a=realloc(a,(n+2)*sizeof(int));
//       n++;
//     }
//     clock_t start_time = clock();
//     int index=binarysearch(a,0,n-1,100000);
//     printf("%d",index);
//     clock_t end_time = clock();
//     double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time taken: %f seconds\n", cpu_time_used);
//     fclose(fptr);
//     free(a);
// }//0 sec

int binarysearch(int *a,int l,int r,int num){
    if(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==num){
            return mid;
        }
        else if(a[mid]<num){
            return binarysearch(a,mid+1,r,num);
        }
        else{
            return binarysearch(a,l,mid-1,num);
        }
    }
    return -1;
}
int main(){
    FILE *fptr;
    fptr=fopen("iascending.txt","r");
    int *a=malloc(sizeof(int));
    int n=0;
    while(fscanf(fptr,"%d",&a[n])==1){
      a=realloc(a,(n+2)*sizeof(int));
      n++;
    }
    clock_t start_time = clock();
    int index=binarysearch(a,0,n-1,50000);
    printf("%d",index);
    clock_t end_time = clock();
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    fclose(fptr);
    free(a);
}//0 sec