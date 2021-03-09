# include <iostream>

using namespace std;

int main(void){

    int lifes=0; // '2'
    char letters = 'a'; // 'o'
    double decimal = 2.5; // 2.5
    bool alive = 0; // true = 1; false = 0

    cout << "Number of lifes: ";
    cin >> lifes;
    cout << "Tip a letter: ";
    cin >> letters;
    cout << "Tip a decimal number: ";
    cin >> decimal;
    cout << "Tip 1 to alive or 0 to dead: ";
    cin >> alive;

    cout << lifes << "\n" << letters << "\n" << decimal << "\n" << alive << "\n";

    return 0;
}