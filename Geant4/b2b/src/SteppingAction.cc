#include "SteppingAction.hh"

#include <iostream>
#include <fstream>
#include <string>

#include "G4RunManager.hh"
#include "G4StepPoint.hh"
#include "G4VPhysicalVolume.hh"
#include "EventAction.hh"

SteppingAction::SteppingAction(B2::EventAction* eventAction)
 : fEventAction(eventAction){}

void SteppingAction::UserSteppingAction(const G4Step* aStep){
  G4StepPoint* preStepPoint  = aStep->GetPreStepPoint();
  G4StepPoint* postStepPoint = aStep->GetPostStepPoint();
  
  G4VPhysicalVolume* preVol = preStepPoint->GetPhysicalVolume();
  G4VPhysicalVolume* postVol = postStepPoint->GetPhysicalVolume();
    
  // Verify particle is inside the gas volume
  if (preVol && postVol){

    if (preVol->GetName() == "CylinderPhys"){
        
      // Add step length to total distance
      G4double stepLength = aStep->GetStepLength();
      fEventAction->AddTrackedDistance(stepLength);
    
    }

    if (preVol->GetName() == "CylinderPhys" &&
        postVol->GetName() != "CylinderPhys") {

          std::ofstream stepFile("init_step_data.csv", std::ios_base::app);
          
          G4ThreeVector pos = preStepPoint->GetPosition();
          G4double energy = preStepPoint->GetKineticEnergy();
          G4double dist = fEventAction->GetTrackedDistance();
          
          stepFile << energy << ","
                   << pos.getX() << "," << pos.getY() << "," << pos.getZ()
                   << ',' << dist << "\n";
          
          stepFile.close();
      }
   }
}