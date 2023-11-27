#ifndef config_h
#define config_h

#include "InnerSize.h"
#include "Color.h"

struct Config
{
private:
	InnerSize inner_console_window_size;
	Color colors;
public:
	Config()
	{
		//default values
		this->inner_console_window_size = InnerSize();
		this->colors = Color();
	}
	Config(InnerSize inner_console_window_size, Color colors)
	{
		this->inner_console_window_size = inner_console_window_size;
		this->colors = colors;
	}
	InnerSize get_inner_console_window_size()
	{
		return this->inner_console_window_size;
	}
	Color get_colors()
	{
		return this->colors;
	}
};


#endif // !config_h

