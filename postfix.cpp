#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int postfix_evaluation(string s)// s is the postfix exp string
{
stack<int> numbers;
for(int i=0;i<s.length();i++)
{
if(s[i]>'0' and s[i]<'9')
{
numbers.push(s[i]-'0');//push the integers into the stack numbers
else
{
int a=numbers.top();
numbers.pop();
int b=numbers.top();
numbers.pop();
switch(s[i])//instead of if else
{
case '+':
numbers.push(a+b);
break;
case '-':
numbers.push(a-b);
break;
case '*':
numbers.push(a*b);
break;
case '/':
numbers.push(a/b);
break;
case '^':
numbers.push(pow(a,b));
break;
}
}
}
return numbers.top();
}

int main()
{
string a="571*+23*4+6*+";
int answer=postfix_evaluation(a);
cout<<"The answer is "<<answer<<endl;
return 0;
}