#include <iostream>
using namespace std;
const int s = 4;
int infinite = 1000000;
void floydwarshall(int matrix[][s])
{
	int distance[s][s];
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			distance[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			for (int k = 0; k < s; k++)
			{
				if (distance[j][i] + distance[i][k] < distance[j][k])
					distance[j][k] = distance[j][i] + distance[i][k];
			}
		}
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			
			if (distance[i][j] == infinite)
			{
				cout << "Infinite" << "     ";
			}
			else cout << distance[i][j] << "      ";

			
		}
		cout << "\n";
	}

}



int main()
{
	int matrix[s][s] = { {1, 3, infinite, 5},
						{infinite, 0, 4, infinite},
						{infinite, infinite, 3, 6},
						{infinite, infinite, infinite, 7}
	};

	floydwarshall(matrix);
	system("pause");
	return 0;
}