#ifndef HadronPhysicsQGSP_INCLXX_HP_h
#define HadronPhysicsQGSP_INCLXX_HP_h 1

#include "globals.hh"
#include "G4ios.hh"

#include "G4VPhysicsConstructor.hh"
#include "G4MiscLHEPBuilder.hh"

#include "G4PiKBuilder.hh"
#include "G4LEPPiKBuilder.hh"
#include "G4QGSPPiKBuilder.hh"
#include "G4BertiniPiKBuilder.hh"
#include "G4INCLXXPiKBuilder.hh"

#include "G4ProtonBuilder.hh"
#include "G4LEPProtonBuilder.hh"
#include "G4QGSPProtonBuilder.hh"
#include "G4BertiniProtonBuilder.hh"
#include "G4INCLXXProtonBuilder.hh"

#include "G4NeutronBuilder.hh"
#include "G4LEPNeutronBuilder.hh"
#include "G4QGSPNeutronBuilder.hh"
#include "G4BertiniNeutronBuilder.hh"
#include "G4INCLXXNeutronBuilder.hh"
#include "G4NeutronHPBuilder.hh"

/**
 * Build hadronic physics using INCL++ and QGSP models.
 *
 * @see G4INCLXXProtonBuilder
 * @see G4INCLXXNeutronBuilder
 * @see G4INCLXXPiKBuilder
 */
class HadronPhysicsQGSP_INCLXX_HP : public G4VPhysicsConstructor
{
public: 
  HadronPhysicsQGSP_INCLXX_HP(G4int verbose =1);
  HadronPhysicsQGSP_INCLXX_HP(const G4String& name, G4bool quasiElastic=true);
  virtual ~HadronPhysicsQGSP_INCLXX_HP();

public: 
  virtual void ConstructParticle();
  virtual void ConstructProcess();

  void SetQuasiElastic(G4bool value) {QuasiElastic = value;}; 
  void SetProjectileDiffraction(G4bool value) {ProjectileDiffraction = value;}; 

private:
  void CreateModels();
  G4NeutronBuilder * theNeutrons;
  G4LEPNeutronBuilder * theLEPNeutron;
  G4QGSPNeutronBuilder * theQGSPNeutron;
  G4BertiniNeutronBuilder * theBertiniNeutron;
  G4INCLXXNeutronBuilder * theInclAblaNeutron;
  G4NeutronHPBuilder * theHPNeutron;
    
  G4PiKBuilder * thePiK;
  G4LEPPiKBuilder * theLEPPiK;
  G4QGSPPiKBuilder * theQGSPPiK;
  G4BertiniPiKBuilder * theBertiniPiK;
  G4INCLXXPiKBuilder * theInclAblaPiK;
    
  G4ProtonBuilder * thePro;
  G4LEPProtonBuilder * theLEPPro;
  G4QGSPProtonBuilder * theQGSPPro; 
  G4BertiniProtonBuilder * theBertiniPro;
  G4INCLXXProtonBuilder * theInclAblaPro;
    
  G4MiscLHEPBuilder * theMiscLHEP;
    
  G4bool QuasiElastic;
  G4bool ProjectileDiffraction;
};

#endif

