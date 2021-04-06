#include<iostream>

int A[11] = { 1, 5, 5, 6, 9, 11, 12, 13, 15, 16, 20 };

using namespace std;

int lower_bound(int find) {
	// �� ���� ã������ �ٷ� ���ߴ� ���� �ƴ� �� ���� �� ���� ���� ��ġ�� �����ϴ� ���� �ٽ�.
	// �� ���� ���̸� �� �ε����� ��.
	int low = 0;
	int high = 11;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;

		if (find <= A[mid]) {
			high = mid;
		}
		else if (find > A[mid]) {
			low = mid + 1;
		}
	}

	return low;
}

int upper_bound(int find) {
	// �� ���� ã������ �ٷ� ���ߴ� ���� �ƴ� �� ���� �� ���� ū ��ġ�� �����ϴ� ���� �ٽ�.
	int low = 0;
	int high = 11;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;

		if (find < A[mid]) {
			high = mid;
		}
		else if (find >= A[mid]) {
			low = mid + 1;
		}
	}
	return low;

}

int main() {

	int S = 20;
	cout << S << "�� �� ���� : " << lower_bound(S) << "\n";
	cout << S << "�� �� ���� : " << upper_bound(S) << "\n";

	return 0;
}