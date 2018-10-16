#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

bool isVisit[1001];
vector <int> edge[1001];


void dfs(int start)
{
	cout << start << " ";
	isVisit[start] = true;
	for (int i = 0; i < edge[start].size(); i++)
	{
		if (!isVisit[edge[start][i]])
		{
			dfs(edge[start][i]);
		}
	}
}
	
void bfs(int start)
{
	queue<int>searchQueue;
	searchQueue.push(start);
	isVisit[start] = true;
	int tempSearchNode;

	while (!searchQueue.empty())
	{
		tempSearchNode = searchQueue.front();
		cout << tempSearchNode << " ";
		searchQueue.pop();
		for (int i = 0; i < edge[tempSearchNode].size(); i++)
		{
			if (!isVisit[edge[tempSearchNode][i]])
			{
				searchQueue.push(edge[tempSearchNode][i]);
				isVisit[edge[tempSearchNode][i]] = true;
			}
		}
	}
}


int main()
{
	//initialization
	int nodeSize, edgeSize, startNode;
	scanf("%d %d %d", &nodeSize, &edgeSize, &startNode);
	int edge_startNode, edge_endNode;
	for (int i = 0; i < edgeSize; i++)
	{
		scanf("%d %d", &edge_startNode, &edge_endNode);
		edge[edge_startNode].push_back(edge_endNode);
		edge[edge_endNode].push_back(edge_startNode);
	}

	for(int i=1; i<=nodeSize; i++)
	sort(edge[i].begin(), edge[i].end());

	//dfs
	dfs(startNode);
	memset(isVisit, 0, sizeof(isVisit));

	printf("\n");
	//bfs
	bfs(startNode);
	return 0;
}