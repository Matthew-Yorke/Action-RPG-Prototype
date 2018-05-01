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

#include <allegro5/allegro_primitives.h>
#include "PlayerCharacter.h"
#include "IdleState.h"

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
PlayerCharacter::PlayerCharacter(Graphics& theGraphics, int theCoordinateX, int theCoordinateY) :
RectangleObject(theCoordinateX, theCoordinateY, 64, 64)
{
   mCurrentHealth = mMaxHealth = 10;
   mCurrentMana = mMaxMana = 5;
   mpVelocity = new Vector2D(2.0F,
                             2.0F);
   mpSprite = new AnimatedSprite(theGraphics,
                                 "../Images/test.png",
                                 0,
                                 0,
                                 64,
                                 64,
                                 6,
                                 4);
   mpHitbox = new Rectangle(theCoordinateX + 20,
                            theCoordinateY + 1,
                            25,
                            63);
   mpMovementHitbox = new Rectangle(theCoordinateX + 20,
                                    theCoordinateY + 33,
                                    25,
                                    31);
   mpMeleeWeapon = new MeleeWeapon(theGraphics,
                                   1);
   mpCurrentState = new IdleState(this);
   mDirection = PlayerConstants::DIRECTION::DOWN;
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
   delete mpHitbox;
   delete mpMovementHitbox;
   delete mpMeleeWeapon;
}

//************************************************************************************************************************************************
//
// Method Name: GetDirection
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
PlayerConstants::DIRECTION PlayerCharacter::GetDirection()
{
   return mDirection;
}

//************************************************************************************************************************************************
//
// Method Name: SetDirection
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::SetDirection(PlayerConstants::DIRECTION theDirection)
{
   mDirection = theDirection;
   mpMeleeWeapon->SetDirection(theDirection);
}

//************************************************************************************************************************************************
//
// Method Name: InsertMovementDirection
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::InsertMovementDirection(PlayerConstants::DIRECTION theDirection)
{
   mMovingDirectionVector.insert(mMovingDirectionVector.begin(),
                                 theDirection);
}

//************************************************************************************************************************************************
//
// Method Name: RemoveMovementDirection
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::RemoveMovementDirection(PlayerConstants::DIRECTION theDirection)
{
   mMovingDirectionVector.erase(std::remove(mMovingDirectionVector.begin(),
                                            mMovingDirectionVector.end(),
                                            theDirection),
                                mMovingDirectionVector.end());
}

//************************************************************************************************************************************************
//
// Method Name: IsMovingDirectionEmpty
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool PlayerCharacter::IsMovingDirectionEmpty()
{
   return mMovingDirectionVector.empty();
}

//************************************************************************************************************************************************
//
// Method Name: IsMovingDirectionEmpty
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
PlayerConstants::DIRECTION PlayerCharacter::GetFrontOfMovingDirectionVector()
{
   return mMovingDirectionVector.front();
}

//************************************************************************************************************************************************
//
// Method Name: GetVelocity
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
Vector2D* PlayerCharacter::GetVelocity()
{
   return mpVelocity;
}

//************************************************************************************************************************************************
//
// Method Name: GetSprite
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
AnimatedSprite* PlayerCharacter::GetSprite()
{
   return mpSprite;
}

//************************************************************************************************************************************************
//
// Method Name: GetHitBox
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
Rectangle* PlayerCharacter::GetHitBox()
{
   return mpHitbox;
}

//************************************************************************************************************************************************
//
// Method Name: GetMovementHitBox
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
Rectangle* PlayerCharacter::GetMovementHitBox()
{
   return mpMovementHitbox;
}

//************************************************************************************************************************************************
//
// Method Name: GetMeleeWeapon
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
MeleeWeapon* PlayerCharacter::GetMeleeWeapon()
{
   return mpMeleeWeapon;
}

//************************************************************************************************************************************************
//
// Method Name: ChangeState
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::ChangeState(State* theState)
{
   delete mpCurrentState;
   mpCurrentState = theState;
}

//************************************************************************************************************************************************
//
// Method Name: KeyDown
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::KeyDown(ALLEGRO_EVENT theEvent)
{
   mpCurrentState->KeyDown(theEvent);
}

//************************************************************************************************************************************************
//
// Method Name: KeyUp
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::KeyUp(ALLEGRO_EVENT theEvent)
{
   mpCurrentState->KeyUp(theEvent);
}

//************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::Update(float theTimeChange)
{
   mpCurrentState->Update(theTimeChange);
   mpHitbox->SetCoordinateX(GetCoordinateX() + 20);
   mpHitbox->SetCoordinateY(GetCoordinateY() + 1);
   mpMovementHitbox->SetCoordinateX(GetCoordinateX() + 20);
   mpMovementHitbox->SetCoordinateY(GetCoordinateY() + 33);
}

//************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayerCharacter::Draw(Graphics& theGraphics)
{
   mpCurrentState->Draw(theGraphics);
   al_draw_rectangle(mpHitbox->GetCoordinateX(), mpHitbox->GetCoordinateY(), mpHitbox->GetCoordinateX() + mpHitbox->GetWidth(), mpHitbox->GetCoordinateY()+ mpHitbox->GetHeight(), al_map_rgb(255,0,0), 1);
   al_draw_rectangle(mpMovementHitbox->GetCoordinateX(), mpMovementHitbox->GetCoordinateY(), mpMovementHitbox->GetCoordinateX() + mpMovementHitbox->GetWidth(), mpMovementHitbox->GetCoordinateY()+ mpMovementHitbox->GetHeight(), al_map_rgb(255,0,0), 1);
}

//************************************************************************************************************************************************
//
// Method Name: DrawSprite
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theGraphics - TODO: Add description.
//
// Return:
//  N/A
//
//************************************************************************************************************************************************
void PlayerCharacter::DrawSprite(Graphics& theGraphics)
{
   mpSprite->Draw(theGraphics,
                  GetCoordinateX(),
                  GetCoordinateY());
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