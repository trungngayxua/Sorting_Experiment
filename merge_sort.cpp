#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Hàm merge hai mảng con
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Hàm merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile || !outputFile) {
        cerr << "❌ Error opening file!" << endl;
        return 1;
    }

    for (int test = 0; test < 10; test++) {
        vector<int> arr(1'000'000);
        for (int i = 0; i < 1'000'000; i++) inputFile >> arr[i];

        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();
        
        outputFile << "Sort time for line " << test + 1 << ": " 
                   << duration_cast<milliseconds>(end - start).count() << " ms\n";
        cout << "✅ Sorted line " << test + 1 << " in " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
