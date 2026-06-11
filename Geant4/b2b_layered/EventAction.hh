#ifndef B2EventAction_h
#define B2EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

//#include <string>

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
    
    void SetPrePos(G4ThreeVector prePos) { 
        prePosX += std::to_string(prePos.x()) + "|";
        prePosY += std::to_string(prePos.y()) + "|";
        prePosZ += std::to_string(prePos.z()) + "|";
    }
    std::string GetPrePos() { 
        return prePosX + "," + prePosY + "," + prePosZ + ","; 
    }
    
    void SetPostPos(G4ThreeVector postPos) { 
        postPosX += std::to_string(postPos.x()) + "|";
        postPosY += std::to_string(postPos.y()) + "|";
        postPosZ += std::to_string(postPos.z()) + "|";
    }
    std::string GetPostPos() { 
        return postPosX + "," + postPosY + "," + postPosZ + ","; 
    }
    
    void SetTotEdep(){
        totEdep += std::to_string(fTrackedEdep) + "|";
    }
    
    std::string GetTotEdep(){ return totEdep; }

private:
    G4double fTrackedEdep = 0.0;    
    G4int curIndex = 0;
    
    G4ThreeVector preStep;
    
    std::string prePosX = "";
    std::string prePosY = "";
    std::string prePosZ = "";
    
    std::string postPosX = "";
    std::string postPosY = "";
    std::string postPosZ = "";
    
    std::string totEdep = "";
};

}  // namespace B2

#endif