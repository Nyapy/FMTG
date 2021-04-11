//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//struct Point {
//	int x, y;
//};
//
//ll dist(Point a, Point b)
//{
//	return (ll)(a.x - b.x) * (a.x - b.x) + (ll)(a.y - b.y) * (a.y - b.y);
//}
//
//int ccw(Point p1, Point p2, Point p3)
//{
//	//���� ������ ���� : Xa*Yb - Ya*Xb 
//	// p1�� ���������ϴ� �������ͷ� ��ȯ�Ͽ� ���� �Ŀ� ��� 
//	ll ret = (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p2.y - p1.y) * (p3.x - p1.x);
//	if (ret > 0) return 1;
//	else if (ret < 0) return -1;
//	else return 0;
//}
//
//int n, top;
//Point data[100001], st[100001], p0;
//
////���� ���� : �������� �������� �� ���� ccw�ؼ� �ð���⿡ �ִ� ���� �켱������ ����.
////           ccw��� ���� 0�� ��� ������ ����� �� �켱.
//bool compare(const Point A, const Point B)
//{
//	int t = ccw(p0, A, B);
//	if (t == 0)
//	{
//		ll dist1 = dist(p0, A);
//		ll dist2 = dist(p0, B);
//		return dist1 < dist2;
//	}
//	return t > 0;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	p0.y = p0.x = 40001;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d %d", &data[i].x, &data[i].y);
//		if (p0.y > data[i].y) p0 = data[i];
//		if (p0.y == data[i].y && p0.x > data[i].x) p0 = data[i];
//	}
//
//	//������
//	sort(data + 1, data + n + 1, compare);
//
//	for (int i = 1; i <= n; i++)
//	{
//		while (top > 1 && ccw(st[top - 1], st[top], data[i]) <= 0)top--;
//
//		st[++top] = data[i];
//	}
//
//	printf("%d", top);
//
//	return 0;
//}