#include <iostream>

template <typename T>
void sort(T* arr, size_t size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

template <>
void sort<char>(char* arr, size_t size) {
    int counts[128] = { 0 };

    for (int i = 0; i < size; i++) {
        counts[arr[i]]++;
    }

    size_t currentIndex = 0;

    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < counts[i]; j++) {
            arr[currentIndex++] = i;
        }
    }
}

int main() {
    char* ime = new char[5];
    ime[0] = 'c';
    ime[1] = 'd';
    ime[2] = 'a';
    ime[3] = 'b';
    ime[4] = '\0';

    sort(ime, 4);

    std::cout << ime;
    delete[] ime;

    std::cout << std::endl;

    int arr[] = {8, 7, 5, 10};
    sort(arr, 4);

    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }
}
