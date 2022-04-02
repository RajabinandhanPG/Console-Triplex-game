#include <iostream>
#include <ctime>
void Prep()
{
    std::cout << "\n\n You are a Young adventurer trying to break a series of 3 digit codes to claim a priceless Artifact";
}
void GameIntro(int Difficulty)
{
    
    std::cout << "\n You are at the door number :" << Difficulty;
    std::cout << "\n Enter the correct code to continue.....XoX" ;
}

bool PlayGame(int Difficulty)
{
    GameIntro(Difficulty);
    // this is just declaring variables
    const int CodeA = rand() % Difficulty + Difficulty + 2;
    const int CodeB = rand() % Difficulty + Difficulty + 3;
    const int CodeC = rand() % Difficulty + Difficulty + 4;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    /*
    Now 
    following
    the 
    rest to declare
    */
    std::cout << std::endl;
    std::cout << "-There are three lines in the code \n";
    std::cout << "-The codes add up to : " << CodeSum;
    std::cout << "\n-The codes multiply to give: " << CodeProduct << std::endl;
    
    //Player Guess Goes here
    int GuessA, GuessB, GuessC; 
    std::cout <<  " Enter Your Guess of the three digit code.... \n\n"; 
    std::cin >> GuessA >>  GuessB >> GuessC;
    int GuessSum = GuessA+ GuessB+ GuessC;
    int GuessProduct = GuessA* GuessB* GuessC;

    // Working on the conditions here
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n Gratz, The Door Opened! ";
        return true;
    }
    else
    {
        std::cout << "\n The Door wont even Budge....Try Again ";
        return false; 
    }
   
}

int main()
{
    srand(time(NULL)); // shufflling the difficulty start
    Prep();
    int LevelDifficulty = 1;
    const int MaxDifficulty =3;

    while (LevelDifficulty <= MaxDifficulty) // this mess loops the game till the game is done
    {
      bool bLevelComplete = PlayGame(LevelDifficulty);  
      std::cin.clear(); // clears any buffer
      std::cin.ignore(); // Discards any buffer

      if (bLevelComplete)
      {
          ++LevelDifficulty;
      }
      
    }

    std::cout << "Congrats you have recovered now the Pricesless Artifact!";

    return 0;
}