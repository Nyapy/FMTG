#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int T,N, M, A, B, C, K, t;

struct node {
	int city, dis, type;
	//����ȣ, �ּҰŸ�, Ÿ��
};

struct go {
	int city, dis, type, from, len;
	//����ȣ, �ּҰŸ�, Ÿ��, �������, �����Ÿ�
};

struct cmp {
	bool operator()(go left, go right) {
		return left.dis > right.dis;
	}
};

int money[11]; //������
long long ans;

int D[20001];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;


		vector<node> path[20001]; //���۷� ���� ����
		vector<pair<int, int>> root[20001]; //��� ����

		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C >> t;
			path[A].push_back({ B, C, t });
		}
		for (int i = 1; i <= K; i++) {
			cin >> money[i];
		}

		//���ͽ�Ʈ��
		for (int i = 1; i <= N; i++) {
			D[i] = 20000001;
		}
		priority_queue<go, vector<go>, cmp> pq;
		pq.push({ 1,0,0,0,0 });
		D[1] = 0;

		while (!pq.empty()) {
			int city = pq.top().city, dist = pq.top().dis, type = pq.top().type, from = pq.top().from, len= pq.top().len;
			pq.pop();

			if (D[city] >= dist) {
				
				D[city] = dist;
				root[city].push_back(make_pair(from, len * money[type])); //root�� (���� ���, �Ÿ�*���) ����

				for (int j = 0; j < path[city].size(); j++) {
					int tem_city = path[city][j].city;
					int tem_dist = path[city][j].dis;
					int tem_type = path[city][j].type;
					if (D[tem_city] >= tem_dist + dist) {
						pq.push({ tem_city, tem_dist + dist, tem_type, city, tem_dist });
					}
				}
			}
		}

		// ����� ��� ���󰡸鼭 �信 ���ϱ�.(bfs�� �������� 1������ ���ã���鼭 ����)
		bool visited[20001];

		ans = 0;
		queue<int> q;
		q.push(N);
		while (!q.empty()) {
			int t = q.front();
			q.pop();

			for (int j = 0; j < root[t].size(); j++) {
				ans += root[t][j].second;
				if (visited[root[t][j].first]) continue;
				q.push(visited[root[t][j].first]);
				visited[root[t][j].first] = true;

			}
		}

		cout << '#' << tc << ' ' << ans << '\n';

	}
	return 0;
}