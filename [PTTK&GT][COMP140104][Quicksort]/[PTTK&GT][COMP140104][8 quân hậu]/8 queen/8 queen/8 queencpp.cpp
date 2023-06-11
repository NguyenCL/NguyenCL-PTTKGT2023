#include <iostream>
using namespace std;
const int SIZE = 8;
int queens[SIZE] = { 0 };
void output() {
	for (int i = 0; i < SIZE; i++) {//duyệt qua cái dòng
		for (int j = 0; j < SIZE; j++) {//duyệt qua cái cột
			if (queens[i] == j)//kiểm tra quân hậu đặt ở vị trí i có trùng với cột j không
				cout << "H\t";
			else
				cout << "0\t";
		}
		cout << endl;
	}
	cout << "ban co muon xem ket qua tiep theo khong (y/n)"; 
	if (getchar() == 'y') {
		cin.ignore(1);
		cout << "=========="<<endl;
	}
	else
		exit(1);
}
bool canPutQueen(int i, int j) {
	for (int k = 0; k < i; k++) {//duyệt tất cả các dòng từ trên tới dòng i
		if (queens[k] == j || abs(k - i) == abs(queens[k] - j))//kiểm tra có quân hậu nào cùng cột không hoặc có nằm trên 1 đường chéo hay không
			return false;
	}
	return true;
}
void putqueen(int index) {
	for (int j = 0; j < SIZE; j++) //tìm ô có khả năng đặt quân hậu
		if (canPutQueen(index, j) == true)//kiểm tra có thể đặt quân hậu không
		{
			queens[index] = j;//nạp quân hậu vào ô j
			if (index == SIZE - 1)//nếu đặt đủ 8 quân hậu thì xuất kết quả
				output();
			else
				putqueen(index + 1);//tiếp tục đặt ở những vị trí tiếp theo
			queens[index] = 0;//reset kết quả
		}
}
int main() {
	putqueen(0);//đặt quân hậu ở dòng đầu tiên
	system("pause");
	return 0;
}