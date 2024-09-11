#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>
#include <Windows.h>

#define Quiz3

using namespace std;

random_device rd;
mt19937 gen(rd());

char GetCommand()
{
	char command = '\0';
	cout << "��ɾ� �Է� : ";
	cin >> command;

	return command;
}

#ifdef Quiz1
enum Mode { ALL, EVEN, ODD };

//��� ���
void PrintSum(int matrix1[][4], int matrix2[][4], int matrixsum[][4], char oper, Mode mod)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(mod == ALL || mod == ODD && (matrix1[i][j] % 2 == 1) || mod == EVEN && (matrix1[i][j] % 2 == 0))
				cout << matrix1[i][j] << " ";
			else
				cout << "  ";
		}
		if (i == 1)
			cout << " " << oper << "  ";
		else
			cout << "    ";

		for (int j = 0; j < 4; ++j)
		{
			if (mod == ALL || mod == ODD && (matrix2[i][j] % 2 == 1) || mod == EVEN && (matrix2[i][j] % 2 == 0))
				cout << matrix2[i][j] << " ";
			else
				cout << "  ";
		}
		if (i == 2 || i == 1)
			cout << " -  ";
		else
			cout << "    ";

		for (int j = 0; j < 4; ++j)
		{
			if (mod == ALL || mod == ODD && (matrixsum[i][j] % 2 == 1) || mod == EVEN && (matrixsum[i][j] % 2 == 0))
				cout << matrixsum[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}
#endif // Quiz1

#ifdef Quiz3
struct Coordinate
{
	int x, y, z;
	int length;
};

enum Sort { NORM, UPPER, LOWER };
#endif // Quiz3

int main()
{
#ifdef Quiz1
	int matrix1[4][4];
	int matrix2[4][4];
	int matrixsum[4][4];
	int sum;
	char command = '\0';
	Mode mod = ALL;

	uniform_int_distribution<int> randval(0, 1);
	uniform_int_distribution<int> randdist(0, 3);

	//��� �ʱ�ȭ
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			matrix1[i][j] = randval(gen);
			matrix2[i][j] = randval(gen);
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		int x = randdist(gen);
		int y = randdist(gen);

		if (matrix1[x][y] == 2)
			--i;
		else
			matrix1[x][y] = 2;
	}
	for (int i = 0; i < 2; ++i)
	{
		int x = randdist(gen);
		int y = randdist(gen);

		if (matrix2[x][y] == 2)
			--i;
		else
			matrix2[x][y] = 2;
	}

	while (command != 'q')
	{
		command = GetCommand();
		switch (command)
		{
		case 'm':
			//��� ����
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					matrixsum[i][j] = matrix1[i][0] * matrix2[0][j] + matrix1[i][1] * matrix2[1][j]
						+ matrix1[i][2] * matrix2[2][j] + matrix1[i][3] * matrix2[3][j];
				}
			}

			PrintSum(matrix1, matrix2, matrixsum, '*', mod);
			break;
		case 'a':
			//��� ����
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					matrixsum[i][j] = matrix1[i][j] + matrix2[i][j];
				}
			}
			
			PrintSum(matrix1, matrix2, matrixsum, '+', mod);
			break;
		case 'd':
			//��� ����
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					matrixsum[i][j] = matrix1[i][j] - matrix2[i][j];
				}
			}

			PrintSum(matrix1, matrix2, matrixsum, '-', mod);
			break;
		case 'r':
			break;
		case 't':
			//��ġ���1
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (mod == ALL || mod == ODD && (matrix1[i][j] % 2 == 1) || mod == EVEN && (matrix1[i][j] % 2 == 0))
						cout << matrix1[i][j] << " ";
					else
						cout << "   ";
				}
				if (i == 2 || i == 1)
					cout << " -  ";
				else
					cout << "    ";

				for (int j = 0; j < 4; ++j)
				{
					if (mod == ALL || mod == ODD && (matrix1[j][i] % 2 == 1) || mod == EVEN && (matrix1[j][i] % 2 == 0))
						cout << matrix1[j][i] << " ";
					else
						cout << "   ";
				}
				cout << endl;
			}
			cout << endl;
			//��ġ���2
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (mod == ALL || mod == ODD && (matrix2[i][j] % 2 == 1) || mod == EVEN && (matrix2[i][j] % 2 == 0))
						cout << matrix2[i][j] << " ";
					else
						cout << "   ";
				}
				if (i == 2 || i == 1)
					cout << " -  ";
				else
					cout << "    ";

				for (int j = 0; j < 4; ++j)
				{
					if (mod == ALL || mod == ODD && (matrix2[j][i] % 2 == 1) || mod == EVEN && (matrix2[j][i] % 2 == 0))
						cout << matrix2[j][i] << " ";
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case 'e':
			if (mod == ALL)
				mod = EVEN;
			else if (mod == EVEN)
				mod = ODD;
			else if (mod == ODD)
				mod = ALL;

			cout << "mode : " << mod << endl;
			break;
		case 's':
			//��� �ʱ�ȭ
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					matrix1[i][j] = randval(gen);
					matrix2[i][j] = randval(gen);
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				int x = randdist(gen);
				int y = randdist(gen);

				if (matrix1[x][y] == 2)
					--i;
				else
					matrix1[x][y] = 2;
			}
			for (int i = 0; i < 2; ++i)
			{
				int x = randdist(gen);
				int y = randdist(gen);

				if (matrix2[x][y] == 2)
					--i;
				else
					matrix2[x][y] = 2;
			}
			break;
		default:
			if (command >= '1' && command <= '9')
			{
				//����
				int n = command - '0';

				for (int i = 0; i < 4; ++i)
				{
					if (i == 0)
						cout << n << " * ";
					else
						cout << "    ";

					for (int j = 0; j < 4; ++j)
					{
						if (mod == ALL || mod == ODD && (matrix1[i][j] % 2 == 1) || mod == EVEN && (matrix1[i][j] % 2 == 0))
							cout << matrix1[i][j] << " ";
						else
							cout << "   ";
					}
					if (i == 2 || i == 1)
						cout << " -  ";
					else
						cout << "    ";

					for (int j = 0; j < 4; ++j)
					{
						if (mod == ALL || mod == ODD && (matrix1[i][j] * n % 2 == 1) || mod == EVEN && (matrix1[i][j] * n % 2 == 0))
							cout << matrix1[i][j] * n << " ";
						else
							cout << "   ";
					}
					cout << endl;
				}
				cout << endl;

				for (int i = 0; i < 4; ++i)
				{
					if (i == 0)
						cout << n << " * ";
					else
						cout << "    ";

					for (int j = 0; j < 4; ++j)
					{
						if (mod == ALL || mod == ODD && (matrix2[i][j] % 2 == 1) || mod == EVEN && (matrix2[i][j] % 2 == 0))
							cout << matrix2[i][j] << " ";
						else
							cout << "   ";
					}
					if (i == 2 || i == 1)
						cout << " -  ";
					else
						cout << "    ";

					for (int j = 0; j < 4; ++j)
					{
						if (mod == ALL || mod == ODD && (matrix2[i][j] * n % 2 == 1) || mod == EVEN && (matrix2[i][j] * n % 2 == 0))
							cout << matrix2[i][j] * n << " ";
						else
							cout << "   ";
					}
					cout << endl;
				}
			}
			break;
		}

		cout << endl;
	}
#endif // Quiz1

#ifdef Quiz3
	Coordinate coordlist[20];
	Coordinate sortedcoordlist[20];
	Coordinate coordbuf;
	int head = 0;
	int count = 0;
	int x, y, z;
	char command = '\0';
	Sort sort = NORM;

	while (command != 'q')
	{
		command = GetCommand();
		switch (command)
		{
		case '+'://�� �� ����Ʈ �߰�
			if (count >= 20)
			{
				cout << "����Ʈ�� �� á���ϴ�." << endl;
				break;
			}

			cout << "��ǥ �Է�: ";
			cin >> x >> y >> z;

			if (head + count >= 20)
			{
				for (int i = head; i < head + count; ++i)
				{
					coordlist[i - 1] = coordlist[i];
				}
				--head;
			}

			coordlist[head + count] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };

			++count;
			break;
		case '-'://�� �� ����Ʈ ����
			if (count <= 0)
			{
				cout << "����Ʈ�� ������ϴ�." << endl;
				break;
			}

			coordlist[head + count - 1] = { 0, 0, 0, 0 };

			--count;
			break;
		case 'e'://�� �Ʒ� ����Ʈ �߰�
			if (count >= 20)
			{
				cout << "����Ʈ�� �� á���ϴ�." << endl;
				break;
			}

			cout << "��ǥ �Է�: ";
			cin >> x >> y >> z;

			if (head <= 0)
			{
				for (int i = count; i > 0; --i)
				{
					coordlist[i] = coordlist[i - 1];
				}
				coordlist[0] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };
			}
			else
			{
				--head;
				coordlist[head] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };
			}

			++count;
			break;
		case 'd'://�� �Ʒ� ����Ʈ ����
			if (count <= 0)
			{
				cout << "����Ʈ�� ������ϴ�." << endl;
				break;
			}

			coordlist[head] = { 0, 0, 0, 0 };
			++head;
			break;
		case 'l'://����� ���� ��
			cout << "����Ʈ ����: " << count;
			break;
		case 'c'://����Ʈ �ʱ�ȭ
			for(int i = 0; i < 20; ++i)
				coordlist[i] = { 0, 0, 0, 0 };
			head = 0;
			count = 0;
			break;
		case 'm'://���� �� ��ǥ
			if (count <= 0)
			{
				cout << "����Ʈ�� ������ϴ�." << endl;
				break;
			}

			coordbuf.length = 0;

			for (int i = head; i < head + count; ++i)
			{
				if (coordlist[i].length > coordbuf.length)
					coordbuf = coordlist[i];
			}

			cout << "���� �� ��ǥ" << endl;
			cout.setf(ios::left);
			cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
			cout.setf(ios::left);
			cout << setw(5) << coordbuf.x << setw(5) << coordbuf.y << setw(5) << coordbuf.z << coordbuf.length << endl << endl;
			break;
		case 'n'://���� ����� ��ǥ
			if (count <= 0)
			{
				cout << "����Ʈ�� ������ϴ�." << endl;
				break;
			}

			coordbuf.length = INT_MAX;

			for (int i = head; i < head + count; ++i)
			{
				if (coordlist[i].length < coordbuf.length)
					coordbuf = coordlist[i];
			}

			cout << "���� ����� ��ǥ" << endl;
			cout.setf(ios::left);
			cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
			cout.setf(ios::left);
			cout << setw(5) << coordbuf.x << setw(5) << coordbuf.y << setw(5) << coordbuf.z << coordbuf.length << endl << endl;
			break;
		case 'a'://�������� ����
			if (sort == UPPER)
				sort = NORM;
			else
				sort = UPPER;
			break;
		case 's'://�������� ����
			if (sort == LOWER)
				sort = NORM;
			else
				sort = LOWER;
			break;
		default:
			break;
		}
		cout << endl;

		int n;
		switch (sort)
		{
		case NORM:
			if (count < 10)
			{
				if (head > 9)
					n = 19;
				else
					n = head + 9;

				cout.setf(ios::left);
				cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
				for (int i = n; i > n - 10; --i)
				{
					cout.setf(ios::left);
					cout << setw(8) << i;

					if (i < head + count && i >= head)
					{
						cout.setf(ios::left);
						cout << setw(5) << coordlist[i].x << setw(5) << coordlist[i].y << setw(5) << coordlist[i].z << coordlist[i].length << endl;
					}
					else
						cout << endl;
				}
			}
			else
			{
				cout.setf(ios::left);
				cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
				for (int i = head + count; i > head; --i)
				{
					cout.setf(ios::left);
					cout << setw(5) << coordlist[i].x << setw(5) << coordlist[i].y << setw(5) << coordlist[i].z << coordlist[i].length << endl;
				}
			}
			cout << endl;
			break;
		case UPPER:
			for (int i = 0; i < count; ++i)
			{
				sortedcoordlist[i] = coordlist[head + i];
			}
			qsort(sortedcoordlist, count, sizeof(Coordinate), [](const void* c1, const void* c2) { 
				const Coordinate* x = (Coordinate*)c1;
				const Coordinate* y = (Coordinate*)c2;

				if ((*x).length > (*y).length)
					return 1;
				if ((*x).length < (*y).length)
					return -1;

				return 0;
				});

			if (count < 10)
				n = 9;
			else
				n = count;

			for (int i = n; i >= 0; --i)
			{
				cout.setf(ios::left);
				cout << setw(8) << i;

				if (i < count)
				{
					cout.setf(ios::left);
					cout << setw(5) << sortedcoordlist[i].x << setw(5) << sortedcoordlist[i].y << setw(5) << sortedcoordlist[i].z << sortedcoordlist[i].length << endl;
				}
				else
					cout << endl;
			}

			cout << endl;
			break;
		case LOWER:
			for (int i = 0; i < count; ++i)
			{
				sortedcoordlist[i] = coordlist[head + i];
			}
			qsort(sortedcoordlist, count, sizeof(Coordinate), [](const void* c1, const void* c2) {
				const Coordinate* x = (Coordinate*)c1;
				const Coordinate* y = (Coordinate*)c2;

				if ((*x).length < (*y).length)
					return 1;
				if ((*x).length > (*y).length)
					return -1;

				return 0;
				});

			if (count < 10)
				n = 9;
			else
				n = count;

			for (int i = n; i >= 0; --i)
			{
				cout.setf(ios::left);
				cout << setw(8) << i;

				if (i < count)
				{
					cout.setf(ios::left);
					cout << setw(5) << sortedcoordlist[i].x << setw(5) << sortedcoordlist[i].y << setw(5) << sortedcoordlist[i].z << sortedcoordlist[i].length << endl;
				}
				else
					cout << endl;
			}

			cout << endl;
			break;
		default:
			break;
		}
	}
#endif // Quiz3

}