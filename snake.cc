/*==============================================================
#              Snake class for the game                        #
#==============================================================#*/

#include "snake.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

Map::Map(int width, int height){
	this->width=width;
	this->height=height;
	}
	

	Fruit::Fruit(Map &m){
		srand(time(0));
		fruit.x = 1+rand()%(m.get_width()-3);
		fruit.y = 1+rand()%(m.get_height()-3);
	}
	
	void Fruit::move_fruit(Map &m){
		fruit.x = 2+rand()%(m.get_width()-3);
		fruit.y = 2+rand()%(m.get_height()-3);
	}
	

	Snake::Snake(Map &m){
		size=1;
		body=new Point[size];
		body[0].x=m.get_width()/2;
		body[0].y=m.get_height()/2;
		no_fruit=0;
		body[0].shape='^';
	}
	void Snake::add_tail(){
		size++;
		Point *nptr= new Point[size];
		for(int i=0; i<size-1; i++){
			nptr[i]=body[i];
		}
		delete body;
		body=nptr;
	}

	bool Snake::is_gameover(Map &m)const{
		if(body[0].x<1||body[0].x>=m.get_width()||body[0].y<1||body[0].y>m.get_height()){
			return true;
		}
		for(int i=2; i<size-1; i++){
			if(body[i].x==body[0].x&&body[i].y==body[0].y){
				return true;
			}
			
		}

		return false;
	}
	
	bool Snake::eat_fruit(Fruit &f){
		if(body[0].x==f.get_fruitX()&&body[0].y==f.get_fruitY()){
			no_fruit+=2;
			return true;
		}
		return false;
	}

void Snake::display(Map &m, Fruit &f){
	system("cls");
	for(int i=0;i<=m.get_width(); i++){
		cout <<"#";
	}
	cout<<endl;
	for(int i=0;i<=m.get_height(); i++){
		string str="GAME OVER!!!";
		int sti=0;
			for(int j=0; j<=m.get_width();j++){
				bool snake_b=false;
				int index;
				for(int k=0; k<size;k++){
					if(body[k].x==j&&body[k].y==i){
						snake_b=true;
						index=k;
						break;
					}
				}
				if((is_gameover(m)&&i==m.get_height()/2 &&j>m.get_width()/4&&j<m.get_width()/4+13
				)){
					cout<<str[sti++];
				}
				
				else if(j==0||j==m.get_width()){
					cout<<"#";	
				}
				else if(!(j==f.get_fruitX()&&i==f.get_fruitY())&&snake_b){
					cout<<body[index].shape;
					
				}
				else if(j==f.get_fruitX()&&i==f.get_fruitY()){
					cout<<"O";
				
				}

				else{
					cout<<" ";
				}		
			}
			cout<<endl;
		} 		
		
		for(int i=0;i<=m.get_width(); i++){
		cout <<"#";
		}
		cout<<endl;
		
		cout<<"Score : "<<(int)(pow(4,sqrt(no_fruit)-1))<<endl;
		if(is_gameover(m)){
			int high_score;
			ifstream high_in("high_score.txt");
			if(!high_in.is_open()){
				cerr<<"Couldn't open the file";
				return;
			}
			high_in>>high_score;
			high_in.close();
			
			ofstream high_out ("high_score.txt");
			if(!high_out.is_open()){
				cerr<<"Couldn't open the file";
				return;
			}
			if((int)(pow(4,sqrt(no_fruit)-1))>high_score){
				high_out<<(int)(pow(4,sqrt(no_fruit)-1));
				high_score=(int)(pow(4,sqrt(no_fruit)-1));
			}
			else{
				high_out<<high_score;
			}
			high_out.close();
			
			cout<<"High Score : " <<high_score<<endl;
		}
		
		
	}
	
void Snake::move(char dir){
	if(size>1){
		for(int i=size-1; i>0; i--){
			body[i]=body[i-1];
		}
		
	}
	
	switch(dir){
		case 'a':
				body[0].x--;
				body[0].shape='<';
				break;
		case 'd':
				body[0].x++;
				body[0].shape='>';
				break;
		case 'w': 
				body[0].y--;
				body[0].shape='^';
				break;
		case 's': 
				body[0].y++;
				body[0].shape='v';
				break;
		}
	}
	


	
