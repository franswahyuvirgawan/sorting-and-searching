#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void akhir();
void cetakAkhir();

void seedArray(int arr[], int n) {
    int i;
    srand(0);
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 64000;
        arr[i] = rand();
    }
}

void seedArraySearching(int arr[], int n) {
    int i;
    srand(0);
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void dupArray(int source[], int target[], int n) {
    int i;
    for (i = 0; i < n; i++)
        target[i] = source[i];
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("-Angka ke-%d : %d", i, arr[i]);
        printf("\n");
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int temp;
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    int pi = partition(arr, low, high);
    if (low < high) {
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int Sorting() {

    clock_t waktu;
    double detik1;
    double detik2;
    double detik3;
    int i;
    char pilihan;
    char enterCheck;
    int n;

    system("cls");
    printf("|============[ MENU SORTING ]===========|\n");
    printf("|=======================================|\n");
    printf("|        This Program Created By :  	|\n");
    printf("|               KELOMPOK 13         	|\n");
    printf("|=======================================|\n");
    printf("|1. 1000 data                           |\n");
    printf("|2. 16000 data                          |\n");
    printf("|3. 64000 data                          |\n");
    printf("|4. Kembali                             |\n");
    printf("|5. Keluar                              |\n");
    printf("|=======================================|\n");
    do {
        printf("\nMasukkan pilihan: ");
        if (scanf("%c%c", & pilihan, & enterCheck) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan == '1') {
                n = 1000;
                break;
            } else if (pilihan == '2') {
                n = 16000;
                break;
            } else if (pilihan == '3') {
                n = 64000;
                break;
            } else if (pilihan == '4') {
                main();
                break;
            } else if (pilihan == '5') {
                return 0;
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);

    int arr[n];
    int arr2[n];
    int arr3[n];
    seedArray(arr, n);
    printf("Array %d data random sebelum di sort :\n", n);
    printArray(arr, n);
    dupArray(arr, arr2, n);
    dupArray(arr, arr3, n);

    //Insertion Sort
    waktu = clock();
    insertionSort(arr, n);
    waktu = clock() - waktu;
    detik1 = (double)(waktu) / CLOCKS_PER_SEC;

    //Bubble Sort
    waktu = clock();
    bubbleSort(arr2, n);
    waktu = clock() - waktu;
    detik2 = (double)(waktu) / CLOCKS_PER_SEC;

    //Quick Sort
    waktu = clock();
    quickSort(arr3, 0, n - 1);
    waktu = clock() - waktu;
    detik3 = (double)(waktu) / CLOCKS_PER_SEC;

    printf("\n=====================================================================================================");
    printf("\nArray %d data random sesudah di sort :\n", n);
    printArray(arr, n);
    printf("\n=====================================================================================================");
    printf("\n\nperbandingan waktu:");
    printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data\n", detik1);
    printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data\n", detik2);
    printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", detik3);
    if (detik1 <= detik2 && detik1 <= detik3) {
        printf("\nInsertion sort yang paling cepat\n");
    } else if (detik2 <= detik1 && detik1 <= detik3) {
        printf("\nBubble sort yang paling cepat\n");
    } else {
        printf("\nQuick sort yang paling cepat\n");
    }

    akhir();
}

double sequentialSearch(int arr[], int n, int angkaDicari) {
    clock_t waktu;
    double detik;
    int i, counter = 0;

    waktu = clock();
    for (i = 0; i < n; i++) {
        if (arr[i] == angkaDicari) {
            counter++;
        }
        printf("-Angka ke-%d : %d", i, arr[i]);
        printf("\n");
    }
    waktu = clock() - waktu;
    detik = (double)(waktu) / CLOCKS_PER_SEC;

    if (counter == 0) {
        printf("\n=====================================================================================================\n");
        printf("\nTidak Ada Angka Yang Sesuai, pada sequential search!");
    } else {
        int indexAngkaDicari[counter];
        counter = 0;

        for (i = 0; i < n; i++) {
            if (arr[i] == angkaDicari) {
                indexAngkaDicari[counter] = i;
                counter++;
            }
        }

        printf("\n=====================================================================================================");
        printf("\n\nAngka Ditemukan Pada Index sequential search: ");
        for (i = 0; i < counter; i++) {
            if (i == 0 && i == counter - 1) {
                printf(" %d.", indexAngkaDicari[i]);
            } else {
                if (i == counter - 1) {
                    printf(" dan %d.", indexAngkaDicari[i]);
                } else {
                    printf(" %d,", indexAngkaDicari[i]);
                }
            }
        }
    }

    return detik;
}

double binarySearch(int arr[], int low, int high, int angkaDicari) {
    clock_t waktu;
    double detik;
    int i, counter = 0;

    waktu = clock();
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == angkaDicari) {
            counter++;
            for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++) {
                counter++;
            }
            for (i = mid - 1; i < high + 1 && arr[i] == angkaDicari; i++) {
                counter++;
            }
            break;
        } else if (arr[mid] > angkaDicari) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    waktu = clock() - waktu;
    detik = (double)(waktu) / CLOCKS_PER_SEC;

    if (counter == 0) {
        printf("\n\nTidak Ada Angka Yang Sesuai pada binary search!");
    } else {
        int indexAngkaDicari[counter];
        counter = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == angkaDicari) {
                indexAngkaDicari[counter] = mid;
                counter++;
                for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++) {
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                for (i = mid - 1; i > 0 && arr[i] == angkaDicari; i--) {
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                break;
            } else if (arr[mid] > angkaDicari) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printf("\n\nAngka Ditemukan Pada Index, binary search: ");
        bubbleSort(indexAngkaDicari, counter);
        for (i = 0; i < counter; i++) {
            if (i == 0 && i == counter - 1) {
                printf(" %d.", indexAngkaDicari[i]);
            } else {
                if (i == counter - 1) {
                    printf(" dan %d.", indexAngkaDicari[i]);
                } else {
                    printf(" %d,", indexAngkaDicari[i]);
                }
            }
        }
    }

    return detik;
}

int Searching() {
    clock_t waktu;
    double detik1;
    double detik2;
    int i;
    int n;
    int menu;
    int angkaDicari;
    char enterCheck;
    char pilihan;

    system("cls");
    printf("|===========[ MENU SEARCHING ]==========|\n");
    printf("|=======================================|\n");
    printf("|        This Program Created By :  	|\n");
    printf("|               KELOMPOK 13         	|\n");
    printf("|=======================================|\n");
    printf("|1. 1000 data                           |\n");
    printf("|2. 16000 data                          |\n");
    printf("|3. 64000 data                          |\n");
    printf("|4. Kembali                             |\n");
    printf("|5. Keluar                              |\n");
    printf("|=======================================|\n");
    do {
        printf("\nMasukkan pilihan: ");
        if (scanf("%c%c", & pilihan, & enterCheck) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan == '1') {
                n = 1000;
                break;
            } else if (pilihan == '2') {
                n = 16000;
                break;
            } else if (pilihan == '3') {
                n = 64000;
                break;
            } else if (pilihan == '4') {
                main();
                break;
            } else if (pilihan == '5') {
                return 0;
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);

    int arr[n];
    int arr2[n];
    seedArraySearching(arr, n);
    printArray(arr, n);
    do {
        printf("\nMasukkan Angka Yang Ingin Dicari: ");
        if (((scanf("%d%c", & angkaDicari, & enterCheck)) != 2 || enterCheck != '\n')) {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (angkaDicari < 0) {
                printf("Inputan tidak boleh dibawah '0'");
            } else {
                break;
            }
        }
    } while (1);

    bubbleSort(arr, n);
    detik1 = sequentialSearch(arr, n, angkaDicari);
    detik2 = binarySearch(arr, 0, n - 1, angkaDicari);

    printf("\n\n=====================================================================================================");
    printf("\n\nperbandingan waktu: \n");
    printf("\nSequential Search Membutuhkan %f Detik Untuk Mencari Data", detik1);
    printf("\nBinary Search Membutuhkan %f Detik Untuk Mencari Data\n", detik2);
    if (detik1 <= detik2) {
        printf("Maka Pada Pencarian Kali Ini, Sequential Search Lebih Cepat Dari Binary Search\n");
    } else {
        printf("Maka Pada Pencarian Kali Ini, Binary Search Lebih Cepat Dari Sequential Search\n");
    }

    akhir();
}

int main() {
    char pilihan;
    char enterCheck;

    system("cls");
    printf("|===========[ MENU SORTING DAN SEARCHING ]==========|\n");
    printf("|===================================================|\n");
    printf("|              This Program Created By :            |\n");
    printf("|                    KELOMPOK 13                    |\n");
    printf("|===================================================|\n");
    printf("|1. Sorting                                         |\n");
    printf("|2. Searching                                       |\n");
    printf("|3. Keluar                                          |\n");
    printf("|===================================================|\n");

    do {
        printf("\nMasukkan pilihan: ");
        if (scanf("%c%c", & pilihan, & enterCheck) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan == '1') {
                Sorting();
                break;
            } else if (pilihan == '2') {
                Searching();
                break;
            } else if (pilihan == '3') {
                return 0;
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);
}

void cetakAkhir() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("* TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI *\n");
    printf("|                GOOD BYE >_<                 |\n");
    printf("*             FROM KELOMPOK 13                *\n");
    printf("-----------------------------------------------\n");
}

void akhir() {
    char pilihan;
    char enterCheck;

    printf("\n=====================================================================================================\n");
    printf("\nSilahkan pilih langkah yang ingin anda lakukan selanjutnya\n");
    printf(" 1. Kembali ke Menu Utama\n");
    printf(" 2. Keluar\n");
    do {
        printf("\nMasukkan pilihan: ");
        if ((scanf("%c%c", & pilihan, & enterCheck)) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan == '1') {
                main();
                break;
            } else if (pilihan == '2') {
                cetakAkhir();
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);
}
