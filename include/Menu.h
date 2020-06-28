#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <fstream>
#include <conio.h>

#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_SPACE 32
#define KEY_UP 72
#define KEY_DOWN 80

extern bool hair_saved;
extern bool eye_saved;

namespace Menu{
	void clear();
	void hair_menu();
	void eye_menu();
}

#endif