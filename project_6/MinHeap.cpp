#include <iostream>
using namespace std;

class MinHeap
{
    private:
        int* arr;
        int maxSize;
        int heapSize;
        void swap(int *a, int *b);
        void minHeapify(int index);
        void decrease(int index, int newValue);
        int parent(int index);
        int leftChild(int index);
        int rightChild(int index);
    public:
        MinHeap(int size);
        int removeMin(); 
        void remove(int value);
        void insert(int value);
        void print();
};
//--- heap constructor ----------
MinHeap::MinHeap(int size)
{
    heapSize = 0;
    maxSize = size;
    arr = new int[size];
}
//--- parent -------------------
int MinHeap::parent(int index)
{
    return (index - 1)/2;
}
//--- left child ---------------
int MinHeap::leftChild(int index)
{
    return (2 * index + 1 );
}
//--- right child --------------
int MinHeap::rightChild(int index)
{
    return (2 * index + 2);
}
//--- insert -------------------
void MinHeap::insert(int value)
{
    if(heapSize == maxSize)
    {
        cout<<" heap is full";
        return;
    }
    heapSize++;
    int index = heapSize - 1;
    arr[index] = value;

    int i = heapSize - 1;
    while (i != 0 && arr[parent(i)] > arr[i])
    { 
        swap(&arr[parent(i)], &arr[i]); 
        i = parent(i); 
    }
}    
//--- increase -----------------
void MinHeap::decrease(int index, int newValue)
{
    arr[index] = newValue;
    while (index != 0 && arr[parent(index)] > arr[index])
    { 
        swap(&arr[index], &arr[parent(index)]); 
        index = parent(index); 
    }
}
//--- max heapify -------------
void MinHeap::minHeapify(int index)
{
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest = index;
    if(left < heapSize && arr[left] < arr[index])
        smallest = left;
    if(right < heapSize && arr[right] < arr[index])
        smallest = right;
    if( smallest != index)
    {
        swap(&arr[index], &arr[smallest]);
        minHeapify(smallest);
    }
}
//--- remove max --------------
int MinHeap::removeMin()
{
    if(heapSize <= 0)
        return INT_MAX;
    if(heapSize == 1)
    {
        heapSize--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize--;

    minHeapify(0);
    return root;
}
//--- remove ------------------
void MinHeap::remove(int value)
{
    int index;
    for(index = 0; index < heapSize; index++)
    {
        if(arr[index] == value)
            break;
    }
    decrease(index, INT_MIN);
    removeMin();
    //minHeapify(0);
}
//--- swap --------------------
void MinHeap::swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
//--- print -------------------
void MinHeap::print()
{
    for(int i=0; i<heapSize; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
