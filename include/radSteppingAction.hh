#ifndef radSteppingAction_hh
#define radSteppingAction_hh 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

#include "TFile.h"
#include "TH3I.h"
#include "TTree.h"
#include "TGraph.h"
#include "radDamage.hh"

class radSteppingAction : public G4UserSteppingAction
{
public:
  radSteppingAction(G4int*);
  ~radSteppingAction();
  
  void UserSteppingAction(const G4Step*);
  void InitVar();
  void InitOutput();
    
private:
  G4int *evNr;
  TFile *fout;
  TTree *tout;

  G4int currentEv;
  
  //tree variables
  G4int eventNr;
  G4int material; //detector 0, tgt 1
  G4int pType;    
  G4int trackID;
  G4int parentID;
  
  //1XX= front detector with id XX 
  //2XX= radial detector with id XX
  //3XX= back detector with id XX  
  G4int detID;
  
  G4double  preE; // total energy
  G4double  preKE;// kinetic energy
  
  G4double  prePosX; //position
  G4double  prePosY;
  G4double  prePosZ;
  G4double  preMomX; //momentum
  G4double  preMomY;
  G4double  preMomZ;  
  G4double  neilVal;
  G4double  mremVal;
  G4double  normCosAng;
  
  radDamage dmgCalc;
};

#endif
