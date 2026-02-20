// Indoor-Positioning-System.cpp : Defines the entry point for the application.
//

#include "Indoor-Positioning-System.h"
#include <iostream> // Add this include for std::cout and std::endl
#include <vector>   // Ensure this include is present for std::vector
#include <cstddef>  // Add this include for std::size_t
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class BeaconInput
{
public:
	double range;
	std::string name;
	std::string beacon_id;
};

class Beacon {
public:
	std::string name;
	std::string beacon_id;
	double latitude;
	double longitude;
};

class PathwayPoint {
public:
	double latitude;
	double longitude;
};

class Point {
	double x, y;
};

std::vector<Beacon> beacons;
std::vector<PathwayPoint> PathwayPoints;
class UserPosition
{
public:
	UserPosition(double lat, double lon) {
		this->latitude = lat;
		this->longitude = lon;
	}
	double latitude;
	double longitude;

};

// Corrected class definition to use std::vector<BeaconInput>
class GetUserPosition
{
private:
	Beacon GetBeaconById(string beaconId)  {
		for (Beacon beacon : beacons) {
			if (beacon.beacon_id == beaconId) {
				return beacon;
			}
		}
	}
private:
	PathwayPoint GetClosestPathwayPointsInsideBuffer() {

	}
private:
	vector<double,double> TriangulatedPolygon(vector<Beacon> closestBeacons) {
		
	}
public:
	UserPosition GetPosition(vector<BeaconInput> beaconInputs ) {
		vector<Beacon> closestBeacons;
		Beacon closestBeacon;
		double closestRange = 9999999.0;
		for (BeaconInput beaconInput : beaconInputs) {
			Beacon inputBeacon = GetBeaconById(beaconInput.beacon_id);
		}

		
		UserPosition userPosition(25.22, 20.88); 
		return userPosition;
	}


};

int main()
{
	std::cout << "Hello CMake." << std::endl;

	// Reading Beacons csv file
	std::ifstream beaconsFile("Beacons.csv");
	std::string beaconsLine;

	if(!beaconsFile .is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}
	int isFirstLine = 1;
	while (std::getline(beaconsFile, beaconsLine)) {
		if (isFirstLine == 0) {
			std::istringstream ss(beaconsLine);
			std::string ss_str = ss.str();

			Beacon beacon;

			std::string latStr, lonStr;

			std::getline(ss, lonStr, ',');
			std::getline(ss, latStr, ',');
			std::getline(ss, beacon.name, ',');
			std::getline(ss, beacon.beacon_id, ',');


			beacon.latitude = std::stod(latStr);
			beacon.longitude = std::stod(lonStr);

			beacons.push_back(beacon);
		}
		isFirstLine = 0;
	}
	for (Beacon beacon : beacons) {
		std::cout << "Beacon Name: " << beacon.name << ", Beacon ID: " << beacon.beacon_id
			<< ", Latitude: " << beacon.latitude << ", Longitude: " << beacon.longitude << std::endl;
	}

	std::ifstream pathwaysFile("PathwayPoints.csv");
	std::string pathwaysLine;

	if(!pathwaysFile .is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}
	int isFirstPathwayLine = 1;
	while (std::getline(pathwaysFile, pathwaysLine)) {
		if (isFirstPathwayLine == 0) {
			std::istringstream ss(pathwaysLine);
			std::string ss_str = ss.str();

			PathwayPoint pathwayPoint;

			std::string sNo, latStr, lonStr;

			std::getline(ss, sNo, ',');
			std::getline(ss, lonStr, ',');
			std::getline(ss, latStr, ',');

			std::cout << lonStr << std::endl;
			pathwayPoint.latitude = std::stod(latStr);
			pathwayPoint.longitude = std::stod(lonStr);

			PathwayPoints.push_back(pathwayPoint);
		}
		isFirstPathwayLine = 0;
	}
	for (PathwayPoint pathwayPoint : PathwayPoints) {
		std::cout << "Latitude: " << std::to_string(pathwayPoint.latitude)	 << ", Longitude: " << std::to_string(pathwayPoint.longitude) << std::endl;
	}
	return 0;
}
