#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "PageRank.h"

using namespace std;

void InitGraph(vector<Node*> & nodes)
{

    // example 1
    Node * a = new Node("A");
    Node * b = new Node("B");
    Node * c = new Node("C");
    Node * d = new Node("D");

    nodes.push_back(a);
    nodes.push_back(b);
    nodes.push_back(c);
    nodes.push_back(d);
    // link in node
    // a <- b, c, d
    a->InsertLinkdInNode(b);
    a->InsertLinkdInNode(d);
    // b <- d
    b->InsertLinkdInNode(c);
    b->InsertLinkdInNode(d);

    // c <- b, d
    c->InsertLinkdInNode(b);
    c->InsertLinkdInNode(d);

    d->InsertLinkdInNode(b);
}

void TestPageRank()
{
    // build graph
    vector<Node*> nodes;
    InitGraph(nodes);
    PageRank pr;
    // calculating pagerank 5 times
    pr.Calc(nodes, 40);
    pr.PrintPageRank(nodes);
}

int main(int argc, const char ** argv)
{
    TestPageRank();
    return 0;
}
