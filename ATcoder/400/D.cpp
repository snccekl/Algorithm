#include <bits/stdc++.h>
using namespace std;
#define int long long
char s[1010][1010];
int G[1010][1010];
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++) cin>>s[i];
    int a,b,c,d;cin>>a>>b>>c>>d;
    --a,--b,--c,--d;
    memset(G,0x3f,sizeof G);
    G[a][b] = 0;
    deque<pair<int,int>> q;
    q.emplace_back(a,b);
    while(q.size()){
        auto [x,y] = q.front();q.pop_front();
        if(x == c && y == d){
            cout<<G[x][y]<<endl;
            return 0;
        }
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                if(abs(i) + abs(j) != 1) continue;
                int nx = x + i,ny = y + j;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(s[nx][ny] == '#') continue;
                if(G[nx][ny] <= G[x][y]) continue;
                G[nx][ny] = G[x][y];
                q.emplace_front(nx,ny);
            }
        }
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                if(abs(i) + abs(j) != 1) continue;
                for(int o=1;o<3;++o){
                    int nx = x + i * o,ny = y + j * o;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(G[nx][ny] <= G[x][y] + 1) continue;
                    G[nx][ny] = G[x][y] + 1;
                    q.emplace_back(nx,ny);
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// char s[2010][2010];
// int dis[2010][2010];
// signed main() {
//     cin.tie(0)->sync_with_stdio(false);
//     int n,m;cin>>n>>m;
//     for(int i=0;i<n;++i)cin>>s[i];
//     int a,b,c,d;cin>>a>>b>>c>>d;
//     --a,--b,--c,--d;
//     deque<pair<int,int>>q;
//     memset(dis,0x3f,sizeof dis);
//     q.emplace_back(a,b);
//     dis[a][b]=0;
//     const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
//     while(q.size()){
//         auto [x,y]=q.front();q.pop_front();
//         if(x==c&&y==d){cout<<dis[x][y]<<'\n';return 0;}
//         for(int d=0;d<4;++d){
//             int i=x+dx[d],j=y+dy[d];
//             if(i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.'&&dis[i][j]>dis[x][y]){
//                 dis[i][j]=dis[x][y];
//                 q.emplace_front(i,j);
//             }
//         }
//         for(int d=0;d<4;++d){
//             for(int o=1;o<3;++o){
//                 int i=x+dx[d]*o,j=y+dy[d]*o;
//                 if(i>=0&&i<n&&j>=0&&j<m&&dis[i][j]>dis[x][y]+1){
//                     dis[i][j]=dis[x][y]+1;
//                     q.emplace_back(i,j);
//                 }
//             }
//         }
//     }
//     cout<<"-1\n";
//     return 0;
// }
