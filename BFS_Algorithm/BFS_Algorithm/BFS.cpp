// �׷��� Ž�� - �ʺ� �켱 Ž��(BFS: Breadth First Search)
// ���� �������� ������ ��带 ���� �湮�ϰ� �ָ� ������ �ִ� ������ ���߿� �湮
// ��� ��带 Ž���ϴ� �ͺ��� �ּ� ���, �ִ� ���, ������ ��θ� ã�ƾ� �ϴ� ��쿡 ���
// ť(Queue) �� �̿��Ͽ� ����
// 1. ���� ��带 Queue�� �����ϰ� visit[����] = true �� �湮 ó��
// 2. Queue�� front�� ���� ��� ������ �����ϰ� pop()
// 3. Queue�� ���� ��忡 �湮���� ���� ���� ��尡 �ִٸ� Queue�� �����ϰ� �湮 ó��
// 4. Queue�� �� ������ �ݺ�

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 1000

using namespace std;

vector <int> graph[MAX_SIZE];
bool visit[MAX_SIZE]; // �������� �����ϸ� false�� �ڵ� �ʱ�ȭ

void bfs(int start) {
	queue<int> q;

	q.push(start); // Queue�� ���� ��� �����ϰ�
	visit[start] = true; // �湮 ó��

	while (!q.empty()) { // ���� Queue�� ��尡 �ִٸ�
		int now = q.front(); // front�� ���� ��� ������ ����
		q.pop(); // Queue���� ����
		cout << now << " ";

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!visit[next]) { // �湮���� ���� �����
				q.push(graph[now][i]); // Queue�� ����
				visit[next] = true; // �湮 ó��
			}
		}
	}

}

int main() {
	int v, e, start;

	cout << "How many vertex?\n";
	cin >> v;

	cout << "How many edge?\n";
	cin >> e;

	cout << "Enter the start node\n";
	cin >> start;

	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	bfs(start);

	return 0;
}