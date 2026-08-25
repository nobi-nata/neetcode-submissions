class PrefixTree {
public:
    struct Tries{
        char val;
        int end;
        vector<Tries*> child;

        Tries(){
            val = '#';
            end = 1;
            child.resize(26, nullptr);
        }
    };
    Tries* tr;
    PrefixTree() {
        tr = new Tries();
    }
    
    void insert(string word) {
        Tries* t = tr;
        for(int i = 0; i < word.size(); i++){
            if(t->child[word[i]-'a'] == nullptr){
                Tries* temp  = new Tries();
                temp->val = word[i];
                temp->end = 0;
                t->child[word[i]-'a'] = temp;
            }
            t = t->child[word[i]-'a'];  
        }
        t->end = 1;
    }
    
    bool search(string word) {
        Tries* t = tr;
        for(int i = 0; i < word.size(); i++){
            if(t->child[word[i]-'a'] != nullptr){ 
                t = t->child[word[i]-'a'];
            }
            else return false;
        }
        if(t->end == 1) return true;
        return false;
    }
    
    bool startsWith(string word) {
        Tries* t = tr;
        for(int i = 0; i < word.size(); i++){
            if(t->child[word[i]-'a'] != nullptr){ 
                t = t->child[word[i]-'a'];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */