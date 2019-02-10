#pragma once
#include <string>

namespace WorkScript
{
	class Report;
	class Location
	{
	public:
		Location(const std::wstring &fileName, long line, long column) : fileName(fileName), line(line), column(column)
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

		inline const std::wstring &getFileName()const {return this->fileName;}
		inline void setFileName(const std::wstring &fileName){this->fileName = fileName;}
	private:
		long line = -1;
		long column = -1;
		std::wstring fileName;


		Location() = default;
		friend class DebugInfo;
	};


	class DebugInfo
	{
	public:
		inline DebugInfo() = default;

		inline DebugInfo(const Location &loc, Report *rep) : location(loc), report(rep)
		{}

		const Location &getLocation() const
		{
			return location;
		}

		void setLocation(const Location &location)
		{
			DebugInfo::location = location;
		}

		Report *getReport() const
		{
			return this->report;
		}
	protected:
		Location location;
		Report *report = nullptr;
	};

}