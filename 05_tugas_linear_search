#include <iostream>
using namespace std;
int metode_ini(int arr[], int n, int key){
    for (int i = 0; i < n; ++i)
    {
        if (arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
    {
        int arr[] = {10, 20, 30, 40, 50};
        int n = sizeof(arr)/sizeof(arr[0]);
        // fungsi sizeof adalah untuk mencari tahu byte kodenya
        // kode diatas menggunakan sizeof arr dibagi sizeof arr agar
        // lebih cepat dalam artian limit perulangan for i < n diatas
        // n nya di limit
        int key = 30;
        int result = metode_ini(arr, n, key);
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
