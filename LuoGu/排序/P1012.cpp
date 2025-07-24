#include <bits/stdc++.h>
using namespace std;

vector<string> vec(25);

bool cmp(const string &a, const string &b){
    return a+b > b+a; 
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.begin() + n, cmp);
    string ans;
    for(int i = 0; i < n; i++){
        ans += vec[i];
    }
    cout << ans << endl;
    return 0;
}
