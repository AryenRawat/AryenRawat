#include <iostream>

void PrintIntroducution(int Difficulty) 
{
  std::cout << "\n\nYou are a ethical hacker at stage " << Difficulty;
  std::cout << "  You have been tasked to recover an account hacked by hecker...\n";
}

bool PlayGame(int Difficulty)
{ 
    PrintIntroducution(Difficulty);
    // Print welcome messages to the terminal
    std::cout <<"Your Account has been hacked by HECKER!!!!\n";
    std::cout <<"You need to find correct codes to beat hecker in his own game and recover your account..\n\n";
    
    

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    // Print sum and product of 3 number code
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    std::cout << std::endl;

    std::cout << "There are 3 numbers in the code\n" ;
    std::cout << "\nThe codes add up to: " <<  CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

    //store player guess

    int GuessA, GuessB, GuessC ;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //checking if player cracks the code or not

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nGreat job u move on to next stage, :)";
        return true;    
    }
    
    else 
    {
        std::cout<< "\nU failed badly,say goodbye to account -_-, pls try again ";
        return false;
    }

}


int main() 
{ 
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)
    { 
       bool bLevelComplete = PlayGame(LevelDifficulty);
       std::cin.clear();//clears errors
       std::cin.ignore();//ignores buffers

       if (bLevelComplete)
      {
        ++LevelDifficulty;
       }
       

    }
    
  std::cout << "\n\nGOOD JOB U CRACKED THE CODE ;), account has been retrieved";
  return 0;
}
