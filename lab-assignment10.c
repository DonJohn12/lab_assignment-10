#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// trie node
struct Trie
{
    struct Trie *children[26];
    int isWord;
};
 
// Returns new trie node (initialized to NULLs)
struct Trie *getNode(void)
{
    struct Trie *pNode = NULL;
 
    pNode = (struct Trie *)malloc(sizeof(struct Trie));
 
    if (pNode)
    {
        int i;
 
        pNode->isWord = 0;
 
        for (i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}

//void insert(struct Trie *root, const char *key)
void insert(struct Trie *ppTrie, char *word)
{
    int level;
    int length = strlen(word);
    int index;
 
    struct Trie *pCrawl = ppTrie;
 
 
    for (level = 0; level < length; level++)
    {
       	
        index = word[level] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
            
        pCrawl = pCrawl->children[index];
    }
    
    // mark last node as leaf
    pCrawl->isWord = 1;
    
}

int numberOfOccurances(struct Trie *pTrie, char *word)
{

	char* curr;

	int result = 0;
 
    // Leaf denotes end of a word
    if (pTrie->isWord == 1)
        result++;
    
	int i;
    for ( i = 0; i < 26; i++)   
    {
      if (pTrie -> children[i])
      {
         result += numberOfOccurances(pTrie -> children[i]);
      }
    }
    
    return result;
}

//struct Trie *deallocateTrie(struct Trie *pTrie);

int main(void)
{
	//read the number of the words in the dictionary
	// parse line  by line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	struct Trie* root = getNode();
	
	int i;
	for(i = 0; i < 5; i++)
	{
		insert(root, pWords[i]);
	}
	
	printf("Number of words %d", numberOfOccurances(root));
	
	/*for (int i=0;i<5;i++)
	{
	  printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
	}
    trie = deallocateTree(&trie);
    if (trie != NULL)
       printf("There is an error in this program\n");*/
    return 0;
};
