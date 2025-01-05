#pragma once

#include <string_view>

namespace Monolith
{
	class ErrorLog
	{
		public:
			static void log(std::string_view caller, std::string_view errorMsg);

		private:
	};
}


