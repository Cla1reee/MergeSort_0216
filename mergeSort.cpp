#include <iostream>
using namespace std;

int arr[20], B[20];
int n;

void input() {
    while (true) {
        cout << "Masukkan Panjang element array : ";
        cin >> n;
        if (n <= 20) break;
        else cout << "\nMaksimal panjang array adalah 20" << endl;
    }

    cout << "\n-------------------" << endl;
    cout << "Inputkan Isi elemen array" << endl;
    cout << "-------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Array index ke-" << i << " : ";
        cin >> arr[i];
    }
}

void output() {
    cout << "\nData setelah diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(low, mid);      // Bagian kiri
    mergeSort(mid + 1, high); // Bagian kanan

    int i = low;     // Indeks awal sub-array kiri
    int j = mid + 1; // Indeks awal sub-array kanan
    int k = low;     // Indeks awal untuk array sementara B

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }

    while (j <= high) { // Sisa di kanan
        B[k] = arr[j];
        j++;
        k++;
    }

    while (i <= mid) { // Sisa di kiri
        B[k] = arr[i];
        i++;
        k++;
    }

    for (int x = low; x <= high; x++) {
        arr[x] = B[x];
    }
}

int main() {
    return 0;
}