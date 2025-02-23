#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int menu, temp, backMenu;
int n = 2000000;
int arr[2000000];
int UseNumber = 1000000;
int arrBaru[1000000];
int arrSort[1000000];


void simpanFile(){
    ofstream myFile;
    myFile.open("data_angka.txt", ios::out);
    if (myFile.is_open()) {
        for(int i = 0; i < n; i++){
            myFile << i+1 << endl;
        }
        myFile.close();
    }
}

void bacaFile() {
    ifstream myFile;
    myFile.open("data_angka.txt");
    if (myFile.is_open()) {
        int j, i = 0;
        while (myFile >> j) {
            arr[i] = j;
            i++;
        }
        myFile.close();

        for (int i = 0; i < n; i++) {
            int angka = rand() % n;
            int temp = arr[i];
            arr[i] = arr[angka];
            arr[angka] = temp;
        }
    }
}

void simpanFileRandom(){
    ofstream myFile;
    myFile.open("data_angkaRandom.txt", ios::out);
    if (myFile.is_open()) {
        for(int i = 0; i < UseNumber; i++){
            myFile << arr[i] << endl;
        }
        myFile.close();
    }
}

void bacaFileRandom() {
    ifstream myFile;
    myFile.open("data_angkaRandom.txt");
    if (myFile.is_open()) {
        int j, i = 0;
        while (myFile >> j) {
            arrBaru[i] = j;
            arrSort[i] = j;
            i++;
        }
        myFile.close();
    }
}

void simpanDurasi(double duration, string nameSort, int n){
    ofstream myFile;
    myFile.open("duration.txt", ios::app);
    if (myFile.is_open()) {
        myFile << nameSort << " ( " << UseNumber << " Data Numbers" << " ) " << ": " << duration << " Seconds" << endl << endl;
        myFile.close();
    }
}

void simpanFileSort(){
    ofstream myFile;
    myFile.open("data_angkaSort.txt", ios::out);
    if (myFile.is_open()) {
        for(int i = 0; i < UseNumber; i++){
            myFile << arrSort[i] << endl;
        }
        myFile.close();
    }
}
void bacaFileSort(){
    ifstream myFile;
    myFile.open("data_angkaSort.txt");
    if (myFile.is_open()) {
        int j, i = 0;
        while (myFile >> j) {
            arrSort[i] = j;
            i++;
        }
        myFile.close();
    }
}

void addLine(){
    ofstream myFile;
    myFile.open("duration.txt", ios::app);
    if (myFile.is_open()) {
        myFile << "---------- New Random Number ----------" << endl;
        myFile.close();
    }
}

int main()
{
    srand(time(0));
    bacaFileRandom();
    bacaFileSort();

    do {
        bool flag;
        int length = sizeof(arrBaru)/sizeof(arrBaru[0]);
        long long  low, high, dicari;
        long long mid;

        cout << "== Searching Menu ==" << endl;
        cout << "1. Generate Number" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Interpolation Search" << endl;
        cout << "0. Exit" << endl;

        do {
            cout << ">> ";
            cin >> menu;
        } while (menu < 0 || menu > 5);
        system("cls");

        switch(menu){
            case 1:{
                do {
                    clock_t start_time = clock();
                    simpanFile();
                    bacaFile();
                    clock_t end_time = clock();
                    // For seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                    simpanFileRandom();
                    addLine();
                    bacaFileRandom();

                    cout << "Generate Number: " << endl << endl;

                    cout << "Finish Generate Numbers" << endl << endl;

                    cout << "Generate Number: " << duration << " Seconds" << endl;
                    cout << "0. Back" << endl;
                    do {
                        cout << ">> ";
                        cin >> backMenu;
                    } while (backMenu < 0 || backMenu > 0);
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 2:{
                do {
                    cout << "Sedang Menyorting .." << endl;
                    clock_t start_time = clock();

                    for(int i = 1; i < UseNumber; i++){
                        for(int j = 0; j <= i-1; j++){
                            if(arrSort[j] > arrSort[i]){
                                temp = arrSort[j];
                                arrSort[j] = arrSort[i];
                                arrSort[i] = temp;
                            }
                        }
                    }

                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                    simpanFileSort();

                    cout << "Insertion Sort: " << endl;

                    for(int k = 0; k < UseNumber; k++){
                        cout << arrSort[k] << endl;
                    }

                    cout << endl << endl;
                    cout << "Insertion Sort took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Insertion Sort", UseNumber);
                    cout << "0. Back" << endl;
                    do {
                        cout << ">> ";
                        cin >> backMenu;
                    } while (backMenu < 0 || backMenu > 0);
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 3:{
                do {
                    cout << "Linear Search: " << endl;
                     cout << endl << "Masukkan angka yang mau dicari: ";
                    cin >> dicari;
                    flag = true;
                    int ctr;
                    ctr = 0;
                    bool found = false;
                    while (flag && ctr < length){
                        if (arrBaru[ctr] == dicari){
                            cout << "found"<<endl;
                            flag = false;

                            found = true;
                        }
                        ctr = ctr +1;
                    };
                    if (!found){
                        cout << "not found"<<endl;
                    }
                    cout << "0. Back" << endl;
                    do {
                        cout << ">> ";
                        cin >> backMenu;
                    } while (backMenu < 0 || backMenu > 0);


                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 4:{
                do {
                    cout << "Binary Search: " << endl;

                    low = 0;
                    high = length-1;
                    flag = true;

                    cout << endl << "Masukkan angka yang mau dicari: ";
                    cin >> dicari;

                    clock_t start_time = clock();
                    while (flag){
                        mid = low + (high - low) / 2;

                        if (arrSort[mid] < dicari){
                            low = mid + 1;
                        }
                        else if (arrSort[mid] > dicari){
                            high = mid - 1;
                        }
                        if (arrSort[mid] == dicari){
                           cout << "Angka "<< arrSort[mid] << " berhasil ditemukan" << endl;
                            flag = false;
                        }if (low > high ){
                           cout << endl << "Not found" << endl;
                            flag = false;
                        }
                    }
                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                    cout << endl;
                    cout << "0. Back" << endl;
                    cout << "Binary Search took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Binary Search", UseNumber);
                    do {
                        cout << ">> ";
                        cin >> backMenu;
                    } while (backMenu < 0 || backMenu > 0);
                } while (backMenu != 0);
                system("cls");
            break;
            }
            case 5:{
                do {

                    cout << "Interpolation Search: " << endl;
                    low = 0;
                    high = length-1;
                    flag = true;

                    cout << endl << "Masukkan angka yang mau dicari: ";
                    cin >> dicari;

                    clock_t start_time = clock();
                    while (flag){


                        mid = low + ((dicari - arrSort[low]) * (high - low) /(arrSort[high] - arrSort[low]) );

                        if (arrSort[mid] < dicari){
                            low = mid + 1;
                        }
                        else if (arrSort[mid] > dicari){
                            high = mid - 1;
                        }
                        if (arrSort[mid] == dicari){
                           cout << "Angka "<< arrSort[mid] << " berhasil ditemukan" << endl;
                            flag = false;
                        }if (low > high ){
                           cout << endl << "Not found" << endl;
                            flag = false;
                        }

                    }
                    clock_t end_time = clock();
                    // For Seconds
                    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                    cout << endl;
                    cout << "0. Back" << endl;
                    cout << "Interpolation Search took " << duration << " Seconds" << endl;
                    simpanDurasi(duration, "Interpolation Search", UseNumber);
                    do {
                        cout << ">> ";
                        cin >> backMenu;
                    } while (backMenu < 0 || backMenu > 0);
                } while (backMenu != 0);
                system("cls");
            break;
            }
        }
    } while(menu != 0);
    return 0;
}
