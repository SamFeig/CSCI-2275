#include <iostream>
#include <sstream>
#include <fstream>

/* Friday in-class activity - build a word translator
 * The user should be able to enter a sequence of texting
 * abbreviations and your program needs to output the
 * English translations.
 *
 * For example, if they entered lol brb, your program would
 * display laugh out loud be right back
 *
 * I've included the lecture notes from Wednesday in this file
 * to get you started. You're welcome to use these, or delete
 * them and go a different direction with your code.
 */

using namespace std;

struct Word{
    string abbrev;
    string translate;
    Word(){};
    Word(string a, string t){
        abbrev = a;
        translate = t;
    }
};

Word binarySearch() {

}

int main() {
    Word dict[4267];
    Word word;
    ifstream words;
    string w;
    string abrev;
    string translate;
    string input;

    for(int i = 0; i < 4267; i++) {
        dict[i].abbrev = "";
        dict[i].translate = "";
    }

    words.open("textToEnglish.txt");
    if(words.fail()){
        cout<<"Something went wrong"<<endl;
    }
    else {
        int index = 0;
        while(getline(words, w, '\n')) {
           int split;
           split = w.find('\t');
           abrev = w.substr(0, split);
           translate = w.substr(split+1, w.size());
           dict[index].abbrev = abrev;
           dict[index].translate = translate;
           index++;
        }
    }

    while(input != "end") {
        cout <<"Enter a word to translate. Type \"end\" to end." <<endl;
        //cin >> input;
        getline(cin, input);
        if(input.find(' ') == -1) {
            for(int i = 0; i < 4267; i++) {
                if(dict[i].abbrev == input) {
                    cout <<dict[i].translate <<" " <<endl;
                }
//                else {
//                    cout <<"Abbreviation not found." <<endl;
//                }
            }
//            cout << "Abbreviation not found." << endl;
        }
        else if(input.find(' ') != -1){
            int split;
            split = w.find(' ');

            for (int i = 0; i < 4267; i++) {
                if (dict[i].abbrev == w.substr(0, split) || dict[i].abbrev == w.substr(split + 1, w.size())) {
                    cout << dict[i].translate << endl;
                }
//                else {
//                    cout << "Abbreviation not found." << endl;
//                }
            }
//            cout << "Abbreviation not found." << endl;
        }
    }
    return 0;
}