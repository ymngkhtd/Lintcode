#include<iostream>
using namespace std;

//��С���ҷ�Χ���򻯲��ҹ���

bool Find(int *matrix, int rows, int columns, int number)
{
	bool found = NULL;

	if(matrix!=NULL&&rows >0&&columns>0)
	{
		int row = 0;
		int col = columns - 1;
		while (row < rows&&col>0)
		{
			if (matrix[row *columns + col] == number)
			{
				found = true;
				break;

			}
			else if (matrix[row*columns + col] > number)
				--col;
			else
			{
				++row;

			}
		}
		return found;
	}
}