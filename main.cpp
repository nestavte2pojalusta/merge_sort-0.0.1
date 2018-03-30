#include <iostream>
#include <sstream>
#include <utility>
#include <stdlib.h>
using namespace std;

void sort(float *st, int left, int right) {
	if (left == right)
		return;
	int M = (left + right) / 2;
	sort(st, left, M);
	sort(st, M + 1, right);
	int i = left;
	int j = M + 1;
	int *tmp = new int[right - left + 1];
	for (int sh = 0; sh < right - left + 1; sh++) {
		if ((j > right) || ((i <= M) && (st[i] < st[j]))) {
			tmp[sh] = st[i];
			i++;
		}
		else {
			tmp[sh] = st[j];
			j++;
		}
	}
	for (int sh = 0; sh < right - left + 1; sh++) {
		st[left + sh] = tmp[sh];
	}

	delete[] tmp;
}

void print_st(float *st, unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		cout << st[i] << " ";
	}
}

bool str(float *st, int n)
{
	bool h = true;
	string t;
	getline(cin, t);
	istringstream stream(t);
	for (unsigned int i = 0; i<n; i++)
	{
		if (!(stream >> st[i]))
		{
			h = false;
			return false;
		}
	}
	return true;
}

int main() {

	unsigned int n;
	if (!(cin >> n)) {
		cout << "An error has occured while reading numbers from line";
		return -1;
	}
	cin.get();
	float *st = new float[n];
	if (str(st, n)) {
		sort(st, 0, n - 1);
		print_st(st, n);
	}
	else {
		cout << "An error has occured while reading numbers from line";
	}
	delete[] st;
	return 0;
}

