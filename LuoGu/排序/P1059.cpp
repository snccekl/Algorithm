#include <bits/stdc++.h>
using namespace std;


int main(){
    set<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);    
    }
    cout<<s.size()<<endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    return 0;
}