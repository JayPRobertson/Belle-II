#ifndef B2EventAction_h
#define B2EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

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

private:
    G4double fTrackedDistance = 0.0;
};

}  // namespace B2

#endif