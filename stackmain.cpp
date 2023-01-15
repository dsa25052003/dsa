#include <iostream>
using namespace std;
//Node structure - Data and next
class node
{
 public:
 int data;
 node* next;
 node()
 {
 data = 0;
 next = NULL;
 }
 node(int data)
 {
 this->data = data;
 this->next = NULL;
 }
};
//Operations in the stack
class stack
{
 node *head;
 node *temp;
 public:
 stack()
 {
 head = NULL;
 }
 void push(int);
 void pop();
 void peek();
 void display();
 void deletes(int);
 int count();
};
//Push routine
void stack::push(int data){
 //Creation of head node in an empty stack
 node* newNode = new node(data);
 if(head==NULL) {
 head = newNode;
 }
 //Push operation when stack has contents already
 else
 {
 newNode->next = head;
 head = newNode;
 }
 cout<<"\nThe pushed element is "<<head->data<<"\n";
}
//Pop routine
void stack::pop(){
 temp=head;
 cout<<"\nThe popped element is "<<temp->data<<"\n";
 head = temp->next;
 delete(temp);
}
//Peek routine to get the recently added element onto the stack
void stack::peek(){
 temp = head;

 cout<<"\nPeek Top : ";
 cout << temp->data;
}
void stack::deletes(int val)
{
  temp=head;
  while(head!=NULL)
  {
    if (head->data==val)
    {
       cout<<"\nThe popped element is "<<temp->data<<"\n";
       head = temp->next;
      delete(temp);
      return;
    }
    else
    {
      head = temp->next;
      delete(temp);
      temp= head;

    }
  }
}
int stack::count()
{
    temp=head;
    int c=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        c=c+1;
    }
    cout<<"number of elements is"<<c;
    return c;
}
//Display routine
void stack::display() {
 cout<<"\nStack contents are :\n ";
 temp = head;
 if(temp==NULL)
 cout<<"Empty stack";
 while(temp!=NULL) {
 if(temp->next!=NULL)
 cout<<temp->data<<" ";
 else
 cout<<temp->data;
 temp = temp->next;
 }
}
int main()
{
 int num,i,key;
 stack stkobj;
 int ch;
do{
 cout<<"\nStack operations\n1. Single Push\n2. Batch Push\n3. Pop\n4. Peek\n5. Display\n6.count\n7.deletion\n8. Exit\n";
 cin>>ch;
 switch(ch)
 {
 case 1:
 //Stack - Push an element
 cout<<"Enter the data to be inserted to the stack: ";
 cin>> key;
 stkobj.push(key);
 stkobj.display();
 break;
 case 2:
 //Push a batch of data elements
 cout<<"Enter the number of elements to be stored in stack: ";
 cin>>num;
 for(i=1;i<=num;i++)
 {
 cin>> key;
 stkobj.push(key);
 }
 stkobj.display();
 break;
 case 3:
 //Pop an element out from the stack
 stkobj.pop();
 stkobj.display();
 break;
 case 4:
 //Get the recently added element that is the top most elemnt in the stack
 stkobj.peek();
 break;
 case 5:
 //Print the STACK
 stkobj.display();
 break;
 case 6:
 stkobj.count();
 case 7:
 cout<<"enter the element to be deleted"<<endl;
 cin>>key;
 stkobj.deletes(key);
 stkobj.display();
 break;
 ch=8;
 break;
 }
 }while(ch<=8);
 return 0;
};