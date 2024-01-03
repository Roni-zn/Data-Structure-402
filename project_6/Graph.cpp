#include <iostream>
#include "E:\UniShits\Repossitories\Data-Structure-402\project_5\SimpleLinkedlist.cpp"
#include"E:\UniShits\Repossitories\Data-Structure-402\project_3\Queue.cpp"
#include <string>
using namespace std;
const int Max_number = 20;
class Graph
{
    private:
        int findindex(int value);
        bool there_is(Linked_list L, int a);
        node array[Max_number] ;
        int count = 0;
    public:
       void AddVertex(int vertex);
       void AddEdge(int firstVertex, int secondVertex);
       //void RemoveEdge(int firstVertex, int secondVertex);
       //void RemoveVertex(int vertex);
       string BFS();
       //string DFS();
       void printg();
};
//--- find index -------------
int Graph::findindex(int value)
{
    int index;
    for(int i = 0; i < count; i++)
    {
        if(array[i].value == value)
        index = i;
    }
    return index;
}
//--- BFS --------------------
string Graph::BFS()
{
    bool visited[Max_number] = {false};
    string result;
    Queue queue;
    int v;
    node* temp;
    queue.Enqueue(array[0].value);
    visited[0] = true;
    while( !queue.is_empty())
    {
        v = queue.Peek();
        result += to_string(queue.Dequeue());
        temp = array[v].link;
        //visited[v] = true;
        while(temp != NULL)
        {
            if(visited[temp->value] == false)
            {
                queue.Enqueue(temp->value);
                visited[temp->value] = true;
            }
            temp = temp->link;
        }

    }
    return result;
}
//--- there is ---------------
bool Graph::there_is(Linked_list L, int a)
{
    node* temp = L.head;
    while(temp != NULL)
    {
        if(temp->value == a)
        return true;

        temp = temp->link;
    }
    return false;
}
//--- print -----------------
void Graph::printg()
{
    Linked_list L;
    for(int i = 0; i < count; i++)
    {
        L.head = array[i].link;
        cout<<array[i].value<<": ";
        L.print();
    }
}
//--- add vertex ------------
void Graph::AddVertex(int vertex)
{
   array[count].value = vertex;
   array[count++].link = NULL;
}
//--- add edge ---------------
void Graph::AddEdge(int firstVertex, int secondVertex)
{
   int first_index = findindex(firstVertex);
   int second_index = findindex(secondVertex);
   Linked_list L1,L2;
   L1.head = array[first_index].link;
   L2.head = array[second_index].link;
   node* temp1 = array[first_index].link;
   node* temp2 = array[second_index].link;
   int flag = there_is(L1, secondVertex);
    if(array[first_index].link == NULL && array[second_index].link == NULL && flag == 0)
    {
        L1.insert_at_begin(secondVertex);
        L2.insert_at_begin(firstVertex);
        array[first_index].link = L1.head;
        array[second_index].link = L2.head;
    }
    else if(array[first_index].link == NULL && flag == 0)
    {
        L1.insert_at_begin(secondVertex);
        array[first_index].link = L1.head;
        L2.insert_at_end(firstVertex);
    }
    else if(array[second_index].link == NULL && flag == 0)
    {
        L2.insert_at_begin(firstVertex);
        array[second_index].link = L2.head;
        L1.insert_at_end(secondVertex);
    }
    else if(flag == 0)
    {
        L1.insert_at_end(secondVertex);
        L2.insert_at_end(firstVertex);
    }
    
}
//--- main -----
int main()
{
    Graph g;
    g.AddVertex(0);
    g.AddVertex(1);
    g.AddVertex(3);
    g.AddVertex(2);
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(1,3);
    g.AddEdge(2,3);
    g.AddEdge(3,2);
    g.printg();
    cout<<g.BFS();
    return 0;

}