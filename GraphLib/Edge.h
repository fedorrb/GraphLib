#ifndef EDGE_LIB
#define EDGE_LIB
#include <string>
using namespace std;
namespace GRAPH_LIB {
    //����� ����������� ����� �����
    //����� � �������� ���������, ����� ���
    class Edge
    {
    private:
        long value;//"���" ����� (���, ����������, ���������...)
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