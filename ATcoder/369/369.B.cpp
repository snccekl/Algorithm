//
// Created by Lenovo on 2025/3/8.
//
#include <bits/stdc++.h>
using namespace std;
stack<int> Stack;
int main() {
    int n;
    cin >> n;
    for(int i = 0;i<100;i++){
        Stack.push(0);
    }
    for(int i = 0;i<n;i++){
        int a;
        cin >> a;
        if(a == 1){
            int x;
            cin>>x;
            Stack.push(x);
        }
        else if(a == 2) {
            cout<<Stack.top()<<endl;
            Stack.pop();
        }
    }
    return 0;
}