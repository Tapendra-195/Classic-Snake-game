/*=======================================================================
#                    Main file for the snake game                       #
#=======================================================================#*/

#include<iostream>
#include <conio.h>
#include "snake.h"
using namespace std;

char get_key(char old);
int main(){
	Map m;
	Snake s(m);
	Fruit f(m);	
	char key='0';

	while(!s.is_gameover(m)){
		if(s.eat_fruit(f)){
			f.move_fruit(m);
			s.add_tail();
		}
		char old=key;
		
		if(_kbhit()){
			key=get_key(old);	
		}
		
		if((old=='a'&&key=='d')||(old=='d'&&key=='a')||(old=='w'&&key=='s')||(old=='s'&&key=='w')){key=old;}
		
		s.move(key);
		s.display(m,f);
		
		
	}
}

char get_key(char old){
	char key;
	switch(_getch()){
				case 'a': key='a';
						break;
				case 'd': key='d';
						break;
				case 'w': key='w';
						break;
				case 's': key='s';
						break;
				default:key=old;
			}	
	
	return key;
}
		
		

	
	
