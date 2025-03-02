#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    int n;
    cout << "Masukkan jumlah bilangan: "; //sebagai printf
    cin >> n; // sebagai scanf
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cout<<"Masukkan bilangan ke-"<< i+1 << ": ";
        cin>>numbers[i];
    }
    for (const auto& num : numbers)
    {
        int sum = 0;
        for (int i = 2; i <= num/2; ++i)
        {
            if (num % i == 0)
            {
                sum += i;
            }
            
        }
        if (num != 1)
        {
            sum += 1;
        }
        cout << sum << endl;
    }
    return 0;
}
