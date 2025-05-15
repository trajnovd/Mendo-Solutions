#include <bits/stdc++.h>
  
using namespace std;
int main()
{
  
    int n;
    cin>>n;
    int ar[n];
    int nt=n;
    for(int ctr1=0; ctr1<n; ctr1++)
        cin>>ar[ctr1];
    sort(ar,ar+n);
    reverse(ar,ar+n);
    for(int ctr2=0; ctr2<n; ctr2++)
    {
        nt-=(ar[ctr2]+1);
        if(nt<=0)
        {
            cout<<ctr2+1;
            return 0;
        }
    }
    return 0;
}
