#include "logger.h"

#include <iostream>
#include <windows.h>

namespace engine {

	void Logger::Log(MessageType type, const std::string& message)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (type) 
		{
		case MessageType::MESSAGE:
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << "[MESSAGE]: " << message << std::endl;
			break;
		case MessageType::WARNING:
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "[WARNING]: " << message << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
			break;
		case MessageType::FATAL:
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "[FATAL]: " << message << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
			break;
		}
	}

}
