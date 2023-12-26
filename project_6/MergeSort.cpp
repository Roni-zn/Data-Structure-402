#include <iostream>
#include <array>
using namespace std;


class MergeSort
{
    private:
     static void merge(int array[] , int const begin, int const end);

    public:
     static void merge_sort(int array[], int const begin, int const end);

};

//--- Merge sort ---------------
void MergeSort::merge_sort( int array[], int const begin, int const end)
{
    
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, end);

 
}
//--- Merge -----------
void MergeSort::merge(int array[] , int const begin, int const end)
{
    int const mid = (begin + end)/2 ;
    int const left_size = mid - begin +1;
    int const right_size = end - mid;


    // creating two sub arrays
    int *leftarray = new int[left_size];
    int *rightarray = new int[right_size];


    // initializing the sub arrays
    for (int i = 0; i < left_size; i++)
    leftarray[i] = array[begin + i];

    for (int i = 0; i < right_size; i++)
    rightarray[i] = array[mid + 1 + i];


    int left_index = 0, right_index = 0, index = begin;
    // comparing values of left & right arrays and merge(replace) them
    // in an ascending order into the main array
    while ( left_index < left_size && right_index < right_size)//checks if the counters cross each other
    {
        if (leftarray[left_index] <= rightarray[right_index])// compare the values
        {
            array[index++] = leftarray[left_index++];//merge(replacing) the items
        }
        else
        {
            array[index++] = rightarray[right_index++];//merge(replacing) the items
        }
    }

    //copy the remaining items of sub arrays into the main array
    // if there were any(whene one of the conditions is violated,
    // it breakes out of the loop; there might be some items left
    //  in the other array which it's condition is still valid )
    while (left_index < left_size)
    {
        array[index++] = leftarray[left_index++];
    }
    
    while (right_index < right_size)
    {
        array[index++] = rightarray[right_index++];
    }
    
    delete[] leftarray;
    delete[] rightarray;

}
void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

//=== MAIN =================================================
int main()
{
    return 0;
}