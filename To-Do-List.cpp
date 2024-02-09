#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_TASKS = 100;
struct Task
{
	string description;
	bool completed;
	Task() : completed(false) {}
};
class TodoList
{
private:
	Task tasks[MAX_TASKS];
	int taskCount;

public:
	TodoList() : taskCount(0) {}
	void addTask(const string &description)
	{
		if (taskCount < MAX_TASKS)
		{
			tasks[taskCount].description = description;
			taskCount++;
			cout << "\t\t\t\t\tTASK ADD SUCCESSFULLY !\n";
		}
		else
		{
			cout << "\t\t\t\t\tTASK LIST IS FULL.CANNOT ADD MORE TASK.\n";
		}
	}
	void viewList()
	{
		if (taskCount == 0)
		{
			cout << "\t\t\t\t\tNo Task Avalaible!\n";
			return;
		}
		cout << "\t\t\t\t\t======TASK LIST!======\n";
		cout << setw(4) << "\t\t\t\t\tNo." << setw(35) << "DESCRIPTION" << setw(20) << "STATUS"
			 << "\n";
		for (int i = 0; i < taskCount; ++i)
		{
			cout << setw(4) << "\t\t\t\t\t" << i + 1 << setw(35) << tasks[i].description << setw(20) << (tasks[i].completed ? "completed" : "panding...") << "\n";
		}
	}
	void markTaskCompleted(int taskIndex)
	{
		if (taskIndex >= 0 && taskIndex < taskCount)
		{
			tasks[taskIndex].completed = true;
			cout << "\t\t\t\t\tTASK MARKED AS COMPLETED!\n";
		}
		else
		{
			cout << "\t\t\t\t\tInvalid Task Number.\n";
		}
	}
	void removeTask(int taskIndex)
	{
		if (taskIndex >= 0 && taskIndex < taskCount)
		{
			for (int i = taskIndex; i < taskCount - 1; ++i)
			{
				tasks[i] = tasks[i + 1];
			}
			taskCount--;
			cout << "\t\t\t\t\t Task Remove Successfully!\n";
		}
		else
		{
			cout << "\t\t\t\t\t Invalid Task Number.\n";
		}
	}
};
int main()
{
	TodoList todoList;
	while (true)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t========================================\n";
		cout << "\t\t\t\t\t****************************************";
		cout << "\n\t\t\t\t\t  ======TODO LIST MANAGER======\n";
		cout << "\t\t\t\t\t1. Add Task\n";
		cout << "\t\t\t\t\t2. View Task\n";
		cout << "\t\t\t\t\t3. Marked Task As Completed\n";
		cout << "\t\t\t\t\t4. Remove Task\n";
		cout << "\t\t\t\t\t5. Exit\n";
		cout << "\t\t\t\t\t****************************************\n";
		cout << "\t\t\t\t\t========================================\n";
		cout << "\t\t\t\t\tENTER YOUR CHOICE:";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{

			string taskDescription;
			cout << "\t\t\t\t\tEnter Your Task:";
			cin.ignore();
			getline(cin, taskDescription);
			todoList.addTask(taskDescription);
			break;
		}
		case 2:
			todoList.viewList();
			break;
		case 3:
		{
			int taskIndex;
			cout << "\t\t\t\t\tEnter Task Number To Marked as Completed.";
			cin >> taskIndex;
			todoList.markTaskCompleted(taskIndex - 1);
			break;
		}
		case 4:
		{
			int taskIndex;
			cout << "\t\t\t\t\tEnter Task Number To Remove.";
			cin >> taskIndex;
			todoList.removeTask(taskIndex - 1);
			break;
		}
		case 5:
			cout << "\t\t\t\t\t________________________________________\n";
			cout << "\t\t\t\t\t========================================\n";
			cout << "\t\t\t\t\tEXISTING THE TODO LIST MANAGER. GoodBye!\n";
			cout << "\t\t\t\t\t========================================\n";
			cout << "\t\t\t\t\t________________________________________\n";

			break;
			return 0;
		default:
			cout << "\t\t\t\t\tInvalid Choice.Please try again!\n";
		}
		cout << "\t\t\t\t\tPress Enter TO Continue.....";
		cin.ignore();
		cin.get();
	}
	return 0;
}
