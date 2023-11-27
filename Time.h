#ifndef time_h
#define time_h

struct Time
{
private:
	unsigned short hours;
	unsigned short minutes;
	unsigned short seconds;
public:
	Time()
	{
		//default values
		this->hours = 0;
		this->minutes = 0;
		this->seconds = 0;
	}
	Time(unsigned short hours, unsigned short minutes, unsigned short seconds)
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	unsigned short get_hours()
	{
		return this->hours;
	}
	unsigned short get_minutes()
	{
		return this->minutes;
	}
	unsigned short get_seconds()
	{
		return this->seconds;
	}
	void set_hours(unsigned short hours)
	{
		this->hours = hours;
	}
	void set_minutes(unsigned short minutes)
	{
		this->minutes = minutes;
	}
	void set_seconds(unsigned short seconds)
	{
		this->seconds = seconds;
	}
};

#endif // !time_h

