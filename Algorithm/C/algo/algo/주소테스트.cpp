#include <iostream>


int A[5] = { 1,2,3,4,5 };

int num = 1;

using namespace std;

void test(int a[], int n) {
	a[2] = 100;
	n = 5;
}

void test2(int a[], int &n) {
	n = 10;
}

int main() {

	cout << "test �� A[2]�� : " << A[2] << "/  num�� : " << num << "\n";
	test(A, num);

	cout << "test �� A[2]�� : " << A[2]<< "/  num�� : " << num << "\n";
	test2(A, num);
	cout << "test �� A[2]�� : " << &A[2] << "/  num�� : " << num << "\n";

	int* p = &num;
	
	cout << "num�ּ� : " << p << "      num�� : " << *p <<"\n";

	*p = 3;

	cout << "num�ּ� : " << p << "      num�� : " << *p;


	return 0;
}