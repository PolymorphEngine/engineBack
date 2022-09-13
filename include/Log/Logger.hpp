/*
** EPITECH PROJECT, 2020
** Logger.hpp
** File description:
** header for Logger.c
*/

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <iostream>

class Logger
{

///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        static inline std::string BLACK = "\033[0;30m";   // BLACK
        static inline std::string RED = "\033[0;31m";     // RED
        static inline std::string GREEN = "\033[0;32m";   // GREEN
        static inline std::string YELLOW = "\033[0;33m";  // YELLOW
        static inline std::string BLUE = "\033[0;34m";    // BLUE
        static inline std::string PURPLE = "\033[0;35m";  // PURPLE
        static inline std::string CYAN = "\033[0;36m";    // CYAN
        static inline std::string WHITE = "\033[0;37m";
        static inline std::string RESET = "\033[0m";

        enum severity {
            DEBUG,
            INFO,
            MINOR,
            MAJOR
        };

        enum Mode {
            DEBUG_MODE,
            RELEASE_MODE
        };

    private:
        static inline std::string _logDir = "Logs/";
        static inline std::string _logInstance;
        static inline std::string _engineLogFile = "engine.log";
        static inline Mode _mode = RELEASE_MODE;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:
        /**
         * @details Overrides the default log directory of the Logger
         * @param logDir new log directory
         */
        static void setLogDir(const std::string& logDir);

        /**
         * @details Adds a custom instance name prefix to the instance log sub directory
         * @param logInstanceName prefix name
         */
        static void setLogInstanceName(const std::string& logInstanceName);
        
        static bool isDebugBuild();

        /**
         * @details Inits the logger instance with a log subdirectory name by date time now and sets the program mode
         * @param mode program logger mode (Release or Debug)
         * @warning Default mode is RELEASE_MODE
         */
        static void initLogInstance(Mode mode = RELEASE_MODE);

        /**
         * @details Logs a message to file and console depending on program mode and severity
         * @param message the message to log
         * @param level the severity of the log (optional)
         */
        static void log(const std::string& message, severity level = INFO);

        /**
         * @details Logs a message to file and console depending on program mode and severity
         * @param message the message to log
         * @param specificFile a custom file to log in (will be placed in the log dir into the instance subdir log)
         * @param level the severity of the log (optional)
         */
        static void log(const std::string& message, std::string specificFile, severity level = INFO);


    private:

        /**
         * @details Logs a message and severity to console
         * @param message the message to log
         * @param level the severity of the log (optional)
         */
        static void _consoleLog(const std::string& message, severity level);

        /**
         * @details Logs a message and severity to default logfile instance
         * @param message the message to log
         * @param level the severity of the log (optional)
         */
        static void _logFile(const std::string& message, severity level);

        /**
         * @details Logs a message and severity to specified logfile
         * @param message the message to log
         * @param file the specific file to log in
         * @param level the severity of the log (optional)
         */
        static void _logFile(const std::string& message, const std::string& file, severity level);

        /**
         * @details Gets and formats the actual date time to readable format
         * @param flags format flags (refer to std::strftime documentation)
         * @returns the formatted date time now string
         */
        static std::string _getTimeNow(const std::string& flags);

        /**
         * @details Convert's the severity enumeration to string
         * @param level severity enum
         * @returns the string corresponding to the severity
         */
        static std::string _severity_to_string(severity level);

        /**
         * @details Convert's the severity enumeration to ANSI color string
         * @param level severity enum
         * @returns the color corresponding to the severity
         */
        static std::string _severity_to_color(severity level);
//////////////////////--------------------------/////////////////////////

};


#endif //ENGINE_LOGGER_HPP
