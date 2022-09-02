
#ifdef WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void minutesTimer(int numberOfMinutes, string currentPosition, string mode);
int main() {
    const string positions[] = {"First", "Second", "Third", "Last"};
    for (int i = 0; i < 4; i++) {
        const string currentPosition = positions[i];
        const int breakTime = (i == 3) ? 15 : 5; 
        minutesTimer(1, currentPosition, "Work");
        minutesTimer(1, currentPosition, "Break");
    }


    return 0;
}

void minutesTimer(int numberOfMinutes, string currentPosition, string mode) {
    const int numberOfSeconds = numberOfMinutes * 60;

    for (int i = numberOfSeconds; i >= 0; --i) {
        // back to start of line
        cout << "\r";
        // format current minute and second
        int minute = floor(numberOfSeconds/60)-1;
        string formattedMinute = to_string(minute);
        formattedMinute = (formattedMinute.length() == 1) ? "0"+formattedMinute : formattedMinute;
        int second = i % 60;
        string formattedSecond = to_string(second);
        formattedSecond = (formattedSecond.length() == 1) ? "0"+formattedSecond : formattedSecond;
        // sleep for a second
        #ifdef WINDOWS
        // sleep in windows
        #else
        sleep(1);
        #endif

        cout << currentPosition << " Pomo " << "(" << mode << ")" << ": " <<formattedMinute << ":" << formattedSecond;
        cout.flush();
    }
    cout << endl;
}