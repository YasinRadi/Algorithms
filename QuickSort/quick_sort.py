from typing import List

class QuickSort:
    """ Quick sort algorithm implementation. """

    @staticmethod
    def _partition(a: List[int], low: int, high: int):
        """ Partition function. 
        
        Parameters:
        -----------
        a : List[int]
            List to be sorted.
        
        low : int
            Lower list bound.
        
        high : int
            Higher list bound.

        Returns: int
            Pivot of sorting algorithm.

        """
        pivot = a[high]
        i = low - 1

        for j in range(high):
            if a[j] <= pivot:
                i += 1
                a[i], a[j] = a[j], a[i]
        
        a[i + 1], a[high] = a[high], a[i + 1]
        return i + 1
    
    @staticmethod
    def sort(a: List[int], low: int, high: int):
        """ Sorting function. 
        
        Parameters:
        -----------
        a : List[int]
            List to be sorted.
        
        low : int
            Lower list bound.
        
        high : int
            Higher list bound.

        """
        if low < high:
            partition_idx = QuickSort._partition(a, low, high)

            # Sort first half
            QuickSort.sort(a, low, partition_idx - 1)

            # Sort second hald
            QuickSort.sort(a, partition_idx + 1, high)