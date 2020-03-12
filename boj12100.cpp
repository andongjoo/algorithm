#include <iostream>

#include <queue>

using namespace std;

 

const int MAX = 20;

 

int N;

int board[MAX][MAX];

int maxBlock;

 

 

void shift(int type)

{

        queue<int> q;

 

        //���ڵ��� ť�� ������� �� ����

        //�ش���� ���������� ���ڸ� �ֱ� ����

        switch (type)

        {

        //����

        case 0:

                 for (int i = 0; i < N; i++)

                 {

                         for (int j = 0; j < N; j++)

                         {

                                 if (board[i][j])

                                          q.push(board[i][j]);

                                 board[i][j] = 0;

                         }

 

                         int idx = 0;

 

                         while (!q.empty())

                         {

                                 int data = q.front();

                                 q.pop();

 

                                 if (board[i][idx] == 0)

                                          board[i][idx] = data;

                                 else if (board[i][idx] == data)

                                 {

                                          board[i][idx] *= 2;

                                          //���߿� �����ִ� ���Ӱ� �޸� ������ �������� �ʴ´�

                                          idx++;

                                 }

                                 else

                                 {

                                          idx++;

                                          board[i][idx] = data;

                                 }

                         }

                 }

                 break;

        //������

        case 1:

                 for (int i = 0; i < N; i++)

                 {

                         for (int j = N - 1; j >= 0; j--)

                         {

                                 if (board[i][j])

                                          q.push(board[i][j]);

                                 board[i][j] = 0;

                         }

 

                         int idx = N - 1;

 

                         while (!q.empty())

                         {

                                 int data = q.front();

                                 q.pop();

 

                                 if (board[i][idx] == 0)

                                          board[i][idx] = data;

                                 else if (board[i][idx] == data)

                                 {

                                          board[i][idx] *= 2;

                                          idx--;

                                 }

                                 else

                                 {

                                          idx--;

                                          board[i][idx] = data;

                                 }

                         }

                 }

                 break;

        //����

        case 2:

                 for (int i = 0; i < N; i++)

                 {

                         for (int j = 0; j < N; j++)

                         {

                                 if (board[j][i])

                                          q.push(board[j][i]);

                                 board[j][i] = 0;

                         }

 

                         int idx = 0;

 

                         while (!q.empty())

                         {

                                 int data = q.front();

                                 q.pop();

 

                                 if (board[idx][i] == 0)

                                          board[idx][i] = data;

                                 else if (board[idx][i] == data)

                                 {

                                          board[idx][i] *= 2;

                                          idx++;

                                 }

                                 else

                                 {

                                          idx++;

                                          board[idx][i] = data;

                                 }

                         }

                 }

                 break;

        //�Ʒ���

        case 3:

                 for (int i = 0; i < N; i++)

                 {

                         for (int j = N - 1; j >= 0; j--)

                         {

                                 if (board[j][i])

                                          q.push(board[j][i]);

                                 board[j][i] = 0;

                         }

 

                         int idx = N - 1;

 

                         while (!q.empty())

                         {

                                 int data = q.front();

                                 q.pop();

 

                                 if (board[idx][i] == 0)

                                          board[idx][i] = data;

                                 else if (board[idx][i] == data)

                                 {

                                          board[idx][i] *= 2;

                                          idx--;

                                 }

                                 else

                                 {

                                          idx--;

                                          board[idx][i] = data;

                                 }

                         }

                 }

                 break;

        }

}

 

void DFS(int cnt)

{

        if (cnt == 5)

        {

                 for (int i = 0; i < N; i++)

                         for (int j = 0; j < N; j++)

                                 maxBlock = max(maxBlock, board[i][j]);

                 return;

        }

 

        int copyBoard[MAX][MAX];

        //�� ������� �����س���

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < N; j++)

                         copyBoard[i][j] = board[i][j];

 

        for (int i = 0; i < 4; i++)

        {

                 shift(i);

                 DFS(cnt + 1);

                 //�����س��� ������·� ���󺹱�

                 for (int i = 0; i < N; i++)

                         for (int j = 0; j < N; j++)

                                 board[i][j] = copyBoard[i][j];

        }

}

 

int main(void)

{

        cin >> N;

 

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < N; j++)

                         cin >> board[i][j];

 

        DFS(0);

        cout << maxBlock << endl;

        return 0;

}

 


