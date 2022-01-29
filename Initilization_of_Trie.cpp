#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag=false;

    bool containKey(char ch)
    {
        if(links[ch-'a']!=NULL)
        {
            return true;
        }
        return false;
    }
    void putKey(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* getNode(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isend()
    {
        return flag;
    }
};
class Trie
{
    private: Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        int len=word.length();
        Node* node=root;
        for(int i=0;i<len;i++)
        {
            if(!node->containKey(word[i]))
            {
                node->putKey(word[i],new Node());
            }
            node=node->getNode(word[i]);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        int len=word.length();
        Node* node=root;
        for(int i=0;i<len;i++)
        {
            if(!node->containKey(word[i]))
            {
               return false;
            }
            node=node->getNode(word[i]);
        }
        if(node->isend()==true)
        {
            return true;
        }
        return false;
    }
     bool startwith(string word)
    {
        int len=word.length();
        Node* node=root;
        for(int i=0;i<len;i++)
        {
            if(!node->containKey(word[i]))
            {
               return false;
            }
            node=node->getNode(word[i]);
        }
        return true;
    }
};
int main()
{
    Trie* obj=new Trie();
    obj->insert("tarun");
    obj->insert("varun");
    obj->insert("arun");
    cout<<obj->search("tarun");
    return 0;
}
