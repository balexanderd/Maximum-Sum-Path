#include <iostream>
#include <string>

using namespace std;

struct path
{
	string Spath = "";
	int sum = 0;
	int i = 0;
	int j = 0;
};

//To adjust the size of n for an n*n array, change the value of size below.
const int size = 3;

void findPath(path &pathObj, int &sum, int input[size][size], string &Spath);

int main()
{
	//Change the value of the n*n array below:
	int twoDarr[size][size] = { { 12, 4, 38 }, { 2, 10, 4 }, { 10, 48, 10 } };
	int sum = 0;
	path pathObj;
	string path = "";

	findPath(pathObj, sum, twoDarr, path);

	cout << "Path: " << pathObj.Spath << "\nSum: " << pathObj.sum;

	cin.get();
	return 0;
}

void findPath(path &pathObj, int &sum, int input[size][size], string &Spath)
{
	if (pathObj.j < size)
	{
		pathObj.j++;
		sum += input[pathObj.i][pathObj.j];
		Spath += "r ";
		findPath(pathObj, sum, input, Spath);
		sum -= input[pathObj.i][pathObj.j];
		Spath = Spath.substr(0, Spath.size() - 2);
		pathObj.j--;
	}
	if (pathObj.i < size)
	{
		pathObj.i++;
		sum += input[pathObj.i][pathObj.j];
		Spath += "d ";
		findPath(pathObj, sum, input, Spath);
		sum -= input[pathObj.i][pathObj.j];
		Spath = Spath.substr(0, Spath.size() - 2);
		pathObj.i--;
	}
	if (pathObj.i == size - 1 && pathObj.j == size - 1)
	{
		sum += input[pathObj.i][pathObj.j];
		if (pathObj.sum < sum)
		{
			pathObj.sum = sum;
			pathObj.Spath = Spath;
		}
		sum -= input[pathObj.i][pathObj.j];
	}
	return;
}