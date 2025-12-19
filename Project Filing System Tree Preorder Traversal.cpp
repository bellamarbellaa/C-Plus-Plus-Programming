#include <iostream>
#include <cstring>
using namespace std;

struct Folder {
    char name[50];
    Folder* left;   // left child
    Folder* right;  // right child
};

Folder* createFolder(const char* value) {
    Folder* f = new Folder;
    strcpy(f->name, value);
    f->left = NULL;
    f->right = NULL;
    return f;
}

// DFS to search and print path
bool dfs(Folder* node, const char* target, string path) {
    if (!node) return false;

    string currentPath = path + "/" + node->name;

    if (strcmp(node->name, target) == 0) {
        cout << currentPath << endl;
        return true;
    }

    // search left subtree
    if (dfs(node->left, target, currentPath))
        return true;

    // search right subtree
    if (dfs(node->right, target, currentPath))
        return true;

    return false;
}

int main() {

    // Build binary folder tree
    Folder* ROOT     = createFolder("ROOT");
    Folder* Projects = createFolder("Projects");
    Folder* Finance  = createFolder("Finance");

    ROOT->left  = Projects;
    ROOT->right = Finance;

    Folder* AI        = createFolder("AI");
    Folder* Contracts = createFolder("Contracts");

    Projects->left  = AI;
    Projects->right = Contracts;

    Folder* ClientA = createFolder("ClientA");
    Contracts->right = ClientA;

    Folder* Reports = createFolder("Reports");
    Finance->left = Reports;

    // Search for folder
    cout << "Full folder path: ";
    dfs(ROOT, "ClientA", "");

    return 0;
}

