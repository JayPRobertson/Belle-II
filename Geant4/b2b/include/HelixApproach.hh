#include "G4ThreeVector.hh"

class HelixApproach {
public:
    HelixApproach(
        const G4ThreeVector& position,
        const G4ThreeVector& momentum,
        const G4ThreeVector& magneticField,
        double mass,
        double charge);

    G4ThreeVector Position(double t) const;
    G4ThreeVector Velocity(double t) const;

    void FindGasVolumeCrossings(
        double innerRadius,
        double outerRadius,
        double halfLength,
        G4ThreeVector& entryPoint,
        G4ThreeVector& exitPoint) const;

private:

    G4ThreeVector RotateToFieldAxis(const G4ThreeVector& v) const;
    G4ThreeVector RotateFromFieldAxis(const G4ThreeVector& v) const;

    bool InGas(const G4ThreeVector& p,
               double innerRadius,
               double outerRadius,
               double halfLength) const;

    G4ThreeVector fInitialPosition;
    G4ThreeVector fFieldAxis;

    G4ThreeVector fHelixCentre;

    double fVparallel = 0.0;
    double fVperp = 0.0;
    double fOmega = 0.0;
    double fRadius = 0.0;
    double fAlpha = 0.0;
};