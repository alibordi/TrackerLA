import FWCore.ParameterSet.Config as cms

from CalibTracker.SiStripCommon.ShallowClustersProducer_cfi import *
from CalibTracker.SiStripCommon.ShallowTrackClustersProducer_cfi import *
from CalibTracker.SiStripCommon.ShallowTracksProducer_cfi import *
#from CalibTracker.SiStripCommon.ShallowGainCalibration_cfi import *
#from CalibTracker.SiStripCommon.ShallowSimTracksProducer_cfi import *
LorentzAngleOutputCommands =  [ 'keep *_shallowClusters_clusterdetid_*',
                                'keep *_shallowClusters_clusternumber_*',
                                'keep *_shallowClusters_clustersubdetid_*',
                                'keep *_shallowClusters_clustermodule_*',
                                'keep *_shallowClusters_clusterwidth_*',
                                'keep *_shallowClusters_clustervariance_*',
                                'keep *_shallowClusters_clustercharge_*',
                                'keep *_shallowClusters_clusterlayerwheel_*',
                                'keep *_shallowClusters_clusterside_*',
                                'keep *_shallowClusters_clusterseedcharge_*',
                                'keep *_shallowClusters_clusterston_*',
                                'keep *_shallowClusters_clusternoise_*',
                                'keep *_shallowClusters_clusterseedindex_*',
                              'keep *_shallowClusters_clusterseednoise_*',
                                'keep *_shallowTrackClusters_tsostrackmulti_*',
                                'keep *_shallowTrackClusters_tsosglobalx_*',
                               'keep *_shallowTrackClusters_tsosglobaly_*',
                                'keep *_shallowTrackClusters_tsosglobalz_*',
                                'keep *_shallowTrackClusters_tsoslocalx_*',
                                'keep *_shallowTrackClusters_tsoslocaly_*',
                                'keep *_shallowTrackClusters_tsoslocalz_*',
                                'keep *_shallowTrackClusters_tsosdrifty_*',
                                'keep *_shallowTrackClusters_tsostrackindex_*',
                                'keep *_shallowTrackClusters_tsosclusterIdx_*',
                                'keep *_shallowTrackClusters_tsoslocalpitch_*',
                                'keep *_shallowTrackClusters_tsosglobaltheta_*',
                                'keep *_shallowTrackClusters_tsosglobalphi_*',
                                'keep *_shallowTrackClusters_tsosstrip_*',
                                'keep *_shallowTrackClusters_tsosdriftx_*',
                                'keep *_shallowTrackClusters_tsosdriftz_*',
                                'keep *_shallowTrackClusters_tsosprojwidth_*',
                               # 'keep *_shallowTrackClusters_tsosstrip_*',
                                'keep *_shallowTrackClusters_tsoslocaltheta_*',
                                'keep *_shallowTrackClusters_tsoslocalphi_*',
                                'keep *_shallowTrackClusters_tsosBdotY_*' ,
                                'keep *_shallowTrackClusters_tsosglobalZofunitlocalY_*',
                                'keep *_shallowTracks_tracknumber_*',
                                'keep *_shallowTracks_trackchi2_*',
                                'keep *_shallowTracks_trackndof_*',
                                'keep *_shallowTracks_trackchi2ndof_*',
                                'keep *_shallowTracks_trackcharge_*',
                                'keep *_shallowTracks_trackmomentum_*',
                                'keep *_shallowTracks_trackpt_*',
                                'keep *_shallowTracks_tracktheta_*',
                                'keep *_shallowTracks_trackphi_*',
                                'keep *_shallowTracks_tracketa_*',
                                'keep *_shallowTracks_trackhitsvalid_*',
                                'keep *_shallowTracks_trackhitslost_*',
                                'keep *_shallowTracks_trackdxy_*',
                                'keep *_shallowTracks_trackdsz_*',
                                'keep *_shallowTracks_trackvx_*',
                                'keep *_shallowTracks_trackvy_*',
                                'keep *_shallowTracks_trackvz_*']
                               # 'keep *_shallowGainCalibration_GainCalibrationamplitude_*',
                                #'keep *_shallowGainCalibration_GainCalibrationnstrips_*',
                                #'keep *_shallowGainCalibration_GainCalibrationrawid_*',
                                #'keep *_shallowGainCalibration_GainCalibrationtrackindex_*']
                                #'keep *_shallowSimTracks_strackpt_*',
                                #'keep *_shallowSimTracks_stracktheta_*',
                                #'keep *_shallowSimTracks_strackphi_*',
                                #'keep *_shallowSimTracks_stracketa_*',
                                #'keep *_shallowSimTracks_strackmulti_*',
                                #'keep *_shallowSimTracks_strackcharge_*']

laCalibrationTree = cms.EDAnalyzer("ShallowTree", outputCommands = cms.untracked.vstring('drop *'))
laCalibrationTree.outputCommands += LorentzAngleOutputCommands
LorentzAngleNtuple = cms.Sequence( (shallowClusters + shallowTrackClusters + shallowTracks) * laCalibrationTree)
#LorentzAngleNtuple = cms.Sequence( (shallowClusters + shallowTrackClusters + shallowSimTracks) * laCalibrationTree)
