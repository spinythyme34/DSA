  #include <iostream>
  using namespace std;

  class route {
  public:
      string data;
      route *next;
      route *prev;
  };

  void insert(route **head, string data) {
      route *newNode = new route();
      newNode->data = data;
      newNode->next = *head;
      newNode->prev = NULL;

      if (*head == NULL) {
          *head = newNode;
          newNode->next = newNode; 
          newNode->prev = newNode;
          return;
      }

      route *temp = *head;
      while (temp->next != *head) {
          temp = temp->next;
      }

      temp->next = newNode;
      newNode->prev = temp;
      newNode->next = *head;
      (*head)->prev = newNode;
  }

  void insertbegin(route **head, string data) {
      route *new_node = new route;
      new_node->data = data;
      new_node->next = *head;
      new_node->prev = NULL;

      if (*head == NULL) {
          *head = new_node;
          new_node->next = new_node; 
          new_node->prev = new_node;
          return;
      }

      route *temp = *head;
      while (temp->next != *head) {
          temp = temp->next;
      }

      temp->next = new_node;
      new_node->prev = temp;
      new_node->next = *head;
      (*head)->prev = new_node;
      *head = new_node;
  }
void insertatspecific(route **head, string data, int pos){
  route *new_node = new route;
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  if (*head == NULL){
    *head = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    return;
  }
  route *temp = *head;
  for(int i=1;i<pos-1;i++){
    temp = temp->next;
  }
  new_node->next = temp->next;
  new_node->prev = temp;
  temp->next->prev = new_node;
  temp->next = new_node;
}
  void deleteNode(route **head, string data) {
      if (*head == NULL) return; 

      route *temp = *head;
      do {
          if (temp->data == data) break;
          temp = temp->next;
      } while (temp != *head);

      if (temp->data != data) return;

      if (temp == *head && temp->next == *head) {
          delete temp;
          *head = NULL;
          return;
      }

      if (temp == *head) {
          *head = temp->next;
      }
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;

      delete temp;
  }

  void display(route *head) {
      if (head == NULL) return; 

      route *temp = head;
      do {
          cout << temp->data << " ";
          temp = temp->next;
      } while (temp != head);
      cout << endl;
  }

int main(){
    route *head=NULL;
    int choice;
    string data;
    int pos;
    do{
      cout<<"\nMenu:\n";
      cout<<"1.Add route at the beginning\n";
      cout<<"2.Add route at the end\n";
      cout<<"3.Add route at a specific position\n";
      cout<<"4.Delete route\n";
      cout<<"5.Display route\n";
      cout<<"6.Exit\n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice){
        case 1:
          cout<<"Enter the route to add at the beginning: ";
          cin>>data;
          insertbegin(&head,data);
          break;
        case 2:
          cout<<"Enter the route to add at the end: ";
          cin>>data;
          insert(&head,data);
          break;
        case 3:
          cout<<"Enter the route to add at a specific position: ";
          cin>>data;
          cout<<"Enter the position: ";
          cin>>pos;
          insertatspecific(&head,data,pos);
          break;
        case 4:
          cout<<"Enter the route to delete: ";
          cin>>data;
          deleteNode(&head,data);
          break;
        case 5:
          cout<<"Displaying route: ";
          display(head);
          cout<<endl;
          break;
        case 6:
          cout<<"Exiting...\n";
          break;
        default:
          cout<<"Invalid choice. Please try again.\n";
          break;

      }
    }while(choice!=6);
    return 0
    