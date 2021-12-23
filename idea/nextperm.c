#include <stdbool.h>
#include <stddef.h>

/* 
 * Computes the next lexicographical permutation of the specified
 * array of integers in place, returning a Boolean to indicate
 * whether a next permutation existed. (Returns false when the
 * argument is already the last possible permutation.)
 */
bool next_permutation(int array[], size_t length) {
    // Find non-increasing suffix
    if (length == 0)
        return false;
    size_t i = length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    if (i == 0)
        return false;
    
    // Find successor to pivot
    size_t j = length - 1;
    while (array[j] <= array[i - 1])
        j--;
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    
    // Reverse suffix
    j = length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return true;
}
