//#include <iostream>
//#include<string>
//#include<queue>
//using namespace std;
//int T,N;
//int card[1000001];
//
//struct saram {
//	int key, seq, card;
//};
//
//struct cmpkey {
//	bool operator()(saram a, saram b) {
//		if (a.key != b.key)	return a.key > b.key;
//		return a.seq < b.seq; 
//	}
//};
//struct cmpseq {
//	bool operator()(saram a, saram b) {
//		return a.seq > b.seq;
//	}
//};
//saram tem;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		priority_queue<saram, vector<saram>, cmpkey> pq;
//		priority_queue<saram, vector<saram>, cmpseq> pq2;
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//
//			cin >> tem.key;
//			tem.seq = i;
//			pq.push(tem);
//		}
//		for (int i = 0; i < N; i++) {
//
//			cin >> card[i];
//		}
//
//		for (int i = 0; i < N; i++) {
//			tem = pq.top();
//			pq.pop();
//
//			tem.card = N - (i);
//			pq2.push(tem);
//		}
//
//		bool flag =true;
//
//		for (int i = 0; i < N; i++) {
//			tem = pq2.top();
//			pq2.pop();
//
//			if (card[i] != tem.card) {
//				flag = false;
//				break;
//			}
//		}
//
//		if (flag) {
//			cout << "YES\n";
//		}
//		else {
//			cout << "NO\n";
//		}
//
//	}
//
//	
//}

//�� ���һ� �׳� ��ũ�� Ű ǥ���� �ڿ� �տ������� �� ũ�� �ȵȴٰ� ������ָ� ��.