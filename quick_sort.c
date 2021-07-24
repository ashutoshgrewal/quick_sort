#include <stdio.h>
#include <inttypes.h>

static inline void
print_arr (int a[], uint64_t size_of_arr)
{
    printf("\n");
    for (int i = 0; i < size_of_arr; i++) {
        printf("%d, ", a[i]);
    }
}

static void
swap_elements (int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;  
}

static void
quick_sort (int *a, int start_idx, int end_idx)
{
    int pivot, pivot_idx;
    int iter, swap_idx;

    if (end_idx <= start_idx) {
        //One or zero elements are always sorted.
        return;
    }

    //Get a "random" pivot.
    pivot_idx = end_idx; 

    iter = start_idx;
    pivot = a[pivot_idx];
    swap_idx = end_idx - 1;
    while (iter < swap_idx) {
        if (a[iter] <= pivot) {
            //This is in correct order.
            iter++;
        } else {
            //Move element to the right of pivot.
            swap_elements(&a[swap_idx], &a[iter]);
            swap_idx--;
        }
    }
    if (a[iter] < pivot) {
        pivot_idx = iter + 1;
    } else {
        pivot_idx = iter;
    }
    swap_elements(&a[pivot_idx], &a[end_idx]);
    quick_sort(a, start_idx, pivot_idx-1);
    quick_sort(a, pivot_idx + 1, end_idx);
}

static void
sort_arr (int *a, uint64_t size_of_arr) {
    return quick_sort(a, 0, size_of_arr - 1);
}

int
main() {
    int a[] = {3, 3};

    uint64_t size_of_arr =  sizeof(a)/sizeof(int);

    print_arr(a, size_of_arr);

    sort_arr(a, size_of_arr);

    print_arr(a, size_of_arr);

}
