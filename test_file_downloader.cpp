



#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestFileDownloader
#include <boost/test/unit_test.hpp>




#include "file_downloader.h"




BOOST_AUTO_TEST_CASE(FileHandle_get_local_filename_returns_the_local_filename)
{
   FileDownloader::FileHandle handle("", "a_local_filename.htm");
   BOOST_CHECK_EQUAL("a_local_filename.htm", handle.get_local_filename());
}




BOOST_AUTO_TEST_CASE(FileHandle_get_file_url_returns_the_file_url)
{
   FileDownloader::FileHandle handle("http://www.fakeurl.com", "");
   BOOST_CHECK_EQUAL("http://www.fakeurl.com", handle.get_file_url());
}




BOOST_AUTO_TEST_CASE(FileDownloader_with_no_URL_will_return_an_error_status)
{
   FileDownloader::FileHandle handle = FileDownloader::download_file("", "");
   BOOST_CHECK_EQUAL(FileDownloader::ERROR, handle.get_status());
}




BOOST_AUTO_TEST_CASE(FileDownloader_with_no_URL_will_return_an_error_message)
{
   FileDownloader::FileHandle handle = FileDownloader::download_file("", "");
   BOOST_CHECK_EQUAL("URL using bad/illegal format or missing URL", handle.get_error());
}




