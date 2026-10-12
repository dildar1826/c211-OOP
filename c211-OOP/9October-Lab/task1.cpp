#include<iostream>
#include<cstring> // how to make strcpy from scratch
using namespace std;
class smartThermostat {
	double currentTempC;
	double targetTempC;
	char  mode[5]; // off problem
public:
	smartThermostat() {
		currentTempC = 22.3;
		targetTempC = 22.0;
		 // type error of -->  mode[5] = "off";
		strcpy(mode, "off");
		
	}
	smartThermostat(double startTempC, const char * startMode) : smartThermostat() { //array problem......
		myStrcpy(mode, startMode);
		startTempC = 22.0;

	}
	void myStrcpy(char * destination, const char * source) {
		while (*source != '\0') {
			*destination = *source;
			destination++;
			source++;
		}
		*destination = '\0'; // Null-terminate the destination string
	}
	void displayStatus() {
		
		cout << "TargetTempC  :" << targetTempC << endl;
		cout << "CurrentTempC  :" << currentTempC<<endl;
		cout << "Mode is  :" << mode;
	}
	double getCurrentTempC() {
		return currentTempC;
	}
	double getCurrentTempF() {
		double currentTempF = 0;
		currentTempF = (currentTempC * 9 / 5) + 32;

		return currentTempF;
	}
	bool setMode(const char * newMode) { 
		if(newMode == "heat" || newMode == "cool" || newMode == "off") {
			myStrcpy(mode, newMode);
			return true;
		}
		return false;
	}
};
/*class Rectangle {
private:
	float length;
	float width;
public:
	float calcParameter() {
		float per = 2 * (length + width);
		return per;

	}
	float calcArea() {
		float area = length * width;
		return area;
	}
	void setlenth(float l) {
		if (l > 0) 
			length = l;
		}
		void setwidth(float m) {
			if (m > 0) {
				width = m;
			}
		}

		float getlength() {
			return length;
		}
		float getwidth() {
			return width;
		}
		bool isSquare() {
			if (length = width) {
				cout << "Is square";

				return true;
			}
			else
				cout << "Not square";
			return false;
		}

	};*/


	/*struct Student {
		int rollNo;
		string name;
		float cgpa;
	};*/
	int main() {
		/*Student st1 = {12,"Ahmad",3.5};
		Student st2;
		st2 = st1;
		cout << st2.rollNo;

		st1.rollNo = 12;
		st1.name = "Ahmad";
		st1.cgpa = 3.5;
		cout <<"Enter rollno"<<endl;
		cin >> st1.rollNo;
		cout << "Roll no is" << st1.rollNo<<endl;*/

		/*Rectangle r1;
		r1.setlenth(30.2);
		r1.setwidth(20.4);
		cout << r1.calcArea()<<endl;
		cout << r1.calcParameter()<<endl;*/

		smartThermostat s1;
		s1.displayStatus();