#include <bits/stdc++.h>
using namespace std;

int main(){
    long long score = 0;
    int n,m;
    cin>>n>>m;
    vector<int> white(m);
    vector<int> black(n);
    for(int i = 0;i<n;i++){
        cin>>black[i];
    }
    for(int i = 0;i<m;i++){
        cin>>white[i];
    }
    sort(black.begin(), black.end(), greater<int>());
    sort(white.begin(), white.end(), greater<int>());
    int numblack = 0;
    int numwhite = 0;
    for(int i = 0;i<n;i++){
        if(black[i] >= 0){
            numblack++;
            score += black[i];
        }
        else{
            break;
        }
    }
    for(int i = 0;i<numblack;i++){
        if(white[i] > 0){
            numwhite++;
            score += white[i];
        }
        else{
            break;
        }
    }
    int l = black.size();
    if(numwhite == m){
        cout<<score;
        return 0;
    }
    for(int i = numblack;i<l;i++){
        if(white[numwhite] > 0 && white[numwhite] > abs(black[i]) && numwhite < m){
            score = score + white[numwhite] + black[i];
            numwhite++;
        }
        else{
            break;
        }
    }
    cout<<score;
    return 0;
}