#include <iostream>
using namespace std;

class history{
    public:
    int top;
    string stack[10];
    history(){
        top = -1;
    }
    void push(string s){
        cout << "Enter the website:  ";
        cin >> s;
        if(top < 9)
            stack[++top] = s; 
        else {
            cout << "History is full" << endl;
        }
    }
    void navigate(){
        if(top >= 0){
            cout << "Navigating to: " << stack[top] << endl;
            top--;
        } else {
            cout << "No website to navigate to." << endl;
        }
    }
    void displayHistory(){
        cout << "Browsing history: ";
        for(int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        }
    void currentPage(){
    if(top >= 0){
        cout << "Current page: " << stack[top] << endl;
    } else {
        cout << "No current page." << endl;
    }
}
    };

int main(){
    history h;
    int choice;
    while(true){
        cout<<"\n1. Enter website"<<endl;
        cout<<"2. Navigate"<<endl;
        cout<<"3. Display History"<<endl;
        cout<<"4. View current page"<<endl;
        cout<<"5. Exit"<<endl;
        
        cin >> choice;
        switch(choice){
            case 1:{
                string s;
                h.push(s);
                break;
            }
            case 2:
                h.navigate();
                break;
            case 3:
                h.displayHistory();
                break;
            case 4:
            h.currentPage();
            break;
            case 5:
                cout<<"Exiting "<<endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

 