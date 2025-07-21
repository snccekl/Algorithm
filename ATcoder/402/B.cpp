#include <bits/stdc++.h>
using namespace std;
vector<int> menu;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n == 1) {
            int x;
            cin >> x;
            menu.push_back(x);
        }
        else if(n == 2){
            cout<<menu.front()<<endl;
            menu.erase(menu.begin());
        }
    }
    return 0;
}