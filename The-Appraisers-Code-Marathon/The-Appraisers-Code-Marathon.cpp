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



int main()
{

}