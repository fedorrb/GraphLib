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
        //������� friend?
        void Transponse();
        void BFS(string initialVertex);
        void BFS(); //all
        void DFS(string initialVertex);
        void DFS(); //all
		void PrintPath(string fromVertex, string toVertex); //���� � ����������� ����������� ������
        //void TopologicalSort();
        void StrongConnectedComponent();

    private:
		struct ParentVertex {
			string vertex; //������� �������
			string parent; //�� ����� ������� �������
			int value; //���
		} parentVertex;
		vector<ParentVertex> parentList;
		void AddParentList(string vertex, string parent, int value);

        bool directed; //���������������
        map<string, int> vertexMap; //������ ������ � ����������

        map<int, string> dfsMap;//������ ������ � �������� ��������� ��������� DFS
        vector<int> vertexCount;
        vector<vector<string> > listVertexComponent;
        void SetVertexDfsNum(string vertex, int value); //��������� dfsMap
        void DFS_MAX(vector<int> & vertexCount, vector<vector<string> > & listVertexComponent); //������ �� ������������������ ����� � ������� ������ ��������� ���������
        void PrintVertexCount(vector<int> & vertexCount);
        int dfsNum;

        vector<Edge> edgeList; //������ ������ � �������� �������� ������� 
        map<string, vector<Edge> > links; //���������� ����

        void SetVertexState(string vertex, int value);
        int GetVertexState(string vertex);
    };
}
#endif