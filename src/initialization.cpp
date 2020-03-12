#include "initialization.h"

using namespace std;

vector<Node> input() {
    ifstream infile("dataset/web.csv");

    vector<Node> temp(916428, Node());

    int inNode, outNode;
    char split;
    while(infile >> inNode >> split >> outNode) {
        temp.at(inNode).id = inNode;
        temp.at(inNode).out.push_back(outNode);
        temp.at(inNode).outSize++;
        temp.at(inNode).degree++;
        temp.at(outNode).in.push_back(inNode);
        temp.at(outNode).inSize++;
        temp.at(outNode).degree++;
    }

    return temp;
}

Node::Node() {
    id = -1;
    in.resize(0);
    out.resize(0);
    inSize = -1;
    outSize = -1;
    degree = -1;
};