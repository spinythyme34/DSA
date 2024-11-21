#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int coeff;
   int pow;
    Node *next;
    Node()
    {
        coeff=pow=0;
        next=NULL;
    }
   
};
class LL
{
    public:
    Node *head=NULL;

void create_node(int x, int y){
    Node *nn=new Node();
    nn->coeff=x;
    nn->pow=y;
   if (head == NULL) {  
    head = nn;
} else {
     Node* temp = new Node();
     temp=head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
}

}

void polyadd(LL l1, LL l2)
{
    Node *p1 = l1.head;
    Node *p2 = l2.head;
    Node *result = new Node(); 
    Node *curr = result;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            curr->next = new Node();
            curr->next->coeff = p1->coeff;
            curr->next->pow = p1->pow;
            curr = curr->next;
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            curr->next = new Node();
            curr->next->coeff = p2->coeff;
            curr->next->pow = p2->pow;
            curr = curr->next;
            p2 = p2->next;
        } else {
            curr->next = new Node();
            curr->next->coeff = p1->coeff + p2->coeff;
            curr->next->pow = p1->pow;
            curr = curr->next;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        curr->next = new Node();
        curr->next->coeff = p1->coeff;
        curr->next->pow = p1->pow;
        curr = curr->next;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        curr->next = new Node();
        curr->next->coeff = p2->coeff;
        curr->next->pow = p2->pow;
        curr = curr->next;
        p2 = p2->next;
    }
    head = result->next;    
}
void printpoly()
{
if(head!=NULL)    
{
    Node *temp=head;
   while(temp->next != NULL)
   {
      cout<<temp->coeff<<" "<<temp->pow<<"+";
      temp = temp->next;
   }
    cout<<temp->coeff<<" "<<temp->pow;
}
}
};
int main(){
   LL l1,l2,l3,l;
   l1.create_node(22,7);
   l1.create_node(10,5);
   l1.create_node(2,0);
   l2.create_node(1,5);
   l2.create_node(15,2);
   printf("polynomial 1: ");
  l1.printpoly();
   printf("\npolynomial 2: ");
   l2.printpoly();
   
   l3.polyadd(l1, l2);
   printf("\npolynomial after adding p1 and p2 : ");
   l3.printpoly();
   return 0;

}

