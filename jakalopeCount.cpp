/*
    Aleksandr Movsesyan
    CS 110 A
    Craig Persiko
    Practice Problem 4
    pp4.cpp

    This program finds the number of jackalope after a certain number of
    generations.
  */

#include <iostream>
using namespace std;

int new_pop( int pop, int num_gen);

int main()
{

  int num_of_jakalopes, num_years_passed, total_jakalopes;
  char cont;

  cout << "\n\nHello and welcome to the Jakalope population calculator.";

  do
  {
    do
    {
      cout << "\nPlease enter the number of Jakalope you have : ";
      cin >> num_of_jakalopes;
      if ( num_of_jakalopes <= 0 )
      {
        cout << "Error 256: Can not have a negative population." << endl;
      }
    }while ( num_of_jakalopes <= 0 );
    do
    {
      cout << "Enter the number of generations you would like to wait: ";
      cin >> num_years_passed;
      if ( num_years_passed <= 0 )
      {
        cout << "Error 401: Some time must pass. The number of generations must
me positive.\n" << endl;
      }
    }while ( num_years_passed <= 0 );

    total_jakalopes = new_pop( num_of_jakalopes, num_years_passed);

    cout << "\nIf you start with " << num_of_jakalopes << " jackalopes and wait
" << num_years_passed <<" generations, ";
    cout << "you'll end up with a total of " << total_jakalopes << " of them."
<< endl;
    cout << "\nDo you want to calculate another population? ";
    cin >> cont;

    if ( cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N' )
    {
      do
      {
        cout  << "Press y for yes and n for no and then hit return:  ";
        cin >> cont;
      }while ( cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N' );
    }
  }while ( (cont == 'y') || (cont == 'Y') );

  cout << "\nThank you for using the Jakalope population calculator. Have a nice
day.\n" << endl;

  return 0;
}

int new_pop( int pop, int num_gen)
{

  int jakalopes_born, jakalopes_died, elapsed_years = 0;
  const float birth_rate = 0.03, death_rate = 0.01;

  while ( num_gen > elapsed_years )
  {
    jakalopes_born = pop * birth_rate;
    pop += jakalopes_born;
    jakalopes_died = pop * death_rate;
    pop -= jakalopes_died;
    num_gen --;
  }

  return pop;
}
