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
	cout << "명령어 입력 : ";
	cin >> command;

	return command;
}

#ifdef Quiz1
enum Mode { ALL, EVEN, ODD };

//결과 출력
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
struct Colide
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

	//행렬 초기화
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
			//행렬 곱셈
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
			//행렬 덧셈
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
			//행렬 뺄셈
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
			//전치행렬1
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
			//전치행렬2
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
			//행렬 초기화
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
				//곱셈
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
	Colide collist[20];
	Colide sortedcollist[20];
	Colide colidebuf;
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
		case '+'://맨 위 리스트 추가
			if (count >= 20)
			{
				cout << "리스트가 꽉 찼습니다." << endl;
				break;
			}

			cout << "좌표 입력: ";
			cin >> x >> y >> z;

			if (head + count >= 20)
			{
				for (int i = head; i < head + count; ++i)
				{
					collist[i - 1] = collist[i];
				}
				--head;
			}

			collist[head + count] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };

			++count;
			break;
		case '-'://맨 위 리스트 제거
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			collist[head + count - 1] = { 0, 0, 0, 0 };

			--count;
			break;
		case 'e'://맨 아래 리스트 추가
			if (count >= 20)
			{
				cout << "리스트가 꽉 찼습니다." << endl;
				break;
			}

			cout << "좌표 입력: ";
			cin >> x >> y >> z;

			if (head <= 0)
			{
				for (int i = count; i > 0; --i)
				{
					collist[i] = collist[i - 1];
				}
				collist[0] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };
			}
			else
			{
				--head;
				collist[head] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };
			}

			++count;
			break;
		case 'd'://맨 아래 리스트 제거
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			collist[head] = { 0, 0, 0, 0 };
			++head;
			break;
		case 'l'://저장된 점의 수
			cout << "리스트 길이: " << count;
			break;
		case 'c'://리스트 초기화
			for(int i = 0; i < 20; ++i)
				collist[i] = { 0, 0, 0, 0 };
			head = 0;
			count = 0;
			break;
		case 'm'://가장 먼 좌표
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			colidebuf.length = 0;

			for (int i = head; i < head + count; ++i)
			{
				if (collist[i].length > colidebuf.length)
					colidebuf = collist[i];
			}

			cout << "가장 먼 좌표" << endl;
			cout.setf(ios::left);
			cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
			cout.setf(ios::left);
			cout << setw(5) << collist[i].x << setw(5) << collist[i].y << setw(5) << collist[i].z << collist[i].length << endl << endl;
			break;
		case 'n'://가장 가까운 좌표
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			colidebuf.length = INTMAX_MAX;

			for (int i = head; i < head + count; ++i)
			{
				if (collist[i].length < colidebuf.length)
					colidebuf = collist[i];
			}

			cout << "가장 가까운 좌표" << endl;
			cout.setf(ios::left);
			cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
			cout.setf(ios::left);
			cout << setw(5) << collist[i].x << setw(5) << collist[i].y << setw(5) << collist[i].z << collist[i].length << endl << endl;
			break;
		case 'a'://오름차순 정렬
			break;
		case 's'://내림차순 정렬
			break;
		default:
			break;
		}
		cout << endl;

		switch (sort)
		{
		case NORM:
			if (count < 10)
			{
				int n;
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
						cout << setw(5) << collist[i].x << setw(5) << collist[i].y << setw(5) << collist[i].z << collist[i].length << endl;
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
					cout << setw(5) << collist[i].x << setw(5) << collist[i].y << setw(5) << collist[i].z << collist[i].length << endl;
				}
			}
			cout << endl;
			break;
		case UPPER:
			break;
		case LOWER:
			break;
		default:
			break;
		}
	}
#endif // Quiz3

}