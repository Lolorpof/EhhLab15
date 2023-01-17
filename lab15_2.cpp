#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double box[][N]){
	for(int i = 0; i < N; i++){
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N; j++){
			cin >> box[i][j];
		}
	}
}

void findLocalMax(const double box[][N], bool check[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			double t = box[i][j];
			if(i == 0 || j == 0 || i == N-1 || j == N-1) check[i][j] = 0;
			else if(t >= box[i-1][j] && t >= box[i+1][j] && t >= box[i][j-1] && t >= box[i][j+1]) check[i][j] = 1;
			else check[i][j] = 0;
		}
	}
}

void showMatrix(const bool check[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(check[i][j] == 0) cout << "0" << " ";
			else cout << "1" << " ";
		}
		cout << "\n";
	}
}