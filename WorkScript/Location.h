#pragma once
class Location
{
public:
	Location(long line, long column) :line(line), column(column) {}
protected:
	long line, column;
};

