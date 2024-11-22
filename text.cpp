#include <iostream>
using namespace std;
class text {
public:
#include<iostream>
using namespace std;
class text_editor {
public:
 text_editor* next;
 text_editor* prev;
 string data;
 text_editor(string data) {
 this->data = data;
 next = NULL;
 prev = NULL;
 }
};
class LL {
 text_editor* head = NULL;
public:
 void insertAtStart(string d);
 void insertAtEnd(string d);
 void printList();
 void deleteText(string d);
 void searchText(string d);
 void reverseText();
};
void LL::insertAtStart(string d) {
 text_editor* nn = new text_editor(d);
 if (head == NULL) {
 head = nn;
 } else {
 head->prev = nn;
 nn->next = head;
 head = nn;
 }
}
void LL::insertAtEnd(string d) {
 text_editor* nn = new text_editor(d);
 if (head == NULL) {
 head = nn;
 } else {
 text_editor* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = nn;
 nn->prev = temp;
 }
}
void LL::printList() {
 text_editor* temp = head;
 if (head == NULL) {
 cout << "\nList is empty";
 return;
 }
 while (temp->next != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << temp->data << endl;
}
void LL::deleteText(string d) {
 text_editor* temp = head;
 if (head == NULL) {
 cout << "\nList is empty" << endl;
 return;
 }
 if (head->data == d) {
 if (head->next == NULL) {
 delete head;
 head = NULL;
 } else {
 head = head->next;
 head->prev = NULL;
 }
 cout << "\nText deleted successfully!" << endl;
 return;
 }
 while (temp != NULL && temp->data != d) {
 temp = temp->next;
 }
 if (temp == NULL) {
 cout << "\nText not found in the list" << endl;
 return;
 }
 if (temp->next == NULL) {
 temp->prev->next = NULL;
 delete temp;
 cout << "\nText deleted successfully!" << endl;
 return;
 }
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 delete temp;
 cout << "\nText deleted successfully!" << endl;
}
void LL::searchText(string d) {
 if (head == NULL) {
 cout << "\nList is empty" << endl;
 return;
 }
 int count = 1;
 text_editor* temp = head;
 while (temp != NULL && temp->data != d) {
 temp = temp->next;
 count++;
 }
 if (temp == NULL) {
 cout << "\nText not found in the list" << endl;
 } else {
 cout << "\nText is present in the list at index " << count << endl;
 }
}
void LL::reverseText() {
 if (head == NULL) {
 cout << "\nList is empty" << endl;
 return;
 }
 text_editor* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->prev;
 }
 cout << endl;
}
int main() {
 LL list;
 int choice;
 string text;
 do {
 cout << "\nMenu:\n";
 cout << "1. Insert text at the start\n";
 cout << "2. Insert text at the end\n";
 cout << "3. Print the text list\n";
 cout << "4. Delete text\n";
 cout << "5. Search for text\n";
 cout << "6. Reverse the text list\n";
 cout << "7. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 cin.ignore();
 switch (choice) {
 case 1:
 cout << "Enter the text to insert at the start: ";
 getline(cin, text);
 list.insertAtStart(text);
 break;
 case 2:
 cout << "Enter the text to insert at the end: ";
 getline(cin, text);
 list.insertAtEnd(text);
 break;
 case 3:
 cout << "\nThe current text list: ";
 list.printList();
 break;
 case 4:
 cout << "Enter the text to delete: ";
 getline(cin, text);
 list.deleteText(text);
 break;
 case 5:
 cout << "Enter the text to search: ";
 getline(cin, text);
 list.searchText(text);
 break;
 case 6:
 cout << "\nReversed text list: ";
 list.reverseText();
 break;
 case 7:
 cout << "\nExiting\n";
 break;
 default:
 cout << "\nPlease enter a valid choice." << endl;
 }
 } while (choice != 7);
 return 0;
}