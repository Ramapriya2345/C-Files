int linearsearch(int *p,int size,int num){
    for(int i=0;i<size;i++){
        if(p[i]==num){
            return i;
            break;
        }
    }
    return -1;
}