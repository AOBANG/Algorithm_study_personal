// �ϳ��� ���� �������κ��� ��� �ٸ� ���������� <�ִ� ���>�� ã�� �˰���
// ���� �ƴ� ���� �׷��������� ���� ��, ���� ���, ���� ���� �ִ� ��� ����
// 1. dist �迭 INF�� �ʱ�ȭ
// 2. ������ �Է� �ް�, dist[������]=0, visit[������]=true �� ���� (Ž�� ���)
//		������ �Է� �ް�, dist[������]=0, pq�� {0, ������} ���� (�켱���� ť ���)
// 3. dist �迭���� �ּ� ��� ������ ã�� visit ó��, �̹� �湮�� ���� ����. (Ž�� ���)
//		pq.empty() �� ������ (�켱���� ť ���)
//		-> pq.front() = {�Ÿ� ���, ��� �ε���}
//		-> dist[��� �ε���] < �Ÿ� ��� �̸� �̹� üũ�� ����̹Ƿ� �н�
// 4. ���ο� ������ ���� �� �� �ִ� �Ÿ��� ���� �Ÿ����� �۴ٸ� �Ÿ��� ����

#include <iostream>
#include <vector>
#include <queue>
#define INF 99999
#define MAX_SIZE 100

using namespace std;

vector<vector<int>> weight; // ����ġ �׷���
int dist[MAX_SIZE]; // ���� �������κ����� �ִ� �Ÿ�
bool visit[MAX_SIZE]; // �湮�� ���� ǥ��
int v, e, start;

// 1. �켱���� ť ������� �ʰ� ���� Ž���ϴ� ��� (�ð����⵵�� O(V^2))
int getSmallestNode() { // �湮���� ���� ���� �߿��� ���� �ּ� ����� ��� ��ȯ
	int min = INF;
	int index = 0;

	for (int i = 0; i < v; i++) {
		if (!visit[i]) { // �湮���� �ʾҰ�
			if (dist[i] < min) { // ���� ���� �� ���ϱ�
				min = dist[i];
				index = i;
			}
		}
	}

	return index;
}

void dijkstra1(int start) {
	for (int i = 0; i < v; i++) {
		dist[i] = weight[start][i]; // ���������� ��� ���������� �ִܰŸ� �ʱⰪ ����
	}
	dist[start] = 0;
	visit[start] = true;

	for (int i = 0; i < v - 1; i++) { // �������� ������ ��� ���� �湮
		int now = getSmallestNode();
		visit[now] = true;

		for (int j = 0; j < v; j++) {
			if (!visit[j]) { // �湮���� �ʾҰ�
				int cost = dist[now] + weight[now][j];
				if (cost < dist[j]) dist[j] = cost; // ���ο� ������ ���İ��� �� �� ������ �� ����
			}
		}
	}

}

// 2. �켱���� ť(�ּ� ��)�� ����ϴ� ��� (�ð����⵵�� O(ElogE)) -> �� ����
//		�켱���� ť�� ����Ʈ�� �������� �����̱� ������ �Ÿ� ����� ������ ��ȯ�ؼ� ���� -> �������� ����ó�� ���̰�
void dijkstra2(int start) {
	priority_queue<pair<int, int>> pq; // <�Ÿ�, ���� �ε���>
	pq.push({ 0, start }); // ���� ����� �ִ� �Ÿ� 0���� �����ؼ� ť�� ����
	dist[start] = 0; // ���� ����� dist�� 0���� ����

	while (!pq.empty()) {
		int nowCost = -pq.top().first; // ����� ������ - �ٿ��� ����� ��ȯ�ؼ� ������
		int nowNode = pq.top().second;
		pq.pop();

		if (dist[nowNode] < nowCost) continue; // �̹� üũ�� ����̹Ƿ� �н�

		for (int i = 0; i < weight[nowNode].size(); i++) {
			int cost = nowCost + weight[nowNode][i];
			if (cost < dist[i]) { 
				dist[i] = cost; // ���ο� ������ ���ļ� ���� �� �� ������ �� ����
				pq.push({ -cost, i }); // - �ٿ��� ������ ��ȯ�ؼ� ����
			}
		}
	}
}

int main() {
	cout << "How many vertex?\n";
	cin >> v; // ���� ���� �Է�

	weight.resize(v, vector<int>(v, INF));

	cout << "How many edge?\n";
	cin >> e; // ���� ���� �Է�
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost; // ���� 2���� ���� �Է�(a���� b�� ���� �Ÿ� ��� c)
		weight[from][to] = cost;
	}
	
	fill_n(dist, v, INF); // �ִ� �Ÿ� �迭 INF�� �ʱ�ȭ

	cout << "Start node?\n";
	cin >> start; // ���� ��� �Է�

	//dijkstra1(start);

	dijkstra2(start);

	for (int i = 0; i < v; i++) {
		cout << dist[i] << " ";
	}

	return 0;
}