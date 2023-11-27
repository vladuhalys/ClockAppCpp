#include "Clock.h"
#include "Digits.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

Clock::Clock(){
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	unsigned short hours = std::localtime(&end_time)->tm_hour;
	unsigned short minutes = std::localtime(&end_time)->tm_min;
	unsigned short seconds = std::localtime(&end_time)->tm_sec;

	is_hours_changed= false;
	is_minutes_changed = false;
	is_seconds_changed = false;
	
	this->config = Config();
	this->time = new Time(hours, minutes, seconds);
}
Clock::Clock(Config config, Time time) 
{
	this->config = config;
	this->time = &time;
}

//Getters
Config Clock::get_config() {
	return this->config;
}
Time Clock::get_time() {
	return *time;
}

//Setters
void Clock::set_config(Config config) {
	this->config = config;
}
void Clock::set_time(Time time) {
	this->time = &time;
}


//Methods 
void Clock::update() 
{
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);

	unsigned short h = std::localtime(&end_time)->tm_hour;
	unsigned short m = std::localtime(&end_time)->tm_min;
	unsigned short s = std::localtime(&end_time)->tm_sec;
	delete this->time;
	this->time = new Time(h,m,s);
}

void Clock::reset() {
	this->is_hours_changed = false;
	this->is_minutes_changed = false;
	this->is_seconds_changed = false;
}

inline void Clock::show_h() {
	gotoxy(0, 0);
	if (this->time->get_hours() < 10)
	{
		cout << "0" << this->time->get_hours();
	}
	else {
		cout << this->time->get_hours();
	}
}
inline void Clock::show_m() {
	gotoxy(5, 0);
	if (this->time->get_minutes() < 10)
	{
		cout << "0" << this->time->get_minutes();
	}
	else {
		cout << this->time->get_minutes();
	}
}
inline void Clock::show_s() {
	gotoxy(10, 0);
	if (this->time->get_seconds() < 10)
	{
		cout << "0" << this->time->get_seconds();
	}
	else {
		cout << this->time->get_seconds();
	}
}
void show_border(int x, int y)
{
	gotoxy(x, y);
	cout << char(201);
	for (size_t i = 0; i < 90; i++)
	{
		cout << char(205);
	}
	cout << char(187);

	for (size_t i = y+1; i < y + 12; i++)
	{
		gotoxy(x, i);
		cout << char(186);
		gotoxy(x + 91, i);
		cout << char(186);
	}
	gotoxy(x, y+12);
	cout << char(200);
	for (size_t i = 0; i < 90; i++)
	{
		cout << char(205);
	}
	cout << char(188);
}

int output_dots(bool flag, int x, int y) {
	if (flag)
	{
		Digits::double_dots(x, y);
	}
	else {
		Digits::double_dots_empty(x, y);
	}
	return x + 7;
}

void output_digit(short number, int x, int y)
{
	switch (number)
	{
	case 0: {Digits::zero(x, y); } break;
	case 1: {Digits::one(x, y); }  break;
	case 2: {Digits::two(x, y); }  break;
	case 3: {Digits::three(x, y); }  break;
	case 4: {Digits::four(x, y); }  break;
	case 5: {Digits::five(x, y); }  break;
	case 6: {Digits::six(x, y); }  break;
	case 7: {Digits::seven(x, y); }  break;
	case 8: {Digits::eight(x, y); }  break;
	case 9: {Digits::nine(x, y); }  break;
	}
}

inline int Clock::show_digits(short number, int x, int y) {
	output_digit(number, x, y);
	return x + 12;
}
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void Clock::show() {
	//show time
	int x, y;
	int counter = 0;
	bool flag = true;
	do
	{
		setcursor(0, 0);
		update();
		float h = this->time->get_hours();
		float m = this->time->get_minutes();
		float s = this->time->get_seconds(); 
		x = 10;
		y = 7;
		show_border(x, y);
		y += 2;
		x += 3;
		x = show_digits(int(h/10), x, y);
		x = show_digits(int(h) % 10, x, y);
		x = output_dots(flag,x, y);
		x = show_digits(int(m / 10), x, y);
		x = show_digits(int(m) % 10, x, y);
		x = output_dots(flag,x, y);
		x = show_digits(int(s / 10), x, y);
		x = show_digits(int(s) % 10, x, y);
		if (counter == 50)
		{
			flag = !flag;
			counter = 0;
		}
		gotoxy(0, 0);
		counter++;
		if (s == 57)
		{
			cout << '\a';
		}
	} while (true);
	
}