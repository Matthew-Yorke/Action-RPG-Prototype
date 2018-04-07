//***************************************************************************************************************************************************
//
// File Name: PlayerCharacter.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "stdio.h"
#include "PlayerCharacter.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: PlayerCharacter
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
PlayerCharacter::PlayerCharacter(Graphics& theGraphics)
{
   mCurrentHealth = mMaxHealth = 10;
   mCurrentMana = mMaxMana = 5;
   mCoordinateX = 0.0F;
   mCoordinateY = 0.0F;
   mpVelocity = new Vector2D(0.0F,
                             0.0F);
   mpSprite = new Sprite(theGraphics,
                         "../Images/TestSprite.png",
                         0,
                         0,
                         32,
                         32);
}

//***************************************************************************************************************************************************
//
// Method Name: ~PlayerCharacter
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
PlayerCharacter::~PlayerCharacter()
{
   delete mpVelocity;
   delete mpSprite;
}

//***************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
void PlayerCharacter::Update()
{
   // Update movement based on the character's current velocity.
   mCoordinateX += mpVelocity->GetComponentX();
   mCoordinateY += mpVelocity->GetComponentY();
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
void PlayerCharacter::Draw(Graphics& theGraphics)
{
   mpSprite->Draw(theGraphics,
                  static_cast<int>(mCoordinateX),
                  static_cast<int>(mCoordinateY));
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