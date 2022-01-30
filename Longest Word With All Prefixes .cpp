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
   int n;
   cin>>n;
   string A[n];
   for(int i=0;i<n;i++)
   {
       cin>>A[i];
       obj->insert(A[i]);
   }
   int ans=INT_MIN;
   for(int i=0;i<n;i++)
   {
       string temp=A[i];
       bool flag=true;
       for(int i=0;i<temp.length();i++)
       {
           string check=temp.substr(0,i+1);
           if(!obj->search(check))
           {
               flag=false;
              break;
           }
       }
       if(flag)
       {
           ans=max(ans,(int)temp.length());
       }
   }
    return 0;
}
