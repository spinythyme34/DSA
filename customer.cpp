#include <iostream>
#include <string>
using namespace std;

class Customer {
    string counter[10]; 
    int front;
    int rear;

public:
    Customer() {
        front = 0;
        rear = 0;
    }

    void arrival(string arrive) {
        if ((rear + 1) % 10 != front) { 
            counter[rear] = arrive;
            rear = (rear + 1) % 10;
        } else {
            cout << "Waitlist is full." << endl;
        }
    }

    void checkout(string arrive) {
        int i = front;
        while (i != rear) {
            if (counter[i] == arrive) {
                cout << "Checking out " << arrive << endl;
                for (int j = i; j != (rear - 1 + 10) % 10; j = (j + 1) % 10) {
                    counter[j] = counter[(j + 1) % 10];
                }
                rear = (rear - 1 + 10) % 10;
                return;
            }
            i = (i + 1) % 10;
        }
        cout << "No such customer arrivals." << endl;
    }

    void closeCounter() {
        if (rear == front) {
            cout << "Counter is already empty." << endl;
        } else {
            cout << "Closing counter..." << endl;
            while (rear != front) {
                cout << "Checking out " << counter[front] << endl;
                front = (front + 1) % 10;
            }
            cout << "Counter closed." << endl;
        }
    }

    void display() {
        int i = front;
        while (i != rear) {
            cout << "Customer " << i << ": " << counter[i] << endl;
            i = (i + 1) % 10;
        }
    }
};

int main() {
    Customer c;
    int choice;

    while (true) {
        cout << "1. Arrival" << endl;
        cout << "2. Checkout" << endl;
        cout << "3. Close checkout counter" << endl;
        cout << "4. View customers" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string arrive;
                cout << "Enter customer name: ";
                getline(cin, arrive);
                c.arrival(arrive);
                break;
            }
            case 2: {
                string arrive;
                cout << "Enter who is checking out: ";
                getline(cin, arrive);
                c.checkout(arrive);
                break;
            }
            case 3: {
                c.closeCounter();
                break;
            }
            case 4: {
                c.display();
                break;
            }
            case 5: {
                cout << "Exiting" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
