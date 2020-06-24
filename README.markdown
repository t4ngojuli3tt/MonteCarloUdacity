Monte Carlo Option Price Calculator - C++ Capstone Project

Requirements
0. Loops, Functions, I/O - The project accepts user input and processes the input.
   In main.cpp program takes user input and processes it to output the price of the option in question.
1. Object Oriented Programming - The project uses Object Oriented Programming techniques
   The project heavily uses OOP techniques both Model.h and Option.h define classes which are at the heart of the project. 
2. Object Oriented Programming - Classes use appropriate access specifiers for class members
   That is the case for all the classes, see Model.h or Option.h.
3. Object Oriented Programming - Classes abstract implementation details from their interfaces.
   Done for all the classes, particularly interesting is PriceByMC (in Option.cpp) public function that calls private PriceByMCSingleThread,
   wwhere actually the protected function contains actual implementation of Monte Carlo pricing and the public one just run it in threads.
4. Object Oriented Programming - Derived class functions override virtual base class functions.
   In model.h GenerateSamplePath function in BSModle override virtual function from class model. 
5. Concurrency - The project uses multithreading
   PriceByMC function in Option.cpp calls PriceByMCSingleThread and run it a multiple thread using async.  

Instruction: 
In project directory run following bash commands to run the project it:
mkdir build && cd build
cmake .. && make
./mc

About:
This project provide impelmetnation of Monte Carlo technique applied for option pricing. 
It allows user to provied paramteres of stock and option using console to get value of the Europen Option in Black Schlotz freamwork. 
It uses async function to run the Monte Carlo simulation in threads which significantly speedup calculation, when run on Intel i7-7700HQ this makes calculation more than ten times faster. 


Code structure:
main.cpp - contains I/O interaction with the user and calls function from classes definr in Model.h and Options.h

Model.h & Model.cpp - Model contains two classes Model and BSModel, Model is an abstract class which contains key function and paramters for model use in Monte Carlo simulation.  
   BSModel is a subclass of Model and it implements Black-Scholtz model.

Option.h & Option.cpp - Here structure is simlar to Model.h, this one contains two classes, base abstract class Option and it subclass EurOption. Option key function and parmeters for a pricing stock option, EurOption class implements Option abstraction for Europen option. 

This structure allows easly expand fuctionality of this code by adding new models, as a subclass of the Model class, or new type of options as subclass of the Option class.



To-do 
Vasicek, PathDependat Option rewrite, American options  - środa