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