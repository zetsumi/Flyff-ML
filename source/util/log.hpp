#pragma once

#if defined(_WIN64)
#include <Windows.h>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cstdarg>

namespace fe
{
    static void _log(bool consoleVS, bool endLine, const char* functionName, uint32_t line, const char* format, ...)
    {
        try
        {
            if (functionName == nullptr || format == nullptr)
                return;
            std::vector<char> temp = std::vector<char>{};
            std::size_t length = std::size_t{ 1024 };
            std::va_list args;
            while (temp.size() <= length)
            {
                temp.resize(length + 1);
                va_start(args, format);
                const auto status = std::vsnprintf(temp.data(), temp.size(), format, args);
                va_end(args);
                if (status < 0)
                    throw std::runtime_error{ "string formatting error" };
                length = static_cast<std::size_t>(status);
            }

            // Ajout de prefix au message
            std::string message;
            if (consoleVS == false)
            {
                message.append("$> ");
            }
            else
            {
                message.append(functionName);
                message.append(" [");
                message.append(std::to_string(line));
                message.append("]: ");

            }
            message.append(std::string{ temp.data(), length });
            if (endLine == true && consoleVS == true)
                message.append("\n");

#if defined(_WIN64)
            if (consoleVS == true)
            {
                ::OutputDebugStringA(message.c_str());
            }
            else
            {
                std::cout << message;
                if (endLine == true)
                    std::cout << std::endl;
            }
#else
            std::cout << message;
            if (endLine == true)
                std::cout << std::endl;
#endif
        }
        catch (const std::exception&)
        {
        }
    }
}

#if defined(_WIN64)
#if defined(_DEBUG)
#define FE_LOG(format, ...)			fe::_log(false, true, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#define FE_PROMPT(format, ...)		fe::_log(false, false, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#define FE_CONSOLELOG(format, ...)	fe::_log(true, true, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#else
#define FE_LOG(format, ...)			fe::_log(false, true, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#define FE_PROMPT(format, ...)		fe::_log(false, false, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#define FE_CONSOLELOG(format, ...)	fe::_log(true, true, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#endif //_DEBUG

#elif defined(__APPLE__)
#if defined(_DEBUG)
#define FE_LOG(format, ...)			fe::_log(false, true, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#define FE_PROMPT(format, ...)		fe::_log(false, false, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#define FE_CONSOLELOG(format, ...)	fe::_log(true, true, __FUNCTION__, __LINE__, format, __VA_ARGS__)
#else
#define FE_LOG(format, ...)			fe::_log(false, true, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)
#define FE_PROMPT(format, ...)		fe::_log(false, false, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)
#define FE_CONSOLELOG(format, ...)	fe::_log(true, true, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)
#endif //_DEBUG

#endif//_WIN64