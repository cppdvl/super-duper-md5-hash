//
// Created by root on 11/4/20.
//

#ifndef GMD5_GMD5HASH_H
#define GMD5_GMD5HASH_H

#include <string>

namespace GMD5HASH { //Guarin Implementation of MD5.

    class HashFile:public std::string {
        unsigned long mFileSize;
        static unsigned long get_size_by_fd(int fd);
        void format_hash(unsigned char* md);
    public:
        HashFile(std::string pathname);
        const unsigned long& FileSize();
    };


}

#endif //GMD5_GMD5HASH_H
