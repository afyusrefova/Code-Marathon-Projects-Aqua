#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define RESET   "\033[0m"

#define RED     "\033[1;91m" 
#define YELLOW  "\033[1;93m"  
#define GREEN   "\033[1;92m"
#define BLUE    "\033[0;36m"
#define CYAN    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define GRAY    "\033[1;90m" 
#define MINT    "\033[1;96m"

#define WHITE   "\033[4;37m"
#define BWhite  "\033[1;37m"  
#define UWhite  "\033[4;37m"  

#define BBlack  "\033[1;30m"    
#define BRed    "\033[1;31m"         
#define BGreen  "\033[1;32m"       
#define BYellow "\033[1;33m"      
#define BBlue   "\033[1;34m"       
#define BPurple "\033[1;35m"      
#define BCyan   "\033[1;36m"       
#define BWhite  "\033[1;37m"      


enum class sex
{
    male,
    female,
    nonBinary
};

enum class condition
{
    good,
    average,
    bad
};

enum class state
{
    stable,
    vulnerable,
    endangered
};


struct BIRD
{
    string species = "";
    short int age = 0;
    sex sex = sex::female;
    condition condition = condition::average;
};

struct BIRD_SPECIES
{
    string species_name = "";
    int population = 0;
    state state = state::vulnerable;
    bool migration = false;
    BIRD birds[30];
};


int cinInt()
{
    int number;

    //while loop until the value entered is an integer
    while (!(cin >> number)) {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl;
        cout << RED << "You have to enter a number. Please, try again: " << RESET;
    }

    return number;
}

void initBirds(BIRD* birds, int& index)
{
    birds[0] = { "Lesser White-fronted Goose (Anser erythropus)", 3, sex::female, condition::average };
    birds[1] = { "Lesser White-fronted Goose (Anser erythropus)", 4, sex::male, condition::bad };
    birds[2] = { "Lesser White-fronted Goose (Anser erythropus)", 1, sex::male, condition::good };
    birds[3] = { "Lesser White-fronted Goose (Anser erythropus)", 1, sex::female, condition::good };
    birds[4] = { "Red-breasted Goose (Branta ruficollis)", 5, sex::male, condition::bad };
    birds[5] = { "Red-breasted Goose (Branta ruficollis)", 2, sex::female, condition::good };
    birds[6] = { "Red-breasted Goose (Branta ruficollis)", 6, sex::male, condition::average };
    birds[7] = { "Red-breasted Goose (Branta ruficollis)", 5, sex::female, condition::bad };
    birds[8] = { "Long-tailed Duck (Clangula hyemalis)", 6, sex::female, condition::average };
    birds[9] = { "Long-tailed Duck (Clangula hyemalis)", 3, sex::male, condition::good };
    birds[10] = { "Long-tailed Duck (Clangula hyemalis)", 5, sex::male, condition::bad };
    birds[11] = { "Long-tailed Duck (Clangula hyemalis)", 4, sex::female, condition::good };
    birds[12] = { "White-headed Duck (Oxyura leucocephala)", 1, sex::male, condition::average };
    birds[13] = { "White-headed Duck (Oxyura leucocephala)", 3, sex::male, condition::bad };
    birds[14] = { "White-headed Duck (Oxyura leucocephala)", 4, sex::female, condition::good };
    birds[15] = { "White-headed Duck (Oxyura leucocephala)", 2, sex::female, condition::average };

    index = 16;
}

void displayBird(BIRD* birds, int index)
{
    cout << GRAY << "ID: " << RESET << index + 1 << endl;
    cout << YELLOW << "Species name: " << RESET << birds[index].species << endl;
    cout << GREEN << "Age (in years): " << RESET << birds[index].age << endl;
    cout << CYAN << "Sex: " << RESET;
    if (birds[index].sex == sex::male)
        cout << "Male" << endl;
    else if (birds[index].sex == sex::female)
        cout << "Female" << endl;
    else
        cout << "Non-binary" << endl;

    cout << PURPLE << "Condition: " << RESET;
    if (birds[index].condition == condition::good)
        cout << "Good" << endl;
    else if (birds[index].condition == condition::average)
        cout << "Average" << endl;
    else
        cout << "Bad" << endl;
}

void displayBirds(BIRD* birds, int index)
{
    cout << YELLOW << "List of all birds: " << RESET << endl << endl;

    for (int i = 0; i < index; i++)
    {
        displayBird(birds, i);
        cout << endl << endl;
    }
}


void initBirdSpecies(BIRD* birds, BIRD_SPECIES* birdSpecies, int& speciesIndex)
{
    birdSpecies[0] = { "Lesser White - fronted Goose(Anser erythropus)", 900, state::vulnerable, true, {birds[0], birds[1], birds[2], birds[3]} };
    birdSpecies[1] = { "Red-breasted Goose (Branta ruficollis)", 350, state::endangered, true, {birds[4], birds[5], birds[6], birds[7]} };
    birdSpecies[2] = { "Long-tailed Duck (Clangula hyemalis)", 1100, state::vulnerable, false, {birds[8], birds[9], birds[10], birds[11]} };
    birdSpecies[3] = { "White-headed Duck (Oxyura leucocephala)", 400, state::endangered, false, {birds[12], birds[13], birds[14], birds[15]} };

    speciesIndex = 4;
}


int main()
{

}