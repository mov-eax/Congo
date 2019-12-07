#ifndef _CONGO_H_
#define _CONGO_H_ 1

#include "./congo.dependencies.hpp"
#include "./congo.query.hpp"

namespace congo {

    /*
    * @function init
    * Initializes the Congo query object
    *
    * @argument|string _uri
    * The uri to connect to
    *
    * @argument|string _db
    * The db to connect to
    *
    * @returns bool
    * The value to return
    */
    bool init(std::string _uri, std::string _db) {
        try {
            config::uri = mongocxx::uri(_uri);
            config::db = _db;

            return true;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return false;
        }
    }

}

#endif
