#include <iostream>

class QuickSort {
    private:
        // Swap utility function
        static void swap(int* a, int* b) {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        };

        // Partition function
        static int partition(int* a, int low, int high) {
            int pivot = a[high];    // Pivot
            int i = low - 1;        // Idx of smaller element

            for (int j = low; j < high; j++) {
                if (a[j] <= pivot) {
                    i++;    // Increment idx of smaller elm
                    swap(&a[i], &a[j]);
                }
            }

            swap(&a[i + 1], &a[high]);
            return ++i;
        };
    
    public:
        // Quick sort implementation 
        static void sort(int* a, int low, int high) {
            if (low < high) {
                int partition_idx = partition(a, low, high);

                // Sort first half
                sort(a, low, partition_idx - 1);

                // Sort second half
                sort(a, partition_idx + 1, high);
            }
        }
};