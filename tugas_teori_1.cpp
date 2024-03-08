#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    const int max = 50001;
    long long int sum[max];
    for (int i = 1; i < max; i++)
    {
        for (int j = 2*i; j < max; j+=i)
        {
            sum[j] += i;
        }
        
    }
    int i;
    cin >> i;
    while (i--)
    {
        int n;
        cin >> n;
        cout << sum[n] << "\n" << endl;
    }
    return 0;
}
