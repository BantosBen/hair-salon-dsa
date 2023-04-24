#include "performance_tracker.h"


PerformanceTracker::PerformanceTracker() {
    database.loadEmployeeMetricsFromFile(employeeMetrics, filename);
}
void PerformanceTracker::addEmployee(string name, double points) {
    if (employeeMetrics.find(name) == employeeMetrics.end()) {
        employeeMetrics.insert(make_pair(name, points));
    }
    else {
        employeeMetrics[name] += points;
    }

    database.saveEmployeeMetricsToFile(employeeMetrics, filename);
}

void PerformanceTracker::removeEmployee(string name) {
    employeeMetrics.erase(name);
    database.saveEmployeeMetricsToFile(employeeMetrics, filename);
}

void PerformanceTracker::printMetrics() {
    if (!employeeMetrics.empty()) {
        cout << "|----------------------|----------------------|\n";
        cout << "| Employee Name        | Total Points         |\n";
        cout << "|----------------------|----------------------|\n";
        for (auto const& pair : employeeMetrics) {
            cout << "| " << left << setw(20) << pair.first << " | ";
            cout << left << setw(20) << pair.second << " | \n";
            cout << "|----------------------|----------------------|\n";
        }
    }
    else {
        cout << "\nNo employee metrics" << endl;
    }
}

void PerformanceTracker::run() {
    while (true) {
        menu();

        int choice;
        string name;
        double points;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Employee name: ";
            cin >> name;
            cout << "\nEnter Points: ";
            cin >> points;
            addEmployee(name, points);
            cout << "\nPerformance Tracker updated successfully" << endl;
            break;
        case 2:
            cout << "\nEnter Employee name: ";
            cin >> name;
            removeEmployee(name);
            cout << "\nPerformance Tracker updated successfully" << endl;
            break;
        case 3:
            printMetrics();
            break;
        case 4:
            return;
        default:
            cout << "\nInvalid choice. Please try again later." << endl;
            break;
        }
    }
}

void PerformanceTracker::menu() {
    cout << "\n====================================" << endl;
    cout << "   Performance Tracker Management" << endl;
    cout << "====================================" << endl;
    cout << "1. Add employee performance" << endl;
    cout << "2. Remove employee" << endl;
    cout << "3. Diaplay all employees" << endl;
    cout << "4. Exit" << endl;
    cout << "> ";
}