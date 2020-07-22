#ifndef snake_h
#define snake_h


class Point{
	public: int x, y;
		char shape;
};

class Map{
	int width, height;
	public:
	Map(int width=30, int height=25);
	int get_width(){return width;}
	int get_height(){return height;}
};

class Fruit{
	protected:
	Point fruit;
	public:
	Fruit(Map &m);
	void move_fruit(Map &m);
	int get_fruitX()const{return fruit.x;}
	int get_fruitY()const{return fruit.y;}
};

class Snake {
	private:
	Point *body;
	int size;
	int no_fruit;
	public:
	Snake(Map &m);
	void add_tail();
	bool is_gameover(Map &m)const;
	bool eat_fruit(Fruit &f);
	void display(Map &m, Fruit &f);
	void move(char dir);
};
#endif 