#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
 
using namespace std;
int dist (int x1,int x2,int y1,int y2){
    return ((x2 - x1) *(x2 - x1)  + (y2 - y1) *  (y2- y1));
}
int main(){
    int n;
    cin>> n;
    pair<int ,int> p[105];
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
 
    int brojac =0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int dist1 = dist(p[i].first,p[j].first,p[i].second,p[j].second);
                int dist2 = dist(p[i].first,p[k].first,p[i].second,p[k].second);
                int dist3 = dist(p[j].first,p[k].first,p[j].second,p[k].second);
 
                if(dist1> dist2 && dist1 > dist3 ){
                    if(dist1 == dist2 + dist3){
                        brojac++;
                    }
                }
                else if(dist2> dist1 && dist2 >dist3){
                    if(dist2== dist1 + dist3){
                        brojac++;
                    }
                }
                else if(dist3 > dist1 && dist3>dist2){
                    if(dist3 == dist1 + dist2){
                        brojac++;
                    }
                }
            }
        }
    }
    cout << brojac/6;
}
