#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
 
int main(){
   string s;
   cin >> s;
   int brojac=0;
    for (int i = 0; i < s.size()-1; i++) {
        if(s[i+1] != 'a' && s[i+1] != 'e' && s[i+1] != 'i' && s[i+1] != 'o' && s[i+1] != 'u' && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] !='o' && s[i] != 'u'){
            brojac++;
        }
    }
    cout << brojac;
}
