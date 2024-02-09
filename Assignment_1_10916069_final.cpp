//Assignment 1
//A program calculate the transition energy duing electron transition
//U Hin Lo, 10916069, 09/02/2024
#include <iostream>
#include <iomanip>

double calculate_transition_energy(int atomic_number, int n_i, int n_f)
{
  return 13.6 * atomic_number * atomic_number * (1.0 / (n_f * n_f) - 1.0 / (n_i * n_i));
}

int main()
{
  int z, n_initial, n_final;
  char unit, repeat;
  bool choose{1};
  while(choose == 1)
  {
    //Gather values of atomic number and check its validity
    std::cout<<"Enter the atomic number Z: "<<std::endl;
    while(!(std::cin>>z) || z <= 0)
      {
        std::cerr<<"Invalid input. Please enter a positive integer for atomic number."<<std::endl;
        std::cout<<"Enter the atomic number Z: "<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
    //Gather values of initial quantum number and check its validity
    std::cout<<"Enter the initial quantum number: "<<std::endl;
    while(!(std::cin>>n_initial) || n_initial <= 0)
      {
        std::cout<<"Invalid input. Please enter a positive integer for initial quantum number."<<std::endl;
        std::cout<<"Enter the initial quantum number: "<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
    //Gather values of final quantum number and check its validity
    std::cout<<"Enter the final quantum number: "<<std::endl;
    while(!(std::cin>>n_final) || n_final <= 0 || n_final >= n_initial)
      {
        std::cout<<"Invalid input. Please enter a positive integer for final quantum number that is less than the initial quantum number."<<std::endl;
        std::cout<<"Enter the final quantum number: "<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
    double energy = calculate_transition_energy(z, n_initial, n_final);
    //Ask for the unit and check its validity
    std::cout<<"Enter the unit of the energy (Joules (j) or eV (e)): "<<std::endl;
    while(!(std::cin>>unit) || (unit != 'J' && unit != 'j' && unit != 'E' && unit != 'e'))
      {
        std::cout<<"Invalid input. Please enter either 'j' for Joules or 'e' for eV."<<std::endl;
        std::cout<<"Enter the unit of the energy (Joules (j) or eV (e)): "<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
    if(unit == 'J' || unit == 'j')
      {
        std::cout<<"The energy of the transition is "<<std::setprecision(3)<<energy*1.602e-19<<" Joules."<<std::endl;
      }
    else if(unit == 'E' || unit == 'e')
      {
        std::cout<<"The energy of the transition is "<<std::setprecision(3)<<energy<<" eV."<<std::endl;
      }
    //Ask if repeat or not
    std::cout<<"Would you like to calculate another transition (y/n)? :"<<std::endl;
    while(!(std::cin >> repeat) || (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'))
      {
        std::cout<<"Invalid input. Please enter either 'y' or 'n'"<<std::endl;
        std::cout<<"Would you like to calculate another transition (y/n)? :"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
    if(repeat == 'N' || repeat == 'n')
      {
        choose = !choose;
      }
  }
  return 0;
}