#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); 
    const int minNumber = 1;
    const int maxNumber = 50; //i have set the limit to 50. it can change as you like.
    const int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
    int guess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n"
         << "I have selected a number between " << minNumber << " and " << maxNumber << ". Try to guess it!\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congrats! You guessed the number " << secretNumber << " correctly in " << attempts << " attempts.\n";
        }
    } while (guess != secretNumber);

    return 0;
}



