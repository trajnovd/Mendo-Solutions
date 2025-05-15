#include <iostream>
using namespace std;
  
int main()
{
    int x,y,pstef=0,pana=0,maxstef=0,maxana=0,cifx=0,cify=0,ctr1,ctr2,x1,y1;
    for (ctr1=0;ctr1<3;ctr1++)
    {
    cin>>x>>y;
    cifx=0;
    cify=0;
    x1=x;
    y1=y;
    for (ctr2=0;ctr2<3;ctr2++)
    {
    cifx=cifx+x1%10;
    x1=x1/10;
    }
    for (ctr2=0;ctr2<3;ctr2++)
    {
    cify=cify+y1%10;
    y1=y1/10;
    }
    if (x%cifx==0)
    {
        pstef=pstef+2;
        pana=pana-1;
    }
    if (y%cify==0)
    {
        pana=pana+2;
        pstef=pstef-1;
    }
    if (x>maxstef)
    {
        maxstef=x;
    }
    if (y>maxana)
    {
        maxana=y;
    }
  
  
    }
    cout<<pstef<<" "<<pana<<endl;
    if (pstef>pana)
    {
        cout<<"Stefan";
    }
    if (pana>pstef)
    {
        cout<<"Ana";
    }
    if(pana==pstef)
    {
        if (maxstef>maxana)
        {
            cout<<"Stefan";
        }
        else cout<<"Ana";
    }
    return 0;
}
