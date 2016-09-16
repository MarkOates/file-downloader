



#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestFileDownloader
#include <boost/test/unit_test.hpp>




#include "file_downloader.h"




BOOST_AUTO_TEST_CASE(FileHandle_get_local_filename_returns_the_local_filename)
{
   FileDownloader::FileHandle handle("", "a_local_filename.htm");
   BOOST_CHECK_EQUAL("a_local_filename.htm", handle.get_local_filename());
}




