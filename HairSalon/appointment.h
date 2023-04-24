#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std;

class Appointment {
private:
	string customerName;
	string date;
	string time;
	string service;

public:
	Appointment() {}
	Appointment(string _name, string _date, string _time, string _service) {
		customerName = _name;
		date = _date;
		time = _time;
		service = _service;
	}

	// Getters and setters
	string getCustomerName() { return customerName; }
	void setCustomerName(string _name) { customerName = _name; }

	string getDate(){ return date; }
	void setDate(string _date) { date = _date; }

	string getTime() { return time; }
	void setTime(string& _time) { time = _time; }

	string getService() { return service; }
	void setService(string _service) {service = _service; }

	// Operator overloading for comparison
	bool operator>(const Appointment& other) const {
		if (date != other.date) {
			return date < other.date;
		}
		return time < other.time;
	}

	friend ostream& operator<<(ostream& os, const Appointment& appointment) {
		os << "Customer Name: " << appointment.customerName << endl;
		os << "Date: " << appointment.date << endl;
		os << "Time: " << appointment.time << endl;
		os << "Service: " << appointment.service << endl;
		return os;
	}
};
