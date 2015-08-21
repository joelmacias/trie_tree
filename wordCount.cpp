// Joel Macias
// Section 1002
// CS302
// Assignment 6
// wordCount.cpp
// wordCount.h implementation, this contains all the function implementation for the wordCount class.
// The wordCount program will read text files from a directory, parse out words with punctuation between letters, and remove all punctuations from the start or end of a word. It will print various stats about the words it reads, total count,
// number of occurences 

#include <iostream>                  // Provides cout
#include <algorithm>                 // Provides max
#include <cstdlib>                   // Provides NULL
#include <cassert>                   // Provides assert
#include <string>
#include <fstream>
#include <cstddef>
#include "wordCount.h"

using namespace std;

//wordCount imp file


// *****************************************************************
// *****************************************************************
//Constructor
wordCount::wordCount(){
    
    totalWordCount = 0;
    
    docFileName = "";
    
}


// *****************************************************************
// *****************************************************************
// Read document
// Passed argument string fileName will hold the name of the file
bool wordCount::readDocument(const string fileName){
    
    
    docFileName = fileName;
    
    ifstream listOfWords(fileName.c_str());                         // listOfWords contains file
    
    if (!listOfWords) {                                     // If file is not valid return false
        
        cout << "Error could not open file " <<endl;
        return false;
    }
    else{
        
        string dictionaryWord;                              // Dictionary word to be stored
        listOfWords >> dictionaryWord;                      // Read first word
       
        
        bool isItAlpha = true;
        
        
        string doNotInsert = "";
        string dontSend ="";
        
        while (!listOfWords.eof()) {
            for (int   i = 0; i < dictionaryWord.length(); i++) {
               
                
                
                if (isalpha(dictionaryWord[i])) {
                dictionaryWord[i] = tolower(dictionaryWord[i]);
                }
         
                if (!isalpha(dictionaryWord[i])) {
                    
                    if (i > 0 and i < (dictionaryWord.length()-1)) {
                        
                        if (isalpha(dictionaryWord[i-1]) and isalpha(dictionaryWord[i+1])) {
                           // cout<<dictionaryWord<<endl;cout<<"HOR"<<endl;
                            doNotInsert = dictionaryWord;
                            
                            isItAlpha = false;
                        }
                    }
                    
                    
                    
                    if (isItAlpha == true) {
                        
                    
                    dictionaryWord.erase(i,1);
                    i--;
                }
                
                }
               
            }
            if (isItAlpha == true) {
                
                for (size_t k = 0; k < dictionaryWord.length(); k++) {
                    if (isdigit(dictionaryWord[k])) {
                        isItAlpha = false;
                    }
                }
                
                if (isItAlpha == true) {
                    
                    if (dictionaryWord != "" and dictionaryWord != doNotInsert) {
                        totalWordCount++;
                        
                        wordTree.insert(dictionaryWord);
                    //cout<<"\t"<<dictionaryWord<<endl;
                    
                    }
                }
            }
            isItAlpha = true;
            listOfWords >> dictionaryWord;
        }
        
    }

   
        return true;

    
    return true;
}


// *****************************************************************
// *****************************************************************
// Show doc file name
void wordCount::showDocumentFileName() const{
    
    cout<< "Document File Name: " << docFileName << endl;
    
    
}

// *****************************************************************
// *****************************************************************
// Show total count

void wordCount::showTotalWordCount() const{
    
    cout<< "Total Word Count: " << totalWordCount <<endl;
    
}

// *****************************************************************
// *****************************************************************
// Show unique word count

void wordCount::showUniqueWordCount() const{
    cout <<"Unique Word Count: " << wordTree.countWords() << endl;
}

// *****************************************************************
// *****************************************************************
// show tree height
void wordCount::showTreeHeight() const{
    
    cout <<"Tree Height: " << wordTree.height() << endl;
    
}

// *****************************************************************
// *****************************************************************
// tree count

void wordCount::showTreeNodeCount() const{
    cout << "Tree Node Count: " << wordTree.countNodes() << endl;
}

// *****************************************************************
// *****************************************************************
// get max node
// passed arguments int&x will hold the number of the maxnode, and string&y will hold the word with the maxnode
void wordCount::getMaxNode(unsigned int & x, string & y){
    
    x = 0;
    y = ""; 
    
    wordTree.getMaxNode(x, y);
    
}

// *****************************************************************
// *****************************************************************
// print tree
void wordCount::printTree() const{
    
    
    wordTree.printTree();
    
}

// *****************************************************************
// *****************************************************************
// get word count
// the passed argument string theWord will hold the word for which we are searching the count for
unsigned int wordCount::getWordCount(string theWord) const{
    
    if (!isalpha(theWord[0])) {
        return 0;
    }
    
    for (int i = 0; i < theWord.length(); i++) {
        theWord[i] = tolower(theWord[i]);
    }
    
    //cout<<"the Word "<<theWord<<endl;
    return wordTree.getWordCount(theWord);
    

}
