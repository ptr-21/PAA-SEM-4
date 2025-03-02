#include <stdio.h>
int binarysearch(int arr[], int low , int high, int key){
    if (low>high)
    {
        return -1;
    }
    int mid = low + (high-low)/2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid]<key)
    {
        return binarysearch(arr, mid + 1, high, key);
    }
    else
    {
        return binarysearch(arr, low, mid - 1, key);
    }
    
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 14;
    int result = binarysearch(arr, 0, n-1, key);
    if (result == -1)
    {
        printf("Elemen tidak ditemukan");
    }
    else
    {
        printf("Elemen ditemukan pada indeks %d\n", result);
    }
    
    return 0;
}
