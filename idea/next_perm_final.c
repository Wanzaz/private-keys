bool next_permutation(char *array, int length)
{
    // find pivot
    int pivot;
    for (pivot = length - 1; pivot > 0 && array[pivot - 1] > array[pivot]; pivot--) ;
    pivot--;

    // if there is no pivot the array is already in its last permutation
    if (pivot < 0)
        return false;

    // find the 'smallest value larger than pivot' (svltp) to the right of pivot (there will always be at leas one)
    int svltp;
    for (svltp = length - 1; array[svltp] < array[pivot]; svltp--) ;

    // swap pivot and sltp
    swap(&array[pivot], &array[svltp]);

    // reverse everything to the right of pivot
    reverse(&array[pivot + 1], length - pivot - 1);

    return true;
}

void reverse(char *array, int length)
{
    int lim = length / 2;
    for (int i = 0; i < lim; i++)
        swap(&array[i], &array[length - 1 - i]);
}

void swap(char *c1, char *c2)
{
    char h = *c1;
    *c1 = *c2;
    *c2 = h;
}
