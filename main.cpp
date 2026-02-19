#include <iostream>
#include <vector>
#include <iomanip>

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

int main() {
    cout << "Electrical Load Monitoring System Initialized.\n";
    return 0;
}

