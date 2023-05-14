//ಥ_ಥ
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <deque>

using namespace std;
const long long inf = 1e18;
void first(int a, int b, vector<vector<int>>v) {
	//long long mxz = -inf, mxi = 0, mxj = 0;
	long long mxz = inf, mxi = 0, mxj = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			//v[i][j];
			if (v[i][j] < mxz) {
				mxz = v[i][j];
				mxi = i;
				mxj = j;
			}
		}
	}
	cout << mxz << ' ' << mxi + 1 << ' ' << mxj + 1 << endl;
}
void second(int a, int b) {
	vector<vector<int>>v(a, vector<int>(b));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			v[i][j] = rand() % 10;
			if (i > j - 1) {
				v[i][j] = 0;
			}
		}
	}	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}
void third(int a, int b) {
	vector<vector<int>>v(7, vector<int>(7)), f(7, vector<int>(7));
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			v[i][j] = rand();
			f[i][j] = rand();
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 6; j++) {
			if (i + j >= 6) {
				v[i][j] = 99;
			}
		}	
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (abs(i - 3) + abs(j - 3) <= 3) {
				f[i][j] = 99;
			}
		}
	}
}
void fourthfirst() {
	bool b = 0;
	int q = 1;
	vector<vector<int>>v(4, vector<int>(6)), f(4, vector<int>(6));
	for (int j = 0; j < 6; j++) {
		if (b == 0) {
			for (int i = 0; i < 4; i++) {
				v[i][j] = q;
				q++;
			}
			b = 1;
		}
		else {
			for (int i = 3; i >= 0; i--) {
				v[i][j] = q;
				q++;
			}
			b = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}
void fourthsecond() {
	vector<vector<int>>v(4, vector<int>(6));
	int x = 0, y = 0, q = 1;
	while (v[x][y] == 0) {
		while (y < 6 && v[x][y] == 0) {
			v[x][y] = q;
			q++;
			y++;
		}
		y--;
		x++;
		while (x < 4 && v[x][y] == 0) {
			v[x][y] = q;
			q++;
			x++;
		}
		x--;
		y--;
		while (y >= 0 && v[x][y] == 0) {
			v[x][y] = q;
			q++;
			y--;
		}
		y++;
		x--;
		while (x >= 0 && v[x][y] == 0) {
			v[x][y] = q;
			q++;
			x--;
		}
		x++;
		y++;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}
void fifth(int a, int b, vector<vector<int>>v) {
	long long mxz = -inf, mxi = 0;
	for (int i = 0; i < a; i++) {
		int q = 0;
		for (int j = 0; j < b; j++) {
			q += v[i][j];
		}
		if (mxz < q) {
			mxz = q;
			mxi = i;
		}
	}
	cout << mxz << ' ' << mxi + 1 << endl;
}
void sixth(int a, int b, vector<vector<int>>v) {
	long long mxz = inf, mxi = 0;
	for (int j = 0; j < b; j++) {
		int q = 0;
		for (int i = 0; i < a; i++) {
			q += v[i][j];
		}
		if (mxz > q) {
			mxz = q;
			mxi = j;
		}
	}
	cout << mxz << ' ' << mxi + 1 << endl;
}
vector<vector<int>>seventh(int a, int b, vector<vector<int>>v) {
	vector<vector<int>>f(b, vector<int>(a));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			f[j][i] = v[i][j];
		}
	}
	return f;
}

vector<vector<int>>eighth(int a, int b, vector<vector<int>>k) {
	vector<vector<int>>d(b, vector<int>(a));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			d[i][b - j - 1] = k[i][j];
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {

	vector<vector<int>>v = {{12, 345, -12},{1, 2, 3},{9, 8, 7}};
	eighth(3, 3, seventh(3, 3, v));
}