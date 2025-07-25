#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, m;
    cin >> n >> m;
    long long sumsquare = n * m;
    if(n > m){
        swap(n, m);
    }
    for(long long i = 2;i<=n;i++){
        sumsquare += (n - i + 1) * (m - i + 1);
    }
    long long sumsquare2 = ((1 + m) * m / 2) * (n + 1) * n / 2; 
    cout << sumsquare << " ";
    cout << sumsquare2 - sumsquare<< endl;
    return 0;
} 