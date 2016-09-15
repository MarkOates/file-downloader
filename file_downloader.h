#ifndef __ALLEGRO_FLARE_FILE_DOWNLOADER
#define __ALLEGRO_FLARE_FILE_DOWNLOADER




#include <vector>
#include <string>




class FileDownloader
{
private:
   static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
   static int progress_function(void *ptr,
         double download_total, double download_now,
         double upload_total, double upload_now
         );

public:
   enum download_status_t
   {
      NONE,
      DOWNLOADING,
      DOWNLOADED,
      ERROR
   };

   class FileHandle
   {
   friend class FileDownloader;

   private:
      static int last_id;
      int id;
      download_status_t status;
      float download_size;
      float percentage;
      std::string file_url;
      std::string local_filename;
      std::string error;

   public:
      FileHandle(std::string file_url, std::string local_filename);
      ~FileHandle();

      float get_download_size();
      float get_percentage();
      download_status_t get_status();
      std::string get_local_filename();
      bool erase_downloaded_file();
      std::string get_error();
   };

   static std::vector<FileHandle> download_history;

   static int num_downloading_files();
   static bool clear_all_downloaded_files();
   static bool clear_history();
   static FileHandle download_file(std::string file_url, std::string local_filename);
};




#endif
