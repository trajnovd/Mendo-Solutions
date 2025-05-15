#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
 
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(b-a-1,c-b-1);
}
