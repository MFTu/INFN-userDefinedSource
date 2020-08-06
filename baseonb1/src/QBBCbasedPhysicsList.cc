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
//
/// \file QBBCbasedPhysicsList.cc
/// \brief Implementation of the QBBCbasedPhysicsList class


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//#include "B3PhysicsList.hh"

//#include "G4DecayPhysics.hh"
//#include "G4EmStandardPhysics.hh"
//#include "G4RadioactiveDecayPhysics.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//B3PhysicsList::B3PhysicsList() 
//: G4VModularPhysicsList(){
//  SetVerboseLevel(1);

  // Default physics
//  RegisterPhysics(new G4DecayPhysics());

  // EM physics
//  RegisterPhysics(new G4EmStandardPhysics());

  // Radioactive decay
//  RegisterPhysics(new G4RadioactiveDecayPhysics());
//}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//B3PhysicsList::~B3PhysicsList()
//{ 
//}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//void B3PhysicsList::SetCuts()
//{
//  G4VUserPhysicsList::SetCuts();
//} 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 



#include "QBBCbasedPhysicsList.hh"
//#include "QBBC.hh"
#include "globals.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleDefinition.hh"
 
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option2.hh"
#include "G4EmExtraPhysics.hh"
#include "G4StoppingPhysics.hh"
 
//#include "G4DataQuestionaire.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4HadronElasticPhysicsHP.hh"
#include "G4ChargeExchangePhysics.hh"
#include "G4IonPhysics.hh"
#include "G4NeutronTrackingCut.hh"
 

//QBBCbasedPhysicsList::QBBCbasedPhysicsList( G4int ver, const G4String&)
//: G4VModularPhysicsList(){

QBBCbasedPhysicsList::QBBCbasedPhysicsList( G4int ver, const G4String&)
{

//  G4DataQuestionaire it(photon, neutronxs);

  //B3PhysicsList::B3PhysicsList() 
//: G4VModularPhysicsList(){

  G4cout << "<<< Reference Physics List QBBCbasedPhysicsList "
         <<G4endl;      
 
  defaultCutValue = 0.7*mm; 
  //defaultCutValue = 0.4*mm; 
  SetVerboseLevel(ver);
 
  // EM Physics
  RegisterPhysics( new G4EmStandardPhysics(ver) );
 
  // Synchroton Radiation & GN Physics
  RegisterPhysics( new G4EmExtraPhysics(ver) );
 
  // Decays
  RegisterPhysics( new G4DecayPhysics(ver) );
 
  // Hadron Physics
  RegisterPhysics( new G4HadronElasticPhysicsXS(ver) );
 
  RegisterPhysics( new G4StoppingPhysics(ver) );
 
  RegisterPhysics( new G4IonPhysics(ver) );
 
  //G4HadronInelasticQBBC* G4HadronInelasticQBBCmf = new G4HadronInelasticQBBC(ver);
  //G4HadronInelasticQBBCmf->AddInelasticCrossSection("NeutronHPInelasticXS");

  //RegisterPhysics(G4HadronInelasticQBBCmf);
  RegisterPhysics( new G4HadronInelasticQBBC(ver));
  
 
  // Neutron tracking cut
  RegisterPhysics( new G4NeutronTrackingCut(ver) );
}                
 
QBBCbasedPhysicsList::~QBBCbasedPhysicsList() 
{}
 
void QBBCbasedPhysicsList::SetCuts()
{
  SetCutsWithDefault();   
}





