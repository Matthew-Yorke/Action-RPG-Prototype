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
//  Load the sprite bitmap with the passed in argument. Set member variables to their default values.
//
//***************************************************************************************************************************************************
Sprite::Sprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight)
{
   mpSpriteSheet = theGraphics.LoadImage(theFilePath);
   mSourceX = theSourceX;
   mSourceY = theSourceY;
   mWidth = theWidth;
   mHeight = theHeight;
}

//***************************************************************************************************************************************************
//
// Method Name: SetNewSprite
//
// Description:
//  Updates the X-Coordinate and Y-Coordinate on the sprite(sheet) bitmap where the sprite image is located at.
//
//***************************************************************************************************************************************************
void Sprite::SetNewSprite(int theSourceX, int theSourceY)
{
   mSourceX = theSourceX;
   mSourceY = theSourceY;
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  Draws the sprite image to the screen.
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
                    theDestinationY);
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