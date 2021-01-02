#include "TuringMachine.h"

void TuringMachine::copy(const TuringMachine& turingMachine)
{
	head = turingMachine.head;
	tapes = turingMachine.tapes;
	state = turingMachine.state;
	results = turingMachine.results;
}

bool TuringMachine::checkTransitionFormat(std::string& line)
{
	std::regex rgx(FORMAT_TRANSITION);

	if (std::regex_match(line, rgx))
	{
		return 1;
	}

	return 0;
}

void TuringMachine::readMachineFromFile()
{
	head = Head();

	while (true)
	{
		std::cout << ENTER_FULL_PATH;
		std::string filePath;
		std::getline(std::cin, filePath);

		if (filePath.size() > 0)
		{
			FileManager fileManager = FileManager(filePath);
			if (fileManager.checkFilePath())
			{
				if (!fileManager.fileExists())
				{
					std::cout << FILE_NOT_EXIST << std::endl;
				}
				else
				{
					std::vector<std::string> lines;
					fileManager.getLinesFromFile(lines);

					if (checkTransitionFormat(lines[0]))
					{
						std::cout << NO_INITIAL_STATE << '\n';
						exit(0);
					}

					state = lines[0];

					for (int i = 1; i < lines.size(); i++)
					{
						if (checkTransitionFormat(lines[i]))
						{
							head.addTransition(Transition(lines[i]));
						}
						else
						{
							std::cout << WRONG_SYNTAX_TRANSITION << '\n';
							std::cout << ERROR_LINE << i + 1 << '\n';
							exit(0);
						}
					}

					break;
				}
			}
		}
		else
		{
			std::cout << NOT_ENTERED_PATH << '\n';
		}
	}
}

void TuringMachine::readTapesFromFile()
{
	while (true)
	{
		std::cout << ENTER_FULL_PATH;
		std::string filePath;
		std::getline(std::cin, filePath);

		if (filePath.size() > 0)
		{
			FileManager fileManager = FileManager(filePath);
			if (fileManager.checkFilePath())
			{
				if (!fileManager.fileExists())
				{
					std::cout << FILE_NOT_EXIST << std::endl;
				}
				else
				{
					std::vector<std::string> lines;
					fileManager.getLinesFromFile(lines);

					for (int i = 0; i < lines.size(); i++)
					{
						tapes.push_back(Tape(lines[i]));
					}

					break;
				}
			}
		}
		else
		{
			std::cout << NOT_ENTERED_PATH << '\n';
		}
	}
}

void TuringMachine::readMachineFromConsole()
{
	while (true)
	{
		std::cout << ENTER_STATE;
		std::getline(std::cin, state);

		if (state.size() == 0)
		{
			std::cout << NOT_ENTERED_STATE << '\n';
		}
		else
		{
			break;
		}
	}

	std::cout << ENTER_TRANSITIONS << '\n';
	std::cout << STOP_TRANSITIONS << '\n';
	std::string transition;
	
	while (true)
	{
		std::getline(std::cin, transition);
		if (transition == "stop")
		{
			break;
		}
		
		if (transition.size() == 0)
		{
			std::cout << NOT_ENTERED_TRANSITION << '\n';
		}
		else
		{
			if (checkTransitionFormat(transition))
			{
				head.addTransition(Transition(transition));
			}
			else
			{
				std::cout << WRONG_SYNTAX_TRANSITION << '\n';
			}
		}
	}
}

void TuringMachine::readTapesFromConsole()
{
	std::cout << ENTER_TAPES << '\n';
	std::cout << STOP_TAPES << '\n';
	std::string tape;

	while (true)
	{
		std::getline(std::cin, tape);
		if (tape == "stop")
		{
			break;
		}
		
		if (tape.size() == 0)
		{
			std::cout << NOT_ENTERED_TAPE << '\n';
		}
		else
		{
			tapes.push_back(Tape(tape));
		}
	}
}

void TuringMachine::optionSelectingMachine()
{
	std::string option;
	while (1)
	{
		std::cout << OPTION;
		std::getline(std::cin, option);

		if (option.size() == 1)
		{
			try
			{
				if (stoi(option) == 1)
				{
					readMachineFromFile();
					break;
				}
				else if (stoi(option) == 2)
				{
					readMachineFromConsole();
					break;
				}
				else
				{
					std::cout << OPTION_NUMBER_NOT_EXIST << '\n';
				}
			}
			catch (const std::exception&)
			{
				std::cout << OPTION_MUST_NUMBER << '\n';
			}
		}
		else if (option.size() > 1)
		{
			std::cout << INVALID_OPTION << '\n';
		}
		else
		{
			std::cout << NOT_ENTERED_OPTION << '\n';
		}
	}
}

void TuringMachine::optionSelectingTapes()
{
	std::string option;
	while (1)
	{
		std::cout << OPTION;
		std::getline(std::cin, option);

		if (option.size() == 1)
		{
			try
			{
				if (stoi(option) == 1)
				{
					readTapesFromFile();
					break;
				}
				else if (stoi(option) == 2)
				{
					readTapesFromConsole();
					break;
				}
				else
				{
					std::cout << OPTION_NUMBER_NOT_EXIST << '\n';
				}
			}
			catch (const std::exception&)
			{
				std::cout << OPTION_MUST_NUMBER << '\n';
			}
		}
		else if (option.size() > 1)
		{
			std::cout << INVALID_OPTION << '\n';
		}
		else
		{
			std::cout << NOT_ENTERED_OPTION << '\n';
		}
	}
}

void TuringMachine::optionSelectingInspection(std::vector<int>& headPositions)
{
	std::string option;
	while (1)
	{
		std::cout << OPTION;
		std::getline(std::cin, option);

		if (option.size() == 1)
		{
			try
			{
				if (stoi(option) == 1)
				{
					while (true)
					{
						std::cout << ENTER_FULL_PATH;
						std::string filePath;
						std::getline(std::cin, filePath);

						if (filePath.size() > 0)
						{
							FileManager fileManager = FileManager(filePath);
							if (fileManager.checkFilePath())
							{
								if (fileManager.fileExists())
								{
									std::cout << FILE_EXISTS_SAME_NAME << '\n';
								}
								else
								{
									fileManager.saveResult(tapes, results, headPositions);
									break;
								}
							}
						}
						else
						{
							std::cout << NOT_ENTERED_PATH << '\n';
						}
					}

					break;
				}
				else if (stoi(option) == 2)
				{
					for (int i = 0; i < tapes.size(); i++)
					{
						for (int j = 0; j < tapes[i].getCells().size(); j++)
						{
							if (j == headPositions[i])
							{
								markHeadPosition(tapes[i].getCells()[j]);
							}
							else
							{
								std::cout << tapes[i].getCells()[j];
							}
						}

						std::cout << ' ';

						if (results[i])
						{
							std::cout << PROCESSED_SUCCESSFULLY;
						}
						else
						{
							std::cout << NOT_PROCESSED_SUCCESSFULLY;
						}

						std::cout << ' ' << headPositions[i] << '\n';
					}

					break;
				}
				else
				{
					std::cout << OPTION_NUMBER_NOT_EXIST << '\n';
				}
			}
			catch (const std::exception&)
			{
				std::cout << OPTION_MUST_NUMBER << '\n';
			}
		}
		else if (option.size() > 1)
		{
			std::cout << INVALID_OPTION << '\n';
		}
		else
		{
			std::cout << NOT_ENTERED_OPTION << '\n';
		}
	}
}

TuringMachine::TuringMachine()
{
	std::cout << INFORMATION_MACHINE << '\n';
	
	for (int i = 0; i < COUNT_OPTIONS_INFORMATION_MACHINE; i++)
	{
		std::cout << i + 1 << ". " << OPTIONS_INFORMATION_MACHINE[i] << '\n';
	}
	
	optionSelectingMachine();

	std::cout << INFORMATION_TAPES << '\n';

	for (int i = 0; i < COUNT_OPTIONS_INFORMATION_TAPES; i++)
	{
		std::cout << i + 1 << ". " << OPTIONS_INFORMATION_TAPES[i] << '\n';
	}

	optionSelectingTapes();
}

TuringMachine::TuringMachine(Head& head, std::vector<Tape>& tapes, std::string& state)
{
	this->head = head;
	this->tapes = tapes;
	this->state = state;
}

TuringMachine::TuringMachine(const TuringMachine& turingMachine)
{
	copy(turingMachine);
}

TuringMachine& TuringMachine::operator=(const TuringMachine& turingMachine)
{
	if (this != &turingMachine) {
		this->copy(turingMachine);
	}
	return *this;
}

void TuringMachine::addTapes(const std::vector<Tape>& tapes)
{
	for (int i = 0; i < tapes.size(); i++)
	{
		this->tapes.push_back(tapes[i]);
	}
}

const bool TuringMachine::processingSuccessful()
{
	if (find(results.begin(), results.end(), false) == results.end())
	{
		return true;
	}

	return false;
}

void TuringMachine::markHeadPosition(const char& character)
{
	char red[] = { 0x1b,'[','0',';','3','1','m',0 };
	char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
	std::cout << red << character << normal;
}

const Head& TuringMachine::getHead() const
{
	return head;
}

const std::vector<Tape>& TuringMachine::getTapes() const
{
	return tapes;
}

const std::string& TuringMachine::getState() const
{
	return state;
}

const std::vector<bool>& TuringMachine::getResults() const
{
	return results;
}

void TuringMachine::run()
{
	std::string initialState = state;
	std::vector<int> headPositions;

	if (tapes.size() >= 1)
	{
		for (int i = 0; i < tapes.size(); i++)
		{
			char element = '\0';
			time_t endwait = time(NULL) + SECONDS_BEFORE_END;
			while (true)
			{
				if (time(NULL) >= endwait)
				{
					headPositions.push_back(head.getPosition());
					results.push_back(false);
					break;
				}

				if (tapes[i].getCells().size() == head.getPosition())
				{
					headPositions.push_back(head.getPosition());
					results.push_back(false);
					break;
				}

				element = tapes[i].getCells()[head.getPosition()];
				int transitionIsFound = head.findTransition(element, state);

				if (transitionIsFound != -1)
				{
					Transition transition = head.getTransitions()[transitionIsFound];
					tapes[i].setCell(head.getPosition(), transition.getNewSymbol());

					if (head.getPosition() == 0)
					{
						head.restartPosition();
					}

					if (transition.getCommand() == 'L')
					{
						head.positionToTheLeft();
					}
					else if (transition.getCommand() == 'R')
					{
						head.positionToTheRight();
					}

					state = transition.getNewState();

					if (state == "halt")
					{
						results.push_back(true);
						headPositions.push_back(head.getPosition());
						break;
					}
				}
				else
				{
					if (tapes.size() == 1)
					{
						std::cout << NO_TRANSITION_FOUND << '\n';
					}
					headPositions.push_back(head.getPosition());
					results.push_back(false);
					break;
				}
			}

			state = initialState;
			head.restartPosition();
		}

		std::cout << INSPECTION << '\n';
		for (int i = 0; i < COUNT_OPTIONS_INSPECTION; i++)
		{
			std::cout << i + 1 << ". " << OPTIONS_INSPECTION[i] << '\n';
		}

		optionSelectingInspection(headPositions);
	}
	else
	{
		std::cout << NO_TAPES << '\n';
	}
}

void TuringMachine::compose(TuringMachine& secondTuringMachine)
{
	if (!tapes.empty())
	{
		std::cout << REGARDING_FIRST_RESULT << '\n';
		run();
		secondTuringMachine.addTapes(tapes);
		tapes.erase(tapes.begin(), tapes.end());
		tapes.shrink_to_fit();
	}
	else
	{
		std::cout << NO_TAPES << ' ' << NOTHING_TO_PROCESS << '\n';
		return;
	}
	
	std::cout << REGARDING_FINAL_RESULT << '\n';
	secondTuringMachine.run();
}

void TuringMachine::continueWith(TuringMachine& positiveTuringMachine, TuringMachine& negativeTuringMachine)
{
	std::vector<Tape> copyTapes = tapes;

	if (!tapes.empty())
	{
		std::cout << REGARDING_FIRST_RESULT << '\n';
		run();
	}
	else
	{
		std::cout << NO_TAPES << ' ' << NOTHING_TO_PROCESS << '\n';
		return;
	}

	if (processingSuccessful())
	{
		std::cout << POSITIVE_RESULT << ' ' << REGARDING_SECOND_RESULT << '\n';
		positiveTuringMachine.addTapes(copyTapes);
		positiveTuringMachine.run();
	}
	else
	{
		std::cout << NEGATIVE_RESULT << ' ' << REGARDING_SECOND_RESULT << '\n';
		negativeTuringMachine.addTapes(copyTapes);
		negativeTuringMachine.run();
	}
}

void TuringMachine::toSingleTape()
{
	std::vector<char> cells;
	for (int i = 0; i < tapes.size(); i++)
	{
		for (int j = 0; j < tapes[i].getCells().size(); j++)
		{
			if (tapes[i].getCells()[j] != EMPTY_CELL)
			{
				cells.push_back(tapes[i].getCells()[j]);
			}
		}
	}

	std::string cellsString(cells.begin(), cells.end());
	Tape tape = Tape(cellsString);

	tapes.erase(tapes.begin(), tapes.end());
	tapes.shrink_to_fit();
	tapes.push_back(tape);
}
