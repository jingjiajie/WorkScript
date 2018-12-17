#pragma once
namespace WorkScript {

	class Location
	{
	public:
		inline Location() {}
		inline Location(long line, long column) :line(line), column(column) {}

		inline long getLine() const { return this->line; };
		inline long getColumn() const { return this->column; };
	protected:
		long line, column;
	};
}