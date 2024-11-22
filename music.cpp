#include<iostream>
using namespace std;
class song {
 string name;
 song* next;
 song* header = NULL;
public:
 void insertatEnd() {
 string val;
 song* nn = new song;
 cout << "\nEnter the name of the song: ";
 cin >> nn->name;
 nn->next = NULL;
 if (header == NULL) {
 header = nn;
 } else {
 song* temp = header;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = nn;
 }
 }
 void print() {
 song* temp = header;
 int count = 1;
 if (header == NULL) {
 cout << "\nYour playlist is empty. Please add songs first." << endl;
 return;
 }
 cout << "\nDisplaying Playlist:\n";
 while (temp != NULL) {
 cout << count << ". " << temp->name << endl;
 temp = temp->next;
 count++;
 }
 }
 void deleteSong() {
 if (header == NULL) {
 cout << "\nYour playlist does not have any song." << endl;
 return;
 }
 song* temp = header;
 string del;
 song* prev;
 cout << "\nEnter the name of the song you want to delete: ";
 cin >> del;
 if (header->name == del) {
 header = header->next;
 cout << "\nSong deleted successfully!" << endl;
 delete temp;
 return;
 }
 while (temp != NULL && temp->name != del) {
 prev = temp;
 temp = temp->next;
 }
 if (temp == NULL) {
 cout << "\nSong does not exist in the playlist!" << endl;
 return;
 }
 prev->next = temp->next;
 cout << "\nSong deleted successfully!" << endl;
 delete temp;
 }
 void playSong() {
 if (header == NULL) {
 cout << "\nYour playlist does not have any song." << endl;
 return;
 }
 string a;
 song* temp = header;
 cout << "\nEnter the name of the song you want to play: ";
 cin >> a;
 while (temp != NULL && temp->name != a) {
 temp = temp->next;
 }
 if (temp == NULL) {
 cout << "\nSong does not exist in your playlist!" << endl;
 return;
 }
 cout << "\nCurrently Playing: " << a << endl;
 }
};
int main() {
 song s;
 int c;
 do {
 cout << "\nEnter your choice:\n"
 << "1. Add songs\n"
 << "2. Remove songs\n"
 << "3. Display the entire playlist\n"
 << "4. Play a Song\n"
 << "5. Exit\n";
 cin >> c;
 switch (c) {
 case 1:
 s.insertatEnd();
 break;
 case 2:
 s.deleteSong();
 break;
 case 3:
 s.print();
 break;
 case 4:
 s.playSong();
 break;
 case 5:
 cout << "\nExited successfully!" << endl;
 break;
 default:
 cout << "\nPlease enter a valid choice!" << endl;
 }
 } while (c != 5);
 return 0;
}
