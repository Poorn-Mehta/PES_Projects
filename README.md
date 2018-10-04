# Project_1_R-P
This is the public repository owned by Rushi James Macwan and Poorn Mehta for the ECEN 5813 (Fall-2018) Project 1. Currently working on Sprint 1. Access from linux.

Some information regarding Sprint 1:

In this Github repository, we have tried to incorporate the basic features for the user as were discussed in the class. On executing the Project_1 file in the command window on Linux, we are able to provide the user with a welcome statement followed by a prompt to seek help. If the user puts a valid keyword (at this stage the user is only expected to type "help" or "help.exit" as valid keywords) then the executable program returns more information on the keyword which can be an executable instruction or a piece of necessary information depending upon the type of the application. If the user enters an invalid keyword then the system will return a response stating the entered keyword as invalid. Furthermore, if the user enters "help.exit" as the keyword then the system responds with a message on further steps to end the execution of the make file. To end this execution, the user can simply enter "exit" as the keyword which brings the user back to the command window operations considering that the while loop is exited.

Thanks.

Sincerely,

Team (Rushi and Poorn)

$ find . \( -name "*.c" -o -name "*.h" \)  -exec cat {} \; >> output.txt
