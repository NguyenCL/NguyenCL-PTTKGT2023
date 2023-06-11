#include <iostream>
#include <vector>
using namespace std;

const int n = 9;
vector<vector<int>> board(n, vector<int>(n));
//kiểm tra xem số num có xuất hiện trong hàng row của bảng Sudoku hay không. 
//Nếu có, trả về giá trị false, ngược lại trả về giá trị true.
bool checkRow(int row, int num) {
    for (int j = 0; j < n; ++j) {
        if (board[row][j] == num) {
            return false;
        }
    }
    return true;
}
//kiểm tra xem số num có xuất hiện trong cột col của bảng Sudoku hay không. 
//Nếu có, trả về giá trị false, ngược lại trả về giá trị true
bool checkCol(int col, int num) {
    for (int i = 0; i < n; ++i) {
        if (board[i][col] == num) {
            return false;
        }
    }
    return true;
}
//kiểm tra xem số num có xuất hiện trong ô vuông chứa ô tại vị trí (row, col) hay không. 
//Nếu có, trả về giá trị false, ngược lại trả về giá trị true.
bool checkSquare(int row, int col, int num) {
    int iStart = row - row % 3, jStart = col - col % 3;
    for (int i = iStart; i < iStart + 3; ++i) {
        for (int j = jStart; j < jStart + 3; ++j) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}
bool solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= n; ++num) {
                    if (checkRow(i, num) && checkCol(j, num) && checkSquare(i, j, num)) {
                        board[i][j] = num;
                        if (solve()) {
                            return true;
                        }
                        else {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "nhap ma tran ban dau";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    cout << "ket qua=================="<<endl;
    if (solve()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Khong tim duoc giai phap" << endl;
    }
    return 0;
}
