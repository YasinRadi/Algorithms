
/**
 * QuickSort implementation class.
 * @author Yasin Radi
 */
public class QuickSort {

    private static int partition(int[] array, int low, int high) {
        // Pivot
        int pivot = array[high];
        // Idx of smaller element
        int i = low - 1;
        int tmp = 0;

        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }

        // Swap element with pivot
        tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        
        return ++i;
    };

    /**
     * Sorts an array using QuickSort algorithm.
     * @param array int[]   Array to be sorted.
     * @param low   int     Lower array bound.
     * @param high  int     Higher array bound.
     */
    public static void sort(int[] array, int low, int high) {
        if (low < high) {
            int partition_idx = partition(array, low, high);

            // Sort first half
            sort(array, low, partition_idx - 1);

            // Sort second half
            sort(array, partition_idx + 1, high);
        }
    };
}