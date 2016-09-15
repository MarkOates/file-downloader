



#include "file_downloader.h"

#include <curl/curl.h>




FileDownloader::FileHandle::FileHandle(std::string file_url, std::string local_filename)
{
}




FileDownloader::FileHandle::~FileHandle()
{
}




float FileDownloader::FileHandle::get_percentage()
{
   return -1.0;
}




FileDownloader::download_status_t FileDownloader::FileHandle::get_status()
{
   return NONE;
}




std::string FileDownloader::FileHandle::get_local_filename()
{
   return local_filename;
}




bool FileDownloader::FileHandle::erase_downloaded_file()
{
   return false;
}




std::string FileDownloader::FileHandle::get_error()
{
   return "";
}




int FileDownloader::num_downloading_files()
{
   return -1;
}




bool FileDownloader::clear_all_downloaded_files()
{
   return false;
}




bool FileDownloader::clear_history()
{
   return false;
}




FileDownloader::FileHandle FileDownloader::download_file(std::string file_url, std::string local_filename)
{
   FileHandle file_handle(file_url, local_filename);
   return file_handle;
}




