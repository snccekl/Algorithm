#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,long long>>> G(15);
bool visited[15];
int n;
long long ans = LONG_LONG_MAX;
void dfs(int v, long long temp){
    if(v == n){
        ans = min(ans, temp);
        return;
    }
    visited[v] = true;
    for(auto x : G[v]){
        if(!visited[x.first]){
            dfs(x.first, temp ^ x.second);
        }
    }
    visited[v] = false;

}
int main(){
    int m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}