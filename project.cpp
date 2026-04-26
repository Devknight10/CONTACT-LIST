#include <iostream>
#include <vector>
using namespace std;
class Contact {
public:
 string name, phone, email, priority;
 Contact(string n, string p, string e, string pr) {
 name = n;
 phone = p;
 email = e;
 priority = pr;
 }
};
class ContactManager {
private:
 vector<Contact> contacts;
public:
 void addContact(string name, string phone, string email, string priority) {
 contacts.push_back(Contact(name, phone, email, priority));
 cout << "\nContact Added Successfully\n";
 }
 void viewContacts() {
 if (contacts.empty()) {
 cout << "\nNo Contacts Found\n";
 return;
 }
 cout << "\n========== CONTACT LIST ==========\n";
 for (auto c : contacts) {
 cout << "\n------------------------------\n";
 cout << "Name : " << c.name << endl;
 cout << "Phone : " << c.phone << endl;
 cout << "Email : " << c.email << endl;
 cout << "Priority : " << c.priority << endl;
 cout << "------------------------------\n";
 }
 }
 // SMART SEARCH (partial match)
 void searchContact(string key) {
 bool found = false;
 for (auto c : contacts) {
 if (c.name.find(key) != string::npos) {
 cout << "\n----- Contact Found -----\n";
 cout << "Name : " << c.name << endl;
 cout << "Phone : " << c.phone << endl;
 cout << "Email : " << c.email << endl;
 cout << "Priority : " << c.priority << endl;
 cout << "-------------------------\n";
 found = true;
 }
 }
 if (!found)
 cout << "\nContact Not Found\n";
 }
 void updateContact(string name, string phone, string email, string priority) {
 for (auto &c : contacts) {
 if (c.name == name) {
 c.phone = phone;
 c.email = email;
 c.priority = priority;
 cout << "\nContact Updated\n";
 return;
 }
 }
 cout << "\nContact Not Found\n";
 }
 void deleteContact(string name) {
 for (int i = 0; i < contacts.size(); i++) {
 if (contacts[i].name == name) {
 contacts.erase(contacts.begin() + i);
 cout << "\nContact Deleted\n";
 return;
 }
 }
 cout << "\nContact Not Found\n";
 }
};
int main() {
 ContactManager cm;
 int choice;
 string name, phone, email, priority;
 // PASSWORD SECURITY
 string password = "contacts@4287", input;
 cout << "Enter Password: ";
 cin >> input;
 if (input != password) {
 cout << "Access Denied!\n";
 return 0;
 }
 cout << "\nAccess Granted!\n";
 while (true) {
 cout << "\n==============================\n";
 cout << " CONTACT MANAGEMENT SYSTEM \n";
 cout << "==============================\n";
 cout << "1. Add Contact\n";
 cout << "2. View Contacts\n";
 cout << "3. Search Contact\n";
 cout << "4. Update Contact\n";
 cout << "5. Delete Contact\n";
 cout << "6. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "\nEnter Name: ";
 cin >> name;
 cout << "Enter Phone: ";
 cin >> phone;
 cout << "Enter Email: ";
 cin >> email;
 cout << "Enter Priority (High/Medium/Low): ";
 cin >> priority;
 cm.addContact(name, phone, email, priority);
 break;
 case 2:
 cm.viewContacts();
 break;
 case 3:
 cout << "\nEnter Name to search: ";
 cin >> name;
 cm.searchContact(name);
 break;
 case 4:
 cout << "\nEnter Name to update: ";
 cin >> name;
 cout << "Enter New Phone: ";
 cin >> phone;
 cout << "Enter New Email: ";
 cin >> email;
 cout << "Enter New Priority: ";
 cin >> priority;
 cm.updateContact(name, phone, email, priority);
 break;
 case 5:
 cout << "\nEnter Name to delete: ";
 cin >> name;
 cm.deleteContact(name);
 break;
 case 6:
 cout << "\nExiting Program...\n";
 return 0;
 default:
 cout << "\nInvalid Choice\n";
 }
 }
}