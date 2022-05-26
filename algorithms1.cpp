#include <iostream>
#include <ctime>

using namespace std;
const int sz = 20;

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++) {
        cout << arr[i] << " " << endl;
    }
    cout << endl;
}

int check_if_sorted(int arr[]) {
    int i = 1;
    int is_sorted = 1;
    while (i < sz && is_sorted) {
        if (arr[i - 1] > arr[i]) {
            is_sorted = 0;
            break;
        }
        i++;
    }
    return (is_sorted);
}

int* getArray() {
    static int arr[sz];
    srand((unsigned)time(NULL));
    for (int i = 0; i < sz; i++) {
        arr[i] = rand();
    }
    return arr;
}

int main()
{
    int *unsorted = getArray();

    // Selection sort
    for (int i = 0; i < sz-1; i++) {
        int minindex = i;
        for (int j = i+1; j < sz; j++) {
            if (unsorted[minindex] > unsorted[j]) {
                minindex = j;
            }
        }
        swap(unsorted[i], unsorted[minindex]);
    }
    cout << "Selection sort" << endl;
    cout << "Array is sorted:" << check_if_sorted(unsorted) << endl;
    printArray(unsorted, sz);

    unsorted = getArray();

    //Insertion sort
    for (int i = 1; i < sz; i++){
        int index = unsorted[i];
        int j = i - 1;
        while (j >= 0 && unsorted[j] > index){
            unsorted[j + 1] = unsorted[j];
            j = j - 1;
        }
        unsorted[j + 1] = index;
    }
    cout << "Insertion sort" << endl;
    cout << "Array is sorted:" << check_if_sorted(unsorted) << endl;
    printArray(unsorted, sz);

    unsorted = getArray();

    //Bubble sort
    int it = 0;
    do {
        it = 0;
        for (int i = 0; i < sz-1; i++) {
            if (unsorted[i] > unsorted[i+1]) {
                swap(unsorted[i], unsorted[i+1]);
                it++;
            }
        }
    } while (it != 0);
    cout << "Bubble sort" << endl;
    cout << "Array is sorted:" << check_if_sorted(unsorted) << endl;
    printArray(unsorted, sz);
}

