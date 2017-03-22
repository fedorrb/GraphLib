#include "stdafx.h"
#include "graph.h"
#include "test.h"
using namespace GRAPH_LIB;

int _tmain(int argc, _TCHAR* argv[])
{
    /*
    Graph gr = Graph(true);
    gr.AddEdge("1","2");
    gr.AddEdge("1","3");
    gr.AddEdge("2","3");
    gr.AddEdge("3","4");
    gr.AddEdge("4","1");
    gr.AddEdge("5","6");
    gr.BFS("1");
	//gr.BFS("4");
    gr.PrintEdges();
    gr.PrintVertex();
    gr.SetVertexUndiscovered();
    gr.PrintVertex();
	gr.PrintPath("1","4");
	cout << "-----------" << endl;
	Graph transposeGr = gr.Transponse();
	transposeGr.BFS("1");
	transposeGr.PrintEdges();
	transposeGr.PrintVertex();
	transposeGr.PrintPath("1","2");
    */
    /*
    Graph gr = Graph(true);
    gr.AddEdge("1","2");
    gr.AddEdge("1","3");
    gr.AddEdge("2","4");
    gr.AddEdge("3","4");
    gr.DFS("1");
    gr.PrintEdges();
    gr.PrintVertex();
    */
    /*
    Graph gr = Graph(true);
    Test test;
    test.LoadGraph("",gr);
    gr.BFS("2");
    gr.PrintEdges();
    gr.PrintVertex();
    gr.PrintPath("2","8");
    */
    Graph gr = Graph(true);
    Test test;
    //test.LoadGraph("d:/ruslan/1/input_08.txt",gr);
    test.LoadGraph("d:/ruslan/1/test08_1.txt",gr);
    gr.StrongConnectedComponent();
	return 0;
}