#include "stdafx.h"

void saves_list(std::string file_name) {
    std::ifstream file (file_name);
    if(file.is_open()) {
        string holder;
        int save_number = 1;
        while ( std::getline (file, holder) ){
            std::cout << save_number << ") " << holder << '\n';
            save_number++;
        }
        file.close();
    }
    else {
		std::cout << "Could not open file.";
	}

}

void print_save(std::string file_name) {
    std::ifstream file (file_name);
    if(file.is_open()) {
        string holder;
        while ( std::getline (file, holder) ){
            std::cout << holder << '\n';
        }
        file.close();
        std::cout << endl;
    }
    else {
		std::cout << "Could not open save file.";
	}

}

string get_save_file(const unsigned int save_num){
    string line;
    std::ifstream file("saves.txt");
    unsigned int line_num = 1;
    while(std::getline(file, line)){
        if (save_num == line_num){
            line = line + ".txt";
            return line;
        }
        line_num++;
    }
    file.close();
    return "Error";
}

void interface(){

    std::cout << "         WELCOME" << endl << "---------------------------" << endl << "1) Begin a new game" << endl << "2) Load a previous safe file" << endl << "3) Quit" << endl;
    int choice;
    cout << "Choose an option: ";
    std::cin >> choice;
    std::cout << endl;

    switch( choice ){
    case 1:{
        std::cout << "Please enter the name of a new save file: ";
        string new_save_name;
        std::cin >> new_save_name;
        std::ofstream new_save (new_save_name);
        break;
    }

    case 2:{
        std::cout << "Saves: " << endl;
        saves_list("saves.txt");
        std::cout << endl << "Which save file would you like to open: ";
        unsigned int save_answer;
        std::cin >> save_answer;
        std::cout << endl;
        print_save(get_save_file(save_answer));
        break;
    }
    case 3:{
        std::exit(0);
        break;
    }
    }
}
