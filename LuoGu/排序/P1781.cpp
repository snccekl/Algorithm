#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string & b) {
    if(a.size() != b.size()) {
        return a.size() > b.size();
    }
    return a > b;
}

int main(){
    int n;
    cin >> n;
    int winner = 1;
    string vote;
    cin>>vote;
    for(int i = 1; i < n; i++){
        string current_vote;
        cin >> current_vote;
        if(cmp(current_vote, vote)) {
            vote = current_vote;
            winner = i + 1; 
        }
    }
    cout << winner << endl;
    cout << vote << endl;
    return 0;

}