#include <iostream>
#include <string>
using namespace std;

class Restaurant {
    string waitlist[10];
    int front;
    int rear;

public:
    Restaurant() {
        front = 0;
        rear = 0;
    }

    void addParty(string party) {
        if (rear < 10) {
            waitlist[rear] = party;
            rear = (rear + 1) % 10;
        } else {
            cout << "Waitlist is full." << endl;
        }   
    }

    void deleteParty(string party) {
        for (int i = front; i != rear; i = (i + 1) % 10) {
            if (waitlist[i] == party) {
                cout << "deleting party of " << party << endl;
                for (int j = i; j != rear - 1; j = (j + 1) % 10) {
                    waitlist[j] = waitlist[(j + 1) % 10];
                }
                rear = (rear - 1 + 10) % 10;
                return;
            }
        }
        cout << "party not found in waitlist." << endl;
    }

    void displayWaitlist() {
        for (int i = front; i != rear; i = (i + 1) % 10) {
            cout << "\nParty of " << waitlist[i] << endl;
        }
    }
};

int main() {
    Restaurant r;
    int choice;
    while (true) {
        cout << "\n1. Add party to waitlist" << endl;
        cout << "2. Delete party from waitlist" << endl;
        cout << "3. Display waitlist" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;
        switch (choice) {
            case 1: {
                string party;
                cout << "Enter party name"
                cin.ignore();
                getline(cin, party);
                r.addParty(party);
                break;
            }
            case 2: {
                string party;
                cout << "Enter people in the party to delete ";
                cin.ignore();
                getline(cin, party);
                r.deleteParty(party);
                break;
            }
            case 3:
                r.displayWaitlist();
                break;
            case 4:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}