#include <bits/stdc++.h>
using namespace std;

bool visited[10] = {false};
bool flag = false;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    for(int i = 1;i<=9;i++){
        visited[i] = true;
        for(int j = 1;j<=9;j++){
            if(visited[j]) continue;
            visited[j] = true;
            for(int k = 1;k<=9;k++){
                if(visited[k]) continue;
                visited[k] = true;
                for(int l = 1;l<=9;l++){
                    if(visited[l]) continue;
                    visited[l] = true;
                    for(int m = 1;m<=9;m++){
                        if(visited[m]) continue;
                        visited[m] = true;
                        for(int n = 1;n<=9;n++){
                            if(visited[n]) continue;
                            visited[n] = true;
                            for(int o = 1;o<=9;o++){
                                if(visited[o]) continue;
                                visited[o] = true;
                                for(int p = 1;p<=9;p++){
                                    if(visited[p]) continue;
                                    visited[p] = true;
                                    for(int q = 1;q<=9;q++){
                                        if(visited[q]) continue;
                                        visited[q] = true;
                                        
                                        int n1 = i * 100 + j * 10 + k;
                                        int n2 = l * 100 + m * 10 + n;
                                        int n3 = o * 100 + p * 10 + q;
                                        if(double(n1)/n2 == double(a)/b && double(n2)/n3 == double(b)/c){
                                            flag = true;
                                            cout<<n1<<" "<<n2<<" "<<n3<<endl;    
                                        }

                                        visited[q] = false;
                                    }
                                    visited[p] = false;
                                }
                                visited[o] = false;
                            }
                            visited[n] = false;
                        }
                        visited[m] = false;
                    }
                    visited[l] = false;
                }
                visited[k] = false;
            }
            visited[j] = false;
        }
        visited[i] = false;
    }
    if(!flag) cout<<"No!!!"<<endl;
    return 0;
}