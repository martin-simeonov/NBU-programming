#include "Link.h"

Link::Link(Node *node, unsigned distance) {
    this->node = node;
    this->distance = distance;
}

Link::Link(Node *node, unsigned distance, unsigned base) {

}



std::ostream& operator<<(std::ostream &os, const Link &link) {
    os << link.distance;
    //os << link.node->getId() << " " << link.distance;
    return os;
}
