#include "scheduler.h"

Scheduler::Scheduler()
{
	tree = new AVLTree;
}

void Scheduler::run()
{
	while (true) {
		menu();
        string timeSlot, employeeName;
        int choice;
        Schedule* result = nullptr;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter time slot (e.g. 9:00am-10:00am): ";
            cin >> timeSlot;
            cout << "Enter employee name: ";
            cin >> employeeName;
            result = tree->insert(tree->getRoot(), timeSlot, employeeName);

            if (result != nullptr) {
                tree->setRoot(result);
                cout << "\nEmployee schedule added successfully!" << endl;
            }
            break;
        case 2:
            cout << "\nEnter time slot to remove (e.g. 9:00am-10:00am): ";
            cin >> timeSlot;
            tree->remove(tree->getRoot(), timeSlot);
            cout << "Employee schedule removed successfully!" << endl;
            break;
        case 3:
            cout << "Enter time slot to search (e.g. 9:00am-10:00am): ";
            cin >> timeSlot;
            result = tree->search(timeSlot);
            if (result == nullptr) {
                cout << "\nEmployee schedule not found!" << endl;
            }
            else {
                cout << "\nEmployee schedule found\n___________________________________" << endl;
                cout << "Time Slot: " << result->timeSlot << endl;
                cout << "Employee Name: " << result->employeeName << endl;
            }
            break;
        case 4:
            return;
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
	}
}

void Scheduler::menu()
{
    cout << "\n====================================" << endl;
    cout << "   Employee Schedule Management" << endl;
    cout << "====================================" << endl;
    cout << "1. Add Employee Schedule" << endl;
    cout << "2. Remove Employee Schedule" << endl;
    cout << "3. Search for Employee Schedule" << endl;
    cout << "4. Exit" << endl;
    cout << "> ";
}
