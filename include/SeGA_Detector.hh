
#ifndef SeGA_Detector_H
#define SeGA_Detector_H 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4PVPlacement.hh"
#include "G4SubtractionSolid.hh"

#include "Doppler.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4RotationMatrix.hh"
#include "globals.hh"

struct SegmentLocation{
G4int Ring;
G4int Number;
G4int z;
G4int phi;
G4int r;
};

class SeGA_Detector {

public:

G4LogicalVolume *expHall_log;

SeGA_Detector(G4LogicalVolume*);
~SeGA_Detector();

void Construct(G4int,G4int,G4int,G4double,G4double,G4double,G4double,Doppler*);
//void PlaceDetector();

private:

Doppler* doppler;

G4Material*  HpGe;
G4Material* Al;
G4Material* preampMat;
G4Material* vacuum;

G4double Length,innerRadius,outerRadius,fingerRadius;
G4double DLinnerRadius, DLouterRadius;
G4double iCanOuterRadius, iCanInnerRadius, iCanLength;
G4double oCanThickness, oCanOuterRadius, oCanInnerRadius, oCanLength;
G4double preampRadius, preampLength;
G4double neckRadius, neckLength;
G4double cryoThickness, cryoOuterRadius, cryoInnerRadius, cryoBaseThickness, cryoLength;
G4double startAngle, spanningAngle;
G4double rd, thetad, phid, F,G,H,thr_center,thr_width;
G4double rmin, rmax, dr;

G4int Orientation;
G4int RingID, Number;

G4ThreeVector cryoBaseOffset, cryoOffset, neckOffset, oCanOffset, preampOffset, DetPos;
G4RotationMatrix DetRot, cryoRot;
G4ThreeVector ZShift;


G4Tubs* iCan;
G4Tubs* oCanFull;
G4Tubs* oCanHollow;
G4Tubs* DL;
G4Tubs* preamp;
G4Tubs* neck;
G4Tubs* cryoBase;
G4Tubs* cryoFull;
G4Tubs* cryoHollow;
G4Tubs* full;
G4Tubs* hollow;
G4Tubs* detectorphiDivisionTub;
G4Tubs* detectorcellTub;

G4SubtractionSolid* oCan;
G4SubtractionSolid* cryo;
G4SubtractionSolid* detector;

G4LogicalVolume* iCan_log;
G4LogicalVolume* oCan_log;
G4LogicalVolume* DL_log;
G4LogicalVolume* preamp_log;
G4LogicalVolume* neck_log;
G4LogicalVolume* cryoBase_log;
G4LogicalVolume* cryo_log;
G4LogicalVolume* detector_log;
G4LogicalVolume* detectorphiDivision_log;
G4LogicalVolume* detectorcell_log;

G4VPhysicalVolume* iCan_phys;
G4VPhysicalVolume* oCan_phys;
G4VPhysicalVolume* DL_phys;
G4VPhysicalVolume* preamp_phys;
G4VPhysicalVolume* neck_phys;
G4VPhysicalVolume* cryoBase_phys;
G4VPhysicalVolume* cryo_phys;
G4VPhysicalVolume* detector_phys;
G4VPhysicalVolume* detectorphiDivision_phys;
G4VPhysicalVolume* detectorcell_phys;

};

#endif

