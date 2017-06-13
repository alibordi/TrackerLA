//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu May  4 14:05:43 2017 by ROOT version 5.34/34
// from TTree tree/
// found on file: LorentzAngleInputVariables.root
//////////////////////////////////////////////////////////

#ifndef LorentzAngle_MD_h
#define LorentzAngle_MD_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "DataFormats/DetId/interface/DetId.h"

#include "DataFormats/SiStripDetId/interface/TIBDetId.h"
#include "DataFormats/SiStripDetId/interface/TOBDetId.h"
#include "DataFormats/SiStripDetId/interface/TIDDetId.h"
#include "DataFormats/SiStripDetId/interface/TECDetId.h"
// Header file for the classes stored in the TTree if any.
#include <vector>
#include <string>
#include "TROOT.h"
#include "TChain.h"
#include "TF1.h"
#include "TFile.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"
#include "TKey.h"
#include "TVirtualFitter.h"


// Fixed size dimensions of array or collections stored in the TTree if any.


Double_t SwartzFunc(Double_t *x,Double_t *par){
  Double_t arg;
  Double_t xx = x[0];
  // par[0] : offset
  // par[1] : width at f(x) minimum
  // par[2] : slope (negative side)
  // par[3] : inflection point abscissa
  // par[4] : slope (positive side)
  if(xx < par[3])
    arg = par[1]*par[1] + par[2]*par[2]*(xx-par[3])*(xx-par[3]);
  else
    arg = par[1]*par[1] + par[4]*par[4]*(xx-par[3])*(xx-par[3]);
  
  Double_t fitval = par[0]+sqrt(arg);
  return fitval;
  
}
Double_t NegSwartzFunc(Double_t *x,Double_t *par){
	Double_t arg;
	Double_t xx = x[0];
	// par[0] : offset
	// par[1] : width at f(x) minimum
	// par[2] : slope (negative side)
	// par[3] : inflection point abscissa
	// par[4] : slope (positive side)
	if(xx < par[3])
		arg = par[1]*par[1] + par[2]*par[2]*(xx-par[3])*(xx-par[3]);
	else
		arg = par[1]*par[1] + par[4]*par[4]*(xx-par[3])*(xx-par[3]);
  
	Double_t fitval = -1.*(par[0]+sqrt(arg));
	return fitval;
	
}







class LorentzAngle_MD {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<double>  *trackchi2;
   vector<double>  *trackchi2ndof;
   vector<double>  *trackdsz;
   vector<double>  *trackdxy;
   vector<double>  *tracketa;
   vector<double>  *trackndof;
   vector<double>  *trackphi;
   vector<double>  *tracktheta;
   vector<double>  *trackvx;
   vector<double>  *trackvy;
   vector<double>  *trackvz;
   vector<float>   *clusternoise;
   vector<float>   *clusterseednoise;
   vector<float>   *clusterston;
   vector<float>   *clustervariance;
   vector<float>   *tsosBdotY;
   vector<float>   *tsosdriftx;
   vector<float>   *tsosdrifty;
   vector<float>   *tsosdriftz;
   vector<float>   *tsosglobalZofunitlocalY;
   vector<float>   *tsosglobalphi;
   vector<float>   *tsosglobaltheta;
   vector<float>   *tsosglobalx;
   vector<float>   *tsosglobaly;
   vector<float>   *tsosglobalz;
   vector<float>   *tsoslocalphi;
   vector<float>   *tsoslocalpitch;
   vector<float>   *tsoslocaltheta;
   vector<float>   *tsoslocalx;
   vector<float>   *tsoslocaly;
   vector<float>   *tsoslocalz;
   vector<float>   *tsosprojwidth;
   vector<float>   *tsosstrip;
   vector<float>   *trackcharge;
   vector<float>   *trackmomentum;
   vector<float>   *trackpt;
   vector<int>     *clusterlayerwheel;
   vector<int>     *clustermodule;
   vector<int>     *clusterside;
   vector<int>     *clustersubdetid;
   vector<int>     *tsosclusterIdx;
   vector<int>     *tsosonTrkClusterIdx;
   vector<int>     *tsosonTrkClustersEnd;
   vector<int>     *tsostrackindex;
   UInt_t          tracknumber;
   vector<unsigned int> *clustercharge;
   vector<unsigned int> *clusterdetid;
   vector<unsigned int> *clusternumber;
   vector<unsigned int> *clusterseedcharge;
   vector<unsigned int> *clusterseedindex;
   vector<unsigned int> *clusterwidth;
   vector<unsigned int> *tsostrackmulti;
   vector<unsigned int> *trackhitslost;
   vector<unsigned int> *trackhitsvalid;

   // List of branches
   TBranch        *b_trackchi2;   //!
   TBranch        *b_trackchi2ndof;   //!
   TBranch        *b_trackdsz;   //!
   TBranch        *b_trackdxy;   //!
   TBranch        *b_tracketa;   //!
   TBranch        *b_trackndof;   //!
   TBranch        *b_trackphi;   //!
   TBranch        *b_tracktheta;   //!
   TBranch        *b_trackvx;   //!
   TBranch        *b_trackvy;   //!
   TBranch        *b_trackvz;   //!
   TBranch        *b_clusternoise;   //!
   TBranch        *b_clusterseednoise;   //!
   TBranch        *b_clusterston;   //!
   TBranch        *b_clustervariance;   //!
   TBranch        *b_tsosBdotY;   //!
   TBranch        *b_tsosdriftx;   //!
   TBranch        *b_tsosdrifty;   //!
   TBranch        *b_tsosdriftz;   //!
   TBranch        *b_tsosglobalZofunitlocalY;   //!
   TBranch        *b_tsosglobalphi;   //!
   TBranch        *b_tsosglobaltheta;   //!
   TBranch        *b_tsosglobalx;   //!
   TBranch        *b_tsosglobaly;   //!
   TBranch        *b_tsosglobalz;   //!
   TBranch        *b_tsoslocalphi;   //!
   TBranch        *b_tsoslocalpitch;   //!
   TBranch        *b_tsoslocaltheta;   //!
   TBranch        *b_tsoslocalx;   //!
   TBranch        *b_tsoslocaly;   //!
   TBranch        *b_tsoslocalz;   //!
   TBranch        *b_tsosprojwidth;   //!
   TBranch        *b_tsosstrip;   //!
   TBranch        *b_trackcharge;   //!
   TBranch        *b_trackmomentum;   //!
   TBranch        *b_trackpt;   //!
   TBranch        *b_clusterlayerwheel;   //!
   TBranch        *b_clustermodule;   //!
   TBranch        *b_clusterside;   //!
   TBranch        *b_clustersubdetid;   //!
   TBranch        *b_tsosclusterIdx;   //!
   TBranch        *b_tsosonTrkClusterIdx;   //!
   TBranch        *b_tsosonTrkClustersEnd;   //!
   TBranch        *b_tsostrackindex;   //!
   TBranch        *b_tracknumber;   //!
   TBranch        *b_clustercharge;   //!
   TBranch        *b_clusterdetid;   //!
   TBranch        *b_clusternumber;   //!
   TBranch        *b_clusterseedcharge;   //!
   TBranch        *b_clusterseedindex;   //!
   TBranch        *b_clusterwidth;   //!
   TBranch        *b_tsostrackmulti;   //!
   TBranch        *b_trackhitslost;   //!
   TBranch        *b_trackhitsvalid;   //!

   LorentzAngle_MD(TTree *tree=0);
   virtual ~LorentzAngle_MD();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef LorentzAngle_MD_cxx
LorentzAngle_MD::LorentzAngle_MD(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("LorentzAngleInputVariables.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("LorentzAngleInputVariables.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("LorentzAngleInputVariables.root:/LATree");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

LorentzAngle_MD::~LorentzAngle_MD()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LorentzAngle_MD::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LorentzAngle_MD::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LorentzAngle_MD::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   trackchi2 = 0;
   trackchi2ndof = 0;
   trackdsz = 0;
   trackdxy = 0;
   tracketa = 0;
   trackndof = 0;
   trackphi = 0;
   tracktheta = 0;
   trackvx = 0;
   trackvy = 0;
   trackvz = 0;
   clusternoise = 0;
   clusterseednoise = 0;
   clusterston = 0;
   clustervariance = 0;
   tsosBdotY = 0;
   tsosdriftx = 0;
   tsosdrifty = 0;
   tsosdriftz = 0;
   tsosglobalZofunitlocalY = 0;
   tsosglobalphi = 0;
   tsosglobaltheta = 0;
   tsosglobalx = 0;
   tsosglobaly = 0;
   tsosglobalz = 0;
   tsoslocalphi = 0;
   tsoslocalpitch = 0;
   tsoslocaltheta = 0;
   tsoslocalx = 0;
   tsoslocaly = 0;
   tsoslocalz = 0;
   tsosprojwidth = 0;
   tsosstrip = 0;
   trackcharge = 0;
   trackmomentum = 0;
   trackpt = 0;
   clusterlayerwheel = 0;
   clustermodule = 0;
   clusterside = 0;
   clustersubdetid = 0;
   tsosclusterIdx = 0;
   tsosonTrkClusterIdx = 0;
   tsosonTrkClustersEnd = 0;
   tsostrackindex = 0;
   clustercharge = 0;
   clusterdetid = 0;
   clusternumber = 0;
   clusterseedcharge = 0;
   clusterseedindex = 0;
   clusterwidth = 0;
   tsostrackmulti = 0;
   trackhitslost = 0;
   trackhitsvalid = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("trackchi2", &trackchi2, &b_trackchi2);
   fChain->SetBranchAddress("trackchi2ndof", &trackchi2ndof, &b_trackchi2ndof);
   fChain->SetBranchAddress("trackdsz", &trackdsz, &b_trackdsz);
   fChain->SetBranchAddress("trackdxy", &trackdxy, &b_trackdxy);
   fChain->SetBranchAddress("tracketa", &tracketa, &b_tracketa);
   fChain->SetBranchAddress("trackndof", &trackndof, &b_trackndof);
   fChain->SetBranchAddress("trackphi", &trackphi, &b_trackphi);
   fChain->SetBranchAddress("tracktheta", &tracktheta, &b_tracktheta);
   fChain->SetBranchAddress("trackvx", &trackvx, &b_trackvx);
   fChain->SetBranchAddress("trackvy", &trackvy, &b_trackvy);
   fChain->SetBranchAddress("trackvz", &trackvz, &b_trackvz);
   fChain->SetBranchAddress("clusternoise", &clusternoise, &b_clusternoise);
   fChain->SetBranchAddress("clusterseednoise", &clusterseednoise, &b_clusterseednoise);
   fChain->SetBranchAddress("clusterston", &clusterston, &b_clusterston);
   fChain->SetBranchAddress("clustervariance", &clustervariance, &b_clustervariance);
   fChain->SetBranchAddress("tsosBdotY", &tsosBdotY, &b_tsosBdotY);
   fChain->SetBranchAddress("tsosdriftx", &tsosdriftx, &b_tsosdriftx);
   fChain->SetBranchAddress("tsosdrifty", &tsosdrifty, &b_tsosdrifty);
   fChain->SetBranchAddress("tsosdriftz", &tsosdriftz, &b_tsosdriftz);
   fChain->SetBranchAddress("tsosglobalZofunitlocalY", &tsosglobalZofunitlocalY, &b_tsosglobalZofunitlocalY);
   fChain->SetBranchAddress("tsosglobalphi", &tsosglobalphi, &b_tsosglobalphi);
   fChain->SetBranchAddress("tsosglobaltheta", &tsosglobaltheta, &b_tsosglobaltheta);
   fChain->SetBranchAddress("tsosglobalx", &tsosglobalx, &b_tsosglobalx);
   fChain->SetBranchAddress("tsosglobaly", &tsosglobaly, &b_tsosglobaly);
   fChain->SetBranchAddress("tsosglobalz", &tsosglobalz, &b_tsosglobalz);
   fChain->SetBranchAddress("tsoslocalphi", &tsoslocalphi, &b_tsoslocalphi);
   fChain->SetBranchAddress("tsoslocalpitch", &tsoslocalpitch, &b_tsoslocalpitch);
   fChain->SetBranchAddress("tsoslocaltheta", &tsoslocaltheta, &b_tsoslocaltheta);
   fChain->SetBranchAddress("tsoslocalx", &tsoslocalx, &b_tsoslocalx);
   fChain->SetBranchAddress("tsoslocaly", &tsoslocaly, &b_tsoslocaly);
   fChain->SetBranchAddress("tsoslocalz", &tsoslocalz, &b_tsoslocalz);
   fChain->SetBranchAddress("tsosprojwidth", &tsosprojwidth, &b_tsosprojwidth);
   fChain->SetBranchAddress("tsosstrip", &tsosstrip, &b_tsosstrip);
   fChain->SetBranchAddress("trackcharge", &trackcharge, &b_trackcharge);
   fChain->SetBranchAddress("trackmomentum", &trackmomentum, &b_trackmomentum);
   fChain->SetBranchAddress("trackpt", &trackpt, &b_trackpt);
   fChain->SetBranchAddress("clusterlayerwheel", &clusterlayerwheel, &b_clusterlayerwheel);
   fChain->SetBranchAddress("clustermodule", &clustermodule, &b_clustermodule);
   fChain->SetBranchAddress("clusterside", &clusterside, &b_clusterside);
   fChain->SetBranchAddress("clustersubdetid", &clustersubdetid, &b_clustersubdetid);
   fChain->SetBranchAddress("tsosclusterIdx", &tsosclusterIdx, &b_tsosclusterIdx);
   fChain->SetBranchAddress("tsosonTrkClusterIdx", &tsosonTrkClusterIdx, &b_tsosonTrkClusterIdx);
   fChain->SetBranchAddress("tsosonTrkClustersEnd", &tsosonTrkClustersEnd, &b_tsosonTrkClustersEnd);
   fChain->SetBranchAddress("tsostrackindex", &tsostrackindex, &b_tsostrackindex);
   fChain->SetBranchAddress("tracknumber", &tracknumber, &b_tracknumber);
   fChain->SetBranchAddress("clustercharge", &clustercharge, &b_clustercharge);
   fChain->SetBranchAddress("clusterdetid", &clusterdetid, &b_clusterdetid);
   fChain->SetBranchAddress("clusternumber", &clusternumber, &b_clusternumber);
   fChain->SetBranchAddress("clusterseedcharge", &clusterseedcharge, &b_clusterseedcharge);
   fChain->SetBranchAddress("clusterseedindex", &clusterseedindex, &b_clusterseedindex);
   fChain->SetBranchAddress("clusterwidth", &clusterwidth, &b_clusterwidth);
   fChain->SetBranchAddress("tsostrackmulti", &tsostrackmulti, &b_tsostrackmulti);
   fChain->SetBranchAddress("trackhitslost", &trackhitslost, &b_trackhitslost);
   fChain->SetBranchAddress("trackhitsvalid", &trackhitsvalid, &b_trackhitsvalid);
   Notify();
}

Bool_t LorentzAngle_MD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LorentzAngle_MD::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LorentzAngle_MD::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef LorentzAngle_MD_cxx
