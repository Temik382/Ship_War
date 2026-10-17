#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// MAIN

int main() {
    // 65001 — это кодовая страница UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    const int SIZE = 6; 
    const int SHIP = 3;
    char letters[] = { '1', '2', '3', '4', '5', '6' };


    char my_board[SIZE][SIZE];
    memset(my_board, '~', sizeof(my_board));
    for (int i = 0; i < SHIP; ++i) {
        int x_m, y_m;
        cout << "Введите расположение вашего корабля по горизонтали: ";
        cin >> x_m;
        cout << "Введите расположение вашего корабля по горизонтали: ";
        cin >> y_m;
        my_board[x_m][y_m] = 'S';
    }

    cout << "Отлично, вы расставили корабли!" << endl << "Начинаем играть!" << endl;

    char computer_board[SIZE][SIZE];
    memset(computer_board, '~', sizeof(computer_board));
    char secret_computer_board[SIZE][SIZE];
    memset(secret_computer_board, '~', sizeof(computer_board));
    for (int i = 0; i < SHIP; ++i) {
        secret_computer_board[rand() % 6][rand() % 6] = 'S';
    }

    int count_ship = 3;
    int count_my_ship = 3;

    while (count_ship > 0 && count_my_ship > 0)
    {
        cout << "  ВАШЕ ПОЛЕ  \t\t  ПОЛЕ ВРАГА\n";
        cout << "  1 2 3 4 5 6  \t\t  1 2 3 4 5 6\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << letters[i] << " ";
            for (int j = 0; j < SIZE; ++j) {
                cout << my_board[i][j] << " ";
            }

            cout << "\t\t" << letters[i] << " ";
            for (int k = 0; k < SIZE; ++k) {
                cout << computer_board[i][k] << " ";
            }
            cout << "\n";
        }

        int X, Y;
        cout << "Введите цифру по горизонтали: ";
        cin >> X;
        cout << "\nВведите цифру по вертикали: ";
        cin >> Y;
        if (X < 1 || X > SIZE || Y < 1 || Y > SIZE) {
            cout << "Координаты вне поля! Нажмите Enter для повтора...";
            cin.ignore();
            cin.get();
            continue;
        }
        int x = X - 1;
        int y = Y - 1;

        if (secret_computer_board[x][y] == 'S') {
            cout << "Попадание!\n";
            computer_board[y][x] = 'X';
            secret_computer_board[x][y] = 'X';
            count_ship--;
        }
        else {
            cout << "Промах\n";
            computer_board[y][x] = '*';
            secret_computer_board[x][y] = '*';
        }

        int x_c = rand() % 6;
        int y_c = rand() % 6;

        if (my_board[y_c][x_c] == 'S') {
            cout << "Твой корабль убили!\n";
            my_board[y_c][x_c] = 'X';
            count_my_ship--;
        }
        else {
            cout << "Компьютер промахнулся" << endl;
            my_board[y_c][x_c] = '*';
        }


    }

    if (count_ship == 0) {
        cout << "Ура, вы победили\n";
        cout << "  ВАШЕ ПОЛЕ  \t\t  ПОЛЕ ВРАГА\n";
        cout << "  1 2 3 4 5 6  \t\t  1 2 3 4 5 6\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << letters[i] << " ";
            for (int j = 0; j < SIZE; ++j) {
                cout << my_board[i][j] << " ";
            }

            cout << "\t\t" << letters[i] << " ";
            for (int k = 0; k < SIZE; ++k) {
                cout << computer_board[i][k] << " ";
            }
            cout << "\n";
        }
    }

    if (count_my_ship == 0) {
        cout << "К сожалению, вы проиграли\n";
        cout << "  ВАШЕ ПОЛЕ  \t\t  ПОЛЕ ВРАГА\n";
        cout << "  1 2 3 4 5 6  \t\t  1 2 3 4 5 6\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << letters[i] << " ";
            for (int j = 0; j < SIZE; ++j) {
                cout << my_board[i][j] << " ";
            }

            cout << "\t\t" << letters[i] << " ";
            for (int k = 0; k < SIZE; ++k) {
                cout << computer_board[i][k] << " ";
            }
            cout << "\n";
        }
    }


    return 0;
}