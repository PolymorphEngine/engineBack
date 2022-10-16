/*
** EPITECH PROJECT, 2020
** Node.hpp.h
** File description:
** header for Node.c
*/

#ifndef MYXMLPP_NODE_HPP
#define MYXMLPP_NODE_HPP

#include <string>
#include <vector>
#include <Attribute.hpp>
#include <memory>
#include <regex>

namespace myxmlpp {
    /**
     * Core class that represent a XML node with tag, attributes, children...
     */
    class Node {
        private:
            /**
             * Tag of the XML node
             */
            std::string _tag;

            /**
             * Everything inside the node if it is not a child node
             */
            std::string _data;

            /**
             * A reference to the parent node
             */
            Node *_parent;

            /**
             * List of attributes present in the node
             */
            std::vector<std::shared_ptr<Attribute>> _attributes;

            /**
             * List of child nodes
             */
            std::vector<std::shared_ptr<Node>> _children;

            std::shared_ptr<myxmlpp::Node>
            _findChildRecursive(const std::string &tag, int depth) const;

            void _findChildrenRecursive(std::vector<std::shared_ptr<Node>> *children,
                                        const std::string &tag,
                                        int depth) const;

            static std::vector<std::string> _split(const std::string &str,
                                                   char delimiter);

            static std::shared_ptr<Node>
            _searchChild(const Node *current,
                         const std::vector<std::string>& tab,
                         std::vector<std::string>::iterator it);

            std::vector<std::shared_ptr<Node>>::iterator
            _findChildIt(const std::string &tag);

            std::shared_ptr<Node> _popChildRecursive(const std::string &tag,
                                                     int depth);

            std::vector<std::vector<std::shared_ptr<Node>>::iterator>
                    _findChildrenIt(const std::string &tag);

            void _popChildrenRecurs(std::vector<std::shared_ptr<Node>> &children,
                                    const std::string &tag,
                                    int depth);

            void _extractAttributes(std::string &str) noexcept;

            static bool _isEndOfNode(std::string &str);

            void _checkEndOfNode(std::string &str,
                                 std::string &remaining);

            /**
             * Private constructor to create a node by parsing a xml file in string format.
             * @param str the source string.
             * @param remaining the remaining characters that could not be parsed
             */
            explicit Node(Node *parent, std::string& str, std::string &remaining);

            void _parseNodeString(std::string &str, std::string &remaining);

            static bool _performRegex(std::smatch &matches,
                                      std::string &regexStr,
                                      std::string &str,
                                      std::string *remaining = nullptr);
            /**
             * @details This method build a string which contains the necessary
             * indent to format a node in a file during writing
             * @param indent the number of tab to return
             * @return the indentation helper string
             */
            static std::string  _strIndent(std::size_t indent);

            /**
             * @details This method will return all the attributes serialized
             * in a minimized way (no necessary spaces between attributes)
             * @return the serialized attributes
             */
            std::string _dumpAttrs() const noexcept;

            /**
             * @details This method will return all the attributes serialized
             * with correct spacing formatting
             * @return the serialized attributes
             */
            std::string _dumpAttrsF() const noexcept;

        public:
            /**
             * Method to create a node with its tag.
             * @param parent parent of the node.
             * Can be set to null if the node has not parent
             * @param tag the tag of the node.
             * @return the created node.
             */
            explicit Node(Node *parent) noexcept;

            /**
             * Method to create a node with its tag and its children.
             * @param parent parent of the node.
             * Can be set to null if the node has not parent
             * @param tag the tag of the node.
             * @param children a vector with the children nodes.
             * @return the created node.
             */
            Node(Node *parent, std::string tag,
                 std::vector<std::shared_ptr<Node>> children) noexcept;

            /**
             * Method to create a node with its tag, children and attributes.
             * @param parent parent of the node.
             * Can be set to null if the node has not parent
             * @param tag the tag of the node.
             * @param attributes a vector of attributes for the node.
             * @param children a vector of the children nodes.
             * @return the created node.
             */
            Node(Node *parent, std::string tag,
                 std::vector<std::shared_ptr<Attribute>> attributes,
                 std::vector<std::shared_ptr<Node>> children = {}) noexcept;

            /**
             * Method to create a node by parsing a xml file in string format.
             * @param str the source string.
             * @return the created node.
             * @throws ParsingException if parsing fails.
             */
            explicit Node(Node *parent, std::string& str);

            /**
             * @details This method will return the serialized node minimized
             * @return the serialized node
             */
            std::string asString(bool includeChildren = true) const noexcept;

            /**
             * @details This method will return the serialized node with
             * indentation formatting
             *
             * @return the serialized node
             */
            std::string asFString(size_t indent,
                                  bool includeChildren = true) const noexcept;

            /**
             * @return the tag of the XML node
             */
            std::string getTag() const noexcept;

            /**
             * @return the data of the xml node
             */
            std::string getData() const noexcept;

            /**
             * @returns a pointer to the XML parent node
             */
            Node *getParent() const noexcept;

            /**
             * A method to change the tag of the XML node
             * @param tag the new tag
             */
            void setTag(const std::string& tag) noexcept;

            /**
             * A method to change the data of the XML node
             * @param tag the new data
             */
            void setData(const std::string& data) noexcept;

            /**
             * A method to change the parent of the XML node
             * @param tag the new parent
             */
            void setParent(Node *parent) noexcept;

            /**
             * Method to find an attribute by its name.
             * @param key key of the searched attribute
             * @return the found attribute
             * @throws AttributeNotFoundException if the attribute is not found
             */
            std::shared_ptr<Attribute>
            findAttribute(const std::string& key) const;

            /**
             * Method to add an attribute to a node by passing a pointer
             * @param attr pointer to the created attribute
             */
            void addAttribute(const std::shared_ptr<Attribute>& attr) noexcept;

            /**
             * Method to add an attribute to a node,
             * this will dynamically allocate an attribute
             * @param key the key of the attribute
             * @param value the value of the attribute
             */
            std::shared_ptr<Attribute>
            addAttribute(const std::string& key,
                         const std::string& value) noexcept;

            /**
             * Remove from the attributes list and delete the attribute object
             * @param key key of the attribute to delete
             */
            void rmAttribute(const std::string& key) noexcept;

            /**
             * Only remove the object from the attributes list
             * @param key key of the attribute to pop
             */
            std::shared_ptr<Attribute>
            popAttribute(const std::string& key);

            using NodeIterator = std::vector<std::shared_ptr<Node>>::iterator;
            /**
             * @details Treat a node as an iterator to his children (begin)
             * @returns First iterator of children
             */
            NodeIterator begin() noexcept
            {
                return _children.begin();
            }

            NodeIterator end() noexcept
            {
                return _children.end();
            }

            /**
             * Method to find a child node by its tag.
             * This method will return the first matched node
             * @param tag tag of the child to find
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::shared_ptr<Node> findChild(const std::string& tag) const;

            /**
             * Method to find a child node by searching recursively,
             * a max depth can be set. This method will return the first
             * matched node
             * @param tag tag of the node to find
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::shared_ptr<Node>
            findChildR(const std::string& tag, int maxDepth=-1) const;

            /**
             * Method to find a child node by a given path. The path is name
             * tags separated by a slash. This method will return the first
             * matched node
             * @param path the path relative to the current node
             * @param tag tag of the node to find
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::shared_ptr<Node> findChildByPath(const std::string& path,
                                                  const std::string& tag,
                                                  char delimiter='/') const;

            /**
             * Method to find a child node by a given path. The path is name
             * tags separated by a slash. The last tag name if the tag of
             * the node to find This method will return the first matched node
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::shared_ptr<Node>
            findChildBySPath(const std::string& path,
                             char delimiter='/') const;

            /**
             * Method to find all children which have the provided tag
             * @param tag tag of the nodes to find
             * @return tag list of all found nodes
             * @throws NodeNotFoundException when a node is not found
             */
            std::vector<std::shared_ptr<Node>>
            findChildren(const std::string& tag) const;

            /**
             * Method to find all children which have the provided tag. The
             * difference is that this method fills a provided vector instead
             * of returning a created one
             * @param tag tag of the nodes to find
             * @param node list of all found nodes
             * @throws NodeNotFoundException when a node is not found
             */
            void findChildren(const std::string& tag,
                              std::vector<std::shared_ptr<Node>> *children) const;

            /**
             * Method to find all children nodes with the same tag by searching
             * recursively, a max depth can be set
             * @param tag tag of the nodes to find
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::vector<std::shared_ptr<Node>>
            findChildrenR(const std::string& tag, int maxDepth=-1) const;

            /**
             * Method to find all children nodes by a given path. The path is
             * name tags separated by a slash by default if there no specified
             * separator
             * @param path the path relative to the current node
             * @param tag tag of the node to find
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::vector<std::shared_ptr<Node>> findChildrenByPath(
                    const std::string& path,
                    const std::string& tag,
                    char delimiter='/') const;

            /**
             * Method to find all children nodes by a given path. The path is
             * name tags separated by a slash by default if there no specified
             * separator
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             * @throws NodeNotFoundException when a node is not found
             */
            std::vector<std::shared_ptr<Node>>
            findChildrenBySPath(const std::string& path,
                                char delimiter='/') const;

            /**
             * Method to add a Node to the children list
             * @param child the Node to add
             */
            void addChild(const std::shared_ptr<Node>& child) noexcept;

            /**
             * Method to add children nodes to the children list.
             * @param children a vector of nodes to add
             */
            void addChildren(
                    const std::vector<std::shared_ptr<Node>> &children)
                noexcept;

            /**
             * Method to add a child to a node referenced by its given path.
             * The path is name tags separated by a slash by default if there
             * no specified separator
             * @param child a Node pointer to the child to add
             * @param path the path relative to the future parent node
             * @param delimiter the separator used in path to delimit nodes
             * @throws NodeNotFoundException when a node is not found
             */
            void addChildByPath(const std::shared_ptr<Node>& child, const std::string& path,
                                char delimiter='/');

            /**
             * Method to add children to a node referenced by its given path.
             * The path is name tags separated by a slash by default if there
             * no specified separator
             * @param children a vector of Node pointers to the children to add
             * @param path the path relative to the future parent node
             * @param delimiter the separator used in path to delimit nodes
             * @throws NodeNotFoundException when a node is not found
             */
            void addChildrenByPath(const std::vector<std::shared_ptr<Node>> &children,
                                   const std::string &path,
                                   char delimiter='/');

            /**
             * Remove from the children list and delete the matching node
             * object. This method will remove the first matched node
             * @param tag tag of the node to remove
             */
            void rmChild(const std::string& tag) noexcept;

            /**
             * Method to remove a node by searching recursively, a max depth
             * can be set. This method will remove the first matched node
             * @param tag tag of the node to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             */
            void rmChildR(const std::string& tag, int maxDepth=-1) noexcept;

            /**
             * Remove a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * remove the first matched node.
             * This method is equivalent to findChildByPath and then rmChild
             * @param path the path relative to the current node
             * @param tag tag of the node to remove
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildByPath(const std::string& path,
                               const std::string& tag,
                               char delimiter='/') noexcept;

            /**
             * Remove a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * remove the first matched node.
             * This method is equivalent to findChildByPath and then rmChild
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildBySPath(const std::string& path,
                                char delimiter='/') noexcept;

            /**
             * Method to remove all children which have the provided tag
             * @param tag tag of the nodes to remove
             */
            void rmChildren(const std::string& tag) noexcept;

            /**
             * Method to remove all children nodes with the same tag by
             * searching recursively, a max depth can be set
             * @param tag tag of the nodes to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             */
            void rmChildrenR(const std::string& tag, int maxDepth=-1) noexcept;

            /**
             * Method to find remove children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param tag tag of the node to remove
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildrenByPath(const std::string& path,
                                  const std::string& tag,
                                  char delimiter='/') noexcept;

            /**
             * Method to find remove children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildrenBySPath(const std::string& path,
                                   char delimiter='/') noexcept;

            /**
            * Method to only remove the object from the children list.
            * This method will pop the first matched node.
            * @param key tag of the node to pop
            * @return the popped node or a null pointer if node is not found
            */
            std::shared_ptr<Node> popChild(const std::string& tag) noexcept;

            /**
             * Method to pop a node by searching recursively, a max depth
             * can be set. This method will pop the first matched node.
             * @param tag tag of the node to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return the popped node or a null pointer if node is not found
             */
            std::shared_ptr<Node>
            popChildR(const std::string& tag, int maxDepth=-1) noexcept;

            /**
             * Pop a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * pop the first matched node. This method is equivalent to
             * findChildByPath and then popChild.
             * @param path the path relative to the current node
             * @param tag tag of the node to pop
             * @param delimiter the separator used in path to delimit nodes
             * @return the popped node or a null pointer if node is not found
             */
            std::shared_ptr<Node> popChildByPath(const std::string& path,
                                 const std::string& tag,
                                 char delimiter='/') noexcept;

            /**
            * Pop a node from the children list of a child node.
            * The path is name tags separated by a slash. This method will
            * pop the first matched node. This method is equivalent to
            * findChildByPath and then popChild.
            * @param path the path relative to the current node
            * @param delimiter the separator used in path to delimit nodes
            * @return the popped node or a null pointer if node is not found
            */
            std::shared_ptr<Node> popChildBySPath(const std::string& path,
                                                  char delimiter='/') noexcept;

            /**
             * Method to pop all children which have the provided tag
             * @param tag tag of the nodes to pop
             * @return a list of the popped nodes or an empty list
             * if no node is found
             */
            std::vector<std::shared_ptr<Node>>
            popChildren(const std::string& tag) noexcept;

            /**
             * Method to pop all children nodes with the same tag by
             * searching recursively, a max depth can be set
             * @param tag tag of the nodes to pop
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return a list of the popped nodes or an empty list
             * if no node is found
             */
            std::vector<std::shared_ptr<Node>>
            popChildrenR(const std::string& tag, int maxDepth=-1) noexcept;

            /**
             * Method to find pop children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param tag tag of the node to pop
             * @param delimiter the separator used in path to delimit nodes
             * @return a list of the popped nodes or an empty list
             * if no node is found
             */
            std::vector<std::shared_ptr<Node>>
            popChildrenByPath(const std::string& path,
                              const std::string& tag,
                              char delimiter='/') noexcept;

            /**
             * Method to find pop children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             * @return a list of the popped nodes or an empty list
             * if no node is found
             */
            std::vector<std::shared_ptr<Node>>
            popChildrenBySPath(const std::string& path,
                               char delimiter='/') noexcept;

            /**
             * Count the number of children of the node, only one level
             * @return the number of children of the node
             */
            unsigned int getNbChildren() const noexcept;

            /**
             * Count the number of children of the node, at all levels
             * @return the number of children of the node and all sub nodes
             */
            unsigned int getNbChildrenR() const noexcept;

            /**
             * Count the number of attributes of the node, only one level
             * @return the number of attributes of the node
             */
            unsigned int getNbAttributes() const noexcept;

            /**
             * Count the number of attributes of the node, at all levels
             * @return the number of attributes of the node and all sub nodes
             */
            unsigned int getNbAttributesR() const noexcept;

            /**
             * Check if the node has children
             * @return true if there is no child
             */
            bool empty() const noexcept;

            /**
             * Check if the node has attributes
             * @return true if there is no attributes
             */
            bool noAttributes() const noexcept;

            /**
             * Combination of empty and noAttributes method
             * @return true if there is no child and no attribute
             */
            bool allEmpty() const noexcept;

            /**
             * Move the current node as a child of the provided node
             * @param newParent the future parent node
             */
            void move(Node &newParent) noexcept;
    };
}

#endif //MYXMLPP_NODE_HPP
