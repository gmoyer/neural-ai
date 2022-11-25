#include <iostream>
#include "path.hpp"

using namespace std;

class Node {
    public:
    private:
        Path *path; //pointer to the first path from the node
        int potential; //the energy needed to activate the node
        int energy = 0; //the current amount of energy
}