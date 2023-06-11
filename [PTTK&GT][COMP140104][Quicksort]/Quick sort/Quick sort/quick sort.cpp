#include <iostream>
#include <vector>
using namespace std;
void quicksort(int a[], int left, int right)
{
	int key = a[(left + right) / 2];//tìm khóa để phân mạch
	int l = left; int r = right;
	do {
		while (a[l] < key)//lớn hơn thì dừng lại chuyển qua phải
			l++;
		while (a[r] > key)//bé hơn khóa thì dừng lại
			r--;

		if (l <= r) //left lớn hơn right thì dừng lại
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}

	} while (l <= r);//left lớn hơn right thì dừng lại
	if (left < r)
		quicksort(a, left, r);//sắp xếp đoạn con bên trái
	if (l < right)
		quicksort(a, l, right);//sắp xếp đoạn con bên phải
}
int main() {
	cout << "Thuat toan quicksort" << endl;
	int a[] = { 1 ,3 ,5,5,6,7,8,4 };
	int n = sizeof(a) / sizeof(a[0]);
	quicksort(a, 0, n - 1);
	for(int i = 0; i < n; i++) 
		cout << a[i] << "\t";
	cout << endl;
	system("pause");
	return 0;
}