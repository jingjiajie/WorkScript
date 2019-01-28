#pragma once
namespace WorkScript {
	class Location
	{
	public:
		Location() = default;

		Location(long line, long column) : line(line), column(column)
		{}

		inline long getLine() const
		{
			return line;
		}

		inline void setLine(long line)
		{
			Location::line = line;
		}

		inline long getColumn() const
		{
			return column;
		}

		inline void setColumn(long column)
		{
			Location::column = column;
		}

	private:
		long line = -1;
		long column = -1;
	};

	class DebugInfo
	{
	public:
		inline DebugInfo()  = default;
		inline DebugInfo(const Location &loc) :location(loc) {}

		inline long getLine() const { return this->location.getLine(); };
		inline long getColumn() const { return this->location.getColumn(); };
	protected:
		Location location;
	};

}