#include <iostream>
#include <array>
using namespace std;

class QuickSort
{
    private:
        static int partition(int array[], int left, int right);    
    public:
        static void quicksort(int array[], int begin, int end); 
        
        

};

int QuickSort::partition(int array[], int left, int right)
{
    int pivot = array[left], pivotindex = left;//peak the first item as pivot

    for(int i = left + 1 ;i <= right ; i++)// moves the pivot forward to put it in middle or about
    {
        if(array[i] <= pivot)
        pivotindex++;// find the right index for pivot
    }
    swap(array[pivotindex], array[left]);// swap the pivot with the value of index
    int i = left,j = right;//takes tow int to traverse the array form begining and end
    while(i < pivotindex && j > pivotindex)// breaks out form loop when reaches the pivot at pivot index
    {
        while(array[i] <= pivot)//traverse till finds an item greater than pivot
        {
            i++;
        }
        while(array[j] > pivot)//traverse from  end  till finds an item smaller than pivot
        {
            j--;
        }
        if(i < pivotindex && j > pivotindex)// if i & j haven't crossed each other, swap the items at index i & j with each other
        {
            swap(array[i++], array[j--]);
        }

    }

    return pivotindex;// returns the index of pivot (to use in quicksort function)

}
//--- quick sort ------------------
void QuickSort::quicksort(int array[], int left, int right)
{
    if(left >= right)//ending condition . whene the sub array's length becomes 1, the array is sorted, so returns and ignor the rest.
    return;

    int border = partition(array, left, right);// takes the returned int from partition function as border(which is the index of pivot)
    quicksort(array, left, border - 1 );//calls quicksort function for the array, but form begining to one item before border(quick sorting the left part of aaray)
    quicksort(array, border + 1 , right);//calls quicksort function for the array, but form one after border (pivot) to end (quick sorting the right part of aaray)
    // the function reqursivly calls it self, first for left parts each time, then for the right parts 
}
//--- main ------
int main()
{
    return 0;
}
