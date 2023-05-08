#include <iostream> //library
#include <string>

using namespace std;
//membuat fungsi isUsernameValid untuk memvalidasi username
bool isUsernameValid(string username) {
    // equivalence class partitioning
    if (username.length() < 6 || username.length() > 20) {
        return false; // invalid length
    }
    for (int i = 0; i < username.length(); i++) {
        if (!isalnum(username[i])) {
            return false; // contains non-alphanumeric characters
        }
    }
    return true;
}
//membuat fungsi isPasswordValid untuk memvalidasi password
bool isPasswordValid(string password) {
    // equivalence class partitioning
    if (password.length() < 8 || password.length() > 30) {
        return false; // invalid length
    }
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    for (int i = 0; i < password.length(); i++) {
        if (isupper(password[i])) {
            hasUppercase = true;
        } else if (islower(password[i])) {
            hasLowercase = true;
        } else if (isdigit(password[i])) {
            hasDigit = true;
        } else {
            hasSpecialChar = true;
        }
    }
    if (!(hasUppercase && hasLowercase && hasDigit && hasSpecialChar)) {
        return false; // doesn't meet complexity requirement
    }
    return true;
}
//membuat fungsi main (tampilan menu)
int main() {
    int choice = 0;
    do {
        cout << "Menu:" << endl;
        cout << "1. Test username validation" << endl;
        cout << "2. Test password validation" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string username;
                cout << "Enter username: ";
                cin >> username;
                bool isValid = isUsernameValid(username);
                if (isValid) {
                    cout << "Username is valid" << endl;
                } else {
                    cout << "Username is invalid" << endl;
                }
                break;
            }
            case 2: {
                string password;
                cout << "Enter password: ";
                cin >> password;
                bool isValid = isPasswordValid(password);
                if (isValid) {
                    cout << "Password is valid" << endl;
                } else {
                    cout << "Password is invalid" << endl;
                }
                break;
            }
            case 3: {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice, please try again" << endl;
                break;
            }
        }
    } while (choice != 3);
    return 0;
}
