#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
	station_nm(nm), my_loc(loc) {
}

ostream& operator<<(std::ostream& os, const GPS& gps) {
	cout << "Latitude: " << gps.latitude << ", Longitude: " <<
		gps.longitude << endl;
	return os;
}

ostream& operator<<(std::ostream& os, const Weather& w) {
	cout << "Weather station " << w.get_name() << " report" <<
		endl << "Weather is ";
	if (w.rating == UNRATED) cout << "unrated ";
	else if (w.rating == BAD) cout << "bad ";
	else if (w.rating == OK) cout << "ok ";
	else if (w.rating == GOOD) cout << "good ";
	else cout << "invalid "; 
	cout << "at " << w.my_loc << endl;
	return os;
}

string Weather::get_name() const {
	return station_nm;
}

int Weather::get_rating() const {
	return rating;
}
void Weather::set_rating(int new_rating) {
	rating = new_rating;
}
