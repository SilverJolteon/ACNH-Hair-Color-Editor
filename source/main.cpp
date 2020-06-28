#include "Menu.h"

int main(int argc, char** argv){
	int select_pnt = 0;
	char select_icon[] = ">  ";
	while(1){
		Menu::clear();
		std::cout << "---------------------------\nACNH Hair Color Editor v1.0\n     by SilverJolteon\n---------------------------" << std::endl;
		std::cout << " " << select_icon[0] << " Edit Hair Color" << std::endl;
		std::cout << " " << select_icon[1] << " Edit Eye Color" << std::endl;
		std::cout << " " << select_icon[2] << " Exit" << std::endl;
		std::cout << "---------------------------" << std::endl;
		if(hair_saved) std::cout << "Saved as CharaMakeHairColorParam.bcsv!" << std::endl;
		if(eye_saved) std::cout << "Saved as CharaMakeEyeColorParam.bcsv!" << std::endl;
		int kDown = getch();
		if(kDown == KEY_ESC) break;
		if(kDown == KEY_DOWN){
			select_pnt++;
			if(select_pnt > 2) select_pnt = 2;
			else{
				select_icon[select_pnt-1] = ' ';
				select_icon[select_pnt] = '>';
			}
			
		}
		if(kDown == KEY_UP){
			select_pnt--;
			if(select_pnt < 0) select_pnt = 0;
			else{
				select_icon[select_pnt+1] = ' ';
				select_icon[select_pnt] = '>';
			}
			
		}
		if((kDown == KEY_ENTER || kDown == KEY_SPACE) && select_pnt == 0) Menu::hair_menu();
		if((kDown == KEY_ENTER || kDown == KEY_SPACE) && select_pnt == 1) Menu::eye_menu();
		if((kDown == KEY_ENTER || kDown == KEY_SPACE) && select_pnt == 2) break;
		
	}
	return 0;
}