#pragma once

#include "appointment.h"
#include "database.h"
#include <iomanip>


class AppointmentScheduler {
private:
	priority_queue<Appointment, vector<Appointment>, greater<Appointment>> appointments;
	string filename;
	Database database;

private:
	void addAppointment();
	void cancelAppointment();
	void searchAppointment();
	void viewAppointments();
	void saveAppointments();
	void readAppointments();
	bool isSlotAvailable(const string& date, const string& time);
	void menu();

public:
	AppointmentScheduler() {
		filename = "appointments.txt";
		std::ifstream infile(filename);
		if (!infile.good()){
			std::ofstream outfile(filename);
			outfile.close();
		}
		infile.close();
		readAppointments();
	}
	void run();
};
