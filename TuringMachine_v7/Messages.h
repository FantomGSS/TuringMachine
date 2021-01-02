#pragma once
#include <iostream>

const std::string INVALID_PATH = "You have entered an invalid path! Forbidden characters are: / < | >";
const std::string ENTER_FULL_PATH = "Enter the full path to the file: ";
const std::string NOT_ENTERED_PATH = "You have not entered a path to the file!";
const std::string FILE_NOT_EXIST = "The file does not exist!";
const std::string FILE_EXISTS_SAME_NAME = "There is already a file with that name! Please enter a different path in the file system.";

const std::string ENTER_STATE = "Enter the initial state of the machine: ";
const std::string NOT_ENTERED_STATE = "You have not entered a initial state!";
const std::string NO_INITIAL_STATE = "There is no information in the file about the initial state of the Turing machine. It must be at the beginning of the file.";
const std::string ENTER_TRANSITIONS = "Each transition must be entered on a new line, strictly following its format.";
const std::string STOP_TRANSITIONS = "To stop entering transitions, you must enter stop!";
const std::string NOT_ENTERED_TRANSITION = "You have not entered a transition!";
const std::string WRONG_SYNTAX_TRANSITION = "The syntax of the transition is wrong! The required format is: <symbol><state> -> <symbol><state><command>";
const std::string ENTER_TAPES = "You must enter at least one tape!";
const std::string STOP_TAPES = "To stop entering tapes, you must enter stop!";
const std::string NOT_ENTERED_TAPE = "You have not entered a tape!";
const std::string ERROR_LINE = "The error is reported on line: ";

const std::string OPTION = "Option: ";
const int COUNT_OPTIONS_INFORMATION_MACHINE = 2;
const int COUNT_OPTIONS_INFORMATION_TAPES = 2;
const int COUNT_OPTIONS_INSPECTION = 2;
const std::string INFORMATION_MACHINE = "How would you like to provide information about the Turing Machine? The options are:";
const std::string INFORMATION_TAPES = "How would you like to provide the tape(s) information? The options are:";
const std::string INSPECTION = "How would you like to review the results? Save the information to a file or display it on the screen?";
const std::string OPTIONS_INFORMATION_MACHINE[COUNT_OPTIONS_INFORMATION_MACHINE] { "From file, providing the full path to the file.", "From console, entering the state of the machine and the transitions." };
const std::string OPTIONS_INFORMATION_TAPES[COUNT_OPTIONS_INFORMATION_TAPES]{ "From file, providing the full path to the file.", "From console, entering one or more tapes." };
const std::string OPTIONS_INSPECTION[COUNT_OPTIONS_INSPECTION]{ "In a file, providing the full path to the file.", "In the console" };
const std::string OPTION_NUMBER_NOT_EXIST = "You have entered an option number that does not exist!";
const std::string OPTION_MUST_NUMBER = "The option must be a number!";
const std::string NOT_ENTERED_OPTION = "You have not entered a option!";
const std::string INVALID_OPTION = "You have entered an invalid option!";

const std::string NO_TAPES = "No tape / tapes!";
const std::string NO_TRANSITION_FOUND = "No transition found that can be performed!";
const std::string PROCESSED_SUCCESSFULLY = "The tape was processed successfully!";
const std::string NOT_PROCESSED_SUCCESSFULLY = "The tape was not processed successfully!";
const std::string REGARDING_FIRST_RESULT = "Regarding the results of the first machine: ";
const std::string REGARDING_SECOND_RESULT = "Regarding the result of the machine, which have to continue depending on the result of the first machine: ";
const std::string REGARDING_FINAL_RESULT = "Regarding the final results of both machines: ";
const std::string NOTHING_TO_PROCESS = "There is nothing to process!";
const std::string POSITIVE_RESULT = "The result of the machine operation is positive.";
const std::string NEGATIVE_RESULT = "The result of the machine operation is negative.";