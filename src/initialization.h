#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Node {
public:
    Node();
    int id;
    vector<int> in;
    vector<int> out;
    int inSize;
    int outSize;
    int degree;
};

class ShortestPath {
    vector<int> path;
};

vector<Node> input();