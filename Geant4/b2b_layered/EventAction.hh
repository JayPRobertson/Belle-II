#ifndef B2EventAction_h
#define B2EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

class G4Event;

namespace B2{

class EventAction : public G4UserEventAction{
  public:
    EventAction() = default;
    ~EventAction() override = default;

    void BeginOfEventAction(const G4Event*) override;

    void EndOfEventAction(const G4Event*) override;

    void AddTrackedEdep(G4double edep) { fTrackedEdep += edep; }
    void ResetTrackedEdep() {fTrackedEdep = 0.0;}
    G4double GetTrackedEdep() const { return fTrackedEdep; }
    
    void SetCurIndex(G4double index) { curIndex = index; }
    G4int GetCurIndex() const { return curIndex; }
    
    void SetPreStep(G4ThreeVector preStepPosition) { 
        preStep = preStepPosition;
    }
    G4ThreeVector GetPreStep() { return preStep; }

private:
    G4double fTrackedEdep = 0.0;    
    G4int curIndex = 0;
    
    G4ThreeVector preStep;
};

}  // namespace B2

#endif