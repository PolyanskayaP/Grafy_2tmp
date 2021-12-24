//variant 66 
//Способ представления графа - матрица инцидентности. Алгоритм:
//Дана матрица весов дуг. Определить и  вывести все циклы в орграфе, заданной длины х(ввод с клав)

#include <iostream>
#include <string>
using namespace std;

const int v = 3;

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
			cout <<" @" << rez << "@ ";
			
			//nashli vershinu
			if (color[j] == 0) {
				color[j] = 1;
				func(j, color, B, rez, n);
			}
			else {
				//rez = rez + to_string(j);
				//<=9   //a na bOlshem kak budet?  //matr vesov sdelay
				int ch = j + 48;
				if (rez.size() == n /*+ 1*/  && rez[0] == ch /*rez[rez.size() - 1]*/)
					cout << rez << endl;
			}
		}
	}	//color[i]=2;
}

int main() {
	//char s[v];
	int n;
	string s = "";
	int B[v][v * v] = { {0,-1,-1,0,0,0,1,0,0},
			   {0,1,0,0,0,-1,0,0,0},
			   {0,0,1,0,0,1,-1,0,0} };
	int color[v] = { 0,0,0 };

	cout << "what length of cycle?" << endl;
	cin >> n;

	for (int i = 0; i < v; i++) {
		if (color[i] == 0) func(i, color, B, s, n);
	}

}