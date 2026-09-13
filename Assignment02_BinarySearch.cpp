#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(const vector<int>& numbers, int target, int& comparisons) {
    int low = 0;
    int high = numbers.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;

        if (numbers[mid] == target) {
            return mid;
        }
        else if (numbers[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(const vector<int>& numbers, int low, int high,
                          int target, int& comparisons) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    comparisons++;

    if (numbers[mid] == target) {
        return mid;
    }
    else if (numbers[mid] < target) {
        return binarySearchRecursive(numbers, mid + 1, high, target, comparisons);
    }
    else {
        return binarySearchRecursive(numbers, low, mid - 1, target, comparisons);
    }
}

int linearSearch(const vector<int>& numbers, int target, int& comparisons) {
    for (int i = 0; i < numbers.size(); i++) {
        comparisons++;
        if (numbers[i] == target) {
            return i;
        }
    }

    return -1;
}

void runTest(const vector<int>& numbers, int target, const string& testName) {
    int iterativeComparisons = 0;
    int recursiveComparisons = 0;
    int linearComparisons = 0;

    int iterativeIndex = binarySearchIterative(numbers, target, iterativeComparisons);
    int recursiveIndex = binarySearchRecursive(numbers, 0, numbers.size() - 1,
                                                target, recursiveComparisons);
    int linearIndex = linearSearch(numbers, target, linearComparisons);

    cout << testName << endl;
    cout << "Target: " << target << endl;
    cout << "Iterative Binary Search: index " << iterativeIndex
         << ", comparisons " << iterativeComparisons << endl;
    cout << "Recursive Binary Search: index " << recursiveIndex
         << ", comparisons " << recursiveComparisons << endl;
    cout << "Linear Search: index " << linearIndex
         << ", comparisons " << linearComparisons << endl;
    cout << endl;
}

int main() {
    vector<int> numbers = {2, 5, 8, 12, 16, 20, 25, 31, 38, 44, 50};

    runTest(numbers, 2, "Test 1 - First Element");
    runTest(numbers, 50, "Test 2 - Last Element");
    runTest(numbers, 20, "Test 3 - Middle Element");
    runTest(numbers, -3, "Test 4 - Missing Below Range");
    runTest(numbers, 18, "Test 5 - Missing Inside Range");

    return 0;
}
