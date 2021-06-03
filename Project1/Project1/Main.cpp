#include <iostream>
using namespace std;
const int V = 20;
void Algo(int GR[V][V], int st, int fi)
{
	int distance[V], count, index, i, u, a = st + 1, b = fi + 1;
	bool visited[V];
	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX && distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Cost of the way from A to B:\t\n";
    if (distance[fi] != INT_MAX && st <= V - 1 && fi <= V - 1)
		cout << a << " -> " << b << " = " << distance[fi] << endl;
	else cout << "This route is not available..." << endl;
}

void main()
{
	int start, finish, GR[V][V], MAIN[38][3] = {
	{1,	2,	2000},
	{1,	5,	2800},
	{2,	3,	2500},
	{2,	4,	2600},
	{2,	5,	3000},
	{3,	4,	2100},
	{3,	6,	2000},
	{4,	6,	2600},
	{4,	7,	2200},
	{5,	7,	1900},
	{6,	7,	1800},
	{6,	8,	2100},
	{7,	3,	2300},
	{7,	9,	2700},
	{7,	10,	2400},
	{7,	11,	2200},
	{8,	12,	1900},
	{9,	12,	1800},
	{11, 12, 2500},
	{11, 13, 2800},
	{11, 14, 2600},
	{11, 15, 2300},
	{12, 15, 2200},
	{12, 17, 2100},
	{13, 10, 2000},
	{13, 14, 2400},
	{13, 20, 1800},
	{14, 15, 1900},
	{14, 19, 2100},
	{14, 20, 2200},
	{15, 16, 2600},
	{15, 18, 2700},
	{15, 19, 2700},
	{16, 17, 2900},
	{16, 18, 2000},
	{17, 18, 2200},
	{18, 19, 2100},
	{19, 20, 2500} };

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			GR[i][j] = 0;
	for (int i = 0; i < 38; i++)
	{
		int a = MAIN[i][0];
		int b = MAIN[i][1];
		int c = MAIN[i][2];
		GR[a - 1][b - 1] = c;
		GR[b - 1][a - 1] = c;
	}

	/*for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			cout << GR[i][j] << " ";
		cout << endl;
	}*/

	cout << "Start point... "; 
	cin >> start;
	cout << "Finish point... ";
	cin >> finish;
	Algo(GR, start - 1, finish - 1);
	system("pause>>void");
}