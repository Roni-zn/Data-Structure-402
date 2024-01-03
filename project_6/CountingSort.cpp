#include <iostream>
#include <array>
#include <vector>
using namespace std;

class CountingSort
{
    private:
        int range = 100;

    public:
        void counting_sort(int array[]);

};
// ---- sorting -----
void CountingSort::counting_sort(int input_arr[])
{
    int size;
    size = sizeof(input_arr) / sizeof(input_arr[0]);
    vector<int> o_arr(size); //int o_array[size];
    vector<int> count_arr(range); //int count_array[range];

  /*  for (int i=0 ;i< range; i++)
    {
        counting_array[i] = 0;
    }
    for (int j= 0; j<size ; j++)
    {
        counting_array[input_array[j]]++ ;
    }*/

    for (int i=0 ;i< range; i++)
    {
        count_arr[i] = 0;
        for (int j=0; j<size; j++)
        {
            if (input_arr[j] == i)
                count_arr[i]++;
        }
    }
    for(int i=1;i<range;i++)
    {
		count_arr[i]= count_arr[i] + count_arr[i-1];
    }
    for(int i=0;i<size ;i++)
		o_arr[--count_arr[input_arr[i]]] = input_arr[i];
	
	for(int i=0;i<size ;i++)
    {
		input_arr[i]=o_arr[i];
    }

}

int main()
{
    return 0;
}