#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int public_QuestionNum = 0;
int public_Score = 1;
bool public_IsLastQuestionCorrect = false;

void PrintQuestion(std::string question)
{
	std::cout << "Question " << public_QuestionNum << " : " << question << "\n";
}

void PrintAnswer(std::string userAnswer, std::string answer, bool isCorrect)
{
	if (isCorrect)
	{
		std::cout << "Correct!\n============================================\n";
		public_Score++;
	}
	else
	{
		std::cout << "Incorrect!\nThe answer is " << answer << "\n============================================\n";
	}
}

void AskQuestion(std::string question, std::string answer)
{
	std::string userAnswer;
	PrintQuestion(question);
	std::cin >> userAnswer;
	public_IsLastQuestionCorrect = userAnswer == answer;
	PrintAnswer(userAnswer, answer, userAnswer == answer);

	public_QuestionNum++;
}

void AskAgain(std::string question, std::string answer)
{
	AskQuestion(question, answer);
}

int main()
{
	std::ifstream inFile("Q and A.txt");

	if (!inFile.is_open())
	{
		std::cout << "You haven't named your file correctly. Is your file name 'Q and A.txt'?"; 
		__debugbreak();
	}

	std::vector<std::string> Questions;
	std::vector<std::string> Answers;

	std::string line;
	
	// read the questions and answers from the file
	while (std::getline(inFile, line))
	{
		// read in a question
		if (line.find("Q:") != std::string::npos)
		{
			std::string question = line.substr(3);

			Questions.push_back(question);
		}
		// read in an answer
		else if (line.find("A:") != std::string::npos)
		{
			std::string answer = line.substr(3);

			Answers.push_back(answer);
		}
	}

	float questionAmount = (float)Questions.size();

	for (int qIndex = 0; qIndex < questionAmount; qIndex++)
	{
		AskQuestion(Questions[qIndex], Answers[qIndex]);
	}

	if (public_Score > questionAmount * 0.75f)
	{
		std::cout << "Your score is " << public_Score << ", nice!\n";
	}
	else
	{
		std::cout << "YOU SUCC U R AN IDIOT THE SCORE IS TRASH LIKE " << public_Score << " WHAT KIND OF A SCORE IS THAT EVEN?????\n";
	}

	std::cout << "\n";

	system("pause");

	return 0;
}