#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool userExists(string username) {
    ifstream file((username + ".txt").c_str());
    return file.good();
}

void registerUser() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists!" << endl;
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file((username + ".txt").c_str());

    if (!file) {
        cout << "Error creating file!" << endl;
        return;
    }

    file << password;
    file.close();

    cout << "Registration Successful!" << endl;
}

void loginUser() {
    string username, password, storedPassword;

    cout << "Enter Username: ";
    cin >> username;

    ifstream file((username + ".txt").c_str());

    if (!file) {
        cout << "User not found!" << endl;
        return;
    }

    file >> storedPassword;
    file.close();

    cout << "Enter Password: ";
    cin >> password;

    if (password == storedPassword)
        cout << "Login Successful!" << endl;
    else
        cout << "Incorrect Password!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}
