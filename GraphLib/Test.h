#ifndef TEST_H
#define TEST_H
#include "graph.h"
using namespace GRAPH_LIB;

class Test
{
public:
    Test(void);
    ~Test(void);
    void LoadGraph(char* fileName, Graph &gr);
};
#endif