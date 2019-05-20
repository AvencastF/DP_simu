//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
//
/// \file DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "TrackerSD.hh"
#include "CalorimeterSD.hh"
#include "G4UniformMagField.hh"


class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class G4UserLimits;

class DetectorMessenger;
class MagneticField;

/// Detector construction class to define materials and geometry.
///
/// In addition a transverse uniform magnetic field is defined in
/// SetMagField() method which can be activated via a command
/// defined in the DetectorMessenger class. 

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

  public:
    virtual G4VPhysicalVolume* Construct();

    // Set methods
    void SetMagField(G4double );
    void SetTargetMaterial (G4String );
    //void SetChamberMaterial(G4String );
    void SetMaxStep (G4double );
    void SetCheckOverlaps(G4bool );
    void SetTTrkMagField(G4double);
    void SetRTrkMagField(G4double);

  private:
    // methods
    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();
  
	// geometry parameters
	G4bool constructed;

	G4double  targetLength			; // full length of Target
	G4double  recoil_chamberLength	;
	G4double  tag_chamberLength		;
    G4double  trackerLength			;  
	G4double  ecalLength			; // length of ECal
	G4double  ecalradius			; 
	G4double  ecalSize				; // half length of ECal
	G4double  trackerRadius			; 
    G4double  targetRadius			; // Radius of Target
	G4double  trackerSize			; // Half length of the Tracker
	G4double  worldLength			;
    G4double  HCalLength            ;

    G4double rx ;
    G4double ry ;
    G4double rz ;
    G4double gx ;
    G4double gy ;
    G4double gz ;

    // data members
    G4Box* worldS;
    G4Box* trackerT;
    G4Box* trackerR;
    G4Box* targetS;
    G4Box* chamberS_tag;
    G4Box* chamberS_ECal;
    G4Box* chamberS_HCal;
    G4Box* chamberS_HCal_Gas;
    G4SubtractionSolid* HCal_RPC_Shell;
    G4Box* chamberS_HCalCap;
    G4Box* chamberS_HCalCap_Gas;
    G4SubtractionSolid* HCalCap_RPC_Shell;
    G4Box* chamberS_HCalSide;
    G4Box* chamberS_HCalSide_Gas;
    G4SubtractionSolid* HCalSide_RPC_Shell;
    G4Box** chamberS_rec;
    G4Box* ECalS;
    G4Box* HCalS;
    G4Box* HCalES;
    G4SubtractionSolid* HCal_Edge;
    //
    G4LogicalVolume*   worldLV;
    G4LogicalVolume*   trackerTLV;
    G4LogicalVolume*   trackerRLV;
    G4LogicalVolume*   fLogicTarget;     // pointer to the logical Target
    G4LogicalVolume**  fLogicChamber_rec;    // pointer to the logical Chamber_rec
    G4LogicalVolume**  fLogicChamber_tag;    // pointer to the logical Chamber_tag
    G4LogicalVolume*   ECalLV;
    G4LogicalVolume**  fLogicChamber_ECal;    // pointer to the logical Chamber_ECal
    G4LogicalVolume*   HCalLV;
    G4LogicalVolume**  HCal_RPC_LV;
    G4LogicalVolume**  HCal_RPC_GAS_LV;
    G4LogicalVolume*   HCalELV;
    G4LogicalVolume**  HCECap_RPC_LV;
    G4LogicalVolume**  HCECap_RPC_GAS_LV;
    G4LogicalVolume**  HCESide_RPC_LV;
    G4LogicalVolume**  HCESide_RPC_GAS_LV;
    //
    G4VPhysicalVolume* worldPV;
    //
    TrackerSD* aTrackerSD_rec;
    TrackerSD* aTrackerSD_tag;
    CalorimeterSD* ECalSD;
    CalorimeterSD* HCalSD;
    CalorimeterSD* HCECapSD;
    CalorimeterSD* HCESideSD;

    G4Material*        fTargetMaterial;  // pointer to the target  material
    G4Material*        fECalMaterial; // pointer to the chamber material

    G4UserLimits* fStepLimit;            // pointer to user step limits

    DetectorMessenger*  fMessenger;   // messenger
    MagneticField*      fMagField;     // magnetic field
    G4UniformMagField* magFieldT;
    G4UniformMagField* magFieldR;
    G4FieldManager* localFieldMgrT;
    G4FieldManager* localFieldMgrR;
    
    G4double fTTrkMagField;
    G4double fRTrkMagField;
    G4bool  fCheckOverlaps; // option to activate checking of volumes overlaps 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
