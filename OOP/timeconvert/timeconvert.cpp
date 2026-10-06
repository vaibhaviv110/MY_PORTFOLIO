/*Time Converter*/
#include<iostream>
using namespace std;

class Timeconverter {
	public:
		void secondtotime() {
			int totalSeconds;
			int hours, minutes, seconds;

			cout << "Enter total seconds: ";
			cin >> totalSeconds;

			hours = totalSeconds / 3600;
			minutes = (totalSeconds % 3600) / 60;
			seconds = totalSeconds % 60;

			cout << "HH:MM:SS => "
			     << hours << ":"
			     << (minutes < 10 ? "0" : "") << minutes << ":"
			     << (seconds < 10 ? "0" : "") << seconds << endl;
		}

		void timeToSeconds() {
			int hours, minutes, seconds;
			int totalSeconds;

			cout << "Enter Hours: ";
			cin >> hours;

			cout << "Enter Minutes: ";
			cin >> minutes;

			cout << "Enter Seconds: ";
			cin >> seconds;

			totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

			cout << "Total Seconds: " << totalSeconds << endl;
		}
};

int main() {
	Timeconverter obj;
	int choice;

	cout << "============================" << endl;
	cout << "       TIME CONVERTER       " << endl;
	cout << "============================" << endl;

	cout << "1. Seconds to HH:MM:SS" << endl;
	cout << "2. HH:MM:SS to Seconds" << endl;

	cout << "\nEnter Your Choice: ";
	cin >> choice;

	if (choice == 1) {
		obj.secondtotime();
	} else if (choice == 2) {
		obj.timeToSeconds();
	} else {
		cout << "Invalid Choice..!" << endl;
	}

	return 0;
}
