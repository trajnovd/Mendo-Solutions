#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long x=N;
    vector<int> koef;
    while(x){
        int r=x%3;
        if(r==0){
            koef.push_back(0);
            x/=3;
        } else if(r==1){
            koef.push_back(1);
            x=(x-1)/3;
        } else {
            koef.push_back(-1);
            x=(x+1)/3;
        }
    }
    vector<long long> ninopak, tinopak;
    ninopak.push_back(N);
    long long p=1;
    for(int i=0;i<(int)koef.size();i++){
        if(koef[i]==1) tinopak.push_back(p);
        else if(koef[i]==-1) ninopak.push_back(p);
        p*=3;
    }
    sort(ninopak.begin(),ninopak.end());
    sort(tinopak.begin(),tinopak.end());
    for(size_t i=0;i<ninopak.size();i++){
        cout<<ninopak[i]<<(i+1<ninopak.size()? ' ' : '\n');
    }
    for(size_t i=0;i<tinopak.size();i++){
        cout<<tinopak[i]<<(i+1<tinopak.size()? ' ' : '\n');
    }
    return 0;
}
