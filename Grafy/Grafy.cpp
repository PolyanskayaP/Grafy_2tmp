//variant 66 
//Способ представления графа - матрица инцидентности. Алгоритм:
//Дана матрица весов дуг. Определить и  вывести все циклы в орграфе, заданной длины х(ввод с клав)

#include <iostream>
#include <string>
using namespace std;

const int v = 4;

void func(int i, int* color, int(*B)[v * v], string rezP, int n) {
	string rez = rezP;
	rez = rez + to_string(i);
	color[i] = 1;

	//poisk vershini FOR!
	for (int k = 0; k < v * v; k++) {
		if (B[i][k] == 1) {
			int j;
			for (j = 0; j < v; j++) {
				if (B[j][k] == -1) break;
			}//  i->j  duga, j-smej versh 
	//		cout <<" @" << rez <<"/"<< count << "@ ";
			
			//nashli vershinu

			if (rez.size()<v && j + 48 != rez[0] && color[j]==0) {
				func(j, color, B, rez, n);
			}
			else {
				//<=9   //a na bOlshem kak budet?  //matr vesov sdelay(+2oy putb')+ABCD
				int ch = j + 48;
				if (rez.size() == n && rez[0] == ch )
					cout << rez << endl;
			}
		}
	}	
	color[i] = 0;
}

int main() {
	int n;
	string s = "";
/*	int B[v][v * v] = {{0,-1,-1,0,0,0,1,0,0},
						 {0,1,0,0,0,-1,0,0,0},
						 {0,0,1,0,0,1,-1,0,0} };
	int color[v] = { 0,0,0 }; */

	int B[v][v * v] = {{0,1,0,1, 0,0,0,0, -1,0,0,0, 0,0,0,0},
						{0,-1,0,0, 0,0,1,1, 0,0,0,0, 0,-1,0,0},
						{0,0,0,0, 0,0,-1,0, 1,0,0,0, 0,0,-1,0},
						{0,0,0,-1, 0,0,0,-1, 0,0,0,0, 0,1,1,0} }; 
	int color[v] = { 0,0,0,0 };

/*	int B[v][v * v] = {{0,1,1,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, -1,0,0,0,0},
						{0,-1,0,0,0, 0,0,1,0,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, 
						{0,0,-1,0,0, 0,0,-1,0,0, 0,0,0,1,1, 0,0,-1,0,0, 0,0,0,0,0},
						{0,0,0,-1,0, 0,0,0,0,0, 0,0,0,-1,0, 0,0,1,0,1, 0,0,0,0,0},
						{0,0,0,0,0, 0,0,0,0,-1, 0,0,0,0,-1, 0,0,0,0,-1, 1,0,0,0,0} };
	int color[v] = { 0,0,0,0,0 }; */

	cout << "what length of cycle?" << endl;
	cin >> n;

	for (int i = 0; i < v; i++) {
		func(i, color, B, s, n);
		color[i] = 2;
	}

}