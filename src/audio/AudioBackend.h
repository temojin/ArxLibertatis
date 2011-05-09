
#ifndef ARX_AUDIO_AUDIOBACKEND_H
#define ARX_AUDIO_AUDIOBACKEND_H

#include "audio/AudioTypes.h"

namespace audio {

class Source;
class Environment;
class Mixer;
class Sample;

/*!
 * An audio source that can play one sample.
 */
class Backend {
	
public:
	
	virtual ~Backend() {};
	
	/*!
	 * Calculate updated positional data if that has not been done already.
	 */
	virtual aalError updateDeferred() = 0;
	
	/*!
	 * Create a new source for the given sample and channel properties.
	 * The source is managed by the backend and should not be deleted directly.
	 * Use deleteSource to remove sources.
	 * @param sampleId The sample to be played by the new source.
	 */
	virtual Source * createSource(SampleId sampleId, const Channel & channel) = 0;
	
	/*!
	 * Get the source for the given id.
	 * @return the source for the given id or NULL if it doesn't exist.
	 */
	virtual Source * getSource(SourceId sourceId) = 0;
	
	/*!
	 * Enable or disable effects.
	 */
	virtual aalError setReverbEnabled(bool enable) = 0;
	
	/*!
	 * Set a unit factor to scale all other distance or velocity parameters.
	 * @param factor The unit factor in meters per unit.
	 */
	virtual aalError setUnitFactor(float factor) = 0;
	
	virtual aalError setRolloffFactor(float factor) = 0;
	
	virtual aalError setListenerPosition(const Vec3f & position) = 0;
	virtual aalError setListenerOrientation(const Vec3f & front, const Vec3f & up) = 0;
	
	virtual aalError setListenerEnvironment(const Environment & env) = 0;
	virtual aalError setRoomRolloffFactor(float factor) = 0;
	
	typedef Source * const * source_iterator;
	virtual source_iterator sourcesBegin() = 0;
	virtual source_iterator sourcesEnd() = 0;
	virtual source_iterator deleteSource(source_iterator it) = 0;
	
	static inline SampleId getSampleId(SourceId sourceId) { return sourceId & 0x0000ffff; }
	static inline SourceId clearSource(SourceId sourceId) { return sourceId | 0xffff0000; }
	
};

} // namespace audio

#endif // ARX_AUDIO_AUDIOBACKEND_H