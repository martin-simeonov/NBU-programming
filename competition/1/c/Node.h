// Node.h
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include "Link.h"

//class Link;
class Node {
    unsigned id;
    std::vector<Link> links;
public:
    Node(unsigned id);
    unsigned getId();
    void addLink(Link link);
    void printLinks() const;
};

#endif
