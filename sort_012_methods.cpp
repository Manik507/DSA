
#include <iostream>
#include <vector>
#include <algorithm> // for inbuilt sort

using namespace std;

// Function 1: Using inbuilt sort
void sortWithInbuilt(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // STL sort
}

// Function 2: Counting 0s, 1s and 2s and filling back
void sortByCounting(vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Count number of 0s, 1s, and 2s
    for (int num : arr) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else count2++;
    }

    // Overwrite the array using counts
    int index = 0;
    while (count0--) arr[index++] = 0;
    while (count1--) arr[index++] = 1;
    while (count2--) arr[index++] = 2;
}

// Function 3: Dutch National Flag algorithm (1 pass)
void sortByDNF(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    // Process elements and place them in correct region
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {2, 0, 2, 1, 1, 0};
    vector<int> arr2 = arr1; // copy for count method
    vector<int> arr3 = arr1; // copy for DNF method

    // Using inbuilt sort
    sortWithInbuilt(arr1);
    cout << "Sorted with inbuilt sort: ";
    printArray(arr1);

    // Using counting method
    sortByCounting(arr2);
    cout << "Sorted by counting: ";
    printArray(arr2);

    // Using Dutch National Flag algorithm
    sortByDNF(arr3);
    cout << "Sorted by DNF algorithm: ";
    printArray(arr3);

    return 0;
}
