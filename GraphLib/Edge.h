#ifndef EDGE_LIB
#define EDGE_LIB
#include <string>
using namespace std;
namespace GRAPH_LIB {
    //класс описывающий ребро графа
    //связь с вершиной косвенная, через имя
    class Edge
    {
    private:
        long value;//"вес" ребра (вес, расстояние, стоимость...)
        string name;
    public:
        Edge(string name);
        Edge(string name, long value);
        string GetName(void);
        long GetValue(void);
        ~Edge(void);
    };
}
#endif