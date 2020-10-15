#include <iostream>
#include <fstream>
#include <vector>

#include "../include/sudoku.h"
#include "../include/text_color.h"

struct commands{
	std::string cmmd;
	int row{0}, col{0}, number{0};
	int dLeft[9]{0};
};

void help_menu(){
   	std::cout << "Usage: Sudoku [<options>] [<input_puzzle_file>]" << std::endl;
    std::cout << "  Game options:" << std::endl;
   	std::cout << "      --ncheck <num>  Number of checks per game. Default = 3." << std::endl;
    std::cout << "      --help          Print this help text." << std::endl;
}

void start_menu(){
   	std::cout << "===================================================" 	<< std::endl;
    std::cout << "   Welcome to a terminal version of Sudoku, v1.0" 	<< std::endl;
   	std::cout << "   Copyright (C) 2020, Edson C da Silva Costa" 		<< std::endl;
    std::cout << "===================================================" 	<< std::endl;
	std::cout << std::endl;
	std::cout << "Press <enter> to start.";
}

void help_screen(){
   	std::cout << Color::tcolor("===================================================", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  The goal of Sudoku is to fill a 9x9 grid with    ", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  numbers so that each row, column and 3x3 sec-    ", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  tion(nonet) contain all of the digits between    ", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  1 and 9.\n", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  The Sudoku rules are:", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  1. Each row, column, and nonet can contain each  ", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("     number(typically 1 to 9) exactly once", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  2. The sum of all numbers in any nonet, row, or  ", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("     column must be equal to 45.", Color::GREEN, Color::REGULAR) << std::endl;
   	std::cout << Color::tcolor("===================================================", Color::GREEN, Color::REGULAR) << std::endl;
}

void main_screen(){
   	std::cout << Color::tcolor("\n===================================================", Color::BRIGHT_BLUE, Color::REGULAR) << std::endl;
   	std::cout << Color::tcolor("===================  MAIN SCREEN  =================", Color::BRIGHT_BLUE, Color::REGULAR) << std::endl;
   	std::cout << Color::tcolor("===================================================", Color::BRIGHT_BLUE, Color::REGULAR) << std::endl;
}

void read_puzzle(int puzzle[][9]){
	std::cout << std::endl;
   	std::cout << Color::tcolor("               1 2 3   4 5 6   7 8 9  ", Color::CYAN, Color::REGULAR) << std::endl;
   	std::cout << "             +-------+-------+-------+" << std::endl;
	for(int i{0};i < 9; i++){
		std::cout << "           " << Color::tcolor(std::to_string(i+1), Color::CYAN, Color::REGULAR) << " | ";

		for(int j{0};j < 9; j++){
			if(puzzle[i][j] < 0){
				std::cout << "  ";
			}else{
				std::cout << puzzle[i][j] << " ";
			}
			if(j == 2 || j == 5){
				std::cout << "| ";
			}
		}
		std::cout << "|";
		if(i == 2 || i == 5){
   			std::cout << "\n             +-------+-------+-------+";
		}
		std::cout << std::endl;
	}
   	std::cout << "             +-------+-------+-------+\n";
}

void action_mode(int puzzle[][9], int puzzleColor[][9], int rArrow, int cArrow){

	std::cout << Color::tcolor("===================================================", Color::BRIGHT_BLUE, Color::REGULAR) << std::endl;
   	std::cout << Color::tcolor("===================  ACTION MODE  =================", Color::BRIGHT_BLUE, Color::REGULAR) << std::endl;
   	std::cout << Color::tcolor("===================================================", Color::BRIGHT_BLUE, Color::REGULAR) << std::endl;

	std::cout << "               ";
	for(int i{0};i < 9;i++){
		if(i == 3 || i == 6){
			std::cout << "  ";
		}
		if((cArrow-1) == i){
			std::cout << Color::tcolor("v", Color::RED, Color::REGULAR);
		}
		std::cout << "  ";
	}

	std::cout << "\n               ";
	for(int i{0};i < 9;i++){
		if(i == 3 || i == 6){
			std::cout << "  ";
		}
		std::cout << Color::tcolor(std::to_string(i+1), Color::BRIGHT_BLUE, Color::REGULAR) << " ";
	}
   	std::cout << "\n             +-------+-------+-------+" << std::endl;
	for(int i{0};i < 9; i++){
		if((rArrow-1) == i){	
			std::cout << Color::tcolor("         > ", Color::RED, Color::REGULAR) << Color::tcolor(std::to_string(i+1), Color::BRIGHT_BLUE, Color::REGULAR) << " | ";
		}else{
			std::cout << "           " << Color::tcolor(std::to_string(i+1), Color::BRIGHT_BLUE, Color::REGULAR) << " | ";
		}

		for(int j{0};j < 9; j++){
			if(puzzle[i][j] < 0){
				std::cout << "  ";
			}else{
				if(puzzleColor[i][j] == 1){
					std::cout << Color::tcolor(std::to_string(puzzle[i][j]), Color::BLUE, Color::REGULAR) << " ";
				}else if(puzzleColor[i][j] == 2){
					std::cout << Color::tcolor(std::to_string(puzzle[i][j]), Color::GREEN, Color::REGULAR) << " ";
				}else if(puzzleColor[i][j] == 3){
					std::cout << Color::tcolor(std::to_string(puzzle[i][j]), Color::RED, Color::REGULAR) << " ";
				}else{
					std::cout << Color::tcolor(std::to_string(puzzle[i][j]), Color::WHITE, Color::REGULAR) << " ";
				}
			}
			if(j == 2 || j == 5){
				std::cout << "| ";
			}
		}
		std::cout << "|";
		if(i == 2 || i == 5){
   			std::cout << "\n             +-------+-------+-------+";
		}
		std::cout << std::endl;
	}
   	std::cout << "             +-------+-------+-------+\n";
}

void command_syntax(){
	std::cout << Color::tcolor("\nCommands syntax:", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  'enter' (without typing anything)  -> go back to previous menu.", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  'p' <row> <col> <number> + 'enter' -> place <number> on board at location (<row>, <col>).", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  'r' <row> <col> + 'enter'          -> remove number on board at location (<row>, <col>).", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  'c' + 'enter'                      -> check which moves made are correct.", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("  'u' + 'enter'                      -> undo last play.", Color::GREEN, Color::REGULAR) << std::endl;
	std::cout << Color::tcolor("<row>, <col>, <number> must be in range [1,9].", Color::GREEN, Color::REGULAR) << std::endl;
}

void error_cd(int errorC){
	if(errorC == 0){
		std::cout << "";
	}if(errorC == 1){
		std::cout << Color::tcolor("This position is filled", Color::YELLOW, Color::REVERSE);
	}if(errorC == 2){
		std::cout << Color::tcolor("Invalid command. Note: Read Command Syntax", Color::YELLOW, Color::REVERSE);
	}if(errorC == 3){
		std::cout << Color::tcolor("Hey, this is not valid move to make, BUT it's up to you keep it or not", Color::YELLOW, Color::REVERSE);
	}if(errorC == 4){
		std::cout << Color::tcolor("Invalid command. Type a valid command between [1,4]", Color::YELLOW, Color::REVERSE);
	}if(errorC == 5){
		std::cout << Color::tcolor("Already in the oldest change", Color::YELLOW, Color::REVERSE);
	}if(errorC == 6){
		std::cout << Color::tcolor("Congratulations, you solved the puzzle! Press enter to continue.", Color::YELLOW, Color::REVERSE);
	}if(errorC == 7){
		std::cout << Color::tcolor("Sorry, you lost! Press enter to continue.", Color::YELLOW, Color::REVERSE);
	}if(errorC == 8){
		std::cout << Color::tcolor("Sorry, all checks were used!", Color::YELLOW, Color::REVERSE);
	}if(errorC == 9){
		std::cout << Color::tcolor("To confirm a new game choose: 1-YES 2-NO", Color::YELLOW, Color::REVERSE);
	}
}

int* digits_left(int puzzles[][9], int *dLeft){
	/*For aninhado usado para verificar se tem algum numero menor que zero(numeros faltando)
	  for com interador k é usado para verificar em qual posicao esta numero do numbersleft
		  O ultimo for é usado para imprimir os numeros na lista*/
	for(int i{0};i < 9;i++){
	  	for(int j{0};j < 9;j++){
			for(int k{0};k < 9;k++){
				if(i+1 == puzzles[j][k])
					dLeft[i] += 1;
			}
		}
	}
	return dLeft;
}

void action_menu(int puzzle[][9], int checks, int *cGame){
	std::string cmd;//Current command
	std::vector<commands> undoCmd;//Vector of Struct that saves the list of commands executed by the player
	int row{0}, col{0}, number{0}, errorC{0};//row, col, number, save the row column and number that player wrote, and errorC message that will appears to player
	int loop{0};//responsible for game loop
	int puzzleBackup[9][9]{0}, puzzleColor[9][9]{0};//puzzleBackup save the current game solution and puzzleColor save which are number will change colors
	int dgLeft[9]{0};// digits
	int *dLeft{digits_left(puzzle, dgLeft)};// pointer to digits left
	int count{0}, rowArrow{0}, colArrow{0};// count aux value to count, rowArrow and colArrow, row and column that show the arrow
	int gameOver{0};//gameOver controll

	// Save the current solution puzzle in variable backup, to make changes in the puzzle
	for(int i{0};i < 9;i++){
		for(int j{0};j < 9;j++){
			puzzleBackup[i][j] = puzzle[i][j];
		}
	}
	do{
		gameOver = 0;

		action_mode(puzzle, puzzleColor, rowArrow, colArrow);

		std::cout << Color::tcolor("Checks left: [ ", Color::YELLOW, Color::REGULAR) 
				  << Color::tcolor(std::to_string(checks), Color::YELLOW, Color::REGULAR)
				  << Color::tcolor(" ]", Color::YELLOW, Color::REGULAR) << std::endl;
		
		std::cout << Color::tcolor("Digits left: [ ", Color::YELLOW, Color::REGULAR);
		for(int i{0};i < 9;i++){
			if(dLeft[i] < 9){
				std::cout << Color::tcolor(std::to_string(i+1), Color::YELLOW, Color::REGULAR) << " ";
			}else{
				std::cout << "  ";
			}
		}
		std::cout << Color::tcolor(" ]", Color::YELLOW, Color::REGULAR) << std::endl;
		for(int i{0};i < 9;i++){
			for(int j{0};j < 9;j++){
				if(puzzle[i][j] < 0){
					gameOver++;
				}
			}
		}
		if(gameOver == 0){
			int auxCount{0};
			int winCondition{0};
			for(int i{0};i < 9;i++){
				for(int j{0};j < 9;j++){
					if(puzzleBackup[i][j] < 0){
						auxCount++;
						if(-(puzzle[i][j]) == puzzleBackup[i][j]){
							winCondition++;
						}
					}
				}
			}
			if(auxCount == winCondition){
				errorC = 6;
				loop++;
			}else{
				errorC = 7;
				loop++;
			}
		}
		std::cout << Color::tcolor("MSG: [ ", Color::YELLOW, Color::REGULAR);
		error_cd(errorC);
		std::cout << Color::tcolor(" ]", Color::YELLOW, Color::REGULAR) << std::endl;
		if(gameOver != 0){
			command_syntax();
			std::cout << Color::tcolor("Enter command > ", Color::YELLOW, Color::REGULAR);
		}
		getline(std::cin, cmd);

		//Command Handling
		if(cmd.empty()){
			std::string temp;
			errorC = 0;
			main_screen();
			read_puzzle(puzzle);
			std::cout << Color::tcolor("MSG: [ ", Color::YELLOW, Color::REGULAR);
			error_cd(errorC);
			std::cout << Color::tcolor(" ]", Color::YELLOW, Color::REGULAR) << std::endl;
			std::cout << Color::tcolor("1-Play 2-New Game 3-Quit 4-Help", Color::YELLOW, Color::REGULAR) << std::endl;
			std::cout << Color::tcolor("Select option [1,4] > ", Color::YELLOW, Color::REGULAR);

			std::getline(std::cin, temp);
			if(temp.empty()){
				continue;
			}
			if(std::stoi(temp.substr(0,1)) == 1){
				continue;
			}else{
				if(std::stoi(temp.substr(0,1)) == 2){// Confirm to exit to Main menu
					std::string tempConfirm;
					errorC = 9;
					main_screen();
					read_puzzle(puzzle);
					std::cout << Color::tcolor("MSG: [ ", Color::YELLOW, Color::REGULAR);
					error_cd(errorC);
					std::cout << Color::tcolor(" ]", Color::YELLOW, Color::REGULAR) << std::endl;
					std::cout << Color::tcolor("1-Confirm 2-Back to game", Color::YELLOW, Color::REGULAR) << std::endl;
					std::cout << Color::tcolor("Select option [1,2] > ", Color::YELLOW, Color::REGULAR);

					std::getline(std::cin, tempConfirm);
					if(tempConfirm.compare(0,1,"1") == 0){
						*cGame = 1;
						loop++;
					}else if(tempConfirm.compare(0,1,"2") == 0){
						errorC = 0;
						continue;
					}else{
						errorC = 2;
						continue;
					}
				}else if(std::stoi(temp.substr(0,1)) == 3){
					*cGame = 2;
					loop++;
				}else if(std::stoi(temp.substr(0,1)) == 4){
					*cGame = 3;
					loop++;
				}else{
					errorC = 10;
				}
			}
		}if(cmd.compare(0,1,"p") == 0){//Check if player typed "p"
			if(cmd.length() == 7){//Check if the string size is validates
				if(cmd.compare(1,1," ") == 0 && cmd.compare(3,1," ") == 0 && cmd.compare(5,1, " ") == 0){//Check if the string format is validates

					row = std::stoi(cmd.substr(2,1));
					col = std::stoi(cmd.substr(4,1));
					number = std::stoi(cmd.substr(6,1));
					rowArrow = row;
					colArrow = col;

					errorC = 0;

					// Check if the number typed is valid
					if(puzzleBackup[(row-1)][(col-1)] < 0){
						if(dLeft[number-1] > 0){
							dLeft[number-1]++;
						}
					//check row and column
					for(int i{0};i < 9;i++){
						if(number == puzzle[row-1][i] && i != row-1){
							errorC = 3;
						}
						if(number == puzzle[i][col-1] && i != col-1){
							errorC = 3;
						}
					}
					//check which quadrant the play wants to put the number
					int rowChunck{0};
					int colChunck{0};
					if(row <= 3){
						rowChunck = 0;
					}if(row >= 4 && row <= 6){
						rowChunck = 3;
					}
					if(row >= 7){
						rowChunck = 6;
					}
					if(col <= 3){
						colChunck = 0;
					}if(col >= 4 && row <= 6){
						colChunck = 3;
					}
					if(col >= 7){
						colChunck = 6;
					}
					//check quadrant
					for(int i{rowChunck};i < rowChunck+3; i++){
						for(int j{colChunck};j < colChunck+3; j++){
							if(number == puzzle[i][j]){
								errorC = 3;
							}
						}
					}
					// End of check

					//undo block
					undoCmd.push_back(commands());
					undoCmd[count].cmmd = "p";
					undoCmd[count].row = row-1;
					undoCmd[count].col = col-1;
					undoCmd[count].number = puzzle[(row-1)][(col-1)];
					for(int i{0};i < 9;i++){
						undoCmd[count].dLeft[i] = dLeft[i];
					}
					count++;

					puzzle[(row-1)][(col-1)] = number;
					puzzleColor[(row-1)][(col-1)] = 1;

				}else{// if the position is filled show error message
					errorC = 1;
				}
			}else{// if invalid command, show error message
				errorC = 2;
			}
		}else{// if invalid command, show error message
			errorC = 2;
		}
		}if(cmd.compare(0,1,"r") == 0){
			if(cmd.length() == 5){
				if(cmd.compare(1, 1, " ") == 0 && cmd.compare(3, 1, " ") == 0){
					row = std::stoi(cmd.substr(2,1));
					col = std::stoi(cmd.substr(4,1));
					rowArrow = row;
					colArrow = col;

					if(puzzle[(row-1)][(col-1)] > 0 && puzzleBackup[(row-1)][(col-1)] < 0){
						errorC = 0;

						puzzle[(row-1)][(col-1)] = puzzleBackup[(row-1)][(col-1)];
						dLeft[number-1]--;
						undoCmd.push_back(commands());
						undoCmd[count].cmmd = "r";
						undoCmd[count].row = row-1;
						undoCmd[count].col = col-1;
						undoCmd[count].number = number;
						for(int i{0};i < 9;i++)
							undoCmd[count].dLeft[i] = dLeft[i];
						count++;
					}else{//if the position is filled show error message
						errorC = 1;
					}
				}else{//if invalid command, show error message
					errorC = 2;
				}
			}else{//if invalid command, show error message
				errorC = 2;
			}
		}if(cmd.compare("c") == 0){
			if(checks > 0){
				for(int i{0};i < 9;i++){
					for(int j{0};j < 9;j++){
						if(puzzleBackup[i][j] < 0){
							if(puzzleBackup[i][j] != -(puzzle[i][j]) && puzzle[i][j] > 0){
								puzzleColor[i][j] = 3;
							}if(puzzleBackup[i][j] == -(puzzle[i][j]) && puzzle[i][j] > 0){
								puzzleColor[i][j] = 2;
							}
						}
					}
				}
				checks--;
			}else{//if all checks were used show message
				errorC = 8;
			}
		}if(cmd.compare("u") == 0){
			if(undoCmd.size() > 0){
				count--;
				undoCmd.pop_back();
				row = undoCmd[count].row;
				col = undoCmd[count].col;
				number = undoCmd[count].number;

				if(undoCmd[count].cmmd.compare("r") == 0){
					puzzle[row][col] = number;
				}
				if(undoCmd[count].cmmd.compare("p") == 0){
					rowArrow = row+1;
					colArrow = col+1;
					puzzle[row][col] = number;

					dLeft[-number-1]--;
				}
			}else{// if all changes were undo, show the message
				errorC = 5;
				rowArrow = 0;
				colArrow = 0;
			}

		}

	}while(loop < 1);

}
