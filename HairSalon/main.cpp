// HairSalon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "customer_mgt.h"
#include "appointment_mgt.h"
#include "inventory_manager.h"
#include "sale_management.h"
#include "waiting_list.h"
#include "loyalty_program_mgt.h"
#include "scheduler.h"
#include "performance_tracker.h"

using namespace std;

void displayMainMenu();

int main()
{

	int choice;
	while(true) {
		displayMainMenu();
		cin >> choice;
		if (choice == 1) {
			CustomerManagement* customer_management= new CustomerManagement();
			customer_management->run();
		}else if(choice==2){
			AppointmentScheduler* appointment = new AppointmentScheduler();
			appointment->run();
		}
		else if (choice == 3) {
			InventoryManager* inventory_manager = new InventoryManager();
			inventory_manager->run();
		}
		else if (choice == 4) {
			SalesManagement* sales_mgt = new SalesManagement();
			sales_mgt->run();
		}
		else if (choice == 5) {
			WaitingList* waitlist = new WaitingList();
			waitlist->run();
		}
		else if (choice == 6) {
			LoyaltyProgram* loyalty_program = new LoyaltyProgram();
			loyalty_program->run();
		}
		else if (choice == 7) {
			Scheduler* scheduler = new Scheduler();
			scheduler->run();
		}
		else if (choice == 8) {
			PerformanceTracker* tracker = new PerformanceTracker();
			tracker->run();
		}
		else if (choice == 9) {
			cout << "\nThank you. Bye" << endl;
			return 1;
		}
		else {
			cout << "Invalid choice. Please" << endl;
		}
	}
}

void displayMainMenu() {
	cout << "=========================" << endl;
	cout << "  HAIR SALON MANAGEMENT" << endl;
	cout << "=========================" << endl;
	cout << "\t1. Customer Management" << endl;
	cout << "\t2. Appointment Scheduling" << endl;
	cout << "\t3. Inventory Management" << endl;
	cout << "\t4. Sales Management" << endl;
	cout << "\t5. Waiting List" << endl;
	cout << "\t6. Loyalty Program" << endl;
	cout << "\t7. Employee Schedule" << endl;
	cout << "\t8. Performance Tracker" << endl;
	cout << "\t9. Exit" << endl;
	cout << "\t>";
}