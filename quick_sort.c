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
quick_sort (int *a, int start_idx, int end_idx)
{
    int pivot, pivot_idx;
    int iter, swap_idx;

    if (end_idx <= swap_idx) {
        //One or zero elements are always sorted.
        return;
    }

    //Get a "random" pivot.
    pivot_idx = (start_idx + end_idx)/2; 

    iter = start_idx;
    pivot = a[pivot_idx];
    swap_idx = end_idx;
    while (iter < swap_idx) {
        if (a[iter] < pivot) {
            //This is in correct order.
            iter++;
        } else {
            //Move element to the right of pivot.
            int temp = a[swap_idx];
            a[swap_idx] = a[iter];
            a[iter] = temp;
            swap_idx--;
        }
    }
    if (a[iter] < pivot) {
        pivot_idx = iter;
    } else {
        pivot_idx = iter - 1;
    }
    quick_sort(a, start_idx, pivot_idx);
    quick_sort(a, pivot_idx + 1, end_idx);
}

static void
sort_arr (int *a, uint64_t size_of_arr) {
    return quick_sort(a, 0, size_of_arr - 1);
}

int
main() {
    int a[] = {1, 11, 93, -3, 72, 4, 11, 23, 300, 21, 31, 2, 13, 73, 1000};

    uint64_t size_of_arr =  sizeof(a)/sizeof(int);

    print_arr(a, size_of_arr);

    sort_arr(a, size_of_arr);

    print_arr(a, size_of_arr);

}
