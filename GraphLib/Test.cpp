#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>   
#include ".\test.h"
using namespace GRAPH_LIB;
using namespace std;

Test::Test(void)
{
}

Test::~Test(void)
{
}

void Test::LoadGraph(char* fileName, Graph &gr) {
    ifstream ifs;
    string line;
    ifs.open(fileName);
    while(getline(ifs,line)){

        // transfer the line contents to line_stream.
        stringstream line_stream( line );

        // transfer line_stream to int variables.
        string node1;
        if ( line_stream >> node1 ) // now do whatever you want with it.
        {
            string node2;
            while ( line_stream >> node2 )
                gr.AddEdge(node1, node2);
        }    
    }
}