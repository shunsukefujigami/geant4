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
// $Id: G4ee2KNeutralModel.hh,v 1.1 2008/07/10 18:07:26 vnivanch Exp $
// GEANT4 tag $Name: geant4-09-02 $
//
// -------------------------------------------------------------------
//
// GEANT4 Class header file
//
//
// File name:     G4ee2KNeutralModel
//
// Author:        Vladimir Ivanchenko
//
// Creation date: 09.07.2008
//
// Modifications:
//

//
// Class Description:
//

// -------------------------------------------------------------------
//

#ifndef G4ee2KNeutralModel_h
#define G4ee2KNeutralModel_h 1

#include "G4Vee2hadrons.hh"
#include "globals.hh"
#include "G4eeCrossSections.hh"

class G4DynamicParticle;
class G4PhysicsVector;

class G4ee2KNeutralModel : public G4Vee2hadrons
{

public:

  G4ee2KNeutralModel(G4eeCrossSections*);

  virtual ~G4ee2KNeutralModel();

  G4double ThresholdEnergy() const;

  G4double PeakEnergy() const;

  G4double ComputeCrossSection(G4double) const;

  G4PhysicsVector* PhysicsVector(G4double, G4double) const;

  virtual void SampleSecondaries(std::vector<G4DynamicParticle*>*,
              G4double, const G4ThreeVector&);

private:

  // hide assignment operator
  G4ee2KNeutralModel & operator=(const  G4ee2KNeutralModel &right);
  G4ee2KNeutralModel(const  G4ee2KNeutralModel&);

  G4eeCrossSections* cross;

  G4double massK;
  G4double massPhi;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline G4double G4ee2KNeutralModel::ThresholdEnergy() const
{
  return 2.0*massK;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline G4double G4ee2KNeutralModel::PeakEnergy() const
{
  return massPhi;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline G4double G4ee2KNeutralModel::ComputeCrossSection(G4double e) const
{
  G4double ee = std::min(HighEnergy(),e);
  return cross->CrossSection2Kneutral(ee);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#endif