//variant 66 
//Способ представления графа - матрица инцидентности. Алгоритм:
//Дана матрица весов дуг. Определить и  вывести все циклы в орграфе, заданной длины х(ввод с клав)

#include <iostream>
#include <string>
using namespace std;

const int v = 5;

void func(int i, int* color, int(*B)[v * v], string rezP, int n, /*int sumP*/ int(*VesaD)[v], int oldj) {
	string rez = rezP;
	rez = rez + to_string(i);
	color[i] = 1;

	for (int k = 0; k < v * v; k++) {
		if (B[i][k] == 1) {
			int j;
			for (j = 0; j < v; j++) {
				if (B[j][k] == -1) break;
			}

			if (rez.size()<v && j + 48 != rez[0] && color[j]==0) {
				func(j, color, B, rez, n, VesaD, j);
			}								//
			else {
				int ch = j + 48;
				int sum = 0;
				int r;
				for (r = 0; r < rez.size()-1; r++) {
					sum = sum + VesaD[rez[r]-48][rez[r + 1]-48]; 
				}
				sum = sum + VesaD[rez[r]-48][rez[0]-48]; 
				if (sum == n && rez[0] == ch)
					cout <<"cycle: " << rez << " length: " << sum << endl;
			}
		}
	}	
	color[i] = 0;
}

int main() {
	int n;
	string s = "";
	int oldj = -1;
	/*
	int B[v][v * v] = {{0,-1,-1,0,0,0,1,0,0},
						 {0,1,0,0,0,-1,0,0,0},
						 {0,0,1,0,0,1,-1,0,0} };
	int color[v] = { 0,0,0 }; 
	
	int VesaD[v][v] = {{-1,-1,1},
					   {2,-1,-1},
					   {1,3,-1}};
	*/

	/*int B[v][v * v] = {{0,1,0,1, 0,0,0,0, -1,0,0,0, 0,0,0,0},
						{0,-1,0,0, 0,0,1,1, 0,0,0,0, 0,-1,0,0},
						{0,0,0,0, 0,0,-1,0, 1,0,0,0, 0,0,-1,0},
						{0,0,0,-1, 0,0,0,-1, 0,0,0,0, 0,1,1,0} }; 
	int color[v] = { 0,0,0,0 };
	int VesaD[v][v] = { {-1,3,-1,1},
						{-1,-1,2,1},
						{2,-1,-1,-1},
						{-1,1,2,-1} }; */

	int B[v][v * v] = {{0,1,1,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, -1,0,0,0,0},
						{0,-1,0,0,0, 0,0,1,0,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, 
						{0,0,-1,0,0, 0,0,-1,0,0, 0,0,0,1,1, 0,0,-1,0,0, 0,0,0,0,0},
						{0,0,0,-1,0, 0,0,0,0,0, 0,0,0,-1,0, 0,0,1,0,1, 0,0,0,0,0},
						{0,0,0,0,0, 0,0,0,0,-1, 0,0,0,0,-1, 0,0,0,0,-1, 1,0,0,0,0} };
	int color[v] = { 0,0,0,0,0 }; 
	
	int VesaD[v][v] = {{-1,2,3,3,-1},
					   {-1,-1,2,-1,1},
					   {-1,-1,-1,1,2},
					   {-1,-1,1,-1,3},
					   {1,-1,-1,-1,-1}};
	

	cout << "what length of cycle?" << endl;
	cin >> n;

	for (int i = 0; i < v; i++) {
		func(i, color, B, s, n, VesaD, oldj);
		color[i] = 2;
	}

} 