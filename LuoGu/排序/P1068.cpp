#include <bits/stdc++.h>
using namespace std;

struct candiate{
    int name;
    int score;
};

bool cmp(const candiate &a, const candiate &b){
    if(a.score != b.score){
        return a.score > b.score;
    }
    return a.name < b.name; 
}
vector<candiate> vec(5001);
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> vec[i].name >> vec[i].score;
    }
    sort(vec.begin(), vec.end(), cmp);
    m = m * 1.5;
    int sum = 0;
    for(int i = m; i < n; i++){
        if(vec[i].score == vec[m - 1].score){
            sum++;
        }
        else{
            break;
        }
    }
    m += sum;
    cout << vec[m-1].score << " " << m << endl;
    for(int i = 0; i < m; i++){
        cout << vec[i].name << " " << vec[i].score << endl;
    }
    return 0;
}