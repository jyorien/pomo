
#ifdef WIN32
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
    int pomoCounter = 0;
    while(true) {
        for (int i = 0; i < 4; i++) {
        const string currentPosition = positions[i];
        const int breakTime = (i == 3) ? 15 : 5; 
        minutesTimer(3, currentPosition, "Work");
        pomoCounter += 1;
        cout << "Start break? (y): ";
        cin.ignore();
        minutesTimer(3, currentPosition, "Break");
        if (i != 0) {
            cout << "Start next pomo? (y): ";
            cin.ignore();
        } else {
            char response;
            cout << "Would you like to continue? (y/n): ";
            cin >> response;
            if (response != 'y') {
                cout << "Total pomos completed: " << pomoCounter;
                goto endLoop;
            }
        }
    }

    }
    endLoop:
        return 0;
}

void minutesTimer(int numberOfMinutes, string currentPosition, string mode) {
    const int numberOfSeconds = numberOfMinutes * 60;

    for (int i = numberOfSeconds; i >= 0; --i) {
        // back to start of line
        cout << "\r";

        // format current minute
        int minute = floor(i/60);
        string formattedMinute = to_string(minute);
        formattedMinute = (formattedMinute.length() == 1) ? "0"+formattedMinute : formattedMinute;

        // format current second
        int second = i % 60;
        string formattedSecond = to_string(second);
        formattedSecond = (formattedSecond.length() == 1) ? "0"+formattedSecond : formattedSecond;

        // sleep for a second
        #ifdef WIN32
        Sleep(1000);
        #else
        sleep(1);
        #endif

        cout << currentPosition << " Pomo " << "(" << mode << ")" << ": " <<formattedMinute << ":" << formattedSecond;
        cout.flush();
    }
    cout << endl;
}