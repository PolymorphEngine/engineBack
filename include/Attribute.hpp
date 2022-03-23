/*
** EPITECH PROJECT, 2020
** attribute.hpp.h
** File description:
** header for Attribute.cpp
*/

#ifndef MYXMLPP_ATTRIBUTE_HPP
#define MYXMLPP_ATTRIBUTE_HPP

#include <string>
#include <vector>
#include <iostream>

namespace myxmlpp {

    class Doc;

    typedef enum {OPENRD, OPENWR, OPENRDWR, OPENAPP} openMode_t;

    /**
     * Attribute in a node
     */
    class Attribute {
        private:
            /**
             * Key of the attribute
             */
            std::string _key;

            /**
             * Value of the attribute
             */
            std::string _value;

            static std::ios_base::openmode _getValueFileOpenMode(
                    openMode_t mode);

        public:
            /**
             * Construct an attribute by its key and its value
             * @param key the key of the attribute
             * @param value the value of the attribute
             */
            Attribute(const std::string& key, const std::string& value);

            /**
             * Construct and attribute by a string with a attrName="attrValue"
             * pattern
             * @param str
             */
            explicit Attribute(std::string& str);

            std::string asString() const noexcept;

            /**
             * @return the key of the attribute
             */
            std::string getKey() const noexcept;

            /**
             * Set the key of the attribute
             * @param key the new key
             */
            void setKey(const std::string& key) noexcept;

            /**
             * @return the value of the attribute
             */
            std::string getValue() const noexcept;

            /**
             * Get the value of the attribute, casted as an int
             * @return the int attribute value
             * @throws IllegalValueException
             */
            int getValueInt() const;

            /**
             * Get the value of the attribute, casted as a float
             * @return the float attribute value
             * @throws IllegalValueException
             */
            float getValueFloat() const;


            /**
             * Get the value of the attribute, casted as a bool
             * @param trueElement [optional] the string representing the string value
             * of true, default is "true"
             * @param falseElement [optional] the string representing the string value
             * of false, default is "false"
             * @return the bool attribute value
             * @throws IllegalValueException
             */
            bool getValueBool(const std::string& trueElement = "true",
                              const std::string& falseElement = "false") const;

            /**
             * Build a new XML document with the filepath of the attribute value
             * @return the new XML doc
             */
            Doc getValueXmlDoc() const;

            /**
             * open a filestream with the filepath of the attribute value
             * @param mode the opening mode
             * @return the opened filestream
             * @throws FileException if the file cannot be opened
             */
            std::fstream getValueFile(openMode_t mode) const;

            /**
             * Set the value of the attribute
             * @param value the new value
             */
            void setValue(const std::string& value) noexcept;

            /**
             * Set the value of the attribute, casted as an int
             * @param the new int attribute value
             */
            void setValueInt(int value);

            /**
             * Set the value of the attribute, casted as an float
             * @param the new float attribute value
             */
            void setValueFloat(float value);

            /**
             * Get the value of the attribute, casted as a bool
             * @param value the new bool attribute value
             * @param trueElement [optional] the string representing the string value
             * of true, default is "true"
             * @param falseElement [optional] the string representing the string value
             * of false, default is "false"
             * @return the bool attribute value
             * @throws IllegalValueException
             */
            void setValueBool(bool value,
                              const std::string& trueElement = "true",
                              const std::string& falseElement = "false");
    };
}


#endif //MYXMLPP_ATTRIBUTE_HPP
