# Hangman-game-in-C
🎮This is a simple implementation of the Hangman game in C. The user has to guess a randomly chosen word by guessing the letters one by one. If they make more than 10 mistakes, they lose the game.

## 📙Libraries used

-   `stdio.h`
-   `stdlib.h`
-   `string.h`
-   `time.h`
-   `stdbool.h`

## Constants used

-   `MAX` : Maximum number of characters for the word.
-   `MAXP` : Maximum number of words inside the file.
-   `INTENTOS` : Maximum number of attempts the user can make.

## Variables used

-   `fichero` : Pointer to the file that contains the words.
-   `palabra` : Array to save the randomly chosen word.
-   `secreto` : Array to save the word in secret format (with underscores).
-   `creencia` : Array to save the guessed word by the user.
-   `c` : Character variable to read characters from the file.
-   `a` : Integer variable to keep track of the number of words read from the file.
-   `numletras` : Integer variable to keep track of the number of letters in the chosen word.
-   `nombre` : Array to save the name of the user.
-   `encontrado` : Boolean variable to check if the randomly chosen word has been found.
-   `numero` : Integer variable to store the randomly generated number.
-   `inte` : Integer variable to keep track of the number of attempts made by the user.
-   `letras` : Array to save the letters guessed by the user.
-   `completo` : Boolean variable to check if the user has completed the word.
-   `esta` : Boolean variable to check if the guessed letter is in the word.
-   `repetida` : Boolean variable to check if the guessed letter has been guessed before.
-   `cont` : Integer variable to keep track of the number of mistakes made by the user.

## 🤔How to run the program

1.  Compile the program with the following command: `gcc hangman.c -o hangman`.
2.  Run the program with the following command: `./hangman`.

## 😋How to play the game

1.  The program will ask for your name. Enter your name and press enter.
2.  The program will choose a word at random. The word will be displayed as a series of underscores.
3.  You will be asked to guess a letter. Enter a letter and press enter.
4.  If the letter is in the word, it will be displayed in the correct position(s).
5.  If the letter is not in the word, you will lose one of your attempts.
6.  You can guess a letter or try to guess the entire word at any time by entering 0.
7.  If you guess the entire word correctly, you win the game.
8.  If you make 10 mistakes, you lose the game.

## Sample output

    Welcome to the Hangman game. What is your name?
    Alice
    
    Hello Alice, let's start the game!
    
    _ _ _ _ _ _ _ _ _ _
    You have 10 attempts left. Alice, what letter do you guess? a
    
    _ _ _ _ _ _ _ _ _ _
    You have 9 attempts left. Alice, what letter do you guess? e
    
    _ _ _ _ _ _ _ _ _ _
    You have 8 attempts left. Alice, what letter do you guess? i
    
    _ _ _ _ _ _ _ _ _ _
    You have 7 attempts left. Alice, what letter do you guess? o
    
    _ _ _ _ _ _ _ _ _ _
    You have 7 attempts left. Alice, what letter
