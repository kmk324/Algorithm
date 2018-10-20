#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//최적의 BC를 선택하는 알고리즘.
//완탐.

//지도의 가로, 세로크기는 10. 고정.
//총 이동시간 20 <= M <=100
// 1<=BC개수<=8 , 1<= 충전범위 <=4
// 10 <= BC의 성능 <= 500 
//사용자 A는 1,1에서 시작 사용자 B는 10,10에서 시작.

//배터리위치 bcInfo에 쭉 넣어놓고, 
//bcInfo벡터 사이즈만큼 루프 돌면서, 현재 이용가능한 배터리 파악.
//두 명의 영역이 겹칠 때 주의.

int map[11][11];
struct bc {
	int y, x, range, power;
};
vector<bc> bcInfo; // 배터리충전기 위치정보 벡터.

int mY[5] = { 0, -1, 0, 1, 0 }; //이동x 상 우 하 좌 fixed.
int mX[5] = { 0, 0, 1, 0, -1 };

int main()
{
	int answer;
	int test_case;
	int TcSize;
	cin >> TcSize;

	int moveSize, batterySize;
	vector<int> moveInfoA;
	vector<int> moveInfoB;
	for (int test_case = 1; test_case <= TcSize; ++test_case)
	{
		//init.
		answer = 0;
		moveInfoA.clear();
		moveInfoB.clear();
		bcInfo.clear();
		int aY = 1;
		int aX = 1;
		int bY = 10;
		int bX = 10;
		int moveInfo;
		int bcY, bcX, bcRange, bcPower;
		cin >> moveSize >> batterySize;
		for (int i = 0; i < moveSize; i++)
		{
			cin >> moveInfo;
			moveInfoA.push_back(moveInfo);
		}
		for (int i = 0; i < moveSize; i++)
		{
			cin >> moveInfo;
			moveInfoB.push_back(moveInfo);
		}
		for (int i = 0; i < batterySize; i++)
		{
			cin >> bcX >> bcY >> bcRange>> bcPower;
			bcInfo.push_back({bcY, bcX, bcRange, bcPower});
		}

		//solve
		int maxSum, nowSum;
		for (int m = 0; m <= moveSize; m++)
		{
			maxSum = 0;
			nowSum = 0;
			for (int i = 0; i < bcInfo.size(); i++)
			{
				//if 사용자 a가 bcposition[i]를 이용 가능하면.
				if ((abs(aY - bcInfo[i].y) + abs(aX - bcInfo[i].x)) <= bcInfo[i].range)
				{
					nowSum = bcInfo[i].power;
					for (int j = 0; j < bcInfo.size(); j++)
					{
						if ((abs(bY - bcInfo[j].y) + abs(bX - bcInfo[j].x)) <= bcInfo[j].range)
						{
							if (i == j)
							{
								nowSum = (bcInfo[i].power);
							}
							else {
								nowSum = bcInfo[i].power + bcInfo[j].power;
							}
						}
						//최대값 갱신. if(i==j) 이면 배터리파워 /=2.
						maxSum = max(maxSum, nowSum);
					}
				}
				else if ((abs(bY - bcInfo[i].y) + abs(bX - bcInfo[i].x)) <= bcInfo[i].range) //a는 이용 불가능 하고. b만 이용 가능.
				{
					nowSum = bcInfo[i].power;
					maxSum = max(maxSum, nowSum);
				}
			}
			answer += maxSum;
			if (m != moveSize)
			{
				aY += mY[moveInfoA[m]];
				aX += mX[moveInfoA[m]];
				bY += mY[moveInfoB[m]];
				bX += mX[moveInfoB[m]];
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}