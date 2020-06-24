Monte Carlo Pricer - C++ Capstone Project

Requiremnts
0. Loops, Functions, I/O - The project accepts user input and processes the input.
   In main.cpp program takes user input and processes it to output the price ot the option in question.
1. Object Oriented Programming - The project uses Object Oriented Programming techniques
   The procject heavly use OOP techniques both model.h and EurOption.h define classes which are at the heart of the project. 
2. Object Oriented Programming - Classes use appropriate access specifiers for class members
   That is the case, take a look at the classes in models.h or EurOption.h.
3. Object Oriented Programming - Classes abstract implementation details from their interfaces.
   Done for all the classes, particularly interesting is PriceByMC public fucntion that calls private PriceByMCSingleThread,
   where accualy the private fucntion contains accual impelmetnation of montecarlo pricing and the public one just run it in threads.
4. Object Oriented Programming - Derived class functions override virtual base class functions.? 
5. Concurrency - The project uses multithreading
   PriceByMC function calls PriceByMCSingleThread and run it a multiple threads using async.  


About:
This project provide impelmetnation of Monte Carlo technique applied for option pricing. 
It allows user to provied paramteres of stock and option to get value of the Europen Option in Black Schlotz freamwork. 
It is implement with OOP techniques, which make it cleare and easy to expand its functionality. Moreover it use async function to run the Monte Carlo simulation
in threads which significantly speedup calcutaion, when run on Intel i7-7700HQ this makes calcutaion more than ten times faster. 

Instruction: 
Procject contains CMAKE file, so its easy to build. In project directory run following bash commands to run it:
mkdir build && cd build
cmake .. && make
./mc

To-do 
 czyszcenie, virtualizacja?,  Vasicek, PathDependat Option rewrite, American options  - środa 
 I/O - czwartek