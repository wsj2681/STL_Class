#define _CRT_SECURE_NO_WARNINGS

#include "save.h"

void save(std::string_view fileName) {

	size_t size = std::filesystem::file_size(fileName);
	std::unique_ptr<char, std::function<void(char*)>> p(new char[size], [](char* p) { delete[] p; });
	
	std::ifstream inFile(fileName);
	inFile.read(p.get(), size);

	std::ofstream outFile("2020_STL_강의내용.txt", std::ios::app|std::ios::binary);


	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);
	auto local = localtime(&time);

	outFile.imbue(std::locale("korean"));

	outFile << std::endl << std::endl << std::endl;
	outFile << "-----------------------------------" << std::endl;
	outFile << std::put_time(local, "%c - (%A)") << std::endl;
	outFile << "FILE SIZE - " << size << std::endl;
	outFile << "-----------------------------------" << std::endl;
	outFile << std::endl;

	outFile.write(p.get(), size);
	std::cout << fileName << "save - complete" << std::endl;
}