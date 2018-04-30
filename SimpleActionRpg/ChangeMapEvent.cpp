//***************************************************************************************************************************************************
//
// File Name: ChangeMapEvent.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "ChangeMapEvent.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: ChangeMapEvent
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
ChangeMapEvent::ChangeMapEvent(int theCoordinateX, int theCoordianteY, int theWidth, int theHeight, std::string theMapFileLocation, int thePlayerCoordinateX, int thePlayerCoordinateY) :
Event(theCoordinateX, theCoordianteY, theWidth, theHeight)
{
   mMapFileLocation = theMapFileLocation;
   mPlayerCoordinateX = thePlayerCoordinateX;
   mPlayerCoordinateY = thePlayerCoordinateY;
}

//************************************************************************************************************************************************
//
// Method Name: ~ChangeMapEvent
//
// Description:
//  TODO: Add description/A
//
//************************************************************************************************************************************************
ChangeMapEvent::~ChangeMapEvent()
{
}

//************************************************************************************************************************************************
//
// Method Name: GetPlayerCoordinateX
//
// Description:
//  TODO: Add description/A
//
//************************************************************************************************************************************************
int ChangeMapEvent::GetPlayerCoordinateX()
{
   return mPlayerCoordinateX;
}

//************************************************************************************************************************************************
//
// Method Name: GetPlayerCoordinateY
//
// Description:
//  TODO: Add description/A
//
//************************************************************************************************************************************************
int ChangeMapEvent::GetPlayerCoordinateY()
{
   return mPlayerCoordinateY;
}

//************************************************************************************************************************************************
//
// Method Name: Execute()
//
// Description:
//  TODO: Add description/A
//
//************************************************************************************************************************************************
Map* ChangeMapEvent::Execute()
{
   return new Map(mMapFileLocation);
}


//***************************************************************************************************************************************************
// End Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Protected Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Protected Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Private Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************