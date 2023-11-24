// Starting off with the new data structures.
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption that word is in capital letter
        int index = word[0] - 'A';
        TrieNode *child;

        // present wala case
        if (root->children != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
    bool hasNoChildren(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }

    // Recursive function to remove a word from the Trie
    TrieNode *removeUtil(TrieNode *root, string word, int depth = 0)
    {
        // Base case: If the Trie is empty
        if (root == NULL)
        {
            return NULL;
        }

        // If we have not reached the end of the word
        if (depth < word.length())
        {
            int index = word[depth] - 'A';
            root->children[index] = removeUtil(root->children[index], word, depth + 1);

            // If the current node is not part of any other word and has no children, delete it
            if (root->isTerminal == false && hasNoChildren(root))
            {
                delete root;
                root = NULL;
            }
        }
        else // If the end of the word is reached
        {
            // If the current node is part of the word
            if (root->isTerminal)
            {
                root->isTerminal = false;
            }

            // If the current node has no children, delete it
            if (hasNoChildren(root))
            {
                delete root;
                root = NULL;
            }
        }

        return root;
    }

    // Public function to remove a word from the Trie
    void removeWord(string word)
    {
        root = removeUtil(root, word);
    }

    
};
int main()
{
    // cout << "Hello Trie" << endl;
    Trie *t = new Trie();
    t->insertWord("ARM");
    cout<<"New Word Inserted"<<endl;
    cout<<endl;
    cout << "Present or not" << t->search("ARM") << endl;

     t->removeWord("ARM");
    cout << "Word 'ARM' removed" << endl;
    cout << "Present or not: " << t->search("ARM") << endl;

    return 0;
}