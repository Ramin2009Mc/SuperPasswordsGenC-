// Подключение библиотек
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Функция отвечающая за генерацию паролей
string corn(string col, string length, string low, string up, string nums, string sima, string flag) {
	const string low_abc = "abcdefghijklmnopqrstuvwxyz";
	const string up_abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const string numbers = "0123456789";
	const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
	const string symbolsSPECIAL = "_.";

	int col_int = stoi(col);
	int len_int = stoi(length);
	srand(time(NULL));

	string final;
	string err = "| Fatal Error |\n";
	string passwords;

	if (col_int <= 0 || len_int <= 0) return err;
	else {
		if (low == "1") final += low_abc;
		if (up == "1") final += up_abc;
		if (nums == "1") final += numbers;
		if (sima == "1") {
			if (flag == "0") final += symbols;
			else if (flag == "1") final += symbolsSPECIAL;
			else return err;
		}

		ofstream file("pwrds.txt", ofstream::trunc);

		for (int j = 0; j < col_int; j++) {
			file << " ==> ";
			passwords += " ==> ";
			for (int i = 0; i < len_int; ++i) {
				string ox = "";
				ox += final[rand() % final.length()];
				file << ox;
				passwords += ox;
			}
			file << "\n";
			passwords += "\n";
		}
		file.close();
	}
	SetConsoleTextAttribute(hConsole, 7);
	if (col_int == 1) passwords += "\nПароль записан по адресу >> C: Users п315 source repos ConsoleApplication32 ConsoleApplication32 pwrds.txt\n";
	else passwords += "\nПароли записаны по адресу >> C: Users п315 source repos ConsoleApplication32 ConsoleApplication32 pwrds.txt\n";
	SetConsoleTextAttribute(hConsole, 8);
	return passwords;
}


// Функция получающая данные от пользователя (меню)
string start() {
	string col, len, low, up, nums, sima, flag, err = "===============\n| Fatal Error |\n===============";
	int run = 0;
	bool errorShown = false;

	SetConsoleTextAttribute(hConsole, 1);
	cout << "=====================" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "| ГЕНЕРАТОР ПАРОЛЕЙ |" << endl;
	SetConsoleTextAttribute(hConsole, 1);
	cout << "=====================" << endl;
	while (run < 1) {
		SetConsoleTextAttribute(hConsole, 3);
		cout << "\n\nВведите количество паролей: ";
		SetConsoleTextAttribute(hConsole, 7);
		cin >> col;
		bool validInput = true;
		for (char c : col) {
			if (!isdigit(c)) {
				validInput = false;
				break;
			}
		}
		if (validInput && stoi(col) > 0)run++;
		else {
			errorShown = false;
			if (!errorShown) {
				SetConsoleTextAttribute(hConsole, 4);
				cout << "\n" << err;
				errorShown = true;
			}
		}
	}
	errorShown = false;
	while (run < 6) {
		while (run < 2) {
			SetConsoleTextAttribute(hConsole, 3);
			(col == "1") ? cout << "\n\nВведите длину пароля: " : cout << "\n\nВведите длины паролей: ";
			SetConsoleTextAttribute(hConsole, 7);
			cin >> len;
			bool validInput = true;
			for (char c : len) {
				if (!isdigit(c)) {
					validInput = false;
					break;
				}
			}
			if (validInput && stoi(len) > 0)run++;
			else {
				errorShown = false;
				if (!errorShown) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "\n" << err;
					errorShown = true;
				}
			}
		}
		while (run < 3) {
			SetConsoleTextAttribute(hConsole, 3);
			cout << "\n\nДобавлять ли в пароль буквы с ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "нижним";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " регистром ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "(0 - Нет, 1 - Да)";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " >> ";
			SetConsoleTextAttribute(hConsole, 7);
			cin >> low;
			bool validInput = true;
			for (char c : low) {
				if (!isdigit(c)) {
					validInput = false;
					break;
				}
			}
			if (validInput && (low == "1" || low == "0"))run++;
			else {
				errorShown = false;
				if (!errorShown) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "\n" << err;
					errorShown = true;
				}
			}
		}
		while (run < 4) {
			SetConsoleTextAttribute(hConsole, 3);
			cout << "\n\nДобавлять ли в пароль буквы с ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "верхним ";
			SetConsoleTextAttribute(hConsole, 3);
			cout << "регистром ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "(0 - Нет, 1 - Да)";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " >> ";
			SetConsoleTextAttribute(hConsole, 7);
			cin >> up;
			bool validInput = true;
			for (char c : up) {
				if (!isdigit(c)) {
					validInput = false;
					break;
				}
			}
			if (validInput && (up == "1" || up == "0")) run++;
			else {
				errorShown = false;
				if (!errorShown) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "\n" << err;
					errorShown = true;
				}
			}
		}
		while (run < 5) {
			SetConsoleTextAttribute(hConsole, 3);
			cout << "\n\nДобавлять ли ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "числа ";
			SetConsoleTextAttribute(hConsole, 3);
			cout << "в пароль ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "(0 - Нет, 1 - Да)";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " >> ";
			SetConsoleTextAttribute(hConsole, 7);
			cin >> nums;
			bool validInput = true;
			for (char c : nums) {
				if (!isdigit(c)) {
					validInput = false;
					break;
				}
			}
			if (validInput && (nums == "1" || nums == "0"))run++;
			else {
				errorShown = false;
				if (!errorShown) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "\n" << err;
					errorShown = true;
				}
			}
		}
		while (run < 6) {
			SetConsoleTextAttribute(hConsole, 3);
			cout << "\n\nДобавлять ли ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "спец.символы ";
			SetConsoleTextAttribute(hConsole, 3);
			cout << "в пароль ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "(0 - Нет, 1 - Да)";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " >> ";
			SetConsoleTextAttribute(hConsole, 7);
			cin >> sima;
			bool validInput = true;
			for (char c : sima) {
				if (!isdigit(c)) {
					validInput = false;
					break;
				}
			}
			if (validInput && (sima == "1" || sima == "0"))run++;
			else {
				errorShown = false;
				if (!errorShown) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "\n" << err;
					errorShown = true;
				}
			}
		}
		if ((int(stoi(low)) + int(stoi(up)) + int(stoi(nums)) + int(stoi(sima))) == 0) {
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "\n\n==========================================" << std::endl;
			std::cout << "| ВЫ НЕ ВЫБРАЛИ КОМПОНЕНТЫ ДЛЯ ГЕНЕРАЦИИ |" << std::endl;
			std::cout << "==========================================" << std::endl;
			run = 2;
		}
	}
	if (sima == "1") {
		while (run < 7) {
			SetConsoleTextAttribute(hConsole, 3);
			cout << "\nВ пароле будет использоваться ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "полный ";
			SetConsoleTextAttribute(hConsole, 3);
			cout << "или ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "ограниченный";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " набор \nспециальных символов ";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "(0 - Полный, 1 - Ограниченный) ";
			SetConsoleTextAttribute(hConsole, 3);
			cout << " >> ";
			SetConsoleTextAttribute(hConsole, 7);
			cin >> flag;
			bool validInput = true;
			for (char c : flag) {
				if (!isdigit(c)) {
					validInput = false;
					break;
				}
			}
			if (validInput && (flag == "1" || flag == "0")) {
				run++;
			}
			else {
				errorShown = false;
				if (!errorShown) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "\n" << err;
					errorShown = true;
				}
			}
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\nRESULT: " << endl;
	SetConsoleTextAttribute(hConsole, 8);
	string res = corn(col, len, low, up, nums, sima, flag);
	return res;
}

int main() {
	setlocale(LC_ALL, "ru");
	int running = 0;
	bool psrun = true;
	string err = "\n===============\n| Fatal Error |\n===============\n";
	string tm;

	while (running < 1) {
		if (psrun) {
			cout << "\n" << start();
		}
		psrun = false;

		SetConsoleTextAttribute(hConsole, 3);
		cout << "\nЗавершить работу программы ";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "(0 - Нет, 1 - Да) ";
		SetConsoleTextAttribute(hConsole, 3);
		cout << " >> ";
		SetConsoleTextAttribute(hConsole, 7);
		cin >> tm;

		bool is_valid = tm.size() == 1 && (tm == "0" || tm == "1");
		if (is_valid) {
			if (tm == "0") {
				cout << "\n";
				psrun = true;
			}
			else {
				SetConsoleTextAttribute(hConsole, 2);
				cout << (tm == "1" ? "\n\n==============================\n| ПРОГРАММА ЗАВЕРШИЛА РАБОТУ |\n==============================\n\n" : "\n");
				SetConsoleTextAttribute(hConsole, 7);
				running++;
			}
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			cout << err;
			SetConsoleTextAttribute(hConsole, 7);
		}
	}

	return 0;
}
