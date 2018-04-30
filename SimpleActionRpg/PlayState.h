//***************************************************************************************************************************************************
//
// File Name: PlayState.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef PlayState_H
#define PlayState_H

#include "GameState.h"
#include "Map.h"
#include "ShadowLayer.h"
#include "PlayerCharacter.h"
#include "Camera.h"
#include "Clock.h"
#include "Enemy.h"

class PlayState : public GameState
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: PlayState
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
      //*********************************************************************************************************************************************
      PlayState(Graphics& theGraphics);

      //*********************************************************************************************************************************************
      //
      // Method Name: ~PlayState
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
      //*********************************************************************************************************************************************
      ~PlayState();

      //*********************************************************************************************************************************************
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
      //*********************************************************************************************************************************************
      void KeyDown(ALLEGRO_EVENT theEvent);

      //*********************************************************************************************************************************************
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
      //*********************************************************************************************************************************************
      void KeyUp(ALLEGRO_EVENT theEvent);

      //*********************************************************************************************************************************************
      //
      // Method Name: Update
      //
      // Description:
      //  Nothing is being done during the idle state, so there is no code in the update method.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Update(float theTimeChange);

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
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
      //*********************************************************************************************************************************************
      void Draw(Graphics& theGraphics);

   protected:

      // There are currently no protected methods for this class.

   private:

      //*********************************************************************************************************************************************
      //
      // Method Name: CollisionDetection
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theRectangleOne - TODO: Add description.
      //  theRectangleTwo - TODO: Add description.
      //
      // Return:
      //  TODO: Add description.
      //
      //*********************************************************************************************************************************************
      bool CollisionDetection(Rectangle* theRectangleOne, Rectangle* theRectangleTwo);

      //*********************************************************************************************************************************************
      //
      // Method Name: PlayerAttackCollision
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
      //*********************************************************************************************************************************************
      void PlayerAttackCollision();

      //*********************************************************************************************************************************************
      //
      // Method Name: MapNonTraverableMapTileCollision
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
      //*********************************************************************************************************************************************
      void MapNonTraverableMapTileCollision();

      //*********************************************************************************************************************************************
      //
      // Method Name: MapEventCollision
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
      //*********************************************************************************************************************************************
      void MapEventCollision();

   //************************************************************************************************************************************************
   // End Method Declarations
   //************************************************************************************************************************************************

   //************************************************************************************************************************************************
   // Start Member Variable Declarations
   //************************************************************************************************************************************************

   public:

      // There are currently no public member variables for this class.

   protected:

      // There are currently no protected member variables for this class.

   private:

      Map* mpCurrentMap;

      ShadowLayer* mpShadowLayer;

      PlayerCharacter* mpPlayer;

      Rectangle* mpMapAreaBoundary;

      Camera* mpCamera;

      Clock* mpGameClock;

      std::vector<Enemy*> mpEnemyList;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif