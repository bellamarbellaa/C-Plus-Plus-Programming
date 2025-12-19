#include <iostream>
#include <string>
using namespace std;

class GravitationalForce {
private:
    string name1;
    string name2;
    const double G = 6.674E-11; // gravitational constant
    double m1;
    double m2;
    double r;

public:
    // Function declarations only
    void SetObject1Name(string firstObjectName);
    void SetObject2Name(string secondObjectName);
    void SetObject1Mass(double mass1);
    void SetObject2Mass(double mass2);
    void SetDistance(double distance);

    string GetObject1Name() const;
    string GetObject2Name() const;
    double GetObject1Mass() const;
    double GetObject2Mass() const;
    double GetDistance() const;

    double CalculateGravitationalForce() const;
    void PrintResult() const;
};

// ===== Function definitions outside the class =====

void GravitationalForce::SetObject1Name(string firstObjectName) {
    name1 = firstObjectName;
}

void GravitationalForce::SetObject2Name(string secondObjectName) {
    name2 = secondObjectName;
}

void GravitationalForce::SetObject1Mass(double mass1) {
    m1 = mass1;
}

void GravitationalForce::SetObject2Mass(double mass2) {
    m2 = mass2;
}

void GravitationalForce::SetDistance(double distance) {
    r = distance;
}

string GravitationalForce::GetObject1Name() const {
    return name1;
}

string GravitationalForce::GetObject2Name() const {
    return name2;
}

double GravitationalForce::GetObject1Mass() const {
    return m1;
}

double GravitationalForce::GetObject2Mass() const {
    return m2;
}

double GravitationalForce::GetDistance() const {
    return r;
}

double GravitationalForce::CalculateGravitationalForce() const {
    return (G * m1 * m2) / (r * r);
}

void GravitationalForce::PrintResult() const {
    cout << "The gravitational force between " << name1
         << " and " << name2 << " is: "
         << CalculateGravitationalForce() << " N" << endl;
}

// ===== Main program =====
int main() {
    GravitationalForce g;
    string name1, name2;
    double mass1, mass2, distance;

    cout << "Enter name of first object: ";
    cin >> name1;
    g.SetObject1Name(name1);

    cout << "Enter mass of " << g.GetObject1Name() << " (kg): ";
    cin >> mass1;
    g.SetObject1Mass(mass1);

    cout << "Enter name of second object: ";
    cin >> name2;
    g.SetObject2Name(name2);

    cout << "Enter mass of " << g.GetObject2Name() << " (kg): ";
    cin >> mass2;
    g.SetObject2Mass(mass2);

    cout << "Enter distance between " << g.GetObject1Name()
         << " and " << g.GetObject2Name() << " (m): ";
    cin >> distance;
    g.SetDistance(distance);

    g.PrintResult();

    return 0;
}

