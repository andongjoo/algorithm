#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;

int N, L;
int result; //���, ���������� �����ϸ� 0
int arr[MAX][MAX];
bool visited[MAX];

//�� Ȯ��
void checkRow(int y)
{
	int cur = arr[y][0];
	for (int i = 0; i < N; i++)
	{
		if (arr[y][i] != cur)
		{
			//���� ���� X
			if (!(abs(arr[y][i] - cur) <= 1))
				return;

			//��������
			if (arr[y][i] < cur)
			{
				int height = -1;
				for (int j = i; j < i + L; j++)
				{
					//���ΰ� ��ġ�� �ȵǰ� ���� ����
					if (!visited[j] && j < N)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[y][j];
							continue;
						}

						//L ���̸�ŭ ���� ���̰� �ƴ϶�� ���� ���� X
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
			//��������
			else
			{
				int height = -1;
				for (int j = i - 1; j > i - 1 - L; j--)
				{
					//���ΰ� ��ġ�� �ȵǰ� ���� ����
					if (!visited[j] && j >= 0)
					{
						visited[j] = true;

						if (height == -1)
						{
							height = arr[y][j];
							continue;
						}

						//L ���̸�ŭ ���� ���̰� �ƴ϶�� ���� ���� X
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

//�� Ȯ��
void checkCol(int x)
{
	int cur = arr[0][x];
	for (int i = 0; i < N; i++)
	{
		if (arr[i][x] != cur)
		{
			//���� ���� X
			if (!(abs(arr[i][x] - cur) <= 1))
				return;

			//��������
			if (arr[i][x] < cur)
			{
				int height = -1;
				for (int j = i; j < i + L; j++)
				{
					//���ΰ� ��ġ�� �ȵǰ� ���� ����
					if (!visited[j] && j < N)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[j][x];
							continue;
						}

						//L ���̸�ŭ ���� ���̰� �ƴ϶�� ���� ���� X
						if (height != -1 && arr[j][x] != height)
							return;
					}
					else
						return;
				}

				//L ���̸�ŭ �����̹Ƿ�
				i += L - 1;
				//���� ����
				if (i >= N)
					break;
			}
			//��������
			else
			{
				int height = -1;
				for (int j = i - 1; j > i - 1 - L; j--)
				{
					//���ΰ� ��ġ�� �ȵǰ� ���� ���� 
					if (!visited[j] && j >= 0)
					{
						visited[j] = true;

						if (height == -1)
						{
							height = arr[j][x];
							continue;
						}

						//L ���̸�ŭ ���� ���̰� �ƴ϶�� ���� ���� X
						if (height != -1 && arr[j][x] != height)
							return;
					}
					else
						return;
				}
			}
			//���� ĭ Ȯ��
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
