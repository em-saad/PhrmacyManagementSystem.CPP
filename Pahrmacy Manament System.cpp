#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


//Global Veriables
	string customerName, medicineName;
	int quantity;
	float price, total = 0;
	int choice;
	int costomer=0;
	int supplier=0;
	int medicine=0;
	int bill=0;
	
// Function prototypes
void welcome();
void purchaseMedicine();
void addCustomer();
void addMedicine();
void addSupplier();
void removeCustomer();
void removeMedicine();
void removeSupplier();
void updateCustomer();
void updateMedicine();
void updateSupplier();
void generateBill();
void displayMedicines();
void displayCustomers();
void displaySuppliers();
void menu();
void about();
void bill_txt();
void report();
int main() {
welcome();
	cout << "--------------------------------------------------\n";
		cout << "             PHARMACY MANAGEMENT SYSTEM           \n";
		cout << "--------------------------------------------------\n";
	do {
	
menu();
		switch (choice) {
		case 1:
			addCustomer();
			break;
		case 2:
			addMedicine();
			break;
		case 3:
			addSupplier();
			break;
		case 4:
			removeCustomer();
			break;
		case 5:
			removeMedicine();
			break;
		case 6:
			removeSupplier();
			break;
		case 7:
			updateCustomer();
			break;
		case 8:
			updateMedicine();
			break;
		case 9:
			updateSupplier();
			break;
		case 10:
			generateBill();
			break;
		case 11:
			displayMedicines();
			break;
		case 12:
			displayCustomers();
			break;
		case 13:
			displaySuppliers();
			break;
			case 14:
				report();
				break;
				case 15:
					purchaseMedicine();
					break;
					case 16:
						about();
						break;
		case 0:
			cout << "Exiting program...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}

	} while (choice != 0);

	return 0;
}

void addCustomer() {
	ofstream file("customers.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	string name, address, phone;
	cout << "Enter customer name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter customer address: ";
	getline(cin, address);
	cout << "Enter customer phone number: ";
	getline(cin, phone);

	file << "Name:"<<name << "Adress:" << address << "Phone:" << phone << "\n";
	file.close();
	cout << "Customer added successfully.\n";
	
}

void addMedicine() {
	ofstream file("medicines.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	string name, manufacturer;
	int quantity;
	float price;
	cout << "Enter medicine name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter manufacturer name: ";
	getline(cin, manufacturer);
	cout << "Enter quantity: ";
	cin >> quantity;
	cout << "Enter price per unit: ";
	cin >> price;

	file <<"Name:" <<name <<"Manufacture:" << manufacturer << "Quantity" << quantity << "Price" << price << "\n";
	file.close();
	cout << "Medicine added successfully.\n";
	medicine++;
}

void addSupplier() {
	ofstream file("suppliers.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	string name, address, phone;
	cout << "Enter supplier name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter supplier address: ";
	getline(cin, address);
	cout << "Enter supplier phone number: ";
	getline(cin, phone);

	file << "Name:"<<name << "Adress:" << address << "Phone:" << phone << "\n";
	file.close();
	cout << "Supplier added successfully.\n";
	 costomer++;
}

void removeCustomer() {
	string name;
	cout << "Enter customer name to remove: ";
	cin.ignore();
	getline(cin, name);

	ifstream inFile("customers.txt");
	ofstream outFile("temp.txt");

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(name) == string::npos) {
			outFile << line << endl;
		}
		else {
			found = true;
		}
	}

	inFile.close();
	outFile.close();

	remove("customers.txt");
	rename("temp.txt", "customers.txt");

	if (found) {
		cout << "Customer removed successfully.\n";
	}
	else {
		cout << "Customer not found.\n";
	}
	costomer--;
}

void removeMedicine() {
	string name;
	cout << "Enter medicine name to remove: ";
	cin.ignore();
	getline(cin, name);

	ifstream inFile("medicines.txt");
	ofstream outFile("temp.txt");

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(name) == string::npos) {
			outFile << line << endl;
		}
		else {
			found = true;
		}
	}

	inFile.close();
	outFile.close();

	remove("medicines.txt");
	rename("temp.txt", "medicines.txt");

	if (found) {
		cout << "Medicine removed successfully.\n";
	}
	else {
		cout << "Medicine not found.\n";
	}
	medicine--;
}

void removeSupplier() {
	string name;
	cout << "Enter supplier name to remove: ";
	cin.ignore();
	getline(cin, name);

	ifstream inFile("suppliers.txt");
	ofstream outFile("temp.txt");

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(name) == string::npos) {
			outFile << line << endl;
		}
		else {
			found = true;
		}
	}

	inFile.close();
	outFile.close();

	remove("suppliers.txt");
	rename("temp.txt", "suppliers.txt");

	if (found) {
		cout << "Supplier removed successfully.\n";
	}
	else {
		cout << "Supplier not found.\n";
	}
	supplier--;
}

void updateCustomer() {
	string name, newName, newAddress, newPhone;
	cout << "Enter customer name to update: ";
	cin.ignore();
	getline(cin, name);

	ifstream inFile("customers.txt");
	ofstream outFile("temp.txt");

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(name) == string::npos) {
			outFile << line << endl;
		}
		else {
			found = true;
			cout << "Enter new name: ";
			getline(cin, newName);
			cout << "Enter new address: ";
			getline(cin, newAddress);
			cout << "Enter new phone number: ";
			getline(cin, newPhone);
			outFile << "Name:"<<newName << "Adress:" << newAddress << "Phone" << newPhone << endl;
		}
	}

	inFile.close();
	outFile.close();

	remove("customers.txt");
	rename("temp.txt", "customers.txt");

	if (found) {
		cout << "Customer updated successfully.\n";
	}
	else {
		cout << "Customer not found.\n";
	}
}

void updateMedicine() {
	string name, newName, newManufacturer;
	int newQuantity;
	float newPrice;
	cout << "Enter medicine name to update: ";
	cin.ignore();
	getline(cin, name);

	ifstream inFile("medicines.txt");
	ofstream outFile("temp.txt");

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(name) == string::npos) {
			outFile << line << endl;
		}
		else {
			found = true;
			cout << "Enter new name: ";
			getline(cin, newName);
			cout << "Enter new manufacturer: ";
			getline(cin, newManufacturer);
			cout << "Enter new quantity: ";
			cin >> newQuantity;
			cout << "Enter new price per unit: ";
			cin >> newPrice;
			outFile << "Name:"<<newName << "Manufacture:" << newManufacturer << "Quantity:" << newQuantity << "Price:" << newPrice << endl;
		}
	}

	inFile.close();
	outFile.close();

	remove("medicines.txt");
	rename("temp.txt", "medicines.txt");

	if (found) {
		cout << "Medicine updated successfully.\n";
	}
	else {
		cout << "Medicine not found.\n";
	}
}

void updateSupplier() {
	string name, newName, newAddress, newPhone;
	cout << "Enter supplier name to update: ";
	cin.ignore();
	getline(cin, name);

	ifstream inFile("suppliers.txt");
	ofstream outFile("temp.txt");

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(name) == string::npos) {
			outFile << line << endl;
		}
		else {
			found = true;
			cout << "Enter new name: ";
			getline(cin, newName);
			cout << "Enter new address: ";
			getline(cin, newAddress);
			cout << "Enter new phone number: ";
			getline(cin, newPhone);
			outFile <<"Name:" <<newName << "Adress:" << newAddress << "Phone:" << newPhone << endl;
		}
	}

	inFile.close();
	outFile.close();

	remove("suppliers.txt");
	rename("temp.txt", "suppliers.txt");

	if (found) {
		cout << "Supplier updated successfully.\n";
	}
	else {
		cout << "Supplier not found.\n";
	}
	supplier--;
}

void generateBill() {


	cout << "Enter customer name: ";
	cin.ignore();
	getline(cin, customerName);

	cout << "Enter number of medicines purchased: ";
	int numMedicines;
	cin >> numMedicines;

	vector<pair<string, float>> medicines;

	for (int i = 0; i < numMedicines; ++i) {
		cout << "Enter medicine name: ";
		cin.ignore();
		getline(cin, medicineName);
		cout << "Enter quantity: ";
		cin >> quantity;
		cout << "Enter price per unit: ";
		cin >> price;

		total += quantity * price;
		medicines.push_back(make_pair(medicineName, quantity * price));
		bill_txt();
		bill++;
	}

	cout << "\n\n";

	cout << "--------------------------------------------------\n";
	cout << "                     INVOICE                      \n";
	cout << "--------------------------------------------------\n";
	cout << "Customer Name: " << customerName << endl;
	cout << "--------------------------------------------------\n";
	cout << setw(20) << left << "Medicine" << setw(10) << right << "Quantity" << setw(15) << right << "Price" << endl;
	cout << "--------------------------------------------------\n";

	for (const auto& med : medicines) {
		cout << setw(20) << left << med.first << setw(10) << right << 1 << setw(15) << right << fixed << setprecision(2) << med.second << endl;
	}

	cout << "--------------------------------------------------\n";
	cout << setw(30) << left << "Total Amount:" << setw(15) << right << total << endl;
	cout << "--------------------------------------------------\n";
	
}
void bill_txt(){
	ofstream file("bill.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	
	

	file << "Name:"<<customerName << endl <<"Medicine:" <<medicineName << endl << "Quantity:"<< quantity << endl <<"Price:"<< price <<endl<<"Total:"<< total<<"\n";
	file.close();
}


void displayMedicines() {
	ifstream file("medicines.txt");
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	cout << "\nMedicines List:\n";
	cout << "--------------------------------------------------------\n";
	cout << setw(20) << left << "Medicine Name" << setw(20) << left << "Manufacturer" << setw(10) << left << "Quantity" << setw(10) << left << "Price" << endl;
	cout << "--------------------------------------------------------\n";

	string name, manufacturer, quantity, price;
	while (getline(file, name, ',') && getline(file, manufacturer, ',') && getline(file, quantity, ',') && getline(file, price)) {
		cout << setw(20) << left << name << setw(20) << left << manufacturer << setw(10) << left << quantity << setw(10) << left << price << endl;
	}

	file.close();
}

void displayCustomers() {
	ifstream file("customers.txt");
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	cout << "\nCustomers List:\n";
	cout << "----------------------------------------------------------------\n";
	cout << setw(20) << left << "Name" << setw(30) << left << "Address" << setw(15) << left << "Phone Number" << endl;
	cout << "----------------------------------------------------------------\n";

	string name, address, phone;
	while (getline(file, name, ',') && getline(file, address, ',') && getline(file, phone)) {
		cout << setw(20) << left << name << setw(30) << left << address << setw(15) << left << phone << endl;
	}

	file.close();
}

void displaySuppliers() {
	ifstream file("suppliers.txt");
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	cout << "\nSuppliers List:\n";
	cout << "----------------------------------------------------------------\n";
	cout << setw(20) << left << "Name" << setw(30) << left << "Address" << setw(15) << left << "Phone Number" << endl;
	cout << "----------------------------------------------------------------\n";

	string name, address, phone;
	while (getline(file, name, ',') && getline(file, address, ',') && getline(file, phone)) {
		cout << setw(20) << left << name << setw(30) << left << address << setw(15) << left << phone << endl;
	}

	file.close();
}

void menu(){
	
		cout << "\n<= Menu =>\n\n";
		cout << "1. Add Customer\n";
		cout << "2. Add Medicine\n";
		cout << "3. Add Supplier\n";
		cout << "4. Remove Customer\n";
		cout << "5. Remove Medicine\n";
		cout << "6. Remove Supplier\n";
		cout << "7. Update Customer\n";
		cout << "8. Update Medicine\n";
		cout << "9. Update Supplier\n";
		cout << "10. Generate/Store Bill\n";
		cout << "11. Display Medicines\n";
		cout << "12. Display Customers\n";
		cout << "13. Display Suppliers\n";
		cout<<"14.Display Report\n";
		cout<<"15.Purchase Medicine\n";
		cout<<"16.About Us\n";
		cout<<"0.Exit!"<<endl;
	
		cout << "Enter your choice: ";
		cin >> choice;
}

void about(){
		cout << "--------------------------------------------------\n";
		cout << "             PHARMACY MANAGEMENT SYSTEM           \n";
		cout << "--------------------------------------------------\n";
		cout<<endl<<endl;
			cout << "--------------------------------------------------\n";
		cout << "            By:Muhammad Saad          \n";
		cout << "--------------------------------------------------\n";
			cout << "--------------------------------------------------\n";
		cout << "             PF FINAL PROJECT           \n";
		cout << "--------------------------------------------------\n";
}

void welcome(){
	cout << "--------------------------------------------------\n";
		cout << "             PHARMACY MANAGEMENT SYSTEM           \n";
		cout << "--------------------------------------------------\n";
		cout<<endl<<endl;
			cout << "--------------------------------------------------\n";
		cout << "                    Welcome         \n";
		cout << "--------------------------------------------------\n";
			cout << "--------------------------------------------------\n";
		cout << "             PF FINAL PROJECT           \n";
		cout << "--------------------------------------------------\n";
}
void report(){
		ofstream file("report.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	

	file<<"--------------------------------------------------------------------"<<endl;
	file<<"                            Report                                  ";
	file<<"Customers          Suppliers          Medicines          Bill Generated          Profit"<<endl;
	file<<costomer<<"            "<<supplier <<"    "<<medicine<<"  "<<bill<<"                 "<<total;
	file<<endl;
		file<<"--------------------------------------------------------------------"<<endl;
		
		
	
	file.close();
}


void updateMedicineQuantity(const string& medicineName, int purchasedQuantity) {
    ifstream inFile("medicines.txt");
    ofstream outFile("temp.txt");

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.find(medicineName) != string::npos) {
            found = true;
            int currentQuantity;
            // Extracting the current quantity
            size_t pos = line.find("Quantity:");
            if (pos != string::npos) {
                pos += string("Quantity:").length();
                currentQuantity = stoi(line.substr(pos));
                // If available quantity is less than purchased quantity
                if (currentQuantity < purchasedQuantity) {
                    cout << "Not enough quantity available for " << medicineName << ".\n";
                    outFile << line << endl;
                    continue;
                }
                // Update the quantity
                currentQuantity -= purchasedQuantity;
                line = "Name:" + medicineName + "Manufacture:" + line.substr(21, pos - 23) + "Quantity:" + to_string(currentQuantity) + "Price:" + line.substr(pos);
            }
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    remove("medicines.txt");
    rename("temp.txt", "medicines.txt");

    if (found) {
        cout << "Medicine quantity updated successfully.\n";
    } else {
        cout << "Medicine not found.\n";
    }
}

void purchaseMedicine() {
    cout << "Enter medicine name: ";
    cin.ignore();
    getline(cin, medicineName);
    cout << "Enter quantity: ";
    cin >> quantity;

    // Update quantity in the medicines file
    updateMedicineQuantity(medicineName, quantity);
}
