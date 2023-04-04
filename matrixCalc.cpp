#include <iostream>
using namespace std;
int matA[10][10];
int matB[10][10];
int matAdd[10][10];
int matMul[10][10];

void addValue(int mat[10][10], int row, int col) {
	for(int i = 0; i<row; i++) {
		for(int j = 0; j<col; j++) {
			cout << "Enter a value at " << i+1 << ", " << j+1 << " :";
			cin >> mat[i][j];
		}
	}
}

void showValue(int mat[10][10], int row, int col) {
	for(int i = 0; i<row; i++) {
		for(int j = 0; j<col; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int m1, n1, m2, n2;
	cout << "How many row in MatA: ";
	cin >> m1;
	cout << "How many column in MatA: ";
	cin >> n1;
	addValue(matA, m1, n1);
	system("cls");
	
	cout << "How many row in MatB: ";
	cin >> m2;
	cout << "How many column in MatB: ";
	cin >> n2;
	addValue(matB, m2, n2);
	system("cls");
	
	cout << "Mat A: " << endl;
	showValue(matA, m1, n1);
	cout << "Mat B: " << endl;
	showValue(matB, m2, n2);
	
	if(m1 == m2 && n1 == n2) {
		for(int i = 0; i<m1; i++) {
			for(int j = 0; j<n1; j++) {
				matAdd[i][j] = matA[i][j] + matB[i][j];
			}
		}
		
		cout << "MatA + MatB : " << endl;
		showValue(matAdd, m1, n1);
	} else {
		cout << "Sorry, Addition can not be possible!" << endl;
	}
	
	if(n1 == m2) {
		for(int i = 0; i < m1; i++) {
			for(int j = 0; j < n2; j++) {
				int temp = 0;
				for(int k = 0; k < n1; k++) {
					temp += matA[i][k] * matB[k][j];
				}
				matMul[i][j] = temp;
			}
		}
		cout << "MatA x MatB : " << endl;
		showValue(matMul, m1, n2);
	} else {
		cout << "Sorry, Multliplication can not be possible!" << endl;
	}
}