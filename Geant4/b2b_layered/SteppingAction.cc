#include "SteppingAction.hh"

#include <iostream>
#include <fstream>
#include <string>

#include "G4RunManager.hh"
#include "G4StepPoint.hh"
#include "G4VPhysicalVolume.hh"
#include "EventAction.hh"
#include "G4ThreeVector.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4DynamicParticle.hh"
#include <cmath>

#include "G4EmCalculator.hh"
#include "G4ParticleTable.hh"

SteppingAction::SteppingAction(B2::EventAction* eventAction)
 : fEventAction(eventAction){}

void SteppingAction::UserSteppingAction(const G4Step* aStep){

  G4StepPoint* preStepPoint  = aStep->GetPreStepPoint();
  G4StepPoint* postStepPoint = aStep->GetPostStepPoint();

  G4VPhysicalVolume* preVol  = preStepPoint->GetPhysicalVolume();
  G4VPhysicalVolume* postVol = postStepPoint->GetPhysicalVolume();
  
  // Verify particle is inside the volume
  if(!preVol || !postVol) return;

  // Get point particle enters gas volume
  if(preVol->GetName() == "GasLayerRing" &&
     postVol->GetName() == "GasLayerRing"){
      
      G4int volumeID = postVol->GetCopyNo();
      G4int curIndex = fEventAction->GetCurIndex();
      
      if (curIndex < volumeID){
         if (curIndex != 0){
            std::ofstream layerFile("layered_edep_data.csv", std::ios_base::app);
            
            fEventAction->AddTrackedEdep(aStep->GetTotalEnergyDeposit());
            
            G4ThreeVector prePos = fEventAction->GetPreStep();
            G4ThreeVector postPos = postStepPoint->GetPosition();
            layerFile << prePos.x() << "," << prePos.y() << "," 
                      << prePos.z() << ","
                      << postPos.x() << "," << postPos.y() << "," 
                      << postPos.z() << ","
                      << fEventAction->GetTrackedEdep() << "\n";   
            
            layerFile.close();
         }

         G4ThreeVector preStepPosition = postStepPoint->GetPosition();
         fEventAction->SetPreStep(preStepPosition);
         fEventAction->SetCurIndex(volumeID);
         fEventAction->ResetTrackedEdep();
     }
  }
 
  
}