#ifndef DayoneDetectorCONSTRUCTIONNEBULAMESSENGER_HH
#define DayoneDetectorCONSTRUCTIONNEBULAMESSENGER_HH

#include "G4UImessenger.hh"

class DayoneDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithoutParameter;
class G4UIcmdWithABool;

class DayoneDetectorConstructionMessenger : public G4UImessenger
{
public:
  DayoneDetectorConstructionMessenger(DayoneDetectorConstruction*);
  virtual ~DayoneDetectorConstructionMessenger();

  void SetNewValue(G4UIcommand*, G4String);

protected:
  DayoneDetectorConstruction* fDetectorConstruction;

  G4UIdirectory* fGeometryDirectory;
  G4UIcmdWithoutParameter* fUpdateGeometryCmd;
  G4UIcmdWithABool* fFillAirCmd;

};

#endif

