#pragma once
#include <string>

namespace WorkScript
{
	class Report;
	class Location
	{
	public:
		Location(const std::wstring &fileName, long line, long column) noexcept : fileName(fileName), line(line), column(column)
		{}

		inline long getLine() const noexcept
		{
			return line;
		}

		inline void setLine(long line) noexcept
		{
			Location::line = line;
		}

		inline long getColumn() const noexcept
		{
			return column;
		}

		inline void setColumn(long column) noexcept
		{
			Location::column = column;
		}

		inline const std::wstring &getFileName()const noexcept {return this->fileName;}
		inline void setFileName(const std::wstring &fileName) noexcept {this->fileName = fileName;}
	private:
		long line = -1;
		long column = -1;
		std::wstring fileName;


		Location() noexcept = default;
		friend class DebugInfo;
	};


	class DebugInfo
	{
	public:
		inline DebugInfo() noexcept = default;

		inline DebugInfo(const Location &loc, Report *rep) noexcept : location(loc), report(rep)
		{}

		const Location &getLocation() const noexcept
		{
			return location;
		}

		void setLocation(const Location &location) noexcept
		{
			DebugInfo::location = location;
		}

		Report *getReport() const noexcept
		{
			return this->report;
		}
	protected:
		Location location;
		Report *report = nullptr;
	};

}
