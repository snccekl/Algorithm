#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> prime;
bool is_prime[N];

void sieve(int n) {
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i < n; i++){
        if(is_prime[i]){
            for(int j = i * i; j < n; j += i){
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i < n; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    sieve(N);
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(is_prime[x]) {
            cout << x << " ";
        }
    }
    return 0;
}