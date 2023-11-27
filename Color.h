#ifndef color_h
#define color_h

enum ColorType
{
	Black,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Brown,
	LightGray,
	DarkGray,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	LightMagenta,
	Yellow,
	White
};

struct Color
{
public:
	ColorType primary_color;
	ColorType secondary_color;
	ColorType background_color;
	ColorType border_color;

	Color()
	{
		//default values
		this->primary_color = ColorType::White;
		this->secondary_color = ColorType::White;
		this->background_color = ColorType::Black;
		this->border_color = ColorType::White;
	}

	Color(ColorType primary_color, ColorType secondary_color, ColorType background_color, ColorType border_color)
	{
		this->primary_color = primary_color;
		this->secondary_color = secondary_color;
		this->background_color = background_color;
		this->border_color = border_color;
	}
};


#endif 
