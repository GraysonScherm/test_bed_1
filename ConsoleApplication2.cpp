// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "User_Interface.h"


void write_file(std::string file_name) {
	std::ofstream file (file_name);
	if (file.is_open()) {
        string holder;
        cin.ignore();
		getline(std::cin, holder);
        file << holder;
		file.close();
	}
	else {
		std::cout << "Could not open file.";
	}
}

void read_file(std::string file_name) {
    std::ifstream file (file_name);
    if(file.is_open()) {
        string holder;
        while ( std::getline (file, holder) ){
            std::cout << holder << '\n';
        }
        file.close();
    }
    else {
		std::cout << "Could not open file.";
	}

}

int main()
{
    interface();

	std::cout << "Please enter the name of a file: ";
	string file_name = "text.txt";
	std::cin >> file_name;
	std::cout << "Would you like to read this file (Y/N): ";
	string answer1 = "N";
	std::cin >> answer1;
	if (answer1 == "Y"){
        read_file(file_name);
        std::cout << endl;
	}

	std::cout << "Would you like to write to this file (Y/N): ";
	std::cin >> answer1;

	if (answer1 == "Y"){
        write_file(file_name);
        getchar();
	}
	else {
        std::cout << endl;
        std::cout << "Program terminated.";
        return 0;
	}

    return 0;
}

