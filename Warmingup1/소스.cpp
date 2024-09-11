#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>
#include <math.h>
#include <Windows.h>

#define Quiz2

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

#ifdef Quiz2
enum Mode{ NORM, CAPITAL, REVERSE, AT, WREVERSE, ALTWORD, UPPER, LOWER, SEARCH};

bool CompareWord(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;

	const int gap = 'a' - 'A';
	for (int i = 0; i < s1.length(); ++i)
		if (s1[i] != s2[i] && s1[i] + gap != s2[i] && s1[i] != s2[i] + gap)
			return false;

	return true;
}
#endif // Quiz2

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

#ifdef Quiz2
	ifstream file("data.txt");
	string strarr[10];
	string sortedstrarr[10];
	string find;
	char command = '\0';
	char cto = '\0', cfor = '\0';
	int wordcount[10];
	int count = 0;
	Mode mode = NORM;

	if (file.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			getline(file, strarr[i]);
			cout << strarr[i] << endl;
		}
		cout << endl;
		file.close();

		for (int i = 0; i < 10; ++i)
		{
			wordcount[i] = 0;
			istringstream ss(strarr[i]);
			string temp;

			while (getline(ss, temp, ' '))
				++wordcount[i];

			for (int j = 0; j < i + 1; ++j)
			{
				if (j == i)
					sortedstrarr[i] = strarr[i];
				else if (wordcount[j] >= wordcount[i])
				{
					for (int k = i; k > j; --k)
					{
						sortedstrarr[k] = sortedstrarr[k - 1];
					}
					sortedstrarr[j] = strarr[i];
					break;
				}
			}
		}

		while (command != 'q')
		{
			command = GetCommand();
			switch (command)
			{
			case 'c':
				if (mode == CAPITAL)
					mode = NORM;
				else
					mode = CAPITAL;
				break;
			case 'd':
				if (mode == REVERSE)
					mode = NORM;
				else
					mode = REVERSE;
				break;
			case 'e':
				if (mode == AT)
					mode = NORM;
				else
					mode = AT;
				break;
			case 'f':
				if (mode == WREVERSE)
					mode = NORM;
				else
					mode = WREVERSE;
				break;
			case 'g':
				if (mode == ALTWORD)
					mode = NORM;
				else
				{
					cout << "바꿀 문자 입력(a->b): ";
					cin >> cto >> cfor;
					mode = ALTWORD;
				}
				break;
			case 'h':
				for (int i = 0; i < 10; ++i)
					cout << i << "번째 줄 단어 개수: " << wordcount[i] << endl;
				break;
			case 'r':
				if (mode == UPPER)
					mode = LOWER;
				else if (mode == LOWER)
					mode = NORM;
				else
					mode = UPPER;
				break;
			case 's':
				if (mode == SEARCH)
					mode = NORM;
				else
				{
					cout << "찾을 단어 입력: ";
					cin >> find;

					mode = SEARCH;
				}
				break;
			default:
				break;
			}
			cout << endl;

			if (command == 'q')
				break;

			switch (mode)
			{
			case NORM:
				for (int i = 0; i < 10; ++i)
					cout << strarr[i] << endl;
				break;
			case CAPITAL:
				count = 0;
				for (int i = 0; i < 10; ++i)
				{
					istringstream ss(strarr[i]);
					string temp;

					while (getline(ss, temp, ' '))
					{
						if (isalpha(temp[0]) == 1)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							++count;
						}
						cout << temp << ' ';

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					cout << endl << "대문자로 시작하는 단어 수: " << count << endl;
				}
				break;
			case REVERSE:
				for (int i = 0; i < 10; ++i)
				{
					for (int j = strarr[i].length() - 1; j >= 0; --j)
						cout << strarr[i][j];
					cout << endl;
				}
				break;
			case AT:
				for (int i = 0; i < 10; ++i)
				{
					for (int j = 0; j < strarr[i].length(); ++j)
					{
						cout << strarr[i][j];
						if (j % 3 == 0)
							cout << "@@";
					}
					cout << endl;
				}
				break;
			case WREVERSE:
				for (int i = 0; i < 10; ++i)
				{
					istringstream ss(strarr[i]);
					string temp;

					while (getline(ss, temp, ' '))
					{
						for (int j = temp.length() - 1; j >= 0; --j)
							cout << temp[j];
						cout << ' ';
					}
					cout << endl;
				}
				break;
			case ALTWORD:
				for (int i = 0; i < 10; ++i)
				{
					for (int j = 0; j < strarr[i].length(); ++j)
					{
						if (strarr[i][j] == cto)
							cout << cfor;
						else
							cout << strarr[i][j];
					}
					cout << endl;
				}
				break;
			case UPPER:
				for (int i = 0; i < 10; ++i)
					cout << sortedstrarr[i] << endl;
				break;
			case LOWER:
				for (int i = 9; i >= 0; --i)
					cout << sortedstrarr[i] << endl;
				break;
			case SEARCH:
				for (int i = 0; i < 10; ++i)
				{
					istringstream ss(strarr[i]);
					string temp;

					while (getline(ss, temp, ' '))
					{
						if (CompareWord(temp, find))
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

						cout << temp << ' ';

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					cout << endl;
				}
				break;
			default:
				break;
			}
		}
	}
	else
		cout << "파일을 찾을 수 없습니다";

	
	
#endif // Quiz2

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
					coordlist[i - 1] = coordlist[i];
				}
				--head;
			}

			coordlist[head + count] = { x, y, z, int(sqrt(pow(x,2) + pow(y,2) + pow(z,2))) };

			++count;
			break;
		case '-'://맨 위 리스트 제거
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			coordlist[head + count - 1] = { 0, 0, 0, 0 };

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
		case 'd'://맨 아래 리스트 제거
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			coordlist[head] = { 0, 0, 0, 0 };
			++head;
			break;
		case 'l'://저장된 점의 수
			cout << "리스트 길이: " << count;
			break;
		case 'c'://리스트 초기화
			for(int i = 0; i < 20; ++i)
				coordlist[i] = { 0, 0, 0, 0 };
			head = 0;
			count = 0;
			break;
		case 'm'://가장 먼 좌표
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			coordbuf.length = 0;

			for (int i = head; i < head + count; ++i)
			{
				if (coordlist[i].length > coordbuf.length)
					coordbuf = coordlist[i];
			}

			cout << "가장 먼 좌표" << endl;
			cout.setf(ios::left);
			cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
			cout.setf(ios::left);
			cout << setw(5) << coordbuf.x << setw(5) << coordbuf.y << setw(5) << coordbuf.z << coordbuf.length << endl << endl;
			break;
		case 'n'://가장 가까운 좌표
			if (count <= 0)
			{
				cout << "리스트가 비었습니다." << endl;
				break;
			}

			coordbuf.length = INT_MAX;

			for (int i = head; i < head + count; ++i)
			{
				if (coordlist[i].length < coordbuf.length)
					coordbuf = coordlist[i];
			}

			cout << "가장 가까운 좌표" << endl;
			cout.setf(ios::left);
			cout << setw(8) << "Index" << setw(5) << "x" << setw(5) << "y" << setw(5) << "z" << "length" << endl;
			cout.setf(ios::left);
			cout << setw(5) << coordbuf.x << setw(5) << coordbuf.y << setw(5) << coordbuf.z << coordbuf.length << endl << endl;
			break;
		case 'a'://오름차순 정렬
			if (sort == UPPER)
				sort = NORM;
			else
				sort = UPPER;
			break;
		case 's'://내림차순 정렬
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