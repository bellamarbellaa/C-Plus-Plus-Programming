#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> groceryQueue;
    int option;
    string item;

    do {
        cout << "\n1. Add grocery (enqueue)\n2. Remove first grocery (dequeue)\n3. View all groceries\n0. Exit\nChoose: ";
        cin >> option; cin.ignore();
        if (option == 1) {
            cout << "Enter item: "; getline(cin, item);
            groceryQueue.push(item);
        } else if (option == 2) {
            if (!groceryQueue.empty()) {
                cout << "Removed: " << groceryQueue.front() << endl;
                groceryQueue.pop();
            } else {
                cout << "List is empty.\n";
            }
        } else if (option == 3) {
            queue<string> temp = groceryQueue;
            cout << "Grocery queue (first added at front):\n";
            while (!temp.empty()) {
                cout << "- " << temp.front() << endl;
                temp.pop();
            }
        }
    } while (option != 0);

    return 0;
}

