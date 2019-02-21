#include <iostream>

class HeapSort {
    private:
        static void swap(int* a, int* b) {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        };

        static int right(int i) {
            return 2 * i + 2;
        };

        static int left(int i) {
            return 2 * i + 1;
        };

        static void heapify(int* a, int n, int i) {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest != i) {
                swap(&a[i], &a[largest]);

                // Recursively heapify the target subtree
                heapify(a, n, largest);
            };
        };

    public:
        static void sort(int* a, int n) {
            // Re-arrange array to build heap
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(a, n, i);
            }

            for (int i = n - 1; i >= 0; i--) {
                // Move current root to end
                swap(&a[0], &a[i]);

                // Call heapify on readuced heap
                heapify(a, i, 0);
            }
        };
};