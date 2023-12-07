#pragma once
#include <fstream>

namespace Loaders {
	class FileReader {
	protected:
		static std::ifstream* _reader;

	protected:
		static bool initReaderFromPath(const char* filepath);
		static std::vector<std::string> readFile();
		static void lineToLower(std::string& line);
		static std::vector<std::string> splitLineAroundChar(const std::string& line,
			const char delimiter);
		static void destroy(std::ifstream& reader);


		static inline const bool isComment(const std::string& line) {
			if (line[0] == '#') { return true; }
			return false; }


		static inline void removeWhitespace(std::string& line) {
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); }
	};
}

