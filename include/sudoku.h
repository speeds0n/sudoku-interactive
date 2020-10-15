/*!
 * \file sudoku.h
 * \author Edson Cassiano
 * \date October, 12th
 */

#ifndef INTERFACE_H
#define INTERFACE_H

/*!
 *
 * Print the Help Screen
 * 
 * This function print the help screen
 *
 * That Function show the syntax used in the command line
 * and the meaning of each command.
 */
void help_menu();

/*!
 *
 * Print the Rules and how to play
 *
 * This function gives a brief explanation abount the game
 * and show the conditions to posit the guesses on the board.
 *
 */
void help_screen();

/*!
 *
 * Print Welcome message
 *
 * This function show welcome message and the source code author.
 *
 */
void start_menu();

/*!
 *
 * Print header
 *
 * This function show the header of Main Screen
 *
 */
void main_screen();

/*!
 *
 * Read puzzle
 *
 * This function get a puzzle and shows it in a formatted way
 *
 * \param puzzle 2D Array that receives the current puzzle and print
 */
void read_puzzle(int puzzle[][9]);

/*!
 *
 * Change the game to Action Mode
 *
 * This function get a puzzle and show it in a formatted way
 * and includes color change during the game and also manipules the indicative arrows.
 *
 * \param puzzle 2D Array that receives the current puzzle and print
 * \param puzzleColor int value that indicates the color change.(1-blue, 2-green, 3-red)
 * \param rArrow int value corresponding to the position of the row arrow
 * \param cArrow int value corresponding to the position of the column arrow
 */
void action_mode(int puzzle[][9], int puzzleColor, int rArrow, int cArrow);

/*!
 *
 * Print Command syntax 
 *
 * This function print the command syntax while the game is running
 *
 */
void command_syntax();

/*!
 *
 * Print all Message to player
 *
 * This function show all messages to player, including error messages,
 * Victory messages and defeat messages.
 *
 * \param errorC int value that indicates the message that will be shown
 */
void error_cd(int errorC);

/*!
 * 
 * Remaining number controller
 *
 * This function check in the 2D Array which numbers are missing in the puzzle 
 *
 * \param puzzle 2D Array that receives the current puzzle
 * \param dLeft int pointer with 9 position that saves which numbers are missing in the puzzle
 * \return return the pointer to array with list of numbers are missing in the puzzle
 */
int* digits_left(int puzzles[][9], int *dLeft);

/*!
 *
 * Function responsible for game control
 *
 * This function is responsible for game control, doing all the action needed to the player to play
 *
 * \param puzzle 2D Array that receives the current puzzle
 * \param checks number of checks in current game
 * \param cGame int pointer that check if the game continue or ends.
 */
void action_menu(int puzzle[][9], int checks, int *cGame);

#endif
