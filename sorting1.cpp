#include <iostream>
#include <string>
using namespace std;
class Student {
 int id;
 string fullName;
 double gpa;
public:
 void inputDetails();
 void sortByID(Student arr[], int count);
 void sortByName(Student arr[], int count);
 void showDetails(Student arr[], int count);
};
void Student::inputDetails() {
 cout << "\nEnter Roll Number: ";
 cin >> id;
 cin.ignore(); // To consume the leftover newline
 cout << "Enter Full Name: ";
 getline(cin, fullName);
 cout << "Enter SGPA: ";
 cin >> gpa;
}
void Student::sortByID(Student arr[], int count) {
 for (int i = 1; i < count; i++) {
 Student current = arr[i];
 int j = i - 1;
 while (j >= 0 && arr[j].id > current.id) {
 arr[j + 1] = arr[j];
 j--;
 }
 arr[j + 1] = current;
 }
}
void Student::sortByName(Student arr[], int count) {
 for (int gap = count / 2; gap > 0; gap /= 2) {
 for (int i = gap; i < count; i++) {
 Student temp = arr[i];
 int j;
 for (j = i; j >= gap && arr[j - gap].fullName > temp.fullName; j -= gap) {
 arr[j] = arr[j - gap];
 }
 arr[j] = temp;
 }
 }
}
void Student::showDetails(Student arr[], int count) {
 for (int i = 0; i < count; i++) {
 cout << "\nName: " << arr[i].fullName;
 cout << "\nRoll Number: " << arr[i].id;
 cout << "\nSGPA: " << arr[i].gpa << endl;
 }
}
int main() {
 int studentCount, option;

 cout << "\nHow many students do you want to enter? ";
 cin >> studentCount;
 Student students[studentCount];
 do {
 cout << "\nMenu:\n";
 cout << "1. Enter Student Data\n";
 cout << "2. Sort by Roll Number\n";
 cout << "3. Sort by Name\n";
 cout << "4. Show All Data\n";
 cout << "5. Exit\n";
 cout << "Choose an option: ";
 cin >> option;
 switch (option) {
 case 1:
 for (int i = 0; i < studentCount; i++) {
 cout << "\nEntering data for Student " << (i + 1) << endl;
 students[i].inputDetails();
 }
 break;
 case 2:
 students[0].sortByID(students, studentCount);
 cout << "\nStudents sorted by Roll Number.\n";
 break;
 case 3:
 students[0].sortByName(students, studentCount);
 cout << "\nStudents sorted by Name.\n";
 break;
 case 4:
 cout << "\nDisplaying all student details:\n";
 students[0].showDetails(students, studentCount);
 break;
 case 5:
 cout << "\nGoodbye!\n";
 break;
 default:
 cout << "\nInvalid choice. Please try again.\n";
 }
 } while (option != 5);
 return 0;
}