


#include "file_downloader.h"


int main(int, char**)
{
   std::string file_url = "https://www.allegro.cc/theme/default/image/logo.png";
   FileDownloader::FileHandle handle = FileDownloader::download_file(file_url, "logo.png");
   return 0;
}


