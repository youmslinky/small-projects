#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
// https://www.hackerrank.com/challenges/crossword-puzzle
// left off at making a way to detect where the words should go, I guess I'm planning on pre-searching through the board to find word slots and then it will make it easy to match the word length the the word slots.

// 3-14-17
//  left off finding and storing horizontal wordslots

class word{
public:
    string contents;
    int wordLength;
    // word(){ //old method of reading in words, don't use
    //     getline(cin,contents,';');
    //     wordLength = contents.length();
    // }
    word(string input){
        contents = input;
        wordLength = contents.length();
    }

    void print(){
        cout << contents << endl;
    }
    int length(){
        return wordLength;
    }

    
};

bool operator < (const word& word1, const word& word2){
    return (word1.contents < word2.contents);
}

class wordSlot{
public:

    int length;
    int startX; //spaces[Y][X]
    int startY;
    char direction; //r for right, d for down

    deque <word> matchingWords;

    wordSlot(int newLength,int newStartX,int newStartY,char newDirection){
        length = newLength;
        startX = newStartX;
        startY = newStartY;
        direction = newDirection;
    }

};

class board{
    public:
    char spaces[10][10];    //master copy of board, don't overwrite this board!
    char filled[10][10];    //copy of the board used as a place to test out if words fit or not.  at the end of the program, this should contain the finished crossword puzzle.  
    char backup[10][10];   //copy of previous filled board for rollBack to use

    deque <wordSlot> wordSlots;
    deque <word> wordList;

    //default constructor, reads in the board from stdin and also copies it into the filled board
    board(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                spaces[i][j] = getchar();
                filled[i][j] = spaces[i][j];
            }
            cin.ignore();
            
        }
        readWords();
        findWordSlots();
        findMatchingLengths();
    }

    //reads words off of stdin
    void readWords(){
        stringstream allWordsStream;
        string allWords;
        string word;

        getline(cin,allWords);
        allWordsStream << allWords;
        while(getline(allWordsStream,word,';')){
            //cout << word << endl;
            wordList.push_back(word);
        }


        // while(cin.good()){
        //     word nextWord;
        //     wordList.push_back(nextWord);
        // }
    }
    
    
    //prints out the filled board in it's current state
    void print(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout << filled[i][j];
            }
            cout << endl;
        }
    }

    //resets the filled board, aka, something doesn't fit right, so we need to retry.
    void reset(){ 
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                filled[i][j] = spaces[i][j];
            }     
        }
    }

    void findWordSlots(){
        //run horizontal word slot check
        int wordLength = 0; //length of the wordslot we are on
        bool onSlot = 0;    //are we currently on a potential horizontal word slot?
        int startXPos,startYPos;

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                
                if(spaces[i][j] == '-' && onSlot == true){
                    wordLength++;
                }
                
                if(spaces[i][j] == '-' && onSlot == false){
                    wordLength++;
                    startYPos = i;
                    startXPos = j;
                    onSlot = 1;  //we found a potentioal word slot
                }

                if(spaces[i][j] == '+' && onSlot == false){
                    onSlot = 0;
                }

                if(spaces[i][j] == '+' && onSlot == true || wordLength == 10 || j==9){
                    //only store word slot if it is bigger than 1
                    if(wordLength > 1){
                        wordSlot newSlot(wordLength,startXPos,startYPos,'r');
                        wordSlots.push_back(newSlot);
                    }
                    wordLength = 0;
                    onSlot = 0;
                }
            }
            wordLength = 0;
            onSlot = 0;
        }


        for(int j=0;j<10;j++){
            for(int i=0;i<10;i++){
                
                if(spaces[i][j] == '-' && onSlot == true){
                    wordLength++;
                }
                
                if(spaces[i][j] == '-' && onSlot == false){
                    wordLength++;
                    startYPos = i;
                    startXPos = j;
                    onSlot = 1;  //we found a potentioal word slot
                }

                if(spaces[i][j] == '+' && onSlot == false){
                    onSlot = 0;
                }

                if(spaces[i][j] == '+' && onSlot == true || wordLength == 10 || i==9){
                    //only store word slot if it is bigger than 1
                    if(wordLength > 1){
                        wordSlot newSlot(wordLength,startXPos,startYPos,'d');
                        wordSlots.push_back(newSlot);
                    }
                    wordLength = 0;
                    onSlot = 0;
                }
            }
            wordLength = 0;
            onSlot = 0;
        }
    }

    void findMatchingLengths(){
        for(int i=0;i< wordSlots.size();i++){
            
            //cout << "wordSlot length: " << wordSlots[i].length << endl;

            for(int j=0;j< wordList.size();j++){

                //cout << "current word: " << wordList[j].contents << ' ';
                //cout << "current word length: " << wordList[j].length() << ' ';
                
                if(wordList[j].length() == wordSlots[i].length){
                    wordSlots[i].matchingWords.push_back(wordList[j]);

                    //cout << "MATCH";
                
                }
                //cout << endl;
            }
            //cout << endl;
        }
    }

    int putWordInSlot(wordSlot slot,word currentWord){
        //i is y
        //j is x
        if(slot.length != currentWord.length()){
            return 0;   //lengths don't match, this isn't the right word for the slot
        }

        if(slot.direction == 'r'){
            for(int j=0;j<slot.length;j++){
                if(filled[slot.startY][slot.startX+j] == '-'){
                    filled[slot.startY][slot.startX+j] = currentWord.contents[j];
                }
                if(filled[slot.startY][slot.startX+j] != currentWord.contents[j]){
                    return 0;   //placing word failed because mismatched word
                }
            }
        }
        else{
            for(int i=0;i<slot.length;i++){
                if(filled[slot.startY+i][slot.startX] == '-'){
                    filled[slot.startY+i][slot.startX] = currentWord.contents[i];
                }
                if(filled[slot.startY+i][slot.startX] != currentWord.contents[i]){
                    return 0;   //placing word failed because mismatched word
                }
            }
        }
        return 1;   //putting word in was succesful, return true value
    }

    //rolls back the board to backup
    void rollBack(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                filled[i][j] = backup[i][j];
            }
        }
    }

    void updateBackup(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                backup[i][j] = filled[i][j];
            }
        }
    }



};




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    board cb;   //cb stands for crossword board, made it short so easy to type
    //cb.print();


    
    
    // cout << "size of words deque: " << cb.wordList.size() << endl;
    // for(int i=0;i< cb.wordList.size();i++){
    //     cb.wordList[i].print();
    // }

    for(int j=0;j< cb.wordList.size();j++){
        cout << cb.wordList[j].contents << ' ';
    }
    cout << endl;

    sort(cb.wordList.begin(),cb.wordList.end());

    int exitFlag=1;//change to 1 if we the current permutation is good
    do{
        cb.reset();
        exitFlag=1;
        for(int i=0;i<cb.wordSlots.size();i++){

            for(int j=0;j< cb.wordList.size();j++){
                cout << cb.wordList[j].contents << ' ';
            }
            cout << endl;
            cb.print();
            cout << endl;

            if(cb.putWordInSlot(cb.wordSlots[i],cb.wordList[i]) == 0){
                exitFlag=0;
                break;
            }
        }

        if(exitFlag){
            break;
        }

    } while(next_permutation(cb.wordList.begin(),cb.wordList.end()));

    cb.print();
    

    for(int i=0;i< cb.wordSlots.size();i++){
        cout << "length: " << cb.wordSlots[i].length << endl;
        cout << "startX: " << cb.wordSlots[i].startX << endl;
        cout << "startY: " << cb.wordSlots[i].startY << endl;
        cout << "direction: " << cb.wordSlots[i].direction << endl << endl;
    }

    // cout << "size of wordSlots deque: " << cb.wordSlots.size() << endl;
    // cout << words[0].length();

    // for(int i=0;i < cb.wordList.size(); i++){
    //     cb.wordList[i].print();
    // }

    // for(int i=0;i < cb.wordSlots.size() ;i++){
    //     cout << "slot length: " << cb.wordSlots[i].length << endl;
    //     cout << "matching words for slot: ";
    //     for(int j=0;j < cb.wordSlots[i].matchingWords.size() ;j++){
    //         cout << cb.wordSlots[i].matchingWords[j].contents << ' ';
    //     }
    //     cout << endl << endl;
    // }

    //we can know for sure that the words slots with only 1 match can be filled
    // for(int i=0;i<cb.wordSlots.size();i++){
    //     if(cb.wordSlots[i].matchingWords.size() == 1){
    //         cb.putWordInSlot(cb.wordSlots[i],cb.wordSlots[i].matchingWords[0]);
    //     }
    // }



    // int done = 0;
    // while(done != 10){

    //     for(int i=0;i<cb.wordSlots.size();i++){
    //         if(cb.wordSlots[i].matchingWords.size() == 1){
    //             cb.putWordInSlot(cb.wordSlots[i],cb.wordSlots[i].matchingWords[0]);
    //         }
    //     }


    //     for(int i=0;i<cb.wordSlots.size();i++){
    //         if(cb.wordSlots[i].matchingWords.size() != 1){
    //             for(int j=0;j<cb.wordSlots.size();j++){
    //                 if(!cb.putWordInSlot(cb.wordSlots[i],cb.wordSlots[i].matchingWords[j])) {
    //                     cb.reset();
    //                     break;
    //                 }
    //             }
            
    //         }
    //     }
    
    //     done++;
    // }


    // for(int i=0;i<cb.wordSlots.size();i++){
    //     for(int j=0;j<cb.wordList.size();j++){

    //         if(cb.wordSlots[i].length == cb.wordList[j].length()){
    //             if(cb.putWordInSlot(cb.wordSlots[i],cb.wordList[j])){
    //                 cb.updateBackup();  //putting word in slot success, save board for next word slot
    //                 //break;  //break out of for loop, we found the right word
    //             }
    //             else{
    //                 cb.rollBack();  //putting word in slot failed, roll back
    //             }
    //         }

    //     }
    // }



    //cout << cb.wordSlots[1].matchingWords.size() << endl;
    return 0;
}
