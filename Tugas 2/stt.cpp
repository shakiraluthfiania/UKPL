#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    bool isStopped = false;
    string currentState = "Off";
    string nextState = "";
    do {
        // Display menu
        cout << "Current state: " << currentState << endl;
        cout << "1. Press button" << endl;
        cout << "2. Turn on" << endl;
        cout << "3. Turn off" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (currentState == "Off") {
                    nextState = "Off";
                } else if (currentState == "On") {
                    nextState = "Heating";
                } else if (currentState == "Heating") {
                    nextState = "On";
                }
                break;
            case 2:
                if (currentState == "Off") {
                    nextState = "On";
                } else if (currentState == "On") {
                    nextState = "On";
                } else if (currentState == "Heating") {
                    nextState = "Heating";
                }
                break;
            case 3:
                if (currentState == "Off") {
                    nextState = "Off";
                } else if (currentState == "On") {
                    nextState = "Off";
                } else if (currentState == "Heating") {
                    nextState = "Off";
                }
                break;
            case 4:
                isStopped = true;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        if (nextState != "") {
            cout << "Transitioning from " << currentState << " to " << nextState << endl;
            currentState = nextState;
            nextState = "";
        }
    } while (!isStopped);
    return 0;
}
