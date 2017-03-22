#include "StdAfx.h"
#include "graph.h"
namespace GRAPH_LIB {
    Graph::Graph(bool directed) {
        this->directed = directed;
        vertexMap.clear();
        links.clear();
    }

    void Graph::AddEdge(string vertex1, string vertex2) {
        vertexMap.insert(make_pair(vertex1, 0));
        vertexMap.insert(make_pair(vertex2, 0));
        map<string, vector<Edge> >::iterator it = links.find(vertex1);
        if(it != links.end())
        {
            //вершина уже есть в списке
            //добавить вершину 2 в список связанных вершин для вершины 1
            //найти эту вершину в links, взять список связанных вершин EdgeList и добавить новую
            edgeList = it->second;
            Edge edge = Edge(vertex2, 1);
            edgeList.push_back(edge);
            it->second = edgeList;
        }
        else
        {
            //добавить новую вершину в links:
            //создать новый список связанных вершин EdgeList, добавить вторую
            //добавить пару вершина - список связанных с ней вершин в links
            edgeList.clear();
            Edge edge = Edge(vertex2, 1);
            edgeList.push_back(edge);
            links.insert(make_pair(vertex1, edgeList));
        }
    }

    void Graph::AddEdge(string vertex1, string vertex2, long value) {
        vertexMap.insert(make_pair(vertex1, 0));
        vertexMap.insert(make_pair(vertex2, 0));
        map<string, vector<Edge> >::iterator it = links.find(vertex1);
        if(it != links.end())
        {
            //вершина уже есть в списке
            //добавить вершину 2 в список связанных вершин для вершины 1
            //найти эту вершину в links, взять список связанных вершин EdgeList и добавить новую
            edgeList = it->second;
            Edge edge = Edge(vertex2, value);
            edgeList.push_back(edge);
            it->second = edgeList;
        }
        else
        {
            //добавить новую вершину в links:
            //создать новый список связанных вершин EdgeList, добавить вторую
            //добавить пару вершина - список связанных с ней вершин в links
            edgeList.clear();
            Edge edge = Edge(vertex2, value);
            edgeList.push_back(edge);
            links.insert(make_pair(vertex1, edgeList));
        }
    }

    //незнаю зачем, но пусть будет
    void Graph::AddEdge(string vertex1) {
        vertexMap.insert(make_pair(vertex1, 0));
        map<string, vector<Edge> >::iterator it = links.find(vertex1);
        if(it != links.end())
        {
            //вершина уже есть в списке
        }
        else
        {
            //добавить новую вершину в links:
            edgeList.clear();
            links.insert(make_pair(vertex1, edgeList));
        }
    }

    //печать вершин со списком связанных
    void Graph::PrintEdges() {
        map<string, vector<Edge> >::iterator it;
        vector<Edge>::iterator it_v;
        for(it = links.begin(); it != links.end(); ++it) {
            cout << it->first << " - ";
            edgeList = it->second; //список связанных вершин для текущей из links
            for(it_v = edgeList.begin(); it_v != edgeList.end(); ++it_v) {
                cout << it_v->GetName() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void Graph::PrintVertex() {
        map<string, int>::iterator it;
        for(it = vertexMap.begin(); it != vertexMap.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;
    }

    unsigned int Graph::GetSize() {
        return static_cast<unsigned int>(vertexMap.size());//size_t
    }

    void Graph::SetVertexUndiscovered() {
        map<string, int>::iterator it;
        for(it = vertexMap.begin(); it != vertexMap.end(); ++it) {
            it->second = 0;
        }
    }

    void Graph::BFS() {
        map<string, int>::iterator it;
        for(it = vertexMap.begin(); it != vertexMap.end(); ++it) {
            if(GetVertexState(it->first))
                continue;
            BFS(it->first);
        }
    }

    void Graph::BFS(string initialVertex) {
        queue<string> vertexQueue; //рабочая очередь
        int k = 1;
        bool incK = true; //если флаг убрать, то будет просто счетчик порядка обхода вершин, иначе расстояние в ребрах-1
        map<string, vector<Edge> >::iterator it_m;
        vector<Edge>::iterator it_v;
        string v; v.clear();
        vertexQueue.push(initialVertex);
        SetVertexState(initialVertex, k); //обозначить как исследованную
		AddParentList(initialVertex, initialVertex, 0); //запомнить последовательность обхода вершин
        while(!vertexQueue.empty()) {
            v = vertexQueue.front(); //достать вершину из стека
            vertexQueue.pop(); //удалить
            k = GetVertexState(v);
            it_m = links.find(v); //найти вершину в графе
            if(it_m != links.end()) {
                incK = true;
                edgeList = it_m->second; //список связанных вершин для текущей из links
                for(it_v = edgeList.begin(); it_v != edgeList.end(); ++it_v) {
                    if(!GetVertexState(it_v->GetName())) { //если не исследованна вершина
						AddParentList(it_v->GetName(), v, it_v->GetValue()); //запомнить последовательность обхода вершин
                        if(incK) {
                            k++;
                            incK = false;
                        }
                        SetVertexState(it_v->GetName(), k); //обозначить как исследованную
                        vertexQueue.push(it_v->GetName()); //добавить в очередь для исследования
                    }
                }
            }
        }
    }

    //запомнить последовательность обхода вершин
	void Graph::AddParentList(string vertex, string parent, int value) {
		parentVertex.vertex = vertex;
		parentVertex.parent = parent;
		parentVertex.value = value;
		parentList.push_back(parentVertex);
	}

	void Graph::PrintPath(string from, string to) {
        //todo: попробовать без for через find, что быстрее
		bool pathExist = false;
		reverse(parentList.begin(), parentList.end());
		vector<ParentVertex>::iterator it;
		stack<string> path;
		for(it = parentList.begin(); it != parentList.end(); ++it) {
			if(it->vertex == to) {
				path.push(to);
				to = it->parent;
				if(from == to)
					pathExist = true;
			}
		}
		if(pathExist) {
			cout << "Path:" << endl;
			while(!path.empty()) {
				cout << path.top() << endl;
				path.pop();
			}
		}
		else
			cout << "No Way!" << endl;
	}

    void Graph::SetVertexState(string vertex, int value) {
        map<string, int>::iterator it = vertexMap.find(vertex);
        if(it != vertexMap.end()) {
            it->second = value;
        }
    }

    int Graph::GetVertexState(string vertex) {
        int value = 0;
        map<string, int>::iterator it = vertexMap.find(vertex);
        if(it != vertexMap.end()) {
            value = it->second;
        }
        return value;
    }

	void Graph::Transponse() {
		Graph gr = Graph(true);
		map<string, vector<Edge> >::iterator it_m;
        vector<Edge>::iterator it_v;

		for(it_m = links.begin(); it_m != links.end(); ++it_m) {
			edgeList = it_m->second; //список связанных вершин для текущей из links
			for(it_v = edgeList.begin(); it_v != edgeList.end(); ++it_v) {
				gr.AddEdge(it_v->GetName(), it_m->first, it_v->GetValue());
			}
		}

        links = gr.links;
	}

    void Graph::DFS(string initialVertex) {
        bool investigated = false;
        stack<string> vertexStack; //рабочая очередь
        int k = 1;
        string v; v.clear();
        map<string, vector<Edge> >::iterator it_m;
        vector<Edge>::iterator it_v;
        vertexStack.push(initialVertex);
        SetVertexState(initialVertex, k); //обозначить как исследованную
        while(!vertexStack.empty()) {
            v = vertexStack.top(); //достать вершину из стека
            it_m = links.find(v); //найти вершину в графе
            if(it_m != links.end()) {
                edgeList = it_m->second; //список связанных вершин для текущей из links
                investigated = true;
                for(it_v = edgeList.begin(); it_v != edgeList.end(); ++it_v) {
                    if(!GetVertexState(it_v->GetName())) { //если не исследованна вершина
                        k++;
                        SetVertexState(it_v->GetName(), k); //обозначить как исследованную
                        vertexStack.push(it_v->GetName()); //добавить в стек для исследования
                        investigated = false;
                        break;
                    }
                }
                if(investigated) {
                    vertexStack.pop(); //удалить
                    dfsNum++;
                    SetVertexDfsNum(v, dfsNum);
                }
            } else {//отсутствуют исходящие ребра
                vertexStack.pop(); //удалить
                dfsNum++;
                SetVertexDfsNum(v, dfsNum);
            }
        }
    }

    void Graph::DFS() {
        dfsNum = 0;
        map<string, int>::iterator it;
        for(it = vertexMap.begin(); it != vertexMap.end(); ++it) {
            if(GetVertexState(it->first))
                continue;
            DFS(it->first);
        }
    }

    void Graph::DFS_MAX(vector<int> & vertexCount, vector<vector<string> > & listVertexComponent) {
        string initialVertex;
        bool investigated = false;
        stack<string> vertexStack; //рабочая очередь
        int k = 1;
        int dfsNum = 0;
        string v; v.clear();
        map<string, vector<Edge> >::iterator it_m;
        vector<Edge>::iterator it_v;
        map<int, string>::reverse_iterator it_dfs;
        for(it_dfs = dfsMap.rbegin(); it_dfs != dfsMap.rend(); ++it_dfs) {
            initialVertex = it_dfs->second;
            if(GetVertexState(initialVertex))
                continue;
            vertexStack.push(initialVertex);
            SetVertexState(initialVertex, k); //обозначить как исследованную
            while(!vertexStack.empty()) {
                v = vertexStack.top(); //достать вершину из стека
                it_m = links.find(v); //найти вершину в графе
                if(it_m != links.end()) {
                    edgeList = it_m->second; //список связанных вершин для текущей из links
                    investigated = true;
                    for(it_v = edgeList.begin(); it_v != edgeList.end(); ++it_v) {
                        if(!GetVertexState(it_v->GetName())) { //если не исследованна вершина
                            k++;
                            SetVertexState(it_v->GetName(), k); //обозначить как исследованную
                            vertexStack.push(it_v->GetName()); //добавить в стек для исследования
                            investigated = false;
                            break;
                        }
                    }
                    if(investigated) {
                        vertexStack.pop(); //удалить
                    }
                } else {//отсутствуют исходящие ребра
                    vertexStack.pop(); //удалить
                }
            }
            vertexCount.push_back(k);
            k = 1;
        }
    }

    void Graph::SetVertexDfsNum(string vertex, int value) {
        dfsMap.insert(make_pair(value, vertex));
    }

    void Graph::PrintVertexCount(vector<int> & vertexCount) {
        cout << "strong component" << endl;
        std::sort(vertexCount.begin(), vertexCount.end());
        vector<int>::iterator it;
        for(it = vertexCount.begin(); it != vertexCount.end(); ++it) {
            cout << (*it) << endl;
        }
    }

    void Graph::StrongConnectedComponent() {
        dfsMap.clear();
        DFS();
        Transponse();
        SetVertexUndiscovered();
        DFS_MAX(vertexCount, listVertexComponent);
        PrintVertexCount(vertexCount);
    }

    Graph::~Graph(void) {
    }
}