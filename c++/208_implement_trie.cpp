class Trie {
public:
    bool end; // Whether or not there is an inserted word that ends with this node
    Trie* children[26] = { nullptr }; // Potential slot for every char in alphabet
    Trie() {
        end = false;
    }
    
    void insert(string word) {
        Trie* cur = this;
        int i = 0;
        
        // Traverse to end of common prefixes
        while (i < word.length() && cur->children[word[i] - 'a'] != nullptr) {
            cur = cur->children[word[i] - 'a'];
            i++;
        }

        // Insert edges for remainder of word into Trie
        for (i; i < word.length(); i++) {
            cur->children[word[i] - 'a'] = new Trie();
            cur = cur->children[word[i] - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Trie* cur = this;

        // Try to naviagte through the whole word, if
        // possible then result is whether or not last
        // Trie node is true for end
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }

        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        
        // Try to navigate through the whole prefix, if possible
        // then prefix is present
        for (char c : prefix) {
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
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
