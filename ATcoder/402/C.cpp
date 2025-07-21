#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> idx(1000000);
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m);
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        cnt[i] = k;
        for(int j = 0;j<k;j++){
            int x;
            cin>>x;
            x--;
            idx[x].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        x--;
        for (auto id : idx[x]) {
            cnt[id]--;
            if (cnt[id] == 0)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}