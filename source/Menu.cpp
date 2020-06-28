#include "Menu.h"
#include "Color.h"

bool hair_saved = false;
bool eye_saved = false;

void Menu::clear(){
	system("@cls");
}

void Menu::hair_menu(){
	bool finished = false;
	std::string hair_color, hair, shine, choice;
	while(!finished){
		Menu::clear();
		std::cout << "---------------------------\n     Hair Color Editor\n---------------------------" << std::endl;
		std::cout << "Hair Color Number: ";
		std::cin >> hair_color;
		std::cout << "Hair Color (in hex): #";
		std::cin >> hair;
		std::cout << "Hair Shine Color (in hex): #";
		std:: cin >> shine;
		Color::edit_hair(std::stoi(hair_color, 0, 10), std::stoi(hair, 0, 16), std::stoi(shine, 0, 16));
		std::cout << std::endl << "Change another? (y/n): ";
		std::cin >> choice;
		if(choice.compare("n") == 0) finished = true;
	}
	Color::save_hair();
	hair_saved = true;
}

void Menu::eye_menu(){
	bool finished = false;
	std::string eye_color, eye, choice;
	while(!finished){
		Menu::clear();
		std::cout << "---------------------------\n     Eye Color Editor\n---------------------------" << std::endl;
		std::cout << "Eye Color Number: ";
		std::cin >> eye_color;
		std::cout << "Eye Color (in hex): #";
		std::cin >> eye;
		Color::edit_eye(std::stoi(eye_color, 0, 10), std::stoi(eye, 0, 16));
		std::cout << std::endl << "Change another? (y/n): ";
		std::cin >> choice;
		if(choice.compare("n") == 0) finished = true;
	}
	Color::save_eye();
	eye_saved = true;
}

/*
int main(int agrc, char** argv){
	std::cout << "---------------------------\nACNH Hair Color Editor v0.4\n     by SilverJolteon\n---------------------------" << std::endl << std::endl;
	bool finished = false;
	std::string hair_color, hair, shine, choice;
	while(!finished){
		std::cout << "Hair Color Number: ";
		std::cin >> hair_color;
		std::cout << "Hair Color (in hex): #";
		std::cin >> hair;
		std::cout << "Hair Shine Color (in hex): #";
		std:: cin >> shine;
		Color::edit_hair(std::stoi(hair_color, 0, 10), std::stoi(hair, 0, 16), std::stoi(shine, 0, 16));
		std::cout << std::endl << "Change another? (y/n): ";
		std::cin >> choice;
		if(choice.compare("n") == 0) finished = true;
	}
	std::cout << std::endl << "Saved as CharaMakeHairColorParam.bcsv" << std::endl;
	Color::save_hair();
	
	return 0;
}
*/