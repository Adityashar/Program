#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> childmap;

    TrieNode(char ch){
        data=ch;
        isTerminal=false;
    }
};
class Trie{
    TrieNode *root;

    void recAddWord(char *word, TrieNode *TN){
        if(word[0]=='\0'){
            TN->isTerminal=true;
            return;
        }
        char ch=word[0];
        auto it=TN->childmap.find(ch); /// Pair BANA KAR DEGA /// KEY is th ARGUMENT IN THE find()
        TrieNode *TN_CHILD;
        if(it==TN->childmap.end()){
            ///key node is not found
            TN_CHILD=new TrieNode(ch);
            TN->childmap[ch]=TN_CHILD;
        }
        else{
            TN_CHILD=it->second;
        }
        recAddWord(word+1,TN_CHILD);
    }

public:
    Trie(){
        root=new TrieNode('\0');
    }
    void addWord(char *word){
        recAddWord(word,root);
    }
    bool Search(char *word){
        TrieNode *temp=root;

        for(int i=0;word[i]!='\0';i++){
            char ch=word[i];
            auto it=temp->childmap.find(ch);
            if(it==temp->childmap.end()){
                return false;
            }
            else{
                temp=it->second;
            }
        }
        return temp->isTerminal;
    }
};

int main(){
    Trie t;
    char *s1="a";
    char *s2="ball";
    char *s3="apple";
    char *s4="ape";
    char *s5="not";
    char *s6="no";
    char *s7="code";

    t.addWord(s1);
    t.addWord(s2);
    t.addWord(s3);
    t.addWord(s4);
    t.addWord(s5);
    t.addWord(s6);
    t.addWord(s7);

    cout<<t.Search("apple");
    cout<<t.Search("apples");
    return 0;
}
