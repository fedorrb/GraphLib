#include "StdAfx.h"
#include "edge.h"
namespace GRAPH_LIB {
    Edge::Edge(string name) {
        this->name = name;
        value = 1;
    }

    Edge::Edge(string name, long value) {
        this->name = name;
        this->value = value;
    }

    long Edge::GetValue() {
        return value;
    }

    string Edge::GetName() {
        return name;
    }

    Edge::~Edge(void) {
    }
}