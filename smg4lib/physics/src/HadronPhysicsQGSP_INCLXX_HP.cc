
#include "HadronPhysicsQGSP_INCLXX_HP.hh"

#include "globals.hh"
#include "G4ios.hh"
#include <iomanip>   
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"

#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4ShortLivedConstructor.hh"

HadronPhysicsQGSP_INCLXX_HP::HadronPhysicsQGSP_INCLXX_HP(G4int)
                    :  G4VPhysicsConstructor("hInelastic QGSP_INCLXX_HP")
		     , QuasiElastic(true)
{
   ProjectileDiffraction=false;
}

HadronPhysicsQGSP_INCLXX_HP::HadronPhysicsQGSP_INCLXX_HP(const G4String& name, G4bool quasiElastic)
                    :  G4VPhysicsConstructor(name) , QuasiElastic(quasiElastic)
{
   ProjectileDiffraction=false;
}

void HadronPhysicsQGSP_INCLXX_HP::CreateModels()
{
  theNeutrons=new G4NeutronBuilder;
  theNeutrons->RegisterMe(theQGSPNeutron=new G4QGSPNeutronBuilder(QuasiElastic, ProjectileDiffraction));
  theNeutrons->RegisterMe(theLEPNeutron=new G4LEPNeutronBuilder);
  theLEPNeutron->SetMinEnergy(19.9*MeV);
  theLEPNeutron->SetMinInelasticEnergy(9.5*GeV);
  theLEPNeutron->SetMaxInelasticEnergy(25*GeV);  

  theNeutrons->RegisterMe(theBertiniNeutron=new G4BertiniNeutronBuilder);
  theBertiniNeutron->SetMinEnergy(2.9*GeV);
  theBertiniNeutron->SetMaxEnergy(9.9*GeV);

  theNeutrons->RegisterMe(theInclAblaNeutron=new G4INCLXXNeutronBuilder);
  theInclAblaNeutron->SetMinEnergy(19.9*MeV);
  theInclAblaNeutron->SetMaxEnergy(3.0*GeV);

  theNeutrons->RegisterMe(theHPNeutron=new G4NeutronHPBuilder);

  thePro=new G4ProtonBuilder;
  thePro->RegisterMe(theQGSPPro=new G4QGSPProtonBuilder(QuasiElastic, ProjectileDiffraction));
  thePro->RegisterMe(theLEPPro=new G4LEPProtonBuilder);
  theLEPPro->SetMinEnergy(9.5*GeV);
  theLEPPro->SetMaxEnergy(25*GeV);

  thePro->RegisterMe(theBertiniPro=new G4BertiniProtonBuilder);
  theBertiniPro->SetMinEnergy(2.9*GeV);
  theBertiniPro->SetMaxEnergy(9.9*GeV);

  thePro->RegisterMe(theInclAblaPro=new G4INCLXXProtonBuilder);
  theInclAblaPro->SetMinEnergy(0.0*GeV);
  theInclAblaPro->SetMaxEnergy(3.0*GeV);
  
  thePiK=new G4PiKBuilder;
  thePiK->RegisterMe(theQGSPPiK=new G4QGSPPiKBuilder(QuasiElastic));
  thePiK->RegisterMe(theLEPPiK=new G4LEPPiKBuilder);
  theLEPPiK->SetMaxEnergy(25*GeV);
  theLEPPiK->SetMinEnergy(9.5*GeV);

  thePiK->RegisterMe(theBertiniPiK=new G4BertiniPiKBuilder);
  theBertiniPiK->SetMinEnergy(2.9*GeV);
  theBertiniPiK->SetMaxEnergy(9.9*GeV);

  thePiK->RegisterMe(theInclAblaPiK=new G4INCLXXPiKBuilder);
  theInclAblaPiK->SetMinEnergy(0.0*GeV);
  theInclAblaPiK->SetMaxEnergy(3.0*GeV);
  
  theMiscLHEP=new G4MiscLHEPBuilder;
}

HadronPhysicsQGSP_INCLXX_HP::~HadronPhysicsQGSP_INCLXX_HP()
{
   delete theMiscLHEP;
   delete theQGSPNeutron;
   delete theLEPNeutron;
   delete theBertiniNeutron;
   delete theInclAblaNeutron;
   delete theQGSPPro;
   delete theLEPPro;
   delete thePro;
   delete theBertiniPro;
   delete theInclAblaPro;
   delete theQGSPPiK;
   delete theLEPPiK;
   delete theInclAblaPiK;
   delete theBertiniPiK;
   delete thePiK;
}

void HadronPhysicsQGSP_INCLXX_HP::ConstructParticle()
{
  G4MesonConstructor pMesonConstructor;
  pMesonConstructor.ConstructParticle();

  G4BaryonConstructor pBaryonConstructor;
  pBaryonConstructor.ConstructParticle();

  G4ShortLivedConstructor pShortLivedConstructor;
  pShortLivedConstructor.ConstructParticle();  
}

#include "G4ProcessManager.hh"
void HadronPhysicsQGSP_INCLXX_HP::ConstructProcess()
{
  CreateModels();
  theNeutrons->Build();
  thePro->Build();
  thePiK->Build();
  theMiscLHEP->Build();
}

