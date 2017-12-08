#include "Node.h"

Node::Node(unsigned id) {
    this->id = id;
}

unsigned Node::getId() {
    return id;
}

void Node::addLink(Link link) {
    links.push_back(link);
}

void Node::printLinks() const {
    for (std::vector<Link>::const_iterator it = links.begin(); it != links.end(); ++it) {
        std::cout << (*it) << std::endl;
    }
}
