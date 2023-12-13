#include<time.h>
#include<stdlib.h>
void insertionsort(int *p,int a)
{
    for(int i=1;i<a;i++){
        int temp=p[i];
      int j=i-1;
      while(j>=0 && p[j]>temp){
          p[j+1]=p[j];
        //   printf("%d ",p[j+1]);
          j--;
      }
      p[j+1]=temp;
    }
}

// void descending(int *p,int a)
// {
//     for(int i=1;i<a;i++){
//         int temp=p[i];
//       int j=i-1;
//       while(j>=0 && p[j]<temp){
//           p[j+1]=p[j];
//         //   printf("%d ",p[j+1]);
//           j--;
//       }
//       p[j+1]=temp;
//     }
// }

// void random(int *p,int a)
// {
//     srand(time(NULL));
//     for(int j=0;j<a;j++){
//      p[j]=rand();
//     }
// }

// void nearsort(int *p,int a,int b)
// {
//     srand(time(NULL));
//     for(int j=a-1;j<b;j++){
//      p[j]=(rand()%(b-a+1))+a;
//     }
    
// }
