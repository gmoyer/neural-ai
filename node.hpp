#include <iostream>
#include "path.hpp"

using namespace std;

class Node {
    public:
    private:
        Path *path; //pointer to the first path from the node
        int potential; //the energy needed to activate the node
        int evenEnergy = 0; //the current amount of energy for an even turn
        int oddEnergy = 0; //the current amount of energy for an odd turn
        bool inEvenQueue = false;
        bool inOddQueue = false;
}