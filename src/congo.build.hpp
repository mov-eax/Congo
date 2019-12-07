#ifndef _CONGOB_H_
#define _CONGOB_H_ 1

#include "./congo.dependencies.hpp"

namespace congo {

    /*
    * @class build
    * This class is used to build documents for Mongo queries
    */
    class build {

        /*
        * @property|bsoncxx::builder::stream::document builder
        * The stream interface to build documents
        */
        bsoncxx::builder::stream::document builder = bsoncxx::builder::stream::document{};

        /*
        * @function reset
        * Reset the Congo build
        *
        * @returns build
        * Returns a pointer of the build object for chainable queries
        */
        build& reset() {
            this->builder.clear();
            return *this;
        }

        /*
        * @function key
        * Add a key and value to the document builder
        *
        * @argument|string key
        * The key to select from
        *
        * @argument|_value value
        * The dynamic templated value to assign to the key
        *
        * @returns build
        * Returns a pointer of the build object for chainable queries
        */
        template <typename _value>
        build& key(std::string key, _value value) {
            this->builder << key << value;
            return *this;
        }

        /*
        * @function array
        * Add a key and value to the document builder
        *
        * @argument|string key
        * The key to select from
        *
        * @argument|_values value
        * The dynamic templated values to assign to the key
        *
        * @returns build
        * Returns a pointer of the build object for chainable queries
        */
        template <typename _values>
        build& array(std::string key, std::vector<_values> values) {
            this->builder << key << bsoncxx::builder::stream::open_array <<

            [&](bsoncxx::builder::stream::array_context<> _array) {
                for (int i = 0; i < values.size(); i++) {
                    _array << values[i];
                }
            }

            << bsoncxx::builder::stream::close_array;

            return *this;
        }

        /*
        * @function key
        * Add a key and value to the document builder
        *
        * @argument|string key
        * The key to select from
        *
        * @argument|map<string, _values> values
        * The dynamic templated values to assign to the key in a map with a string.
        *
        * @returns build
        * Returns a pointer of the build object for chainable queries
        */
        template <typename _values>
        build& object(std::string key, std::map<std::string, _values> values) {
            this->builder << key << bsoncxx::builder::stream::open_document;

            for (auto const &value : values) {
                builder << value.first << value.second;
            }

            this->builder << bsoncxx::builder::stream::close_document;

            return *this;
        }

        /*
        * @function build
        * Build the current document
        *
        * @returns bsoncxx::document::value
        * Returns a bson document that can be used for the database
        */
        bsoncxx::document::value build() {
            bsoncxx::document::value document = this->builder << bsoncxx::builder::stream::finalize;
            return document;
        }

    }

}

#endif
