
#include<iostream> 
#include<stack>
using namespace std; 
bool isbalanced(string a) //the string which has the brackets
{
stack<char>s;//the stack
char ch;//the character added to the stack(bracket)
for(int i=0;i<a.length();i++)
{
if(a[i]=='(' or a[i]=='[' or a[i]=='{') //1.push in stack normally
{
s.push(a[i]);
continue;
}
if(s.empty())//2.
{
return false;
}
switch(a[i])//3.
{
case ')':
ch=s.top();//points to top of stack
s.pop();
if(ch=='[' or ch=='{')
return false;
break;
case ']':
ch=s.top();
s.pop();
if(ch=='(' or ch=='{')
return false;
break;
case '}':
ch=s.top();
s.pop();
if(ch=='[' or ch=='(') 
return false;
break;
}
}//end of for loop
return (s.empty()); 
    
}
int main()
{
string x;
cout<<"Enter your string:"; 
cin>>x;
if(isbalanced(x)) 
cout<<"Balanced"<<endl; 
else
cout<<"Not balanced"<<endl; return 0;
}
