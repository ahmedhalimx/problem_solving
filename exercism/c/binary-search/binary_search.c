#include "binary_search.h"

 const int *binary_search(int value, const int *arr, size_t length){    
    int left = 0;
    int right = length;

    if (arr == NULL)
        return NULL;

    while (left < right) {
            int middle_idx = left + ((right - left) / 2);
            
            if (arr[middle_idx] == value) 
                return (arr + middle_idx);

            if (arr[middle_idx] < value)
                left = middle_idx + 1;
            else 
                right = middle_idx;
    }
    return (NULL);
}
