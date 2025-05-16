#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
 
int main() {
    int s,r;
    cin >> s >>r;
    char mat[s][r];
    for(int i =0;i<s;i++){
        for(int j = 0;j<r;j++){
            cin >> mat[i][j];
        }
    }
    bool visited[s][r];
    for(int i = 0;i<s;i++){
        for(int j = 0;j<r;j++){
            visited[i][j] = false;
        }
    }
    int volci_kraj = 0;
    int ovci_kraj = 0;
     
    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};
     
    for(int i =0;i<s;i++){
        for(int j = 0;j<r;j++){
            if(mat[i][j] != '#' and !visited[i][j]){
                queue<int>q;
                q.push(i);
                q.push(j);
                visited[i][j] = true;
                int ovci = 0, volci = 0;
                while(!q.empty()){
                    int ti = q.front();
                    q.pop();
                    int tj = q.front();
                    q.pop();
                     
                    if(mat[ti][tj] == 'o') ovci++;
                    if(mat[ti][tj] == 'v') volci++;
                     
                     
                    for(int k = 0;k<4;k++){
                        int ci = ti+di[k];
                        int cj = tj +dj[k];
                        if(ci>=0 and ci<s and cj>=0 and cj<r and mat[ci][cj]!='#' and !visited[ci][cj]){
                            visited[ci][cj] = true;
                            q.push(ci);
                            q.push(cj);
                        }
                    }
                     
                }
                if(volci>=ovci) volci_kraj+= volci;
                else ovci_kraj+=ovci;
            }
        }
    }
    cout << ovci_kraj   << " " << volci_kraj;
