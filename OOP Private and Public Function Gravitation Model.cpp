#include <iostream>
#include <string>
using namespace std;

class GravitationalForce {
private:
    string name1, name2;
    const double G = 6.674E-11;
    double m1, m2, r;

    // Private helper function
    double ComputeForce() const;

public:
    void SetObject1Name(string);
    void SetObject2Name(string);
    void SetObject1Mass(double);
    void SetObject2Mass(double);
    void SetDistance(double);
    void CalculateGravity() const;
};

// ===== Definitions outside the class =====
void GravitationalForce::SetObject1Name(string obj1) { name1 = obj1; }
void GravitationalForce::SetObject2Name(string obj2) { name2 = obj2; }
void GravitationalForce::SetObject1Mass(double mass1) { m1 = mass1; }
void GravitationalForce::SetObject2Mass(double mass2) { m2 = mass2; }
void GravitationalForce::SetDistance(double distance) { r = distance; }

// Private function defined outside class
double GravitationalForce::ComputeForce() const {
    return (G * m1 * m2) / (r * r);
}

void GravitationalForce::CalculateGravity() const {
    double F = ComputeForce(); 
    cout << "The gravitational force between " << name1 << " and " << name2
         << " is " << F << " N" << endl;
}

int main() {
    GravitationalForce g;
    string obj1, obj2;
    double mass1, mass2, distance;

    cout << "Enter the name of the first object: ";
    cin >> obj1;
    g.SetObject1Name(obj1);

    cout << "Enter the mass of " << obj1 << " (kg): ";
    cin >> mass1;
    g.SetObject1Mass(mass1);

    cout << "Enter the name of the second object: ";
    cin >> obj2;
    g.SetObject2Name(obj2);

    cout << "Enter the mass of " << obj2 << " (kg): ";
    cin >> mass2;
    g.SetObject2Mass(mass2);

    cout << "Enter the distance between " << obj1 << " and " << obj2 << " (m): ";
    cin >> distance;
    g.SetDistance(distance);

    g.CalculateGravity();

    return 0;
}
