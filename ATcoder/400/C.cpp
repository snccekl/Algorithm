#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n;
    cin >> n;
    long long c1 = sqrtl(n / 2), c2 = sqrtl(n / 4);
    long long ans = c1 + c2;
    cout<<ans<<endl;
    return 0;
}