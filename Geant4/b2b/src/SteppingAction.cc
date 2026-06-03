#include "SteppingAction.hh"

#include <iostream>
#include <fstream>
#include <string>

#include "G4RunManager.hh"
#include "G4StepPoint.hh"
#include "G4VPhysicalVolume.hh"

void SteppingAction::UserSteppingAction(const G4Step* aStep){
  G4StepPoint* preStepPoint  = aStep->GetPreStepPoint();

  // Check if the step starts on gas boundary
  if (preStepPoint->GetStepStatus() == fGeomBoundary) {
    
    // Verify particle is inside the gas volume
    G4VPhysicalVolume* volume = preStepPoint->GetPhysicalVolume();
    if (volume && volume->GetName() == "CylinderPhys") {
        std::ofstream stepFile("init_step_data.csv", std::ios_base::app);
        
        G4ThreeVector pos = preStepPoint->GetPosition();
        G4double energy  = preStepPoint->GetKineticEnergy();
        
        stepFile << energy << ",";
        stepFile << pos.getX() << "," << pos.getY() << ","<< pos.getZ() << "\n";
        
        stepFile.close(); 
    }
    
  }
  
}
