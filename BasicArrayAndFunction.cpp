#include <iostream>
#include <cmath>
using namespace std;

// 1. Arry Inupt and output 
// 2. Function

int add(int a, int b) {  // f(a, b) = a+b;
	int result = a + b;
	return result;
}

double rmCalc(int arr[], int n, int r) {
	double sum = 0;
	
	for(int i = 0; i < n; i++) {
		sum = sum + pow(arr[i], r);
	}
	
	return sum/n;
}

double cmCalc(int arr[], int n, int r) {
	double mean = rmCalc(arr, n, 1);
	double sum = 0;
	
	for(int i = 0; i < n; i++) {
		sum = sum + pow(arr[i] - mean, r);
	}
	
	return sum / n;
}

double skCalc(int arr[], int n) {
	double cm2 = cmCalc(arr, 10, 2);
	double cm3 = cmCalc(arr, 10, 3);
	
	double result = cm3 / pow(cm2, 1.5);
	return result;
}

double krCalc(int arr[], int n) {
	double cm2 = cmCalc(arr, 10, 2);
	double cm4 = cmCalc(arr, 10, 4);
	
	double result = cm4 / pow(cm2, 2);
	return result;
}



int main() {
//	int results[10] = {78, 82, 89, 78, 90, 49, 90, 76, 96, 100};
//	// Index           0   1    2  3    4  5    6   7   8   9
	
	int n;
	cout << "How many numbers do you have? => ";
	cin >> n;
	int results[n] = {};
	
	// Input from user 
	
	for(int i = 0; i < n; i++) {
		cout << "Input a value at " << i+1 << "th position => ";
		cin >> results[i];
	}

	// Output
	cout << "Output " << endl;
	for(int i = 0; i < n; i++) {
		cout << results[i] << ", ";
	}
	cout << endl;
	
//	int addition = add(5, 6);
//	int addition2 = add(10, 20);
//	
//	cout << addition << endl;
//	cout << addition2 << endl;
//	cout << add(45, 90) << endl;

	double rm1 = rmCalc(results, n, 1);
	double rm2 = rmCalc(results, n, 2);
	double rm3 = rmCalc(results, n, 3);
	double rm4 = rmCalc(results, n, 4);

	cout << "RM1 = " << rm1 << endl;
	cout << "RM2 = " << rm2 << endl;
	cout << "RM3 = " << rm3 << endl;
	cout << "RM4 = " << rm4 << endl;
	
	double cm1 = 0;
	double cm2 = cmCalc(results, n, 2);
	double cm3 = cmCalc(results, n, 3);
	double cm4 = cmCalc(results, n, 4);
	
	cout << "CM1 = " << cm1 << endl;
	cout << "CM2 = " << cm2 << endl;
	cout << "CM3 = " << cm3 << endl;
	cout << "CM4 = " << cm4 << endl;
	
	double sk = skCalc(results, n);
	double kr = krCalc(results, n);
	
	cout << "Sk = " << sk << endl;
	cout << "Kr = " << kr << endl;
	
}
