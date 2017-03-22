#ifndef GRAPH_LIB_H
#define GRAPH_LIB_H
#include <vector>
#include <string>
#include <utility> //pair
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include "edge.h"

using namespace std;

namespace GRAPH_LIB {

    class Graph
    {
    public:
        Graph(bool directed);
        ~Graph(void);
        void AddEdge(string vertex1, string vertex2);
        void AddEdge(string vertex1, string vertex2, long value);
        void AddEdge(string vertex1);
        bool IsDirected();
        unsigned int GetSize();
        void PrintEdges();
        void PrintVertex();
        void SetVertexUndiscovered();
        //сделать friend?
        void Transponse();
        void BFS(string initialVertex);
        void BFS(); //all
        void DFS(string initialVertex);
        void DFS(); //all
		void PrintPath(string fromVertex, string toVertex); //путь с минимальным количеством вершин
        //void TopologicalSort();
        void StrongConnectedComponent();

    private:
		struct ParentVertex {
			string vertex; //текущая вершина
			string parent; //из какой вершины открыта
			int value; //вес
		} parentVertex;
		vector<ParentVertex> parentList;
		void AddParentList(string vertex, string parent, int value);

        bool directed; //ориентированный
        map<string, int> vertexMap; //список вершин с состоянием

        map<int, string> dfsMap;//список вершин с номерами окончания обработки DFS
        vector<int> vertexCount;
        vector<vector<string> > listVertexComponent;
        void SetVertexDfsNum(string vertex, int value); //заполнить dfsMap
        void DFS_MAX(vector<int> & vertexCount, vector<vector<string> > & listVertexComponent); //проход по транспонированному графу с поиском сильно связанных компонент
        void PrintVertexCount(vector<int> & vertexCount);
        int dfsNum;

        vector<Edge> edgeList; //список вершин с которыми связанна текущая 
        map<string, vector<Edge> > links; //собственно граф

        void SetVertexState(string vertex, int value);
        int GetVertexState(string vertex);
    };
}
#endif