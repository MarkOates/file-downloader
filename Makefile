



file_downloader:
	g++ -Wall ex_file_downloader.cpp file_downloader.cpp -o ex_file_downloader -lcurl
	g++ -Wall file_downloader.cpp test_file_downloader.cpp -o test_file_downloader -lcurl -lboost_unit_test_framework




