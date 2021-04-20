/*
 * Name: Joshua Kennerly
 * Date Submitted: 10/26/20
 * Assignment Name: Single Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
     string letters = " ";
    vector<string> anagrams;
   
    //unordered_map<char,int> map;
   
    //goes through all the letters in wordlist
    for(int loop = 1; loop < wordlist.size(); loop++)
    {
        letters = wordlist[loop];
       
        int wordLength = word.length();
        int letterLength = letters.length();
       
        // creates map
        unordered_map<char,int> map;
       
        //check if it does not match
        if(wordLength != letterLength)
        { continue; }
       
        for(int i = 0; i < wordLength; i++)
        {
            map[word[i]]++;
        }
       
        for(int i = 0; i < letterLength; i++)
        {
            if(map.find(letters[i]) == map.end())
            {
                break;
            }
            else
            {
                map[letters[i]]--;
               
                if(map[letters[i]] == 0)
                {
                    map.erase(letters[i]);
                }
            }
        }
       
        // pushes anagram value back

        if(map.size() == 0)
        { anagrams.push_back(letters);}    
    }
  // returns item
  return anagrams;
}