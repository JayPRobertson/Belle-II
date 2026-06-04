#include "SteppingAction.hh"

#include <iostream>
#include <fstream>
#include <string>

#include "G4RunManager.hh"
#include "G4StepPoint.hh"
#include "G4VPhysicalVolume.hh"
#include "EventAction.hh"
#include "G4ThreeVector.hh"

SteppingAction::SteppingAction(B2::EventAction* eventAction)
 : fEventAction(eventAction){}

void SteppingAction::UserSteppingAction(const G4Step* aStep){

  G4StepPoint* preStepPoint  = aStep->GetPreStepPoint();
  G4StepPoint* postStepPoint = aStep->GetPostStepPoint();

  G4VPhysicalVolume* preVol  = preStepPoint->GetPhysicalVolume();
  G4VPhysicalVolume* postVol = postStepPoint->GetPhysicalVolume();
  
  // Verify particle is inside the gas volume
  if(!preVol || !postVol) return;

   // Add step length to total distance
  if(preVol->GetName() == "CylinderPhys"){
    fEventAction->AddTrackedDistance(aStep->GetStepLength());
  }

  // Get point particle enters gas volume
  if(preVol->GetName() != "CylinderPhys" &&
     postVol->GetName() == "CylinderPhys"){

      fEventAction->SetActualEntry(postStepPoint->GetPosition());
  }

  if(preVol->GetName() == "CylinderPhys" &&
     postVol->GetName() != "CylinderPhys"){
      
      // Get point particle exits gas volume
      fEventAction->SetActualExit(preStepPoint->GetPosition());
      
      std::ofstream stepFile("init_step_data.csv", std::ios_base::app);

      G4ThreeVector pos = preStepPoint->GetPosition();
      G4double energy = preStepPoint->GetKineticEnergy();
      G4double dist = fEventAction->GetTrackedDistance();

      stepFile << energy << ","
               << pos.x() << "," << pos.y() << "," << pos.z()
               << "," << dist << ",";
               
      stepFile.close();
      
      G4ThreeVector fPredEntry = fEventAction->GetPredictedEntry();
      G4ThreeVector fPredExit  = fEventAction->GetPredictedExit();
      G4ThreeVector fActEntry  = fEventAction->GetActualEntry();
      G4ThreeVector fActExit   = fEventAction->GetActualExit();
      
      std::ofstream eePosFile("entry_exit_data.csv", std::ios_base::app);
      
      eePosFile << fActEntry.x() << "," << fActEntry.y() << ","
                 << fActEntry.z() << ","
                 << fActExit.x() << "," << fActExit.y() << ","
                 << fActExit.z() << ","
                 
                 << fPredEntry.x() << "," << fPredEntry.y() << ","
                 << fPredEntry.z() << ","
                 
                 << fPredExit.x() << "," << fPredExit.y() << ","
                 << fPredExit.z() << "\n";
                 
      eePosFile.close();
  }
}