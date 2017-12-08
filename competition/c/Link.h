// Link.h
#ifndef LINK_H
#define LINK_H

#include <ostream>
#include "Link.h"

class Node;
class Link {
    Node *node;
    unsigned distance;
    friend std::ostream& operator<<(std::ostream &os, const Link &link);
public:
    Link(Node *node, unsigned distance);
    Link(Node *node, unsigned distance, unsigned base);
};

#endif
