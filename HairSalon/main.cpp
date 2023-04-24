// HairSalon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "customer_mgt.h"
#include "appointment_mgt.h"
#include "inventory_manager.h"
#include "sale_management.h"
#include "waiting_list.h"
#include "loyalty_program_mgt.h"

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
	cout << "1. Customer Management" << endl;
	cout << "2. Appointment Scheduling" << endl;
	cout << "3. Inventory Management" << endl;
	cout << "4. Sales Management" << endl;
	cout << "5. Waiting List" << endl;
	cout << "6. Loyalty Program" << endl;
	cout << "7. Exit" << endl;
	cout << ">";
}