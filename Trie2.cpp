#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int prefixcnt=0;
    int endwithcnt=0;

    bool containKey(char ch)
    {
        if(links[ch-'a']!=NULL)
        {
            return true;
        }
        return false;
    }

    void putKey(char ch,Node* newnode)
    {
        links[ch-'a']=newnode;
    }
    
    Node* getNode(char ch)
    {
        return links[ch-'a'];
    }

    void pre()
    {
        prefixcnt++;
    }

    void end()
    {
        endwithcnt++;
    }

    int getEndcnt()
    {
        return endwithcnt;
    }

    int cntPrefix()
    {
        return prefixcnt;
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
            node->pre();
        }
        node->end();
    }
    int countword(string word)
    {
        int len=word.length();
        Node* node=root;
        for(int i=0;i<len;i++)
        {
            if(!node->containKey(word[i]))
            {
               return 0;
            }
            node=node->getNode(word[i]);
        }
        return node->getEndcnt();
    }
    int  Cntstartwith(string word)
    {
        int len=word.length();
        Node* node=root;
        for(int i=0;i<len;i++)
        {
            if(!node->containKey(word[i]))
            {
               return 0;
            }
            node=node->getNode(word[i]);
        }
        return node->cntPrefix();
    }
};
int main()
{
    Trie* obj=new Trie();
    obj->insert("tarun");
    obj->insert("tarun");
    obj->insert("tarun");
    cout<<obj->Cntstartwith("tarun");
    return 0;
}
//Implement Trie-2 | INSERT | countWordsEqualTo() | countWordsStartingWith() | C++ 
