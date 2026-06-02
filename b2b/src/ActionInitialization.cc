#include "ActionInitialization.hh"

#include "EventAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

namespace B2{

void ActionInitialization::BuildForMaster() const{
  SetUserAction(new RunAction);
}


void ActionInitialization::Build() const{
  SetUserAction(new PrimaryGeneratorAction());
  SetUserAction(new RunAction);
  SetUserAction(new EventAction);
}


}  // namespace B2

