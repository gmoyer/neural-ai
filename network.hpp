#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Network {
    public:
        Network(int ip, int op); //standard constructor
        void mainAction(); //the main action, runs through the queue
        int randomNode(); //returns a random node
    private:
        vector<*Node> brain; //vector of node pointers to each node in the brain
        int inputNodes = 0; //count of input nodes
        int nodes = 0; //count of the number of nodes in the brain
        queue<int> q; //a queue of nodes that need to be updated with reference to the node via the vector (-1 = time update)
        bool turnType = 0; //whether a turn is even or odd 0 = even, 1 = odd
}