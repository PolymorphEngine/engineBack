/*
** EPITECH PROJECT, 2020
** Logger.hpp
** File description:
** header for Logger.c
*/

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <iostream>
namespace polymorph::engine
{
    class Logger
    {
    
        public:
            Logger() = default;
            ~Logger() = default;
    ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline const std::string BLACK = "\033[0;30m";   // BLACK
            static inline const std::string RED = "\033[0;31m";     // RED
            static inline const std::string GREEN = "\033[0;32m";   // GREEN
            static inline const std::string YELLOW = "\033[0;33m";  // YELLOW
            static inline const std::string BLUE = "\033[0;34m";    // BLUE
            static inline const std::string PURPLE = "\033[0;35m";  // PURPLE
            static inline const std::string CYAN = "\033[0;36m";    // CYAN
            static inline const std::string WHITE = "\033[0;37m";
            static inline const std::string RESET = "\033[0m";
    
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
            std::string _logDir = "Logs/";
            std::string _logInstance;
            std::string _engineLogFile = "engine.log";
            Mode _mode = RELEASE_MODE;
    //////////////////////--------------------------/////////////////////////
    
    
    
    /////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @details Overrides the default log directory of the Logger
             * @param logDir new log directory
             */
            void setLogDir(const std::string& logDir);
    
            /**
             * @details Adds a custom instance name prefix to the instance log sub directory
             * @param logInstanceName prefix name
             */
            void setLogInstanceName(const std::string& logInstanceName);
            
            bool isDebugBuild();
    
            /**
             * @details Inits the logger instance with a log subdirectory name by date time now and sets the program mode
             * @param mode program logger mode (Release or Debug)
             * @warning Default mode is RELEASE_MODE
             */
            void initLogInstance(Mode mode = RELEASE_MODE);
    
            /**
             * @details Logs a message to file and console depending on program mode and severity
             * @param message the message to log
             * @param level the severity of the log (optional)
             */
            void log(const std::string& message, severity level = INFO);
            /**
             * @details Logs a message to console depending on severity staticly
             * @param message the message to log
             * @param level the severity of the log (optional)
             */
            static void Log(const std::string& message, severity level = INFO);
    
            /**
             * @details Logs a message to file and console depending on program mode and severity
             * @param message the message to log
             * @param specificFile a custom file to log in (will be placed in the log dir into the instance subdir log)
             * @param level the severity of the log (optional)
             */
            void log(const std::string& message, std::string specificFile, severity level = INFO);

            /**
             * @details Gets and formats the actual date time to readable format
             * @param flags format flags (refer to std::strftime documentation)
             * @returns the formatted date time now string
             */
            static std::string getTimeNow(const std::string& flags);

            /**
             * @details Convert's the severity enumeration to string
             * @param level severity enum
             * @returns the string corresponding to the severity
             */
            static std::string severity_to_string(severity level);

            /**
             * @details Convert's the severity enumeration to ANSI color string
             * @param level severity enum
             * @returns the color corresponding to the severity
             */
            static std::string severity_to_color(severity level);

            
        private:
    
            /**
             * @details Logs a message and severity to console
             * @param message the message to log
             * @param level the severity of the log (optional)
             */
            void _consoleLog(const std::string& message, severity level);
    
            /**
             * @details Logs a message and severity to default logfile instance
             * @param message the message to log
             * @param level the severity of the log (optional)
             */
            void _logFile(const std::string& message, severity level);
    
            /**
             * @details Logs a message and severity to specified logfile
             * @param message the message to log
             * @param file the specific file to log in
             * @param level the severity of the log (optional)
             */
            void _logFile(const std::string& message, const std::string& file, severity level);
    
    //////////////////////--------------------------/////////////////////////
    
    };
}


#endif //ENGINE_LOGGER_HPP
