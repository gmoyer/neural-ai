#include <iostream>
#include "network.hpp"

using namespace std;



Network::Network(int ip) {
    inputNodes = ip; //to decide where to place the next node
    for (int i = 0; i < ip; i++) {
        brain.push_back(nullptr);
    }
}

int Network::randomNode() {
    //returns a random number between inputNodes and nodes
    return rand()*(nodes-inputNodes)+inputNodes; 
}

void Network::mainAction() {
    q.push(-1);
}