#include <iostream>
#include <string>
using namespace std;

class JobQueue {
private:
    string jobIds[20];
    string descriptions[20];
    int priorities[20];
    int front;
    int rear;
    int size;

public:
    JobQueue() {
        front = rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == 20;
    }

    void insertJob(string id, string desc, int priority, bool atFront) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (size == 0) {
            front = rear = 0;
        } else if (atFront) {
            front = (front - 1 + 20) % 20;
        } else {
            rear = (rear + 1) % 20;
        }
        jobIds[front] = id;
        descriptions[front] = desc;
        priorities[front] = priority;
        size++;
        cout << "Job " << id << " added successfully" << endl;
    }

    void removeJob(bool fromFront) {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (fromFront) {
            cout << "Job " << jobIds[front] << " removed from front" << endl;
            front = (front + 1) % 20;
        } else {
            cout << "Job " << jobIds[rear] << " removed from rear" << endl;
            rear = (rear - 1 + 20) % 20;
        }
        size--;
    }

    void displayJobs() {
        if (size == 0) {
            cout << "No jobs in the queue" << endl;
            return;
        }
        int current = front;
        cout << "\nCurrent Jobs:\n";
        for (int i = 0; i < size; i++) {
            cout << "Job " << (i + 1) << ": ID=" << jobIds[current] 
                 << ", Description=" << descriptions[current] 
                 << ", Priority=" << priorities[current] << endl;
            current = (current + 1) % 20;
        }
    }

    void searchJob(string id) {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int current = front;
        for (int i = 0; i < size; i++) {
            if (jobIds[current] == id) {
                cout << "Job found: ID=" << jobIds[current] 
                     << ", Description=" << descriptions[current] 
                     << ", Priority=" << priorities[current] << endl;
                return;
            }
            current = (current + 1) % 20;
        }
        cout << "Job with ID " << id << " not found" << endl;
    }
};

int main() {
    JobQueue jobQueue;
    int choice;
    string id, desc;
    int priority;

    while (true) {
        cout << "\n1. Add High Priority Job (Front)\n";
        cout << "2. Add Normal Priority Job (Rear)\n";
        cout << "3. Remove Job from Front\n";
        cout << "4. Remove Job from Rear\n";
        cout << "5. Display All Jobs\n";
        cout << "6. Search for a Job\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> id;
                cout << "Enter Job Description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter Priority (1-10): ";
                cin >> priority;
                jobQueue.insertJob(id, desc, priority, true);
                break;

            case 2:
                cout << "Enter Job ID: ";
                cin >> id;
                cout << "Enter Job Description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter Priority (1-10): ";
                cin >> priority;
                jobQueue.insertJob(id, desc, priority, false);
                break;

            case 3:
                jobQueue.removeJob(true);
                break;

            case 4:
                jobQueue.removeJob(false);
                break;

            case 5:
                jobQueue.displayJobs();
                break;

            case 6:
                cout << "Enter Job ID to search: ";
                cin >> id;
                jobQueue.searchJob(id);
                break;

            case 7:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
