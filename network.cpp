#include <iostream>
#include "network.hpp"
#include "node.hpp"
#include "path.hpp"

using namespace std;



Network::Network(int ip, int op) {
    int initPaths = 100;
    int initNodes = 10;
    inputNodes = ip; //to decide where to place the next node
    for (int i = 0; i < ip+op; i++) {
        brain.push_back(nullptr);
    }

    //add initial paths
    for (int i = 0; i < initPaths; i++) {
        
    }
}

int Network::randomNode() {
    //returns a random number between inputNodes and nodes
    return rand()*(nodes-inputNodes)+inputNodes; 
}

int Network::randomInputNode() {
    return rand()*(inputNodes); 
}

void Network::mainAction() {
    q.push(-1);
    for (int i = 0; i < ip; i++) {
        q.push(i); //adding all the input nodes to the front of the queue
    }

    //main loop
    while (q.front() != -1) {
        Node *curr = brain[q.front()];
        bool activate = false;
        if (turnType == 0) {
            if (curr->evenEnergy >= curr->potential)
                activate = true;
            curr->evenEnergy = 0;
            curr->inEvenQueue = false;
        } else {
            if (curr->oddEnergy >= curr->potential)
                activate = true;
            curr->oddEnergy = 0;
            curr->inOddQueue = false;
        }
        if (activate) {
            //add all the nodes to the queue
            Path *p = curr->path;
            while (p != nullptr) {
                Node *dest = brain[p->dest];
                if (turnType == 0) { //even turn
                    if (!dest->inOddQueue)
                        q.push(p->dest);
                    dest->oddEnergy++; //for the next turn
                    dest->inOddQueue = true;
                } else { //odd turn
                    if (!dest->inEvenQueue)
                        q.push(p->dest);
                    dest->evenEnergy++;
                    dest->inEvenQueue = true;
                }
                p = p->next;
            }
        }

        q.pop();
    }
    q.pop(); //pop the -1

    //switch turn
    if (turnType == 0)
        turnType = 1;
    else
        turnType = 0;
}