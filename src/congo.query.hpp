#ifndef _CONGOQ_H_
#define _CONGOQ_H_ 1

#include "./congo.dependencies.hpp"
#include "./congo.build.hpp"

namespace congo {

    /*
    * @class query
    * This class is used to query the database from documents built with Congo
    */
    class query {

        /*
        * @property|mongocxx::pool::entry poolInstance
        * A single thread in a pool to build documents
        */
        mongocxx::pool::entry poolInstance;

        /*
        * @property|mongocxx::collection client
        * The collection to query from
        */
        mongocxx::collection client;

        /*
        * @property|congo::build builder
        * The congo query builder tool
        */
        congo::build builder;

        /*
        * @function init
        * Initialize a Congo query
        *
        * @argument|string collection
        * The collection to query
        *
        * @returns query
        * Returns a pointer of the query object for chainable queries
        */
        query& init(std::string collection) {
            this->poolInstance = config::pool.acquire();
            this->client = (*poolInstance)[config::db][collection];
            return *this;
        }

    }

}

#endif
