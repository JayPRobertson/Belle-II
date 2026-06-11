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

void SteppingAction::UserSteppingAction(const G4Step* aStep) {
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    G4VPhysicalVolume* preVol = preStepPoint->GetPhysicalVolume();

    // Verify particle is inside the volume
    if (!preVol) return;

    // Process only if the particle is currently inside a gas layer
    if (preVol->GetName() == "GasLayerRing") {
        G4int volumeID = preVol->GetCopyNo();
        G4int curIndex = fEventAction->GetCurIndex();

        // Check if new layer entered
        if (curIndex < volumeID) {
            fEventAction->SetTotEdep(); 

            // Initialize tracking for new layer
            G4ThreeVector entryPos = preStepPoint->GetPosition();
            fEventAction->SetPrePos(entryPos);
            fEventAction->SetPreStep(entryPos);
            fEventAction->SetCurIndex(volumeID);
            fEventAction->ResetTrackedEdep();
        }
        
        // Store positions and total energy of layer for this beam
        fEventAction->AddTrackedEdep(aStep->GetTotalEnergyDeposit());
        G4StepPoint* postStepPoint = aStep->GetPostStepPoint();
        fEventAction->SetPostPos(postStepPoint->GetPosition());
    }
}