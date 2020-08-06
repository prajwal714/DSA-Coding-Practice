class Word {
    public:
    Word* next[26];
    bool is_word;
    
    Word(){
        memset(next, 0, sizeof(next));
        is_word=false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Word* root;
    WordDictionary() {
        root=new Word();
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        Word* p=root;
        for(int i=0;i<word.length();i++)
        {
            if(p->next[word[i]-'a']==NULL)
            {
                p->next[word[i]-'a']=new Word();
            }
            p=p->next[word[i]-'a'];
        }
        
        p->is_word=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
       return find(word,0,root);
    }
    
    private:
    
    bool find(string s,int pos, Word* root)
    {
       if(pos==s.length())
           return root->is_word;
        
        if(s[pos]!='.')
        {
            root=root->next[s[pos]-'a'];
            if(root==NULL)
                return false;
            else
                return find(s,pos+1,root);
        }
        
      
            for(int j=0;j<26;j++)
            {
                if(root->next[j]&&find(s,pos+1,root->next[j]))
                    return true;
            }
            return false;
       
        
       
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
