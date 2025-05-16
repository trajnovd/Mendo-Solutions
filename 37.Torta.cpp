#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
 
int main() {
    int n,k;
    cin >>n >> k;
    pair<int,int> p[k];
    for(int i = 0;i<k;i++){
        cin >> p[i].first >> p[i].second;
    }
    int res=0;
    int min_cena = 2e9;
    for(int i = 0;i<k;i++){
        int min;
        if(p[i].first <=  p[i].second*6){
            min = p[i].first;
        }
        else min = p[i].second*6;
         
        if(min < min_cena) min_cena = min;
    }
    res += (n/6)*min_cena;
    n = n -(n/6)*6;
    int min_za_ostanatite= 2e9;
    for(int i =0;i<k;i++){
        int res1= 0;
        res1 = n*p[i].second;
        if(res1< p[i].first){
            if(res1<min_za_ostanatite) min_za_ostanatite = res1;
        }
        else{
            if(p[i].first<min_za_ostanatite) min_za_ostanatite = p[i].first;
        }
    }
    cout << res+min_za_ostanatite;
}
