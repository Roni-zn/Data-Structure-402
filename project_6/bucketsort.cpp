#include <iostream>

using namespace std;

class BucketSort
{
    public:
        void bucket_sort(int *array, int s);
};

void BucketSort::bucket_sort(int arr[], int s)
{
    const int max_value = 100;
    const int num_buckets = max_value + 1;
    int buckets[num_buckets] = {0}; // Creating an array of buckets

    for (int i = 0; i < s; i++)
    {
        int b1 = num_buckets * arr[i] / (max_value + 1);
        buckets[b1]++;
    }

    // Sorting buckets
    int index = 0;
    for (int j = 0; j < num_buckets; j++)
    {
        for (int k = 0; k < buckets[j]; k++)
        {
            arr[index++] = j * (max_value + 1) / num_buckets;
        }
    }
}

int main()
{
    return 0;
}
