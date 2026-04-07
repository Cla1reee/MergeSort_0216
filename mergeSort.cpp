#include <iostream>
using namespace std;

// Deklarasi array utama dan array sementara secara global
int arr[20], B[20];
int n; 

void input() {
    while (true) {
        cout << "Masukkan Panjang element array : ";
        cin >> n;

        if (n > 0 && n <= 20) {
            break;
        } else {
            cout << "\nMaksimal panjang array adalah 20 dan tidak boleh 0!" << endl;
        }
    }

    cout << "\n-------------------" << endl;
    cout << "Inputkan Isi elemen array" << endl;
    cout << "-------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Array index ke-" << i << " : ";
        cin >> arr[i];
    }
}

void mergeSort(int low, int high) {
    // Step 1: Base case
    if (low >= high) {
        return;
    }

    // Step 2: Mencari titik tengah
    int mid = (low + high) / 2;

    // Step 3: Rekursi
    mergeSort(low, mid);      
    mergeSort(mid + 1, high); 

    // Step 4: Merging
    int i = low;      
    int j = mid + 1;  
    int k = low;      

    // Perbaiki Step 4.d - Logika perbandingan
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

    // Perbaiki Step 4.e & 4.f - Memindahkan sisa elemen
    while (i <= mid) { 
        B[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) { 
        B[k] = arr[j];
        j++;
        k++;
    }

    // Step 5: Copy data kembali ke array asal
    for (int x = low; x <= high; x++) {
        arr[x] = B[x];
    }
}

void output() {
    cout << "\nData setelah diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    input();             
    if (n > 0) {
        mergeSort(0, n - 1); 
        output();            
    }
    return 0;
}