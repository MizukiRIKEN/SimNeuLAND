#ifndef SAMURAIMINEKINECUTS_HH
#define SAMURAIMINEKINECUTS_HH

#include "G4ios.hh"
#include "globals.hh"
#include "SpecialCuts.hh"

class SAMURAIMinEkineCuts : public SpecialCuts
{
public:     
  SAMURAIMinEkineCuts(const G4String& processName ="SAMURAIMinEkineCuts" );
  virtual ~SAMURAIMinEkineCuts();

  virtual G4VParticleChange* PostStepDoIt(const G4Track&,
					  const G4Step&);

  // PostStep GPIL
  virtual G4double PostStepGetPhysicalInteractionLength(const G4Track& track,
							G4double   previousStepSize,
							G4ForceCondition* condition);
};

#endif

