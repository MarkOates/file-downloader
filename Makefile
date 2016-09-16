



file_downloader:
	g++ -Wall main.cpp file_downloader.cpp -o main -lcurl
	g++ -Wall test_file_downloader.cpp -o test_file_downloader -lboost_unit_test_framework




