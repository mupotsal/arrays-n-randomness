/** 
   By Dr. Jan Pearce to explore arrays and pseudo-randomness
   Created for CSC 236 Data Structures at Berea College
   Names: Liberty Mupotsa, Jalen Prater
 */

#include <iostream> //for input & output
#include <random> //needed for Getrandom
#include <chrono> //needed for Getrandom's seed

using namespace std;

//---------------------------------------------------------------------
// Program illustrating use of C++ classes called Dice and Getrandom
//---------------------------------------------------------------------

class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};


class Dice{
/** class that can be used to make dice.
Dependent upon the Getrandom class above. */
public:
	Dice(){// default constructor assumes a 6-sided die.
		self_roll_count_ = 0;
		self_sides_ = 20;	
	}
	Dice(int sides){        // constructor for any size dice
		self_roll_count_ = 0;
		self_sides_ = sides;
	}
	int roll() {             // return the random roll of the die
		// postcondition: number of rolls updated, random 'die' roll returned

		Getrandom newrandom(self_sides_);
		self_roll_count_ = self_roll_count_ + 1;         // update # of times die rolled
		return(newrandom.roll());
	}
	int get_sides() const{   // how many sides this die has
		// postcondition: return # of sides of die
		return self_sides_;
	}
	int get_roll_count() const{   // # times this die rolled
		// postcondition: return # of times die has been rolled
		return self_roll_count_;
	}
private:
	int self_roll_count_;       // # times die rolled
	int self_sides_;           // # sides on die
}; //a semi colon must end every C++ class declaration.


//---------------------------------------------------------------------
// main begins here

int main(){
	char stopme;
	int thisroll;
	int numrolls = 12;
	int tallyroll[300] = {0}; // intializes tallyroll to 0
	int dsize;
	
	//FIXME: create a new variable and interact with the user here

	Dice die6;					// make a six-sided die
	//Dice die16(16);             // make a 16-sided die

	//FIXME: Create the two dice you need here.
	cout << "What size if the dice do you want  to roll?" << endl;
	
	cin >> dsize;
	Dice diceone(dsize);
	Dice dice2(dsize);
	cout << "This loop displays " << numrolls << " rolls of a " << diceone.get_sides() << "-sided die:\n" << endl;
	for (int i = 0; i < numrolls; i++){
		
		//thisroll = die6.roll(); //roll the die
		thisroll = diceone.roll() + dice2.roll();
		tallyroll[thisroll]++; // increment count of this roll value
		//cout << "Roll " << i << " is " << thisroll << "." << endl;
	}
	//cout << "\nRolled the die " << die6.get_roll_count() << " times.\n" << endl;
	cout << "\n Rolled the die " << diceone.get_roll_count() << " times.\n" << endl;
	//cout << "\n Rolled the die " << dice2.get_roll_count() << " times.\n" << endl;

	for (int i = 2; i <= 2 * dsize; i++) {
	}

	//FIXME: write a loop that runs for the number of rolls you want to make
	//       Inside the loop roll both dice, sum them together, 
	//       and increment the correct location in tallyroll[].

	//FIXME: write a loop that outputs all of the values of tallyroll[] and their counts
	for (int i = 2; i <= 2 * dsize; i++) {
		cout <<i<< " was rolled "<< tallyroll[i] << endl;
		//cout << &tallyroll[i] << endl;

	}
	

	cin >> stopme; //holds open the window in some cases
	return 0;
}


//
//
//for (int i = 0; i < 12; i++) {
//	cout << tallyroll[i] << endl;
//	cout << "id: " << tallyroll[i] << endl;


