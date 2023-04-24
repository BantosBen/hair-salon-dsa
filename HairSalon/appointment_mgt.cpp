#include "appointment_mgt.h"

void AppointmentScheduler::menu() {
	cout << "1. Add appointment\n";
	cout << "2. Cancel appointment\n";
	cout << "3. Search appointment\n";
	cout << "4. View appointments\n";
	cout << "5. Exit\n";
	cout << "> ";
}

void AppointmentScheduler::run() {

	cout << "\nAppointment Scheduler Menu\n";
	cout << "--------------------------\n";
	int choice = 0;
	while (true) {
		menu();
		cin >> choice;
		cin.ignore(); // ignore newline character

		switch (choice) {
		case 1:
			addAppointment();
			break;
		case 2:
			cancelAppointment();
			break;
		case 3:
			searchAppointment();
			break;
		case 4:
			viewAppointments();
			break;
		case 5:
			return;
		default:
			cout << "Invalid choice, please try again.\n";
			break;
		}
	}
}

void AppointmentScheduler::addAppointment() {
	// Get customer name
	string name;
	cout << "Enter customer name: ";
	getline(cin, name);

	// Get date and time
	string date, time;
	cout << "Enter date (MM/DD/YYYY): ";
	getline(cin, date);
	cout << "Enter time (HH:MM): ";
	getline(cin, time);

	// Get service
	string service;
	cout << "Enter service: ";
	getline(cin, service);

	if (isSlotAvailable(date, time)) {
		// Create appointment and add to priority queue
		Appointment appointment(name, date, time, service);
		appointments.push(appointment);

		cout << "\nAppointment added successfully." << endl;
		saveAppointments();
	}
	else {
		cout << "\nFailed! Slot is taken already." << endl;
	}
}

// Check if an appointment slot is available for a given date and time
bool AppointmentScheduler::isSlotAvailable(const string& date, const string& time) {
	priority_queue<Appointment, vector<Appointment>, greater<Appointment>> temp;
	while (!appointments.empty()) {
		Appointment appointment = appointments.top();
		appointments.pop();
		if (appointment.getDate() == date && appointment.getTime() == time) {
			return false;
		}
		temp.push(appointment);
	}
	appointments = temp;
	return true;
}
void AppointmentScheduler::cancelAppointment() {
	priority_queue<Appointment, vector<Appointment>, greater<Appointment>> temp;

	// Get date and time
	string date, time;
	cout << "Enter date (MM/DD/YYYY): ";
	getline(cin, date);
	cout << "Enter time (HH:MM): ";
	getline(cin, time);

	// Find appointment with matching date and time
	bool found = false;
	while (!appointments.empty()) {
		Appointment top = appointments.top();
		if (top.getDate() == date && top.getTime() == time) {
			found = true;
			appointments.pop();
			cout << "\nAppointment for " << top.getCustomerName() << " at " << date << " " << time << " has been cancelled.\n" << endl;
			saveAppointments();
			break;
		}
		else {
			temp.push(top);
			appointments.pop();
		}
	}

	// If appointment not found, display message
	if (!found) {
		cout << "\nNo appointment found at " << date << " " << time << ".\n" << endl;
	}

	// Move appointments from temporary priority queue back to original priority queue
	while (!temp.empty()) {
		Appointment top = temp.top();
		appointments.push(top);
		temp.pop();
	}
}

void AppointmentScheduler::searchAppointment() {
	// Get date and time
	string date, time;
	cout << "Enter date (MM/DD/YYYY): ";
	getline(cin, date);
	cout << "Enter time (HH:MM): ";
	getline(cin, time);

	// Search for appointment with matching date and time
	bool found = false;
	priority_queue<Appointment, vector<Appointment>, greater<Appointment>> copy = appointments;
	while (!copy.empty()) {
		Appointment top = copy.top();
		if (top.getDate() == date && top.getTime() == time) {
			found = true;
			cout << "\nAppointment for " << top.getCustomerName() << " at " << date << " " << time << " is scheduled for " << top.getService() << ".\n" << endl;
			break;
		}
		copy.pop();
	}

	// If appointment not found, display message
	if (!found) {
		cout << "\nNo appointment found at " << date << " " << time << ".\n" << endl;
	}
}

void AppointmentScheduler::viewAppointments() {
	priority_queue<Appointment, vector<Appointment>, greater<Appointment>> temp;
	if (!appointments.empty()) {
		cout << "|----------------------|----------------------|----------------------|\n";
		cout << "| Client Name          | Appt. Date Time      | Booked Service       |\n";
		cout << "|----------------------|----------------------|----------------------|\n";
		while (!appointments.empty()) {
			Appointment appointment = appointments.top();
			appointments.pop();
			cout << "| " << left << setw(20) << appointment.getCustomerName() << " | ";
			cout << left << setw(20) << (appointment.getDate() + " " + appointment.getTime()) << " | ";
			cout << left << setw(20) << appointment.getService() << " |\n";
			cout << "|----------------------|----------------------|----------------------|\n";
			temp.push(appointment);
		}
		appointments = temp;
	}
	else {
		cout << "\nThere are no appointments\n" << endl;
	}
}


void AppointmentScheduler::saveAppointments() {
	database.storeAppointmentsToFile(appointments, filename);
	readAppointments();
}

void AppointmentScheduler::readAppointments() {
	database.readAppointmentsFromFile(appointments, filename);
}