from CalibTracker.SiStripCommon.shallowTree_test_template import *
process.TFileService.fileName = 'LorentzAngleInputVariables.root'

process.load('CalibTracker.SiStripCommon.ShallowClustersProducer_cfi')
process.load('CalibTracker.SiStripCommon.ShallowTrackClustersProducer_cfi')
#process.load('CalibTracker.SiStripCommon.ShallowSimTracksProducer_cfi')
process.load('CalibTracker.SiStripCommon.ShallowTracksProducer_cfi')  
#process.load('CalibTracker.SiStripCommon.ShallowGainCalibration_cfi')   

process.load('RecoTracker.TrackProducer.TrackRefitters_cff')

from RecoTracker.TrackProducer.TrackRefitter_cfi import TrackRefitter
from CalibTracker.SiStripLorentzAngle.ntuple_cff import LorentzAngleOutputCommands
process.tracksRefit = TrackRefitter.clone()
process.shallowTrackClusters.Tracks = 'tracksRefit'
#process.maxEvents = 30
process.LATree = cms.EDAnalyzer(
   "ShallowTree",
   outputCommands = cms.untracked.vstring(
      'drop *',
      'keep *_shallowTrackClusters_*clusterIdx*_*',
      'keep *_shallowTrackClusters_*onTrkClusterIdx*_*',
      'keep *_shallowTrackClusters_*onTrkClustersEnd*_*',
      'keep *_shallowTrackClusters_*trackindex*_*',
      )
   )
process.LATree.outputCommands += LorentzAngleOutputCommands

#process.p = cms.Path(process.MeasurementTrackerEvent*process.tracksRefit*process.shallowTrackClusters*process.shallowClusters*process.shallowSimTracks*process.LATree)
#process.p = cms.Path(process.MeasurementTrackerEvent*process.tracksRefit*process.shallowTrackClusters*process.shallowClusters*process.shallowTracks*process.shallowGainCalibration*process.LATree)
process.p = cms.Path(process.MeasurementTrackerEvent*process.tracksRefit*process.shallowTrackClusters*process.shallowClusters*process.shallowTracks*process.LATree)
