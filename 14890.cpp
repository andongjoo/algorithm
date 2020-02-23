#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;

int N, L;
int result; //결과, 전역변수로 선언하면 0
int arr[MAX][MAX];
bool visited[MAX];

//열 확인
void checkRow(int y)
{
	int cur = arr[y][0];
	for (int i = 0; i < N; i++)
	{
		if (arr[y][i] != cur)
		{
			//조건 충족 X
			if (!(abs(arr[y][i] - cur) <= 1))
				return;

			//내리막길
			if (arr[y][i] < cur)
			{
				int height = -1;
				for (int j = i; j < i + L; j++)
				{
					//경사로가 겹치면 안되고 범위 내에
					if (!visited[j] && j < N)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[y][j];
							continue;
						}

						//L 길이만큼 같은 높이가 아니라면 조건 충족 X
						if (height != -1 && arr[y][j] != height)
							return;
					}
					else
						return;
				}

				i += L - 1;
				if (i >= N)
					break;
			}
			//오르막길
			else
			{
				int height = -1;
				for (int j = i - 1; j > i - 1 - L; j--)
				{
					//경사로가 겹치면 안되고 범위 내에
					if (!visited[j] && j >= 0)
					{
						visited[j] = true;

						if (height == -1)
						{
							height = arr[y][j];
							continue;
						}

						//L 길이만큼 같은 높이가 아니라면 조건 충족 X
						if (height != -1 && arr[y][j] != height)
							return;
					}
					else
						return;
				}
			}
			cur = arr[y][i];
		}
	}
	result++;
}

//행 확인
void checkCol(int x)
{
	int cur = arr[0][x];
	for (int i = 0; i < N; i++)
	{
		if (arr[i][x] != cur)
		{
			//조건 충족 X
			if (!(abs(arr[i][x] - cur) <= 1))
				return;

			//내리막길
			if (arr[i][x] < cur)
			{
				int height = -1;
				for (int j = i; j < i + L; j++)
				{
					//경사로가 겹치면 안되고 범위 내에
					if (!visited[j] && j < N)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[j][x];
							continue;
						}

						//L 길이만큼 같은 높이가 아니라면 조건 충족 X
						if (height != -1 && arr[j][x] != height)
							return;
					}
					else
						return;
				}

				//L 길이만큼 경사로이므로
				i += L - 1;
				//조건 충족
				if (i >= N)
					break;
			}
			//오르막길
			else
			{
				int height = -1;
				for (int j = i - 1; j > i - 1 - L; j--)
				{
					//경사로가 겹치면 안되고 범위 내에 
					if (!visited[j] && j >= 0)
					{
						visited[j] = true;

						if (height == -1)
						{
							height = arr[j][x];
							continue;
						}

						//L 길이만큼 같은 높이가 아니라면 조건 충족 X
						if (height != -1 && arr[j][x] != height)
							return;
					}
					else
						return;
				}
			}
			//다음 칸 확인
			cur = arr[i][x];
		}
	}
	result++;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
	{
		memset(visited, false, sizeof(visited));
		checkRow(i);
	}
	
	for (int i = 0; i < N; i++)
	{
		memset(visited, false, sizeof(visited));
		checkCol(i);
	}

	cout << result << "\n";
	return 0;
}
