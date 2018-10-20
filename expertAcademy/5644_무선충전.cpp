#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//������ BC�� �����ϴ� �˰���.
//��Ž.

//������ ����, ����ũ��� 10. ����.
//�� �̵��ð� 20 <= M <=100
// 1<=BC����<=8 , 1<= �������� <=4
// 10 <= BC�� ���� <= 500 
//����� A�� 1,1���� ���� ����� B�� 10,10���� ����.

//���͸���ġ bcInfo�� �� �־����, 
//bcInfo���� �����ŭ ���� ���鼭, ���� �̿밡���� ���͸� �ľ�.
//�� ���� ������ ��ĥ �� ����.

int map[11][11];
struct bc {
	int y, x, range, power;
};
vector<bc> bcInfo; // ���͸������� ��ġ���� ����.

int mY[5] = { 0, -1, 0, 1, 0 }; //�̵�x �� �� �� �� fixed.
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
				//if ����� a�� bcposition[i]�� �̿� �����ϸ�.
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
						//�ִ밪 ����. if(i==j) �̸� ���͸��Ŀ� /=2.
						maxSum = max(maxSum, nowSum);
					}
				}
				else if ((abs(bY - bcInfo[i].y) + abs(bX - bcInfo[i].x)) <= bcInfo[i].range) //a�� �̿� �Ұ��� �ϰ�. b�� �̿� ����.
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