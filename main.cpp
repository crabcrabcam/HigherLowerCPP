//Input and Outputs (prints and gets)
#include <iostream>
//Literally for the string class. This feels like Java... :(
#include <string>
//For random numbers
#include <experimental/random>


std::string name;
std::string quitReason;
int total;

//The main loop of the code
void mainLoop()
{
    total = 0;
    quitReason = "";

    std::cout << "I'm going to think of a number between 1 and 100, you need to guess if it's higher or lower" << std::endl;

    int holdNumber = std::experimental::randint(1, 99);

    //Keep running until there's a reason to finish
    while (quitReason == "")
    {

        int newNumber = std::experimental::randint(1, 99);
        std::cout << "The number is: " << holdNumber << std::endl;
        std::cout << "Is the next number higher (h) or lower (l)?" << std::endl;
        //Gets a single character. Hopefully 'h' or 'l'
        std::string ans;
        //Wish I could get 1 char but that's some effort...
        getline(std::cin, ans);

        if (ans == "h")
        {
            if (newNumber > holdNumber)
            {
                std::cout << "Correct!" << std::endl;
                total += 1;
                std::cout << "Your current total is: " << total << std::endl;
                holdNumber = newNumber;
            }
            else if (newNumber < holdNumber)
            {
                std::cout << "Wrong!" << std::endl;
                std::cout << "The number was: " << newNumber << std::endl;
                quitReason = "Wrong";
            }
            else
            {
                std::cout << "REKT!" << std::endl;
                quitReason = "Rekt";
            }
        }
        else if (ans == "l")
        {
            if (newNumber < holdNumber)
            {
                std::cout << "Correct!" << std::endl;
                total += 1;
                std::cout << "Your current total is: " << total << std::endl;
                holdNumber = newNumber;
            }
            else if (newNumber > holdNumber)
            {
                std::cout << "Wrong!" << std::endl;
                std::cout << "The number was: " << newNumber << std::endl;
                quitReason = "Wrong";
            }
            else
            {
                std::cout << "REKT!" << std::endl;
                quitReason = "Rekt";
            }
        }
        else
        {
            std::cout << "That wasn't 'l' or 'h'..." << std::endl;
            continue;
        }

    }
}

//For some reason people seem to use void ints for their functions? I guess if that's the convention I'll use it!
int main(void)
{
	//Print a line
    std::cout << "This is a program that let's you play Higher or Lower!" << std::endl;
    std::cout << "It was written in C++ for me to learn how to write code in it" << std::endl;
    std::cout << "It is almost certainly bad C++, but it should work (just about)" << std::endl;
    //Make the variable for name
    std::cout << "What is your name?: ";
    getline(std::cin, name);
    //Set the name to an input from the user
    //First arg is the input method (cin) and the second arg is the output var

    std::cout << "Right then " << name << " let's get on with the game!" << std::endl;

    while (true)
	{
		mainLoop();

		if (quitReason == "Wrong")
        {
            std::cout << "Your total is: " << total << std::endl;

            std::cout << "Would you like to play again? (y/n)" << std::endl;
            std::string again;
            getline(std::cin, again);

            if (again == "y")
            {
                continue;
            }
            else
            {
                std::cout << "Bye!" << std::endl;
                std::exit(1);
            }
        }

        if (quitReason == "Rekt")
        {
            std::cout << "It was the same, you lose!" << std::endl;
            std::cout << "Your total is: " << total << std::endl;

            std::cout << "Would you like to play again? (y/n)" << std::endl;
            std::string again;
            getline(std::cin, again);

            if (again == "y")
            {
                continue;
            }
            else
            {
                std::cout << "Bye!" << std::endl;
                std::exit(1);
            }
        }

	}
}

