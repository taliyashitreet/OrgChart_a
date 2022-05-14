#include "OrgChart.hpp"
using namespace std;

namespace ariel
{
    OrgChart::OrgChart() {}
    OrgChart::~OrgChart() {}

    OrgChart &OrgChart::add_root(string name)
    {
        this->root.name = name;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string father, string child)
    {

        if(recursive_sub(this->root, father, child)==0){
            throw runtime_error("didnt found this father");
        }

        return *this;
    }
    bool OrgChart::recursive_sub(Node &root, string father, string child)
    {
        if (root.name == father)
        {
            Node enter;
            enter.name = child;
            this->root.children.push_back(enter);
            return true;
        }
        else
        {
            for (unsigned int i = 0; i < root.children.size(); i++)
            {
                if(recursive_sub(root.children.at(i), father, child)){
                    return true;
                }
            }
        }

        return false;
    }

    string *OrgChart::begin_level_order()
    {
        
        this->level_order_lst.clear();
        this->level_order_lst.push_back(root.name);
        recursive_level(this->root);
        return &this->level_order_lst.at(0);

    }
    void OrgChart::recursive_level(Node &root)
    {
        
        for (unsigned int i = 0; i < root.children.size(); i++)
        {
            this->level_order_lst.push_back(root.children.at(i).name);
        }
        for (unsigned int i = 0; i < root.children.size(); i++)
        {
            recursive_level(root.children.at(i));
        }
    }
    string *OrgChart::end_level_order()
    {
        return  &(this->level_order_lst[this->level_order_lst.size()]);
    }
    string *OrgChart::begin_reverse_order()
    {
        begin_level_order();
        revers_order_();
        return &this->reverse_order_lst.at(0);
    }
    void OrgChart::revers_order_()
    {
        for (unsigned int i = this->level_order_lst.size() - 1; i >0; i--)
        {
            reverse_order_lst.push_back(this->level_order_lst.at(i));
        }
    }
    string *OrgChart::reverse_order()
    {
        return &(this->reverse_order_lst[this->reverse_order_lst.size()]);
    }
    string *OrgChart::begin_preorder()
    {
        this->preorder_lst.clear();
        recursive_preorder(this->root);
        return &this->preorder_lst.at(0);
    }
    void OrgChart::recursive_preorder(Node &root)
    {
        this->preorder_lst.push_back(root.name);
        for (unsigned int i = 0; i < root.children.size(); i++)
        {
            recursive_preorder(root.children.at(i));
        }
    }
    string *OrgChart::end_preorder()
    {
        return &(this->preorder_lst[this->preorder_lst.size()]);
    }


    ostream &operator<<(ostream &out, OrgChart &root)
    {
        for (auto i = root.begin_level_order(); i != root.end_level_order(); i++)
        {
            out << (*i) << ", ";
        }
        return out;
    }

}