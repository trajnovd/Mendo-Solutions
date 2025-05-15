#include <iostream>
#include <algorithm>
using namespace std;
string a,b;
int memo[305][305];
int rec(int i,int j){
    if(i == -1 || j == -1){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int result = 0;
    if(a[i] == b[j]){
        result = max(result,rec(i-1,j-1)+1);
    }
    result = max(result, rec(i-1,j));
    result = max(result,rec(i,j-1));
    return memo[i][j] = result;
}
int main()
{
    int n;
    cin >> n;
 
 
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < 300; ++i) {
            for (int j = 0; j < 300; ++j) {
                memo[i][j] = -1;
            }
        }
        cin >> a >> b;
        int res;
        res = rec(a.size()-1,b.size()-1);
        if(res == a.size()){
            cout << "DA" <<endl;
        }
        else
            cout << "NE" << endl;
 
    }
 
}
