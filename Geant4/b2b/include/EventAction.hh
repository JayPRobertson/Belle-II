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

    void AddTrackedDistance(G4double distance) { fTrackedDistance += distance; }
    G4double GetTrackedDistance() const { return fTrackedDistance; }

    void SetPredictedEntry(const G4ThreeVector& v) { 
        fPredEntry = v; 
        fHasPredEntry = true; 
    }
    
    void SetPredictedExit(const G4ThreeVector& v) { 
        fPredExit  = v; 
        fHasPredExit  = true; 
    }

    void SetActualEntry(const G4ThreeVector& v) { 
        fActEntry = v; 
        fHasActEntry = true; 
    }
    
    void SetActualExit(const G4ThreeVector& v) { 
        fActExit  = v; 
        fHasActExit  = true; 
    }

    G4ThreeVector GetPredictedEntry() const { return fPredEntry; }
    G4ThreeVector GetPredictedExit()  const { return fPredExit; }

    G4ThreeVector GetActualEntry() const { return fActEntry; }
    G4ThreeVector GetActualExit()  const { return fActExit; }

private:
    G4double fTrackedDistance = 0.0;

    G4ThreeVector fPredEntry;
    G4ThreeVector fPredExit;

    G4ThreeVector fActEntry;
    G4ThreeVector fActExit;

    G4bool fHasPredEntry = false;
    G4bool fHasPredExit  = false;
    G4bool fHasActEntry  = false;
    G4bool fHasActExit   = false;
};

}  // namespace B2

#endif