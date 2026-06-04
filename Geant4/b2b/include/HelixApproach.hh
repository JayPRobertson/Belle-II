#ifndef HELIX_APPROACH_HH
#define HELIX_APPROACH_HH

#include "G4ThreeVector.hh"

class HelixApproach{

public:
    HelixApproach(
        const G4ThreeVector& position,
        const G4ThreeVector& momentum,
        const G4ThreeVector& magneticField,
        double mass,
        double charge);
    
    G4ThreeVector Position(double t) const;
    G4ThreeVector Velocity(double t) const;

    double FindCylinderIntersection(double cylinderRadius, \
        double tStart = 0.0) const;

private:
    G4ThreeVector RotateToFieldAxis(const G4ThreeVector& v) const;
    G4ThreeVector RotateFromFieldAxis(const G4ThreeVector& v) const;

    G4ThreeVector fInitialPosition;
    G4ThreeVector fFieldAxis;
    
    double fRadius;
    double fOmega;
    
    double fVparallel;
    double fVperp;
    
    double fAlpha;
    
    G4ThreeVector fHelixCentre;

};

#endif
