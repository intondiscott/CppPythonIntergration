#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include "Menu.h"
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonInjection");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonInjection");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean and clear space :D
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonInjection");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname; // clear space

	return _PyLong_AsInt(presult);
}

int main()
{
	Menu displayMenu; // object called
	int value, answer;
	displayMenu.CustomCommandLine(); // customs colors to add some personality :)
	do {
		ifstream read;
		string text, food;
		char ans;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		read.open("frequency.dat");
		vector<string>foodListName , foods;
		vector<int>foodFrequentcy;
		ofstream write;
		answer = displayMenu.CommandPrompt(); // condiction for switch case
		switch (answer) { // switch case used to get returned value from menu and from there call appropreit function 
		case 1: cout << "Enter the food you want to enter in the list..." << endl;
			do {
				cout << "enter item here -> ";
				cin >> food;
				foods.push_back(food);
				write.open("file.txt");
				for (auto& i : foods) { write << i << endl;} // writing file
				cout << "would you like to enter another item?(Y for yes or any key for no)..." << endl;
				cin >> ans;
				write.close();
			} while (ans == 'Y' || ans == 'y'); break;
		case 2: cout << "Prints out list of food + frequency \n--------------------------------------------" << endl;
			CallProcedure("writing_to_file");
			cout << "Items added on " << "(" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << "-" << 1900 + ltm->tm_year << ")" << endl;
			while (getline(read, text)) { cout << text << endl; } break;
		case 3: cout << "Prints histagram of list from " << 1 + ltm->tm_mon << "-" << ltm->tm_mday << "-" << 1900 + ltm->tm_year << "\n--------------------------------------" << endl;
			CallProcedure("writing_to_file");
			while ((read >> text) && (read >> value)) { // reading texts and numbers in file and seperating them accordinly
				foodListName.push_back(text);
				foodFrequentcy.push_back(value);
			}
			cout << "Items added on " << "(" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << "-" << 1900 + ltm->tm_year << ")" << endl; // sets date in standard form
			for (int i = 0; i < foodListName.size(); i++) { cout << foodListName[i] << " " << string(foodFrequentcy[i], '*') << endl; } break;
		default: cout << "invalid selection..." << endl;
		}
	} while (answer != 4);
	return 1;
	}