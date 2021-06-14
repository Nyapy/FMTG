#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int T, N, a, b, center;
int find_center[300001];
int cost[300001];
vector<int> route[300001];

struct gaji {
	int mcost;
	vector<int> node;
	int total;
};

struct qs {
	int c, num, depth;
};

gaji branch[3];
bool visited[300001];

long long answer, center_total, tem_answer, plus_v, minus_v;

void bfs() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	queue<qs> q;
	visited[center] = true;

	for (int i = 0; i < 3; i++) {
		q.push({ i,route[center][i],1 });
		visited[route[center][i]] = true;

	}
	while (!q.empty()) {
		qs tq = q.front();
		q.pop();
		branch[tq.c].node.push_back(tq.num);
		branch[tq.c].mcost += cost[tq.num];
		branch[tq.c].total += (cost[tq.num] * tq.depth);

		for (int i = 0; i < route[tq.num].size(); i++) {
			if (!visited[route[tq.num][i]]) {
				visited[route[tq.num][i]] = true;
				q.push({ tq.c, route[tq.num][i] , tq.depth+1 });

			}
		}
	}

}

int main() {
	
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			find_center[i] = 0;
			route[i] = vector<int>();
		}
		for (int i = 0; i < 3; i++) {
			branch[i].node = vector<int>();
			branch[i].mcost = 0;
			branch[i].total = 0;

		}

		//�Է� �����鼭 ��� ����
		for(int i= 0; i<N-1; i++){
			cin >> a >> b;
			route[a].push_back(b);
			route[b].push_back(a);
			find_center[a]++;
			find_center[b]++;
		}
		// �߽� ��� ã��
		for (int i = 1; i <= N; i++) {
			if (find_center[i] == 3) {
				center = i;
				break;
			}
		}
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}

		//bfs ������ �� ���� �� (�������(node), ����� �̵���� ��(mcost), �߽����� ������ �� �̵���� ��(total) )�� ����
		bfs();

		center_total = 0;
		//�߽ɿ��� �������� �� �̵������ ���� ����
		for (int i = 0; i <3; i++) {
			center_total += branch[i].total;
		}

		//������ �ʱⰪ�� ���Ϳ����� �� �̵����.
		answer = center_total;


		for (int i = 0; i < 3; i++) {
			tem_answer = answer;
			//�ʱⰪ
			// Plus value = Ž���Ϸ��� ���� ���� 2�� ������ ������ �̵���� �� + �߽ɳ���� �̵����
			// Minus value = Ž���ϴ� ������ ������ �̵������ ��
			if (i == 0) {
				plus_v = branch[1].mcost + branch[2].mcost+ cost[center];
			}
			else if (i == 1) {
				plus_v = branch[0].mcost + branch[2].mcost+ cost[center];
			}
			else {
				plus_v = branch[0].mcost + branch[1].mcost+ cost[center];
			}
			minus_v = branch[i].mcost;

			for (int j = 0; j < branch[i].node.size(); j++) {
				//������ �� ĭ�� �Ž��� ���� ���� ����� ���� �÷��� ��ҿ� ���̳ʽ� ��Ҹ� ��� ���ذ��� ���� ���Ѵ�.
				tem_answer += (plus_v - minus_v);

				//���� ���� �Ѿ���� ���� ���س���� �ڽ�Ʈ��ŭ plus���� �������� minus���� ����.
				minus_v -= cost[branch[i].node[j]];
				plus_v += cost[branch[i].node[j]];

				//���� ��忡���� �� ����� ���� ����� ������ ������ ����.
				if (tem_answer < answer) {
					answer = tem_answer;
				}
			}
		}

		cout << '#' << tc << " " << answer << '\n';
	}

}