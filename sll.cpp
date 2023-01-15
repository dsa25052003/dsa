#include<iostream>
using namespace std;

class Node
{
public:
int value;
Node *next;
Node();
Node(int a);
};


Node::Node()
{
value=0;
next=NULL;
}
Node::Node(int a)
{
value=a;
next=NULL;
}
class Linklist// a linked list has a head only
{
int cnt=0;
Node *head;
public:

Linklist();
void insertnode(int number);
int getlength();
void makeempty();
void getnextitem(int value);
void printlist();
void findkth(int pos);
void find();
void deletenode();
};
Linklist::Linklist()//default cons
{
head=NULL;
}
void Linklist::insertnode(int number)//INSERTTTTTTT
{
Node *newnode=new Node(number);
if(head==NULL)
{
head=newnode;
}
else
{
newnode->next=head;//insert in the beginning 
head=newnode;
}
}

int Linklist::getlength()//GET LENGHTHHHHHH

{
Node *newnode=new Node();
newnode=head;
while(newnode!=NULL)
{
cnt+=1;
newnode=newnode->next;
}
return cnt;
}
void Linklist::makeempty()//ALL VALUES =0
{
Node *newnode=new Node();
newnode=head;
while(newnode->next!=NULL)
{
newnode->value=0;
newnode=newnode->next;
}
if(newnode->next==NULL)
newnode->value=0;
}
void Linklist::printlist()
{
Node *newnode=new Node();
newnode=head;
while(newnode!=NULL)
{

cout<<newnode->value<<" ";
newnode=newnode->next;
}
}
void Linklist::getnextitem(int a)
{
Node *newnode=new Node();
newnode=head;
Node *temp=new Node();
while(newnode->next!=NULL)
{
if(newnode->value==a)
{
temp=newnode->next;
cout<<"The next item is "<<temp->value<<endl;
}
newnode=newnode->next;
}
}
void Linklist::findkth(int pos)
{
int c=0;
Node *newnode=new Node();
newnode=head;
while(newnode->next!=NULL)
{
c+=1;
if(c==pos)

{
cout<<"\nThe element at the given position is:"<<newnode->value<<endl;
}
newnode=newnode->next;
}
}
void Linklist::find()
{
int value,d=0;
cout<<"\nEnter the element to specify position:";
cin>>value;
Node *newnode=new Node();
newnode=head;
while(newnode->next!=NULL)
{
if(newnode->value==value)
{
cout<<"The position is"<<d+1<<endl;
}
newnode=newnode->next;
d+=1;
}
if(newnode->next==NULL)
{
if(newnode->value==value)
{
cout<<"The position is:"<<d+1<<endl;
}

}
}
void Linklist::deletenode()
{
int v,c;
cout<<"Enter position to be deleted:";
cin>>v;
Node *newnode=new Node();
newnode=head;
Node *prev=new Node();
if(v==1)
{
prev=head;
head=head->next;
delete(prev);// DELETING THE BEGINNING OF THE LIST
}
else
{
while(newnode!=NULL)
{
prev=newnode;
newnode=newnode->next;
c++;
if(c==v+1)
{
prev->next=newnode->next;
delete newnode;
break;

}
}
}
cnt--;
}
int main()
{
Linklist n;
int value,a;
n.insertnode(20);
n.insertnode(10);
n.insertnode(30);
n.insertnode(100);
n.insertnode(200);
value=n.getlength();
cout<<"The length of the list is:"<<value<<endl;
n.getnextitem(10);
cout<<"Displaying elements of the list"<<endl;
n.printlist();
cout<<"\nEnter the position to find element:";
cin>>a;
n.findkth(a);
n.find();
n.deletenode();
cout<<"\nAfter deleting"<<endl;
n.printlist();
cout<<"\nAfter making it empty"<<endl;
n.makeempty();

n.printlist();
return 0;
}