

#include <stdio.h>
#include <stdlib.h>

#define in32(x) scanf("%d", &x)
#define out32(x) printf("%d\n", x)

// Merge sort
void sort(int * arr, int n) {
    if (n <= 12) {
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j) {
                if (arr[j] < arr[j - 1]) {
                    arr[j] ^= arr[j-1];
                    arr[j-1] ^= arr[j];
                    arr[j] ^= arr[j-1];
                    j--;
                } else {
                    break;
                }
            }
        }
        return;
    }
    int m = (n>>1);
    sort(arr, m);
    sort(arr + m, n - m);
    int * tmp = calloc(n, sizeof(int));
    int fptr = 0, bptr = m;
    for (int i = 0; i < n; i++)  {
        if (fptr == m || (bptr < n && arr[fptr] > arr[bptr]))
            tmp[i] = arr[bptr++];
        else
            tmp[i] = arr[fptr++];
    }
    for (int i = 0; i < n; i++)
        arr[i] = tmp[i];
    free(tmp);
}

// Binary search method to find the index of a particular value in a sorted array
int find(int * arr, int size, int target) {
    if (size < 0) return -1;
    if (size == 1) return 0;
    int m = (size>>1);
    /*
    printf("mid point ");
    out32(m);*/
    if (arr[m] == target) return m;
    if (arr[m] > target) return find(arr, m, target);
    return find(arr + m + 1, size - (m + 1), target) + m + 1;
}

// Method to coordinate compress an array 
void compress(int * arr, int n) {
   
    // Create a sorted version of the original array
    int * tmp = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        tmp[i] = arr[i];
    sort(tmp, n);
    
    // Remove duplicates
    int num = 1;
    for (int i = 1; i < n; i++)
        if (tmp[i] != tmp[i - 1])
            tmp[num++] = tmp[i];
         
    // Find the index using a binary search in the sorted array of no uniques using a binary search
    for (int i = 0; i < n; i++)
        arr[i] = find(tmp, num, arr[i]);
     
    // clean up the array created to store the sorted values
    free(tmp);
}

int main() {
    int n;
    in32(n);
    
    // Create and compress the array of values
    int * arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        in32(arr[i]);
    compress(arr, n);
     
    // find the minimum and maximum indices for each unique value in the array
    int * max = calloc(n, sizeof(int));
    int * min = calloc(n, sizeof(int));
    int largest = 0;
    for (int i = 0; i < n; i++) {
        if (largest < arr[i])
            largest = arr[i];
        max[arr[i]] = i;
        min[arr[n-i-1]] = n-i-1;
    }
    
    // Sweep through the array and greedily take intervals that do not overlap with the last
    int ans = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (i == max[arr[i]] && min[arr[i]]>=last){
            ans++;
            last = i;
        }
    }
    
    // Print the number of unique items differenced with the longest non-overlapping food groups
    out32(largest + 1 - ans);
    
    // Clean up memory
    free(arr);
    free(min);
    free(max);
    
    // Return
    return 0;
}