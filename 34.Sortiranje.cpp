#include <bits/stdc++.h>
using namespace std;
struct Name {
    string s;
    long long sum;
    int len;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<Name> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i].s;
        v[i].len=v[i].s.size();
        v[i].sum=0;
        for(char c:v[i].s) v[i].sum+=c-'A'+1;
    }
    stable_sort(v.begin(),v.end(),[](const Name& a,const Name& b){
        return a.sum*b.len < b.sum*a.len;
    });
    for(auto& x:v) cout<<x.s<<"\n";
    return 0;
}
