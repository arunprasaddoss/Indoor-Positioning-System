#include <cstddef>
// Indoor-Positioning-System.h : Include file for standard system include files,
// or project specific include files.

#ifndef INDOOR_POSITIONING_SYSTEM_H
#define INDOOR_POSITIONING_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif


// C representation of a beacon (plain-old-data)
typedef struct CIP_BeaconInput {
    double range;
    double name;
    double beacon_id;
} CIP_BeaconInput;

// C representation of a user position (plain-old-data)
typedef struct CIP_UserPosition {
    double latitude;
    double longitude;
} CIP_UserPosition;

// Opaque handle for the C wrapper around the C++ GetUserPosition object
typedef struct CIP_GetUserPosition CIP_GetUserPosition;

// Create/destroy the GetUserPosition wrapper
CIP_GetUserPosition* cip_gup_create(const CIP_BeaconInput* beacons);
void cip_gup_destroy(CIP_GetUserPosition* handle);

// Compute/obtain the user position from the wrapper
CIP_UserPosition cip_gup_compute(const CIP_GetUserPosition* handle);

#ifdef __cplusplus
}
#endif

#endif // INDOOR_POSITIONING_SYSTEM_H
