// �׷��� Ž�� - ���� �켱 Ž��(DFS: depth first search)
// ���� �������� �� �������� ��� ���� ���ٰ� �� �̻� �� �� ���� �Ǹ� �ٽ� ���� ����� ������� �ö�ͼ� �ٸ� �������� �������� Ž�� ����
// ��� ��带 �湮�ؾ� �ϴ� ��쿡 ���
// ����(Stack) �Ǵ� ����Լ��� �̿��Ͽ� ����

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX_SIZE 1000

using namespace std;

vector <int> graph[MAX_SIZE];
bool visit[MAX_SIZE]; // �������� �����ϸ� false�� �ڵ� �ʱ�ȭ

// Stack ���
// 1. ���� ��带 Stack�� �����ϰ� visit[����] = true �� �湮 ó��
// 2. Stack�� �ֻ�� ��� top�� ���� ��� ������ �����ϰ� pop() �ϰ� �湮 ó��
// 3. Stack�� ���� ��忡 �湮���� ���� ���� ��尡 �ִٸ� Stack�� ����
// 4. Stack�� �� ������ �ݺ�
void dfs1(int start) {
	stack<int> st;

	st.push(start); // Stack�� ����
	while (!st.empty()) { // ���� Stack�� ��尡 �ִٸ�
		int now = st.top(); // �ֻ�� ��� ���� ������ ����
		st.pop(); // Stack���� ����

		if (!visit[now]) { // �湮���� ���� �����
			cout << now << " ";
			visit[now] = true; // �湮 ó��

			for (int i = 0; i < graph[now].size(); i++) {
				st.push(graph[now][i]); // ���� ���� Stack�� ����
			}
		}
	}
}

// ����Լ� ���
// 1. ���� ��� �湮 ó��
// 2. ���� ���� ������ ���� �� �湮�� �� ���� ��尡 �ִٸ� ��� ȣ��
void dfs2(int start) {
	visit[start] = true; // �湮 ǥ��
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if(!visit[next]) dfs2(next); // �湮�� �� ���� ����� ��� ȣ��
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

	//dfs1(start);

	dfs2(start);

	return 0;
}