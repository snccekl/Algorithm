#include <bits/stdc++.h>
using namespace std;

struct score{
    int id;
    int chinese;
    int math;
    int english;
    int total;
};
bool cmp(const score &a, const score &b){
    if(a.total != b.total) return a.total > b.total;
    if(a.chinese != b.chinese) return a.chinese > b.chinese;
    return a.id < b.id;
}
int main(){
    int n;
    cin >> n;
    vector<score> scores(n);
    for(int i = 0; i < n; i++){
        cin >>scores[i].chinese >> scores[i].math >> scores[i].english;
        scores[i].total = scores[i].chinese + scores[i].math + scores[i].english;
        scores[i].id = i + 1;
    }
    sort(scores.begin(), scores.end(), cmp);
    
    for(int i = 0;i<5;i++){
        const auto &s = scores[i];
        cout << s.id << " " << s.total << endl;
    }
    return 0;

}