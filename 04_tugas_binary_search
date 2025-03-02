#include <iostream>
using namespace std;
int metode_ini(int arr[], int j, int k, int key) {
    while (j <= k)
    {
        int m = j + (k - j) / 2;
        if (arr[m] == key)
        {
            return m;
        }
        else if (arr[m] < key)
        {
            j = m + 1;
        }
        else
        {
            k = m - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
    {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int result = metode_ini(arr, 0, n - 1, key);
    if (result != -1)
    {
        cout << "Berhasil: " << result << endl;
    }
    else
    {
        cout << "Tidak Berhasil" << endl;
    }
    
    return 0;
}
