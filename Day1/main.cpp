#include <iostream>
#include <fstream>

using namespace std;

int calc_fuel (int mass)
{
    int fuel = (mass/3)-2;

    if(fuel > 6)
    {
        fuel += calc_fuel(fuel);
    }

    return fuel;

}

int main ()
{

    ifstream input_file;
    input_file.open("input.txt");

    if(!input_file) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    /*
    int input_val;
    int sum = 0;

    while( input_file >> input_val)
    {
        sum += ((input_val/3)-2);
    }

    cout << "Part one answer: " << sum << endl;
    */

    int input_val = 0;
    int sum = 0;
    
    while( input_file >> input_val)
    {
        sum += calc_fuel(input_val);
    }

    input_file.close();

    cout << "Part two answer: " << sum << endl;

    return 0;
}