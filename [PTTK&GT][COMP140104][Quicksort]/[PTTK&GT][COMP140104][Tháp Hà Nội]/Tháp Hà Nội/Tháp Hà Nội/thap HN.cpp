#include<stdio.h>
#include<iostream>
using namespace std;
void ThapHN(int n, char a, char b, char c) {//chuyển n đĩa từ tháp A sang thấp B với tháp trung gian là C
	if (n == 1) {//nếu có 1 đĩa thì chuyển đĩa đó từ A sang B
		printf("\n%c->%c", a, b);
		cout << endl;
		return;
	}
	//để giải bài toán: chuyển n đĩa từ A sang B
	// Thuật toán làm 3 bước
	//1.dùng tháp B làm trung gian chuyển n-1 đĩa sang tháp B
	ThapHN(n - 1, a, c, b);
	//2.chuyển đĩa lớn nhất từ A sang B với c là trung gian
	ThapHN(1, a, b, c);
	//3.chuyển n-1 đĩa từ C sang B với A là trung gian
	ThapHN(n - 1, c, b, a);
}
int main() {
	char a = 'A', b = 'B', c = 'C';
	int Sodia;
	cout << "nhap so dia";
	cin >> Sodia;
	ThapHN(Sodia, a, b, c);
	system("pause");
	return 0;

}
