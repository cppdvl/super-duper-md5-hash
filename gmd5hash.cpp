#include <sys/stat.h>

#ifdef _WIN64 || _WIN32
#include <mman.h>
#else
#include <sys/mman.h>
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <string>
#include <openssl/md5.h>
#include <iomanip>
#include <iostream>

#include "gmd5hash.h"


        unsigned long GMD5HASH::HashFile::get_size_by_fd(int fd) {
            struct stat statbuf;
            if(fstat(fd, &statbuf) < 0) exit(-1);
            return statbuf.st_size;
        }
        void GMD5HASH::HashFile::format_hash(unsigned char* md){
            for (auto i = 0; i < MD5_DIGEST_LENGTH; ++i){
                std::stringstream buff;
                buff << std::setfill('0') << std::setw(2) << std::hex << (unsigned int) md[i];
                *this += buff.str();
            }
        }
        GMD5HASH::HashFile::HashFile(std::string pathname){
            unsigned char result[MD5_DIGEST_LENGTH];
            int file_descript;
            char* file_buffer;

            file_descript = open(pathname.c_str(), O_RDONLY);
            if(file_descript < 0) exit(-1);
            mFileSize = GMD5HASH::HashFile::get_size_by_fd(file_descript);

            file_buffer = reinterpret_cast<char*>(mmap(0, mFileSize, PROT_READ, MAP_SHARED, file_descript, 0));
            MD5((unsigned char*) file_buffer, mFileSize, result);
            munmap(file_buffer, mFileSize);
            this->format_hash(result);

        }
        const unsigned long& GMD5HASH::HashFile::FileSize(){
            return mFileSize;
        }


