#define LorentzAngle_MD_cxx
#include "LorentzAngle_MD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void LorentzAngle_MD::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L LorentzAngle_MD.C
//      Root > LorentzAngle_MD t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

 //Setter--------------------------------------------------------------------canvas
  TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 1000, 600);
  TCanvas *c2 = new TCanvas("c2" , "c2", 0, 0, 800,600);
 //TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 800, 800);
   //TCanvas *c1 = new TCanvas("c1", "c1",65,24,1301,744);
// gStyle->SetOptStat(0);
   c1->Divide(2,2,0,0);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->Range(1.806143,-10406.49,1.900429,34839.11);
   c1->SetFillColor(10);
   c1->SetBorderMode(0);
   c1->SetBorderSize(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameLineWidth(2);   
   c1->SetLeftMargin(0.2);
   c1->SetBottomMargin(0.23);
   c1->SetFrameFillColor(0);

//-------------------------------------------------

   //c1->Divide(2,2,0,0);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c2->Range(1.806143,-10406.49,1.900429,34839.11);
   c2->SetFillColor(10);
   c2->SetBorderMode(0);
   c2->SetBorderSize(0);
   c2->SetFrameBorderMode(0);
   c2->SetFrameLineWidth(2);   
   c2->SetLeftMargin(0.2);
   c2->SetBottomMargin(0.23);
   c2->SetFrameFillColor(0);
  // vector<double> vtantheta;
  // vector<int> vwidth;
  
  const int kXbin = 12, kYbin = 10;
  
  TH1D *hTanTheta = new TH1D("hTanTheta","#theta of the trajectory with respect to the local reference frame of the module (Z-axis perpendicular to module)", 314, 0.0, TMath::Pi());
  TH1D *hCosPhi = new TH1D("hCosPhi","#phi of the trajectory with respect to the local reference frame of the module", 80, -4.0, 4.);
  TH1D *hTanThetaY = new TH1D("hTanThetaY","TanThetaY", 160, -8.0, 8.);
  TH1D *hWidth = new TH1D("hWidth","Width", kYbin, 0.0, 10.);
  TH1D *hTrackid = new TH1D("hTrackid", "Trackid", 300, 1, 60);
  TH1D *hClusterid = new TH1D("hClusterid", "Clusterid", 300, 0, 500e+06);
 
 
  TH1D *hClusterVariance = new TH1D("hClusterVariance" , "ClusterVariance=#sum(charge^2-Mean Charge)/Cluster Strip", 100, 0, 20);
  TH1D *hClusterNumber = new TH1D("hClusterNumber","Cluster Number[0]global number,[/=0] number per Sun detector id", 200, 0, 90000);
  TH1D *hClusterSubdetectorId = new TH1D("hClusterSubdetectorId","Cluster Subdtector Id", 200, 3, 7);
  TH1D *hClusterModule = new TH1D("hClusterModule","Module id", 200,1, 14);
  TH1D *hClusterCharge = new TH1D("ClusterCharge","Cluster Charge", 200 ,0., 1800.);
  TH1D *hClusterLayerWheel = new TH1D("hClusterLayerWheel", "Layer for barrel subdetectors/Layers for EndCap subdetectors", 200, 1, 10);
  TH1D *hClusterSide = new TH1D("hClusterSide", "Side", 200, -1, 2);
  TH1D *hClusterSeedCharge = new TH1D("hClusterSeedCharge", "Value of the maximum charge deposite on the strip cluster" , 400, 10.,280.);
  TH1D *hClusterStoN = new TH1D("hClusterStoN" , "Signal over noise, charge over cluster noise rescaled by gain", 200, 0., 400.);
  TH1D *hClusterNoise = new TH1D("hClusterNoise","Noise rescaled by gain, Noise/APV_gain", 200, 3., 50.);
  TH1D *hClusterSeedIndex = new TH1D("hClusterSeedIndex","Strip number(within cluster) having maximum charge deposite;Number of strips; Number of events", 400, 0, 12);
  TH1D *hClusterSeedNoise = new TH1D("hClusterSeedNoise","Noise rescaled by the agin of the strip  having maximum charge deposite", 200, 3., 50. );
  
  
  TH1D *hTrackMultiplicity = new TH1D("hTrackMultiplicity","Number of the tracks matched with the cluster", 200, 0,100);
  TH1D *hTrackIndex = new TH1D("hTrackIndex","OnTrack cluster->track index",  200, 0,1200);
  TH1D *hClusterIdx = new TH1D("hClusterIdx", "On track cluster->general cluster info",200, 0, 90000 );
  TH1D *hLocalPitch = new TH1D("hLocalPitch", "Strip pitch at impact points", 200, 0., 0.03);
  TH1D *hGlobalTheta = new TH1D("hGlobalTheta", "#theta of trajectory on module in global coordinates" , 314,0.0,TMath::Pi());
  TH1D *hGlobalPhi = new TH1D("hGlobalPhi" , "#phi of trajectory on module in global coordinates ", 314,0.0,TMath::Pi());
  TH1D *hStrip = new TH1D("hStrip","Strip index corresponding to the position of the interaction of the trajectory with the module", 200,0,780);
  TH1D *hProjWidth = new TH1D("hProjWidth","tan#theta_{L} X cos#phi_{L}",200, -3.0, 3.);
  TH1D *hBdotY = new TH1D("hBdotY","Local y projection of the magnetic field(in Tesla) on the module surface", 200, -4., 4.);
  TH1D *hLocalX = new TH1D("hLocalX ","local x position of the cluster with respect to the detector module frame;X coordinate at local frame;Number of Events ", 200, 0., 0.05 );
  TH1D *hDriftX = new TH1D("hDriftX","expected Lorentz drift along x", 200, -0., 0.01 );
  TH1D *hDriftZ = new TH1D("hDriftZ","expected Lorentz drift along z", 200, 0., 0.001 );
 
  TH1D *hPseudoRapidity = new TH1D("hPseudoRapidity", "PseudoRapidity" , 100, -3.0, 3.0);
  TH1D *hTrackNumber = new TH1D("hTrackNumber","Number of tracks in the event", 200,0,1200);
  TH1D *hTrackChi2 = new TH1D("hTrackChi2", "#chi^{2};Nb of events", 200, 0., 40.);
  TH1D *hTrackndof  = new TH1D("hTrackndof", "Number of degrees of the track fit", 200, 0., 58.);
  TH1D *hTrackChi2ndof = new TH1D("hTrackChi2ndof", "#chi^{2}/ndof" , 200, 0., 15.);
  TH1D *hTrackCharge = new TH1D("hTrackCharge" , "Charge", 50, -1, 1);
  TH1D *hTrackMomentum = new TH1D("hTrackMomentum","Track momentum", 200,0.,20.);
  TH1D *hTrackpt = new TH1D("hTrackpt","Track p_{T}", 200, 0., 20.);
  TH1D *hTrackTheta = new TH1D("hTrackTheta","#theta ", 314,0.0,TMath::Pi() );
  TH1D *hTrackPhi = new TH1D("hTrackPhi","#phi ", 314,0.0,TMath::Pi() );
  TH1D *hTrackEta = new TH1D("hTrackEta", "#eta", 300, 1, 60);
  TH1D *hTrackdxy = new TH1D("hTrackdxy", "Track d_{xy}", 200, -5., 5.);
  TH1D *hTrackdsz = new TH1D("hTrackdsz", "Track d_{s}" , 400, -20.0, 20.);
  TH1D *hTrackHitsValid = new TH1D("hTrackHitsValid", "Number of valid hits in the tracker", 200, 0., 40.);
  TH1D *hTrackHitsLost = new TH1D("hTrackHitsLost", "Number of missing hits in the tracker" , 400, 0., 10.);



  TH1D *hclusterseedcharge_trackid = new TH1D("clusterseedcharge_trackid","clusterseedcharge_trackid;Cluster seed charge for valid tracks;Nb. of events",256, 0, 256);
  TH1D *hclusterston_trackid      = new TH1D("clusterston_trackid","clusterston_trackid;Cluster signal-to-noise ratio for valid tracks;Nb. of events",200, 0, 200);
  TH1D *hclusternoise_trackid      = new TH1D("clusternoise_trackid","clusternoise_trackid; Cluster noise for valid tracks;Nb. of events",200, 0, 50);
  TH1D *hclusterseednoise_trackid  = new TH1D("clusterseednoise_trackid","clusterseednoise_trackid; Cluster seed noise for valid tracks;Nb. of events",200, 0, 50);

 
  TH2D *hTanThetaWidth = new TH2D("hTanThetaWidth","TanThetaWidth",
				  kXbin, -.6, .6,
				  kYbin,0.0,30.);
  
 // hprof  = new TProfile("hprof","tan(#theta_t) vs Clusterwidth",100,-8.,8.,0.0,10.);
 hprof1 = new TProfile("hprof1","tan#theta_{t} vs Clusterwidth",100,-3.5,3.5,0.0,10.);
 hprof2 = new TProfile("hprof2", "tan#theta_{t} vs Clusterwidth",100,-2.2,2.2,0.0,10.);
 hprof3 = new TProfile("hprof3", "Clustervariance vs Trackangle",100, -0.5, 0.5,0.0, 10.0);

// hprof  = new TProfile("hprof","tan(#theta_t) vs Clusterwidth",100,-8.,8.,0.0,10.);
   //TProfile *hClusterWidth_vs_Trackangle  = new TProfile("ClusterWidth_vs_Trackangle","tan#theta_{t} vs Clusterwidth-for TOB layer 1",100,-.6,.6,0.0,10.);
   TProfile *hClusterWidth_vs_Trackangle  = new TProfile("ClusterWidth_vs_Trackangle","tan#theta_{t} vs Clusterwidth- for TIB layer 1;Trackangle:CLusterwidth",100,-.3,.3,0.0,10.);
   TProfile *hClusterVariance_vs_Trackangle = new TProfile("ClusterVariance_vs_Trackangle", "tan#theta_{t} vs Clustervariance;Trackangle;Clustervariance",100,-0.4,0.4,0.0,10.);
   TProfile *hClusterVariance_vs_Trackangle_Reco = new TProfile("ClusterVariance_vs_Trackangle_Reco", "tan#theta_{t} vs Clustervariance_Reco;Angular Shift; Clustervariance",100,-.8,0.8,0.0,10.);
   TProfile *hDetId_vs_Layer = new TProfile("DetId_vs_Layer", "Detectorid vs layer;Layers and Wheels;Detectorid",100,0,10,0,10);
   TProfile *hDetId_vs_ClusterNumber = new TProfile("DetId_vs_ClusterNumber", "Detectorid vs ClusterNumber;Clusternumber per subdetid; Detectorid",100,0,90000,0.0,10.);
   TProfile *hClusterWidth_vs_Trackangle1  = new TProfile("ClusterWidth_vs_Trackangle1","tan#theta_{t} vs Clusterwidth",100,-0.8,0.8,0.0,10.);
  //histogram--------------------------------------------------------------

   hClusterWidth_vs_Trackangle -> SetLineColor(4);
   hClusterWidth_vs_Trackangle -> SetLineWidth(1);
   	
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetTitleOffset(1.4);
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetTitleOffset(0.9);
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetTitleFont(40);    //for setting title font
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetTitleFont(40);
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetLabelOffset(0.04);   
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetTitleColor(1);
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetLabelFont(62);    //for setting Label font
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetLabelFont(62);
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetLabelSize(0.05);     
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetLabelSize(0.05);
   hClusterWidth_vs_Trackangle -> GetXaxis() ->  SetTitleSize(0.05);
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetTitleSize(0.05);
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetTitleColor(1);
   hClusterWidth_vs_Trackangle -> GetYaxis() ->  SetRange(2,5);
   
   hClusterWidth_vs_Trackangle -> GetXaxis() -> SetTitle("Trackangle ");    
   hClusterWidth_vs_Trackangle -> GetYaxis() -> SetTitle("Clusterwidth");

//-------------------------------------------------------fit


 TF1 *vShapeRoundedAsym = new TF1("vShapeRoundedAsym",SwartzFunc,-.2,.2,5);
  TF1 *vNegShapeRoundedAsym = new TF1("vNegShapeRoundedAsym",NegSwartzFunc,-0.2,-.02,5);

  vShapeRoundedAsym->SetParameter(0,0.2);  // par[0] : offset
  vShapeRoundedAsym->SetParLimits(0,-10,10);
  vShapeRoundedAsym->SetParName(0,"Offset");
  vShapeRoundedAsym->SetParameter(1,0.01); // par[1] : width at f(x) minimum
  vShapeRoundedAsym->SetParLimits(1,0,1);
  vShapeRoundedAsym->SetParName(1,"Width at min.");
  vShapeRoundedAsym->SetParameter(2,0.3);  // par[2] : slope (negative side)
  vShapeRoundedAsym->SetParLimits(2,0,10);
  vShapeRoundedAsym->SetParName(2,"Slope (-)");
  vShapeRoundedAsym->SetParameter(3,-0.1);   // par[3] : inflection point abscissa
  vShapeRoundedAsym->SetParLimits(3,-.5,.5);
  vShapeRoundedAsym->SetParName(3,"Minimum");
  vShapeRoundedAsym->SetParameter(4,0.3);  // par[4] : slope (positive side)
  vShapeRoundedAsym->SetParLimits(4,0,10);
  vShapeRoundedAsym->SetParName(4,"Slope (+)");

  vNegShapeRoundedAsym->SetParameter(0,-0.4); // par[0] : offset
  vNegShapeRoundedAsym->SetParLimits(0,-10,10);
  vNegShapeRoundedAsym->SetParName(0,"Offset");
  vNegShapeRoundedAsym->SetParameter(1,0.1);  // par[1] : width at f(x) minimum
  vNegShapeRoundedAsym->SetParLimits(1,0,1);
  vNegShapeRoundedAsym->SetParName(1,"Width at min.");
  vNegShapeRoundedAsym->SetParameter(2,0.6);  // par[2] : slope (negative side)
  vNegShapeRoundedAsym->SetParLimits(2,0,10);
  vNegShapeRoundedAsym->SetParName(2,"Slope (-)");
  vNegShapeRoundedAsym->SetParameter(3,0.);   // par[3] : inflection point abscissa
  vNegShapeRoundedAsym->SetParLimits(3,-.6,.6);
  vNegShapeRoundedAsym->SetParName(3,"Minimum");
  vNegShapeRoundedAsym->SetParameter(4,0.6);  // par[4] : slope (positive side)
  vNegShapeRoundedAsym->SetParLimits(4,0,10);
  vNegShapeRoundedAsym->SetParName(4,"Slope (+)");

  vShapeRoundedAsym->SetLineWidth(2);
  vNegShapeRoundedAsym->SetLineWidth(2);
  vShapeRoundedAsym->SetLineColor(kRed);
  vNegShapeRoundedAsym->SetLineColor(kRed);

//----------------------------------------------------------------------------------------------------declaration
  
  float tantheta = 0., CosPhi = 0., tthetaT = -1,Trackangle=-1,  Clusterid = 0., ClusterVariance = 0.;
  unsigned int Width = 0; 
  int sign = 0, sign1=0;
  
  int TrackIndex = -1;
  int tanthetaY = 0;
  double  PseudoRapidity =0.;
  int ClusterNumber = 0, ClusterSubdetectorId=0, ClusterModule=0, ClusterLayerWheel=0, ClusterSide=-1, ClusterSeedIndex=0;
  float ClusterCharge=0., ClusterSeedCharge=0., ClusterStoN=0., ClusterNoise=0.; 
  unsigned int TrackNumber=0, TrackHitsValid=0, TrackHitsLost=0;
  int  TrackMultiplicity=0, ClusterIdx=0, Trackndof=0;
  float ClusterSeedNoise=0., LocalPitch=0., GlobalTheta=0., GlobalPhi=0., Strip=0., ProjWidth=0., BdotY=0.;  
  double TrackChi2=0., TrackChi2ndof=0.;
  float  TrackCharge=0., TrackMomentum=0.;
  float Trackpt=0., LocalX=0.,DriftX=0.,DriftZ =0.;
  double TrackTheta=0., TrackEta=0., Trackdxy=0., Trackdsz=0., TrackPhi=0.;
  bool TrackId = false;
  float variable11=0.,variablecharge=0.,variable12=0., exact1=0.,exact2=0.,exactfinal=0., angulardrift=0., angularshift=0., CV=0;
  



   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   cout<<nentries<<"\n";
   cout<<"Event = "<<nentries<<endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   Long64_t LAentry = LoadTree(jentry);
   if (LAentry < 0) break;


//ShallowClusterProducer
//-----------------------------------------------------------
  b_clusterwidth->GetEntry(LAentry);
  b_clusterdetid->GetEntry(LAentry);
  b_clustervariance->GetEntry(LAentry); 
  b_clusternumber->GetEntry(LAentry); 
  b_clustersubdetid->GetEntry(LAentry);
  b_clustermodule->GetEntry(LAentry);
  b_clustercharge->GetEntry(LAentry);
  b_clusterlayerwheel->GetEntry(LAentry);
  b_clusterside->GetEntry(LAentry);
  b_clusterseedcharge->GetEntry(LAentry);
  b_clusterston->GetEntry(LAentry);
  b_clusternoise->GetEntry(LAentry);
  b_clusterseedindex->GetEntry(LAentry);
  b_clusterseednoise->GetEntry(LAentry); 
//Shallow TrackerClusterProducer
//-------------------------------------------------------------------------
  b_tsoslocaltheta->GetEntry(LAentry);
  b_tsoslocalphi->GetEntry(LAentry);
  b_tsosglobalZofunitlocalY->GetEntry(LAentry);
  b_tsostrackindex->GetEntry(LAentry);
  b_tsostrackmulti->GetEntry(LAentry);
  b_tsosclusterIdx->GetEntry(LAentry);
  b_tsoslocalpitch->GetEntry(LAentry);
  b_tsosglobaltheta->GetEntry(LAentry);
  b_tsosglobalphi->GetEntry(LAentry);
  b_tsosstrip->GetEntry(LAentry);
  b_tsosprojwidth->GetEntry(LAentry);
  b_tsosBdotY->GetEntry(LAentry);
 
//Shallow Tracks producer
//---------------------------------------------------------------------------------

  b_tracketa->GetEntry(LAentry);
  b_tracknumber->GetEntry(LAentry);
  b_trackchi2->GetEntry(LAentry);
  b_trackndof->GetEntry(LAentry);
  b_trackchi2ndof->GetEntry(LAentry);
  b_trackcharge->GetEntry(LAentry);
  b_trackmomentum->GetEntry(LAentry);
  b_trackpt->GetEntry(LAentry);
  b_tracktheta->GetEntry(LAentry);
  b_trackphi->GetEntry(LAentry);
  b_trackdxy->GetEntry(LAentry);
  b_trackdsz->GetEntry(LAentry);
  b_trackhitslost->GetEntry(LAentry);
  b_trackhitsvalid->GetEntry(LAentry);

cout<<LAentry<<"\n";

// Loop over the list of tracks ____________________________________________________________________________________________________________________
  hTrackMultiplicity->Fill(trackpt->size());
  for(unsigned int j=0;j<trackpt->size();j++)
  {
    hTrackpt->Fill(trackpt->at(j));
    //if(trackchi2)
    hTrackChi2->Fill(trackchi2->at(j));
    if(trackchi2ndof) hTrackChi2ndof->Fill(trackchi2ndof->at(j));
    if(trackndof)hTrackndof->Fill(trackndof->at(j));
    if(trackhitslost)hTrackHitsLost->Fill(trackhitslost->at(j));
    if(trackhitsvalid) hTrackHitsValid->Fill(trackhitsvalid->at(j));
  }
 // Loop over the list of clusters __________________________________________________________________________________________________________________
  for(unsigned int k=0;k<tsostrackindex->size();k++)
  {
   // if(tsostrackmulti->at(k) != 1) continue; // ???
    
    // Retrieve the informations related to the cluster ______________________________________
    Width = clusterwidth->at(k);hWidth->Fill(Width);
    ClusterVariance = sqrt(clustervariance->at(k));hClusterVariance->Fill(ClusterVariance); 
    ProjWidth = tsosprojwidth->at(k);hProjWidth->Fill(ProjWidth);
    //if(clusterdetid){
    Clusterid  = clusterdetid->at(k);hClusterid->Fill(Clusterid);
   // if(clusterlayerwheel){
    ClusterLayerWheel=clusterlayerwheel->at(k);hClusterLayerWheel->Fill(ClusterLayerWheel);
   //if(clustermodule){
    ClusterModule=clustermodule->at(k);hClusterModule->Fill(ClusterModule);
    ClusterSeedIndex = clusterseedindex->at(k);hClusterSeedIndex->Fill(ClusterSeedIndex);
    Strip = tsosstrip->at(k);hStrip->Fill(Strip);
    if(tsosdriftz<k)DriftZ=tsosdriftz->at(k);hDriftZ->Fill(DriftZ);
    

   

 //if(clusterseedcharge)
    if(clusterseedcharge){ClusterSeedCharge = clusterseedcharge->at(k); hClusterSeedCharge->Fill(ClusterSeedCharge);}
    if(clusterston){ClusterStoN = clusterston->at(k);  hClusterStoN->Fill(ClusterStoN);}
    if(clusternoise){ ClusterNoise = clusternoise->at(k); hClusterNoise->Fill(ClusterNoise);}
    if(clusterseednoise){ClusterSeedNoise  = clusterseednoise->at(k);hClusterSeedNoise->Fill(ClusterSeedNoise);}
  

   // Identify the track the cluster belongs to ______________________________________________
    if(TrackIndex != tsostrackindex->at(k)) TrackIndex = tsostrackindex->at(k);hTrackIndex->Fill(TrackIndex);
   

   // Retrieve the informations related to that track ________________________________________
  // if(clusternumber){ClusterNumber=clusternumber->at(TrackIndex);hClusterNumber->Fill(ClusterNumber);}
    if(trackpt)         Trackpt        = trackpt->at(TrackIndex);hTrackpt->Fill(Trackpt);
    if(trackchi2ndof)  TrackChi2ndof  = trackchi2ndof->at(TrackIndex);hTrackChi2ndof->Fill(TrackChi2ndof);
    if(trackndof)      Trackndof      = trackndof->at(TrackIndex);hTrackndof->Fill(Trackndof);
    if(trackhitslost)  TrackHitsLost  = trackhitslost->at(TrackIndex);hTrackHitsLost->Fill(TrackHitsLost);
    if(trackhitsvalid) TrackHitsValid = trackhitsvalid->at(TrackIndex);hTrackHitsValid->Fill(TrackHitsValid);

 if(trackpt && trackchi2ndof && trackndof && trackhitslost && trackhitsvalid)
    {
      if(Trackpt>0.3 && TrackChi2ndof<1.5 && Trackndof>4 && TrackHitsLost==0 && TrackHitsValid>3)
        TrackId = true;
    }
    else if(trackpt && trackchi2ndof && trackhitslost && trackhitsvalid)
    {
      if(Trackpt>0.3 && TrackChi2ndof<1.5 && TrackHitsLost==0 && TrackHitsValid>3)
        TrackId = true;
    }
    else if(trackpt && trackchi2ndof && trackhitsvalid) 
    {
      if(Trackpt>0.3 && TrackChi2ndof<1.5 && TrackHitsValid>3)
        TrackId = true;
    }
    else
      TrackId = false;

    if(TrackId)// to choose particular track id
    {
      if(clusterseedcharge) hclusterseedcharge_trackid->Fill(ClusterSeedCharge);
      if(clusterston)       hclusterston_trackid->Fill(ClusterStoN);
      if(clusternoise)      hclusternoise_trackid->Fill(ClusterNoise);
      if(clusterseednoise)  hclusterseednoise_trackid->Fill(ClusterSeedNoise);
    //-------------------------------------------------------------------------------------------------Definition of clustervariance
    //This is the definition of clustervariance given in abage thesis which is available Gregory's parent directory.
   //Even they have plotted very smooth curve for clustervariance vs track angular shift.I believ for low statistics data file this is the only way to get V curve . Because of several integration,
   // we are collecting most dispersion relations.Help me out for the cuts on localx, and reconstructed driftx, and driftz
   for(unsigned int  m=1; m<tsosstrip->size();m++)
     {if(tsoslocalx && tsosdriftx && tsosdriftz <m)
      {variable11 +=((tsoslocalx->at(m))*(tsoslocalx->at(m))*(clustercharge->at(m)));
       cout<<variable11<<"\n";
       variable12 +=((tsoslocalx->at(m))*(clustercharge->at(m)));
       variablecharge +=clustercharge->at(m);
       exact1=(variable11)/(variablecharge);
       exact2=(variable12)/(variablecharge);
       exactfinal=pow(exact2,2);
       sign1 = tsosglobalZofunitlocalY->at(m);
       angulardrift=sign1*(tsosdriftx->at(m))/(tsosdriftz->at(m));
     } }

     // for( float i1=-1.; i1<tsoslocalx;i1=i1+0.0005){LocalX=tsoslocalx->at(i1);hLocalX->Fill(LocalX);}
     // Calculate the track angle (theta_L) ____________________________________________________
    
     sign = tsosglobalZofunitlocalY->at(k) < 0 ? -1 : 1;
     //cout<<"projection:"<<sign<<"\n";   
     CosPhi=cos(tsoslocalphi->at(k));hCosPhi->Fill(CosPhi);
    //const float tthetaL = sign * tsosdriftx->at(i) / tsosdriftz->at(i);
     Trackangle=sign*tsosprojwidth->at(k);
     tthetaT = sign * tan(tsoslocaltheta->at(k)) * cos(tsoslocalphi->at(k));
     CV=exact1-exactfinal;
     angularshift=Trackangle-angulardrift;
     hClusterVariance_vs_Trackangle_Reco->Fill(angularshift, CV, 1);//This is the plot I want to plot
     hClusterWidth_vs_Trackangle->Fill(tthetaT, Width, 1); // this is one methos to calculate trackangle vs clusterwidth
     hClusterWidth_vs_Trackangle1->Fill(Trackangle, Width, 1); // this one is another one
     hClusterVariance_vs_Trackangle->Fill(tthetaT, ClusterVariance,1);// This clustervariance vs trackangle but not from definition
     hDetId_vs_Layer->Fill(ClusterLayerWheel, Clusterid,1);// This is get infelction points between layers/wheels and detid to give a cut on detid to different layers.

   // We also have a variable Bdoty and local y , dividing one by another will give us fibble acting magnetic field, from where we can collect mobility.  
     
    



     //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                 // hDetId_vs_ClusterNumber->Fill(ClusterNumber, Clusterid,1);
                 // vtantheta.push_back(tantheta);

                 //Application of detector and layers
	     /*    for(unsigned int j=0;j<1;j++)// for(unsigned int j=0;j<NDetectors;j++)
	            {for(unsigned int k=0;k<1;k++)// for(unsigned int k=0;k<NLayers;k++)
	           {
		    if(((Clusterid&((15<<28)|(7<<25)|(7<<14)|(3<<12)|(3<<0)))!=((1<<28)|((3+2*j)<<25)|((k+1)<<14)|(1<<12)|((k<2?2:0)<<0)))) continue;
		   // clustermultiplicity[j][k]++;
		   for(unsigned int l=0;l<1;l++)// for(unsigned int l=0;l<NMethods;l++)
		   {		     		     
                   hClusterWidth_vs_Trackangle->Fill(tthetaT,Width, 1);		      
		   } 
		   }//NMetods		
	           }//NDetectors loop over
      */        
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
}
}

// LA->ResetBranchAddresses();
  // hClusterVariance_vs_Trackangle->Draw();
//hprof1->Draw("colz");
//hprof->Fit(vShapeRoundedAsym,"R");
//hClusterWidth_vs_Trackangle->DrawNormalized();


//hClusterWidth_vs_Trackangle->Fit(vNegShapeRoundedAsym,"R+");
//-----------------------------------------------------------------------------
   c1->cd(1);
   gPad->SetTickx(2);
   hClusterWidth_vs_Trackangle->Draw("colz");
   hClusterWidth_vs_Trackangle->Fit(vShapeRoundedAsym,"R");

   c1->cd(2);
   gPad->SetTickx(2);
   gPad->SetTicky(2);
   //hClusterVariance_vs_TrackAngle->GetYaxis()->SetLabelOffset(0.01);
   hClusterVariance_vs_Trackangle->Draw();

   c1->cd(3);
   hClusterWidth_vs_Trackangle1->Draw();

   c1->cd(4);
   gPad->SetTicky(2);
   hClusterVariance_vs_Trackangle_Reco->Draw();

   c2->cd();
   gPad->SetTickx(0);
   hClusterWidth_vs_Trackangle->Draw("colz");
   hClusterWidth_vs_Trackangle->Fit(vShapeRoundedAsym,"R");
   //hClusterWidth_vs_Trackangle->Fit(vNegShapeRoundedAsym,"R+");

//---------------------------------------------------
  


  TFile *fOut = TFile::Open("SiStripLorentzAngleOutput.root","RECREATE");
  if (!fOut) { return; }
  hprof1->Write();
  hprof2->Write();
  hWidth->Write();
  hCosPhi->Write();
  hLocalX->Write();
  hDriftX->Write();
  hDriftZ->Write();
  hStrip->Write();
  hProjWidth->Write();
  hTrackIndex->Write();
  hTrackChi2->Write();
  hTrackndof->Write();
  hTrackChi2ndof->Write();
  hTrackHitsLost->Write();
  hTrackHitsValid->Write();
  hClusterid->Write();
  hClusterSeedCharge->Write();
  hClusterVariance->Write();
  hClusterStoN->Write();
  hClusterNoise->Write();
  hClusterSeedNoise->Write();
  hClusterSeedIndex->Write();
  hTrackMultiplicity->Write();
  hClusterLayerWheel->Write();
  hclusterseedcharge_trackid->Write();
  hclusterston_trackid->Write();
  hclusternoise_trackid->Write();
  hclusterseednoise_trackid->Write();

 

  fOut->Write();
  delete fOut;
   }




      //nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

}
