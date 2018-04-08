//***************************************************************************************************************************************************
//
// File Name: Graphics.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#include "AnimatedSprite.h"
#include "Game.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: AnimatedSprite
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
AnimatedSprite::AnimatedSprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight,
                               float theFps, int theNumberFrames) :
   Sprite(theGraphics, theFilePath, theSourceX, theSourceY, theWidth, theHeight),
   mFrameTime(1 / theFps),
   mNumberFrames(theNumberFrames),
   mCurrentFrame(0),
   mElapsedTime(0)
{
}

//***************************************************************************************************************************************************
//
// Method Name: ~AnimatedSprite
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
AnimatedSprite::~AnimatedSprite()
{
}

//************************************************************************************************************************************************
//
// Method Name: SetNewAnimation
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void AnimatedSprite::SetNewAnimation(int theSourceX, int theSourceY, int theNumberFrames)
{
   SetNewSprite(theSourceX, theSourceY);
   mNumberFrames = theNumberFrames;
   mCurrentFrame = 0;
}

//***************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
void AnimatedSprite::Update(float theElapsedTime)
{
   mElapsedTime += theElapsedTime;

   if (mElapsedTime > mFrameTime)
   {
      mCurrentFrame++;
      mElapsedTime = 0;

      if (mCurrentFrame < mNumberFrames)
      {
         mSourceX += mWidth;
      }
      else
      {
         mSourceX -= mWidth * (mNumberFrames - 1);
         mCurrentFrame = 0;
      }
   }
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