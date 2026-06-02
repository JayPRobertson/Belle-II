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

namespace B2{

PrimaryGeneratorAction::PrimaryGeneratorAction(){
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

    G4ThreeVector direction(px, py, pz);

    fParticleGun->SetParticleMomentumDirection(direction);
    fParticleGun->GeneratePrimaryVertex(event);
}

}  // namespace B2

