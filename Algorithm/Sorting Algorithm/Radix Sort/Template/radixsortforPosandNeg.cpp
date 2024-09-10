#include <iostream>
using namespace std;

const int MSB = 64;

void sort(int a[], int d, int lo, int hi) {
    // Function to check if the k-th bit is set in x
    auto isBitSet = [](long x, int k) {
        bool set = (x & (1L << (k - 1))) != 0;
        return (k == MSB) != set;
    };

    // Function to swap two elements in the array
    auto swap = [](int a[], int i, int j) {
        long tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    };

    if (hi < lo || d < 1) return;

    int left = lo - 1;
    int right = hi + 1;

    for (int i = left + 1; i < right; ) {
        if (isBitSet(a[i], d)) {
            swap(a, i, --right);
        } else {
            left++;
            i++;
        }
    }

    sort(a, d - 1, lo, left);
    sort(a, d - 1, right, hi);
}

int main() {
    int n;
    
    cin >> n;

    int a[n];
   
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, MSB, 0, n - 1);

    
    for(int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;

    return 0;
}
