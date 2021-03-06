#pragma once

#include <iostream>
#include <boost/shared_ptr.hpp>
#include "jml/arch/exception.h"
#include <map>

namespace Datacratic{

/**
 * KvpLogger are key-value-pair loggers
 */
class IKvpLogger{
    public:
        struct KvpLoggerParams{
            std::string hostAndPort;//format host:port
            std::string db;
            std::string user;
            std::string pwd;
            bool failSafe;//if true, all errors are catched but printed to cerr
        };

        /**
         * Factory like getter for kvp
         */
        static std::shared_ptr<IKvpLogger>
            getKvpLogger(const std::string& type, const KvpLoggerParams&);

        virtual void log(const std::map<std::string, std::string>&, const std::string&) = 0;
        virtual ~IKvpLogger(){};
};


}//namespace Datacratic
