#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

namespace ariel
{
    struct Node
    {
        string name;
        vector<Node> children;
    };
    class OrgChart
    {
    private:
        Node root;
        bool recursive_sub(Node &node, string tather, string child);
        void recursive_level(Node &node);
        void recursive_revers(Node &node);
        void recursive_preorder(Node &node);
        vector<string> order;
        // vector<string> level_order_lst;
        // vector<string> reverse_order_lst;
        // vector<string> preorder_lst;


    public:
        
        OrgChart();
        OrgChart &add_root(string name);
        OrgChart &add_sub(string father, string child);
        friend ostream &operator<<(ostream &out, OrgChart &root);
        string *begin_level_order();
        string *end_level_order();
        string *begin_reverse_order();
        string *reverse_order();
        string *begin_preorder();
        string *end_preorder();
        string *begin()
        {
            return begin_level_order();
        }
        string *end()
        {
            return end_level_order();
        }
        ~OrgChart();

    
    // class Iterator
    //     {
    //     private:
    //         Node* pointer;
    //         vector<Node*> iter_lst;

    //     public:
    //         Iterator(){};
    //         Iterator(Node *node);
    //         Iterator(Node *root, string type);
    //         void recursive_level(Node *root);
    //         void recursive_revers(Node *root);
    //         void recursive_pre(Node *root);

    //         string operator*();
    //         friend bool operator==(const Iterator &a, const Iterator &b);
    //         friend bool operator!=(const Iterator &a, const Iterator &b);
    //         Iterator &operator++();
    //         Iterator &operator++(int);
    //         string *operator->();
    //         int size();
    //     };

        

    };


}