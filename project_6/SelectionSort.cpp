#include <iostream>
#include <array>
using namespace std;

class SelectionSort
{
    public:
    static void selectionsort(int array[],int size);

};

void SelectionSort::selectionsort(int array[], int size)
{
    int  i, j, min_index;
    for(i = 0; i < size; i++)//
    {
        min_index = i;
        for(j = i + 1; j < size; j++)//finds the index of the smallest item
        {
            if(array[j] < array[min_index])
            min_index = j;
        }

        if(array[min_index] != array[i])//if the smallest item was at the begining, or there were several of same value, dosen't swap them.
        swap(array[min_index], array[i]);
    }

}
int main()
{
    return 0;
}