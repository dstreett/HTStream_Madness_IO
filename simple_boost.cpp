#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include <vector>
#include <fstream>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <map>
#include <unordered_map>
#include <boost/functional/hash.hpp>
#include <unistd.h>

namespace bi = boost::iostreams;
namespace bf = boost::filesystem;

int check_open_r(const std::string &fname) {
    FILE *f = NULL;
    f = popen( (fname).c_str() , "r");
    std::cout << fileno(f) << '\n';
    return fileno(f);
}

int main(int argc, char** argv)
{
    std::vector<std::string> s = {"ls", "ls"}; 
    for(size_t i = 0; i < s.size(); ++i) {
        FILE *f = NULL;
        f = popen( (s[i]).c_str() , "r");
        int fd_1 = fileno(f);
        bi::stream<bi::file_descriptor_source> is1{fd_1, bi::close_handle};
        for(std::string str; std::getline(is1, str); ) {
            std::cout << "Processed line " << str << '\n';
        }
        is1.close();
        close(fd_1);
        //pclose(f);
    }
}
