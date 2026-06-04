#include "HelixApproach.hh"

#include <cmath>

namespace{
    constexpr double c_light = 2.99792458e8;
}

HelixApproach::HelixApproach(
    const G4ThreeVector& position,
    const G4ThreeVector& momentum,
    const G4ThreeVector& magneticField,
    double mass,
    double charge): fInitialPosition(position){
        
    fFieldAxis = magneticField.unit();
    
    double p = momentum.mag();
    double gamma = std::sqrt(p*p + mass*mass) / mass;
    double beta = p / std::sqrt(p*p + mass*mass);
    double speed = beta*c_light;
    double B = magneticField.mag();
    
    G4ThreeVector dir = RotateToFieldAxis(momentum.unit());
    
    fVparallel = speed*dir.z();
    fVperp = speed*dir.perp();
    
    fOmega = charge*B*c_light/(gamma*mass);
    
    fRadius = gamma*mass*fVperp/(charge*B*c_light);
    
    fAlpha = std::atan2(-dir.x(), dir.y());
    
    fHelixCentre = G4ThreeVector(
            -fRadius*std::cos(fAlpha),
            -fRadius*std::sin(fAlpha),
            0.0);
}

G4ThreeVector HelixApproach::RotateToFieldAxis(const G4ThreeVector& v) const{
    double ux = fFieldAxis.x();
    double uy = fFieldAxis.y();
    double uz = fFieldAxis.z();
    double rho = std::sqrt(ux*ux + uy*uy);
    
    if(rho < 1e-12) return v;
    
    return G4ThreeVector(
        ux*uz*v.x()/rho + uy*v.y()/rho - rho*v.z(),
        -uy*v.x()/rho + ux*v.y()/rho,
        ux*v.x() + uy*v.y() + uz*v.z());    

}

G4ThreeVector HelixApproach::RotateFromFieldAxis(const G4ThreeVector& v) const {
    double ux = fFieldAxis.x();
    double uy = fFieldAxis.y();
    double uz = fFieldAxis.z();
    double rho = std::sqrt(ux*ux + uy*uy);
    
    if(rho < 1e-12) return v;
    
    return G4ThreeVector(
        ux*uz*v.x()/rho - uy*v.y()/rho + ux*v.z(),
        uy*uz*v.x()/rho + ux*v.y()/rho + uy*v.z(),
        -rho*v.x() + uz*v.z());

}

G4ThreeVector HelixApproach::Position(double t) const {
    G4ThreeVector shift(
        fRadius*std::cos(fOmega*t + fAlpha),
        fRadius*std::sin(fOmega*t + fAlpha),
        fVparallel*t);
    
    return fInitialPosition + RotateFromFieldAxis(fHelixCentre + shift);

}

G4ThreeVector HelixApproach::Velocity(double t) const {
    return RotateFromFieldAxis(
        G4ThreeVector(
        -fVperp*std::sin(fOmega*t + fAlpha),
        fVperp*std::cos(fOmega*t + fAlpha),
        fVparallel));
}

double HelixApproach::FindCylinderIntersection(double radius, double tStart) const {
    
    double t = tStart;
    
    for(int i=0; i<100; i++){
        G4ThreeVector p = Position(t);
        G4ThreeVector v = Velocity(t);
    
        double rho = std::sqrt(p.x()*p.x() + p.y()*p.y());
        double f = rho - radius;
    
        if(std::abs(f) < 1e-6) return t;
    
        double fp = (p.x()*v.x() + p.y()*v.y()) / rho;
        t -= f/fp;
    }
    
    return t;
}
