#include <iostream>
using namespace std;
class Employee {
 int id;
 string name;
 float salary;
public:
 void insert() {
 cout << "\nEnter Employee ID: ";
 cin >> id;
 cout << "Enter Employee Name: ";
 cin.ignore(); // To ignore the newline left by previous input
 getline(cin, name);
 cout << "Enter Employee Salary: ";
 cin >> salary;
 }
 void quickSort(Employee arr[], int low, int high) {
 if (low < high) {
 int pivot = partitionById(arr, low, high);
 quickSort(arr, low, pivot - 1);
 quickSort(arr, pivot + 1, high);
 }
 }
 int partitionById(Employee arr[], int low, int high) {
 int pivot = arr[low].id;
 int i = low + 1;
 int j = high;
 while (i <= j) {
 while (i <= high && arr[i].id <= pivot) i++;
 while (arr[j].id > pivot) j--;
 if (i < j) swap(arr[i], arr[j]);
 }
 swap(arr[low], arr[j]);
 return j;
 }
 void mergeSort(Employee arr[], int left, int right) {
 if (left < right) {
 int mid = left + (right - left) / 2;
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 mergeByName(arr, left, mid, right);
 }
 }
 void mergeByName(Employee arr[], int left, int mid, int right) {
 int n1 = mid - left + 1;
 int n2 = right - mid;
 Employee* leftArr = new Employee[n1];
 Employee* rightArr = new Employee[n2];
 for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
 for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];
 int i = 0, j = 0, k = left;
 while (i < n1 && j < n2) {
 if (leftArr[i].name <= rightArr[j].name) arr[k++] = leftArr[i++];
 else arr[k++] = rightArr[j++];
 }
 while (i < n1) arr[k++] = leftArr[i++];
 while (j < n2) arr[k++] = rightArr[j++];
 delete[] leftArr;
 delete[] rightArr;
 }
 void display(int n, Employee arr[]) {
 cout << "\nEmployee Data:\n";
 for (int i = 0; i < n; i++) {
 cout << "ID: " << arr[i].id << "\nName: " << arr[i].name << "\nSalary: " << arr[i].salary << "\n\n";
 }
 }
};
int main() {
 int n;
 cout << "\nEnter the number of employees: ";
 cin >> n;
 Employee employees[n];
 int choice;
 cout << "\nEnter Employee Details:\n";
 for (int i = 0; i < n; i++) {
 employees[i].insert();
 }
 do {
 cout << "\nEmployee Database Menu:";
 cout << "\n1. Display Employees Sorted by Employee ID (Ascending Order)";
 cout << "\n2. Display Employees Sorted by Employee Name (Alphabetical Order)";
 cout << "\n3. Exit";
 cout << "\nEnter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 employees[0].quickSort(employees, 0, n - 1);
 cout << "\nEmployees Sorted by Employee ID (Ascending Order):";
 employees[0].display(n, employees);
 break;
 case 2:
 employees[0].mergeSort(employees, 0, n - 1);
 cout << "\nEmployees Sorted by Employee Name (Alphabetical Order):";
 employees[0].display(n, employees);
 break;
 case 3:
 cout << "\nExiting the program.";
 break;
 default:
 cout << "\nInvalid choice. Please try again.";
 }
 } while (choice != 3);
 return 0;
}
