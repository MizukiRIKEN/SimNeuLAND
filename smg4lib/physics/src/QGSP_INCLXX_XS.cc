
#include "QGSP_INCLXX_XS.hh"

#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "HadronPhysicsQGSP_INCLXX.hh"
//#include "G4QStoppingPhysics.hh"
#include "G4StoppingPhysics.hh"
//#include "G4IonInclAblaPhysics.hh"
#include "G4IonINCLXXPhysics.hh"
#include "AddXSPhysics.hh"
#include "SAMURAICutsPhysics.hh"

#include "G4DataQuestionaire.hh"

QGSP_INCLXX_XS::QGSP_INCLXX_XS(G4int ver, const G4String&) : G4VModularPhysicsList()
{
  G4DataQuestionaire it(photon, neutron, neutronxs);
  G4cout << "<<< Geant4 Physics List simulation engine: QGSP_INCLXX_XS"<< G4endl;
  G4cout << G4endl;

  defaultCutValue = 1*mm;  
  SetVerboseLevel(ver);

  // EM Physics
  RegisterPhysics( new G4EmStandardPhysics(ver) );

  // Synchroton Radiation & GN Physics
  RegisterPhysics( new G4EmExtraPhysics(ver) );

  // Decays
  RegisterPhysics( new G4DecayPhysics(ver) );

  // Hadron Elastic scattering
  RegisterPhysics( new G4HadronElasticPhysics(ver) );

  // Hadron Physics
  RegisterPhysics( new HadronPhysicsQGSP_INCLXX(ver));

  // Stopping Physics
  //  RegisterPhysics( new G4QStoppingPhysics(ver) );
  RegisterPhysics( new G4StoppingPhysics(ver) );

  // Ion Physics
  //  RegisterPhysics( new G4IonInclAblaPhysics(ver)); // used with INCLXX
  RegisterPhysics( new G4IonINCLXXPhysics(ver));

  // Add XS data set
  RegisterPhysics( new AddXSPhysics(ver));

  // SAMURAICutsPhysics
  RegisterPhysics( new SAMURAICutsPhysics(ver) );
}

QGSP_INCLXX_XS::~QGSP_INCLXX_XS()
{;}

void QGSP_INCLXX_XS::SetCuts()
{
  SetCutsWithDefault();   
}
