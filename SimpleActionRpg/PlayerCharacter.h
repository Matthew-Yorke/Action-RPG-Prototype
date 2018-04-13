//***************************************************************************************************************************************************
//
// File Name: PlayerCharacter.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#ifndef PlayerCharacter_h
#define PlayerCharacter_h

#include <allegro5/allegro_acodec.h>
#include "allegro5\allegro.h"
#include "Vector2D.h"
#include "AnimatedSprite.h"
#include "MeleeWeapon.h"
#include "Rectangle.h"
#include "State.h"
#include "PlayerConstants.h"
#include <vector>
#include <algorithm>
#include "Object.h"

class PlayerCharacter : public Object
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: PlayerCharacter
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
      PlayerCharacter(Graphics& theGraphics, int theCoordianteX, int theCoordinateY);

      //************************************************************************************************************************************************
      //
      // Method Name: ~PlayerCharacter
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      ~PlayerCharacter();

      //************************************************************************************************************************************************
      //
      // Method Name: GetDirection
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      PlayerConstants::DIRECTION GetDirection() { return mDirection; };

      //************************************************************************************************************************************************
      //
      // Method Name: SetDirection
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theDirection - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void SetDirection(PlayerConstants::DIRECTION theDirection) { mDirection = theDirection; mpMeleeWeapon->SetDirection(theDirection); };

      //************************************************************************************************************************************************
      //
      // Method Name: InsertMovementDirection
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theDirection - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void InsertMovementDirection(PlayerConstants::DIRECTION theDirection)
      {
         mMovingDirectionVector.insert(mMovingDirectionVector.begin(),
                                       theDirection);
      };

      //************************************************************************************************************************************************
      //
      // Method Name: RemoveMovementDirection
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theDirection - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void RemoveMovementDirection(PlayerConstants::DIRECTION theDirection)
      {
         mMovingDirectionVector.erase(std::remove(mMovingDirectionVector.begin(),
                                                  mMovingDirectionVector.end(),
                                                  theDirection),
                                      mMovingDirectionVector.end());
      };

      //************************************************************************************************************************************************
      //
      // Method Name: IsMovingDirectionEmpty
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      inline bool IsMovingDirectionEmpty()
      {
         return mMovingDirectionVector.empty();
      };

      //************************************************************************************************************************************************
      //
      // Method Name: IsMovingDirectionEmpty
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      inline PlayerConstants::DIRECTION GetFrontOfMovingDirectionVector()
      {
         return mMovingDirectionVector.front();
      };

      //************************************************************************************************************************************************
      //
      // Method Name: GetVelocity
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      inline Vector2D* GetVelocity() { return mpVelocity; };

      //************************************************************************************************************************************************
      //
      // Method Name: GetSprite
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      inline AnimatedSprite* GetSprite() { return mpSprite; };

      //************************************************************************************************************************************************
      //
      // Method Name: GetMeleeWeapon
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      inline MeleeWeapon* GetMeleeWeapon() { return mpMeleeWeapon; };

      //************************************************************************************************************************************************
      //
      // Method Name: ChangeState
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theState - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void ChangeState(State* theState) { delete mpCurrentState; mpCurrentState = theState; mpCurrentState->SetCharacterReference(this); };

      //************************************************************************************************************************************************
      //
      // Method Name: KeyDown
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theEvent - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void KeyDown(ALLEGRO_EVENT theEvent) { mpCurrentState->KeyDown(theEvent); };

      //************************************************************************************************************************************************
      //
      // Method Name: KeyUp
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theEvent - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void KeyUp(ALLEGRO_EVENT theEvent) { mpCurrentState->KeyUp(theEvent); };

      //************************************************************************************************************************************************
      //
      // Method Name: Update
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
      inline void Update(float theTimeChange) { mpCurrentState->Update(theTimeChange); };

      //************************************************************************************************************************************************
      //
      // Method Name: Draw
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
      inline void Draw(Graphics& theGraphics) { mpCurrentState->Draw(theGraphics); };

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
      void DrawSprite(Graphics& theGraphics);

   protected:

   private:

   //************************************************************************************************************************************************
   // End Method Declarations
   //************************************************************************************************************************************************

   //************************************************************************************************************************************************
   // Start Member Variable Declarations
   //************************************************************************************************************************************************

   public:

   protected:

   private:

      // TODO: Add description.
      int mMaxHealth;

      // TODO: Add description.
      int mCurrentHealth;

      // TODO: Add description.
      int mMaxMana;

      // TODO: Add description.
      int mCurrentMana;

      // TODO: Add description.
      Vector2D* mpVelocity;

      // TODO: Add description.
      AnimatedSprite* mpSprite;

      // TODO: Add description.
      Rectangle* mpHitbox;

      // TODO: Add description.
      MeleeWeapon* mpMeleeWeapon;

      // TODO: Add description.
      State* mpCurrentState;

      // TODO: Add description.
      PlayerConstants::DIRECTION mDirection; 

      // TODO: Add description.
      std::vector<PlayerConstants::DIRECTION> mMovingDirectionVector;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif