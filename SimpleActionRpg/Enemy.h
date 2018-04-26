//***************************************************************************************************************************************************
//
// File Name: Enemy.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#ifndef Enemy_h
#define Enemy_h

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
#include "RectangleObject.h"

class Enemy : public RectangleObject
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: Enemy
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
      Enemy(Graphics& theGraphics, int theCoordianteX, int theCoordinateY);

      //************************************************************************************************************************************************
      //
      // Method Name: ~Enemy
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
      ~Enemy();

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
      AnimatedSprite* GetSprite();

      //************************************************************************************************************************************************
      //
      // Method Name: GetHitBox
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
      Rectangle* GetHitBox();

      //************************************************************************************************************************************************
      //
      // Method Name: TakeDamage
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theDamage - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void TakeDamage(int theDamage);

      //************************************************************************************************************************************************
      //
      // Method Name: TemporaryInvincible
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
      void TemporaryInvincible();

      //************************************************************************************************************************************************
      //
      // Method Name: GetIsInvincible
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
      bool GetIsInvincible();

      //************************************************************************************************************************************************
      //
      // Method Name: GetCurrentHealth
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
      int GetCurrentHealth();

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
      void Update(float theTimeChange);

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
      void Draw(Graphics& theGraphics);

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
      AnimatedSprite* mpSprite;

      // TODO: Add description.
      Rectangle* mpHitbox;

      bool mInvincible;

      float mInvincibleTime;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif