#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int n = 10;
int arr[] = {99, 69, 96, 85, 68, 58, 80, 90, 100, 65};
//double arr[n];


// Calculation Functions
double rmCalc(int r);
double cmCalc(int r);

// Data Show Function
void showArr();
void addArray();
void rawMoments();
void centralMoments();
void SK();
void KR();
void exit();

int main() {
	short int choice;
	system("cls");
	system("color 06");
	
	cout << "\n\n\n\t\t***********************";
	cout <<     "\n\t\t* Moments Calculation *";
	cout <<     "\n\t\t***********************";
	cout <<"\n\n\t1. Check Array Data \n\t2. Add Or Edit Data\n\t3. Calculate Raw Moments\n\t4. Calculate Central Moments\n\t5. Calculate Skewness\n\t6. Calculate Kurtosis\n\t7. Exit \n\t > ";
	cin >> choice;
	
	switch(choice) {
		case 1:
			showArr();
			break;
		case 2:
			addArray();
			break;
		case 3:
			rawMoments();
			break;
		case 4:
			centralMoments();
			break;
		case 5:
			SK();
			break;
		case 6:
			KR();
			break;
		case 7:
			exit();
			break;
		default:
			cout << "\n\n\tInvalid Input !";
			cout << "\n\tPress Any Key To Continue...";
			getch();
			exit();
			main();
	}
}

// Calculation Function 
double rmCalc(int r) {
	double sum = 0;
	
	for(int i = 0; i<n; i++) {
		sum += pow(arr[i], r);
	}
	return sum/n;
}

double cmCalc(int r) {
	double mean = rmCalc(1);
	double sum = 0;
	
	for(int i = 0; i < n; i++) {
		sum += pow(arr[i] - mean, r);
	}
	return sum / n;
}

// Data Show Function
void showArr() {
	system("cls");
	cout << endl << endl;
	cout << "\tArry = [ ";
	for(int i = 0; i < n; i++) {
		cout << arr[i];
		if(i < n-1) {
			cout << ", ";
		} else {
			cout << " ]";
		}
	}
	
	cout << "\n\n\tPress any key to continue ... ";
	getch();
	main();
}
void addArray() {
	system("cls");
	cout << "\n\n\n\t\tPlease, input " << n << " numbers." << endl;
	
	// Input from user
	for(int i = 0; i < n; i++) {
		cout << "\t" << i+1 << "th element > ";
		cin >> arr[i];
	}

	cout << "\n\n\tPress any key to continue ... ";
	getch();
	main();
}

void rawMoments() {
	system("cls");
	cout << "\n\n\t1st raw Moment = " << rmCalc(1);
	cout << "\n\t2nd raw Moment = " << rmCalc(2);
	cout << "\n\t3rd raw Moment = " << rmCalc(3);
	cout << "\n\t4th raw Moment = " << rmCalc(4);
	
	cout << "\n\n\tPress any key to continue ... ";
	getch();
	main();
}

void centralMoments() {
	system("cls");
	cout << "\n\n\t1st central Moment = " << cmCalc(1);
	cout << "\n\t2nd central Moment = " << cmCalc(2);
	cout << "\n\t3rd central Moment = " << cmCalc(3);
	cout << "\n\t4th central Moment = " << cmCalc(4);
	
	cout << "\n\n\tPress any key to continue ... ";
	getch();
	main();
}

void SK() {
	system("cls");
	double cm2 = cmCalc(2);
	double cm3 = cmCalc(3);
	double sk = cm3 / pow(cm2, 1.5);
	
	cout << "\n\n\tSkewness = " << sk;
	
	cout << "\n\n\tPress any key to continue ... ";
	getch();
	main();
}

void KR() {
	system("cls");
	double cm2 = cmCalc(2);
	double cm4 = cmCalc(3);
	double kr = cm4 / pow(cm2, 2);
	
	cout << "\n\n\tKurtosis = " << kr;
	
	cout << "\n\n\tPress any key to continue ... ";
	getch();
	main();
}



void exit() {
	system("cls");
	cout << "\n\n\n\t\tTanak You For Using!";
}
