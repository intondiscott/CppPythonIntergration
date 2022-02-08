#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>
#include <limits>
#include "Menu.h"
using namespace std;


Menu::Menu() { }

void Menu::CustomCommandLine() {
	int backgroundColor, textColor, screen = 0;

	cout << " --------Customize your command prompt---------" << endl;
	printf("|Color id || Color || Color id ||   Color      |\n");
	printf("|   1     || Blue  ||(9)->11   || Light Blue   |\n");
	printf("|   2     || Green ||(0)->12   ||   Black      |\n");
	printf("|   3     || Aqua  ||(A)->13   || Light Green  |\n");
	printf("|   4     || Red   ||(B)->14   || Light Aqua   |\n");
	printf("|   5     || Purple||(C)->15   || Light Red    |\n");
	printf("|   6     || White ||(D)->16   || Light Yellow |\n");
	printf("|   7     || Yellow||(E)->17   || Light Purple |\n");
	printf("|  (8)->10|| Gray  ||(F)->18   || Bright White |\n");
	printf(" ----------------------------------------------\n");

	cout << "Enter Color id(Background Color) followed by Color id(Text Color) here -> ";

	cin >> backgroundColor, textColor;
	screen = backgroundColor, textColor;
	switch (screen) { // Custize Command prompt to your liking :D
	case 121: {cout << system("color 01"); break; } case 122: {system("color 02"); break; } case 123: {system("color 03"); break; }case 124: {system("color 04"); break; }
	case 125: {system("color 05"); break; }case 126: {system("color 06"); break; }case 127: {system("color 07"); break; }case 1213: {system("color 0A"); break; }case 1224: {system("color 0B"); break; }
	case 1215: {system("color 0C"); break; }case 1216: {system("color 0D"); break; }case 1217: {system("color 0E"); break; }case 1218: {system("color 0F"); break; }case 12: {system("color 12"); break; }
	case 13: {system("color 13"); break; }case 14: {system("color 14"); break; }case 15: {system("color 15"); break; }case 16: {system("color 16"); break; }case 17: {system("color 17"); break; }
	case 110: {system("color 18"); break; }case 111: {system("color 19"); break; }case 112: {system("color 10"); break; }case 113: {system("color 1A"); break; }case 114: {system("color 1B"); break; }
	case 115: {system("color 1C"); break; }case 116: {system("color 1D"); break; }case 117: {system("color 1E"); break; }case 118: {system("color 1F"); break; }case 21: {system("color 21"); break; }
	case 22: {system("color 22"); break; }case 23: {system("color 23"); break; }case 24: {system("color 24"); break; }case 25: {system("color 25"); break; }case 26: {system("color 26"); break; }
	case 27: {system("color 27"); break; }case 210: {system("color 28"); break; }case 211: {system("color 29"); break; }case 212: {system("color 20"); break; }case 213: {system("color 2A"); break; }
	case 214: {system("color 2B"); break; }case 215: {system("color 2C"); break; }case 216: {system("color 2D"); break; }case 217: {system("color 2E"); break; }case 218: {system("color 2F"); break; }
	case 31: {system("color 31"); break; }case 32: {system("color 32"); break; }case 33: {system("color 33"); break; }case 34: {system("color 34"); break; }case 35: {system("color 35"); break; }
	case 36: {system("color 36"); break; }case 37: {system("color 037"); break; }case 310: {system("color 38"); break; }case 311: {system("color 39"); break; }case 312: {system("color 30"); break; }
	case 313: {system("color 3A"); break; }case 314: {system("color 3B"); break; }case 315: {system("color 3C"); break; }case 316: {system("color 3D"); break; }case 317: {system("color 3E"); break; }
	case 318: {system("color 3F"); break; }case 41: {system("color 41"); break; }case 42: {system("color 42"); break; }case 43: {system("color 43"); break; }case 44: {system("color 44"); break; }
	case 45: {system("color 45"); break; }case 46: {system("color 46"); break; }case 47: {system("color 47"); break; }case 410: {system("color 48"); break; }case 411: {system("color 49"); break; }
	case 412: {system("color 40"); break; }case 413: {system("color 4A"); break; }case 414: {system("color 4B"); break; }case 415: {system("color 4C"); break; }case 416: {system("color 4D"); break; }
	case 417: {system("color 4E"); break; }case 418: {system("color 4F"); break; }case 51: {system("color 51"); break; }case 52: {system("color 52"); break; }case 53: {system("color 53"); break; }
	case 54: {system("color 54"); break; }case 55: {system("color 55"); break; }case 56: {system("color 56"); break; }case 57: {system("color 57"); break; }case 510: {system("color 58"); break; }
	case 511: {system("color 59"); break; }case 512: {system("color 50"); break; }case 513: {system("color 5A"); break; }case 514: {system("color 5B"); break; }case 515: {system("color 5C"); break; }
	case 516: {system("color 5D"); break; }case 517: {system("color 5E"); break; }case 518: {system("color 5F"); break; }case 61: {system("color 61"); break; }case 62: {system("color 62"); break; }
	case 63: {system("color 63"); break; }case 64: {system("color 64"); break; }case 65: {system("color 65"); break; }case 66: {system("color 66"); break; }case 67: {system("color 67"); break; }
	case 610: {system("color 68"); break; }case 611: {system("color 69"); break; }case 612: {system("color 60"); break; }case 613: {system("color 6A"); break; }case 614: {system("color 6B"); break; }
	case 615: {system("color 6C"); break; }case 616: {system("color 6D"); break; }case 617: {system("color 6E"); break; }case 618: {system("color 6F"); break; }case 71: {system("color 71"); break; }
	case 72: {system("color 72"); break; }case 73: {system("color 73"); break; }case 74: {system("color 74"); break; }case 75: {system("color 75"); break; }case 76: {system("color 76"); break; }
	case 77: {system("color 77"); break; }case 710: {system("color 78"); break; }case 711: {system("color 79"); break; }case 712: {system("color 70"); break; }case 713: {system("color 7A"); break; }
	case 714: {system("color 7B"); break; }case 715: {system("color 7C"); break; }case 716: {system("color 7D"); break; }case 717: {system("color 7E"); break; }case 718: {system("color 7F"); break; }
	case 101: {system("color 81"); break; }case 102: {system("color 82"); break; }case 103: {system("color 83"); break; }case 104: {system("color 84"); break; }case 105: {system("color 85"); break; }
	case 106: {system("color 86"); break; }case 107: {system("color 87"); break; }case 1010: {system("color 88"); break; }case 1011: {system("color 89"); break; }case 1012: {system("color 80"); break; }
	case 1013: {system("color 8A"); break; }case 1014: {system("color 8B"); break; }case 1015: {system("color 8C"); break; }case 1016: {system("color 8D"); break; }case 1017: {system("color 8E"); break; }
	case 1018: {system("color 8F"); break; }case 91: {system("color 91"); break; }case 92: {system("color 92"); break; }case 93: {system("color 93"); break; }case 94: {system("color 94"); break; }
	case 95: {system("color 95"); break; }case 96: {system("color 96"); break; }case 97: {system("color 97"); break; }case 910: {system("color 98"); break; }case 911: {system("color 99"); break; }
	case 912: {system("color 90"); break; }case 913: {system("color 9A"); break; }case 914: {system("color 9B"); break; }case 915: {system("color 9C"); break; }case 916: {system("color 9D"); break; }
	case 917: {system("color 9E"); break; }case 918: {system("color 9F"); break; }
	default: {cout << "invalid key..." << endl; }
	}
}

int Menu::CommandPrompt() {
	int selection = NULL;
	int value = 0;
	
	
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<
		"\n| 1.) Enter Food name                      |" <<
		"\n| 2.) Display Food quantity                |" <<
		"\n| 3.) Display histagram                    |" <<
		"\n| 4.) Exit                                 |" <<
		"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<
		"\nEnter your selection as a number 1, 2, 3 or 4..." << endl;
	
	try
	{
		cin >> selection;
		if (cin.fail()) {
			throw runtime_error("invalid input, please enter a number(program will now exit due to error)...\n");
		}
	}
	catch (runtime_error& here)
	{
		cout << here.what();
		return 4;
	}
	
	while (selection != 4) {
		if (selection == 1) {
			return value = 1;
		}
		else if (selection == 2) {
			return value = 2;
		}
		else if (selection == 3) {
			return value = 3;
		}
		else
		{
			cout << "invalid key..." << endl;
		}
		cout << "Enter your selection as a number 1, 2, 3, or 4..." << endl;
		cin >> selection;
	}
	
}
 
