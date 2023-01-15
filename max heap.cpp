#include <iostream>
using namespace std;
void max_heap(int *a, int m, int n)
{
 int j, t;
 t = a[m];
 j = 2 * m;
 
 while (j <= n)
 {
 if (j < n && a[j+1] > a[j])
 j = j + 1;
 if (t > a[j])
 break;
 else if (t <= a[j]) {
 a[j / 2] = a[j];
 j = 2 * j;
 }
 }
 a[j/2] = t;
 return; }
void build_maxheap(int *a,int n)
{
 int k;
 for(k = n/2; k >= 1; k--) {
 max_heap(a,k,n);
 }
}
void heapify(int arr[], int n, int i)
{
 int largest = i;
 int l = 2 * i + 1;
 int r = 2 * i + 2;
 if (l < n && arr[l] > arr[largest])
 largest = l;
 if (r < n && arr[r] > arr[largest])
 largest = r;
 if (largest != i) {
 swap(arr[i], arr[largest]);
 heapify(arr, n, largest);
 }
}
void deleteRoot(int arr[], int &n)
{
 int lastElement = arr[n];
 arr[1] = lastElement;
 n = n - 1;
 build_maxheap(arr, n);
} 
int main()
{
 int n, i, ch, num=0, total;
 cout<<"Enter the number of elements : "; cin>>n;
 int a[n+10];
 total = n + num;
 for (i = 1; i <= n; i++)
 {
 cout<<"enter element "<<(i)<<" : ";
 cin>>a[i];
 }
 build_maxheap(a,total);
 cout<<"Max Heap\n";
 for (i = 1; i <= n; i++)
 {
 cout<<a[i]<<" ";
 }
 do {
 cout<<"\n\tMENU \n 1. Find maximum \n 2. Delete maximum \n 3. Heapinsert \n 4. Exit"<<endl;
 cout<<"Enter your choice: "; cin>>ch;
 switch (ch)
 {
 case 1:
 cout<<"Maximum value in heap : "<<a[1]<<endl;
 break;
 case 2:
 deleteRoot(a, total);
 for (i = 1; i <= total; i++)
 {
 cout<<a[i]<<" ";
 }
 break;
 case 3:
 cout<<"Enter the number of elements to be inserted : "; cin>>num;
 for (int i=0; i<num; i++)
 {
 cout<<"Enter the data : "; cin>>a[n+i];
 }
 build_maxheap(a,n+num);
 cout<<"Max Heap\n";
 
 for (i = 1; i < n+num; i++)
 {
 cout<<a[i]<<" ";
 }
 break;
 default :
 break;
 }
 } while (ch<4);
 return 0;
} 