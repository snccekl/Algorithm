#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    long long sum = 0;
    long long temp = 1;
    for(int i = 0; i <= m; i++){
        sum += temp;
        temp *= n;
        if(sum > 1000000000){
            cout << "inf";
            return 0;
        }
    }
    cout << sum;
    return 0;
}