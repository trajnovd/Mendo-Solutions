#include <iostream>
#include <cmath>
  
using namespace std;
  
string rnk;
int n;
int dp[201][201];
  
bool vrska(int a,int b){
    if(rnk[a]=='A' && rnk[b]=='U')
        return 1;
    if(rnk[a]=='U' && rnk[b]=='A')
        return 1;
    if(rnk[a]=='C' && rnk[b]=='G')
        return 1;
    if(rnk[a]=='G' && rnk[b]=='C')
        return 1;
    if(rnk[a]=='G' && rnk[b]=='U')
        return 1;
    if(rnk[a]=='U' && rnk[b]=='G')
        return 1;
    return 0;
}
  
int pogolem(int a,int b){
    return a>b?a:b;
}
  
int dpf(int a,int b){
    if(abs(b-a)<2)
        return 0;
    else if(dp[a][b]==0){
        for(int ctr1=a+2;ctr1<=b;ctr1++){
            if(vrska(a,ctr1))
            dp[a][b]=pogolem(dp[a][b],1+dpf(a+1,ctr1-1)+dpf(ctr1+1,b));
        }
        dp[a][b]=pogolem(dp[a][b],dpf(a+1,b));
    }
    return dp[a][b];
}
  
  
  
  
int main(){
  
    cin>>n;
    cin>>rnk;
    cout<<dpf(0,n-1);
  
    return 0;
}
