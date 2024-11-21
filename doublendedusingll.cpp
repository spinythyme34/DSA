    #include <iostream>
    #include <string>
    using namespace std;

    class Job {
    public:
        string jobId;
        string description;
        int priority;
        Job* next;
        Job* prev;

        Job(string id, string desc, int prio) {
            jobId = id;
            description = desc;
            priority = prio;
            next = nullptr;
            prev = nullptr;
        }
    };

    class JobQueue {
    private:
        Job* front;
        Job* rear;
        int size;

    public:
        JobQueue() {
            front = nullptr;    
            rear = nullptr;
            size = 0;
        }

        bool isFull() {
            return size == 20;

        }

        void insertFront(string id, string desc, int priority) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }
            Job* newJob = new Job(id, desc, priority);
            if (size == 0) {
                front = rear = newJob;
            } else {
                newJob->next = front;
                front->prev = newJob;
                front = newJob;
            }
            size++;
            cout << "Job " << id << " added at front successfully" << endl;
        }

        void insertRear(string id, string desc, int priority) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }
            Job* newJob = new Job(id, desc, priority);
            if (size == 0) {
                front = rear = newJob;
            } else {
                rear->next = newJob;
                newJob->prev = rear;
                rear = newJob;
            }
            size++;
            cout << "Job " << id << " added at rear successfully" << endl;
        }

        void removeFront() {
            if (size == 0) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Job " << front->jobId << " removed from front" << endl;
            Job* temp = front;
            front = front->next;
            if (front != nullptr) {
                front->prev = nullptr;
            } else {
                rear = nullptr; // If the queue becomes empty
            }
            delete temp;
            size--;
        }

        void removeRear() {
            if (size == 0) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Job " << rear->jobId << " removed from rear" << endl;
            Job* temp = rear;
            rear = rear->prev;
            if (rear != nullptr) {
                rear->next = nullptr;
            } else {
                front = nullptr; // If the queue becomes empty
            }
            delete temp;
            size--
        }

        void displayJobs() {
            if (size == 0) {
                cout << "Job queue is empty\n";
                return;
            }

            cout << "\nCurrent Jobs in Queue:\n";
            Job* current = front;
            while (current != nullptr) {
                cout << "\nJob ID: " << current->jobId << "\n";
                cout << "Description: " << current->description << "\n";
                cout << "Priority: " << current->priority << "\n";
                current = current->next;
            }
        }

        void searchJob(string id) {
            if (size == 0) {
                cout << "Job queue is empty\n";
                return;
            }

            Job* current = front;
            while (current != nullptr) {
                if (current->jobId == id) {
                    cout << "Job found:\n";
                    cout << "ID: " << current->jobId << "\n";
                    cout << "Description: " << current->description << "\n";
                    cout << "Priority: " << current->priority << "\n";
                    return;
                }
                current = current->next;
            }
            cout << "Job with ID " << id << " not found.\n";
        }
    };

    int main() {
        JobQueue jobQueue;
        int choice;
        string id, desc;
        int priority;

        while (true) {
            cout << "\nJob Queue Menu:\n";
            cout << "1. Add High Priority Job (Front)\n";
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
                    cout << "Enter Job Priority: ";
                    cin >> priority;
                    jobQueue.insertFront(id, desc, priority);
                    break;
                case 2:
                    cout << "Enter Job ID: ";
                    cin >> id;
                    cout << "Enter Job Description: ";
                    cin.ignore();
                    getline(cin, desc);
                    cout << "Enter Job Priority: ";
                    cin >> priority;
                    jobQueue.insertRear(id, desc, priority);
                    break;
                case 3:
                    jobQueue.removeFront();
                    break;
                case 4:
                    jobQueue.removeRear();
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
                    cout << "Exiting the program.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        return 0;
    }
 