# TrackerLA
Lorentz Angle Calculation for tracker Si Strip 
------------------------------------------------
Preparation of ntuple
-------------------------------------
cmsrel CMSSW_8_0_5
cd CMSSW_8_0_5/src
cmsenv
git-cms-addpkg CalibTracker
scramv1 b -rj8/20
 -cd SiStripLorentzAngle/python
 -vim -nw ntuple_cff.py
 
 Define variables you need in the following way
 extension will be different for variables coming from different producers
 https://twiki.cern.ch/twiki/bin/viewauth/CMS/SiStripTreeFormat
 - 'keep *_shallowTracks_tsostrackmulti_*'
-git clone https://gist.github.com/mverzett/d6bde8ed6e6dec8a5ff4.git
-cmsRun lantuples.py

Analysis
-----------------------
I prefer a different CMSSW, you can use the same one

cmsrel CMSSW_8_0_12
cd CMSSW_8_0_12/src
git-cms-addpkg
DataFormats, Calibtracker, FWCore
scramv1 b -rj20
MakeClass your ntuple
add these in your header files

#include "DataFormats/DetId/interface/DetId.h"

#include "DataFormats/SiStripDetId/interface/TIBDetId.h"
#include "DataFormats/SiStripDetId/interface/TOBDetId.h"
#include "DataFormats/SiStripDetId/interface/TIDDetId.h"
#include "DataFormats/SiStripDetId/interface/TECDetId.h"

or you can have my file
