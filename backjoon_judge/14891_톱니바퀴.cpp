#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//��Ϲ��� �� 4��.
//�Է� ��Ϲ����� s��n������. 1/0
//��Ϲ����� ȸ�� �� rollSize. 1~100
//��� ��Ϲ��� ����������� ȸ������ �־���. 1->�ð���� -1 ->�� �ð����. 
//������Ȳ�� ���� ����Ͽ� ���.
//1�� 12��(0�ε���������) N(0)�̸�0�� S(1) 1��
//2 '' 0�� 2��.
//3 '' 0�� 4��.
//4 '' 0�� 8��.

vector<int> gear[4]; //1234 -> 0123
int sum = 0;
int copyGear[8];

void copy(int gearNum)
{
	for (int i = 0; i < 8; i++)
		copyGear[i] = gear[gearNum][i];
}

void roll(int gearNum, int clockWise)
{
	copy(gearNum);

	if (clockWise==1) //�ð�����̸�.
	{
		gear[gearNum][0] = copyGear[7];
		for (int i = 1; i < 8; i++)
		{
			gear[gearNum][i] = copyGear[i - 1];
		}
	}
	else {
		gear[gearNum][7] = copyGear[0]; //0=1 1=2 5=6 6=7
		for (int i = 0; i < 7; i++)
		{
			gear[gearNum][i] = copyGear[i + 1];
		}
	}
}

void solve(int gearNum, int clockWise)
{
	//������ ���� ��Ȳ Ȯ��.  //0�ƴϸ� 1Ʋ��.
	if (gearNum == 0)
	{
		//1������� 6�� Ȯ�� 0������� 2�� �ٸ� ���̸�-> 1�� -clockwise�� ȸ��.
		if (gear[0][2] != gear[1][6])
		{
			roll(0, clockWise);
			if (gear[1][2] != gear[2][6])
			{
				roll(1, -clockWise);
				if(gear[2][2] !=gear[3][6])
				{
					roll(2, clockWise);
					roll(3, -clockWise);
				}
				else {
					roll(2, clockWise);
				}
			}
			else {
				roll(1, -clockWise);
			}
		}
		else {
			roll(0, clockWise);
		}
	}
	else if (gearNum == 1)//0 2 ��.
	{
		if (gear[1][6] != gear[0][2] || gear[1][2] != gear[2][6])
		{
			if (gear[1][6] != gear[0][2] && gear[1][2] != gear[2][6])
			{
				roll(0, -clockWise);
				roll(1, clockWise);
				if (gear[2][2] != gear[3][6])
				{
					roll(2, -clockWise);
					roll(3, clockWise);
				}
				else {
					roll(2, -clockWise);
				}
			}
			else if (gear[1][6] != gear[0][2] && gear[1][2] == gear[2][6])
			{
				roll(0, -clockWise);
				roll(1, clockWise);
			}
			else { //gear[1][2] != gear[2][6] && gear[1][6] == gear[0][2]
				roll(1, clockWise);
				if (gear[2][2] != gear[3][6])
				{
					roll(2, -clockWise);
					roll(3,  clockWise);
				}
				else {
					roll(2, -clockWise);
				}
			}
		}
		else {
			roll(1, clockWise);
		}
	}
	else if (gearNum == 2)
	{
		if (gear[2][2] != gear[3][6] || gear[1][2] != gear[2][6])
		{
			if (gear[2][2] != gear[3][6] && gear[1][2] != gear[2][6])
			{
				roll(3, -clockWise);
				roll(2, clockWise);
				if (gear[0][2] != gear[1][6])
				{
					roll(0, clockWise);
					roll(1, -clockWise);
				}
				else {
					roll(1, -clockWise);
				}
			}
			else if (gear[2][2] != gear[3][6] && gear[1][2] == gear[2][6])
			{
				roll(3, -clockWise);
				roll(2, clockWise);
			}
			else { //gear[1][2] != gear[2][6] && gear[2][2] == gear[3][6]
				roll(2, clockWise);
				if (gear[0][2] != gear[1][6])
				{
					roll(1, -clockWise);
					roll(0, clockWise);
				}
				else {
					roll(1, -clockWise);
				}
			}
		}
		else {
			roll(2, clockWise);
		}
	}
	else {//gear3
		if (gear[3][6] != gear[2][2])
		{
			roll(3, clockWise);
			if (gear[2][6] != gear[1][2])
			{
				roll(2, -clockWise);
				if (gear[1][6] != gear[0][2])
				{
					roll(1, clockWise);
					roll(0, -clockWise);
				}
				else {
					roll(1, clockWise);
				}
			}
			else {
				roll(2, -clockWise);
			}
		}
		else {
			roll(3, clockWise);
		}
	}
}


void answerCalc()
{
	for (int i = 0; i < 4; i++)
	{
		if(gear[i][0] ==1)
			sum += pow(2 , i);
	}
}

int main()
{
	int gearState;
	int clockSize;
	int gearNum, clockWise;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &gearState);
			gear[i].push_back(gearState);
		}
	}
	cin >> clockSize;
	for (int i = 0; i < clockSize; i++)
	{
		cin >> gearNum >> clockWise;
		solve(gearNum-1, clockWise);
	}

	answerCalc();
	cout << sum;
}