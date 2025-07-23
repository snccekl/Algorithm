#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;

vector<int> vec(INF);
int main(){
    int n, m;
    cin >> n >> m;
    //这是用stl-sort的方式
    // for(int i = 0; i < m; i++) {
    //     cin>> vec[i];
    // }
    // sort(vec.begin(), vec.begin() + m);
    // for(int i = 0; i < m; i++) {
    //     cout << vec[i] << " ";
    // }
    // return 0;

    //这是桶排
    for(int i = 0;i<m;i++){
        int x;
        cin >> x;
        vec[x]++;
    }
    for(int i = 0;i<1000;i++){
        if(vec[i] > 0){
            for(int j = 0;j<vec[i];j++){
                cout << i << " ";
            }
        }
    }
    return 0;
}