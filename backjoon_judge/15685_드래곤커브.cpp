#include <iostream>
#include <vector>
using namespace std;

/*
풀이 후기
소요시간 약 1시간.
 nextdir = nowDir+1%4 (연산자 우선순위 조심!)
 nextdir = (nowDir+1) %4 연산자 우선순위 문제로 이렇게 묶어주어야 하는데
 첫줄 처럼 구현했다가 디버깅하는데 30분 소요했다.
 */

//알고리즘 구상
//드래곤 커브 마킹해놓고, 쭉 돌면서 숫자 세기.
//100 x 100 맵.
//드래곤커브는 0~10세대, 1~20개.
//d는 시작 방향 0동 1북 2서 3남 fixed. nextdir = nowDir+1%4 (연산자 우선순위 조심!)
//드래곤 커브는 왔던 방향만 기록해놓았다면 각 세대의 마지막 위치에서 그려나갈 수 있다.!

//0세대 시작방향으로 +1 ex)동
//1세대 0세대마지막점에서 +1 ex)북쪽으로
//2세대 동북 서북 //북서세트 동북세트.
//3세대 동북서북 서남서북
//4세대 동북서북 서남서북+ 서남동남

//2세대 드레곤 커브를 만든다->for(3번) 초기에 들어있는 방향으로 이동, 
//0세대, 들어있는 방향으로 이동&& 벡터에 방향 추가,
//1세대, 들어있는 방향+1로 이동 && 벡터에 (방향+1) 추가.
//2세대, 1세대 끝점에서시작. 들어있는 벡터(2개들어있음)에서 하나씩(인덱스 뒤에서부터) 해당방향 +1방향으로가면서 이동 && 벡터에 방향 추가.

int answer = 0;
int map[101][101];
int mY[4] = { 0,-1,0,1 };
int mX[4] = { 1,0,-1,0 };
vector<int> exDir;

void makeCurve(int sX, int sY, int sDir, int generation)
{
	int nowX, nowY, nowDir, exDirSize;
	exDir.clear();
	exDir.push_back(sDir);
	//0세대 생성
	map[sY][sX] = 1;
	nowY = sY + mY[sDir];
	nowX = sX + mX[sDir];
	map[nowY][nowX] = 1;

	//generation 0이면 들어가지 않는다.
	for (int i = 0; i < generation; i++)
	{
		exDirSize = exDir.size();
		for (int j = exDirSize-1; j>=0; j--) //exDir커지기전에 저장한 값을 써야함.
		{
			nowDir = (exDir[j] + 1)% 4;
			nowY = nowY + mY[nowDir];
			nowX = nowX + mX[nowDir];
			map[nowY][nowX] = 1;
			exDir.push_back(nowDir);
		}
	}
}

void squareCnt()
{
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				answer++;
		}
	}
}

int main()
{
	int curveSize, startX,startY, startDir, generation;
	cin >> curveSize;
	for (int i = 0; i < curveSize; i++)
	{
		cin >> startX >> startY >> startDir >> generation;
		makeCurve(startX, startY, startDir, generation);
	}
	squareCnt();

	cout << answer;
}