#include <stdio.h>
#include<time.h>
#include <stdlib.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n,i;
    double clk;
    clock_t starttime,endtime;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    starttime=clock();
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("\n The run time is %f\n",clk);

    return 0;
}
