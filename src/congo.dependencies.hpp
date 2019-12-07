#ifndef _CONGOD_H_
#define _CONGOD_H_ 1

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/array_context.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>
#include <bsoncxx/stdx/make_unique.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/stdx/string_view.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/options/find.hpp>
#include <mongocxx/uri.hpp>

#include <string>
#include <vector>
#include <map>

namespace congo {
    namespace config {

        /*
        * @mongocxx::instance MongoInstance
        * The MongoDB instance
        */
        mongocxx::instance MongoInstance{};

        /*
        * @mongocxx::uri uri
        * The Mongo URI to the database
        * The default is on localhost
        */
        mongocxx::uri uri = "mongodb://localhost:27017";

        /*
        * @mongocxx::pool pool
        * The Mongo thread pool
        * You pass the uri to the pool
        */
        mongocxx::pool pool{config::uri};

        /*
        * @string db
        * The database to use
        * The default database is "congo"
        */
        std::string db = "congo";

    }
}

#endif
