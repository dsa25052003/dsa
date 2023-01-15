#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) //arranges in the form of a min heap with min as root node
{
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;

 if (left < n && arr[left] > arr[largest])
 largest = left;

 if (right < n && arr[right] > arr[largest])
 largest = right;

 if (largest != i) 
 {
 swap(arr[i], arr[largest]);
 heapify(arr, n, largest);
 }
 }

 void heapSort(int arr[], int n) //adds the min element of the min heap into a seperate array 
 {
 for (int i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i);
 for (int i = n - 1; i >= 0; i--) {
 swap(arr[0], arr[i]);
 heapify(arr, i, 0);
 }}

 void printArray(int arr[], int n) {
 for (int i = 0; i < n; ++i)
 cout << arr[i] << " ";
 cout << "\n";}


 int main() 
 {
 int a;
 cout<<"Enter number of elements:";
 cin>>a;
 int arr[a];
 for(int i=0;i<a;i++)
 {
 cout<<"Enter value ";
 cin>>arr[i];
 }
 int n = sizeof(arr) / sizeof(arr[0]);
 heapSort(arr, n);
 cout << "Sorted array is \n";
 printArray(arr, n);
 }









#include<iostream>
#include<math.h>

using namespace std;

class MinHeap {
public:
	int * harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
	
	MinHeap(int cap) {
		heap_size = cap;
		capacity = cap;
		harr = new int[cap];
	}
	
	void printArray() {
		for (int i = 0; i < heap_size; i++)
			cout << harr[i] << " ";
		cout << endl;
	}
	
	int parent(int i) {
		return (i - 1) / 2;
	}
	
	int left(int i) {
		return (2 * i + 1);
	}
	
	int right(int i) {
		return (2 * i + 2);
	}
	int getMin() {
		return harr[0];
	}
	void MinHeapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && harr[l] < harr[i])
			smallest = l;
		if (r < heap_size && harr[r] < harr[smallest])
			smallest = r;
		if (smallest != i) {
			swap(harr[i], harr[smallest]);
			MinHeapify(smallest);
		}
	}
	// Method to remove minimum element (or root) from min heap
	int extractMin() {
		if (heap_size <= 0)
			return INT_MAX;
		if (heap_size == 1) {
			heap_size--;
			return harr[0];
		}
		
		// Store the minimum value, and remove it from heap
		int root = harr[0];
		harr[0] = harr[heap_size - 1];
		heap_size--;
		MinHeapify(0);
		//printArray();
		//cout <<"--"<<harr[0]<<"--";
		return root;
	}
	
	void getUnsortedArray() {
		cout << "Enter " << capacity << " no of elements to sort using HEAPSORT" << endl;
		for (int i = 0; i < capacity; i++)
			cin >> harr[i];
	}
	
	void heapSort() {
		int temp[capacity];
		for (int j = 0; j < capacity; j++) {
			//cout<<extractMin()<<" ";
			temp[j] = extractMin();
			cout << temp[j] << " ";
		}
	}
	
};

int main() {
	int s;
	cout << "Enter Size of Min Heap" << endl;
	cin >> s; // 5
	MinHeap obj(s);
	obj.getUnsortedArray(); // 7 4 3 9 8
	
	cout << "Heap Sorted Array :" << endl;
	obj.heapSort();
	
}
