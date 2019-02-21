using System;

/// <summary>
/// QuickSort implementation class.
/// </summary>
public class QuickSort
{
    private static void Swap(ref int a, ref int b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    private static  int Partition(ref int[] a, int low, int high) {
        // Pivot
        int pivot = a[high];
        // Idx of smaller element
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a[j] <= pivot) {
                i++;
                Swap(ref a[i], ref a[j]);
            }
        }

        Swap(ref a[i + 1], ref a[high]);
        return ++i;
    }

    /// <summary>
    /// Sorts a given array using QuickSort algorithm.
    /// </summary>
    /// <param name="a">Array to be sorted.</param>
    /// <param name="low">Lower array bound.</param>
    /// <param name="high">Higher array bound.</param>
    public static void Sort(ref int[] a, int low, int high) {
        if (low < high) {
            int partition_idx = Partition(ref a, low, high);

            // Sort first half
            Sort(ref a, low, partition_idx - 1);

            // Sort second half
            Sort(ref a, partition_idx + 1, high);
        }
    }
}