#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> G(1000000);
bool visited[1000000];
int val[1000000];
int ans[1000000];
void dfs(int v){

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            
        }
    }
}   