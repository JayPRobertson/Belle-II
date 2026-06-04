#include "PrimaryGeneratorAction.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"

#include "Randomize.hh"
#include <cmath>

#include "EventAction.hh"

namespace B2{

PrimaryGeneratorAction::PrimaryGeneratorAction(EventAction* eventAction)
: fEventAction(eventAction){
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);

  G4ParticleDefinition* particleDefinition =
    G4ParticleTable::GetParticleTable()->FindParticle("mu-");

  fParticleGun->SetParticleDefinition(particleDefinition);
  fParticleGun->SetParticleEnergy(2.0 * GeV);
  fParticleGun->SetParticlePosition(G4ThreeVector(0,0,0));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction(){
  delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event){

    G4double cosTheta = 2.0*G4UniformRand() - 1.0;
    G4double sinTheta = std::sqrt(1.0 - cosTheta*cosTheta);

    G4double phi = 2.0*CLHEP::pi*G4UniformRand();

    G4double px = sinTheta*std::cos(phi);
    G4double py = sinTheta*std::sin(phi);
    G4double pz = cosTheta;

    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(px, py, pz));
    fParticleGun->GeneratePrimaryVertex(event);

    // Define detector geometry limits
    const G4double Rin  = 16. * cm;
    const G4double Rout = 109.6 * cm;
    const G4double Zmax = 241.69/2 * cm;

    const G4double mass = 0.105658 * GeV; // mu-
    const G4double charge = -1.0 * eplus;

    G4double energy = 2.0 * GeV;
    G4double momentum = std::sqrt(energy*energy - mass*mass);

    // protect against beam parallel to z-axis
    G4double sinThetaDir = std::sqrt(px*px + py*py);

    if (sinThetaDir < 1e-12) {
        fEventAction->SetPredictedEntry(G4ThreeVector(0,0,0));
        fEventAction->SetPredictedExit(G4ThreeVector(0,0,Zmax));
        return;
    }

    // approximate helix-cylinder intersection
    G4double tEntry = Rin  / (momentum * sinThetaDir);
    G4double tExit  = Rout / (momentum * sinThetaDir);

    // enforce z-boundary
    G4double tz = Zmax / std::abs(pz);
    if (tz < tExit) tExit = tz;

    G4ThreeVector entry = G4ThreeVector(px,py,pz) * tEntry;
    G4ThreeVector exit  = G4ThreeVector(px,py,pz) * tExit;

    fEventAction->SetPredictedEntry(entry);
    fEventAction->SetPredictedExit(exit);
}

}  // namespace B2