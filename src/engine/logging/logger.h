#pragma once

#include <string>

namespace engine {

	class Logger
	{
	public:
		static enum class MessageType { INFO, WARNING, FATAL };

		static void Log(MessageType type, const std::string& message);
	};

}