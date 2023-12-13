// #include <stdio.h>
// #include <stdlib.h>

// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     // Allocate memory for the return array
//     int* retur = (int*)malloc(2 * sizeof(int));
//        *returnSize = 2;
//     for (int i = 0; i < numsSize; i++) {
//         for (int j = i + 1; j < numsSize; j++) {
//             if (nums[i] + nums[j] == target) {
//                 retur[0] = i;
//                 retur[1] = j;
//                 return retur;
//             }
//         }
//     }
// }
// int main() {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
    
//     int *p = (int*)malloc(n * sizeof(int));
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &p[i]);
//     }
    
//     int target;
//     printf("Enter the target sum: ");
//     scanf("%d", &target);
    
//     int returnSize;
//     int *d = twoSum(p, n, target, &returnSize);
    
//     if (returnSize == 2) {
//         printf("Indices: [%d, %d]\n", d[0], d[1]);
//     } else {
//         printf("No solution found.\n");
//     }
    
//     // Free allocated memory
//     free(p);
//     free(d);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// char * longestCommonPrefix(char **strs, int strsSize) {
//     int small = strlen(strs[0]);
//     for (int i = 0; i < strsSize; i++) {
//         if (strlen(strs[i]) < small) {
//             small = strlen(strs[i]);
//         }
//     }
//     char *str = (char *)malloc((small + 1) * sizeof(char));
//     for (int i = 0; i < small; i++) {
//         for (int j = 0; j < strsSize - 1; j++) {
//             if (strs[j][i] != strs[j + 1][i]) {
//                 str[i] = '\0';
//                 return str;
//             }
//         }
//         str[i] = strs[0][i];
//     }
//     str[small] = '\0';
//     return str;
// }

// int main() {
//     char *strs[] = {"flower", "flow", "flight"};
//     int strsSize = sizeof(strs) / sizeof(strs[0]);
//     char *str = longestCommonPrefix(strs, strsSize);
//     puts(str);
// }

// bool containsDuplicate(int* nums, int numsSize){
// bool flag=false;
// for(int i=0;i<numsSize;i++){
//     for(int j=i+1;j<numsSize;j++){
//         if(nums[i]==nums[j]){
//             flag=true;
//             break;
//         }
//     }
// }
// return flag;
// }

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int count[128] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (count[nums[i]] == 1) {
            printf("%d ", nums[i]); // Add a space after each printed number
        }
    }
}

int main() {
    int nums[] = {4, 3,5,2, 4, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    singleNumber(nums, numsSize);
    return 0;
}
