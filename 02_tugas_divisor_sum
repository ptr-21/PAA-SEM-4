#include<bits/stdc++.h>
using namespace std;
const int MAX = 500001;
long long int sum[MAX];
void precomputeSumOfDivisors() {
    for (int i=1; i<MAX; i++) {
        for (int j=2*i; j<MAX; j+=i) {
            sum[j] += i;
        }
    }
}
int main() {
    precomputeSumOfDivisors();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << sum[n] << "\n";
    }
    return 0;
}
