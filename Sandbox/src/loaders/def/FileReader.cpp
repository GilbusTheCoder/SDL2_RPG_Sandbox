#include "pch.h"
#include "../hdr/FileReader.h"

namespace Loaders {
	std::ifstream* FileReader::_reader = nullptr;
	bool FileReader::initReaderFromPath(const char* filepath) {
		if (!_reader) { _reader = new std::ifstream(); }
		
		_reader->open(filepath);
		if (!_reader->is_open()) { return false; }

		return true; }


	std::vector<std::string> FileReader::readFile() { 
		if (!_reader) { return { }; }
		std::vector<std::string> lines;
		std::string line;

		while (std::getline((*_reader), line)) {
			if (!isComment(line) && !line.empty()) { 
				lineToLower(line);
				lines.emplace_back(line); } } 
		
		return lines; }
	

	void FileReader::destroy(std::ifstream& reader) { 
		if (_reader) {
			if (_reader->is_open()) { _reader->close(); }
			delete _reader;
			_reader = nullptr; } }
	
	
	void FileReader::lineToLower(std::string& line) {
		for (int idx = 0; idx < line.size(); ++idx) {
			if (line[idx] < 91 && line[idx] > 64) { line[idx] -= 32; } } }
	
	
	std::vector<std::string> FileReader::splitLineAroundChar(const std::string& line, 
		const char delimiter) {	if (line.empty()) { return {}; }
		std::vector<std::string> split_lines;
		int start_idx = 0;
		
		for (int end_idx = 0; end_idx <= line.size(); ++end_idx) { 
			if(line[end_idx] == delimiter) {
				std::string new_line;
				new_line.append(line, start_idx, end_idx - start_idx);
				if (!new_line.empty()) { split_lines.emplace_back(new_line); }
				
				start_idx = ++end_idx; } }

		return split_lines; } 
}
