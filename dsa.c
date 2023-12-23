void binarySearch(int arr[], int n, int target_value) {

    int left = 0;
    int right = n - 1;
    int found = 0;

    while(left <= right) {

        //int mid = left + (right - left) / 2; //preferred
        /* This will also work but the above is preferred because the above mid = left + (right - left) / 2 prefents integer overflow issues.
        In some programming language, if left and right are large integers adding them might exceed the maximum representable integer value causing overlow
        and unexpected behaviour. Both above and below equation are the same but in case of mid = (left+right)/2 the program
        calculates (left+right) first and then devide by 2 hence there is a possibility of overflow. But if we do mid = left + (right - left)/2
        then we are doing (right - left) first; device by 2 and then adding with left hence the possibility of overflow is less.*/

        int mid = (left + right) / 2; //Not preferred

        if(arr[mid] == target_value) {
            printf(GREEN_COLOR "\nElement %d is found at index: %d" RESET_COLOR, target_value, mid);
            found = 1;
            break;
        } else if(arr[mid] < target_value) {
            left = mid+1;
        } else if(arr[mid] > target_value) {
            right = mid -1;
        }

    }

    if(found == 0) {
        printf(RED_COLOR "\nElement %d is not found the array." RESET_COLOR, target_value);
    }

}

void bubbleSort(int arr[], int n) {

    printf("\n%sThe numbers before sorting: %s", GREEN_COLOR, RESET_COLOR);
    printNumbersArray(arr, n);

    printf("\n\n%sBelow are the bubble sorting steps: %s\n", BLUE_COLOR, RESET_COLOR);

    int temp;
    /* n-1 because we need to go upto the n-1 th element
    and check with the last elment with j and j+1 */
    for(int i=0; i<n-1; i++) {
        int swapped = 0;
        /* n-i-1 because the last element is sorted with each outer loop completed
        and we don't need to check it for the next iterations */

        printf(BLUE_COLOR "Step %d: Swappings\n" RESET_COLOR, i+1);

        for(int j=0; j<n-i-1; j++) {

            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;

                printf("    Swapping %d with %d\n", arr[j], arr[j+1]);

            }
        }

        /*If no element was swapped in the inner loop then
         no more elements to sort, so break */
        if(swapped == 0) {
            break;
        }
    }

    printf("\n%sThe numbers after sorting(ASC): %s", GREEN_COLOR, RESET_COLOR);
    printNumbersArray(arr, n);
    printf("\n");

}

void insertionSort(int arr[], int n) {

    int temp, key;

    printf(GREEN_COLOR "\nGiven array: " BLUE_COLOR);
    printNumbersArray(arr, n);

    printf(BLUE_COLOR "\n\nInsertion Sorting steps: \n" RESET_COLOR);

    for(int i=1; i<n; i++) {

        key = arr[i];

        // Using coremen book's insertion sort algorithm
        /*
        int j = i-1;
        while(j>=0 && arr[j]>key) {

            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
        */

        //Using my own algorithm
        for(int j=i-1, k=i; j>=0 && arr[j]>key; j--, k--) {
            //Swap elements
            temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
        }

        printf("Step %d: array after i=%d outer loop iteration: ", i, i);
        printNumbersArray(arr, n);
        printf("\n");

    }

    printf(GREEN_COLOR "\nFinal array after insertion sorting: " RESET_COLOR);
    printNumbersArray(arr, n);

}

long double factorial(int n) {

    if( n == 0 ) {

        return 1;

    } else {

        return n * factorial(n-1);
    }
}

long long int fibonacchi(int n) {

    if( n <= 1 ) {
        return n;
    } else {
        return fibonacchi(n-1)+fibonacchi(n-2);
    }

}

void tower_of_hanoi(int n, char A, char B, char C) {

    if(n>0) {

        tower_of_hanoi(n-1, A, C, B);
        printf("Move disc from %c to %c\n", A, C);
        tower_of_hanoi(n-1, B, A, C);

    }
}
