#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class Appliance {
private:
    string name;
    double powerRating;   // Watts
    double usageHours;    // Hours per day

public:
    Appliance() {
        name = "";
        powerRating = 0;
        usageHours = 0;
    }

    Appliance(string n, double p, double u) {
        name = n;
        powerRating = p;
        usageHours = u;
    }

    string getName() const { return name; }
    double getPower() const { return powerRating; }
    double getUsage() const { return usageHours; }

    double calculateEnergy() const {
        return (powerRating * usageHours) / 1000.0; // kWh
    }

    void display() const {
        cout << left << setw(15) << name
             << setw(12) << powerRating
             << setw(12) << usageHours
             << setw(12) << fixed << setprecision(2)
             << calculateEnergy() << endl;
    }
};

vector<Appliance> appliances;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void registerAppliance() {
    string name;
    double power;
    double hours;

    cout << "Enter appliance name: ";
    clearInput();
    getline(cin, name);

    cout << "Enter power rating (Watts): ";
    cin >> power;

    cout << "Enter daily usage hours: ";
    cin >> hours;

    appliances.push_back(Appliance(name, power, hours));
    cout << "Appliance registered successfully!\n";
}

void viewAppliances() {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(15) << "Name"
         << setw(12) << "Power(W)"
         << setw(12) << "Hours"
         << setw(12) << "Energy(kWh)" << endl;
    cout << "-------------------------------------------------------------\n";

    for (size_t i = 0; i < appliances.size(); i++) {
        appliances[i].display();
    }
}

void menu() {
    int choice;

    do {
        cout << "\n===== ELECTRICAL LOAD MONITORING SYSTEM =====\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                registerAppliance();
                break;
            case 2:
                viewAppliances();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);
}

int main() {
    cout << "Electrical Load Monitoring System Initialized.\n";
    menu();
    return 0;
}