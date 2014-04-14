#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

// use graph store webpage, weight representlink times
class Node
{
public:
    explicit Node(string name, double pr = 1){
        name_ = name;
        page_rank_ = pr;
    }

    ~Node()
    {
        linkin_nodes_.clear();
    }
    void InsertLinkdInNode(Node* node)
    {
        //如果没有链接
        if (linkin_nodes_.find(node) == linkin_nodes_.end())
        {
            linkin_nodes_.insert(node);
        }
        node->InsertLinkOutNode(this);
    }

    void InsertLinkOutNode(Node* node)
    {
        //如果没有链接
        if (linkout_nodes_.find(node) == linkout_nodes_.end())
        {
            linkout_nodes_.insert(node);
        }
    }

    double GetPageRank()
    {
        return page_rank_;
    }

    void SetPageRank(double pr)
    {
        page_rank_ = pr;
    }

    double CalcRank()
    {
        double pr = 0;
        set<Node*>::const_iterator citr = linkin_nodes_.begin();
        for (; citr != linkin_nodes_.end(); ++citr)
        {
            Node * node = *citr;
            pr += node->GetPageRank()/node->GetOutBoundNum();
        }
        return pr;
    }

    size_t GetOutBoundNum()
    {
        return linkout_nodes_.size();
    }

    size_t GetInBoundNum()
    {
        return linkin_nodes_.size();
    }

    void PrintNode()
    {
        cout << "Node:" << name_ << "'s pagerank is: " << page_rank_ << endl;
    }
private:
    string name_;
    set<Node*> linkin_nodes_;
    set<Node*> linkout_nodes_;
    double page_rank_;
};

class PageRank
{
public:
    PageRank(double q=0.85);
    ~PageRank(void);
    void Calc(vector<Node*> & nodes, int n);
    double Calc(Node* node);
    void PrintPageRank(vector<Node*> & nodes);
private:
    double q_;
};
