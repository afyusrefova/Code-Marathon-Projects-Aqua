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


//void displayMainMenu(BIRD* birds, int& birdIndex, BIRD_SPECIES* birdSpecies, int& speciesIndex);

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
    cout << GRAY << "List of all birds: " << RESET << endl << endl;

    for (int i = 0; i < index; i++)
    {
        displayBird(birds, i);
        cout << endl << endl;
    }
}

void enterBird(BIRD* birds, int& index)
{
    int choice;

    cout << GRAY << "Enter info about bird:" << RESET << endl;

    cout << YELLOW << "Name of species: " << RESET;
    cin >> birds[index].species;

    cout << GREEN << "Age (in years): " << RESET;
    birds[index].age = cinInt();

    cout << CYAN << "Sex (1-M, 2-F, 3-NB): " << RESET;
    choice = cinInt();

    if (choice == 1)
        birds[index].sex = sex::male;
    else if (choice == 2)
        birds[index].sex = sex::female;
    else
        birds[index].sex = sex::nonBinary;


    cout << PURPLE << "Condition (1-G, 2-A, 3-B): " << RESET;
    choice = cinInt();

    if (choice == 1)
        birds[index].condition = condition::good;
    else if (choice == 2)
        birds[index].condition = condition::average;
    else
        birds[index].condition = condition::bad;

    index++;
}

void deleteBird(BIRD* birds, int& index)
{
    int position;

    cout << GRAY << "Enter the ID of the bird you would like to remove from the list: " << RESET;
    position = cinInt();
    position -= 1;

    for (int i = position; i < index - 1; i++)
    {
        birds[i] = birds[i + 1];
    }

    index--;
}

void editBird(BIRD* birds, int& index)
{
    int position;
    cout << GRAY << "Enter the ID of the bird you would like to edit: " << RESET;
    cin >> position;
    position -= 1;

    enterBird(birds, position);
    
}

void sortBirdsBySpecies(BIRD* birds, int& index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (birds[j].species > birds[j + 1].species)
            {
                BIRD temp = birds[j];
                birds[j] = birds[j + 1];
                birds[j + 1] = temp;
            }
        }
    }

    displayBirds(birds, index);
}

void sortBirdsByAge(BIRD* birds, int& index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (birds[j].age > birds[j + 1].age)
            {
                BIRD temp = birds[j];
                birds[j] = birds[j + 1];
                birds[j + 1] = temp;
            }
        }
    }

    displayBirds(birds, index);
}

void sortBirdsBySex(BIRD* birds, int& index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (birds[j].sex > birds[j + 1].sex)
            {
                BIRD temp = birds[j];
                birds[j] = birds[j + 1];
                birds[j + 1] = temp;
            }
        }
    }

    displayBirds(birds, index);
}

void sortBirdsByCondition(BIRD* birds, int& index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (birds[j].condition > birds[j + 1].condition)
            {
                BIRD temp = birds[j];
                birds[j] = birds[j + 1];
                birds[j + 1] = temp;
            }
        }
    }

    displayBirds(birds, index);
}

void filterBirdsBySpecies(BIRD* birds, int& index)
{
    string filter;
    cout << GRAY << "Enter the species of birds which you want to see: " << RESET;
    getline(cin, filter);

    cout << endl;

    int count = 0;

    for (int i = 0; i < index; i++)
    {
        if (birds[i].species == filter)
        {
            displayBird(birds, i);
            cout << endl << endl;
            count++;
        }
    }

    if (count == 0)
        cout << RED << "Sorry, we couldn't find any birds of the species you are looking for!" << RESET << endl;
}

void filterBirdsByAge(BIRD* birds, int& index)
{
    int filter;
    cout << GRAY << "Enter the age of birds which you want to see: " << RESET;
    filter = cinInt();

    cout << endl;

    int count = 0;

    for (int i = 0; i < index; i++)
    {
        if (birds[i].age == filter)
        {
            displayBird(birds, i);
            cout << endl << endl;
            count++;
        }
    }

    if (count == 0)
        cout << RED << "Sorry, we couldn't find any birds of the age you are looking for!" << RESET << endl;
}

void filterBirdsBySex(BIRD* birds, int& index)
{
    int filter;
    cout << GRAY << "Enter the sex of birds which you want to see (1-M, 2-F, 3-NB): " << RESET;
    filter = cinInt();

    cout << endl;

    int count = 0;

    for (int i = 0; i < index; i++)
    {
        if (filter == 1)
        {
            if (birds[i].sex == sex::male)
            {
                displayBird(birds, i);
                cout << endl << endl;
                count++;
            }
        }
        else if (filter == 2)
        {
            if (birds[i].sex == sex::female)
            {
                displayBird(birds, i);
                cout << endl << endl;
                count++;
            }
        }
        else if (filter == 3)
        {
            if (birds[i].sex == sex::nonBinary)
            {
                displayBird(birds, i);
                cout << endl << endl;
                count++;
            }
        }
    }

    if (count == 0)
    {
        cout << RED << "Sorry, we couldn't find any birds of the sex you are looking for!" << RESET << endl;
    }
}

void filterBirdsByCondition(BIRD* birds, int& index)
{
    int filter;
    cout << GRAY << "Enter the condition of birds which you want to see (1-G, 2-A, 3-B): " << RESET;
    filter = cinInt();

    cout << endl;

    int count = 0;

    for (int i = 0; i < index; i++)
    {
        if (filter == 1)
        {
            if (birds[i].condition == condition::good)
            {
                displayBird(birds, i);
                cout << endl << endl;
                count++;
            }
        }
        else if (filter == 2)
        {
            if (birds[i].condition == condition::average)
            {
                displayBird(birds, i);
                cout << endl << endl;
                count++;
            }
        }
        else if (filter == 3)
        {
            if (birds[i].condition == condition::bad)
            {
                displayBird(birds, i);
                cout << endl << endl;
                count++;
            }
        }
    }

    if (count == 0)
        cout << RED << "Sorry, we couldn't find any birds of the condition you are looking for!" << RESET << endl;
}


void initBirdSpecies(BIRD* birds, BIRD_SPECIES* birdSpecies, int& speciesIndex)
{
    birdSpecies[0] = { "Lesser White - fronted Goose(Anser erythropus)", 900, state::vulnerable, true, {birds[0], birds[1], birds[2], birds[3]} };
    birdSpecies[1] = { "Red-breasted Goose (Branta ruficollis)", 350, state::endangered, true, {birds[4], birds[5], birds[6], birds[7]} };
    birdSpecies[2] = { "Long-tailed Duck (Clangula hyemalis)", 1100, state::vulnerable, false, {birds[8], birds[9], birds[10], birds[11]} };
    birdSpecies[3] = { "White-headed Duck (Oxyura leucocephala)", 400, state::endangered, false, {birds[12], birds[13], birds[14], birds[15]} };

    speciesIndex = 4;
}

void displayBirdSpecies(BIRD_SPECIES* birdSpecies, int index)
{
    cout << GRAY << "ID: " << RESET << index + 1 << endl;

    cout << YELLOW << "Species name: " << RESET << birdSpecies[index].species_name << endl;

    cout << GREEN << "Population: " << RESET << birdSpecies[index].population << endl;

    cout << CYAN << "State: " << RESET;
    if (birdSpecies[index].state == state::stable)
        cout << GREEN <<"Stable" << RESET << endl;
    else if (birdSpecies[index].state == state::vulnerable)
        cout << YELLOW <<"Vulnerable" << RESET << endl;
    else
        cout << RED << "Endangered" << RESET << endl;

    cout << PURPLE << "Do they migrate: " << RESET;
    if (birdSpecies[index].migration == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void displayAllBirdSpecies(BIRD_SPECIES* birdSpecies, int index)
{
    cout << YELLOW << "List of all species: " << RESET << endl << endl;

    for (int i = 0; i < index; i++)
    {
        displayBirdSpecies(birdSpecies, i);
        cout << endl << endl;
    }
}


bool returnBack()
{
    int choice;

    cout << endl;
    cout << "What would you like to do now?" << endl << endl;
    cout << GREEN << "1)" << RESET << " Stay in this menu" << endl;
    cout << GRAY << "2)" << RESET << " Go back to the main menu" << endl << endl;
    cout << "Enter your choice: ";

    choice = cinInt();

    while (choice > 2 or choice < 1)
    {
        cout << endl;
        cout << RED << "The number you enter has to be either 1 or 2! Please, try again: " RESET;
        choice = cinInt();
    }

    cout << endl;

    system("cls");

    if (choice == 1)
        return true;

    return false;
}



void displayBirdsMenu(BIRD* birds, int& birdIndex, BIRD_SPECIES* birdSpecies, int& speciesIndex)
{
    bool cont = true;

    while (cont == true)
    {
        int choice = 0;

        cout << endl;
        cout << GREEN << "  ____  _         _     "<< endl;
        cout << " |  _ \\(_)       | |    " << endl;
        cout << " | |_) |_ _ __ __| |___ " << endl;
        cout << " |  _ <| | '__/ _` / __|" << endl;
        cout << " | |_) | | | | (_|\\__ \\" << endl;
        cout << " |____/|_|_|  \\___|___/" << endl << endl << RESET;
        cout << " =======================================" << endl;
        cout << "|" << " 1)" << CYAN << " Show a list of all birds    " << RESET << "       |" << endl;
        cout << "|" << " 2)" << GREEN << " Add a new bird         " << RESET << "            |" << endl;
        cout << "|" << " 3)" << RED << " Delete a bird        " << RESET << "              |" << endl;
        cout << "|" << " 4)" << BLUE << " Edit info about a bird    " << RESET << "         |" << endl;
        cout << "|" << " 5)" << PURPLE << " Show filtered list     " << RESET << "            |" << endl;
        cout << "|" << " 6)" << YELLOW << " Show sorted list     " << RESET << "              |" << endl;
        cout << "|" << " 7)" << GRAY << " Return back to the Main Menu    " << RESET << "   |" << endl;
        cout << " =======================================" << endl << endl;

        cout << "Enter your choice: ";
        choice = cinInt();

        while (choice > 7 or choice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 7! Please, try again: " << RESET;
            choice = cinInt();
        }

        system("cls");

        switch (choice)
        {
        case 1:
            displayBirds(birds, birdIndex);
            cont = returnBack();
            break;
        case 2:
            enterBird(birds, birdIndex);
            cont = returnBack();
            break;
        case 3:
            deleteBird(birds, birdIndex);
            cont = returnBack();
            break;
        case 4:
            editBird(birds, birdIndex);
            cont = returnBack();
            break;
        case 5:
            int option;

            cout << "How would you like to filter the birds?" << endl << endl;
            cout << "1. By species" << endl;
            cout << "2. By age" << endl;
            cout << "3. By sex" << endl;
            cout << "4. By condition" << endl<<endl;
            cout << "Enter your choice: ";
            option = cinInt();

            while (option > 4 or option < 1)
            {
                cout << endl;
                cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
                option = cinInt();
            }

            system("cls");

            if (option == 1)
                filterBirdsBySpecies(birds, birdIndex);
            else if (option == 2)
                filterBirdsByAge(birds, birdIndex);
            else if (option == 3)
                filterBirdsBySex(birds, birdIndex);
            else
                filterBirdsByCondition(birds, birdIndex);

            cont = returnBack();
            break;

        case 6:
            cout << "How would you like to sort the birds?" << endl << endl;
            cout << "1. By species" << endl;
            cout << "2. By age" << endl;
            cout << "3. By sex" << endl;
            cout << "4. By condition" << endl << endl;
            cout << "Enter your choice: ";
            option = cinInt();

            while (option > 4 or option < 1)
            {
                cout << endl;
                cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
                option = cinInt();
            }

            system("cls");

            if (option == 1)
                sortBirdsBySpecies(birds, birdIndex);
            else if (option == 2)
                sortBirdsByAge(birds, birdIndex);
            else if (option == 3)
                sortBirdsBySex(birds, birdIndex);
            else
                sortBirdsByCondition(birds, birdIndex);

            cont = returnBack();
            break;
        case 7:
            cont = false;
            break;
        }
    }
}

void displayBirdSpeciesMenu(BIRD* birds, int& birdIndex, BIRD_SPECIES* birdSpecies, int& speciesIndex)
{
    bool cont = true;

    while (cont == true)
    {
        int choice = 0;

        cout << endl;
        cout << CYAN << "   _____                 _           " << endl;
        cout << "  / ____|               (_)          " << endl;
        cout << " | (___  _ __   ___  ___ _  ___  ___ " << endl;
        cout << "  \\___ \\| '_ \\ / _ \\/ __| |/ _ \\/ __|" << endl;
        cout << "  ____) | |_) |  __/ (__| |  __/\\__ \\" << endl;
        cout << " |_____/| .__/ \\___|\\___|_|\\___||___/" << endl;
        cout << "        | |                          " << endl;
        cout << "        |_|                          " << endl << endl << RESET;
        cout << " =======================================" << endl;
        cout << "|" << " 1)" << YELLOW << " Show a list of all birds    " << RESET << "       |" << endl;
        cout << "|" << " 2)" << GRAY << " Return back to the Main Menu    " << RESET << "   |" << endl;
        cout << " =======================================" << endl << endl;

        cout << "Enter your choice: ";
        choice = cinInt();

        while (choice > 2 or choice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 2! Please, try again: " << RESET;
            choice = cinInt();
        }

        system("cls");

        switch (choice)
        {
        case 1:
            displayAllBirdSpecies(birdSpecies, speciesIndex);
            cont = returnBack();
            break;
       
        case 2:
            cont = false;
            break;
        }
    }
}

void displayMainMenu(BIRD* birds, int& birdIndex, BIRD_SPECIES* birdSpecies, int& speciesIndex)
{
    int choice = 0;

    while (choice != 3)
    {
        cout << endl;

        cout << " __  __       _         __  __                      " << endl;
        cout << "|  \\/  |     (_)       |  \\/  |                   " << endl;
        cout << "| \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _   " << endl;
        cout << "| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| |  | | (_| | | | | | | |  | |  __/ | | | |_| |    " << endl;
        cout << "|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_| " << endl;

        cout << endl;
        cout << endl;

        cout << "Which set of data would you like to work with?" << endl << endl;
        cout << " =====================" << endl;
        cout << "|" << " 1)" << GREEN << " Birds" << RESET <<"            |" << endl;
        cout << "|" << " 2)" << CYAN << " Species Of birds" << RESET << " |" << endl;
        cout << "|" <<  " 3)" <<PURPLE << " Exit" << RESET << "             |" << endl;
        cout << " =====================" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        choice = cinInt();

        while (choice > 3 or choice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 3! Please, try again: " << RESET;
            choice = cinInt();
        }

        system("cls");

        switch (choice)
        {
        case 1:
            displayBirdsMenu(birds, birdIndex, birdSpecies, speciesIndex);
            break;
        case 2:
            displayBirdSpeciesMenu(birds, birdIndex, birdSpecies, speciesIndex);
            break;
        case 3:
            exit(0);
            break;
        }
    }

}

int main()
{
    BIRD* birds = new BIRD[300];
    BIRD_SPECIES* birdSpecies = new BIRD_SPECIES[100];
    int birdIndex = 0, speciesIndex = 0;

    initBirds(birds, birdIndex);
    initBirdSpecies(birds, birdSpecies, speciesIndex);

    displayMainMenu(birds, birdIndex, birdSpecies, speciesIndex);
}