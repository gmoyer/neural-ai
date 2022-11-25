#include <iostream>
#include "network.hpp"
#include "node.hpp"
#include "path.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    cout << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
}