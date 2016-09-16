


#include "file_downloader.h"

#include <iostream>


int main(int, char**)
{
   std::string file_url = "https://www.allegro.cc/theme/default/image/logo.png";
   FileDownloader::FileHandle handle = FileDownloader::download_file(file_url, "logo.png");

   if (handle.get_status() == FileDownloader::DOWNLOADED)
      std::cout << "File Downloaded Successfully!" << std::endl;
   else
      std::cout << "Download Error: " << handle.get_error() << std::endl;

   return 0;
}


