// Indoor-Positioning-System.cpp : Defines the entry point for the application.
//

#include "Indoor-Positioning-System.h"
#include <iostream> // Add this include for std::cout and std::endl
#include <vector>   // Ensure this include is present for std::vector
#include <cstddef>  // Add this include for std::size_t

using namespace std;

class BeaconInput
{
	double range;
	double name;
	double beacon_id;
};

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
public:
	GetUserPosition(const std::vector<BeaconInput>& beacons) : beaconInputs(beacons) {
		UserPosition userPosition(25.22, 20.88);
	}

private:
	std::vector<BeaconInput> beaconInputs;
};

int main()
{
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
