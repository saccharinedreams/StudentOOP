#include <iostream>
#include <string>
#include "weather.h"

using namespace std;


const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
	: width(w), height(h)
{
	filename = flnm;
	image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
	image_buf = new char;
	copy_fields(img2);
}

Image::~Image() {
	if (!image_buf) delete image_buf;
}

Image& Image::operator=(const Image& img2) {
	if (this != &img2) {
		if (!image_buf) delete image_buf;
		image_buf = new char;
		copy_fields(img2);
	}
	return *this;
}

int Image::image_sz() {
	return width * height;
}


void Image::copy_fields(const Image& img2) {
	*image_buf = *img2.image_buf;
	height = img2.get_height();
	width = img2.get_width();
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
	return "Displaying image " + s;
}

ostream& operator<<(ostream& os, const Date& date) {
	cout << "Date: " << date.month << "/" << date.day << "/"
		<< date.year << endl;
	return os;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

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

ostream& operator<<(std::ostream& os, const WReading& wr) {
	cout << wr.date << "Temperature: " << wr.temperature <<
		"\nHumidity: " << wr.humidity << "\nWindspeed: " << wr.windspeed
		<< endl;
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
	for (WReading wr : w.wreadings) {
		cout << wr;
	}
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

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

/*
double WReading::get_tempC() {
	return temperature;
}
*/

double WReading::get_tempF() {
	return (temperature * C_TO_F) + 32;
}