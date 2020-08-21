#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << "secure server room...\nEnter the correct code to continue...\n\n"
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    std::cout << "You are a secret agent breaking into a secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are three numbers in the code" 
    std::cout << "\n+ The codes add-up to:  " << CodeSum 
    std::cout << "\n+ The codes multiply to give:  " << CodeProduct <<std::end1;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! Keep going! ***"
        return true;
    }
    else
    {
        std::cout << "\n*** Wrong code! Try again! ***"
        return false;
    }
}

int main()
{ 
    srand(time(NULL)); //Create a new random sequence based on the time of the day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = Playgame(LevelDifficulty);
        std::cin.clear(); //Clears errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; 
        }
    }
    std::cout << "\n*** Great work agent! You got all files, now get out of there ***\n" 
    return 0;
}