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

        if (recursive_sub(this->root, father, child) == 0)
        {
            throw runtime_error("didnt found this father");
        }

        return *this;
    }
    bool OrgChart::recursive_sub(Node &start, string father, string child)
    {
        if (start.name == father)
        {
            Node enter;
            enter.name = child;
            start.children.push_back(enter);
            return true;
        }
        else
        {
            for (unsigned int i = 0; i < start.children.size(); i++)
            {
                if (recursive_sub(start.children.at(i), father, child))
                {
                    return true;
                }
            }
        }

        return false;
    }

    string *OrgChart::begin_level_order()
    {

        this->order.clear();
        this->order.push_back(root.name);
        recursive_level(this->root);
        return &this->order.at(0);
    }
    void OrgChart::recursive_level(Node &start)
    {

        for (unsigned int i = 0; i < start.children.size(); i++)
        {
            this->order.push_back(start.children.at(i).name);
        }
        for (unsigned int i = 0; i < start.children.size(); i++)
        {
            recursive_level(start.children.at(i));
        }
    }
    string *OrgChart::end_level_order()
    {
        return &(this->order[this->order.size()]);
    }
    string *OrgChart::begin_reverse_order()
    {
        this->order.clear();
        this->order.push_back(this->root.name);
        recursive_revers(this->root);
        reverse(this->order.begin(), this->order.end());
        return &this->order.at(0);
    }
    void OrgChart::recursive_revers(Node &start)
    {

        for (int i = start.children.size() - 1; i >= 0; i--)
        {
            order.push_back(start.children.at(size_t(i)).name);
        }
            for (int i = start.children.size() - 1; i >= 0; i--)
            {
                recursive_revers(start.children.at(size_t(i)));
            }

    }
    string *OrgChart::reverse_order()
    {
        return &(this->order[this->order.size()]);
    }
    string *OrgChart::begin_preorder()
    {
        this->order.clear();
        recursive_preorder(this->root);
        return &this->order.at(0);
    }
    void OrgChart::recursive_preorder(Node &start)
    {
        this->order.push_back(start.name);
        for (unsigned int i = 0; i < start.children.size(); i++)
        {

            recursive_preorder(start.children.at(i));
        }
    }
    string *OrgChart::end_preorder()
    {
        return &(this->order[this->order.size()]);
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