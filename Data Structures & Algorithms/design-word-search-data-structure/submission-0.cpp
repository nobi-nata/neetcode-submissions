class WordDictionary {
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
    WordDictionary() {
        tr = new Tries();
    }
    
    void addWord(string word) {
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
        return find(word, t);
    }

    bool find(string word, Tries* t){
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26; j++){
                    if(t->child[j] && find(word.substr(i+1), t->child[j])){
                        return true;
                    }
                }
                return false;
            }
            else if(t->child[word[i]-'a'] != nullptr){ 
                t = t->child[word[i]-'a'];
            }
            else return false;
        }
        if(t->end == 1) return true;
        return false;
    }
};
