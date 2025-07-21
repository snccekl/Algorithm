#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int A = 1000001;
vector<int> v(A);
vector<ll> vec;
int main(){
    for (int i = 2; i < A; i++) {
		if (v[i] == 0) for (int j = i; j < A; j += i) v[j]++;
	}
    vector<ll> vec;
	for (ll i = 2; i < A; i++) if (v[i] == 2) vec.push_back(i * i);
    int q;
    cin >> q;
    while (q--) {
		ll a;
		cin >> a;
		cout << *prev(upper_bound(vec.begin(), vec.end(), a)) << '\n';
	}
}