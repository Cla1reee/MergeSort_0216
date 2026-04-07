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

int main() {
    return 0;
}