#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
 
int main() {
 
    int startHour, startMinute;
    int endHour, endMinute;
    int durationHour, durationMinute;
 
    // Input: start time
    cin >> startHour >> startMinute;
    // Input: end time
    cin >> endHour >> endMinute;
 
    // Calculate duration
    durationMinute = endMinute - startMinute;
    durationHour = endHour - startHour;
 
    if (durationMinute < 0) {
        // Adjust minutes and hours if end minutes are less than start minutes
        durationMinute += 60;
        durationHour -= 1;
    }
    if (durationHour < 0) {
        // Adjust hours if end hours are less than start hours (next day)
        durationHour += 24;
    }
 
    // Output formatted duration HH:MM
    cout << setfill('0') << setw(2) << durationHour << ":"
         << setfill('0') << setw(2) << durationMinute << endl;
 
    return 0;
}
