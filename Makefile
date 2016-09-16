



file_downloader:
	g++ -Wall ex_file_downloader.cpp file_downloader.cpp -o ex_file_downloader -lcurl
	g++ -Wall test_file_downloader.cpp -o test_file_downloader -lboost_unit_test_framework




