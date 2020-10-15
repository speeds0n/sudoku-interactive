#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>

#include "include/sudoku.h"
#include "include/text_color.h"
int main(int argc, char *argv[]){

    /*
        command 0 is ./a.out
    */
    std::string command_help{"--help"};
    std::string command_check{"--ncheck"};
	std::string temp;
	std::ifstream inputPuzzles("data/input.txt");
	std::fstream ncheckFile("data/ncheck.txt"/*, std::fstream::app*/);
	int option{0};
	int ncheckValue{0}, errorC{0}, continueGame{0};
	
		if(ncheckFile.is_open()){
			ncheckFile >> ncheckValue;
		}

    if(argc == 1){/*./sudoku - deve abrir um arquivo default com os puzzles, e imprime msg de abertura*/
        // após mostar a mensagem de boas-vindas, aguarde comando <enter>, se precionado mostrar mainscreen
		std::cout << ">>> Opening input file[../data/input.txt]." << std::endl;

		if(inputPuzzles.is_open()){
			std::cout << ">>> Processing data, please wait." << std::endl;
			std::cout << ">>> Finished reading input data file." << std::endl << std::endl;
			start_menu();
			//std::cin.get(ch);
			std::getline(std::cin, temp);
			if(!temp.empty()){
				ncheckFile.close();
				inputPuzzles.close();
				return 0;
			}
			int number{0};
			int puzzle[8][9]{0};
			int i{0}, j{0};

			while(i < 9){
				j = 0;
				while(j < 9){
					inputPuzzles >> number;
					puzzle[i][j] = number;
					j++;
				}
				i++;
			}

			do{
				if(continueGame == 0){
					main_screen();
					read_puzzle(puzzle);
					std::cout << Color::tcolor("MSG: [ ", Color::YELLOW, Color::REGULAR);
					error_cd(errorC);
					std::cout << Color::tcolor(" ]", Color::YELLOW, Color::REGULAR) << std::endl;
					std::cout << Color::tcolor("1-Play 2-New Game 3-Quit 4-Help", Color::YELLOW, Color::REGULAR) << std::endl;
					std::cout << Color::tcolor("Select option [1,4] > ", Color::YELLOW, Color::REGULAR);

					std::getline(std::cin, temp);
				}
				if(temp.empty()){
					option = 5;
					errorC = 4;
				}else{
					if(continueGame == 0){
						if(temp.size() == 1){
							char tempchar{temp[0]};
							if((int)tempchar > 48 && (int)tempchar < 53){
								option = std::stoi(temp.substr(0,1));
								tempchar = '\0';
							}else{//if the command dont is [1,2,3,4], show error message.
								option = 6;// Here option = 6 is equivalent to a invalid command(to the "switch/case" is "default" statement)
							}
						}else{//if command has no expected size, show error message.
							option = 6;// Here option = 6 is equivalent to a invalid command(to the "switch/case" is "default" statement)
						}
							
					}else{
						if(continueGame == 1){
							option = 2;
						}if(continueGame == 2){
							option = 3;
						}if(continueGame == 3){
							option = 4;
						}
					continueGame = 0;				
					}
				}
				switch(option){
					case 1:
						errorC = 0;
						action_menu(puzzle, ncheckValue, &continueGame);
						break;
					case 2:
						i = 0;
						while(i < 9){
							j = 0;
							while(j < 9){
								if(!(inputPuzzles >> number).eof()){
									puzzle[i][j] = number;
									j++;
								}else{
									inputPuzzles.clear();
									inputPuzzles.seekg(0);
								}
							}
							i++;
						}
						//read_puzzle(puzzle);
						errorC = 0;
						break;
					case 3:
						errorC = 0;
						return 0;
						break;
					case 4:
						errorC = 0;
						help_screen();
						std::getline(std::cin, temp);
						break;
					default:
						errorC = 4;
				}
				
			}while(option != 0);
		}else{	
        	std::cout << "Don't find the file" << std::endl;
		}
    }else if(argc > 1){
        if(command_help.compare(argv[1]) == 0){
            help_menu();
        }else if(command_check.compare(argv[1]) == 0){
				std::fstream tempFile("data/temp.txt", std::fstream::app);
				remove("data/ncheck.txt");
			if(argc > 2){
				if(tempFile.is_open()){
					tempFile.write(argv[2],2);
				}else{
						std::cout << "Error in open the file!\n";
				}
			}else{
					tempFile.write("3",1);
			}
			rename("data/temp.txt", "data/ncheck.txt");
			tempFile.close();
			ncheckFile.close();
		}else{
			std::cout << "Invalid command, type './sudoku --help' to help." << std::endl;
		}
    }

	ncheckFile.close();
	inputPuzzles.close();
    return 0;
}
