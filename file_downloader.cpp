



#include "file_downloader.h"

#include <curl/curl.h>




FileDownloader::FileHandle::FileHandle(std::string file_url, std::string local_filename)
   : id(last_id++)
   , status(NONE)
   , percentage(0.0)
   , file_url(file_url)
   , local_filename(local_filename)
   , error("")
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
   return status;
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

   CURL *curl = nullptr;
   FILE *file_pointer = nullptr;
   CURLcode res;
   curl = curl_easy_init();

   if (curl)
   {
      file_pointer = fopen(local_filename.c_str(), "wb");
      curl_easy_setopt(curl, CURLOPT_URL, file_url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, FileDownloader::write_data);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, file_pointer);
      res = curl_easy_perform(curl);
      /* always cleanup */
      curl_easy_cleanup(curl);
      fclose(file_pointer);
   }
   else
   {
      file_handle.status = ERROR;
   }

   return file_handle;
}




size_t FileDownloader::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
   size_t written = fwrite(ptr, size, nmemb, stream);
   return written;
}



int FileDownloader::FileHandle::last_id = -1;




