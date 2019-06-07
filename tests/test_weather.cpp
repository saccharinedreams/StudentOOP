#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"

using namespace std;

string get_input_file() {
	string filenm;
	cout << "Input the name of the new readings file:\n";
	cin >> filenm;
	return filenm;
}

void get_wreadings(Weather& w) {
	ifstream rfile(get_input_file());
	while(!rfile) {
		cout << "Could not read input file" << endl;
		rfile.close();
		rfile.open(get_input_file());
	}
	int m, d, y;
	double temp, hum, ws;
	while (rfile >> m >> d >> y >> temp >> hum >> ws) {
		WReading wr = WReading(Date(d, m, y), temp, hum, ws);
		w.add_reading(wr);
	}
	rfile.close();
}


int main() {
	Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

	string filenm;
	cout << "Input the name of the new readings file:\n";
	cin >> filenm;

	get_wreadings(irkutsk);

	cout << irkutsk << endl;
}