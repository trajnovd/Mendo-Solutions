#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
 
using namespace std;
 
int main(){
int n;
cin >>n;
int brojac =0;
    for (int i = 0; i < n; i++) {
        string s,s1;
        cin>> s >> s1;
        sort(s.begin(), s.end());
        sort(s1.begin(),s1.end());
        if(s == s1){
            brojac++;
        }
    }
    cout << brojac;
}
