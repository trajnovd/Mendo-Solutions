#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <set>
using namespace std;
 
int main(){
    int a[12];
    set<int> s;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        s.insert(a[i]%42);
    }
   cout << s.size();
}
