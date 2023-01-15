#include <iostream>
using namespace std;
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

class queue
{
 node *head = new node;
 node *tail = new node;
 node *temp = new node;
 int count = 0;

 public:
 queue()
 {
 head = tail = NULL; //default constructor
 }
 void enqueue(int);
 void dequeue();
 void length();
 void search(int);
 void display();
};

void queue::enqueue(int val) //ENQUEEEEEEEEEEEE
{
 
 node *new_node = new node(val);//creating the new node
 //element entering the empty queue
 if(head==NULL && tail==NULL)
 {
 head = tail = new_node;
 }
 //element entering the existing queue
 else
 {
 temp = head;
 while (temp->next != NULL)
 {
 temp = temp->next;
 }
 temp->next = new_node;
 tail = new_node;
 }

}
void queue::dequeue()// DEQUEEEEEEEEEEEEEEEEEEEE
{
 if(head==NULL)
 cout<<"Empty queue.";
 else
 //deletion at the front end of the queue
 head = head->next;
}
void queue::length() //LENGTH OF QUEEEEEEE
{
 count = 0;
 temp = head;
 while (temp != NULL)
 {
 count = count + 1;
 temp = temp->next;
 }
 cout << "The length of the queue is: " << count<<endl;
}
void queue::search(int val)// SEARCHHHHHHH 
{
 count=0;
 temp = head;
 while (temp != NULL)
 {
 if (temp->data == val)
 count = count + 1;
 temp = temp->next;
 }
 if(count==0)
 cout << "The data "<<val<<" is not available.\n";
 else if(count>0)
 cout << "The data "<<val<<" is available "<<count<<" time(s)\n"<<endl;
}
void queue::display()// DISPLAYYYYYY
{
 cout<<"\nQueue contents are :\n ";
 temp = head;
 if(temp==NULL)
 cout<<"Empty Queue";
 while(temp!=NULL) {
 //cout << temp->next->data << endl;
 if(temp->next!=NULL)
 cout<<temp->data<<"-";
 else
 cout<<temp->data;
 temp = temp->next;
 }
}
int main()
{
 int num,i,key;
 queue qobj;
 int ch;
do{
 cout<<"\nQueue operations\n1. Single element enqueue\n2. Batch enqueue\n3. Dequeue\n4. Length\n5.Search\n6. Display\n7. Exit\n";
 cin>>ch;
 switch(ch)
 {
 case 1:
 //Queue - Single enqueue of an element
 cout<<"Enter the data to be inserted to the queue: ";
 cin>>key;
 qobj.enqueue(key);
 qobj.display();
 break;
 case 2:
 //Batch enqueue of data elements
 cout<<"Enter the number of elements to be stored in queue: ";
 cin>>num;
 for(i=1;i<=num;i++)
 {
 cin>> key;
 qobj.enqueue(key);
 }
 qobj.display();
 break;
 case 3:
 //Dequeue an element - First In First Out Principle
 qobj.dequeue();
 cout<<"Elements in the queue after dequeue\n";
 qobj.display();
 break;
 case 4:
 //Length of queue
 cout<<endl;
 qobj.length();
 break;
 case 5:
 //Search the number of occurences of the similar data items available in the queue
 cout<<"Enter the item to be checked: ";
 cin>>num;
 cout<<"Searching "<<num<<" in the queue\n";
 qobj.search(num);
 break;
 case 6:
 //Print the elements in the queue
 cout<<"Elements in the queue\n";
 qobj.display();
 break;
 case 7:
 ch=8;
 break;
 }
 }while(ch<=7);
return 0;
};