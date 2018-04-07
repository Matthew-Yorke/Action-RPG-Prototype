//***************************************************************************************************************************************************
//
// File Name: Sprite.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Sprite.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: BattleMap
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
Sprite::Sprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight)
{
   mpSpriteSheet = theGraphics.LoadImage(theFilePath);
   mSourceX = theSourceX;
   mSourceY = theSourceY;
   mWidth = theWidth;
   mHeight = theHeight;
   mAngle = 0.0F;
}

//***************************************************************************************************************************************************
//
// Method Name: ~Sprite
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
Sprite::~Sprite()
{
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
void Sprite::Draw(Graphics& theGraphics, int theDestinationX, int theDestinationY)
{
   theGraphics.Draw(mpSpriteSheet,
                    mSourceX,
                    mSourceY,
                    mWidth,
                    mHeight,
                    theDestinationX,
                    theDestinationY,
                    mAngle);
}

//***************************************************************************************************************************************************
// End Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Protected Method Definitions
//***************************************************************************************************************************************************

// Note: There are no protected methods in this class.

//***************************************************************************************************************************************************
// End Protected Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Private Method Definitions
//***************************************************************************************************************************************************

// Note: There are no private methods in this class.

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************