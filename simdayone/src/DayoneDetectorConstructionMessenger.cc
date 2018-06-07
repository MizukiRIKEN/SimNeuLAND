
#include "DayoneDetectorConstructionMessenger.hh"
#include "DayoneDetectorConstruction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithABool.hh"

DayoneDetectorConstructionMessenger::DayoneDetectorConstructionMessenger(DayoneDetectorConstruction* Det)
 : fDetectorConstruction(Det)
{

  fGeometryDirectory = new G4UIdirectory("/samurai/geometry/");
  fGeometryDirectory->SetGuidance("Modification Commands for Dayone");

  fUpdateGeometryCmd = new G4UIcmdWithoutParameter("/samurai/geometry/Update",this);
  fUpdateGeometryCmd->SetGuidance("Update SAMURAI Geometry");

  fFillAirCmd = new G4UIcmdWithABool("/samurai/geometry/FillAir",this);
  fFillAirCmd->SetGuidance("Fill Air or Vacuum for Experimental room");
  fFillAirCmd->SetParameterName("FillAir",true);
  fFillAirCmd->SetDefaultValue(false);
}

DayoneDetectorConstructionMessenger::~DayoneDetectorConstructionMessenger()
{
  delete fGeometryDirectory;
  delete fUpdateGeometryCmd;
  delete fFillAirCmd;
}

void DayoneDetectorConstructionMessenger::SetNewValue(G4UIcommand* command, 
							G4String  newValue)
{
  if       ( command == fUpdateGeometryCmd ){
    fDetectorConstruction->UpdateGeometry();
  }else if ( command == fFillAirCmd ){
    fDetectorConstruction->SetFillAir(fFillAirCmd->GetNewBoolValue(newValue));
  }
}


