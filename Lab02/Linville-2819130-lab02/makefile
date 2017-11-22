DrivingRecords: main.o Executive.o DriversLicenseRecord.o
	g++ -std=c++11 -g -Wall main.o Executive.o DriversLicenseRecord.o -o DrivingRecords

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp DriversLicenseRecord.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

DriversLicenseRecord.o: DriversLicenseRecord.h DriversLicenseRecord.cpp
	g++ -std=c++11 -g -Wall -c DriversLicenseRecord.cpp

clean:
	rm *.o DrivingRecords
