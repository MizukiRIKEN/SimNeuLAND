#ifndef SAMURAIMAXTIMECUTS_HH
#define SAMURAIMAXTIMECUTS_HH

#include "G4ios.hh"
#include "globals.hh"
#include "SpecialCuts.hh"

class SAMURAIMaxTimeCuts : public SpecialCuts
{
public:     
  SAMURAIMaxTimeCuts(const G4String& processName ="SAMURAIMaxTimeCuts");
  virtual ~SAMURAIMaxTimeCuts();

  virtual G4VParticleChange* PostStepDoIt(const G4Track&,
					  const G4Step&);

  // PostStep GPIL
  virtual G4double PostStepGetPhysicalInteractionLength(const G4Track& track,
							G4double   previousStepSize,
							G4ForceCondition* condition);

private:
  G4double fMaxTime;
};

#endif

