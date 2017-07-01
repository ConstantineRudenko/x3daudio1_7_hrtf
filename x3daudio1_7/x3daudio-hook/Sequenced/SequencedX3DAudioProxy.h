#pragma once
#include "ISpatializationGlue.h"
#include "ChannelMatrix.h"

class SequencedX3DAudioProxy : public ISpatializationGlue
{
public:
	SpatialData ExtractSpatialData(XAudio2VoiceProxy * source, IXAudio2Voice * pDestinationProxy) override;
	void X3DAudioCalculate(const X3DAUDIO_LISTENER * pListener, const X3DAUDIO_EMITTER * pEmitter, UINT32 Flags, X3DAUDIO_DSP_SETTINGS * pDSPSettings) override;

private:
	void CorrectVolume(SpatialData & spatialDataCopy, const ChannelMatrix & clientMatrix) const;
private:
	SpatialData _lastSpatialData;


};
