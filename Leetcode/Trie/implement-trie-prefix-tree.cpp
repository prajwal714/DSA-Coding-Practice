class TrieNode {
    public:
    bool is_word;
    TrieNode* next[26];
    
    TrieNode()
    {
        is_word=false;
        memset(next, NULL, sizeof(next) );
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }

    ~Trie()
    {
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(p->next[word[i]-'a']==nullptr)
            {
                p->next[word[i]-'a']=new TrieNode();
            }
            
            p=p->next[word[i]-'a'];
        }
        p->is_word=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        auto p=find(word);
        
        if( p!=NULL && (p->is_word))
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* p=find(prefix);
        if(p!=nullptr)
            return true;
        else
            return false;
        
    }
    
 private:
    
    TrieNode* find(string s)
    {
        auto p=root;
        for(int i=0;i<s.length();i++)
        {
            if(p->next[s[i]-'a']!=nullptr)
            p=p->next[s[i]-'a'];
            else
                return nullptr;
        }
        
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */