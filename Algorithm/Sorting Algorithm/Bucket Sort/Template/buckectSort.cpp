#include <iostream>
using namespace std;

void bucketSort(double input[], int size, int num_buckets)
{
    if (size <= 0)
        return; // Handle empty input

    // Find minimum and maximum values
    double min_val = input[0], max_val = input[0];
    for (int i = 1; i < size; ++i)
    {
        if (input[i] < min_val)
            min_val = input[i];
        if (input[i] > max_val)
            max_val = input[i];
    }

    // Calculate the range and width of each bucket
    double range = max_val - min_val;
    double bucket_width = range / num_buckets;

    // Initialize buckets
    int bucket_counts[num_buckets] = {0};
    double **buckets = new double *[num_buckets];
    for (int i = 0; i < num_buckets; ++i)
    {
        buckets[i] = new double[size];
    }

    // Distribute elements into buckets
    for (int i = 0; i < size; ++i)
    {
        int bucket_index = (input[i] - min_val) / bucket_width;
        if (bucket_index == num_buckets)
            bucket_index--; // Adjust for the last bucket
        buckets[bucket_index][bucket_counts[bucket_index]++] = input[i];
    }

    // Sort elements within each bucket (using insertion sort)
    for (int i = 0; i < num_buckets; ++i)
    {
        for (int j = 1; j < bucket_counts[i]; ++j)
        {
            double key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Merge buckets back into input array
    int index = 0;
    for (int i = 0; i < num_buckets; ++i)
    {
        for (int j = 0; j < bucket_counts[i]; ++j)
        {
            input[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }
    delete[] buckets;
}

int main()
{
    int n;
    cin >> n;
    double a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int num_buckets = 5;

    bucketSort(a, n, num_buckets);

    cout << "Sorted Output:";
    for (int i = 0; i < n; ++i)
        cout << " " << a[i];
    cout << endl;

    return 0;
}
