#include <iostream>
#include <cmath>
using namespace std;

double rmCalc(double arr[], int n, int r) {
	double sum = 0;
	
	for(int i = 0; i < n; i++) {
		sum = sum + pow(arr[i], r);
	}
	
	return sum / n;
}

double cmCalc(double arr[], int n, int r) {
	double mean = rmCalc(arr, n, 1);
	double sum = 0;
	
	for(int i = 0; i < n; i++) {
		sum = sum + pow((arr[i] - mean), r);
	}
	
	return sum/n;
}

double sk(double arr[], int n) {
	double CM2 = cmCalc(arr, n, 2);
	double CM3 = cmCalc(arr, n, 3);
	
	double result = CM3/pow(CM2, 1.5);
	return result;
}

double kr(double arr[], int n) {
	double CM2 = cmCalc(arr, n, 2);
	double CM4 = cmCalc(arr, n, 4);
	
	double result = CM4/pow(CM2, 2);
	return result;
}


void calculation() {
	int n;
	cout << "How many numbers do you have? => ";
	cin >> n;
	
	double results[n];
	for(int i = 0; i<n; i++) {
		cout << i+1 << ": ";
		cin >> results[i];
	}
	
	cout << endl;
	
	for(int i = 0; i<n; i++) {
		if(i < n-1) {
			cout << results[i] << ", ";
		} else {
			cout << results[i] << endl << endl;
		}
	}
	
	double RM1 = rmCalc(results, n, 1);
	double RM2 = rmCalc(results, n, 2);
	double RM3 = rmCalc(results, n, 3);
	double RM4 = rmCalc(results, n, 4);
	
	
	cout << "RM1 => " << RM1 << endl;
	cout << "RM2 => " << RM2 << endl;
	cout << "RM3 => " << RM3 << endl;
	cout << "RM4 => " << RM4 << endl << endl;
	
	double CM1 = 0;
	double CM2 = cmCalc(results, n, 2);
	double CM3 = cmCalc(results, n, 3);
	double CM4 = cmCalc(results, n, 4);
	
	cout << "CM1 => " << CM1 << endl;
	cout << "CM2 => " << CM2 << endl;
	cout << "CM3 => " << CM3 << endl;
	cout << "CM4 => " << CM4 << endl << endl;
	
	double SK = sk(results, n);
	double KR = kr(results, n);
	
	cout << "SK => " << SK << endl;
	cout << "KR => " << KR << endl << endl;
	
}

int main() {
	char confirmation;
	do {
		calculation();
		
		cout << "Do you want to calcultate again? (y/n) => ";
		
		cin >> confirmation;
		cout << endl;
	} while (confirmation == 'y');
	
	return 0;
}
