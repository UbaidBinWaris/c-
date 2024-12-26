#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftPart = new int[n1];
    int *rightPart = new int[n2];

    for (int i = 0; i < n1; i++)
        leftPart[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightPart[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftPart[i] <= rightPart[j])
        {
            arr[k++] = leftPart[i++];
        }
        else
        {
            arr[k++] = rightPart[j++];
        }
    }

    while (i < n1)
        arr[k++] = leftPart[i++];
    while (j < n2)
        arr[k++] = rightPart[j++];

    delete[] leftPart;
    delete[] rightPart;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main Function for Testing
int main()
{
    srand(time(0));

    const int SIZE = 20;
    int scores[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        scores[i] = rand() % 100; // Random numbers between 0 and 99
    }

    cout << "Original Scores: ";
    printArray(scores, SIZE);

    // Testing Merge Sort
    int mergeSortedScores[SIZE];
    copy(scores, scores + SIZE, mergeSortedScores);
    mergeSort(mergeSortedScores, 0, SIZE - 1);
    cout << "Merge Sorted Scores: ";
    printArray(mergeSortedScores, SIZE);

    // Testing Quick Sort
    int quickSortedScores[SIZE];
    copy(scores, scores + SIZE, quickSortedScores);
    quickSort(quickSortedScores, 0, SIZE - 1);
    cout << "Quick Sorted Scores: ";
    printArray(quickSortedScores, SIZE);

    return 0;
}
