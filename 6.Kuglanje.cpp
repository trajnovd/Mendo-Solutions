#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
int memo[105][105];
int matrix[105][105];
int n;
int dp (int i ,int j){
    if(i == n-1){
        return matrix[i][j];
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int dole = 0, diagonalno = 0;
    dole = max(dole,dp(i+1,j) + matrix[i][j]);
    diagonalno = max(diagonalno,dp(i+1,j+1) + matrix[i][j]);
    int res = max(dole,diagonalno);
    return memo[i][j] = res;
}
int main(){
 
cin >> n;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            memo[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i>=j){
                cin >> matrix[i][j];
            }
 
        }
    }
    cout << dp(0,0) ;
}
