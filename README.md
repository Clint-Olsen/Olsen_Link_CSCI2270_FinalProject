# Olsen_Link_CSCI2270_FinalProject
This project will focus on building a program that simulates a vending machine.
The vending machine will keep track of the stock of various items and how much these items cost.
The program will also incorporate basic vending machine functions such as restocking, vending items, and displaying prices. 

## Overview
This program builds a simulated vending machine through an array of linked lists. Each memeber of the array is the head pointer of a doubly linked list that each represent the different rows of the vedning machine. The linked list is comprised of nodes that are defined by the structure vendingItem, and contain information such as the item name, price, quantity, and next and previous pointers. The user is able to explore a variety of features such as viewing the status of the vending machine, making purchases, and entering an administrator menu that allows for more detatiled changes. The vending machine also attempts to simulate reality by occassionally becoming stuck!

## How to run
This program contains a driver file named main.cpp, two source files VendingMachine.cpp and Helper.cpp (one for the vending machine class and one for helper functions), as well as the correlating header files for the source files. These are stored within the vendingMachine folder in the GitHub repository. To run the propram, pull this folder into a local directory on your machine and open Codeblocks. Within Codeblocks, select "Open Existing Project" and select the vendingMachine.cbp file from the directory from GitHub. When the project is opened, check to see if the Source and Header folders are located in the Workspace area to the left. If not, right click on vendingMachine within the Workspace and select "Add files...". Search for the two source files within the src directory and for the two header files within the include directory. The files will now be added to the project. Next, a complier flag needs to be set in order to use some of the functions required within the program. To do this, navigate to the "Project" tab, select "Build Options", ensure you are in the "Complier Setting" and "Complier Flags" tabs, check the box next to "Have g++ follow the c++11 iso c++ langauge standard [-std=c++11]", and select "Ok". The next thing that needs to be done is to add a program argument that will open the correct .txt file that comes with the program (this file is located in the vendingMachine directory). To do this navigate to "Project"->"Set program's arguments..." and in the text box that is labeled "Program Arguments" type vendingItems.txt. Select "Ok". The program is now ready to run!

## Dependencies
None

## System Requirements
This program is optimized to be opened as a Codeblocks project, which is best run on Windows or Linux machines.

## Group Members
Clint Olsen
Sean Link

## Collaborators
None

## Open issues/bugs
Upon compliation, and error may occur on Linux based computers that states either "fatal error: VendingMachine.h: no such file or directory", "fatal error: Helper.h: no such file or directory" or both. If this occurs, the #include statement that is currently set to #include "VendingMachine.h" or "Helper.h"needs to be set to a specfic path the main.cpp and VendingMachine.cpp files. To do this, use File Manager (Linux file searching utility) to find the exact path to the VendingMachine.h file or Helper.h. Take this path and add it to the include statements within the two specified files. It will have the for #include "/home/user/.../VendingMachine.h" or  "/home/user/.../Helper.h".

