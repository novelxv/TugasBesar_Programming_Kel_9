#include <iostream>
#include <ctime>

using namespace std;

const int rows = 10;
const int elements = 10;

int maxships = 10;

int matrix[rows][elements];

void Clear(int (*matrixPtr)[elements]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < elements; j++){
            *(matrixPtr[i] + j) = 0;
        }
    }
}

void Show(int (*matrixPtr)[elements]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < elements; j++){
            cout << *(matrixPtr[i] + j) << " ";
        }
        cout << endl;
    }
}

int NumberOfShips(int (*matrixPtr)[elements]){
    int c = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < elements; j++){
            if (*(matrixPtr[i] + j) == 1)
                c++;
        }
    }
    return c;
}

void SetShips(int (*matrixPtr)[elements]){
    int s = 0;
    while (s < maxships){
        int x = rand() % rows;
        int y = rand() % elements;
        if (*(matrixPtr[x] + y) != 1){
            s++;
            *(matrixPtr[x] + y) = 1;
        }
    }
}

bool Attack(int x, int y, int (*matrixPtr)[elements]){
    if (*(matrixPtr[x] + y) == 1){
        *(matrixPtr[x] + y) = 2;
        return true;
    }
    return false;
}

int main(){
    srand(time(NULL));
    Clear(matrix);
    SetShips(matrix);
    int pos1, pos2;
    char prompt;
    while (1){
        cout << "Input lokasi yang ingin diserang (X Y): ";
        cin >> pos1 >> pos2;
        if (Attack(pos1, pos2, matrix))
            cout << "Kapal musuh berhasil diserang!" << endl;
        else
            cout << "Tidak ada kapal di lokasi ini." << endl;
        cout << "Kapal musuh yang tersisa: " << NumberOfShips(matrix) << endl;
        cout << "Ingin menyerah (y/n)? ";
        cin >> prompt;
        if (prompt == 'y')
            break;
    }
    cout << "Game Over" << endl;
    Show(matrix);
    system("pause");
    return 0;
}