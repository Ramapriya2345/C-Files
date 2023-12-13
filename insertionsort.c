#include "insertionsort.h"
#include "linearsearch.h"
#include "bubblesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bubblesort
int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
FILE *ptr=fopen("iascending.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//4.053 seconds

int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//4.181 seconds

int main(){
 FILE *fptr;
 fptr=fopen("descending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
FILE *ptr=fopen("idescending.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//10.958 seconds

int main(){
 FILE *fptr;
 fptr=fopen("descending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//10.935 seconds

int main(){
 FILE *fptr;
 fptr=fopen("random.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
FILE *ptr=fopen("idescending.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//15.095 seconds

int main(){
 FILE *fptr;
 fptr=fopen("random.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//15.901 seconds

int main(){
 FILE *fptr;
 fptr=fopen("nearlysorted.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
bubblesort(p,i);
FILE *ptr=fopen("inearly.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//4.008 seconds

int main(){
 FILE *fptr;
 fptr=fopen("nearlysorted.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0.001 seconds



insertionsort
int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
FILE *ptr=fopen("iascending.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0.015 seconds

int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds

int main(){
 FILE *fptr;
 fptr=fopen("descending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
FILE *ptr=fopen("idescending.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//5.278 seconds

int main(){
 FILE *fptr;
 fptr=fopen("descending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//4.98 seconds

int main(){
 FILE *fptr;
 fptr=fopen("random.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
FILE *ptr=fopen("idescending.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//2.68 seconds

int main(){
 FILE *fptr;
 fptr=fopen("random.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//2.431 seconds

int main(){
 FILE *fptr;
 fptr=fopen("nearlysorted.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
FILE *ptr=fopen("inearly.txt","w");
for(int j=0;j<i;j++){
fprintf(ptr,"%d\n",p[j]);
}
fclose(ptr);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds

int main(){
 FILE *fptr;
 fptr=fopen("nearlysorted.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
insertionsort(p,i);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds


Linear Search
int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
int index=linearsearch(p,i,1);
printf("%d",index);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds //0.001 

int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
int index=linearsearch(p,i,100000);
printf("%d",index);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds //0.001 seconds

int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
int index=linearsearch(p,i,500);
printf("%d",index);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds //0.001 seconds

int main(){
 FILE *fptr;
 fptr=fopen("ascending.txt","r");
 int *p=malloc(sizeof(int));
 int i=0;
 while(fscanf(fptr,"%d",&p[i])==1){
    p=realloc(p,(i+2)*sizeof(int));
    i++;
 }
clock_t start_time = clock();
int index=linearsearch(p,i,100001);
printf("%d",index);
clock_t end_time = clock();
double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", cpu_time_used);
fclose(fptr);
free(p);
}//0 seconds //0.001 seconds
