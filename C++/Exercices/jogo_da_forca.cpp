#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    char word[50], letter;
    int limbs = 9, successes = 0, size=0, i;

    cout << "The hangman is a game where you try to find out a word to guesses\n";
    cout << "In this version, if your limbs reach zero this will mean you are dead and you lost...\n";
    cout << "Good Luck, everybody!\n";

    cout << "First, say the secret word: ";
    cin >> word;
    system("cls");
    cout << "Now, call your friend and let him try to find out\n";

    do{
        size++;
    }while(word[size] != '\0');

    char find[size];
    for(i = 0; i < size; i++){
        find[i] = '-';
    }
    find[i] = '\0';

    while(limbs != 0){
        cout << "Tip a letter: ";
        cin >> letter;

        for(i = 0; i < size; i++){
            if(word[i] == letter){
                find[i] = word[i];
                word[i] = '0';
                successes++;
                cout << "The letter " << letter << " is in the word\n";
                break;
            }
        }

        if(i == size){
            cout << "The letter " << letter << " ins't in the word\n";
            limbs--;
        }
        
        system("pause");
        system("cls");
        cout << "Letters finded: " << find << '\n';
        cout << "Successes: " << successes << "\n";
        cout << "Limbs: " << limbs << "\n";

        if(successes == size){
            cout << "Congradulations! You had find the word\n";
            break;
        }

    }

    if(limbs == 0){
        cout << "Game Over!More luck in the next time\n";
    }

    return 0;
}